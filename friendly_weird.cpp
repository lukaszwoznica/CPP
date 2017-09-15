#include <iostream>

using namespace std;

class WeirdClass{
private:
    int x;
    WeirdClass(int x){
        this->x = x;
        cout << "Utworzono obiekt WeirdClass" << endl;
    }
public:
    int get_x(){
        return x;
    }
    friend void makeWeirdObiect(WeirdClass * &, int);
};

void makeWeirdObiect(WeirdClass * &wsk, int x){
    wsk = new WeirdClass(x);
}

int main(){
    WeirdClass * wsk;
    makeWeirdObiect(wsk, 5);
    cout << wsk->get_x() << endl;
    return 0;
}
