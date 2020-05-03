#include "solver.hpp"

#include <string>
#include <complex>

namespace solver {
    RealVariable::RealVariable(){
        a = 0;
        b = 1;
        c = 0;
        leftside = true;
    };
    RealVariable RealVariable::operator-(RealVariable sec){
        RealVariable newVariable;
        if (!this->leftside) {
            newVariable.a = this->a + sec.a;
            newVariable.b = this->b + sec.b;
            newVariable.c = this->c + sec.c;
            newVariable.leftside = this->leftside;
            return newVariable;
        }
        newVariable.a = this->a - sec.a;
        newVariable.b = this->b - sec.b;
        newVariable.c = this->c - sec.c;
        newVariable.leftside = this->leftside;
        return newVariable;
    };
    RealVariable RealVariable::operator-(double sec){
        RealVariable newVariable;
        if (!this->leftside) {
            newVariable.a = this->a;
            newVariable.b = this->b;
            newVariable.c = this->c + sec;
            newVariable.leftside = this->leftside;
            return newVariable;
        }
        newVariable.a = this->a;
        newVariable.b = this->b;
        newVariable.c = this->c - sec;
        newVariable.leftside = this->leftside;
        return newVariable;
    };
    RealVariable RealVariable::operator+(RealVariable sec){
        RealVariable newVariable;
        if (!this->leftside) {
            newVariable.a = this->a - sec.a;
            newVariable.b = this->b - sec.b;
            newVariable.c = this->c - sec.c;
            newVariable.leftside = this->leftside;
            return newVariable;
        }
        newVariable.a = this->a + sec.a;
        newVariable.b = this->b + sec.b;
        newVariable.c = this->c + sec.c;
        newVariable.leftside = this->leftside;
        return newVariable;
    };
    RealVariable RealVariable::operator+(double sec){
        RealVariable newVariable;
        if (!this->leftside) {
            newVariable.a = this->a;
            newVariable.b = this->b;
            newVariable.c = this->c - sec;
            newVariable.leftside = this->leftside;
            return newVariable;
        }
        newVariable.a = this->a;
        newVariable.b = this->b;
        newVariable.c = this->c + sec;
        newVariable.leftside = this->leftside;
        return newVariable;
    };

    RealVariable RealVariable::operator*(RealVariable sec){
        RealVariable newVariable;
        newVariable.a = this->a*sec.c + this->b*sec.b + this->c*sec.a;
        newVariable.b = this->b*sec.c + this->c*sec.b;
        newVariable.c = this->c*sec.c;
        newVariable.leftside = this->leftside;
        return newVariable;
    };
    RealVariable RealVariable::operator*(double sec){
        RealVariable newVariable;
        newVariable.a = this->a*sec;
        newVariable.b = this->b*sec;
        newVariable.c = this->c*sec;
        newVariable.leftside = this->leftside;
        return newVariable;
    };
//need to think
    // RealVariable RealVariable::operator/(RealVariable sec){
    //     this->a = this->a*sec.c + this->b*sec.b + this->c*sec.a;
    //     this->b = this->b*sec.c + this->c*sec.b;
    //     this->c = this->c*sec.c;
    //     return this;
    // };
    RealVariable RealVariable::operator/(double sec){
        RealVariable newVariable;
        if (sec == 0.0) {
          throw std::exception();
        }
        newVariable.a = this->a/sec;
        newVariable.b = this->b/sec;
        newVariable.c = this->c/sec;
        newVariable.leftside = this->leftside;
        return newVariable;
    };

    RealVariable RealVariable::operator^(int sec){
        RealVariable newVariable;
        newVariable.a = this->a;
        newVariable.b = this->b;
        newVariable.c = this->c;
        newVariable.leftside = this->leftside;
        if (sec>2 || sec<0) {
            throw std::exception();
        }
        if (sec == 0) {
            newVariable.a = 0;
            newVariable.b = 0;
            newVariable.c = 1;
            return newVariable;
        }
        if (sec == 1) {
            return newVariable;
        }
        if (newVariable.a != 0) {
            throw std::exception();
        }
        newVariable.a = this->b*this->b;
        newVariable.b = 2*this->b*this->c;
        newVariable.c = this->c*this->c;
        return newVariable;
    };
    RealVariable RealVariable::operator==(RealVariable sec){
        RealVariable newVariable;
        newVariable.a = this->a - sec.a;
        newVariable.b = this->b - sec.b;
        newVariable.c = this->c - sec.c;
        newVariable.leftside = false;
        return newVariable;
    };
    RealVariable RealVariable::operator==(double sec){
        RealVariable newVariable;
        newVariable.a = this->a;
        newVariable.b = this->b;
        newVariable.c = this->c - sec;
        newVariable.leftside = false;
        return newVariable;
    };
    RealVariable operator * (double sec ,const RealVariable & first){
        RealVariable newVariable;
        newVariable.a = first.a*sec;
        newVariable.b = first.b*sec;
        newVariable.c = first.c*sec;
        newVariable.leftside = first.leftside;
        return newVariable;
    };

    RealVariable operator + (double sec,const RealVariable & first){
        RealVariable newVariable;
        if (!first.leftside) {
            newVariable.a = -first.a;
            newVariable.b = -first.b;
            newVariable.c = -first.c - sec;
            newVariable.leftside = first.leftside;
            return newVariable;
        }
        newVariable.a = first.a;
        newVariable.b = first.b;
        newVariable.c = first.c + sec;
        newVariable.leftside = first.leftside;
        return newVariable;
    };
    RealVariable operator - (double sec,const RealVariable & first){
        RealVariable newVariable;
        if (!first.leftside) {
            newVariable.a = first.a;
            newVariable.b = first.b;
            newVariable.c = first.c - sec;
            newVariable.leftside = first.leftside;
            return newVariable;
        }
        newVariable.a = -first.a;
        newVariable.b = -first.b;
        newVariable.c = -first.c + sec;
        newVariable.leftside = first.leftside;
        return newVariable;
    };
    RealVariable operator==(double sec,const RealVariable & first){
        RealVariable newVariable;
        newVariable.a = -first.a;
        newVariable.b = -first.b;
        newVariable.c = sec - first.c;
        newVariable.leftside = false;
        return newVariable;
    };
    double solve(RealVariable equ){
        if (equ.a == 0 && equ.b == 0 && equ.c != 0){
            throw std::exception();
        }
        if (equ.a == 0){
            return -equ.c/equ.b;
        }
        if (equ.b*equ.b -4*equ.a*equ.c < 0) {
          throw std::exception();
        }
        // printf("%.7lf\n", equ.a);
        // printf("%.7lf\n", equ.b);
        // printf("%.7lf\n", equ.c);
        return -equ.b/(2*equ.a) + std::sqrt(equ.b*equ.b-4*equ.a*equ.c)/(2*equ.a);
    };





    ComplexVariable::ComplexVariable(){
        a = 0;
        b = 1;
        c = 0;
        leftside = true;
    };
    ComplexVariable ComplexVariable::operator-(ComplexVariable sec){
        ComplexVariable newVariable;
        if (!this->leftside) {
            newVariable.a = this->a + sec.a;
            newVariable.b = this->b + sec.b;
            newVariable.c = this->c + sec.c;
            newVariable.leftside = this->leftside;
            return newVariable;
        }
        newVariable.a = this->a - sec.a;
        newVariable.b = this->b - sec.b;
        newVariable.c = this->c - sec.c;
        newVariable.leftside = this->leftside;
        return newVariable;
    };
    ComplexVariable ComplexVariable::operator-(std::complex<double> sec){
        ComplexVariable newVariable;
        if (!this->leftside) {
            newVariable.a = this->a;
            newVariable.b = this->b;
            newVariable.c = this->c + sec;
            newVariable.leftside = this->leftside;
            return newVariable;
        }
        newVariable.a = this->a;
        newVariable.b = this->b;
        newVariable.c = this->c - sec;
        newVariable.leftside = this->leftside;
        return newVariable;
    };
    ComplexVariable ComplexVariable::operator+(ComplexVariable sec){
        ComplexVariable newVariable;
        if (!this->leftside) {
            newVariable.a = this->a - sec.a;
            newVariable.b = this->b - sec.b;
            newVariable.c = this->c - sec.c;
            newVariable.leftside = this->leftside;
            return newVariable;
        }
        newVariable.a = this->a + sec.a;
        newVariable.b = this->b + sec.b;
        newVariable.c = this->c + sec.c;
        newVariable.leftside = this->leftside;
        return newVariable;
    };
    ComplexVariable ComplexVariable::operator+(std::complex<double> sec){
        ComplexVariable newVariable;
        if (!this->leftside) {
            newVariable.a = this->a;
            newVariable.b = this->b;
            newVariable.c = this->c - sec;
            newVariable.leftside = this->leftside;
            return newVariable;
        }
        newVariable.a = this->a;
        newVariable.b = this->b;
        newVariable.c = this->c + sec;
        newVariable.leftside = this->leftside;
        return newVariable;
    };

    ComplexVariable ComplexVariable::operator*(ComplexVariable sec){
        ComplexVariable newVariable;
        newVariable.a = this->a*sec.c + this->b*sec.b + this->c*sec.a;
        newVariable.b = this->b*sec.c + this->c*sec.b;
        newVariable.c = this->c*sec.c;
        newVariable.leftside = this->leftside;
        return newVariable;
    };
    ComplexVariable ComplexVariable::operator*(std::complex<double> sec){
        ComplexVariable newVariable;
        newVariable.a = this->a*sec;
        newVariable.b = this->b*sec;
        newVariable.c = this->c*sec;
        newVariable.leftside = this->leftside;
        return newVariable;
    };
    //need to think
    // ComplexVariable ComplexVariable::operator/(ComplexVariable sec){
    //     this->a = this->a*sec.c + this->b*sec.b + this->c*sec.a;
    //     this->b = this->b*sec.c + this->c*sec.b;
    //     this->c = this->c*sec.c;
    //     return this;
    // };
    ComplexVariable ComplexVariable::operator/(std::complex<double> sec){
        ComplexVariable newVariable;
        if (sec == 0.0) {
          throw std::exception();
        }
        newVariable.a = this->a/sec;
        newVariable.b = this->b/sec;
        newVariable.c = this->c/sec;
        newVariable.leftside = this->leftside;
        return newVariable;
    };

    ComplexVariable ComplexVariable::operator^(int sec){
        ComplexVariable newVariable;
        newVariable.a = this->a;
        newVariable.b = this->b;
        newVariable.c = this->c;
        newVariable.leftside = this->leftside;
        if (sec>2 || sec<0) {
            throw std::exception();
        }
        if (sec == 0) {
            newVariable.a = 0;
            newVariable.b = 0;
            newVariable.c = 1;
            return newVariable;
        }
        if (sec == 1) {
            return newVariable;
        }
        if (newVariable.a != 0.0) {
            throw std::exception();
        }
        newVariable.a = this->b*this->b;
        newVariable.b = 2.0*this->b*this->c;
        newVariable.c = this->c*this->c;
        return newVariable;
    };
    ComplexVariable ComplexVariable::operator==(ComplexVariable sec){
        ComplexVariable newVariable;
        newVariable.a = this->a - sec.a;
        newVariable.b = this->b - sec.b;
        newVariable.c = this->c - sec.c;
        newVariable.leftside = false;
        return newVariable;
    };
    ComplexVariable ComplexVariable::operator==(std::complex<double> sec){
        ComplexVariable newVariable;
        newVariable.a = this->a;
        newVariable.b = this->b;
        newVariable.c = this->c - sec;
        newVariable.leftside = false;
        return newVariable;
    };
    ComplexVariable operator * (std::complex<double> sec ,const ComplexVariable & first){
        ComplexVariable newVariable;
        newVariable.a = first.a*sec;
        newVariable.b = first.b*sec;
        newVariable.c = first.c*sec;
        newVariable.leftside = first.leftside;
        return newVariable;
    };
    ComplexVariable operator * (int sec ,const ComplexVariable & first){
        ComplexVariable newVariable;
        newVariable.a = first.a*(1.0*sec);
        newVariable.b = first.b*(1.0*sec);
        newVariable.c = first.c*(1.0*sec);
        newVariable.leftside = first.leftside;
        return newVariable;
    };

    ComplexVariable operator + (std::complex<double> sec,const ComplexVariable & first){
        ComplexVariable newVariable;
        if (!first.leftside) {
            newVariable.a = -first.a;
            newVariable.b = -first.b;
            newVariable.c = -first.c - 1.0*sec;
            newVariable.leftside = first.leftside;
            return newVariable;
        }
        newVariable.a = first.a;
        newVariable.b = first.b;
        newVariable.c = first.c + 1.0*sec;
        newVariable.leftside = first.leftside;
        return newVariable;
    };
    ComplexVariable operator + (int sec,const ComplexVariable & first){
        ComplexVariable newVariable;
        if (!first.leftside) {
            newVariable.a = -first.a;
            newVariable.b = -first.b;
            newVariable.c = -first.c - 1.0*sec;
            newVariable.leftside = first.leftside;
            return newVariable;
        }
        newVariable.a = first.a;
        newVariable.b = first.b;
        newVariable.c = first.c + 1.0*sec;
        newVariable.leftside = first.leftside;
        return newVariable;
    };
    ComplexVariable operator - (std::complex<double> sec,const ComplexVariable & first){
        ComplexVariable newVariable;
        if (!first.leftside) {
            newVariable.a = first.a;
            newVariable.b = first.b;
            newVariable.c = first.c - sec;
            newVariable.leftside = first.leftside;
            return newVariable;
        }
        newVariable.a = -first.a;
        newVariable.b = -first.b;
        newVariable.c = -first.c + 1.0*sec;
        newVariable.leftside = first.leftside;
        return newVariable;
    };
    ComplexVariable operator - (int sec,const ComplexVariable & first){
        ComplexVariable newVariable;
        if (!first.leftside) {
            newVariable.a = first.a;
            newVariable.b = first.b;
            newVariable.c = first.c - 1.0*sec;
            newVariable.leftside = first.leftside;
            return newVariable;
        }
        newVariable.a = -first.a;
        newVariable.b = -first.b;
        newVariable.c = -first.c + 1.0*sec;
        newVariable.leftside = first.leftside;
        return newVariable;
    };
    ComplexVariable operator==(std::complex<double> sec ,const ComplexVariable & first){
        ComplexVariable newVariable;
        newVariable.a = -first.a;
        newVariable.b = -first.b;
        newVariable.c = sec - first.c;
        newVariable.leftside = false;
        return newVariable;
    };
    std::complex<double>  solve(ComplexVariable equ){
      if (equ.a == 0.0 && equ.b == 0.0 && equ.c != 0.0){
          throw std::exception();
      }
      if (equ.a == 0.0){
          return -equ.c/equ.b;
      }
      std::complex<double> val =-equ.b/(2.0*equ.a)  + std::sqrt(equ.b*equ.b-4.0*equ.a*equ.c)/(2.0*equ.a) ;
      val.real(std::round(val.real()));
      val.imag(std::round(val.imag()));
      return val;
    };

};
