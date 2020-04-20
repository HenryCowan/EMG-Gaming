## Unit-test demonstration: 
**This is a demonstration of the read-in of emg data, that is high-pass filtered (Fc = 2Hz), power-time-smoothed (5 samples) and sent through UDP to an Android server**

*This demonstration is for a 2 channel input

## Compilation
- When compiling using the cmake command from the terminal, the reading in from dat files often fails
- It is recommended to run in QT creator, although in QT creator new dat files cannot be exported with the fopen command
