#include <iostream>
#include <cmath>

using namespace std;

class Figure{
protected:
    double circumference;
    double area;
public:
    double get_circumference(){return circumference;}
    double get_area(){return area;}
};

class Rectangle : public Figure{
private:
    double a, b;
public:
    Rectangle(double a, double b){
        this->a = a;
        this->b = b;
    }
    void calculate_circumference(){
        circumference = (2*a) + (2*b);
    }
    void calculate_area(){
        area = a*b;
    }
};

class Square : public Figure{
private:
    double a;
public:
    Square(double a) {this->a = a;}
    void calculate_circumference(){
        circumference = 4*a;
    }
    void calculate_area(){
        area = a*a;
    }
};

class Circle : public Figure{
private:
    double r;
public:
    Circle(double r) {this->r = r;}
    void calculate_circumference(){
        circumference = 2*3.14*r;
    }
    void calculate_area(){
        area = 3.14*r*r;
    }
};

class Triangle : public Figure{
private:
    double a, b, c;
public:
    Triangle(double a, double b, double c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    void calculate_circumference(){
        circumference = a+b+c;
    }
    void calculate_area(){
        double p = (a+b+c)/2;
        area = sqrt(p*(p-a)*(p-b)*(p-c));
    }
};

int main(){
    Rectangle prostokat(3,4);
    prostokat.calculate_circumference();
    prostokat.calculate_area();
    cout << prostokat.get_circumference() << endl;
    cout << prostokat.get_area() << endl;

    Square kwadrat(5);
    kwadrat.calculate_circumference();
    kwadrat.calculate_area();
    cout << kwadrat.get_circumference() << endl;
    cout << kwadrat.get_area() << endl;

    Circle kolo(7);
    kolo.calculate_circumference();
    kolo.calculate_area();
    cout << kolo.get_circumference() << endl;
    cout << kolo.get_area() << endl;

    Triangle trojkat(3,4,5);
    trojkat.calculate_circumference();
    trojkat.calculate_area();
    cout << trojkat.get_circumference() << endl;
    cout << trojkat.get_area() << endl;

    return 0;
}
