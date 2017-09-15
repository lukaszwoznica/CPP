#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

class Encyclopedia{
private:
    vector< pair<string, string> > v;
public:
    void add(string word, string definition){
        pair<string, string> p;
        p.first = word;
        p.second = definition;
        v.push_back(p);
    }
    string find(string word){
        for(size_t it = 0; it < v.size(); it++){
            if(v[it].first == word)
                return v[it].second;
        }
        return "";
    }
};

int main(){
    Encyclopedia enc;
    enc.add("Lampard", "Angielski pilkarz");
    enc.add("Ronaldinho", "Brazylijski pilkarz");
    enc.add("Lewandowski", "Polski pilkarz");
    cout << enc.find("Lewandowski") << endl;
    return 0;
}
