# 2DoF Laser pointer robot

Simple controller for a 2-DoF laser pointer robot using an ESP32 and a gamepad.

## Contents
- `controller.py` - Python controller that reads a joystick and sends serial commands.
- `sketch_jun29b/sketch_jun29b.ino` - Arduino/ESP32 sketch for the robot.

## Requirements
- Python 3.8+
- `pygame`
- `pyserial`
- A connected gamepad and the ESP32 on a serial port (set in `controller.py`).

## Usage
1. Install dependencies:

```bash
pip install pygame pyserial
```

2. Edit `controller.py` and set your ESP32 port (e.g. `COM3`).
3. Run the controller:

```bash
python controller.py
```

## License
This repository contains example code. Use at your own risk.
