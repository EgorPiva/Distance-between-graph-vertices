@echo off
REM Скрипт для сборки проекта

REM Путь к Qt
SET QTDIR=C:\Qt\Qt5.15.2\5.15.2\mingw81_64
SET PATH=%QTDIR%\bin;C:\Qt\Qt5.15.2\Tools\mingw810_64\bin;%PATH%

:menu
cls
echo ===================================
echo Qt Client Server Build System
echo ===================================
echo.
echo Build options:
echo 1. Build project
echo 2. Clean project
echo 3. Generate documentation
echo 4. Exit
echo.

set /p option="Enter option (1-4): "

if "%option%"=="1" goto build
if "%option%"=="2" goto clean
if "%option%"=="3" goto docs
if "%option%"=="4" goto end

echo Invalid option
pause
goto menu

:build
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
pause
goto menu

:clean
REM Очистка проекта
echo Очистка проекта...
if exist build rmdir /s /q build
echo Проект очищен!
pause
goto menu

:docs
echo.
echo Generating documentation...
call generate_docs.bat
echo.
pause
goto menu

:end
echo Exiting...
exit /b 0 