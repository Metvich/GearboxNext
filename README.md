# GearboxNext 🎉

## Описание

Это программа создана для помощи в настройке коробок передач в Stormworks. Она перебирает все комбинации включения коробок передач, сортирует результат и убирает повторяющиеся значения. 

Результатом работы является 2-мерный массив lua. Его использовать можно в этом [контроллере](https://steamcommunity.com/sharedfiles/filedetails/?id=2852692348).

## Установка
### Готовые решения

Для Windows скачайте архив GearboxNext-windows.7z и распакуйте в любом месте. Запустите GearboxNext.exe.

Для Linux установите qt6-base, скачайте файл GearboxNext и запустите его.

### Как скомпилировать

Linux:
1. Склонировать репозиторий: `git clone https://github.com/your-username/EasyGearBox.git`
2. Открыть папку с проектом: `cd GearBoxNext`
3. Создать папку build и открыть её: `mkdir build && cd build`
4. Сконфигурировать CMake проект: `cmake -G Ninja ..`
5. Собрать проект: `ninja`

Windows:
1. Склонировать репозиторий: `git clone https://github.com/your-username/EasyGearBox.git`
2. Скачать с [qt6-base-windows](https://download.qt.io/online/qtsdkrepository/windows_x86/desktop/qt6_672/qt.qt6.672.win64_msvc2019_64/6.7.2-0-202406110335qtbase-Windows-Windows_10_22H2-MSVC2019-Windows-Windows_10_22H2-X86_64.7z.mirrorlist) и распокавать.
3. Сконфигурировать проект под Visual Studio 2017 с qt_toolchain файлом
4. Открыть .sln файл.
5. Собрать с помощью VS проект.





**How to Use:**
-----------------

1. **Click on the Generate 🔥 button**: This will launch the gear ratio generator.
2. **Set Min and Max Gear Ratio 🔄**: Adjust the minimum and maximum gear ratios according to your needs.
3. **Click Calculate ➡️**: EasyGearBox will generate optimal gear sets based on your input.
4. **Click Minus 👋** (optional): Remove one of the generated gears from the list.
5. **Click Copy Gears 📄**: Get ready to paste the Lua code into Stormworks!

**Tips and Tricks:**

* Experiment with different ratio ranges to find the perfect setup for your game.
* Use the minus button to remove unwanted gear sets and streamline your results.

That's it! EasyGearBox is designed to be simple, intuitive, and powerful. Happy generating, and don't hesitate to reach out if you have any questions or feedback! 💬