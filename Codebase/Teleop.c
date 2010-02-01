#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Motor,  mtr_S1_C1_1,     motorD,        tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     motorE,        tmotorNormal, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     ejectionMachine, tmotorNormal, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     conveyorBelt,  tmotorNormal, openLoop)
#pragma config(Servo,  srvo_S1_C3_1,    backGrabber,          tServoNormal)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                           Tele-Operation Mode Code Template
//
// This file contains a template for simplified creation of an tele-op program for an FTC
// competition.
//
// You need to customize two functions with code unique to your specific robot.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.


/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                    initializeRobot
//
// Prior to the start of tele-op mode, you may want to perform some initialization on your robot
// and the variables within your program.
//
// In most cases, you may not have to add any code to this function and it will remain "empty".
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

void initializeRobot()
{
  // Place code here to sinitialize servos to starting positions.
  // Sensors are automatically configured and setup by ROBOTC. They may need a brief time to stabilize.

  return;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                         Main Task
//
// The following is the main code for the tele-op robot operation. Customize as appropriate for
// your specific robot.
//
// Game controller / joystick information is sent periodically (about every 50 milliseconds) from
// the FMS (Field Management System) to the robot. Most tele-op programs will follow the following
// logic:
//   1. Loop forever repeating the following actions:
//   2. Get the latest game controller / joystick settings that have been received from the PC.
//   3. Perform appropriate actions based on the joystick + buttons settings. This is usually a
//      simple action:
//      *  Joystick values are usually directly translated into power levels for a motor or
//         position of a servo.
//      *  Buttons are usually used to start/stop a motor or cause a servo to move to a specific
//         position.
//   4. Repeat the loop.
//
// Your program needs to continuously loop because you need to continuously respond to changes in
// the game controller settings.
//
// At the end of the tele-op period, the FMS will autonmatically abort (stop) execution of the program.
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

task main()
{
  initializeRobot();

  //waitForStart();   // wait for start of tele-op phase

  while (true)
  {
	  ///////////////////////////////////////////////////////////
	  ///////////////////////////////////////////////////////////
	  ////                                                   ////
	  ////      Add your robot specific tele-op code here.   ////
	  ////                                                   ////
	  ///////////////////////////////////////////////////////////
	  ///////////////////////////////////////////////////////////

    // Insert code to have servos and motors respond to joystick and button values.

    // Look in the ROBOTC samples folder for programs that may be similar to what you want to perform.
    // You may be able to find "snippets" of code that are similar to the functions that you want to
    // perform.

    getJoystickSettings(joystick);


    //Direct Drive for Wheels
    motor[motorD] = joystick.joy1_y1;
    motor[motorE] = joystick.joy1_y2;


    if(joystick.joy1_Buttons == 2)
    {
      servo[backGrabber] = 0;
    }
    else if(joystick.joy1_Buttons == 8)
    {
      servo[backGrabber] = 160;
    }

    if(joystick.joy1_Buttons == 32) //R1 runs the shooter forwards
    {
      motor[ejectionMachine] = 85;
    }
    else if(joystick.joy1_Buttons == 128) //R2 runs the shooter backwards, but slower.
    {
      motor[ejectionMachine] = -50;
    }
    else
    {
      motor[ejectionMachine] = 0;
    }

    if(joystick.joy1_Buttons == 16) //L1 runs the conveyor out fast
    {
      motor[conveyorBelt] = 50;
    }
    else if(joystick.joy1_Buttons == 64) //L2 runs the conveyor in slowly
    {
      motor[conveyorBelt] = -35;
    }
    else
    {
      motor[conveyorBelt] = 0;
    }


    }
}
