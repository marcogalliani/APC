//
// Created by Marco Galliani on 30/12/22.
//

#ifndef EMPLOYEE_EMPLOYEE_HH
#define EMPLOYEE_EMPLOYEE_HH

#include <iostream>
#include <string>

class Employee{
protected:
    std::string name, surname;
    unsigned employee_ID;
    double pay_rate = 7.5;
    unsigned work_hours;
public:
    //constructor
    Employee(const std::string &name, const std::string &surname, unsigned int employeeId) : name(name),
                                                                                             surname(surname),
                                                                                             employee_ID(employeeId) {}
    //setters
    void set_work_hours(unsigned int workHours) {
        work_hours = workHours;
    }
    //virtual method to compute salary
    virtual double salary_cal(void) =0;
    //print
    void print(){
        std::cout << "---------------------" << std::endl;

        std::cout << "Name: " << name << std::endl;
        std::cout << "Surname: " << surname << std::endl;

        std::cout << "---------------------" << std::endl;
    }
};


#endif //EMPLOYEE_EMPLOYEE_HH
