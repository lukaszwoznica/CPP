#include <iostream>
#include <cmath>

using namespace std;

double SQRT(double x){
    if(x < 0)
        throw x;
    return sqrt(x);
}

int main(){
    double x;
    cout << "Podaj liczbę:" << endl;
    cin >> x;
    try{
       double y =SQRT(x);
       cout << "Pierwiastek z liczby " << x << " wynosi " << y << endl;
    }
    catch(const double a){
        cout << "Podałeś liczbę " << a << ", która jest liczbą ujemną" << endl;
    }
    return 0;
}
