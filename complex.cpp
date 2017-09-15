#include <iostream>
#include <ostream>

using namespace std;

class LiczbaZespolona{
private:
    double a, b;
public:
    LiczbaZespolona(double a, double b){
        this->a = a;
        this->b = b;
    }
    void set_a(double x){
        a = x;
    }
    void set_b(double x){
        b = x;
    }
    double get_a(){
        return a;
    }
    double get_b(){
        return b;
    }
    LiczbaZespolona operator+( LiczbaZespolona & lz){
        LiczbaZespolona sum(0,0);
        sum.a = a + lz.a;
        sum.b = b + lz.b;
        return sum;
    }
    LiczbaZespolona operator-( LiczbaZespolona & lz){
        LiczbaZespolona sub(0,0);
        sub.a = a - lz.a;
        sub.b = b - lz.b;
        return sub;
    }
};

ostream & operator<<(ostream &s, LiczbaZespolona &lz){
        return s << "[" << lz.get_a() << ", " << lz.get_b() << "]";
}

int main(){
    LiczbaZespolona z1(4,3);
    LiczbaZespolona z2(2,2);
    LiczbaZespolona z3 = z1-z2;
    LiczbaZespolona z4 = z1+z2;
    cout << z3 << endl;
    cout << z4 << endl;
    return 0;
}

/*Napisz klasę LiczbaZespolona, zawierającą dwa pola prywatne typu double (a oraz b). Każde z pól
powinno posiadać swój setter i getter. Następnie poza klasą zdefiniuj operatory dodawania
i odejmowania obiektów tej klasy. Każdy z tych operatorów powinien zwracać nowy obiekt klasy
LiczbaZespolona. Użycie konstruktorów jest opcjonalne.*/
