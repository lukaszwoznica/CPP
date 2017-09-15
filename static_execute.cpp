#include <iostream>

using namespace std;

class Counter{
public:
    static void execute(){
        static int l = 0;
        cout << "To jest wykonanie numer: " << l++ << endl;
    }
};

int main()
{
    Counter::execute();
    Counter::execute();
    Counter::execute();
    Counter::execute();
    Counter tab[30];
    for(int i=0; i<30; i++){
       tab[i].execute();
    }
    return 0;
}
