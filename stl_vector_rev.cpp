#include <iostream>
#include <vector>

using namespace std;

void vector_reverse(vector<int> & v){
    int temp, i;
    int size = v.size();
    for(i = 0; i < size/2; i++){
        temp = v[i];
        v[i] = v[size-1-i];
        v[size-1-i] = temp;
    }
}

int main() {
    vector<int> v;
    int i,x;
    cout << "Podaj 5 liczb" << endl;
    for(i = 0; i < 5; i++){
        cin >> x;
        v.push_back(x);
    }
    cout << endl;
    cout << "Przed zamianą:" << endl;
    for(i = 0; i < 5; i++){
        cout << v[i] << ", ";
    }
    cout << endl;
    vector_reverse(v);
    cout << "Po zamianie:" << endl;
    for(i = 0; i < 5; i++){
        cout << v[i] << ", ";
    }
    cout << endl;
    return 0;
}
