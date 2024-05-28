# AR-Robot Remote Navigation System

This project involves the development of a remotely controlled 4-wheeled robot equipped with a camera for video feed capture and real-time processing using augmented reality and computer vision techniques like object detection and tracking.

## Overview

### Hardware Components
- 4-wheeled robot chassis
- Raspberry Pi
- Camera module
- Arduino R3
- HC-05 Bluetooth module
- L293D motor driver
- DC motors
- Battery pack

### Software Components
- Raspberry Pi for live video feed
- YOLOv8 for object detection and tracking
- User interface to toggle augmentations

## System Design

### Robot Design and Architecture
- **Bluetooth Controller**: Communicates with the HC-05 module for wireless control.
- **HC-05 Module**: Interfaces with the Arduino R3.
- **Arduino R3**: Controls the L293D motor driver.
- **L293D Motor Driver**: Drives the DC motors.

### Computer Vision
- **Raspberry Pi**: Captures live video feed.
- **YOLOv8**: Processes the video feed for object detection and tracking.
- **User Interface**: Allows toggling of augmentations on/off as needed.

## Diagram
![System Design Overview](path/to/diagram.png)
*Figure: Software design overview*

## Usage

1. **Hardware Setup**:
   - Assemble the robot chassis.
   - Connect the camera module to the Raspberry Pi.
   - Interface the HC-05 Bluetooth module with the Arduino R3.
   - Connect the L293D motor driver to the Arduino and the DC motors.
   - Power the system using the battery pack.

2. **Software Setup**:
   - Clone this repository.
     ```sh
     git clone https://github.com/yourusername/AR-Robot-Remote-Navigation.git
     cd AR-Robot-Remote-Navigation
     ```
   - Install the required dependencies.
     ```sh
     pip install -r requirements.txt
     ```
   - Run the main control script.
     ```sh
     python main.py
     ```

3. **Operation**:
   - Use the Bluetooth controller to navigate the robot.
   - View the live video feed on the Raspberry Pi interface.
   - Toggle object detection and tracking augmentations using the user interface.

## Contributing

Contributions are welcome! Please fork this repository and submit pull requests.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
