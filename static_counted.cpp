#include <iostream>

using namespace std;

class Counted{
public:
    static int nr;
    Counted();
};

int Counted::nr = 0;

Counted::Counted(){
    nr++;
}

int main(){
    Counted c1;
    Counted c2;
    Counted c3;
    Counted c4;
    cout << Counted::nr << endl;
    return 0;
}
