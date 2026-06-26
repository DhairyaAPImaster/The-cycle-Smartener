#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include <driver/i2s.h>
#include <Preferences.h>
#include <Wire.h>

#if __has_include(<Adafruit_GFX.h>)
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#define HAS_LCD_LIB 1
#else
#define HAS_LCD_LIB 0
#endif

namespace {
constexpr gpio_num_t PIN_SD_CS = GPIO_NUM_5;
constexpr gpio_num_t PIN_LCD_CS = GPIO_NUM_16;
constexpr gpio_num_t PIN_LCD_DC = GPIO_NUM_17;
constexpr gpio_num_t PIN_LCD_RST = GPIO_NUM_21;
constexpr gpio_num_t PIN_LCD_BL = GPIO_NUM_27;
constexpr gpio_num_t PIN_SPI_SCK = GPIO_NUM_18;
constexpr gpio_num_t PIN_SPI_MOSI = GPIO_NUM_23;
constexpr gpio_num_t PIN_SPI_MISO = GPIO_NUM_19;

constexpr gpio_num_t PIN_I2S_BCLK = GPIO_NUM_26;
constexpr gpio_num_t PIN_I2S_LRCLK = GPIO_NUM_22;
constexpr gpio_num_t PIN_I2S_DIN = GPIO_NUM_25;
constexpr gpio_num_t PIN_I2S_MIC_BCLK = GPIO_NUM_14;
constexpr gpio_num_t PIN_I2S_MIC_WS = GPIO_NUM_15;
constexpr gpio_num_t PIN_I2S_MIC_SD = GPIO_NUM_32;
constexpr gpio_num_t PIN_I2S_AMP_SD = GPIO_NUM_25;

constexpr gpio_num_t PIN_STATUS_LED = GPIO_NUM_2;
constexpr gpio_num_t PIN_BOOT_BUTTON = GPIO_NUM_0;
constexpr gpio_num_t PIN_BUTTON_1 = GPIO_NUM_34;
constexpr gpio_num_t PIN_BUTTON_2 = GPIO_NUM_35;

constexpr uint32_t AUDIO_SAMPLE_RATE = 16000;
constexpr size_t AUDIO_FRAME_COUNT = 256;

Preferences preferences;

#if HAS_LCD_LIB
Adafruit_ILI9341 lcd(PIN_LCD_CS, PIN_LCD_DC, PIN_LCD_RST);
#endif

bool sdReady = false;
bool lcdReady = false;

void setBacklight(bool enabled) {
  digitalWrite(static_cast<int>(PIN_LCD_BL), enabled ? HIGH : LOW);
}

void setStatusLed(bool enabled) {
  digitalWrite(static_cast<int>(PIN_STATUS_LED), enabled ? HIGH : LOW);
}

void drawBootScreen(const char *line1, const char *line2, uint16_t color) {
#if HAS_LCD_LIB
  if (!lcdReady) {
    return;
  }
  lcd.fillScreen(ST77XX_BLACK);
  lcd.setTextWrap(true);
  lcd.setTextSize(2);
  lcd.setTextColor(color);
  lcd.setCursor(12, 24);
  lcd.println(line1);
  lcd.setCursor(12, 64);
  lcd.setTextSize(1);
  lcd.println(line2);
#else
  (void)line1;
  (void)line2;
  (void)color;
#endif
}

void initDisplay() {
  pinMode(static_cast<int>(PIN_LCD_BL), OUTPUT);
  setBacklight(true);

#if HAS_LCD_LIB
  pinMode(static_cast<int>(PIN_LCD_CS), OUTPUT);
  pinMode(static_cast<int>(PIN_LCD_DC), OUTPUT);
  pinMode(static_cast<int>(PIN_LCD_RST), OUTPUT);
  SPI.begin(static_cast<uint8_t>(PIN_SPI_SCK), static_cast<uint8_t>(PIN_SPI_MISO), static_cast<uint8_t>(PIN_SPI_MOSI), static_cast<uint8_t>(PIN_LCD_CS));
  lcd.begin();
  lcd.setRotation(1);
  lcdReady = true;
  drawBootScreen("Cycle Smartener", "LCD ready", ST77XX_GREEN);
#else
  lcdReady = false;
#endif
}

void initSdCard() {
  SPI.begin(static_cast<uint8_t>(PIN_SPI_SCK), static_cast<uint8_t>(PIN_SPI_MISO), static_cast<uint8_t>(PIN_SPI_MOSI), static_cast<uint8_t>(PIN_SD_CS));
  pinMode(static_cast<int>(PIN_SD_CS), OUTPUT);
  digitalWrite(static_cast<int>(PIN_SD_CS), HIGH);

  sdReady = SD.begin(static_cast<uint8_t>(PIN_SD_CS), SPI, 20000000);
  if (sdReady) {
    Serial.println("SD card mounted");
  } else {
    Serial.println("SD card mount failed");
  }
}

bool initAudioOutput() {
  const i2s_config_t config = {
      .mode = static_cast<i2s_mode_t>(I2S_MODE_MASTER | I2S_MODE_TX),
      .sample_rate = static_cast<int>(AUDIO_SAMPLE_RATE),
      .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
      .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT,
      .communication_format = I2S_COMM_FORMAT_STAND_I2S,
      .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
      .dma_buf_count = 8,
      .dma_buf_len = 256,
      .use_apll = false,
      .tx_desc_auto_clear = true,
      .fixed_mclk = 0,
  };

  const i2s_pin_config_t pins = {
      .bck_io_num = static_cast<int>(PIN_I2S_BCLK),
      .ws_io_num = static_cast<int>(PIN_I2S_LRCLK),
      .data_out_num = static_cast<int>(PIN_I2S_DIN),
      .data_in_num = I2S_PIN_NO_CHANGE,
  };

  if (i2s_driver_install(I2S_NUM_0, &config, 0, nullptr) != ESP_OK) {
    return false;
  }
  if (i2s_set_pin(I2S_NUM_0, &pins) != ESP_OK) {
    return false;
  }
  return true;
}

bool initMicInput() {
  const i2s_config_t config = {
      .mode = static_cast<i2s_mode_t>(I2S_MODE_MASTER | I2S_MODE_RX),
      .sample_rate = static_cast<int>(AUDIO_SAMPLE_RATE),
      .bits_per_sample = I2S_BITS_PER_SAMPLE_32BIT,
      .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
      .communication_format = I2S_COMM_FORMAT_STAND_I2S,
      .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
      .dma_buf_count = 8,
      .dma_buf_len = 256,
      .use_apll = false,
      .tx_desc_auto_clear = false,
      .fixed_mclk = 0,
  };

  const i2s_pin_config_t pins = {
      .bck_io_num = static_cast<int>(PIN_I2S_MIC_BCLK),
      .ws_io_num = static_cast<int>(PIN_I2S_MIC_WS),
      .data_out_num = I2S_PIN_NO_CHANGE,
      .data_in_num = static_cast<int>(PIN_I2S_MIC_SD),
  };

  if (i2s_driver_install(I2S_NUM_1, &config, 0, nullptr) != ESP_OK) {
    return false;
  }
  if (i2s_set_pin(I2S_NUM_1, &pins) != ESP_OK) {
    return false;
  }
  return true;
}

void showStorageSummary() {
#if HAS_LCD_LIB
  if (!lcdReady) {
    return;
  }
  lcd.fillScreen(ST77XX_BLACK);
  lcd.setCursor(0, 0);
  lcd.setTextSize(2);
  lcd.setTextColor(ST77XX_CYAN);
  lcd.println("Cycle Smartener");
  lcd.setTextSize(1);
  lcd.setTextColor(ST77XX_WHITE);
  lcd.print("SD: ");
  lcd.println(sdReady ? "ready" : "missing");
  lcd.print("Audio: ");
  lcd.println("I2S active");
  lcd.print("Buttons: ");
  lcd.println("boot / user");
#endif
}

void readButtons() {
  const bool bootPressed = digitalRead(static_cast<int>(PIN_BOOT_BUTTON)) == LOW;
  const bool button1Pressed = digitalRead(static_cast<int>(PIN_BUTTON_1)) == LOW;
  const bool button2Pressed = digitalRead(static_cast<int>(PIN_BUTTON_2)) == LOW;

  if (bootPressed) {
    setStatusLed(true);
  } else {
    setStatusLed(false);
  }

  if (button1Pressed) {
    preferences.putUInt("lastButton", 1);
  }
  if (button2Pressed) {
    preferences.putUInt("lastButton", 2);
  }
}

void readMicLevel() {
  static int32_t samples[AUDIO_FRAME_COUNT];
  size_t bytesRead = 0;
  esp_err_t result = i2s_read(I2S_NUM_1, samples, sizeof(samples), &bytesRead, 0);
  if (result != ESP_OK || bytesRead == 0) {
    return;
  }

  const size_t sampleCount = bytesRead / sizeof(int32_t);
  int64_t sum = 0;
  for (size_t index = 0; index < sampleCount; ++index) {
    sum += abs(samples[index] >> 14);
  }
  const uint32_t level = sampleCount ? static_cast<uint32_t>(sum / static_cast<int64_t>(sampleCount)) : 0;
  preferences.putUInt("micLevel", level);
}

void logSystemState() {
  Serial.printf("SD=%s LCD=%s Mic=%s\n", sdReady ? "ready" : "missing", lcdReady ? "ready" : "missing", "ready");
}
}  // namespace

void setup() {
  Serial.begin(115200);
  delay(200);

  pinMode(static_cast<int>(PIN_STATUS_LED), OUTPUT);
  pinMode(static_cast<int>(PIN_BOOT_BUTTON), INPUT_PULLUP);
  pinMode(static_cast<int>(PIN_BUTTON_1), INPUT);
  pinMode(static_cast<int>(PIN_BUTTON_2), INPUT);

  preferences.begin("cycle", false);

  initDisplay();
  initSdCard();

  const bool micReady = initMicInput();
  const bool ampReady = initAudioOutput();

  Serial.printf("Mic init: %s\n", micReady ? "ok" : "failed");
  Serial.printf("Amp init: %s\n", ampReady ? "ok" : "failed");

  showStorageSummary();
  logSystemState();
}

void loop() {
  static uint32_t lastUiRefresh = 0;
  static uint32_t lastMicRead = 0;

  readButtons();

  const uint32_t now = millis();
  if (now - lastMicRead >= 40) {
    lastMicRead = now;
    readMicLevel();
  }

  if (now - lastUiRefresh >= 1000) {
    lastUiRefresh = now;
    showStorageSummary();
    logSystemState();
  }

  delay(5);
}
