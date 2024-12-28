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
Download the [GearboxNext-windows.7z]() and unpack. Launch GearboxNext.exe. If you are using Windows 11, run in Windows 8 compatibility mode.

### Building
#### Linux:
1. Install qt6-base for your distribution.
2. Clone repository: `git clone https://github.com/Metvich/EasyGearBox.git`
3. Open the project folder: `cd GearBoxNext`
4. Configure the project: `cmake -S . -B build`
5. Build the project: `cmake --build build --config Release`
6. Install in the selected location: `cmake --install build --prefix ./out`

#### Windows:
1. Clone repository: `git clone https://github.com/Metvich/EasyGearBox.git`
2. Download from [qt6-base-windows]([https://download.qt.io/online/qtsdkrepository/windows_x86/desktop/qt6_672/qt.qt6.672.win64_msvc2019_64/6.7.2-0-202406110335qtbase-Windows-Windows_10_22H2-MSVC2019-Windows-Windows_10_22H2-X86_64.7z.mirrorlist](https://mirrors.tuna.tsinghua.edu.cn/qt/online/qtsdkrepository/windows_x86/desktop/qt6_690/qt6_690/qt.qt6.690.win64_msvc2022_64/6.9.0-0-202412120612qtbase-Windows-Windows_11_23H2-MSVC2022-Windows-Windows_11_23H2-X86_64.7z)) and unpack.
3. Open cmd in the project folder.
4. Configure a project for Visual Studio 2017 with a qt_toolchain file from qtbase: `cmake-D CMAKE_TOOLCHAIN_FILE="*/lib/cmake/Qt6/qt.toolchain.cmake" -S . -B build`
5. Build the project: `cmake --build build --config Release`
6. Install in the selected location: `cmake --install build --prefix ./out`

> Insert the path to the qtbase directory together with the "*" in the fourth step
