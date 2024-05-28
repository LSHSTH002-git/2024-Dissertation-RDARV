![image](https://github.com/LSHSTH002-git/Robot-Digital-Augmented-Reality-View-/assets/88942864/afd67bc6-f217-450d-a6b4-9a8806f47dcb)#Robot Digital Augmented Reality View

This project involves the development of a remotely controlled 4-wheeled robot equipped with a camera for video feed capture and real-time processing, employing computer vision tasks like object detection and tracking to bring about digital augmentations of the robot camera view. The augmentations enhancing the robot's ability to perceive and interact with its environment more effectively, improving navigation, safety, and decision-making. By overlaying digital information onto the physical world, the system provides operators with valuable insights in real-time, enabling more precise control and better situational awareness in complex environments.

## Overview

### Essential Hardware Components
- 4-wheeled robot chassis
- Raspberry Pi
- Raspberry Pi Camera Module
- Arduino R3
- HC-05 Bluetooth module
- L293D motor driver
- DC motors
- 18650 battery holders
- DC-DC step down converter

### Software Components
- Raspberry Pi for live video feed
- YOLOv8 for object detection and tracking

## System Design

### Robot Design and Architecture
- **Bluetooth Controller**: Communicates with the HC-05 module for wireless control.
- **HC-05 Module**: Interfaces with the Arduino R3.
- **Arduino R3**: Controls the L293D motor driver.
- **L293D Motor Driver**: Drives the DC motors.

### Computer Vision
- **Raspberry Pi**: Captures live video feed.
- **YOLOv8**: Processes the video feed for object detection and tracking.

- Navigate in the folders for source code

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

## Contributing

Contributions are welcome! Please fork this repository and submit pull requests.

## Contant Info:
Name: S'thabiso Lushaba
Email: sthabisoslushaba@gmail.com
