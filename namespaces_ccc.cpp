#include <iostream>

double c = 2.5;
namespace C {
    double c = 7.0;

    class C {
    private:
        double c;
    public:
        C(double c);
        double get_c() {return c;}
    };
}

namespace C {
    namespace CC {
        double c = 9.0;
        class CC : public C::C {
        private:
            double c;
        public:
            CC(double c, double cc);
            double get_c() {return c;}
        };
 }
}

C::C::C(double c) : c(c) {
}

C::CC::CC::CC(double c, double cc) : C(c), c(cc) {

}

int main(){
    double c = 15.0;
    C::C *pc = new C::CC::CC(1.0, 2.0);
    std::cout << ::c + C::c + pc->get_c() + C::CC::c + ((C::CC::CC *)pc)->get_c() + c << std::endl;
    delete pc;
    return 0;
}
