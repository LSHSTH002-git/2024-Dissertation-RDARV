/*
Author: Sthabiso Lushaba
Student Number: LSHSTH002

This code controls a robot's movement using an HC-05 Bluetooth module and four DC motors. 
It defines functions to move the robot forward, backward, left, right, rotate, pause, and start.
*/

#include <AFMotor.h> // Include the AFMotor library

// Define motor objects for each motor
AF_DCMotor Front_left_wheel(3);
AF_DCMotor Front_right_wheel(2);
AF_DCMotor Back_left_wheel(4);
AF_DCMotor Back_right_wheel(1);

int motor_speed = 100; // Maximum speed
int command; // This holds the command read from the HC-05 Bluetooth module

void setup() {
  Serial.begin(9600);  // Set the baud rate for serial communication
  // Initialize any other necessary setup code here

  // Set the speed for each motor
  Front_left_wheel.setSpeed(motor_speed);
  Front_right_wheel.setSpeed(motor_speed);
  Back_left_wheel.setSpeed(motor_speed);
  Back_right_wheel.setSpeed(motor_speed);
}

void loop() {
  // Check if there is data available from the serial port
  while(Serial.available() > 0) {
    // Read the command from the serial port
    command = Serial.read(); // If there is data, store it in command;
    Serial.println(command); // Print this to the serial monitor just to double check

    // Determine the action based on the received command
    if(command == 'F') {
      move_forward();
    } else if(command == 'B') {
      move_backward();
    } else if(command == 'L') {
      move_left();
    } else if(command == 'R') {
      move_right();
    } else if(command == 'P') {
      pause();
    } else if(command == 'S') {
      start();
    } else if(command == 'r') {
      rotate();
    } else if(command == 'A') {
      accelerate();
    } else if(command == 'D') {
      decelerate();
    }
  }
}

// Function to move the robot forward
void move_forward() {
  // Set the speed for all motors
  Front_left_wheel.setSpeed(motor_speed);
  Front_right_wheel.setSpeed(motor_speed);
  Back_left_wheel.setSpeed(motor_speed);
  Back_right_wheel.setSpeed(motor_speed);

  // Run all motors forward
  Front_left_wheel.run(FORWARD);
  Front_right_wheel.run(FORWARD);
  Back_left_wheel.run(FORWARD);
  Back_right_wheel.run(FORWARD);
}

// Function to move the robot backward
void move_backward() {
  // Set the speed for all motors
  Front_left_wheel.setSpeed(motor_speed);
  Front_right_wheel.setSpeed(motor_speed);
  Back_left_wheel.setSpeed(motor_speed);
  Back_right_wheel.setSpeed(motor_speed);

  // Run all motors backward
  Front_left_wheel.run(BACKWARD);
  Front_right_wheel.run(BACKWARD);
  Back_left_wheel.run(BACKWARD);
  Back_right_wheel.run(BACKWARD);
}

// Function to move the robot right
void move_right() {
  // Set the speed for all motors
  Front_left_wheel.setSpeed(motor_speed);
  Front_right_wheel.setSpeed(motor_speed);
  Back_left_wheel.setSpeed(motor_speed);
  Back_right_wheel.setSpeed(motor_speed);

  // Run motors in a manner to turn the robot right
  Front_left_wheel.run(FORWARD);
  Front_right_wheel.run(BACKWARD);
  Back_left_wheel.run(BACKWARD);
  Back_right_wheel.run(FORWARD);
}

// Function to move the robot left
void move_left() {
  // Set the speed for all motors
  Front_left_wheel.setSpeed(motor_speed);
  Front_right_wheel.setSpeed(motor_speed);
  Back_left_wheel.setSpeed(motor_speed);
  Back_right_wheel.setSpeed(motor_speed);

  // Run motors in a manner to turn the robot left
  Front_left_wheel.run(BACKWARD);
  Front_right_wheel.run(FORWARD);
  Back_left_wheel.run(FORWARD);
  Back_right_wheel.run(BACKWARD);
}

// Function to pause all motors
void pause() {
  // Release all motors to stop movement
  Front_left_wheel.run(RELEASE);
  Front_right_wheel.run(RELEASE);
  Back_left_wheel.run(RELEASE);
  Back_right_wheel.run(RELEASE);
}

// Function to start all motors (same as pause)
void start() {
  pause(); // Same as pause
}

// Function to rotate the robot
void rotate() {
  // Set the speed for all motors
  Front_left_wheel.setSpeed(motor_speed);
  Front_right_wheel.setSpeed(motor_speed);
  Back_left_wheel.setSpeed(motor_speed);
  Back_right_wheel.setSpeed(motor_speed);

  // Run motors to rotate the robot
  Front_left_wheel.run(BACKWARD);
  Back_left_wheel.run(BACKWARD);
  Front_right_wheel.run(FORWARD);
  Back_right_wheel.run(FORWARD);
}

// Function to accelerate the motor speed
void accelerate() {
  motor_speed += 10; // Increment motor speed by 10
  // If motor speed exceeds 250, set it to 0
  if (motor_speed > 250) {
    motor_speed = 0;
  }
}

// Function to decrease the motor speed
void decelerate() {
  motor_speed -= 10; // Decrement motor speed by 10
  // If motor speed goes below 0, set it to 0
  if (motor_speed < 0) {
    motor_speed = 0;
  }
}
