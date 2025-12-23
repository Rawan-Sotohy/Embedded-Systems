# 🌡️ Smart Temperature-Controlled Fan System

## 📝 Project Description

An intelligent embedded system that automatically monitors ambient temperature and controls fan speed accordingly with visual LED indicators. The system provides an automated cooling solution that responds to temperature changes in real-time, making it ideal for temperature-sensitive environments.

---

## ✨ Key Features

### 🎯 Automatic Temperature Monitoring
- **Real-time Sensing**: Continuous temperature monitoring using LM35 sensor
- **High Accuracy**: Precise temperature readings with ±0.5°C accuracy
- **Fast Response**: Quick reaction to temperature changes

### 🌡️ Three-Zone Temperature Management

- 🟢 Safe Zone (≤25°C)
- 🟡 Warm Zone (26-35°C)
- 🔴 Hot Zone (>35°C)

### ⚡ PWM Motor Control
- **Smooth Speed Control**: Proportional fan speed adjustment
- **Energy Efficient**: Only runs when needed
- **Linear Response**: Speed increases proportionally with temperature

### 💡 Visual Feedback System
- **Color-Coded LEDs**: Instant visual status indication
- **Clear States**: Easy to understand temperature zones
- **Always Visible**: At-a-glance system monitoring

---
## 📈 Performance Analysis

### System Specifications
- **Temperature Range**: 0-100°C (operational)
- **Accuracy**: ±0.5°C
- **Response Time**: <200ms
- **PWM Frequency**: 490Hz (Arduino default)
- **Power Consumption**: 
  - Idle: ~100mA
  - Active (fan max): ~500mA

### Temperature vs Fan Speed Graph
```
Fan Speed (%)
100% |                    ●━━━━━━━━
     |                   ╱
 75% |              ●━━━
     |            ╱
 50% |       ●━━━
     |      ╱
 25% |  ●━━
     | ╱
  0% |●━━━━━━━
     └─────────────────────────────→
       25  28  31  34  37  40  Temperature (°C)
```
---

## 📸 Screenshots

### Circuit 

![Circuit](https://raw.githubusercontent.com/Rawan-Sotohy/Embedded-Systems/main/Smart%20Temperature-Controlled%20Fan%20System/image/SCREEN.png)

---
---

*This embedded system demonstrates practical application of microcontroller programming, analog sensing, PWM control, and automated decision-making in a real-world temperature management scenario.*
