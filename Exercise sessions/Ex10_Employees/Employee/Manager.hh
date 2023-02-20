//
// Created by Marco Galliani on 30/12/22.
//

#ifndef EMPLOYEE_MANAGER_HH
#define EMPLOYEE_MANAGER_HH

#include "Employee.hh"

class Manager : public Employee{

private:
    double wsh_rate=8.5,m_rate=9.5;
    unsigned wsh_hours, m_hours;
public:
    //constructor
    Manager(const std::string &name, const std::string &surname, unsigned int employeeId): Employee(name,surname,employeeId){}
    //setters
    void set_wsh_hours(unsigned int wshHours);
    void set_m_hours(unsigned int mHours);
    //overriding method to compute the salary
    double salary_cal(void) override;
};


#endif //EMPLOYEE_MANAGER_HH
