#include <iostream>

using namespace std;

class OutOfRange{
private:
    unsigned int x1, x2, x3, n;
public:
    OutOfRange(unsigned int x1, unsigned int x2, unsigned int x3, unsigned int n){
        this->x1 = x1;
        this->x2 = x2;
        this->x3 = x3;
        this->n = n;
    }
    void message() const{
        if(x1 >= n)
            cout << "Indeks w tablicy 1 został przekroczony" << endl;
        if(x2 >= n)
            cout << "Indeks w tablicy 2 został przekroczony" << endl;
        if(x3 >= n)
            cout << "Indeks w tablicy 3 został przekroczony" << endl;
    }
};

void swap(int t1[], int t2[], int t3[], unsigned int n, unsigned int l1, unsigned int l2, unsigned int l3){
    if(l1 >= n || l2 >= n || l3 >= n)
        throw OutOfRange(l1, l2, l3, n);
    int temp[3];
    temp[0] = t1[l1];
    temp[1] = t2[l2];
    temp[2] = t3[l3];
    t2[l2] = temp[0];
    t3[l3] = temp[1];
    t1[l1] = temp[2];
}

int main(){
    int size=3;
    int tab1[3] = {1,2,3};
    int tab2[3] = {4,5,6};
    int tab3[3] = {7,8,9};
    int l1 = 0, l2 = 1, l3 = 3;
    try{
        swap(tab1, tab2, tab3, size, l1, l2, l3);
        cout << "tab1[" << l1 << "] = " << tab1[l1] << endl;
        cout << "tab2[" << l2 << "] = " << tab2[l2] << endl;
        cout << "tab3[" << l3 << "] = " << tab3[l3] << endl;
    }
    catch(const OutOfRange &e){
        e.message();
    }

    return 0;
}
