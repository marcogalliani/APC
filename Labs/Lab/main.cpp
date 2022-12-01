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

    FileManager FM;

    // parse students file
    table_type fields = FM.parse_file(filename_students);

    // add students to the map
    add_students(fields, students);

    // parse exams file
    fields = FM.parse_file(filename_exams);

    // add exams to the corresponding students, if they exist in the map
    add_exams(fields, students);

    // compute and print average of students' grades
    
    /* Your code goes here */
    auto s = students.cbegin();
    while (s != students.cend()){
        cout << "---student " << s->second.getName()<< " " << s->second.getLastName()<< "---" << endl;

        cout << "StudentID: "<<s->first << endl;

        cout << "Average grade: " << s->second.average_grade() << endl;

        s++;
    }



}

void add_students (const table_type& fields, students_type& students) {

    /* Your code goes here */
    unsigned key;

    for (auto & f:fields){
        key = std::stoi(f[0]);
        if(students.find(key)==students.end())
            students.insert({key,StudentsData(f[1],f[2],f[3])});
    }
}

void add_exams (const table_type& fields, students_type& students) {

    /* Your code goes here */
    unsigned key;

    for (auto & f:fields){
        key = std::stoi(f[0]);

        auto found = students.find(key);
        if (found != students.end())
            found->second.add_exam(Exam(std::stoi(f[1]),f[2], std::stoi(f[3])));
    }

}