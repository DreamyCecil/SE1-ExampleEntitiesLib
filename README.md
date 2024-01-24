# Example Entities Library

This is a clean library base for your own Serious Sam entities based on [Serious Engine 1 Mod SDK](https://github.com/DreamyCecil/SE1-ModSDK).

This example library contains an entity that can display information about all players. The project files were created for Visual Studio 2010 and newer.

### Notes

- If you want to create other entity packs, you can base them off renamed `CustomEntities` project and add them to `EntitiesLib.sln` instead of cloning the entire repository again.
- If you want your entities to depend on vanilla ones, you have to include headers from `EntitiesV` and optional `GameV` directories into your code to link vanilla libaries.
  - You can see this dependency implementation in the example project. Look for the `VANILLA_ENTITIES` macro switch.
- Alternatively, you can freely move `CustomEntites` folder into the mod SDK and build entity packs with your mod.

## Building

To compile the library, you'll need to use a compiler from Microsoft Visual C++ 6.0.

Full guide: https://github.com/DreamyCecil/SE1-ModSDK#building

## Running

Once the project is compiled, the library (e.g. `CustomEntitiesMP.dll`) is automatically placed into the Bin folder one level above the sources folder (e.g `C:/SeriousSam/Bin` if the sources are in `C:/SeriousSam/Sources`).

To change the path where to copy the library (if you wish to put sources separately from the game), consider changing the path in the post-build step (**Project properties** -> **Build Events** -> **Post-Build Step** -> **Command Line**).

### How to use your new entities in the game

1. Copy the compiled library into the Bin folder (e.g. `C:/SeriousSam/Bin`).
2. Create a `ECL` (Entity Class Link) file with your entity in it. Example can be found at `Classes/ExampleEntity.ecl`.
3. Add your class file into the virtual tree in Serious Editor.

And then you'll be able to use your entity just like any other entity.

## License

Just like Croteam's [Serious Engine 1.10](https://github.com/Croteam-official/Serious-Engine) source code, Serious Sam SDK is licensed under the GNU GPL v2 (see LICENSE file).
