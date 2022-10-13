//
// Created by Danilo Ardagna on 14/10/2020.
//

#ifndef RETURNREF_BASEOK_H
#define RETURNREF_BASEOK_H


class BaseOK{
    int x;
public:
    BaseOK() {
        x = -1;
    };

    BaseOK(int val): x(val) {};

    BaseOK& operator=(const BaseOK& rhs); // return BaseOK&

    int get_x() const;

    void set_x(int val);
};


#endif //RETURNREF_BASEOK_H
