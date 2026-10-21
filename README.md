<div align="center">

<img src="https://capsule-render.vercel.app/api?type=waving&color=0:1B3A6B,100:00B4D8&height=200&section=header&text=Autonomous%20Mobile%20Robot&fontSize=42&fontColor=ffffff&desc=with%20ASRS%20%E2%80%A2%20Fork%20Lifter%20%E2%80%A2%20Cartesian%20Arm&descAlignY=72&descSize=18&animation=fadeIn" width="100%" alt="Autonomous Mobile Robot banner"/>

### 🏭 One robot. Three attachments. Built for the warehouse floor.

![Arduino](https://img.shields.io/badge/Arduino-00878F?style=for-the-badge&logo=arduino&logoColor=white)
![C++](https://img.shields.io/badge/Embedded%20C%2FC%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![ESP8266](https://img.shields.io/badge/ESP8266-E7352C?style=for-the-badge&logo=espressif&logoColor=white)
![Blynk](https://img.shields.io/badge/Blynk%20IoT-23C48E?style=for-the-badge)
![SolidWorks](https://img.shields.io/badge/SolidWorks-DA291C?style=for-the-badge&logo=dassaultsystemes&logoColor=white)
![ANSYS](https://img.shields.io/badge/ANSYS-FFB71B?style=for-the-badge&logoColor=black)

![Status](https://img.shields.io/badge/status-completed%20prototype-success?style=flat-square)
![Type](https://img.shields.io/badge/Bachelor's%20project-KLE%20Tech%202022--23-1B3A6B?style=flat-square)
![Team](https://img.shields.io/badge/team-4%20members%20%7C%20team%20lead-blueviolet?style=flat-square)

</div>

---

## 📌 At a glance

> A multipurpose **Autonomous Mobile Robot (AMR)** for industrial material handling. It drives between stations, senses obstacles, and swaps between three tools — a **fork lifter**, a **vertical carousel storage unit (ASRS)** and a **Cartesian robotic arm** — while operators monitor and override it over **IoT**.

| 🔧 Built | 👥 Team | 🧠 My role | 📏 Footprint |
|:---:|:---:|:---:|:---:|
| 2022 – 2023 | 4 engineers | Team lead · circuit design · hardware build · embedded code | ≈ 500 × 500 × 100 mm |

<!-- 📸 Replace with a real photo of the robot — the single biggest upgrade to this README
<div align="center">
  <img src="media/amr-front.jpg" width="70%" alt="The finished AMR"/>
</div>
-->

---

## 📑 Contents

- [The problem](#-the-problem)
- [What the robot does](#-what-the-robot-does)
- [System architecture](#-system-architecture)
- [Hardware](#-hardware)
- [The ASRS module](#-the-asrs-module-in-code)
- [Mechanical design](#-mechanical-design)
- [Testing](#-testing)
- [Repository map](#-repository-map)
- [What I learned](#-what-i-learned)
- [Roadmap](#-roadmap)

---

## 🎯 The problem

Small warehouses and workshops still move parts by hand: walk, lift, store, find, retrieve. That's slow, error-prone and hard on people.

**Goal:** one compact, modular platform that can *transport*, *lift*, *store* and *pick* — instead of three separate machines.

---

## ⚙️ What the robot does

<table>
<tr>
<td width="33%" align="center" valign="top">

### 🚜 Fork Lifter
Lifts and carries small pallets and crates between stations.

</td>
<td width="33%" align="center" valign="top">

### 🗄️ ASRS Carousel
A vertical carousel stores items in trays. Type a tray number on the keypad — it rotates that tray to you.

</td>
<td width="33%" align="center" valign="top">

### 🦾 Cartesian Arm
X-Y-Z gantry arm, driven by NEMA 23 steppers, for precise pick-and-place.

</td>
</tr>
</table>

**Plus:**
- 🧭 **Line following** for repeatable routes between stations
- 🛑 **Obstacle detection** with LIDAR, ultrasonic and IR sensors
- 📱 **IoT remote control** via the Blynk app: drive, switch tools, monitor live
- 🔋 **Battery powered**: 12 V Li-ion with regulated supply rails

---

## 🧩 System architecture

```mermaid
flowchart LR
    subgraph Sensing
        L[RPLIDAR] 
        U[Ultrasonic]
        I[IR sensors]
    end
    subgraph Control
        M[Arduino Mega<br/>main controller]
        E[ESP8266<br/>Wi-Fi bridge]
    end
    subgraph Actuation
        D[DC geared motors<br/>L298N drivers]
        S[NEMA 23 steppers<br/>TB6600 drivers]
        V[Servo<br/>ASRS carousel]
    end
    K[Keypad] --> M
    L --> M
    U --> M
    I --> M
    M --> D
    M --> S
    M --> V
    M <--> E
    E <--> B[(Blynk Cloud)]
    B <--> P[📱 Operator app]
    BAT[12 V Li-ion<br/>SMPS + buck] -.power.-> M
```

---

## 🔌 Hardware

| Subsystem | Components |
|---|---|
| 🧠 **Controllers** | Arduino Mega · ESP8266 (IoT) |
| 👁️ **Sensors** | RPLIDAR · ultrasonic · IR · keypad input |
| 🏎️ **Drive** | DC geared motors + L298N drivers · front caster wheels |
| 🦾 **Arm & lift** | 2 × NEMA 23 steppers + TB6600 drivers |
| 🗄️ **ASRS** | Servo-positioned carousel trays |
| 🔋 **Power** | 12 V Li-ion battery · SMPS · buck converters (5 V rail) · dual cooling fans |
| 🖥️ **Feedback** | LCD status display · Blynk dashboard |

---

## 💻 The ASRS module in code

The sketch in [`Asrs_code/Asrs_code.ino`](Asrs_code/Asrs_code.ino) runs the storage carousel:

```text
 Operator types tray number on keypad
            │
            ▼
   Arduino reads key  ──►  moveTray(n)
            │
            ▼
   Servo rotates carousel to tray n  ──►  item delivered to the front
```

**Libraries:** `Keypad.h` · `Servo.h`

<details>
<summary><b>▶ How to run it</b></summary>

1. Open `Asrs_code/Asrs_code.ino` in the **Arduino IDE**
2. Install the **Keypad** library (Library Manager); `Servo` ships with the IDE
3. Wire the keypad rows/columns and the servo signal pin as defined at the top of the sketch
4. Select your board, then **Upload**
5. Enter a tray number on the keypad and watch the carousel move

</details>

---

## 📐 Mechanical design

- 🖥️ Designed in **SolidWorks**, load paths checked in **ANSYS**
- 🪶 Lightweight **aluminium alloy** chassis
- 📦 ≈ **500 × 500 × 100 mm** base with bays for electronics, cooling and payload
- 🛞 Two rear drive wheels for traction, casters at the front for stability
- 🔩 **Modular**: mechanical and electrical layers separate for easy maintenance

📄 Full drawings and design report: [`Autonomous Mobile Robot system.pdf`](Autonomous%20Mobile%20Robot%20system.pdf)

---

## 🧪 Testing

| Test | What we checked | Result |
|---|---|:---:|
| Line following | Repeatable station-to-station routes | ✅ |
| Obstacle detection | Stops / steers around objects in path | ✅ |
| ASRS carousel | Correct tray reached for each keypad input | ✅ |
| Fork lifter & arm | Full lift and pick-and-place cycles | ✅ |
| Drive & power | Traction and battery performance on different floors | ✅ |
| IoT control | Remote drive, tool switching and telemetry via Blynk | ✅ |

<!-- 🎬 Add a demo video/GIF here:
[![Watch the demo](media/demo-thumbnail.jpg)](https://youtu.be/YOUR_VIDEO_ID)
-->

---

## 🗂️ Repository map

```
📦 Autonomous-Mobile-Robot-with-ASRS-Cartesian-Robot
 ┣ 📂 Asrs_code
 ┃ ┗ 📜 Asrs_code.ino                  ← ASRS carousel control (Keypad + Servo)
 ┣ 📜 ASRS CODE                        ← earlier version of the ASRS sketch
 ┣ 📕 Autonomous Mobile Robot system.pdf  ← project report + SolidWorks designs
 ┣ 🗜️ BlynkESP8266-master.zip          ← Blynk library used for IoT control
 ┗ 📘 README.md
```

---

## 🧠 What I learned

- 🔗 **Systems integration**: making mechanical, electrical and embedded parts work as *one* machine
- ⚡ **Motor control**: choosing drivers, sizing steppers and distributing power safely
- 📡 **Sensor integration** for obstacle detection in a real, noisy environment
- 👥 **Leading a team of 4** from concept through CAD, fabrication and testing

---

## 🚀 Roadmap

- [x] Mechanical design, fabrication and assembly
- [x] Drive, sensing and IoT control
- [x] ASRS carousel, fork lifter and Cartesian arm
- [ ] 📸 Add build photos and a demo video
- [ ] 🗺️ Rebuild the navigation stack on **ROS 2** (Nav2 + SLAM) in **Gazebo** simulation — *in progress, I'm currently learning ROS 2*

---

<div align="center">

### 👋 Built by **Ajay Arjun Mannolkar**
M.Sc. Mechatronics & Cyber-Physical Systems · THD Deggendorf

[![Portfolio](https://img.shields.io/badge/Portfolio-technolkar.github.io-1B3A6B?style=for-the-badge&logo=githubpages&logoColor=white)](https://technolkar.github.io)
[![LinkedIn](https://img.shields.io/badge/LinkedIn-ajaymannolkar-0A66C2?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/ajaymannolkar)
[![YouTube](https://img.shields.io/badge/YouTube-TECHNOL%20KAR-FF0000?style=for-the-badge&logo=youtube&logoColor=white)](https://www.youtube.com/@TechnolkarInnovations)

⭐ *If this project helped or inspired you, consider giving it a star!*

<img src="https://capsule-render.vercel.app/api?type=waving&color=0:00B4D8,100:1B3A6B&height=100&section=footer" width="100%"/>

</div>
