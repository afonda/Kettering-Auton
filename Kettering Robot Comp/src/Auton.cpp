/*
 * Auton.cpp
 *
 *  Created on: Aug 14, 2017
 *      Author: Andy
 */
#include "Auton.h"
#include "WPILib.h"
#include "CANTalon.h"
#include "Timer.h"

Auton::Auton(Drivetrain* drivetrain){

	list = new struct AutonList;

	list->drivetrain = drivetrain;

}

void Auton::Turn(double angle, bool rev){

	list->drivetrain->Rotate(angle, rev);

	list->time.Start();
	list->time.Reset();

	while(list->time.Get() < 1){
		list->drivetrain->Update();
	}

	list->time.Stop();
}

void Auton::Fwd(double time, bool rev, double speed){

	list->time.Start();
	list->time.Reset();

		if(rev)
			speed = speed*-1;

	while(list->time.Get() < time){
	list->drivetrain->Drive(speed, 0, 0);
	}

	list->drivetrain->Stop();

	list->time.Stop();
}

void Auton::Strafe(double time, bool rev, double speed){

	list->time.Start();
		list->time.Reset();

			if(rev)
				speed = speed*-1;

		while(list->time.Get() < time){
		list->drivetrain->Drive(0, 0, speed);
		}

		list->drivetrain->Stop();

		list->time.Stop();
}
