# Autonomous-Mobile-Robot-with-ASRS-Cartesian-Robot
Designed and developed an autonomous mobile robot (AMR) for industrial material handling and warehouse automation. The robot integrates multiple attachments including a fork lifter, vertical carousel storage unit, and Cartesian robotic arm for multipurpose operations. Equipped with IR, ultrasonic, and LIDAR sensors and controlled using IoT.

📘 Overview
This project presents the design, fabrication, and development of a Multipurpose Autonomous Mobile Robot (AMR) that can navigate, map, and perform tasks autonomously using sensors and embedded systems.The robot integrates navigation, perception, mapping, and  manipulation capabilities to operate efficiently in dynamic environments such as industries, warehouses, and institutions. The system was built using NVIDIA Jetson, Raspberry Pi 4, and Arduino controllers, and utilizes LIDAR sensors, ultrasonic sensors, and IR modules for autonomous decision-making and obstacle avoidance.

🎯 Project Objectives
Navigation: Enable the robot to move autonomously between waypoints.
Perception: Detect and interpret surrounding obstacles and environment.
Mapping: Create and update a map of its environment using LIDAR data.
Decision Making: Plan paths, adjust speed, and avoid obstacles dynamically.
Task Execution: Perform transport or inspection tasks autonomously.
Safety & Reliability: Ensure stable, collision-free operation.
Scalability: Adapt the system for new environments and payloads.

🧩 System Design and Methodology
1️⃣ Sensing and Data Acquisition
The RPLIDAR sensor continuously scans the environment in 360° to detect objects and distances. Ultrasonic sensors are used for short-range obstacle detection and safety. The sensor data is processed in real-time on the NVIDIA Jetson Nano for perception and mapping.

2️⃣ Data Processing and Control
LIDAR and camera data are processed to generate a 2D map of the surroundings. The Jetson runs SLAM (Simultaneous Localization and Mapping) algorithms to localize the robot. Motion control and real-time decision-making are handled using the Robot Operating System (ROS) and Python scripts.

3️⃣ Path Planning and Motion
The robot computes an optimal path between locations using SLAM data. Motor control signals are generated to drive the DC and stepper motors through TB6600 and L298N drivers. The robot dynamically avoids obstacles by recalculating alternate routes.

4️⃣ Mechanical Fabrication
The mechanical body was designed in SolidWorks and analyzed in ANSYS for strength and load distribution. Fabrication used lightweight aluminum alloy (8 mm sheet) for the frame. Dimensions: 500 mm × 500 mm × 100 mm with space for electronics, cooling, and payload. Caster wheels are mounted in the front for directional stability, with two rear drive motors providing traction.

5️⃣ Electronics and Circuit Integration
Controllers: NVIDIA Jetson Nano, Raspberry Pi 4, and Arduino Mega. Sensors: LIDAR, Ultrasonic, IR, and Camera Module. Motors: 2 × NEMA 23 stepper motors and 4 × DC geared motors. Drivers: TB6600 Stepper Driver and L298N Motor Driver. Display: LCD for status output. Power: 12 V Li-ion battery with SMPS and buck converters for regulated supply. Cooling: Dual fans maintain temperature for embedded processors.

6️⃣ Software Stack
Languages: Python, Embedded C, C++
Platforms: Ubuntu + ROS 2, Arduino IDE, SolidWorks, ANSYS Libraries: ROS Navigation Stack, OpenCV, and LIDAR SDK for mapping. IoT Interface: Blynk Cloud for remote control and live monitoring

7️⃣ Testing and Validation
Performed line-following, obstacle avoidance, and mapping tests. Verified autonomous navigation between mapped points. Conducted stress analysis in ANSYS — max load capacity ≈ 7.5 × 10⁵ N. Validated drive efficiency, traction, and power under different surfaces. Final integration test showed reliable navigation and accurate sensor fusion.

⚙️ Key Features
Fully autonomous navigation with SLAM mapping. 360° environmental scanning via LIDAR. Obstacle detection and path replanning in real time. Wireless IoT dashboard for manual override and telemetry. Camera-based live monitoring using Raspberry Pi or ESP32-CAM. Modular architecture with separable mechanical and electrical layers. Optimized power management with SMPS and 12 V Li-ion battery.

🧠 Technical Summary
Chassis Material: Aluminum Alloy 1060 (Lightweight & Strong) Drive Motors: 2 × DC geared motors + 1 × caster wheel Processor: NVIDIA Jetson Nano & Raspberry Pi 4 Model B Controllers: Arduino Mega for peripheral actuation Sensors: LIDAR, Ultrasonic, IR, and Camera Power: 12 V Li-ion battery with 5 V converter Software: ROS + Python + C/C++ (control and automation) Mapping: LIDAR + SLAM-based 2D environment reconstruction Communication: IoT (Wi-Fi/Blynk) and wired debugging via USB

🧪 Learning Outcomes
Hands-on experience with ROS, SLAM, and real-time sensor fusion. Proficiency in SolidWorks, ANSYS, and embedded C/Python programming. Integration of hardware and software in an embedded robotic platform. Development of a portable, rechargeable, and intelligent robot capable of multi-tasking.
