# 🚦 Smart Traffic Light Controller with Pedestrian Crossing System

## 📝 Project Overview

An intelligent traffic light controller system built with Arduino that simulates real-world traffic management. The system features an automated traffic light sequence with an integrated pedestrian crossing request system, allowing pedestrians to safely request extended crossing time by pressing a button.

---

## ✨ Key Features

### 🚥 Automated Traffic Light System
- **Continuous Operation**: Automatic cycle through Green → Yellow → Red sequence
- **Precise Timing**: Accurate time control for each phase
- **State Machine Design**: Reliable and predictable state transitions
- **Visual Indicators**: Three LED lights (Red, Yellow, Green)

### 🚶 Pedestrian Crossing Request
- **Push Button Interface**: Simple one-button pedestrian request
- **Smart Extension**: Red light duration automatically extends when requested
- **Safe Operation**: Completes current phase before extending red light
- **Automatic Reset**: Returns to normal operation after pedestrian crossing

### ⏱️ Timing Specifications

#### Normal Traffic Sequence:
- **Green Light**: 8 seconds
- **Yellow Light**: 2 seconds  
- **Red Light**: 5 seconds
- **Total Cycle**: 15 seconds

#### With Pedestrian Request:
- **Green Light**: 8 seconds
- **Yellow Light**: 2 seconds
- **Red Light**: 9 seconds (5 + 4 extra seconds for pedestrian crossing)
- **Total Cycle**: 19 seconds

---

### Performance Metrics
- ✅ Timing Accuracy: ±10ms
- ✅ Button Response: Immediate detection
- ✅ State Transitions: Smooth and reliable
- ✅ Serial Output: Clear status messages

---

## 📸 Screenshots

### Circuit 
![Circuit ](https://github.com/Rawan-Sotohy/Embedded-Systems/blob/main/Traffic%20Light%20Controller/image/SCREEN.png)

---

*This project demonstrates practical application of embedded systems, state machines, and real-time control in traffic management scenarios. Perfect for learning Arduino programming and understanding intelligent traffic control systems.*
