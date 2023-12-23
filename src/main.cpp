#include "vex.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// LeftMotor            motor         4               
// RightMotor           motor         5               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;

// Include the controller header
#include "vex_controller.h"

// Function prototypes
double getControllerAxiss(int axis);
int mapJoystickToMotor(double joystickValue);
void setMotorSpeed(motor& motorObj, int speed);

// Define motor ports
int leftMotorPort = 4;
int rightMotorPort = 5;

// Define controller axes
int leftAxis = 3;
int rightAxis = 2;

// Initialize motor objects
motor leftMotor(leftMotorPort);
motor rightMotor(rightMotorPort);

// Initialize the Controller1 object
controller Controller1;

// Main control loop
int main() {
    // Infinite loop for continuous control
    while (true) {
        // Read joystick values
        double leftJoystickValue = getControllerAxis(leftAxis);
        double rightJoystickValue = getControllerAxis(rightAxis);

        // Map joystick values to motor speeds
        int leftMotorSpeed = mapJoystickToMotor(leftJoystickValue);
        int rightMotorSpeed = mapJoystickToMotor(rightJoystickValue);

        // Set motor speeds
        setMotorSpeed(leftMotor, leftMotorSpeed);
        setMotorSpeed(rightMotor, rightMotorSpeed);

        // Optional: Add a small delay to control loop to avoid rapid updates
        vex::task::sleep(20);
    }

    return 0;
}

// Function to get joystick axis value from the controller
double getControllerAxis(int axis) {
    // Replace this with your platform-specific code to read joystick values
    return Controller1.AxisValue(axis);
}

// Function to map joystick values to motor speeds
int mapJoystickToMotor(double joystickValue) {
    // Replace this with your own mapping function based on your preferences
    // and the range of values returned by your controller
    return static_cast<int>(joystickValue); // Convert double to int if needed
}

// Function to set motor speed
void setMotorSpeed(motor& motorObj, int speed) {
    // Replace this with your platform-specific code to set motor speed
    // Ensure that the motor speed is within the valid range for your motors
    motorObj.setVelocity(speed, percent);
    motorObj.spin(forward);
}
