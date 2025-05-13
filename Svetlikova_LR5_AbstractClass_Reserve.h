#ifndef SVETLIKOVA_LR_5_6_ABSTRACT_H
#define SVETLIKOVA_LR_5_6_ABSTRACT_H
#include "Svetlikova_LR5_def.h"


using namespace std;

class Reserve{
protected:
    // string name ="";
    int id, protectedSpeciesCount;//количество охраняемых видов
    double area;//площадь в км²
    virtual ostream& print(ostream& myostream) const=0;
    virtual istream& input(istream& myistream);
public:
    // дефолтный
    Reserve():id(0){}
    // копирования
    Reserve(const Reserve &other_reserve):id(other_reserve.id){}
    // преобразования
    Reserve(const int& id):id(id){}
    // виртуальный деструктор
    virtual ~Reserve(){}

    // геты
    int get_id()const {return id;}
    int get_protectedSpeciesCount()const {return protectedSpeciesCount;}
    double get_area()const {return area;}

    // сеты
    void set_id(int i) {id=i;}
    void set_protectedSpeciesCount(int p) {protectedSpeciesCount=p;}
    void set_area(double a) {area=a;}

    // перегрузка ==по id 
    // virtual Reserve* operator==(const Reserve & other_reserve)const=0;
    bool operator==(const Reserve& other) const;

    // дружественные ввод и вывод
    friend ostream& operator<<(ostream& myostream,const Reserve & reserve){
        return reserve.print(myostream);
    }
    friend istream& operator>>(istream& myistream,Reserve & reserve){
        return reserve.input(myistream);
    }
    // чисто виртуальные calculateEcoImpact() и getBiomeType() и validate()
    virtual void calculateEcoImpact()const=0;
    virtual void getBiomeType()const=0;
    virtual void validate()const=0;
    
};
istream& Reserve:: input(istream& myistream){
    enter_number(myistream,id,"enter id of reserve: ")();
    return myistream;
}

#endif