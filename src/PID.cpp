#include "PID.h"

using namespace std;

/**
 * TODO: Complete the PID class. You may add any additional desired functions.
 */

PID::PID(double Kp, double Ki, double Kd) : Kp(Kp), Ki(Ki), Kd(Kd) {}


PID::~PID() {}


void PID::UpdateError(double cte) {
    /**
     * TODO: Update PID errors based on cte.
     */
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;
}

double PID::TotalError() {
    /**
     * TODO: Calculate and return the total error
     */
    double steer = -Kp * p_error - Kd * d_error - Ki * i_error;
    if (steer < -1) {
        steer = -1;
    }
    if (steer > 1) {
        steer = 1;
    }
    return steer;  // TODO: Add your total error calc here!
}