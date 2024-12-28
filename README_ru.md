# GearboxNext 🎉

## Описание

Это программа создана для помощи в настройке коробок передач в Stormworks. Она перебирает все комбинации включения коробок передач, сортирует результат и убирает повторяющиеся значения. 

Результатом работы является 2-мерный массив. Он используется в этом [контроллере](https://steamcommunity.com/sharedfiles/filedetails/?id=2852692348).

[Гайд по пользованию](https://youtu.be/WhTUE5Qy-hM)

## Установка
### Собранные решения

#### Linux
Установите qt6-base, скачайте архив [GearboxNext-linux.7z](https://github.com/Metvich/GearboxNext/releases/download/v1.0.1/GearboxNext-linux.7z) и распакуйте. Запустите GearboxNext.

#### Windows
Скачайте архив [GearboxNext-windows.7z](https://github.com/Metvich/GearboxNext/releases/download/v1.0.1/GearboxNext-windows.7z) и распакуйте. Запустите GearboxNext.exe. Если используете Windows 11, запустите в режиме совместимости Windows 8.


### Cборка

#### Linux:
1. Установите qt6-base для вашего дистрибутива.
2. Склонировать репозиторий: `git clone https://github.com/Metvich/EasyGearBox.git`
3. Открыть папку с проектом: `cd GearboxNext`
4. Сконфигурировать проект: `cmake -S . -B build`
5. Собрать проект: `cmake --build build --config Release`
6. Установить в выбранное место: `cmake --install build --prefix ./out`

#### Windows:
1. Склонировать репозиторий: `git clone https://github.com/Metvich/EasyGearBox.git`
2. Скачать [qt6-base-windows](https://mirrors.tuna.tsinghua.edu.cn/qt/online/qtsdkrepository/windows_x86/desktop/qt6_690/qt6_690/qt.qt6.690.win64_msvc2022_64/6.9.0-0-202412120612qtbase-Windows-Windows_11_23H2-MSVC2022-Windows-Windows_11_23H2-X86_64.7z) и распаковать.
3. Открыть cmd в папке проекта.
4. Сконфигурировать проект под Visual Studio 2017 qt_toolchain файлом из qtbase: `cmake -D CMAKE_TOOLCHAIN_FILE="*/lib/cmake/Qt6/qt.toolchain.cmake" -S . -B build`
5. Собрать проект: `cmake --build build --config Release`
6. Установить в выбранное место: `cmake --install build --prefix ./out`
> Вместо "*" в четвертом шаге вставить путь до директории qtbase
