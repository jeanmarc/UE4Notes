# UE4Notes
Repository with my notes on using Unreal Engine 4 on Linux.

Go to the [main index page](doc/Index.md)

I created this repo to document the knowledge gathered during my getting acquainted with Unreal Engine 4 on Linux.
This is an ongoing journey (well, at least as long as you see recent commits to this repo ;) ), and may not be the
most effective way for you to follow. I use it mainly for my own reference and to be able to pick up where I left off
if I happen to get caught in other distractions (like work :P).

Some background: I am an experienced Java developer (with some ancient C++ knowledge), that has a passion for Computer
Graphics. Some 15 years ago I was actively building my own Graphics engine, in C++ using OpenGL. Then kids happened :D.
Now, the kids are 15 and 13, some free time comes available again. I wanted to pick up Graphics again and looked
around what is available at the moment.

My son is really enjoying Rocket League, and since a couple of months Fortnite. I noticed these are games built with
Unreal Engine, which I of course knew from my ancient gaming times (Doom, Unreal, Unreal Tournament), so I decided to
take a closer look. Unreal blew my mind. Beautiful graphics, a complete development environment, and completely free 
until you start making actual money off a game you develop. This is one beast I want to master.

C++ apparently has evolved quite a bit as well, so there will be lots to (re)learn there as well.

Me being me, I never take the easy route, so it has to be on Linux (I fail to be productive on Windows or Macs),
and it has to be CLion (being an IntelliJ user for my profesisonal job, I really like the familiar look & feel).

I have a basic setup working, but now and then stuff breaks and sometimes I have to start over. Hopefully I will be 
able to stabilize the setup in such a way that I can actually start creating levels and interaction. Stay tuned.

Jean-Marc van Leerdam
April 2018

## My setup
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
