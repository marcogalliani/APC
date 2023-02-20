//
// Created by Marco Galliani on 30/12/22.
//

#ifndef EMPLOYEE_SECRETARY_HH
#define EMPLOYEE_SECRETARY_HH

#include "Employee.hh"

class Secretary : public Employee{
public:
    //constructor
    Secretary(const std::string &name, const std::string &surname, unsigned int employeeId): Employee(name,surname,employeeId){}
    //overriding method to compute the salary
    double salary_cal(void) override;


};


#endif //EMPLOYEE_SECRETARY_HH
