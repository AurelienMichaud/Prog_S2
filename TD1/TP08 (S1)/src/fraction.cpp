#include "fraction.hpp"
#include "utils.hpp"

#include <iostream>

void Fraction::display() {
    std::cout << numerator << "/" << denominator;
}

Fraction add(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator + f2.numerator * f1.denominator,
        f1.denominator * f2.denominator
    });
}

// Fraction add(Fraction const& f1, Fraction const& f2) {
//     Fraction result {
//         f1.numerator * f2.denominator + f2.numerator * f1.denominator
//         f1.denominator * f2.denominator
//     };

//     return simplify(result);
// }


//Fraction sub(Fraction const& f1, Fraction const& f2) {
//    return simplify({
//        f1.numerator * f2.denominator - f2.numerator * f1.denominator,
//        f1.denominator * f2.denominator
//    });
//}

Fraction operator+(Fraction const& a, Fraction const& b) {
    return {add(a,b)};
}

Fraction mul(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.numerator,
        f1.denominator * f2.denominator
    });
}
Fraction operator*(Fraction const& a, Fraction const& b) {
    return {mul(a,b)};
}

Fraction div(Fraction const& f1, Fraction const& f2) {
    return simplify({
        f1.numerator * f2.denominator,
        f1.denominator * f2.numerator
    });
}

Fraction operator/(Fraction const& a, Fraction const& b) {
    return {div(a,b)};
}