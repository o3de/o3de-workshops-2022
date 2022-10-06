@echo off
REM
REM Copyright (c) Contributors to the Open 3D Engine Project.
REM For complete copyright and license terms please see the LICENSE at the root of this distribution.
REM
REM SPDX-License-Identifier: Apache-2.0 OR MIT
REM
REM

echo.
echo ~   Adding local Dev_Env settings:
echo ~  Procedural-Worlds\Gems\Building-Blocks\Tools\Env_Dev.bat
echo.


set DCCSI_GDEBUG=True

set DCCSI_DEV_MODE=False

set DCCSI_GDEBUGGER=WING

:: Default level logger will handle
:: Override this to control the setting
:: CRITICAL:50
:: ERROR:40
:: WARNING:30
:: INFO:20
:: DEBUG:10
:: NOTSET:0
set DCCSI_LOGLEVEL=10

set O3DE_DEV=C:\Depot\o3de-dev

set "O3DE_BUILD_FOLDER=Build\bin\profile"

set PATH_O3DE_BIN=%O3DE_DEV%\%O3DE_BUILD_FOLDER%

:: Default Maya and Python version
set MAYA_VERSION=2022
set DCCSI_PY_VERSION_MAJOR=3
set DCCSI_PY_VERSION_MINOR=7
set DCCSI_PY_VERSION_RELEASE=7