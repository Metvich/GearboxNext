# GearboxNext 🎉

## Description

This program is designed to help you set up gearboxes in Stormworks. It goes through all the combinations of gearboxes, sorts the result and removes duplicate values.

The result of the work is a 2-dimensional array. It is used in this [controller](https://steamcommunity.com/sharedfiles/filedetails/?id=2852692348).

[User Guide]()

## Installation
### Ready-made solutions --------------- ???

#### Linux:
Install qt6-base, Download the GearboxNext file and run it.

#### Windows:
Download the GearboxNext-windows.7z archive and unpack anywhere. Launch GearboxNext.exe.

### Manual assembly -------------- ???
#### Linux:
1. Clone repository: `git clone https://github.com/your-username/EasyGearBox.git`
2. Open the project folder: `cd GearBoxNext`
3. Create a build folder and open it: `mkdir build && cd build`
4. Configure the CMake project: `cmake -G Ninja ..`
5. Build a project: `ninja`

#### Windows:
1. Clone repository: `git clone https://github.com/your-username/EasyGearBox.git`
2. Download from [qt6-base-windows](https://download.qt.io/online/qtsdkrepository/windows_x86/desktop/qt6_672/qt.qt6.672.win64_msvc2019_64/6.7.2-0-202406110335qtbase-Windows-Windows_10_22H2-MSVC2019-Windows-Windows_10_22H2-X86_64.7z.mirrorlist) and unpack.
3. Configure a project for Visual Studio 2017 with a qt_toolchain file from qt6-base(*/lib/cmake/Qt6/qt.toolchain.cmake)
4. Open the .sln file.
5. Build a project using VS.
6. It will be copied to the Output folder the .exe file and the contents of the lib folder.