@echo off
echo Generating documentation with Doxygen...

REM Check if Doxygen is installed
where doxygen >nul 2>&1
if %ERRORLEVEL% NEQ 0 (
    echo Error: Doxygen is not installed or not in PATH
    echo Please install Doxygen from http://www.doxygen.nl/download.html
    exit /b 1
)

REM Create docs directory if it doesn't exist
if not exist docs mkdir docs

REM Run Doxygen
doxygen Doxyfile

if %ERRORLEVEL% EQU 0 (
    echo Documentation generated successfully in docs/html/
    echo You can open docs/html/index.html in your browser
) else (
    echo Error generating documentation
)

exit /b 0 