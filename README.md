# Science Olympiad Robot Tour Library
A work in progress library for all your RoTo-ing needs!

## Features
- PID Controller

## In Progress Features
- L298N Motor Driver Controller
- Pose Estimation
- Automatic Pathfinding

## Details

# [PID](https://en.wikipedia.org/wiki/Proportional%E2%80%93integral%E2%80%93derivative_controller) Controller
Uses mathmatical approximations of the derivative and integral in order to calculate the PID values.
Should generally be close enough for low-precision needs such as in high friction drive systems.
Requires a sensor (usually an encoder) to find the amount of error.

# L298N Motor Driver Controller
Adds [PWM](https://en.wikipedia.org/wiki/Pulse-width_modulation) control for the L298N. Also automatically reverses
the motor direction for negative input values. Will also add support for stepper motors.

# Pose Estimation
Uses encoder distances and gyro readings in order to determine the position of the robot.

# Automatic Pathfinding
TBD
