# o3de-workshops-2022

This repository contains asset gems and project files used in workshops during the  O3Dcon 2022.  Instructions for each workshop are detailed below.

# Workshop: World Building

### Project: Procedural-Worlds

A content sample project for Open 3D Engine (O3DE) that contains a series of procedural world examples, used in the O3Dcon 2022 workshop "World Building with O3DE"

![image](https://user-images.githubusercontent.com/23222931/196006789-299b2e9f-f864-4a2a-988d-b75476ec043c.png)

#### 1. Set up the Engine

Either build the installer yourself (*cmake --build build/windows_vs2019 --target INSTALL --config profile), or download the 22.10 release,* or download the latest nightly install build https://o3debinaries.org/development/Latest/Windows/o3de_installer.exe

This repository uses Git LFS for storing large binary files. You will need to create a Github personal access token to authenticate with the LFS service.

#### Create a Git Personal Access Token

You will need your personal access token credentials to authenticate when you clone the repository.

[Create a personal access token with the 'repo' scope.](https://docs.github.com/en/github/authenticating-to-github/creating-a-personal-access-token)

#### (Recommended) Verify you have a credential manager installed to store your credentials

Recent versions of Git install a credential manager to store your credentials so you don't have to put in the credentials for every request. It is highly recommended you check that you have a [credential manager installed and configured](https://github.com/microsoft/Git-Credential-Manager-Core)

#### Step 2. Clone the workshop repository

You can clone the project to any folder locally, including inside the engine folder. If you clone the project inside an existing Git repository (e.g. o3de) you should add the project folder to the Git exclude file for the existing repository.ne-the-repository)

##### Option #1 (Highly Recommended) - cloning into a folder outside the engine repository folder

```shell
# clone the project into a folder outside your engine repository folder
> git clone https://github.com/o3de/o3de-workshops-2022.git
Cloning into 'o3de-workshops-2022'...
```

##### Option #2 - cloning into the engine repository folder

```shell
# clone the project into a folder named 'o3de-workshops-2022 in your existing engine repository folder
> git clone https://github.com/o3de/o3de-workshops-2022.git c:/path/to/o3de/o3de-workshops-2022
Cloning into 'o3de-workshops-2022'...

# modify the local engine git exclude file to ignore the project folder
> echo o3de-workshops-2022 > c:/path/to/o3de/.git/info/exclude
```

If you have a Git credential helper configured, you should not be prompted for your credentials anymore.

### Step 3. Register the Gems and Project with the engine

You may have already done this, these are the same steps as setting up the o3de-multiplayer sample project. But if you are adding them to your own project these are the steps to do so.

Make sure your engine is registered.

```batch
:: register the gems with the engine, you only need to do this once
> c:\path\to\o3de\scripts\o3de register --this-engine
```

Now make sure that the source gems are registered

```batch
:: register the gems with the engine, you only need to do this once
> o3de register --all-gems-path c:\path\to\o3de-workshops-2022\Gems
```

 The above command will recursively scan the input path, then registers all paths with gem.json files into the ~/.o3de/o3de_manifest.json  Now these Gems will be available in the Project Manager and can be added to your Project.

This repository contains it's own O3DE Game project

```shell
# the test project for mps assets, is in this project folder in repo
> cd C:\path\to\o3de-workshops-2022\Projects\Procedural-Worlds
```

### Option 1. Add Project to O3DE Project Manager

1. Launch your O3DE Project Manager (o3de.exe)

2. Use the blue button in the upper right labeled "New Project ...", and with the pulldown select "Open Existing Project"

3. Browse to and add the MPS Asset Test Project folder: C:\path\to\repo\o3de-workshops-2022\Projects\Procedural-Worlds

4. You may be prompted to rebuild the project (there are other options for building as a developer)

5. Launch the Editor for the project

### Option 2. Add via cli and build yourself

You can use the o3de cli tools to register your project with your engine.

```shell
# change directory to the egine root folder
> cd c:\path\to\your\o3de-engine
# register the gems with the engine, you only need to do this once
> scripts\o3de register --project-path C:\path\to\repo\o3de-workshops-2022\Projects\Procedural-Worlds
```

There are a number of ways to configure and build the engine and project ...

[Configure and Build - Open 3D Engine](https://www.o3de.org/docs/user-guide/build/configure-and-build/)

As a developer, I often find it useful to build in an engine-centric way

```batch
# change directory to the egine root folder
> cd c:\path\to\your\o3de-engine
# create a build folder
> mkdir build
> cd build
# configure cmake and create sollutiuon
> cmake .. -G "Visual Studio 16" -A x64 -DLY_3RDPARTY_PATH="%LY_3RDPARTY_PATH%" -DLY_UNITY_BUILD=OFF -DLY_PROJECTS="C:\path\to\repo\o3de-workshops-2022\Projects\Procedural-Worlds"
```

This should generate a build\O3DE.sln file, which can be opened in Visual Studio 2019 and compiled.

Don't forget to build the project in Profile

![image](https://user-images.githubusercontent.com/23222931/185497967-b94e1e5e-722c-4b84-b950-a00477343e56.png)

Building the Editor project will build with all dependencies.

![image](https://user-images.githubusercontent.com/23222931/185498026-0f235b71-ff10-4135-8008-ba067b6a285b.png)

The built binary executables will be in:

```shell
# bin folder
> cd C:\depot\o3de-dev\build\bin\profile\
# executbales
# C:\depot\o3de-dev\build\bin\profile\o3de.exe
# C:\depot\o3de-dev\build\bin\profile\editor.exe
# ...
```

If this is the project you are primarily working with, you can also set it as the "default project".

```shell
# change directory to the egine root folder
> cd c:\path\to\your\o3de-engine
# register the gems with the engine, you only need to do this once
> scripts\o3de set-global-project -pp <project-path>
```

This will make this the project that launches by default if you manually directly double-click on a o3de executable like editor.exe

## License

For terms please see the LICENSE*.TXT file at the root of this distribution.

// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.  
// SPDX-License-Identifier: CC-BY-4.0
