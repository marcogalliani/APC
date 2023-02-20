//
// Created by Marco Galliani on 30/12/22.
//

#include "Developer.hh"

double Developer::salary_cal(void) {
    return ((work_hours - wsh_hours) * pay_rate) + (wsh_hours * wsh_rate);
}

void Developer::set_wsh_hours(unsigned int wshHours) {
    wsh_hours = wshHours;
}