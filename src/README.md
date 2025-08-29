Control software
====

This directory contains the ESP32 firmware for ROBODYNAMOS, organized per challenge round.

Structure
----

- Round 1/
  - Library_declarations.ino — common includes, pin maps, configuration
  - Open_Challenge_code.ino — lane following, turning, and parking logic
- Round 2/
  - Library_declarations.ino — shared declarations for obstacle round
  - Obstacle_challenge.ino — obstacle avoidance and box/turn handling

Build and upload
----

1) Open the required .ino in Arduino IDE
2) Board: ESP32 Dev Module (ESP32 core)
3) Port: select the ESP32 COM port
4) Upload and then calibrate steering center and distance thresholds