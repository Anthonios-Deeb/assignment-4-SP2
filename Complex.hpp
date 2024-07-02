// anthoniosdb@gmail.com
// 3993
#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <string>

using namespace std;

class Complex
{

public:
  Complex(double real, double imaginary = 0);                      // Constructor
  double get_real() const;                                         // Get the real part of the complex number
  double get_imaginary() const;                                    // Get the imaginary part of the complex number
  string to_string() const;                                        // Convert the complex number to a string
  bool operator<(const Complex &complex) const;                    // Check if the current complex number is less than the given complex number
  bool operator==(const Complex &complex) const;                   // Check if the current complex number is equal to the given complex number
  friend ostream &operator<<(ostream &os, const Complex &complex); // Print the complex number

private:
  double real;
  double imaginary;
};

#endif // COMPLEX_HPP