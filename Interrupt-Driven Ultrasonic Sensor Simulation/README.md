# ⚡ Interrupt-Driven Ultrasonic Sensor System

## 📝 Project Overview

An advanced embedded systems project that implements a **non-blocking ultrasonic distance sensor** using Arduino interrupts and timers. This project demonstrates the superior performance of interrupt-driven design over traditional blocking methods for real-time robotic applications.

### Problem Statement
Traditional ultrasonic sensors using `pulseIn()` cause the entire system to "freeze" while waiting for echo responses, making robots unresponsive during sensor readings. This project solves that problem using interrupt-driven architecture.

---

## ✨ Key Features

### ⚡ Interrupt-Driven Architecture
- **Non-Blocking Operation**: System remains responsive during sensor readings
- **Pin Change Interrupts**: Automatic edge detection without polling
- **Real-Time Response**: Immediate reaction to sensor signals

### ⏱️ Precision Timing System
- **Timer1 Configuration**: Microsecond-precision timing
- **Overflow Handling**: Support for extended measurements
- **Accurate Distance**: Precise calculations using hardware timers

### 🤖 State Machine Design
- **Robust Edge Detection**: Handles rising and falling edges separately
- **Error Prevention**: Guards against spurious signals
- **Reliable Operation**: State-based logic ensures consistency

### 📊 Performance Comparison
- **Blocking vs Non-Blocking**: Direct comparison of both approaches
- **Efficiency Metrics**: Measure response time improvements
- **Real-World Application**: Ideal for autonomous robots and navigation systems


---

## 🔧 Implementation Phases

### Phase 1: Basic Interrupt Setup

- **Configure Pin Change Interrupt:**

### Phase 2: State Machine for Edge Detection

- **Implement Robust Edge Detection:**

### Phase 3: Timer1 Configuration

- **Configure Hardware Timer for Precision:**
- **Timer Calculation:**

### Phase 4: Distance Calculation with Overflow Handling

- **Complete Measurement System**
- **Distance Formula Explained**

---
## 📸 Screenshots

### Circuit 
![Circuit ](https://github.com/Rawan-Sotohy/Embedded-Systems/blob/main/Interrupt-Driven%20Ultrasonic%20Sensor%20Simulation/image/screen.jpeg)

---

## 👥 Authors & Contributors

- [Jannah Ayman](https://github.com/jannah-ayman)
- [Rawan Sotohy](https://github.com/Rawan-Sotohy)
- [Nancy Saad](https://github.com/nancyabdelbaryy)

---


*This project demonstrates advanced embedded systems programming using hardware interrupts, timers, and state machines for real-time sensor applications. Essential learning for robotics, automation, and IoT development.*
