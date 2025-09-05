Modify
ROBODYNAMOS – Future Engineers Project Report
1. Introduction
The ROBODYNAMOS team is participating in the WRO Future Engineers Challenge with an autonomous vehicle designed to navigate, detect obstacles, and park with precision. This report documents the design, development, and implementation of our system, integrating hardware, software, and mechanical design for reproducibility and evaluation.

2. Repository Structure
Folder	Contents
t-photos/	Team images (formal & candid)
v-photos/	Six clear views of the vehicle
video/	Demo link and supporting notes
schemes/	Electrical layout, connectors, and system diagrams
src/	Firmware and control logic
models/	3D printable parts & CAD drawings
other/	Datasheets, pin maps, setup guides
3. Team Details
Role	Name	Department	Register No.
Mentor	Dr. M. Gomathy Nayagam	ASP / CSBS	—
Member	V. Abishek Kumar	CSBS	953624244003
Member	D. Mirjone	MECH	953624114018
Member	S. Madesh Sai Pratap	ECE	953624106057
	•	Team Name: ROBODYNAMOS
* Team ID: 1142

4. Project Overview
Our platform is a camera-assisted, sensor-aided autonomous car featuring:
* Front-wheel Anti Ackermann steering
* Speed control tuned for the WRO track
* Distance sensing fused with vision cues
* Obstacle avoidance & lane following
* Final parking maneuver after laps

5. Objectives
  . Design a stable and reliable autonomous vehicle.
  . Integrate ESP32-based control with modular software.
  . Use sensors + vision cues for robust lane following and obstacle handling.
  . Ensure easy reproducibility with open schematics, CAD models, and documented firmware.

6. Hardware System
6.1 Central Controller
* ESP32 MCU with PWM & GPIO control
* Motor driver for DC propulsion
* Ports for ultrasonic & vision sensors
6.2 Motors & Actuation
* Propulsion: DC gear motor (300 RPM)
* Steering: High-torque servo (±20° Ackermann steering)
6.3 Sensors
* Ultrasonic: Front and side ranging for obstacle detection
* Vision: Color sensor or phone-based system for lane and box recognition
6.4 Structure
* Lightweight rigid chassis (centralized mass)
* 3D-printed mounts for sensors, motors, and steering linkage

7. Software System
7.1 Development
* Arduino IDE (C/C++)
* Modular code for mobility, sensing, strategy, utilities
7.2 Workflow
1. Read sensors & vision inputs
2. Compute heading and speed
3. Apply throttle & steering
4. Execute tasks (straight, corner, obstacle, parking)

8. Dimensions & Specifications
Parameter	Value
Length	~280 mm
Width	~190 mm
Height	~250 mm
Weight (no phone)	~0.98 kg
Wheel Diameter	~67 mm
Ground Clearance	~8 mm
Runtime	~40–50 min
9. Design & Engineering
9.1 Mobility Management
* Ackermann geometry → reduced slip, consistent turns
* Drive motor duty cycle → smooth acceleration/braking
* Calibrated servo endpoints → symmetric steering
9.2 Motor Calculations
* Torque = Force × Radius
* Speed = RPM × Wheel Circumference (~1.0–1.1 m/s)
* Power = Torque × Angular Velocity
9.3 Chassis
* Rigid base plate, low mass, balanced CoG
* Bearings and reinforced joints for repeatability

10. Power Management
* Single-cell Li-ion with protection
* Regulated rails for logic & motors
* Off-track charging (safety enforced)
* Efficiency via adaptive sensor polling

11. Obstacle Management Strategy
* Straight path: adjust steering via side distances
* Corners: orange = clockwise, blue = counter-clockwise
* Boxes: red = right turn, green = left turn
* Parking: align slowly and stop at bay after laps

12. Firmware Flow
1. Power on & arm
2. Acquire sensor/vision inputs
3. Compute outputs (steering + throttle)
4. Task sequence → straight, corner, box, parking
5. Repeat until stop

13. Testing & Validation
* Calibration: steering zero-point, ultrasonic thresholds
* Trial Runs: performed on mock track with obstacles
* Performance Metrics: lap consistency, obstacle avoidance accuracy, parking success rate

14. Safety & Reliability
* Over-current protection on motors
* Voltage regulation for ESP32 & sensors
* Fail-safe mode: vehicle halts if signal/data loss occurs
* No hot-charging permitted during operation

15. Tools & Assembly
Tools
* Screwdrivers (M3/M4), pliers, nut drivers
Steps
1. Mount controller & power module
2. Install sensor brackets & phone holder
3. Fit motors, wheels, steering linkage
4. Wire as per schematics
5. Verify polarity & calibrations

16. Future Scope
* Upgrade to camera-based lane detection (OpenCV/ML).
* Integrate LiDAR / depth sensors for better mapping.
* Add wireless telemetry for real-time monitoring.
* Optimize chassis weight with carbon fiber or composites.

*Problem Statement & Challenge Context
* Briefly describe WRO Future Engineers challenge, requirements (autonomous navigation, obstacle avoidance, parking), and constraints (track layout, dimensions, rules).

*Methodology / Design Approach
* Explain your design cycle: requirement analysis → CAD modeling → hardware selection → firmware coding → testing → optimization.

*System Block Diagram
* Show information flow: Sensors → ESP32 → Control Logic → Actuators (motor/servo).

*Electrical System Details
* Pin mapping of ESP32 (which GPIO controls what).
* Voltage/current requirements of each module.
* Protections used (fuses, regulators).

*Software Flowchart / Pseudocode
* Simple flow diagrams showing decision-making (lane following, corner detection, obstacle avoidance).

*Testing & Performance Results
* Number of trial runs, average lap time, success rate for obstacle handling, parking accuracy.
* Calibration process explained in detail.

*Risk Analysis & Mitigation
* Common issues (sensor noise, wheel slip, power drain) and your countermeasures.

*Future Enhancements (more technical)
* Machine learning-based vision detection.
* PID control for speed and steering.
* Integration of ROS (Robot Operating System) for scalability.


17. Conclusion
The ROBODYNAMOS project successfully integrates robust sensing, clean control logic, and reliable mechanical design to complete the WRO Future Engineers course. The design emphasizes stability, serviceability, and efficiency, while leaving room for future enhancements.

18. References
* Repository folders (schemes/, models/, src/) for complete documentation
* Sensor and motor datasheets (see other/)
* WRO Future Engineers challenge rules (2025 edition)
