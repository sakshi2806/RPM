# RPM Measurement with ESP32

## Overview
This project measures the rotational speed (RPM) of an object using an IR sensor and an ESP32. The system uses FreeRTOS tasks to handle sensor readings and RPM calculations efficiently.

## Components Required
* ESP32 Development Board
* IR Sensor (e.g., reflective optical sensor)
* Reflective Tape (for wheel or fan)
* Connecting wires
* Breadboard

## Project Architecture
* **IR Sensor:**  Detects rotation and generates pulses.
* **ESP32:** Calculates RPM based on sensor pulses.
* **Task 1**: Reads pulses from the IR sensor and calculates the RPM.
* **Task 2:** Outputs the RPM to the Serial Monitor.

## Hardware Setup
1. Connect the IR Sensor to ESP32:
   * **IR Sensor VCC** to **ESP32 3.3V**
    * **IR Sensor GND** to **ESP32 GND**
    * **IR Sensor Signal Pin** to **ESP32 GPIO 4**
2. Reflective Tape Installation:
   * Stick reflective tape on the wheel or fan in a way that it is evenly spaced.
   * Ideally, place 4 pieces of reflective tape around the wheel or fan to ensure consistent pulse detection.


## Logic Overview 
1. **Initialization:**
   * **Serial communication** is started.
   * **Task 1** and **Task 2** are created and assigned to different CPU cores.
2. **Task 1:**
   * Monitors the IR sensor for pulses.
   * Counts pulses and calculates RPM based on time intervals.
   * Sets a flag when RPM data is ready and triggers Task 2.
3. **Task 2:**
   * Checks if RPM data is ready.
   * Outputs RPM to the Serial Monitor.
4. **Loop:**
   * The loop function is idle and allows tasks to run.


## Testing the Project
* **Upload the Code:** Use the Arduino IDE to upload the sketch to your ESP32.
* **Monitor RPM:** Open the Serial Monitor at 115200 baud rate to view RPM output.


## Troubleshooting
* **No RPM Output:** Ensure the IR sensor is connected correctly and the ESP32 is powered.
* **Inaccurate RPM:** Check sensor alignment and ensure the pulse counting logic is correct.

## Author
Sakshi Mishra


