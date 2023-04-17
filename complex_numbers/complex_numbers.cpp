//Complex Numbers Class Practice Assignment
//The Program utilises the "classes" tool within C++ and does most operations of complex numbers using overloaded operators
//By: Qi Nohr Chen Date: 10.03.2023

#include<iostream>
#include<cmath>

class Complex
//Complex Number Class
{
    //Friend Function overloading ostream operator
    friend std::ostream & operator<<(std::ostream &os, const Complex &c_number);

private:
//Private data
    double real;
    double imaginary;
public:
    // Constructors & destructor
    Complex() = default;
    Complex(double r, double i) : real{r},imaginary{i}{}
    ~Complex(){} //Destructor

    double return_real()
    {
        //Returns the real part of the complex number
        std::cout << "The real part of the Complex Number is: " << real << std::endl;
        return real;
    };
    
    double return_imaginary()
    {
        //Returns the imaginary part of the complex number
        std::cout << "The imaginary part of the Complex Number is: " << imaginary << std::endl;
        return imaginary;
    };

    double return_modulus(); //Function returning the modulus
    double return_argument(); //Function returning the argument
    
    Complex return_conjugate()
    {
        //Function returning the conjugate
        Complex complex_conjugate;
        complex_conjugate.real = real;
        complex_conjugate.imaginary = imaginary * -1;
        return complex_conjugate;
    };

    // Overloading operator
    Complex operator + (const Complex &complex_num) 
    {
        //Overloading the + Operator
        Complex added_comp_num;
        added_comp_num.real = real + complex_num.real;
        added_comp_num.imaginary = imaginary + complex_num.imaginary;
        return added_comp_num;
    };

    Complex operator - (const Complex &complex_num)
    {
        //Overlading the - Operator
        Complex subtracted_comp_num;
        subtracted_comp_num.real = real -complex_num.real;
        subtracted_comp_num.imaginary = imaginary - complex_num.imaginary; 
        return subtracted_comp_num;
    };

    Complex operator * (const Complex &complex_num)
    {
        //Overloading the * operator
        Complex multiplied_comp_num;
        multiplied_comp_num.real = complex_num.real * real - imaginary * complex_num.imaginary;
        multiplied_comp_num.imaginary =  complex_num.real * imaginary + complex_num.imaginary * real;
        return multiplied_comp_num;
    }

    
    Complex operator / (Complex &complex_num)
    {
        //Overloading the / operator
        Complex divided_comp_num;
        double modulus{pow(complex_num.return_modulus(),2)};
        Complex top;
        top = *this * complex_num.return_conjugate();
        top.real = (top.real)/modulus;
        top.imaginary = (top.imaginary)/modulus;
        return top;
    };
};

double Complex::return_modulus()
    {
        //Function returns modulus
        return sqrt(real*real + imaginary*imaginary);
    };

double Complex::return_argument()
{
    //Function returns argument of a complex number
    double fraction{real/imaginary};
    double argument{atan(fraction)};
    return argument;
};

std::ostream & operator<<(std::ostream &os, const Complex &c_number)
{
    //Overloading the ostream and cout for complex numbers
    if (c_number.imaginary < 0){
    os<<c_number.real<< "" << c_number.imaginary<< "i";
    return os;}
    else if(c_number.imaginary >= 0){
    os<<c_number.real<< "+" << c_number.imaginary<< "i";
    return os;
    }
    return os;
};



int main()
{
    //Main function
    Complex c1{2,3};
    Complex cc{c1.return_conjugate()};
    std::cout << "Complex Number 1:" << std::endl;
    std::cout << c1 <<std::endl;
    double im{c1.return_imaginary()};
    double re{c1.return_real()};
    std::cout << "Complex Number 1 real: " << re << std::endl;
    std::cout << "Complex Number 1 imaginary: " << im << std::endl;
    std::cout << "Complex Number 1 conjugate: " << cc << std::endl; 
    std::cout << "Complex Number 1 argument: " << c1.return_argument() << std::endl; 
    Complex c2{4,5};
    std::cout << "Complex Number 2:" << std::endl;
    std::cout << c2 <<std::endl;
    
    Complex c3;

    std::cout << "ADDITION" <<std::endl;
    c3 = c1 + c2;
    std::cout << c3 <<std::endl;

    std::cout << "SUBTRACTION" <<std::endl;
    c3= c1 - c2;
    std::cout << c3 <<std::endl;

    std::cout << "MULTIPLICATION" <<std::endl;
    c3 = c1 * c2;
    std::cout << c3 <<std::endl;

    std::cout << "DIVISION" <<std::endl;
    c3 = c1 / c2;
    std::cout << c3 <<std::endl;

    return 0;
}
