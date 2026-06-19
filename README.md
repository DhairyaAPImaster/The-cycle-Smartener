<img width="1983" height="793" alt="Cycle smartener banner" src="https://github.com/user-attachments/assets/2b015623-9076-4258-9e88-68227a751b99" />

# The Cycle Smartener
**(Makes the cycle kindda smart)**
### By Dhairya


## About "The Cycle Smartener"

So the Cycle smartener or TCS for short is basically this device that i designed that can be fitted on top of (almost) any modern cycle. Btw i made this cause i absolutelly love cycling and yeah having such a device would make the whole ride way more fun and interesting.

I plan on integrating TinyML to also integrate AI into it so that it can do stuff like change the song or answer questions from voice commands. Alsoin next versions i plan on adding bluetooth so that one can connect their device - smart phone or something to it. and an sd card slot for one to put a micro sd in it to add music.

Btw it also has a 2.4inch LCD Display  (to displays whatever needs to be displayed).



## Folder Structure

`src/` - source files for PCB and CAD
`src/FreeCAD/` - mechanical CAD sources (open the .FCStd in FreeCAD)
`src/KiCAD/` - KiCad project files for the PCB
`production/` - exports and fab outputs (gerbers, BOM, stls)
`production/PCB/` - gerbers, BOM, CPL
`production/CAD/` - exported STLs for the case
`images/` - screenshots and photos used in this README


## BOM





## How to Replicate

- Step 1 - Basically Just Clone or downlaod this repo from github. U can do this by either going to the code button on this repo page and pressing download Zip or u can clone this Repo Or you can go to the Releases on this repo and download the Zip File there too (the fastest way to download is like just going to code and pressing download Zip Or by cloning the Repo.)

- Step 2 - In the the production folder you will find the CAD and PCB folders.

- Step 3 - The CAD folder contains all the 3d Pritnable files for the case of the keyboard. If you wish to u can make any changes to the design or make your own design and use that instead.

- Step 4 - The PCB folder contains the Gerbers, BOM , and CPL files. These are the files that allow you to get the PCB manufactured from JLCPCB (im using JLCPCB) or any other PCB manufacturer(like PCBway or others).

- Step 5 - Upload the gerbers zip file in JLCPCB "Place order / get instant quote" Page (u will need to sign up to order but can get a quote without signing up)

- Step 6 - Change the colour of the PCB in the options JLC gives (if u use JLC PCB most of the times canging colours does not add any charge acc to what i know)

- Step 7 - Select PCBA if u want JLCPCB to assemble the PCB for you but ngl soldering all components by hand is cheaper and saves u a ton of money and also is pretty fun (im hand soldering all components)

- Step 8 - Upload the CPL and BOM files whe JLCPCB asks u to.

- Step 9 - Recheck the position of all components (i faced no problem with this as all components were in the correct place but i have faced issues with the placement in one of my other projects i made in KiCAD)
- Step 10 - Order the PCB

- Step 11 - if u dont have a 3d printer u can order the 3d model from JLC's JLC3DP but yeah all you have to do now is print the case and assemble the PCB in the case. (note u might have to trim down the spacers just a little)

- Step 12 - Get 8 M2 bolts and 8 heat insterts for it.

- Step 13 - Attatch the heat insrets into the case through the holes made for the hook. each hook has 4 holes for botlts.

- Step 14 - Position the hook from below on the cycles bar and position the case itself above it and then carefully screw in the screws securing the device to your cycle!!!!!!

- DONE!!!!! 


## Images

<img width="665" height="394" alt="Screenshot 2026-06-17 182957" src="https://github.com/user-attachments/assets/fcb57724-daa1-44b7-9b97-7227330e0cc1" />
<img width="145" height="75" alt="Screenshot 2026-06-17 182929" src="https://github.com/user-attachments/assets/184e0782-3de0-48c9-b640-2fce1529298c" />
<img width="959" height="539" alt="Screenshot 2026-06-17 182924" src="https://github.com/user-attachments/assets/3323f316-a39c-4e21-9b2d-73b025a8c3fb" />
<img width="270" height="329" alt="Screenshot 2026-06-17 182845" src="https://github.com/user-attachments/assets/3c85f28f-0ea8-4253-8776-ac231dbadd75" />
<img width="98" height="152" alt="Screenshot 2026-06-17 182830" src="https://github.com/user-attachments/assets/33cebb4e-b3b7-48d5-91b7-f413a7c002ea" />
<img width="160" height="135" alt="Screenshot 2026-06-17 182823" src="https://github.com/user-attachments/assets/8a549afe-2f51-48f0-9cb3-1b373c1799ec" />
<img width="129" height="129" alt="Screenshot 2026-06-17 182813" src="https://github.com/user-attachments/assets/8423da74-b021-412b-bc1d-3433775cc6cf" />
<img width="238" height="123" alt="Screenshot 2026-06-17 182800" src="https://github.com/user-attachments/assets/62f73b7f-c9c6-45aa-920d-ee236a468c13" />
<img width="1918" height="1078" alt="image" src="https://github.com/user-attachments/assets/819cb95a-9ca3-47a9-a83c-cd4528d374bd" />
<img width="841" height="382" alt="image" src="https://github.com/user-attachments/assets/3a42351b-3218-4bd4-9414-e3efafd4adae" />
<img width="1918" height="1006" alt="image (13)" src="https://github.com/user-attachments/assets/658efee7-7f52-409a-9519-2cdf6ba116e3" />
<img width="1636" height="840" alt="image (12)" src="https://github.com/user-attachments/assets/a4bc483c-6272-4ce5-b161-34f02ba098fe" />
<img width="523" height="556" alt="image (11)" src="https://github.com/user-attachments/assets/90919ea9-417b-439b-8f0b-2297d3ab02f2" />
<img width="400" height="337" alt="image (11)" src="https://github.com/user-attachments/assets/d669bad7-f2c3-44cc-8dff-bdca3a2a6937" />
<img width="1248" height="541" alt="image (10)" src="https://github.com/user-attachments/assets/0630a963-ee6e-422b-86cb-86636ebc7b1e" />
<img width="1122" height="510" alt="image (10)" src="https://github.com/user-attachments/assets/65fc49cf-60aa-4141-91ca-7c6d2754b422" />
<img width="1306" height="768" alt="image (9)" src="https://github.com/user-attachments/assets/d7224850-b042-4f58-a85a-0b452a420551" />
<img width="1194" height="538" alt="image (9)" src="https://github.com/user-attachments/assets/0d5d1045-6c7e-41c0-a29b-6359d8d78555" />
<img width="960" height="712" alt="image (8)" src="https://github.com/user-attachments/assets/5bd09609-7e5e-4fcf-a4f9-1269f75d9f07" />
<img width="1123" height="502" alt="image (8)" src="https://github.com/user-attachments/assets/b326532d-5c34-4641-9c80-c2eadce5deec" />
<img width="1068" height="771" alt="image (7)" src="https://github.com/user-attachments/assets/d953100a-47a2-4052-8b46-ace8ab9fad87" />
<img width="1414" height="771" alt="image (7)" src="https://github.com/user-attachments/assets/62882c41-2157-474f-a125-1e8276af02fb" />
<img width="1912" height="1077" alt="image (6)" src="https://github.com/user-attachments/assets/c0be7796-9c24-4f6f-83d0-a6a35a62c6c9" />
<img width="469" height="510" alt="image (6)" src="https://github.com/user-attachments/assets/f9aee5c0-a689-4cd5-8e0e-75dbfd434adb" />
<img width="1918" height="1078" alt="image (5)" src="https://github.com/user-attachments/assets/33723f4f-d6fe-4057-90c7-37759e7f8482" />
<img width="394" height="310" alt="image (5)" src="https://github.com/user-attachments/assets/f75c41c8-97f7-4b1f-9326-f8cbe5246ba9" />
<img width="811" height="597" alt="image (4)" src="https://github.com/user-attachments/assets/5ae852f7-0fd5-49b9-b093-778fc344d61c" />
<img width="945" height="375" alt="image (4)" src="https://github.com/user-attachments/assets/44e13105-df68-4781-8bc1-588a74c07957" />
<img width="949" height="604" alt="image (3)" src="https://github.com/user-attachments/assets/83a8109b-da8e-438d-b8d5-946345f07b32" />
<img width="310" height="637" alt="image (3)" src="https://github.com/user-attachments/assets/1a2b7333-f6e0-45c0-b62a-4d5d178ccbcf" />
<img width="1896" height="1066" alt="image (2)" src="https://github.com/user-attachments/assets/80541bf9-32f0-4225-98b0-d76b54fe6b65" />
<img width="1822" height="1078" alt="image (2)" src="https://github.com/user-attachments/assets/bf256a60-e5c6-45a4-99d5-80eeb8cf8bf9" />
<img width="1918" height="1078" alt="image (1)" src="https://github.com/user-attachments/assets/95e44cf0-f42d-43e2-b23f-313a68de5895" />
<img width="327" height="258" alt="Screenshot 2026-06-17 185231" src="https://github.com/user-attachments/assets/e92a486c-40e2-4339-8fd8-2581c2bc06d6" />



## License and Credits

***I used the following for making this project***

- ***KiCAD*** - For PCB design
- ***FreeCAD*** - For designing the Case
- **[APX HUB by @Gabouin](https://github.com/Gabouin/APX-USB-HUB)** - Readme template

## Final Notes

btw i will add notes here when i need to but rn there is no note.



