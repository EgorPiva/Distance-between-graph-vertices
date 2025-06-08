@echo off
REM Скрипт для сборки проекта

REM Путь к Qt
SET QTDIR=C:\Qt\Qt5.15.2\5.15.2\mingw81_64
SET PATH=%QTDIR%\bin;C:\Qt\Qt5.15.2\Tools\mingw810_64\bin;%PATH%

REM Очистка и пересборка проекта
echo Очистка проекта...
if exist build rmdir /s /q build
mkdir build
cd build

echo Запуск qmake...
qmake ..\QtClientServer.pro -spec win32-g++ CONFIG+=debug

echo Сборка проекта...
mingw32-make -j4

echo Готово!
cd .. 