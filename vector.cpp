#include <iostream>
#include <vector>
#include <utility>

using namespace std;

pair<int,int> min_max(vector <int> &v){
    pair <int, int> p;
    int vMax,vMin;
    vMax = v[0];
    vMin = v[0];
    for( size_t i = 0; i < v.size(); i++ ){
        if(vMax < v[i]){
            vMax = v[i];
        }
        if(vMin > v[i]){
            vMin = v[i];
        }
    }
    p = make_pair (vMin,vMax);
    return p;
}
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    v.push_back(6);
    v.push_back(0);
    pair<int,int> p;
    p = min_max(v);
    cout << p.first << ", " << p.second << endl;
    return 0;
}


/*
Napisz funkcję, która będzie obliczała najmniejszą i największą wartość występującą w wektorze
liczb (int lub double). Wektor powinien być przekazywany do funkcji jako argument (np. przez
referencję). Wynik powinien być zwracany w postaci pary liczb (szablon pair), z których pierwsza
będzie zawierała obliczone minimum, a druga maksimum.
*/
