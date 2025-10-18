## About

The simplest temperature measurement station was built during this project, all the necessary and detailed information is in [pdf](./Report.pdf) file.
![photo](./images/20250127_172856.jpg)


## Key results

- System performs cyclic, synchronous measurement of process value (controlled variable) with
constant sample time.
- System allows for process control in safe range of process value.
- System ensures steady-state error at 5% of the control range
- System allows to set a reference value (set-point) with serial port
- System allows reading current values of: measurement, reference and control signals with serial
port

## Hardware and software

The project was completed using STM32CubeIDE version 1.16.1 on NUCLEO development kit with the STM32F746ZG microcontroller + Temrinal app which communicates through UART.

##IMPORTANT

For better performance it is suggested to use higher power supply(I used 9V battery which turned out not to be enough) and retune gains. In my case the PID controller is very sluggish.

