#include <iostream>

using namespace std;

class B{
    public:
        int arg;
        B(const int &a):arg(a){ printf("[log] Объект класса B создан\n"); }
        ~B(){ printf("[log] Объект класса B разрушен\n"); }
};

class A{
    public:
        B *cb;
        A(const int &arg){ cb = new B(arg); printf("[log] Объект класса A создан\n"); }
        ~A(){ delete cb; printf("[log] Объект класса A разрушен\n"); }
};

int main(){
    A ac(1);
}
