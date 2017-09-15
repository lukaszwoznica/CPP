#include <iostream>

using namespace std;

class Math{
public:
    static const double pi;
    static double deg2rad(int alfa);
};

const double Math::pi = 3.14;

double Math::deg2rad(int alfa){
    return alfa*pi/180;
}

int main()
{
    cout << Math::deg2rad(240) << endl;
    return 0;
}
