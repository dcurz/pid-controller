#include "PID.h"
#include <iostream>

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double kp, double ki, double kd) {
	Kp = kp;
	Ki = ki; 
	Kd = kd; 
	p_error = 0; 
	i_error = 0;
	d_error = 0; 
}

void PID::UpdateError(double cte) {
	d_error = cte-p_error; 
	p_error = cte;
	i_error += cte; 
}

double PID::TotalError() { 
	double steering_angle = (-Kp * p_error) - (Ki * i_error) - (Kd * d_error); 
	if(steering_angle <= -1.0){steering_angle = -1.0;}
	if(steering_angle >= 1.0){steering_angle = 1.0;}
	//std::cout<<"Calculator Called and calculated angle is: " << steering_angle << std::endl;
	//std::cout<<"Kp = "<<Kp<<"  Ki = "<<Ki<<"   Kd = "<<Kd<<std::endl;
	return steering_angle;
}

