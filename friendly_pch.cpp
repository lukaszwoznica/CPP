#include <iostream>

using namespace std;

class PrivateConstructorHolder{
friend class Builder;
private:
    PrivateConstructorHolder(){
        cout << "Utworzono obiekt klasy PrivateConstructorHolder" << endl;
    }
};

class Builder{
private:
    PrivateConstructorHolder pch;
};

int main(){
    Builder b;
    return 0;
}
