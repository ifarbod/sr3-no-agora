# Saints Row: The Third - My Steelport Service Patch

## Overview

This patch resolves the stuttering issue in **Saints Row: The Third** caused by the game repeatedly trying to connect to the discontinued **My Steelport** service hosted by AgoraGames. By patching the game executable, we disable these unnecessary connection attempts for a smoother gameplay experience.

## How It Works

This patch will intercept the game's startup routine, and prevent it from attempting connections to the **My Steelport** service.

## Installation Guide

### Prerequisites

1. Download the **Ultimate ASI Loader**:
   - [Ultimate ASI Loader GitHub](https://github.com/ThirteenAG/Ultimate-ASI-Loader/releases/latest)

2. Ensure you have administrative privileges to modify files in the game directory. (Only if your Steam library is under `C:\Program Files (x86)`)

### Steps

1. **Download the Patch Files**
   - Download the [zip file containing the ASI file](https://github.com/ifarbod/sr3-no-agora/releases/latest).
   - Extract its contents, you can use Windows Explorer, WinRAR, 7-Zip, etc.

2. **Copy the ASI Loader DLL**
   - Rename `dinput8.dll` (from Ultimate ASI Loader) to `d3d11.dll`.
   - Place the renamed `d3d11.dll` in the game's installation directory. This is typically the folder containing the `SaintsRowTheThird_DX11.exe` file.

3. **Copy the Patch Script**
   - Copy the included `.asi` file from this repository to the game's installation directory.

4. **Launch the Game**
   - Run the game as usual. The patch will be applied automatically on startup.

---

## Notes

- Don't worry about getting a VAC ban, the game doesn't use it.
- If you experience issues, try verifying the integrity of the game files through Steam or Epic Games Store and reinstalling the patch.
- To uninstall, simply delete the `d3d11.dll` and `.asi` files from the game directory.

## Acknowledgments

- **Ultimate ASI Loader** by ThirteenAG
- PCGamingWiki forum discussions that identified the My Steelport service issue
