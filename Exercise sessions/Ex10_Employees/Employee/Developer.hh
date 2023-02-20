//
// Created by Marco Galliani on 30/12/22.
//

#ifndef EMPLOYEE_DEVELOPER_HH
#define EMPLOYEE_DEVELOPER_HH

#include "Employee.hh"

class Developer : public Employee{
private:
    double wsh_rate=8.0;
    unsigned wsh_hours;
public:
    //constructor
    Developer(const std::string &name, const std::string &surname, unsigned int employeeId): Employee(name,surname,employeeId){}
    //setters
    void set_wsh_hours(unsigned int wshHours);
    //overriding method to compute the salary
    double salary_cal(void) override;
};


#endif //EMPLOYEE_DEVELOPER_HH
