#include <iostream>

using namespace std;

class Unique{
private:
    const unsigned int id;
    static unsigned int id_2;
public:
    Unique();
    unsigned int get_id();
};

unsigned int Unique::id_2 = 0;

Unique::Unique() : id(id_2){
    id_2++;
}

unsigned int Unique::get_id(){
    return id;
}

int main(){
    Unique u1;
    Unique u2;
    Unique u3;
    Unique u4;
    cout << u1.get_id() << ", " << u2.get_id() << ", " << u3.get_id() << ", " << u4.get_id() << endl;
    return 0;
}
