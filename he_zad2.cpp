#include <iostream>
#include <string>

using namespace std;

// BankAccount - start

class BankAccount {
private:
    string * name;
    string * acc_name;
    string * acc_nr;
    double saldo;
protected:
    void set_saldo(double);
    double get_saldo();
public:
    BankAccount(string, string, string, double saldo = 0);
    BankAccount(const BankAccount &);
    ~BankAccount();
    void add_saldo(double);
    bool sub_saldo(double);
    void show_acc_data();
    string get_name() const;
    string get_acc_name() const;
    string get_acc_nr() const;
};

BankAccount::BankAccount(string name, string acc_name, string acc_nr, double saldo){
    this->name = new string(name);
    this->acc_name = new string(acc_name);
    this->acc_nr = new string(acc_nr);
    this->saldo = saldo;
}

void BankAccount::add_saldo(double amount){
    saldo = saldo + amount;
}

bool BankAccount::sub_saldo(double amount){
    if(amount > saldo)
        return false;
    else{
        saldo = saldo - amount;
        return true;
    }
}

void BankAccount::show_acc_data(){
    cout << name << endl << acc_name << endl << acc_nr << endl << saldo << endl;
}

string BankAccount::get_name() const{
    return *name;
}

string BankAccount::get_acc_name() const{
    return *acc_name;
}

string BankAccount::get_acc_nr() const{
    return *acc_nr;
}

BankAccount::BankAccount(const BankAccount &ba1){
    this->name = new string(ba1.get_name());
    this->acc_name = new string(ba1.get_acc_name());
    this->acc_nr = new string(ba1.get_acc_nr());
    this->saldo = ba1.saldo;
}

BankAccount::~BankAccount(){
    delete name;
    delete acc_name;
    delete acc_nr;
}

void BankAccount::set_saldo(double saldo){
    this->saldo = saldo;
}

double BankAccount::get_saldo(){
    return saldo;
}

// BankAccount - end

//BankAccountVIP - start

class BankAccountVIP : public BankAccount {
private:
    double debit;
    double max_debit;
public:
    BankAccountVIP(string, string, string, double, double, double);
    BankAccountVIP(const BankAccountVIP &);
    void add_saldo(double);
    void sub_saldo(double);
    void set_max_debit(double);
    double get_max_debit();
    void show_vip_acc_data();
};

BankAccountVIP::BankAccountVIP(string name, string acc_name, string acc_nr, double saldo, double debit, double max_debit) : BankAccount(name, acc_name, acc_nr, saldo) {
    this->debit = debit;
    this->max_debit = max_debit;
}

/*BankAccountVIP::BankAccountVIP(const BankAccountVIP &ba1) : BankAccount(const BankAccount &ba1){
    this->debit = ba1.debit;
    this->max_debit = ba1.max_debit;
}*/

void BankAccountVIP::add_saldo(double saldo){
    BankAccount::add_saldo(saldo);
}

void BankAccountVIP::sub_saldo(double saldo){
    double saldo_temp = BankAccount::get_saldo();
    saldo_temp = saldo_temp - saldo;
    BankAccount::set_saldo(saldo_temp);
}

void BankAccountVIP::set_max_debit(double max_debit){
    this->max_debit = max_debit;
}

double BankAccountVIP::get_max_debit(){
    return max_debit;
}

void BankAccountVIP::show_vip_acc_data(){
    BankAccount::show_acc_data();
    cout << debit << endl << max_debit << endl;
}

// BankAccountVIP - end

// Bank - start

class Bank{
private:
    BankAccount *tab;
    BankAccountVIP *tab_vip;
public:
    Bank(int, int);
    Bank(const Bank &);
    ~Bank();
    BankAccount & get_tab(int);
    BankAccountVIP & get_tab_vip(int);
};

Bank::Bank(int size_1, int size_2){
    tab = new BankAccount[size_1];
    tab_vip = new BankAccountVIP[size_2];
}

int main()
{
    cout << "Hello World!" << endl;
    return 0;
}
