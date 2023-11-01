/*
LoaderMDO was used as Adibou3.EXE in Adibou 3 and as ADI5.EXE in ADI 5.
It was developed to be linked to Loader7.exe to run it.
***********************************************************************
This is just an attempt to recreate that EXE in C++ as it was developed.
It was originally developed for ADI 5 version 5.00 in the Year 2000
Requirements:
-  Compile under MSVC 6.0
Compiling:
- Compile in Release mode to get near the filesize of the original exe.
TODO:
- Try to match the original filesize (24kb)
- Try to strip out the Console window completely
*/

#include <windows.h>
#include <string>

	int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {


    // Create the ADI5_LAUNCH_MUTEX
    HANDLE mutex = CreateEvent(NULL, TRUE, FALSE, "ADI5_LAUNCH_MUTEX");

    if (mutex != NULL) {
        std::string command = "Loader7.exe";
        system(command.c_str());
        CloseHandle(mutex);
    }

    return 0;
}

