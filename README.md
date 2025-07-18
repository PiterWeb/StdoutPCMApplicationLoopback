# StdoutPCMApplicationLoopback
This programm is a modification of [Microsoft Sample ApplicationLoopback](https://github.com/microsoft/Windows-classic-samples/tree/main/Samples/ApplicationLoopback).

> [!WARNING]  
> The software only works on Windows OS

### Objective: 
Stream through stdout (only works on CMD, PowerShell does not work) PCM audio data to pipe to other programs like ffmpeg/ffplay or any that can read PCM from stdin.

Example of use with ffmpeg (generate .wav file using pipe streaming):
```bash

StdoutPCMApplicationLoopback.exe <pid> | ffmpeg -f s16le -ac 2 -ar 44100 -i pipe: output.wav

```

### Build:
Follow the [build instructions of the original project](https://github.com/microsoft/Windows-classic-samples/tree/main/Samples/ApplicationLoopback#to-build-the-sample-using-the-command-prompt)
