#include <iostream>
using namespace std;

template <typename T>
class Complex {
private:
    T real;
    T imaginary;
    
public:
    // Konstruktor
    Complex(T real = 0, T imaginary = 0) : real(real), imaginary(imaginary) {}
    
    // Operator przypisania
    Complex& operator=(const Complex& other) {
        if (this != &other) {
            real = other.real;
            imaginary = other.imaginary;
        }
        return *this;
    }
    
    // Operator dodawania
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imaginary + other.imaginary);
    }
    
    // Operator mnożenia
    Complex operator*(const Complex& other) const {
        T realPart = real * other.real - imaginary * other.imaginary;
        T imaginaryPart = real * other.imaginary + imaginary * other.real;
        return Complex(realPart, imaginaryPart);
    }
    
    // Przyjaciel klasy do obsługi wyjścia na std::cout
    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.real;
        if (c.imaginary >= 0) {
            os << "+" << c.imaginary << "i";
        } else {
            os << c.imaginary << "i";
        }
        return os;
    }
};

// DO NOT MODIFY ANYTHING BELOW, MAY RESULT WITH FAILED HOMEWORK
int main() 
{   
    Complex<int> result1;
    Complex<double> result2;
    int re,im;
    double re1,im1;
    
    std::cin>>re;
    std::cin>>im;
    
    Complex<int> c1(re,im);
    
    std::cin>>re;
    std::cin>>im;
    
    Complex<int> c2(re,im);
    
    std::cin>>re1;
    std::cin>>im1;
    
    Complex<double> c3(re1,im1);
    
    std::cin>>re1;
    std::cin>>im1;
    
    Complex<double> c4(re1,im1);
    
    result1 = c1 * c2;
    
    std::cout<< result1 << std::endl;
    
    result2 = c3 + c4;
    
    std::cout<< result2 << std::endl;
    
    return 0; 
}
