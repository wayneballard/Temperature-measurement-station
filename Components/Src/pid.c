/*
 * pid.c
 *
 *  Created on: Jan 25, 2025
 *      Author: limok
 */

#include "pid.h"

float32_t CalculatePID(PID* pid, float32_t setpoint, float32_t value_measured){
	float32_t u = 0, P, I, D, error, integral, derivative;
	error = setpoint - value_measured;

	P = pid -> params.Kp*error;

	integral = pid -> previous_integral + (error + pid -> previous_error);
	pid -> previous_integral = integral;
	I = pid -> params.Ki*integral*(pid -> params.Ts/2.0);

	derivative = (error - pid -> previous_error);
  pid -> previous_error = error;
  D = pid -> params.Kd*derivative/(pid -> params.Ts);

  u = P + I + D;
  return u;
}

