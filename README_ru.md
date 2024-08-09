# GearboxNext 🎉

## Описание

Это программа создана для помощи в настройке коробок передач в Stormworks. Она перебирает все комбинации включения коробок передач, сортирует результат и убирает повторяющиеся значения. 

Результатом работы является 2-мерный массив. Он используется в этом [контроллере](https://steamcommunity.com/sharedfiles/filedetails/?id=2852692348).

[Гайд по пользованию]()

## Установка
### Готовые решения

#### Linux
Установите qt6-base, скачайте файл GearboxNext и запустите его.

#### Windows
Скачайте архив GearboxNext-windows.7z и распакуйте в любом месте. Запустите GearboxNext.exe.


### Ручная сборка

#### Linux:
1. Склонировать репозиторий: `git clone https://github.com/your-username/EasyGearBox.git`
2. Открыть папку с проектом: `cd GearBoxNext`
3. Создать папку build и открыть её: `mkdir build && cd build`
4. Сконфигурировать CMake проект: `cmake -G Ninja ..`
5. Собрать проект: `ninja`

#### Windows:
1. Склонировать репозиторий: `git clone https://github.com/your-username/EasyGearBox.git`
2. Скачать с [qt6-base-windows](https://download.qt.io/online/qtsdkrepository/windows_x86/desktop/qt6_672/qt.qt6.672.win64_msvc2019_64/6.7.2-0-202406110335qtbase-Windows-Windows_10_22H2-MSVC2019-Windows-Windows_10_22H2-X86_64.7z.mirrorlist) и распаковать.
3. Сконфигурировать проект под Visual Studio 2017 с qt_toolchain файлом из qt6-base(*/lib/cmake/Qt6/qt.toolchain.cmake)
4. Открыть .sln файл.
5. Собрать с помощью VS проект.
6. В папку Output скопируется .exe файл и содержимое папки lib.

> В папке lib .dll файлы взяты из qt6-base//bin/ и qt6-base//plugins/