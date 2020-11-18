/* Example sketch to control a 28BYJ-48 stepper motor with ULN2003 driver board, AccelStepper and Arduino UNO: number of steps/revolutions. More info: https://www.makerguides.com */
// Include the AccelStepper library:
#include <AccelStepper.h>
// Motor pin definitions:
#define motorPin1  8      // IN1 on the ULN2003 driver
#define motorPin2  9      // IN2 on the ULN2003 driver
#define motorPin3  10     // IN3 on the ULN2003 driver
#define motorPin4  11     // IN4 on the ULN2003 driver
#define motorPin5  4      // IN1 on the ULN2003 driver
#define motorPin6  5      // IN2 on the ULN2003 driver
#define motorPin7  6     // IN3 on the ULN2003 driver
#define motorPin8  7     // IN4 on the ULN2003 driver
// Define the AccelStepper interface type; 4 wire motor in half step mode:
#define MotorInterfaceType1 8
#define MotorInterfaceType2 4
// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper library with 28BYJ-48 stepper motor:
AccelStepper stepper1 = AccelStepper(MotorInterfaceType1, motorPin1, motorPin3, motorPin2, motorPin4);
AccelStepper stepper2 = AccelStepper(MotorInterfaceType2, motorPin5, motorPin6, motorPin7, motorPin8);
void setup() {
  // Set the maximum steps per second:
  stepper1.setMaxSpeed(1000);
  stepper2.setMaxSpeed(1000);
}
void loop() {

  delay(100);
  // Reset the position to 0:
stepper2.setCurrentPosition(0);
stepper1.setCurrentPosition(0);
  // Run the motor backwards at 1000 steps/second until the motor reaches -4096 steps (1 revolution):
  while (stepper1.currentPosition() != 4096) {
    stepper1.setSpeed(100);
    stepper1.runSpeed();
     stepper2.setSpeed(-5);
    stepper2.runSpeed();
  }
   
  delay(100);
  // Reset the position to 0:
 stepper2.setCurrentPosition(0);
  stepper1.setCurrentPosition(0);
  // Run the motor forward at 1000 steps/second until the motor reaches 8192 steps (2 revolutions):
  while (stepper1.currentPosition() != -4096) {
    stepper1.setSpeed(-100);
    stepper1.runSpeed();
     stepper2.setSpeed(5);
    stepper2.runSpeed();
  }
  delay(0);
}
