@echo off
REM ================================================
REM DirStructGen - Windows Batch Wrapper
REM Author: Lakan Haraya Dima
REM Purpose: Convenient wrapper para sa dirstructgen.py
REM ================================================

setlocal enabledelayedexpansion

REM Get script directory
set "SCRIPT_DIR=%~dp0"

REM ================================================
REM Try to find Python executable
REM ================================================

set "PYTHON_CMD="

REM Try 1: Python Launcher (modern, preferred)
where py >nul 2>&1
if %errorlevel% == 0 (
    set "PYTHON_CMD=py"
    goto :found_python
)

REM Try 2: Direct python in PATH (traditional)
where python >nul 2>&1
if %errorlevel% == 0 (
    set "PYTHON_CMD=python"
    goto :found_python
)

REM Try 3: python3 in PATH (some installations)
where python3 >nul 2>&1
if %errorlevel% == 0 (
    set "PYTHON_CMD=python3"
    goto :found_python
)

REM Python not found
echo.
echo  [ERROR] Python ay hindi nakita sa system!
echo.
echo  Kinakailangan: Python 3.8 o mas bago
echo.
echo  Solusyon:
echo    1. I-install ang Python mula sa https://www.python.org
echo    2. I-add sa PATH during installation
echo    3. I-run ang installer ulit gamit ang "Modify"
echo.
exit /b 1

REM ================================================
REM Run dirstructgen.py
REM ================================================

:found_python
%PYTHON_CMD% "%SCRIPT_DIR%dirstructgen.py" %*
exit /b %errorlevel%