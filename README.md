# C++ Programming Language | VS Code

This repository contains a development environment for Visual Studio code to be used by C++ Programming Language of AMA Online Education.

## Running on your Windows Machine

Before pressing "F5" or debugging, go to `Run and Debug` tab and from the dropdown change to `C++ Launch [windows local]`. Now you can press start debugging. Make sure your [MinGW](https://sourceforge.net/projects/mingw/) is installed on C:/MinGW, otherwise, you'll need to modify the configuration file on [.vscode/launch.json(Line 63)](.vscode/launch.json#63).

I made the application run on external terminal so you get the feel of what it's like when the application is running on it's own.

## Running on container

Instead of cloning this repo, you can run it on codespace. In that environment you don't need to change anything, just run it.

**Table of Contents**

- [Getting Started](docs/getting-started/README.md)
  - [Dev Container](docs/getting-started/dev-container/README.md)
    - [Installing the Pre-requisites](docs/getting-started/dev-container/README.md#installing-the-pre-requisites)
      - [Windows](docs/getting-started/dev-container/windows.md)
      - [macOS](docs/getting-started/dev-container/osx.md)
      - [Linux](docs/getting-started/dev-container/linux.md)
    - [Configuring the Visual Studio Code](docs/getting-started/dev-container/README.md#configuring-the-visual-studio-code)
    - [Cloning the Git Repository](docs/getting-started/dev-container/README.md#cloning-the-git-repository)
    - [Opening in Dev Container](docs/getting-started/dev-container/README.md#opening-in-dev-container)
  - [Bare Metal](docs/getting-started/bare-metal/README.md)
    - [Installing the Pre-requisites](docs/getting-started/bare-metal/README.md#installing-the-pre-requisites)
      - [Windows](docs/getting-started/bare-metal/windows.md)
      - [macOS](docs/getting-started/bare-metal/osx.md)
      - [Linux](docs/getting-started/bare-metal/linux.md)
    - [Configuring the Visual Studio Code](docs/getting-started/bare-metal/README.md#configuring-the-visual-studio-code)
    - [Cloning the Git Repository](docs/getting-started/bare-metal/README.md#cloning-the-git-repository)
    - [Opening in Bare Metal](docs/getting-started/bare-metal/README.md#opening-in-bare-metal)
- [Maintenace](docs/maintenance/README.md)
  - [Updating the CMake Version](docs/maintenance/README.md#updating-the-cmake-version)
  - [Updating the Dev Container Image](docs/maintenance/README.md#updating-the-dev-container-image)



