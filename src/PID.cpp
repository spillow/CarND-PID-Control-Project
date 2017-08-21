#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;

    prev_cte = 0.;
    int_cte = 0.;
    iteration = 0;
    err2 = 0.;
}

void PID::UpdateError(double cte) {
    int_cte += cte;

    p_error = -Kp * cte;
    i_error = -Ki * int_cte;
    d_error = -Kd * (cte - prev_cte);

    prev_cte = cte;
}

double PID::TotalError() {
    return p_error + i_error + d_error;
}

