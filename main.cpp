#include <iostream>

using namespace std;

class Food{
    public:
        int *Freshness;
        int *HealthBuff;
        Food(const int &f, const int &hb) : Freshness(new int(f)), HealthBuff(new int(hb)){
            printf("[log] Объект класса еда создан\n");
        }
        int GetFreshness(){
            return *Freshness;
        }
        int GetHelthBuff(){
            return *HealthBuff;
        }
        ~Food(){
            delete Freshness;
            delete HealthBuff;
            printf("[log] Объект класса еда разрушен\n");
        }
};

class Cheburek : public Food{
    public:
        int *Juiciness;
        Cheburek(const int &f, const int &hb, const int &j) : Food(f, hb), Juiciness(new int(j)){
            printf("[log] Объект класса чебурек создан\n");
        }
        void DryingOut(){
            printf("[log] Чебурек заветривается, juiciness = %d\n", --*Juiciness);
        }
        ~Cheburek(){
            delete Juiciness;
            printf("[log] Объект класса чебурек разрушен\n");
        }
        
};

int main(){
    Cheburek *c = new Cheburek(100, 300, 110);
    printf("Свежесть чебурека = %d\n", c->GetFreshness());
    c->DryingOut();
    delete c;
}
