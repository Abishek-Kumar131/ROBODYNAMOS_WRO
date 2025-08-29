ROBODYNAMOS – Future Engineers Repository
====

An autonomous vehicle project by team ROBODYNAMOS for the WRO Future Engineers challenge. This repo aggregates our media, build artifacts, wiring references, and control software in one place so the robot can be rebuilt and evaluated end‑to‑end.

Repository map
----

- `t-photos/` team images (formal + candid)
- `v-photos/` six clear views of the vehicle
- `video/` demo link and notes
- `schemes/` electrical layout, connectors, and system blocks
- `src/` firmware and control logic
- `models/` 3D printable parts and mechanical drawings
- `other/` any supporting docs (datasheets, pin maps, setup guides)

Team roster
----

| Role        | Name                | Department     | Register No.   |
| ----------- | ------------------- | -------------- | -------------- |
| Mentor      | Dr. M. Gomathy      | ASP - III/CSBS | —              |
| Member      | V. Abhisek Kumar    | CSBS           | 953624244003   |
| Member      | D. Mirjone             | MECH           | 953624114018   |
| Member      | S. Madesh Sai Pratap | ECE            | 953624106057   |

- Team name: ROBODYNAMOS
- Team ID: 1142 &

Project overview
----

Our platform is a camera‑assisted, sensor‑aided car with front‑wheel steering and speed control tuned for the WRO track. The system fuses distance sensing with vision cues to follow lanes, negotiate corners, avoid obstacles, and finish with a parking maneuver.

Hardware snapshot
----

- ESP32 microcontroller with PWM/GPIO for steering and drive
- DC motor for traction and a high‑torque servo for steering
- Ultrasonic range modules for front, side, and rear awareness
- Simple, rigid chassis with 3D‑printed mounts for sensors and links
- Regulated power from a single Li‑ion source with onboard charging

Software workflow
----

1. Read sensors and vision hints
2. Decide desired heading and speed
3. Apply steering (Ackermann‑style) and throttle outputs
4. Handle turns, boxes/signals, and final parking routine

Build and upload
----

- Edit and compile code in the Arduino IDE (C/C++)
- Connect controller over USB and upload firmware
- Calibrate straight‑ahead steering and distance thresholds before runs

Notes for reviewers
----

- Media folders document the exact build we are submitting.
- Schematics show every electrical connection used on the vehicle.
- Source is modular: movement control, sensing, task logic, and utilities are separated for clarity.

Acknowledgements
----

Guided by our mentor, Dr. M. Gomathy (ASP - III/CSBS), with contributions from CSBS, MECH, and ECE team members.

---

## 🔧 Hardware Overview

### Central Controller – ROBODYNAMOS Core

- ESP32 (32‑bit) MCU with timers and PWM for steering/drive control
- Onboard motor driver for DC propulsion and servo signal output
- Start/arm control and status indication for reproducible runs
- Ports for ultrasonic range sensors and color/vision input

### Motors and Actuation

#### Propulsion
- DC gear motor sized for track speed while maintaining controllable torque

#### Steering
- High‑torque servo provides Ackermann‑style steering within ±20° travel

### Sensors

#### Ultrasonic Set
- Three front sensors for obstacle ranging, left/right for centering, one rear for backing safety

#### Color/Vision
- Color sensor or phone‑based vision provides lane/box cues to firmware

### Structure

#### Chassis
- Rigid, lightweight plate with centralized mass for balance

#### 3D‑Printed Parts
- Custom brackets for sensors, motor mounts, and steering linkages

---

## 💻 Software Stack

### Development Environment
- Arduino IDE (C/C++) used to build and flash the control firmware

### Code Architecture
- Modular separation:
  - Mobility: steering and throttle control
  - Perception: ultrasonic processing and color/vision decoding
  - Strategy: straight, corner, box, and parking routines
  - Utilities: timing, calibration, configuration

---

## 📏 Dimensions and Specifications

| Parameter                  | Value           |
| -------------------------- | --------------- |
| Length                     | ≈ 280 mm        |
| Width                      | ≈ 190 mm        |
| Height                     | ≈ 250 mm        |
| Weight (no phone)          | ≈ 0.98 kg       |
| Wheel Diameter             | ≈ 67 mm         |
| Ground Clearance           | ≈ 8 mm          |
| Typical Runtime            | ≈ 40–50 minutes |

---

## 🚗 Mobility Management

- Ackermann geometry minimizes slip and improves turn consistency
- Duty‑cycle control on the drive motor for smooth acceleration/braking
- Servo endpoints calibrated to maintain symmetric left/right response
- Side distance feedback used for lane centering in narrow passages

---

## ⚙️ Motor Selection & Engineering Calculations

### Relations
- Torque = Force × Radius
- Speed = RPM × Wheel Circumference
- Power = Torque × Angular Velocity

### Representative Values
- Wheel radius ≈ 33.5 mm → circumference ≈ 210 mm
- 300 RPM → ≈ 1.0–1.1 m/s theoretical no‑load speed
- Power budgeted to avoid thermal saturation under continuous runs

### Selection Rationale
- DC gear motor: compact, efficient, suitable for 3–12 V operation
- Steering servo: high stall torque to hold angle under vibration and load

---

## 🏗️ Chassis & Mechanical Design

- Stiff base plate prevents flex while keeping mass low
- Centralized phone/controller placement maintains stable center of gravity
- Bearings and reinforced joints reduce play and improve repeatability
- Printed components include sensor pods, motor mounts, steering links, spacers

---

## 🔬 Engineering Principles

- Newton’s Second Law guides torque/acceleration budgeting for total mass
- Electrical rails are regulated to protect logic and actuation devices
- Low ground clearance favors stability while clearing track surface
- Ackermann linkage maintains correct wheel angles around an instantaneous center

---

## 🔋 Power Management

- Single‑cell Li‑ion source with protection and monitored discharge
- Dedicated regulation for logic and motors to limit noise coupling
- Charging via module off‑track; no hot charging during runs
- Runtime extended by adaptive sensor polling and motor duty optimization

---

## 🚧 Obstacle Management Strategy

### Straight Path
- Left distance < threshold → steer slightly right
- Right distance < threshold → steer slightly left
- Both clear → maintain heading

### Corner Handling and Color Cues
- Orange cue → execute clockwise turn
- Blue cue → execute counterclockwise turn

### Box/Sign Logic
- Red box → plan right turn
- Green box → plan left turn
- Vision/color module provides the cue to firmware

### Parking
- After configured laps, enable parking mode on wall detection
- Perform slow alignment and final stop inside the bay

---

## 🔄 Firmware Flow

1. Power on and arm
2. Acquire sensors/vision
3. Compute steering/throttle setpoints
4. Run task sequence (straight → corner → box → parking)
5. Loop at fixed control interval until stop

---

## 🛠️ Tools & Assembly

### Tools
- Screwdrivers (M3/M4), pliers, nut drivers

### Steps
1. Mount controller and power module
2. Install sensor brackets and phone holder
3. Fit motors, wheels, and steering linkage
4. Wire per `schemes/` documentation
5. Verify polarity and calibrations before first run

### Printed Parts
- Ultrasonic holders (front/side/rear), motor mount, start button carrier, bush + links

---

## 🎯 Conclusion

ROBODYNAMOS integrates reliable sensing, robust steering, and clean task logic to complete the Future Engineers course with consistency, emphasizing stability, efficiency, and serviceability.

---

## 📚 Additional Resources

See each repository folder for deeper documentation (schematics, models, and source) that together describe the full electrical, mechanical, and software stack for ROBODYNAMOS.
