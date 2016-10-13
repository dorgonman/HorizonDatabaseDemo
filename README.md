----------------------------------------------  
<h2 align="center">				
			HorizonDatabasePlugin<br>
					0.2.0(beta)   <br>
			http://dorgon.horizon-studio.net  <br>
				dorgonman@hotmail.com  <br>
</h2>
----------------------------------------------  

The goal of thie plugin is to provide a SOCI wrapper for UE4 and ORM ability.  

What is SOCI? It is a C++ Database Access Library, you can check detail [here](https://github.com/SOCI/soci).    

You can find document here: [doc/doxygen/html/index.html](http://horizon-studio.net/ue4/horizon_database_plugin/doc/doxygen/html/index.html)  

-----------------------  
System Requirements
-----------------------  

Tested UnrealEngine version: 4.13

-----------------------
Installation Guide
-----------------------  

put HorizonDatabasePlugin into YOUR_PROJECT/Plugins folder, 
and then add module to your project 
YOUR_PROJECT.Build.cs:
PublicDependencyModuleNames.AddRange(new string[] { "HorizonDatabase"});



-----------------------
Technical Details
-----------------------  

List of Modules: HorizonDatabaseEditor(Editor), HorizonDatabase (Runtime)  

Tested Engine veriosn: 4.13.

Windows: tested.

MACOSX: Failed. need modify engine(Engine/Source/Programs/UnrealBuildTool/Mac/MacToolChain.cs) to enable rtti.

Android: tested, need cherry pick this commit and rebuild engine source code.

iOS: not tested, need cherry pick this commit and rebuild engine source code.

Linux: not tested.

Demo Project: https://github.com/dorgonman/HorizonHorizonDatabaseDemo 


-----------------------
Contact and Support
-----------------------  

email: dorgonman@hotmail.com


-----------------------
 Version History
-----------------------  

* 0.2.0
 - Refactor: Implement and adjust function for blueprint
 - BugFix: Fix UTF8 type_conversion from db to FString

* 0.1.0
 - NEW: First Version including core features.
