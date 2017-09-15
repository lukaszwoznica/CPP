#include <iostream>
#include <cmath>

using namespace std;

class Complex{
private:
    double re;
    double im;
public:
    Complex(double re = 0, double im = 0);
    void set_re_im(double, double);
    double get_re();
    double get_im();
    double get_modulus();
    Complex get_conjugate(Complex & c);
    void show();
};

Complex::Complex(double re, double im){
    this->re = re;
    this->im = im;
}

void Complex::set_re_im(double re, double im){
    this->re = re;
    this->im = im;
}

double Complex::get_re(){
    return re;
}

double Complex::get_im(){
    return im;
}

double Complex::get_modulus(){
    return sqrt((re*re)+(im*im));
}

Complex Complex::get_conjugate(Complex & c){
    c.im = im*(-1);
    c.re = re;
    return c;
}

void Complex::show(){
    if(im >= 0)
        cout << re << " + " << im << "i" << endl;
    else
        cout << re << " - " << im*(-1) << "i" << endl;
}

class Quaternion{
private:
    Complex a, b, c, d;
public:
    Quaternion(Complex &, Complex &);
    Complex get_a();
    Complex get_b();
    Complex get_c();
    Complex get_d();
};

Quaternion::Quaternion(Complex  &z1, Complex  &z2){
    a.set_re_im(z1.get_re(), z1.get_im());
    b.set_re_im(z2.get_re(), z2.get_im());
    c.set_re_im(z1.get_re()*(-1), z1.get_im()*(-1));
    d.set_re_im(z2.get_re()*(-1), z2.get_im()*(-1));
}

Complex Quaternion::get_a(){
    return a;
}

Complex Quaternion::get_b(){
    return b;
}

Complex Quaternion::get_c(){
    return c;
}

Complex Quaternion::get_d(){
    return d;
}

int main(){
    Complex c1(5,7);
    Complex c2(3,8);
    c1.show();
    cout << c1.get_modulus() << endl;
    Complex c1_con = c1.get_conjugate(c1);
    c1_con.show();
    Quaternion q1(c1, c2);
    q1.get_a().show();
    q1.get_b().show();
    q1.get_c().show();
    q1.get_d().show();
    return 0;
}
