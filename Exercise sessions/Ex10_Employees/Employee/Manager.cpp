//
// Created by Marco Galliani on 30/12/22.
//

#include "Manager.hh"

double Manager::salary_cal(void) {
    return ((work_hours - m_hours - wsh_hours) * pay_rate) + (m_hours * m_rate) + (wsh_hours * wsh_rate);
}

void Manager::set_wsh_hours(unsigned int wshHours) {
    wsh_hours = wshHours;
}

void Manager::set_m_hours(unsigned int mHours) {
    m_hours = mHours;
}
