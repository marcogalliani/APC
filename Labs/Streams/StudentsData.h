//
// Created by Danilo Ardagna on 18/11/2019.
//

#ifndef STUDENTSFILE_STUDENTSDATA_H
#define STUDENTSFILE_STUDENTSDATA_H

#include <iostream>
#include <vector>
#include <string>

#include "Exam.h"

class StudentsData {

    std::string name;
    std::string last_name;
    std::string birth_date;

    std::vector<Exam> exams;

public:
    StudentsData(const std::string& name, const std::string& lastName,
                 const std::string& birthDate);

    void add_exam(const Exam& e);

    float average_grade() const;


    void print_name() const {
        std::cout << name << ", " << last_name << " " <<  std::endl;
    }

    void print() const{
        std::cout << name << ", " << last_name << ", " << birth_date << std::endl;
        std::cout << "Exams: " << std::endl;
        for(Exam e:exams)
            e.print();
    }
};


#endif //STUDENTSFILE_STUDENTSDATA_H
