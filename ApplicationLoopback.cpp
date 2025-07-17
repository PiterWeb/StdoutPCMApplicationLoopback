// ApplicationLoopback.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include <iostream>
#include "LoopbackCapture.h"
#include <fcntl.h>
#include <io.h>


void usage()
{
    std::wcout <<
        L"Usage: ApplicationLoopback <pid> <outputfilename>\n"
        L"\n"
        L"<pid> is the process ID to capture or exclude from capture\n"
        L"<outputfilename> is the WAV file to receive the captured audio (10 seconds)\n"
        L"\n"
        L"Examples:\n"
        L"\n"
        L"ApplicationLoopback 1234 includetree CapturedAudio.wav\n"
        L"\n"
        L"  Captures audio from process 1234 and its children.\n";
}

int wmain(int argc, wchar_t* argv[])
{
    //_setmode(_fileno(stdout), _O_BINARY);

    if (argc != 2)
    {
        usage();
        return 0;
    }

    DWORD processId = wcstoul(argv[1], nullptr, 0);
    if (processId == 0)
    {
        usage();
        return 0;
    }

    bool includeProcessTree = true;

    CLoopbackCapture loopbackCapture;
    HRESULT hr = loopbackCapture.StartCaptureAsync(processId, includeProcessTree);
    if (FAILED(hr))
    {
        wil::unique_hlocal_string message;
        FormatMessageW(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS | FORMAT_MESSAGE_ALLOCATE_BUFFER, nullptr, hr,
            MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (PWSTR)&message, 0, nullptr);
        std::wcout << L"Failed to start capture\n0x" << std::hex << hr << L": " << message.get() << L"\n";
    }
    else
    {

        // Sleep 1s infinite
        while (true) {
            Sleep(1000);
        }

    }

    return 0;
}
