# GearboxNext 🎉

## Описание

Это программа создана для помощи в настройке коробок передач в Stormworks. Она перебирает все комбинации включения коробок передач, сортирует результат и убирает повторяющиеся значения. 

Результатом работы является 2-мерный массив. Он используется в этом [контроллере](https://steamcommunity.com/sharedfiles/filedetails/?id=2852692348).

[Гайд по пользованию](https://youtu.be/WhTUE5Qy-hM)

## Установка
### Собранные решения

#### Linux
Установите qt6-base, скачайте архив GearboxNext-linux.7z и распакуйте. Запустите GearboxNext.

#### Windows
Скачайте архив GearboxNext-windows.7z и распакуйте. Запустите GearboxNext.exe.


### Cборка

#### Linux:
1. Установите qt6-base для вашего дистрибутива.
2. Склонировать репозиторий: `git clone https://github.com/Metvich/EasyGearBox.git`
3. Открыть папку с проектом: `cd GearBoxNext`
4. Создать папку build и открыть её: `mkdir build && cd build`
5. Сконфигурировать CMake проект: `cmake -G Ninja ..`
6. Собрать проект: `ninja`

#### Windows:
1. Склонировать репозиторий: `git clone https://github.com/Metvich/EasyGearBox.git`
2. Скачать [qt6-base-windows](https://download.qt.io/online/qtsdkrepository/windows_x86/desktop/qt6_672/qt.qt6.672.win64_msvc2019_64/6.7.2-0-202406110335qtbase-Windows-Windows_10_22H2-MSVC2019-Windows-Windows_10_22H2-X86_64.7z.mirrorlist) и распаковать.
3. Сконфигурировать проект под Visual Studio 2017 qt_toolchain файлом из qt6-base (*/lib/cmake/Qt6/qt.toolchain.cmake)
4. Открыть .sln файл.
5. Собрать с помощью VS проект.
6. В папку Output скопируется .exe файл и необходимые библиотеки.

> Если использовать компилятор MinGw, то нужны следующие .dll: libstdc++-6.dll,  libgcc_s_seh-1.dll libwinpthread-1.dll. Их можно найти в 'mingw64/bin'.
