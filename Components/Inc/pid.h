/*
 * pid.h
 *
 *  Created on: Jan 25, 2025
 *      Author: limok
 */

#ifndef INC_PID_H_
#define INC_PID_H_

typedef float float32_t;

typedef struct{
	float32_t Kp;
	float32_t Ki;
	float32_t Kd;
	float32_t Ts;
} PID_params;

typedef struct{
	PID_params params;
	float32_t previous_error, previous_integral;
} PID;



float32_t CalculatePID(PID* pid, float32_t setpoint, float32_t measured_value);
#endif /* INC_PID_H_ */
