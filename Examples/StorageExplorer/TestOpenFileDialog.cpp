#include <windows.h>

#include <iostream>
#include <string>

void test() {
    //OPENFILENAME ofn;       // common dialog box structure
    //char szFile[260];       // buffer for file name
    //HANDLE hf;              // file handle

    //// Initialize OPENFILENAME
    //ZeroMemory(&ofn, sizeof(ofn));
    //ofn.lStructSize = sizeof(ofn);
    //ofn.hwndOwner = (HWND) 0;
    //ofn.lpstrFile = szFile;
    //// Set lpstrFile[0] to '\0' so that GetOpenFileName does not 
    //// use the contents of szFile to initialize itself.
    //ofn.lpstrFile[0] = '\0';
    //ofn.nMaxFile = sizeof(szFile);
    //ofn.lpstrFilter = "All\0*.*\0Text\0*.TXT\0";
    //ofn.nFilterIndex = 1;
    //ofn.lpstrFileTitle = NULL;
    //ofn.nMaxFileTitle = 0;
    //ofn.lpstrInitialDir = NULL;
    //ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

    //// Display the Open dialog box. 

    //if (GetOpenFileName(&ofn) == TRUE) {
    //    hf = CreateFile(ofn.lpstrFile,
    //        GENERIC_READ,
    //        0,
    //        (LPSECURITY_ATTRIBUTES)NULL,
    //        OPEN_EXISTING,
    //        FILE_ATTRIBUTE_NORMAL,
    //        (HANDLE)NULL);
    //}

    //std::cout << "Closed Dialog:" << std::endl;
    //std::cout << ofn.lpstrFile << std::endl;
}