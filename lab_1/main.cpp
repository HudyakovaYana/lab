#include <iostream>
#include <windows.h>
#include <sysinfoapi.h>
#include <stdio.h>
using namespace std;
extern "C" __declspec(dllimport)
BOOL __stdcall GetPhysicallyInstalledSystemMemory(PULONGLONG);
int main()
{
    ULONGLONG TotalMemoryInKilobytes;
    GetPhysicallyInstalledSystemMemory(&TotalMemoryInKilobytes);
    cout<<TotalMemoryInKilobytes/1024/1024<<" gb";
//    MEMORYSTATUSEX ram;

//    GlobalMemoryStatusEx(&ram);
//    cout<<(" RAM: %u\n", ram.ullTotalPhys/1024/1024/1024)<<" gb";

}
