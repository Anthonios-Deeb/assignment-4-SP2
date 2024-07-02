// anthoniosdb@gmail.com
// 3993
#include "Complex.hpp"

Complex::Complex(double real, double imaginary) : real(real), imaginary(imaginary)
{
}

// Get the real part of the complex number
double Complex::get_real() const
{
    return real;
}

// Get the imaginary part of the complex number
double Complex::get_imaginary() const
{
    return imaginary;
}

// Convert the complex number to a string
string Complex::to_string() const
{
    return std::to_string(real) + " + " + std::to_string(imaginary) + "i";
}

// Check if the current complex number is equal to the given complex number
bool Complex::operator==(const Complex &complex) const
{
    return real == complex.real && imaginary == complex.imaginary;
}

// Check if the current complex number is less than the given complex number
bool Complex::operator<(const Complex &complex) const
{
    if (real < complex.real)
    {
        return true;
    }
    else if (real == complex.real)
    {
        return imaginary < complex.imaginary;
    }

    return false;
}

// Print the complex number
ostream &operator<<(ostream &os, const Complex &complex)
{
    os << complex.real << " + " << complex.imaginary << "i";
    return os;
}