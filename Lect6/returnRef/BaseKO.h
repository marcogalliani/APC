//
// Created by Danilo Ardagna on 14/10/2020.
//

#ifndef RETURNREF_BASEKO_H
#define RETURNREF_BASEKO_H


class BaseKO{
    int x;
public:
    BaseKO() {
        x = -1;
    };

    BaseKO(int val): x(val) {};

    BaseKO operator=(const BaseKO& rhs); // return *copy* BaseKO

    int get_x() const;

    void set_x(int val);
};


#endif //RETURNREF_BASEKO_H
