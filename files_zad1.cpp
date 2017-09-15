#include <iostream>

using namespace std;

class List{
private:
    int size;
protected:
    void set_size(int s) {size = s;}
public:
    virtual ~List() {}
    int get_size() {return size;}
    virtual void append(char) = 0;
    virtual char & front() = 0;
    virtual char pop_front() = 0;
    virtual void insert(int, char) = 0;
};

class ArrayList : public List{
private:
    char *tab;
public:
    ArrayList(int);
    virtual ~ArrayList();
    virtual void append(char);
    virtual char & front();
    virtual char pop_front();
    virtual void insert(int n, char ch);
    char get_tab(int);
};

ArrayList::ArrayList(int s){
    set_size(s);
    tab = new char[s];
}

ArrayList::~ArrayList(){
    delete [] tab;
    tab = NULL;
}

void ArrayList::append(char x){
    int i;
    for(i=0; i<=get_size(); i++){
        if(tab[i]=='\0'){
            tab[i]=x;
            break;
        }
    }
}

char & ArrayList::front(){
    return tab[0];
}

char ArrayList::pop_front(){
    int i;
    for(i=1; i<=get_size(); i++){
        tab[i-1] = tab[i];
    }
}

void ArrayList::insert(int n, char ch){
    int i;
    for(i=get_size()-1; i>=n; i--){
        tab[i]=tab[i-1];
    }
    tab[n]=ch;
}

char ArrayList::get_tab(int n){
    return tab[n];
}

/*
class LinkedList : public List{
private:
    struct Item{
        char value;
        Item *next;
    };
    Item *head;
public:
    LinkedList();
    virtual ~LinkedList();
    virtual void append(char);
    virtual char & front();
    virtual char pop_front();
    virtual void insert(int i, char ch);
};*/

int main(){
    ArrayList lista(6);
    lista.insert(0,'x');
    lista.insert(1,'d');
    lista.insert(2,'a');
    lista.insert(1,'r');
    lista.append('q');
    lista.pop_front();
    cout << lista.get_tab(0) << endl;
    cout << lista.get_tab(1) << endl;
    cout << lista.get_tab(2) << endl;
    cout << lista.get_tab(3) << endl;
    cout << lista.get_tab(4) << endl;
    return 0;
}
