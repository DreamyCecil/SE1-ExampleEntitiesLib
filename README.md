# Custom Entities Library
This is a clean library base for your own Serious Sam entities based on Serious Sam SDK v1.07 by Croteam released in 2002.

This SDK contains only the engine headers and the project files were created for Visual Studio 2013 Professional edition.

If you wish to interract with vanilla Serious Sam entities directly from your library, include the `EntitiesMP` (and optional `GameMP`) project into this one. Then copy included `EntitiesMP` headers from `EntitiesMP/StdH/StdH.h` to `CustomEntities/StdH/StdH.h`.
A VS2013+ compatible version can be found at https://github.com/DreamyCecil/SeriousSam_SDK107

If you wish to create other entity packs, you can base it off renamed `CustomEntities` project and add it to the `EntitiesLib` solution (don't forget to reconfigure library names and paths).
No need to clone this entire repository for another entity pack.

Building
--------

To compile the library, you'll need to use a compiler from Microsoft Visual C++ 6.0.

Full guide: https://github.com/DreamyCecil/SeriousSam_SDK107#building

Running
-------

Once the project is compiled, there should be a `CustomEntitiesMP.dll` library in the release folder (`CustomEntities/Release`) and in the Bin folder one level above the sources folder (e.g `C:/SeriousSam/Bin` if the sources are in `C:/SeriousSam/Sources`).

To change the path where to copy the library (if you wish to put sources separately from the game), consider changing the path in the custom build step (**Project properties** -> **Custom Build Step** -> **Command Line**).

How to use your new entities in the game:
1. Copy the library into the same folder as `EntitiesMP.dll` (e.g. `C:/SeriousSam/Bin`).
2. Create a .ecl (Entity Class Link) file with your entity in it. Entity Class Link file example can be found in `Classes/ExampleEntity.ecl`.
3. Add your class file into the virtual tree in Serious Editor.

And then you'll be able to use your entity just like any other entity.

When running a selected project, make sure the path in project properties **Debugging** -> **Command Arguments** is set to `SeriousEditor.exe` or `SeriousSam.exe` from the game where you copy your library to (e.g. `C:/SeriousSam/Bin/SeriousSam.exe`).

License
-------

This project, along with the engine headers, is licensed under the GNU GPL v2 (see LICENSE file).

This SDK includes Croteam's Entity Class Compiler (`Extras/Ecc.exe`) that is used to compile entity source (`.es`) files and is officially distributed with classic Serious Sam games. Its source code is included in Serious Engine 1.10.

Some of the code included with the SDK may not be licensed under the GNU GPL v2:

* DirectX8 SDK (Headers & Libraries) (`d3d8.h`, `d3d8caps.h` and `d3d8types.h` located in `Extras` folder) by Microsoft
