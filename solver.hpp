#pragma once

#include <string>
#include <iostream>
#include <complex>

namespace solver {
    class RealVariable {
    public:
        double a;
        double b;
        double c;
        bool leftside;
        RealVariable();
        RealVariable operator-(RealVariable);
        RealVariable operator-(double);
        RealVariable operator+(RealVariable);
        RealVariable operator+(double);
        RealVariable operator*(RealVariable);
        RealVariable operator*(double);
        RealVariable operator/(RealVariable);
        RealVariable operator/(double);
        RealVariable operator^(int);
        RealVariable operator==(RealVariable);
        RealVariable operator==(double);
    };
    class ComplexVariable {
    public:
        std::complex<double> a;
        std::complex<double> b;
        std::complex<double> c;
        bool leftside;
        ComplexVariable();
        ComplexVariable operator-(ComplexVariable);
        ComplexVariable operator-(std::complex<double>);
        ComplexVariable operator+(ComplexVariable);
        ComplexVariable operator+(std::complex<double>);
        ComplexVariable operator*(ComplexVariable);
        ComplexVariable operator*(std::complex<double>);
        ComplexVariable operator/(ComplexVariable);
        ComplexVariable operator/(std::complex<double>);
        ComplexVariable operator^(int);
        ComplexVariable operator==(ComplexVariable);
        ComplexVariable operator==(std::complex<double>);
    };
    RealVariable operator*(double ,const RealVariable & );
    
    RealVariable operator+(double ,const RealVariable & );
    RealVariable operator-(double ,const RealVariable & );

    ComplexVariable operator*(std::complex<double> ,const ComplexVariable & );
    ComplexVariable operator+(std::complex<double> ,const ComplexVariable & );
    ComplexVariable operator-(std::complex<double> ,const ComplexVariable & );
    ComplexVariable operator*(int ,const ComplexVariable & );
    ComplexVariable operator+(int ,const ComplexVariable & );
    ComplexVariable operator-(int ,const ComplexVariable & );
    RealVariable operator==(double ,const RealVariable & );

    ComplexVariable operator==(std::complex<double> ,const ComplexVariable & );
	double solve(RealVariable);
    std::complex<double> solve(ComplexVariable);

}
