/*
 * Drivetrain.cpp
 *
 *  Created on: Aug 14, 2017
 *      Author: Andy
 */

#include <Drivetrain.h>
#include "WPILib.h"
#include <iostream>


Drivetrain::Drivetrain() {

	list = new struct motorList;

	list->Gyro = new ADXRS450_Gyro();

	list->motor1 = new VictorSP(0);
	list->motor2 = new VictorSP(1);
	list->motor3 = new VictorSP(2);
	list->motor4 = new VictorSP(3);

}

void Drivetrain::Drive(float fwd, float trn, float strfe){

	float max;
	float temp;
	float front_left;
	float front_right;
	float rear_left;
	float rear_right;

	list->gyroAngle = list->Gyro->GetAngle()-list->gyroZero;

	SmartDashboard::PutNumber("Gyro Angle", list->gyroAngle);
	SmartDashboard::PutNumber("Gyrozero", list->gyroZero);

	if(trn != 0){
		list->gyroZero = list->Gyro->GetAngle();
	}

	list->fwd = -fwd;
	list->trn = (trn + list->gyroAngle*-0.05)/2;
	list->strfe = strfe;

	front_left = list->fwd + list->trn + list->strfe;
	front_right = list->fwd - list->trn - list->strfe;
	rear_left = list->fwd + list->trn - list->strfe;
	rear_right = list->fwd - list->trn + list->strfe;

	max = fabs(front_left);

	temp = fabs(front_right);

	if (temp>max) max = temp;

	temp = fabs(rear_left);

	if (temp>max) max = temp;

	temp = fabs(rear_right);

	if (temp>max) max = temp;

	if (max>1)
	  {front_left/=max; front_right/=max; rear_left/=max; rear_right/=max;}

	list->motor1->Set(rear_right);
	list->motor2->Set(front_right);
	list->motor3->Set(-rear_left);
	list->motor4->Set(-front_left);

}

void Drivetrain::Rotate(double angle, bool rev){

	if(!rev){
	list->gyroZero = list->Gyro->GetAngle()+angle;
	}else if(rev){
	list->gyroZero = list->Gyro->GetAngle()-angle;
	}

}

void Drivetrain::Update(){

	Drive(0, 0, 0);

}

void Drivetrain::Stop(){

	list->motor1->Set(0);
	list->motor2->Set(0);
	list->motor3->Set(0);
	list->motor4->Set(0);


}
