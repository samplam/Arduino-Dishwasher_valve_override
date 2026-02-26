# Arduino-Dishwasher_valve_override
Simple program that runs on an Attiny85. It's function is to override a Bosh 500 dishwasher filling valve TRIAC at very specific moments to maximize the draining of the dirty and difficult to completely flush water located in the sump area during a cycle.

## Overview
This project is an Arduino-based that I made to override a Bosh 500 dishwasher filling valve TRIAC at very specific moments to maximize the draining of the dirty and difficult to completely flush water located in the sump area water during a cycle. The input signal from the drain pump has to be interfaced with an opto-coupler circuit. The output is a simple relay contact that short the TRIAC on the dishwasher's main PCB.

## Features
- Basic automation functions, loops and logic  
- Commented and structured code for readability

## Skills Highlighted
- Programming in C/C++ for microcontrollers
- Basic electronics and automation principles

## Usage
1. Open `Dishwasher_valve_override_v2025-04.ino` in Arduino IDE  
2. Upload to the Arduino board
3. Connect the input and output as per requirements
4. Test the program
