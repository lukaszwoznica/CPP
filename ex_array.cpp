#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Exceptions{
protected:
    int n;
public:
    virtual string message() = 0;
};

class OutOfRange : public Exceptions{
public:
    OutOfRange(int n){
            this->n = n;
    }
    virtual string message(){
        stringstream ss;
        ss << "Podano indeks: " << n << ", ktory jest niepoprawny";
        return ss.str();
    }
};

class BadAllocation : public Exceptions{
public:
    BadAllocation(int n){
        this->n = n;
    }
    virtual string message(){
        stringstream ss;
        ss << "Podano zly rozmiar: " << n << ", nie mozna zaalokowac tablicy";
        return ss.str();
    }
};

class Array{
private:
    int *tab;
    int size;
public:
    Array(int s){
        if(s <= 0)
            throw BadAllocation(s);
        tab = new int[s];
        size = s;
    }
    ~Array(){
        delete [] tab;
    }
    int get(int n){
        if(n < 0 || n >= size)
            throw OutOfRange(n);
        return tab[n];
    }
    int & get_ref(int n){
        if(n < 0 || n >= size)
            throw OutOfRange(n);
        return tab[n];
    }
};

int main(){
    try{
        Array tab(-2);
        cout << tab.get(-1) << endl;
    }
    catch(BadAllocation & e1){
        cout << e1.message() << endl;
    }
    catch(OutOfRange & e2){
        cout << e2.message() << endl;
    }
    return 0;
}
