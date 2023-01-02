# DLL Sideload
## _DLL Sideload without DLL Main_

## Blogpost
Find the reference blogpost at https://www.redteam.cafe/red-team/dll-sideloading/dll-sideloading-not-by-dllmain

## How to run 
Find the sideload using the loadlibrary.js 
```
frida -f C:\Windows\System32\WFS.exe -l loadlibrary.js 
```
Lookout for GetProcAddress calls and find the DLL name and function.
Modify the sure.js to confirm the sideload 
```
frida -f C:\Windows\System32\WFS.exe -l sure.js --pause
%resume
```
Find the DLL exports using comment.py

Put all things together in Visual Studio 
