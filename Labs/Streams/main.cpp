#include <iostream>
#include <unordered_map>

#include "FileManager.h"

using std::unordered_map;
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cerr;

typedef vector<string> row_type;
typedef vector<row_type> table_type;
typedef unordered_map<unsigned,StudentsData> students_type;

void add_students (const table_type&, students_type&);
void add_exams (const table_type&, students_type&);

int main () {

    string filename_students = "../students.txt";
    string filename_exams = "../exams.txt";

    students_type students;

    FileManager FM_exams,FM_students;

    // parse students file
    table_type fields_students = FM_students.parse_file(filename_students);

    // add students to the map
    add_students(fields_students, students);

    // parse exams file
    table_type fields_exams = FM_exams.parse_file(filename_exams);

    /*
    //to see what fields contain
    std::cout << "Reading file exams" << endl;
    for(auto f:fields){
        std::cout << "New exam: " << endl;
        std::cout << f[0] << endl;
        std::cout << f[1] << endl;
        std::cout << f[2] << endl;
        std::cout << f[3] << endl;
    }
    */

    // add exams to the corresponding students, if they exist in the map
    add_exams(fields_exams, students);

    // compute and print average of students' grades
    
    /* Your code goes here */
    size_t key;
    for (const auto & s:students) {

        cout << "------student------ "<< endl;
        cout << "Student ID: " << s.first << endl;

        for (const auto & f:fields_students) {
            std::istringstream reader(f[0]);
            reader >> key;
            if(key== s.first)
                s.second.print_name();
        }


        cout << "Average grade: : " << s.second.average_grade() << endl;

    }

    //debugging
    /*
    for (const auto & s:students) {
        cout << s.first << endl;
        s.second.print();
    }
    */


}

void add_students (const table_type& fields, students_type& students) {
    /* Your code goes here */
    unsigned int key;

    for (auto & f:fields) {
        //to convert strings into typed objects we rely on streams
        //first we create a stream from the string
        //then we use the >> operator to store the stream element in the variable of the desired type
        std::istringstream reader(f[0]);
        reader >> key;

        students.insert({key,StudentsData(f[1],f[2],f[3])});
    }



}

void add_exams (const table_type& fields, students_type& students) {

    /* Your code goes here */
    unsigned int key;
    size_t cID;
    unsigned g;

    for (const auto &f:fields) {
        //same conversion as before
        std::istringstream reader(f[0]);
        reader >> key;

        auto found = students.find(key);
        if(found != students.end()) {
            //similar conversions
            std::istringstream course_ID(f[1]);
            std::istringstream grade(f[3]);

            course_ID >> cID;
            grade >> g;

            found->second.add_exam(Exam(cID, f[2], g));
        }
    }
}