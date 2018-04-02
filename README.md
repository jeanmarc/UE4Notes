# UE4Notes
Notes about using Unreal Engine 4 on Linux

## Setup
I am running Debian Stretch, and am using Unreal 4.19, checked out from github, in combination with CLion:

```
$ git remote -v
origin	git@github.com:EpicGames/UnrealEngine.git (fetch)
origin	git@github.com:EpicGames/UnrealEngine.git (push)

$ git branch
* 4.19

```

## Web resources
Some web sites and links I have collected over time that have helped me getting things up and running:

* Naming conventions and project structure related
    * https://wiki.unrealengine.com/Assets_Naming_Convention
    * https://arne-mertz.de/2016/06/organizing-directories-namespaces/
    
* General Information resources
    * http://api.unrealengine.com/INT/API/index.html

* CLion and Unreal
    * https://github.com/dotBunny/CLionSourceCodeAccess/issues/95 (explains how to fix build error caused by Steam defines - UE 4.19.1, CLion 2017.3, April 2018)

* Rigging
    * https://wiki.unrealengine.com/Exporting_the_Mannequin_Skeleton_from_Unreal_Engine_4_to_Blender_and_Re-importing
    * https://forums.unrealengine.com/development-discussion/animation/100864-tutorial-how-to-make-ue4-mannequin-in-blender
