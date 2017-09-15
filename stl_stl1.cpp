#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int> v;
    int x;
    cout << "Podaj liczby do listy: ";
    for(;;){
        cin >> x;
        v.push_back(x);
        if(x == 0)
            break;
    }
    cout << endl;
    for(list<int>::iterator it = v.begin(); it != v.end(); it++){
        cout << *it << endl;
    }
    return 0;
}
