# Golf-Ball-Dispenser-Project


## Overview
This project incorporates CAD and Arduino electronics to produce an automatic electro-mechanical machine that drops golf ball when user holds golf club to ultrasonic sensor. The system waits for 2 continuous seconds of presence in front of the ultrasonic sensor before dispensing ball to ensure golfer only receives a ball when they are ready. Because 3D printing capabilities were limited, the project has two parts with a functional electronic test-bench and a production ready 3D CAD Design.

## Proof of Concept and 3D CAD Assembly
**Physical Electronic Prototype:** 


### Hardware Design and Arduino: 
**Microcontroller:** Arduino UNO R3

**Actuator:** SG90 Servo Motor

**Sensor:** HC-SR04

**CAD Software:** OnShape

**Component Models:** Arduino UNO R3 and its associated components were sourced via GrabCad to ensure accurate mounting and spacing

**Storage:** Commercial Golf Klicka Stick used as golf ball storage magazine

### Software
**Languages:** C++ (Arduino IDE)
**Libraries:** '<Servo.h>'

## Repository Structure
* **`/Firmware`** — Contains the embedded software controlling the system logic.
  * `golf_ball_dispenser.ino` — The full Arduino C++ production code handling distance sensing, 2-second timing verification, and servo gate control.
* **`/Hardware`** — Houses all CAD assemblies files.
  * `Indvdual_CAD_Models/` — Individual `.stl` part exports (Housings, Ramps, Doors, Hinges) ready for 3D printing slicing software.
  * 'Master_Assembly/` — The fully integrated mechanical assembly file, detailing how the individual parts are assembled.
  * `Source_Cad/` — Raw workspace and design history on the main OnShape workspace.

### How it Works
1. The Servo Motor arm hold queue of golf balls on ramp.
2. The HC-SR04 Sensor constantly monitors the golf club view zone (10 cm from sensor).
3. When HC-SR04 Sensor detects object in golf club view zone vicinity for longer than 2 seconds then it sends signal to Arduino.
4. Arduino signals Servo Motor to rotate 180 degrees allowing for one golf ball to be released from the ramp.
5. The system enters a cool down so a double dispensing does not occur.


