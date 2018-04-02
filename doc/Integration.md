# CLion and Unreal integration
([back to Index](Index.md))

As of Unreal 4.19 the CLion plugin is bundled with the Engine, and you only have to activate it. However, on Linux
the detection of the CLion start script may fail, as the plugin searches only in a single location:

```/opt/clion/bin/clion.sh```

To make it work I created a symlink in the `/opt/clion/bin` folder to the actual CLion start script like this
(replace {CLionInstallFolder} with the actual folder where CLion is installed):

```
sudo mkdir -p /opt/clion/bin
sudo ln -s {CLionInstallFolder}/bin/clion.sh /opt/clion/bin/clion.sh
```

## Compile errors referencing Steamv139 or other Steam versions

Source: [Bug report of old CLion plugin](https://github.com/dotBunny/CLionSourceCodeAccess/issues/95)

If the compiler output shows something like:

```
clang: error: no such file or directory: '('
clang: error: no such file or directory: '1.39'
clang: error: no such file or directory: ')'
clang: error: no such file or directory: '('
clang: error: no such file or directory: 'Steamv139'
clang: error: no such file or directory: ')'
```

This can be fixed by changing the CMakefileGenerator.cs file. As S.Marais says in his comment:
```
I finally found the problem in UE 4.19 and it's nothing to do with CLion 2.0. 
The problem is in the CMakefileGenerator.cs in UE4. Preprocessors from Intellisense are the ones used to create the 
cmake definitions and the steam sdks' ones come with TEXT(""). Editing the CMakefileGenerator.cs line 389 like the 
following solves the issue:

string Definition = PreProcessorDefinition.Replace("TEXT(\"", "").Replace("\")", "");

You can find the same line in UE 4.18 at line 191. Replacing it with the one above should solve the issue.

``` 
