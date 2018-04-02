# Interacting with HTTP servers in Unreal
([back to Index](Index.md))

This is very much a work in progress. Resources used so far:
* https://wiki.unrealengine.com/Http-requests
* http://www.wraiyth.com/?p=198 and http://www.wraiyth.com/?p=222

## Preparation
I created a Python SimpleHTTPServer that will serve static files from a folder. See [http web server](/src/helper/pythonHttp)
Start a command line and run the `start.sh` script. This will make the webserver available at http://localhost:8080 

You can test this with curl or a browser.

## Steps to get it working
1. Add Http, Json, and JsonUtilities modules to the project:
    * In {project}.Build.cs add/update the line with `PrivateDependencyModuleNames.AddRange` to include them (comma separated strings)
    * save the file
1. Rebuild the project in Unreal (File->Refresh CLion Project) 
1. Create a new C++ class, parent is 'Actor'. I called it HelloWorldService (see [sample folder](/src/http))
1. Compile the project in Unreal Editor (in CLion build fails or takes forever)
1. Drag the HelloWorldService class onto your level
1. Run
1. Observe the log window has a warning displaying the helloworld message
