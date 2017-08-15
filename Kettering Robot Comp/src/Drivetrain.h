/*
 * Drivetrain.h
 *
 *  Created on: Aug 14, 2017
 *      Author: Andy
 */

#include "WPILib.h"

#ifndef SRC_DRIVETRAIN_H_
#define SRC_DRIVETRAIN_H_

class Drivetrain {
public:
	Drivetrain();
	void Drive(float fwd, float trn, float strfe);
	void Rotate(double angle, bool rev);
	void Stop();
	void Update();




public:

struct motorList{
	VictorSP *motor1;
	VictorSP *motor2;
	VictorSP *motor3;
	VictorSP *motor4;

	ADXRS450_Gyro *Gyro;

	double gyroAngle = 0;
	double gyroZero = 0;

	float fwd;
	float trn;
	float strfe;
	};

struct motorList *list;

};

#endif /* SRC_DRIVETRAIN_H_ */
