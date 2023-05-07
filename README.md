# Example Entities Library

This is a clean library base for your own Serious Sam entities based on [this Serious Sam Mod SDK](https://github.com/DreamyCecil/SE1-ModSDK).

This SDK contains an example library with one entity that can display information about all players. The project files were created for Visual Studio 2013 and newer.

- If you want your entities to depend on vanilla ones, you have to include headers from `EntitiesV` and optional `GameV` directories into your code and link vanilla libaries.
  - You can see this dependency implementation in the example project. Look for the `VANILLA_ENTITIES` macro switch.
- Alternatively, you can freely move `CustomEntites` folder into the mod SDK and build entity packs with the mod.

### You don't have to clone this entire repository just for another entity pack.

If you wish to create other entity packs, you can base it off renamed `CustomEntities` project and add it to the main solution (`EntitiesLib.sln`).

## Building

To compile the library, you'll need to use a compiler from Microsoft Visual C++ 6.0.

Full guide: https://github.com/DreamyCecil/SE1-ModSDK#building

## Running

Once the project is compiled, the library (e.g. `CustomEntitiesMP.dll`) is automatically placed into the Bin folder one level above the sources folder (e.g `C:/SeriousSam/Bin` if the sources are in `C:/SeriousSam/Sources`).

To change the path where to copy the library (if you wish to put sources separately from the game), consider changing the path in the post-build step (**Project properties** -> **Build Events** -> **Post-Build Step** -> **Command Line**).

How to use your new entities in the game:
1. Copy the compiled library into the Bin folder (e.g. `C:/SeriousSam/Bin`).
2. Create a `ECL` (Entity Class Link) file with your entity in it. Entity Class Link file example can be found in `Classes/ExampleEntity.ecl`.
3. Add your class file into the virtual tree in Serious Editor.

And then you'll be able to use your entity just like any other entity.

When running a selected project, make sure the path in project properties **Debugging** -> **Command Arguments** is set to `SeriousEditor.exe` or `SeriousSam.exe` from the game where you copy your library to (e.g. `C:/SeriousSam/Bin/SeriousSam.exe`).

## License

Just like Croteam's [Serious Engine 1.10](https://github.com/Croteam-official/Serious-Engine) source code, Serious Sam SDK is licensed under the GNU GPL v2 (see LICENSE file).
