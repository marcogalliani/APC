//
// Created by Marco Galliani on 12/10/22.
//

#include "Complex.h"
#include <iostream>
#include <cmath>


double Complex::getMReal() const {
    return m_real;
}

void Complex::setMReal(double mReal) {
    m_real = mReal;
}

double Complex::getMImg() const {
    return m_img;
}

void Complex::setMImg(double mImg) {
    m_img = mImg;
}

Complex::Complex(double mReal, double mImg) : m_real(mReal), m_img(mImg) {}



void Complex::print() const {
     std::cout << "(" << m_real << ") + (" << m_img <<")i\n";
}

void Complex::print_polar() const {
    std::cout << getModulus() << "[" << "cos(" << getPhase() << ") + i*" << "sin(" << getPhase() << ")]\n";
}

double Complex::getModulus() const {
    return sqrt(pow(m_real,2)+pow(m_img,2));
}

double Complex::getPhase() const {
    double phase=std::numeric_limits<double>::quiet_NaN();

    double sign=m_img >=0 ? 1.0:-1.0;
    //equivalent to
    /*if (m_img>=0)
        sign=1.0;
    else
        sign=-1.0;
    */

    if (m_real>0.0)
        phase=atan(m_img/m_real);
    else if (m_real<0.0)
        phase=atan(m_img/m_real)+sign+M_PI;
    else {
        if (m_img > 0 || m_img < 0)
            phase = sign * M_PI / 2.0;
    }
    return phase;


}

void Complex::setModulus(double mod) {
    //IMPORTANT: Coherence between modulus,phase and real_part, img_part
    double phase = getPhase();

    m_real = mod * cos(phase);
    m_img  = mod * sin(phase);

}

void Complex::setPhase(double phase) {
    //IMPORTANT: Coherence between modulus,phase and real_part, img_part
    double mod = getModulus();

    m_real = mod * cos(phase);
    m_img  = mod * sin(phase);
}

Complex operator+(const Complex& lhs, const Complex& rhs){
    double real, img;

    real = lhs.getMReal()+rhs.getMReal();
    img = lhs.getMImg()+rhs.getMImg();

    return Complex(real,img);
}
Complex operator-(const Complex& lhs, const Complex& rhs){
    double real, img;

    real = lhs.getMReal()-rhs.getMReal();
    img = lhs.getMImg()-rhs.getMImg();

    return Complex(real,img);
}
Complex operator*(const Complex& lhs, const Complex& rhs){
    double mod_l=lhs.getModulus(),mod_r=rhs.getModulus();
    double phase_l=lhs.getPhase(),phase_r=rhs.getPhase();

    return Complex(mod_l*mod_r*cos(phase_l+phase_r),mod_l*mod_r*sin(phase_l+phase_r));


}
Complex operator/(const Complex& lhs, const Complex& rhs){
    double mod_l=lhs.getModulus(),mod_r=rhs.getModulus();
    double phase_l=lhs.getPhase(),phase_r=rhs.getPhase();

    return Complex(mod_l/mod_r*cos(phase_l-phase_r),mod_l/mod_r*sin(phase_l-phase_r));
}
