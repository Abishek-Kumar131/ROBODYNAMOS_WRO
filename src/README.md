# WRO 2022 Front-End Template - Arduino Code Structure

This directory contains the Arduino code for the WRO 2022 competition, restructured following Arduino .ino file conventions.

## Structure Overview

### Round 1 - Open Challenge
Located in `Round 1/` folder:

- **Round1.ino** - Main file containing the loop function and global variables
- **ColorLineDetection.ino** - Function for detecting and initializing color line tracking
- **ColorLogicControl.ino** - Function for handling color-based turning logic
- **SideUltrasonicLogic.ino** - Function for side ultrasonic sensor navigation
- **BotShutdown.ino** - Function for safely stopping the robot
- **LeftStop.ino** - Function for left-side stopping maneuver
- **RightStop.ino** - Function for right-side stopping maneuver
- **EndStop.ino** - Function for final stopping sequence
- **Library_declarations.ino** - Hardware declarations, libraries, and utility functions

### Round 2 - Obstacle Challenge
Located in `Round 2/` folder:

- **Round2.ino** - Main file containing the loop function and global variables
- **BoxDetection.ino** - Function for detecting and handling colored boxes
- **FrontUltrasonicArray.ino** - Function for front ultrasonic sensor array processing
- **BufferLimit.ino** - Function for managing serial buffer
- **ColorLineDetection.ino** - Function for detecting and initializing color line tracking
- **ColorLogicControl.ino** - Function for handling color-based turning logic
- **SideUltrasonicLogic.ino** - Function for side ultrasonic sensor navigation
- **BotShutdown.ino** - Function for safely stopping the robot
- **LeftStop.ino** - Function for left-side stopping maneuver
- **RightStop.ino** - Function for right-side stopping maneuver
- **EndStop.ino** - Function for final stopping sequence
- **Library_declarations.ino** - Hardware declarations, libraries, and utility functions

## Arduino .ino File Rules Followed

1. **Folder Structure**: Each round is in its own folder, with the main .ino file named the same as the folder
2. **Main File**: Contains the `loop()` function and global variables
3. **Function Separation**: Each major function is in its own .ino file
4. **Automatic Inclusion**: Arduino IDE automatically includes all .ino files in the same folder
5. **Descriptive Names**: Function names have been made more descriptive and clear

## Key Changes Made

### Function Name Changes:
- `color_line_fun()` → `ColorLineDetection.ino`
- `color_logic_fun()` → `ColorLogicControl.ino`
- `side_us_logic_fun()` → `SideUltrasonicLogic.ino`
- `bot_shutdown()` → `BotShutdown.ino`
- `left_stop()` → `LeftStop.ino`
- `right_stop()` → `RightStop.ino`
- `end_stop()` → `EndStop.ino`
- `box_detection()` → `BoxDetection.ino`
- `fus_array()` → `FrontUltrasonicArray.ino`
- `buffer_limit()` → `BufferLimit.ino`

### Round 2 Specific Functions:
- `get_US_Values()` - Wrapper for ultrasonic sensor readings
- `get_CS_Values()` - Wrapper for color sensor readings

## Usage

1. Open the Arduino IDE
2. Open the folder for the desired round (Round 1 or Round 2)
3. The Arduino IDE will automatically compile all .ino files in the folder
4. Upload the code to your ESP32 board

## Hardware Requirements

- ESP32 Development Board
- Color Sensor (TCS34725)
- Ultrasonic Sensors (HC-SR04)
- Servo Motor
- DC Motors
- RGB LED
- DPDT Push Button

## Libraries Required

- Wire.h
- Adafruit_TCS34725.h
- ESP32Servo.h
- NewPing.h
- FastLED.h