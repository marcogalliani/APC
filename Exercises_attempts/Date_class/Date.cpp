//
// Created by Marco Galliani on 18/10/22.
//

#include "Date.h"
#include <cmath>

Date::Date(int d, int m, int y):day(d),month(m),year(y){
    if ((year%4==0 && year%100!=0) ||( year%400==0))
        leap= true;
    else
        leap= false;
}


Date Date::next_sunday(const Date &d) {
    return Date(0, 0, 0);
}

Date Date::next_Weekday(const Date &d) {
    return Date(0, 0, 0);
}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

int Date::get_max() const {
    return 0;
}

int Date::dooms_month() const {
    int doom = 12;
    if (month == 1)
        doom = 24 + leap;
    if (month == 2)
        doom = 28 + leap;
    if (month == 3)
        doom = 7;
    if (month == 4)
        doom = 4;
    if (month == 5)
        doom = 9;
    if (month == 6)
        doom = 6;
    if (month == 7)
        doom = 11;
    if (month == 8)
        doom = 8;
    if (month == 9)
        doom = 5;
    if (month == 10)
        doom = 10;
    if (month == 11)
        doom = 7;
    return doom;
}

int Date::Doomsday() const {

    //step 1: compute anchor day
    int cbd,century;
    century = year/100+1;

    cbd = ((5*century+((century-1)/4))%7+4)%7; //0:sunday, 1:monday ...

    //step 2: compute the doomsday of the year
    int dooms,ldy;
    ldy=year%100; //last two digits of the year

    dooms = (ldy/12 + ldy%12 +(ldy%12)/4)%7+cbd;

    //step 3: find doomsday closest to given date
    int ddm=dooms_month(); //doomsday of the month

    int dd=day-ddm;
    int dooms_day = dd+dooms;
    int my_day = dooms_day%7;

    if (my_day<0)
        my_day+=7;

    return my_day;
}


void Date::add_days(int n) {

}

void Date::show_date() const {

}

bool Date::leap_year(int y) {
    return false;
}

std::string Date::day_name(int d) {
    return std::string();
}

