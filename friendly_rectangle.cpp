#include <iostream>

using namespace std;

class Rectangle;

class Checker{
public:
    static bool isSquare(Rectangle &);
};

class Rectangle{
friend class Checker;
private:
    double width, height;
public:
    void set_w_h(double width, double height){
        this->width = width;
        this->height = height;
    }
};

bool Checker::isSquare(Rectangle & r){
    if(r.width == r.height)
        return true;
    else
        return false;
}

int main(){
    Rectangle r;
    r.set_w_h(4,4);
    cout << Checker::isSquare(r) << endl;
    return 0;
}
