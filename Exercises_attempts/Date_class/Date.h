//
// Created by Marco Galliani on 18/10/22.
//

#ifndef DATE_CLASS_DATE_H
#define DATE_CLASS_DATE_H

#include <string>

class Date {
private:
    int day;
    int month;
    int year;

    bool leap;

    int get_max() const;
    int dooms_month() const;
    int Doomsday() const;

    std::string day_name(int d);


public:
    Date(int d, int m, int y);

    void add_days(int n);

    int getDay() const;
    int getMonth() const;
    int getYear() const;

    void show_date() const;

    bool leap_year(int y);

    Date next_sunday(const Date & d);
    Date next_Weekday(const Date & d);

};


#endif //DATE_CLASS_DATE_H
