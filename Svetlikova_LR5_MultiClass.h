#ifndef SVETLIKOVA_LR_5_6_MULTI_CLASS_H
#define SVETLIKOVA_LR_5_6_MULTI_CLASS_H
#include "Svetlikova_LR5_AbstractClass_Reserve.h"
#include "Svetlikova_LR5_Parent_Class.h"

using namespace std;

class  WetlandReserve : virtual public Reserve,virtual public ClimateRegulator
{
private:
    int waterRetention ;//удержание воды в млн литров
    int floodRiskLevel ;//риск наводнений: 1-10
protected:
    ostream& print(ostream& myostream)const override;
    istream& input(istream& myistream)override;
public:
    // виртуальный деструктор
    virtual ~WetlandReserve(){}
    WetlandReserve();
    WetlandReserve(int id);
    WetlandReserve(const WetlandReserve& other);
    // добавить из ClimateRegulator поля
    WetlandReserve(int id, double area, int protectedSpeciesCount, double waterRetention, int floodRiskLevel);
    // виртуальный деструктор
    virtual ~WetlandReserve(){}//хули не работает..
    // переопределение чисто виртуальных методов 
    void calculateEcoImpact()const override { cout<<"eco impact: "<<waterRetention*1000 - floodRiskLevel*5000<<endl; }
    void getBiomeType()const override {cout<<"Болотистый биом"<<endl;}
    void validate()const override {if (floodRiskLevel <=5 ){cout<<"wetland data validated"<<endl;}}
    // доп метод
    int preventErosion();//снижение риска наводнений на 2 пункта
    // перегрузка []
    double operator[](const string& climateParameter) const;
};


#endif