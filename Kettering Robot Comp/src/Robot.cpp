//Robot.cpp is the main file for the robot code. This is where the code
//begins (It's like begin.vi).
//The #includes import additional functions into the program.
#include <iostream>
//iostream includes default c++ functions, like cout.
#include "WPILib.h"
//WPILib is the FIRST Robotics library.
#include "CANTalon.h"
//CANTalon.h includes functionality for the CANTalon motor controllers.
#include "Drivetrain.h"
//Drivetrain.h is a handwritten file that controls the drivetrain.
#include "EdgeDetection.h"

#include "Timer.h"
#include "Auton.h"
class Robot: public frc::SampleRobot {

	Drivetrain drivetrain;
	Joystick joy;
	Edge Rotate;
	Edge NegRotate;
	Edge Fwd;
	Auton auton;

public:
	Robot():
		drivetrain(), joy(0), Rotate(joy.GetPOV()==90), NegRotate(joy.GetPOV()==270), Fwd(joy.GetPOV()==0), auton(&drivetrain)
	{

	}

	void RobotInit() {

	}
	void Autonomous() {

		drivetrain.list->gyroZero = drivetrain.list->Gyro->GetAngle();

		//53 deg to gear
/* Left Gear Auton
		auton.Fwd(1.5, true, 0.5);
		auton.Turn(47, false);
		auton.Fwd(1.9, true, 0.5);
*/
/* Right Gear Auton
		auton.Fwd(1.2, true, 0.5);
		auton.Turn(48.5, true);
		auton.Fwd(2, true, 0.5);
*/
/* Center Gear
		auton.Fwd(2, true, 0.5);
*/
		/* 1/2 way around airship

		auton.Fwd(2.2, true, 1);
		frc::Wait(0.5);
		auton.Turn(75, true);
		frc::Wait(0.5);
		auton.Fwd(1.2, true, 1);

*/
/* one time around airship
		auton.Fwd(2.2, true, 1);
		frc::Wait(0.5);
		auton.Turn(75, true);
		frc::Wait(0.5);
		auton.Fwd(2.2, true, 1);
		frc::Wait(0.5);
		auton.Turn(80, true);
		frc::Wait(0.5);
		auton.Fwd(2.2, true, 1);
		frc::Wait(0.5);
		auton.Turn(75, true);
		frc::Wait(0.5);
		auton.Fwd(1.9, true, 1);
		frc::Wait(0.5);
		auton.Turn(75, true);
*/
		/* 2 times around airship


auton.Fwd(2.2, true, 1);
		frc::Wait(0.5);
		auton.Turn(75, true);
		frc::Wait(0.5);
		auton.Fwd(2.2, true, 1);
		frc::Wait(0.5);
		auton.Turn(80, true);
		frc::Wait(0.5);
		auton.Fwd(2.2, true, 1);
		frc::Wait(0.5);
		auton.Turn(75, true);
		frc::Wait(0.5);
		auton.Fwd(1.9, true, 1);
		frc::Wait(0.5);
		auton.Turn(75, true);


		auton.Fwd(2.2, true, 1);
				frc::Wait(0.5);
				auton.Turn(75, true);
				frc::Wait(0.5);
				auton.Fwd(2.2, true, 1);
				frc::Wait(0.5);
				auton.Turn(80, true);
				frc::Wait(0.5);
				auton.Fwd(2.2, true, 1);
				frc::Wait(0.5);
				auton.Turn(75, true);
				frc::Wait(0.5);
				auton.Fwd(1.9, true, 1);
				frc::Wait(0.5);
				auton.Turn(75, true);


*/






	}

	//Expands Deadzone On Joysticks
	float deadzone(float f) {
			if (fabs(f) < .15)
				return 0.0f;
			else {
				if (f > 0)
					return (f - .15) / (1 - .15);
				else
					return (f + .15) / (1 - .15);
			}
		}



	void OperatorControl() override {

		drivetrain.list->gyroZero = drivetrain.list->Gyro->GetAngle();

		while (IsOperatorControl() && IsEnabled()) {
			Rotate.update(joy.GetPOV()==90);
			NegRotate.update(joy.GetPOV()==270);
			Fwd.update(joy.GetPOV()==0);

			if(Rotate.isPressed()){
				drivetrain.Rotate(90, false);
			}

			if(NegRotate.isPressed()){
				drivetrain.Rotate(90, true);
			}

			drivetrain.Drive(deadzone(joy.GetRawAxis(1)), deadzone(joy.GetRawAxis(4)), deadzone(joy.GetRawAxis(0)));

			frc::Wait(0.005);
		}
	}

	/*
	 * Runs during test mode
	 */
	void Test() override {

	}
};

START_ROBOT_CLASS(Robot)
