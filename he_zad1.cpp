#include <iostream>
#include <string>

using namespace std;

class CGood {
private:
    int a;
public:
    CGood(int);
};

CGood::CGood(int a){
    this->a=a;
}

class CComponent {
private:
    double b;
    string c;
public:
    CComponent(double, string);
};

CComponent::CComponent(double b, string c){
    this->b=b;
    this->c=c;
}

class CBetter : public CGood {
private:
    CComponent d;
public:
    CBetter(int a, double b, string c) : CGood(a), d(b, c) {}
};

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
