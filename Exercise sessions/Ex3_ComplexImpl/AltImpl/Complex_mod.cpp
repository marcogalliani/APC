//
// Created by Marco Galliani on 12/10/22.
//

#include "Complex_mod.h"
#include <iostream>
#include <cmath>


double Complex::getMReal() const {
    return m_mod*cos(m_phase);
}

void Complex::setMReal(double mReal) {
    //IMPORTANT: Coherence between modulus,phase and real_part, img_part
    double mImg=getMImg();
    m_mod = sqrt(pow(mReal,2)+pow(mImg,2));
    m_phase=std::numeric_limits<double>::quiet_NaN();

    double sign=mImg >=0 ? 1.0:-1.0;
    //equivalent to
    /*if (m_img>=0)
        sign=1.0;
    else
        sign=-1.0;
    */

    if (mReal>0.0)
        m_phase=atan(mImg/mReal);
    else if (mReal<0.0)
        m_phase=atan(mImg/mReal)+sign+M_PI;
    else {
        if (mImg > 0 || mImg < 0)
            m_phase = sign * M_PI / 2.0;
    }
}

double Complex::getMImg() const {
    return m_mod*sin(m_phase);
}

void Complex::setMImg(double mImg) {
    //IMPORTANT: Coherence between modulus,phase and real_part, img_part
}

Complex::Complex(double mReal, double mImg) {
    m_mod = sqrt(pow(mReal,2)+pow(mImg,2));

    m_phase =std::numeric_limits<double>::quiet_NaN();

    double sign=mImg >=0 ? 1.0:-1.0;
    //equivalent to
    /*if (m_img>=0)
        sign=1.0;
    else
        sign=-1.0;
    */
    if (mReal>0.0)
        m_phase=atan(mImg/mReal);
    else if (mReal<0.0)
        m_phase=atan(mImg/mReal)+sign+M_PI;
    else {
        if (mImg > 0 || mImg < 0)
            m_phase = sign * M_PI / 2.0;
    }
}


void Complex::print() const {
     std::cout << "(" << getMReal() << ") + (" << getMImg() <<")i\n";
}

void Complex::print_polar() const {
    std::cout << m_mod << "[" << "cos(" << m_phase << ") + i*" << "sin(" << m_phase << ")]\n";
}

double Complex::getModulus() const {
    return m_mod;
}

double Complex::getPhase() const {
    return m_phase;
}

void Complex::setModulus(double mod) {
    m_mod = mod;
}

void Complex::setPhase(double phase) {
    m_phase = phase;
}

Complex operator+(const Complex& lhs, const Complex& rhs){
    double real, img, mod;

    real = lhs.getMReal()+rhs.getMReal();
    img = lhs.getMImg()+rhs.getMImg();

    return Complex(real,img);
}

Complex operator-(const Complex& lhs, const Complex& rhs){
    double real, img, mod;

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
