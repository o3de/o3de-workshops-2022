@echo off
REM
REM Copyright (c) Contributors to the Open 3D Engine Project.
REM For complete copyright and license terms please see the LICENSE at the root of this distribution.
REM
REM SPDX-License-Identifier: Apache-2.0 OR MIT
REM
REM

:: Sets up environment for O3DE DCC tools and code access

:: Store current dir
%~d0
cd %~dp0
PUSHD %~dp0

:: Put you project env vars and overrides in this file

:: chanhe the relative path up to dev
set ABS_PATH=%~dp0

:: project name as a str tag
IF "%O3DE_PROJECT_NAME%"=="" (
    for %%I in ("%~dp0.") do for %%J in ("%%~dpI.") do set O3DE_PROJECT_NAME=%%~nxJ
    )

echo.
echo _____________________________________________________________________
echo.
echo ~    Setting up O3DE DSI %O3DE_PROJECT_NAME% Environment ...
echo _____________________________________________________________________
echo.
echo     O3DE_PROJECT_NAME = %O3DE_PROJECT_NAME%

:: if the user has set up a custom env call it
:: this should allow the user to locally
:: set env hooks like O3DE_DEV or O3DE_PROJECT
IF EXIST "%~dp0Env_Dev.bat" CALL %~dp0Env_Dev.bat

:: Constant Vars (Global)
SET DCCSI_GDEBUG=False
echo     DCCSI_GDEBUG = %DCCSI_GDEBUG%
SET DCCSI_DEV_MODE=False
echo     DCCSI_DEV_MODE = %DCCSI_DEV_MODE%
SET DCCSI_GDEBUGGER=WING
echo     DCCSI_GDEBUGGER = %DCCSI_GDEBUGGER%

:: Override the default maya version
IF "%MAYA_VERSION%"=="" (set MAYA_VERSION=2022)
echo     MAYA_VERSION = %MAYA_VERSION%

:: You can define the project name
IF "%O3DE_PROJECT%"=="" (set "O3DE_PROJECT=%O3DE_PROJECT_NAME%")
echo     O3DE_PROJECT = %O3DE_PROJECT%

CD /D ..

IF "%PATH_O3DE_PROJECT%"=="" (set "PATH_O3DE_PROJECT=%CD%")
echo     PATH_O3DE_PROJECT = %PATH_O3DE_PROJECT%

:: Change to root Lumberyard dev dir
:: You must set this in a User_Env.bat to match youe engine repo location!
IF "%O3DE_DEV%"=="" (set "O3DE_DEV=C:\Depot\o3de-engine")
echo     O3DE_DEV = %O3DE_DEV%

set "PATH_DCCSIG=%O3DE_DEV%\Gems\AtomLyIntegration\TechnicalArt\DccScriptingInterface"

CALL %PATH_DCCSIG%\Tools\Dev\Windows\Env_O3DE_Core.bat

:: add to the PATH here (this is global)
SET PATH=%PATH_O3DE_BIN%;%PATH_DCCSIG%;%PATH%

CALL %PATH_DCCSIG%\Tools\Dev\Windows\Env_DCC_Maya.bat

:: ide and debugger plug
set "DCCSI_PY_DEFAULT=%MAYA_BIN_PATH%\mayapy.exe"
echo     DCCSI_PY_DEFAULT = %DCCSI_PY_DEFAULT%

:: Some IDEs like Wing, may in some cases need acess directly to the exe to operate correctly
set "DCCSI_PY_IDE=%MAYA_BIN_PATH%\mayapy.exe"
echo     DCCSI_PY_IDE = %DCCSI_PY_IDE%

SET PATH=%MAYA_BIN_PATH%;%DCCSI_PY_IDE%;%DCCSI_PY_DEFAULT%;%PATH%

CALL %PATH_DCCSIG%\Tools\Dev\Windows\Env_O3DE_Python.bat

:: add to the PATH
SET PATH=%MAYA_BIN_PATH%;%PATH%

:: add all python related paths to PYTHONPATH for package imports
set PYTHONPATH=%DCCSI_MAYA_SCRIPT_PATH%;%PATH_O3DE_TECHART_GEMS%;%PATH_DCCSIG%;%PATH_DCCSI_PYTHON_LIB%;%PATH_O3DE_BIN%;%PYTHONPATH%

:: if the user has set up a custom env call it
:: this ensures any user envars remain intact after initializing other envs
IF EXIST "%~dp0Env_Dev.bat" CALL %~dp0Env_Dev.bat

:: Restore original directory
popd

:: Change to root dir
CD /D %ABS_PATH%

GOTO END_OF_FILE

:: Return to starting directory
POPD

:END_OF_FILE