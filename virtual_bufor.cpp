#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Bufor{
public:
    Bufor() {cout << "Konstruktor Bufor" << endl;}
    virtual ~Bufor() {cout << "Destruktor Bufor" << endl;}
    virtual void dodaj(int) = 0;
    virtual void wypisz() = 0;
};

class BuforTab : public Bufor{
private:
    int *tab;
    int size;
public:
    BuforTab();
    BuforTab(int);
    ~BuforTab();
    virtual void dodaj(int);
    virtual void wypisz();
};

BuforTab::BuforTab(){
    size = 100;
    tab = new int[size];
    cout << "Konstruktor bezargumentowy BuforTab" << endl;
    int i;
    for(i=0; i<=size; i++)
        tab[i] = NULL;
}

BuforTab::BuforTab(int size){
    this->size = size;
    tab = new int[size];
    cout << "Konstruktor jednoargumentowy BuforTab" << endl;
    int i;
    for(i=0; i<=size; i++)
        tab[i] = NULL;
}

BuforTab::~BuforTab(){
    delete [] tab;
    tab = NULL;
    cout << "Destruktor BuforTab" << endl;
}
void BuforTab::dodaj(int x){
    int i;
    for(i=0; i<=size; i++){
        if(tab[i] == NULL){
            tab[i] = x;
            break;
        }
        if(i==size-1){
            cout << "Tablica jest juz pelna!" << endl;
        }
    }
}

void BuforTab::wypisz(){
    int i;
    int s = 0;
    for(i=0; tab[i]!=NULL; i++){
        if(i>=size)
            break;
        cout << tab[i] << ", ";
        s++;
    }
    cout << endl << "Liczba elementow: " << s << endl;
}

class BuforPlik : public Bufor{
private:
    fstream plik;
public:
    BuforPlik();
    BuforPlik(char *);
    ~BuforPlik();
    virtual void dodaj(int);
    virtual void wypisz();
};

BuforPlik::BuforPlik(){
    plik.open("plik.txt", ios::in | ios::out);
    cout << "Konstruktor bezargumentowy BuforPlik" << endl;
}

BuforPlik::BuforPlik(char *sciezka){
    plik.open(sciezka, ios::in | ios::out);
    cout << "Konstruktor jednoargumentowy BuforPlik" << endl;
}

BuforPlik::~BuforPlik(){
    if(plik.good() == true)
        plik.close();
    cout << "Destruktor BuforPlik" << endl;
}

void BuforPlik::dodaj(int x){
    if(plik.good() == true)
        plik << x << endl;
    else
        cout << "Nie wczytano pliku!" << endl;
}

void BuforPlik::wypisz(){
    string dane;
    if(plik.good() == true){
        getline(plik, dane);
        cout << dane << endl;
    }
    else
        cout << "Nie wczytano pliku!" << endl;
}

int main(){
    BuforTab tab1;
    BuforTab tab2(3);
    Bufor *wsk = &tab2;
    wsk->dodaj(3);
    wsk->dodaj(5);
    wsk->dodaj(8);
    wsk->dodaj(1);
    wsk->wypisz();
    BuforPlik plik1;
    BuforPlik plik2("ddd/plik2.txt");
    wsk = &plik1;
    wsk->dodaj(2);
    wsk->dodaj(4);
    wsk->dodaj(9);
    wsk->wypisz();
    wsk = &plik2;
    wsk->dodaj(3);
    wsk->dodaj(4);
    wsk->dodaj(1);
    wsk->wypisz();
    return 0;
}
