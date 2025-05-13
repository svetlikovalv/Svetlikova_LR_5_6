#ifndef SVETLIKOVA_LR_5_6_PARENT_CLASS_H
#define SVETLIKOVA_LR_5_6_PARENT_CLASS_H
#include "Svetlikova_LR5_AbstractClass_Reserve.h"

using namespace std;

class ClimateRegulator: virtual public Reserve
{
private:
    int temperature;// в градусах 
    double air_humidity;// влажность воздуха в процентах от 20 до 100
    double precipitation;//кол-во осадков в миллилитрах
protected:
    ostream& print(ostream& myostream)const override;
    istream& input(istream& myistream)override;
public:
    // дефолтный
    ClimateRegulator():temperature(0),air_humidity(0),precipitation(0){}
    // копирования
    ClimateRegulator(const ClimateRegulator &other):Reserve(other),temperature(other.temperature){}
    // преобразования
    ClimateRegulator(const int& temperature,const double& air_humidity,const double& precipitation):
    temperature(temperature),air_humidity(air_humidity),precipitation(precipitation){}
    // виртуальный деструктор
    virtual ~ClimateRegulator(){}


};



#endif