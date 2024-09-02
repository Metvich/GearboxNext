# GearboxNext 🎉

## Description

This program is designed to help you set up gearboxes in Stormworks. It goes through all the combinations of gearboxes, sorts the result and removes duplicate values.

The result of the work is a 2-dimensional array. It is used in this [controller](https://steamcommunity.com/sharedfiles/filedetails/?id=2852692348).

[User Guide](https://youtu.be/ltSZGTZyRIM)

## Installation
### The assembled solutions

#### Linux:
Install qt6-base, download the [GearboxNext-linux.7z](https://github.com/Metvich/GearboxNext/releases/latest/download/GearboxNext-linux.7z) and unpack. Launch GearboxNext.

#### Windows:
Download the [GearboxNext-windows.7z]() and unpack. Launch GearboxNext.exe .

### Building
#### Linux:
1. Install qt6-base for your distribution.
2. Clone repository: `git clone https://github.com/Metvich/EasyGearBox.git`
3. Open the project folder: `cd GearBoxNext`
4. Create a build folder and open it: `mkdir build && cd build`
5. Configure the CMake project: `cmake -G Ninja ..`
6. Build a project: `ninja`

#### Windows:
1. Clone repository: `git clone https://github.com/Metvich/EasyGearBox.git`
2. Download from [qt6-base-windows](https://download.qt.io/online/qtsdkrepository/windows_x86/desktop/qt6_672/qt.qt6.672.win64_msvc2019_64/6.7.2-0-202406110335qtbase-Windows-Windows_10_22H2-MSVC2019-Windows-Windows_10_22H2-X86_64.7z.mirrorlist) and unpack.
3. Configure a project for Visual Studio 2017 with a qt_toolchain file from qt6-base(*/lib/cmake/Qt6/qt.toolchain.cmake)
4. Open the .sln file.
5. Build a project using VS.
6. It will be copied to the Output folder the .exe file and the necessary libraries.

> If you use the MinGW compiler, you need the following .dll: libstdc++-6.dll , libgcc_s_seh-1.dll libwinpthread-1.dll . They can be found in 'mingw64/bin'.
