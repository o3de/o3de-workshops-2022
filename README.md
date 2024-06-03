<u>Supported o3de versions</u> : **23.10**

# O3DCon 2022 Workshops

![gameplay](doc/gameplay.gif?raw=true)

This repository contains a series of procedural world examples, used in the O3Dcon 2022 workshop "World Building with O3DE". The video conference to follow along [is available here](https://www.youtube.com/watch?v=x5NtCK15AGo) and the slides [are available here](doc/O3DECon_2022_JKG_WorldBuilding.pdf).

A similar workshop for multiplayer games [is available here](https://github.com/AMZN-Gene/o3dcon-2022-multiplayer-workshop)

## Prerequisites

You need to build or [install O3DE engine](https://o3de.org/download/).

You need to [install git with lfs support](https://git-scm.com/downloads), and [setup a token on your github account](https://www.docs.o3de.org/docs/welcome-guide/setup/setup-from-github/#configure-credentials-for-git-lfs). Needed as the repository uses Git LFS, the "Download ZIP" button will not download assets.

## How to run

1. Clone the github repository (`git clone https://github.com/o3de/o3de-workshops-2022.git`). When prompted to authenticate, use your github username and the token as password.
2. Launch O3DE. It will open the Project manager. Click on the **New Project** button then **Open Existing Project** option.
3. Navigate to the cloned repository. Open the **Projects/Procedural-Worlds** folder. The project should now be registered.

![project](doc/cover.png?raw=true)

4. Click on the **Build Project** button, located on the **Procedural Worlds** image.
5. Once the project has been built successfully, use the **Open Editor** button.
6. The asset pre-processor will run for a bit. Once it is over you will be welcomed with the **Open a Level** window. Pick one as you like.

## Project Highlights

- **Terrain gem showcase** various terrain setups with high quality assets,
- **Procedural terrain generation** uses procedural generation to create terrain from a small set of data at runtime
- **PostFX rendering pass** use custom post process pass to improve the visuals

### Screenshots

![screenshot](doc/screenshot-1.png?raw=true)

![screenshot](doc/screenshot-2.png?raw=true)

![screenshot](doc/screenshot-3.png?raw=true)

## License

For terms please see the LICENSE*.TXT file at the root of this distribution.

