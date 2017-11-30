#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	Kp = Kp;
	Ki = Ki; 
	Kd = Kd; 
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
	double steering_angle = -Kp * p_error - Ki * i_error - Kd * d_error; 
	if(steering_angle <= -1.0){steering_angle = -1.0;}
	if(steering_angle >= 1.0){steering_angle = 1.0;}
	return steering_angle;
}

