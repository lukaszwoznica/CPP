#include <iostream>

using namespace std;

class Value{
friend class ValuePrinter;
private:
    int val;
public:
    Value(int val){
        this->val = val;
    }
    friend void swap(Value &, Value &);
};

class ValuePrinter{
public:
    void printValue(Value &w){
        cout << w.val << endl;
    }
};

void swap(Value &w1, Value &w2){
    Value w3(0);
    w3.val = w2.val;
    w2.val = w1.val;
    w1.val = w3.val;
}

int main(){
    Value w1(5);
    ValuePrinter print;
    print.printValue(w1);
    Value w2(8);
    swap(w1, w2);
    print.printValue(w1);
    print.printValue(w2);
    return 0;
}
