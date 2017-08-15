/*
 * Auton.h
 *
 *  Created on: Aug 14, 2017
 *      Author: Andy
 */

#ifndef SRC_AUTON_H_
#define SRC_AUTON_H_
#include "WPILib.h"
#include "CANTalon.h"
#include "Timer.h"
#include "Drivetrain.h"


class Auton{
public:

	Auton(Drivetrain* drivetrain);
	void Turn(double angle, bool rev);
	void Fwd(double Time, bool rev);
	void Strafe(double time, bool rev);
	void Stop();

private:

	struct AutonList{
		Drivetrain *drivetrain;

		Timer time;

	};


	struct AutonList *list;


};



#endif /* SRC_AUTON_H_ */
