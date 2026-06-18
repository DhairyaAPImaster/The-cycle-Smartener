The Cycle Smartener
by Dhairya

About The Device
The Cycle Smartener is my quick project where i tried to make a tiny handlebar device with an RP2040 brain. it's just a design — im not gonna mass-produce this or anything. think of it as a thing i made for fun and to learn.

Features
- RP2040 controller (runs whatever firmware you want)
- OLED on the top-ish area for time / status / modes
- RGB LEDs under switches/indicators for colours/effects
- 3D-printable case pieces (in `src/FreeCAD` / `production/CAD`)

Repo structure
src/ - source files for PCB and CAD
src/FreeCAD/ - mechanical CAD sources (open the .FCStd in FreeCAD)
src/KiCAD/ - KiCad project files for the PCB
production/ - exports and fab outputs (gerbers, BOM, stls)
production/PCB/ - gerbers, BOM, CPL
production/CAD/ - exported STLs for the case
images/ - screenshots and photos used in this README

Important - design only
This repo is mainly for the design. i made the boards and case files so people can look at how i did stuff, not because i expect anyone to manufacture them. if you want to prototype that's cool, but it's optional — the files are here if u wanna learn or tweak.

How to use this repo (if ur curious)
- Clone or download the repo.
- Open `src/KiCAD` if you wanna see the schematic and PCB layout.
- Open `src/FreeCAD` to poke around the case and parts.
- `production/PCB/BOM.csv` has the component list if you just want to see what i used.

Optional: prototyping steps (if u actually wanna test it)
- Gerbers are in `production/PCB` — upload to a fab if u want a board (optional).
- STLs are in `production/CAD` — print the case or just look at the models.
- If you do assemble: start with SMD parts, then through-hole, mount into case.
- Flash firmware to the RP2040 (if you want it to do stuff).

BOM / costs (rough)
- BOM in `production/PCB/BOM.csv` — i kept track of parts there.
- cost varies by where u buy stuff; this was more a learning exercise for me.

License
MIT — see `LICENSE`.

Credits
- KiCad, FreeCAD, misc parts libraries

If u want: i can rewrite this more, add pics, or drop a short firmware guide.

Last updated: 2026-06-19
