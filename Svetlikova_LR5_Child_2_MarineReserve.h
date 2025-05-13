#ifndef SVETLIKOVA_LR_5_6_CHILD_2_H
#define SVETLIKOVA_LR_5_6_CHILD_2_H
#include "Svetlikova_LR5_AbstractClass_Reserve.h"

using namespace std;

class MarineReserve final: virtual public Reserve{
private:
    double coralCover; //% кораллового покрова
    int waterPollutionLevel; //уровень загрязнения: 1-5
protected:
    ostream& print(ostream& myostream)const override;
    istream& input(istream& myistream);
public:
    // дефолтный
    MarineReserve():coralCover(0),waterPollutionLevel(0){}
    // копирования
    MarineReserve(const MarineReserve &other_m_reserve):Reserve(other_m_reserve),coralCover(other_m_reserve.coralCover){}
    // преобразования
    MarineReserve(const int& id,const int& coralCover):Reserve(id),coralCover(coralCover){}
    // виртуальный деструктор
    virtual ~MarineReserve(){}

    // переопределение чисто виртуальных методов
    void calculateEcoImpact()const override { cout<<"eco impact: "<<(100 - waterPollutionLevel*15)*coralCover<<endl; }
    void getBiomeType()const override {cout<<"Морской биом"<<endl;}
    void validate()const override{if(0<=coralCover&& coralCover<=100){cout<<"marine data validated"<<endl;}}
    
    // доп метод
    void trackPlasticWaste();
    // перегрузка += (увеличение кораллового покрова на 5%)
    MarineReserve& operator+=(double percent);

}; 


#endif