#include <iostream>
#include <string>

using namespace std;

class Animal{
public:
    string species;
    string name;
};

class Snake : public Animal{
public:
    double length;
    Snake(double legth){
        species = "Waz";
        this->length = length;
    }
};

class Cat : public Animal{
public:
    double length;
    double height;
    Cat(double length, double height){
        species = "Kot";
        this->length = length;
        this->height = height;
    }
};

class Eagle : public Animal{
public:
    double length;
    double wingspan;
    Eagle(double length, double wingspan){
        species = "Orze³";
        this->length = length;
        this->wingspan = wingspan;
    }
};

int main(){
    Snake waz(5.20);
    Cat kot(0.30, 0.25);
    Eagle orzel(1.20, 2.50);
    cout << waz.species;
    return 0;
}
