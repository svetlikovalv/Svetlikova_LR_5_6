#ifndef SVETLIKOVA_LR_5_6_CHILD_1_H
#define SVETLIKOVA_LR_5_6_CHILD_1_H
#include "Svetlikova_LR5_AbstractClass_Reserve.h"

using namespace std;

class ForestReserve final: virtual public Reserve{
private:
    int treeDensity;//плотность деревьев/га
    double carbonAbsorption;//поглощение CO₂ в тоннах/год
protected:
    ostream& print(ostream& myostream)const override;
    istream& input(istream& myistream);
public:
    // дефолтный
    ForestReserve():treeDensity(0),carbonAbsorption(0){}
    // копирования
    ForestReserve(const ForestReserve &other_f_reserve):Reserve(other_f_reserve),treeDensity(other_f_reserve.treeDensity){}
    // преобразования
    ForestReserve(const int& id,const int& treeDensity):Reserve(id),treeDensity(treeDensity){}
    // виртуальный деструктор
    virtual ~ForestReserve(){}
    // переопределение чисто виртуальных методов 
    void calculateEcoImpact()const override { cout<<"eco impact: "<< carbonAbsorption*area*0.8<<endl; }
    void getBiomeType()const override {cout<<"Лесной биом"<<endl;}
    void validate()const override {if (area>0|| protectedSpeciesCount>=1|| treeDensity <=2000){cout<<"forest data validated"<<endl;}}
    
    void simulateWildfire();//метод уменьшения плотности деревьев на 30%
    
    // перегрузка + (объединение данных двух лесных зон)
    ForestReserve operator+(const ForestReserve & other_f_reserve);

};

#endif