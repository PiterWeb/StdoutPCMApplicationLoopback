# StdoutPCMApplicationLoopback
This programm is a modification of [Microsfot Sample ApplicationLoopback](https://github.com/microsoft/Windows-classic-samples/tree/main/Samples/ApplicationLoopback).

### Objective: 
Stream through stdout (only works on CMD, PowerShell does not work) PCM audio data to pipe to other programs like ffmpeg/ffplay ...

Example of use with ffmpeg (generate .wav file using pipe streaming):
```bash

StdoutPCMApplicationLoopback.exe 14136 | ffmpeg -f s16le -ac 2 -ar 44100 -i pipe: output.wav

```


