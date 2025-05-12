#ifndef SVETLIKOVA_LR_5_6_ABSTRACT_H
#define SVETLIKOVA_LR_5_6_ABSTRACT_H
#include "Svetlikova_LR5_def.h"


using namespace std;

class Reserve{
protected:
    string name ="";

    virtual ostream& print(ostream& myostream) const=0;
    virtual istream& input(istream& myostream);
public:
    // дефолтный
    Reserve():name("no name character"){}
    // копирования
    Reserve(const Reserve &other_character):name(other_character.name){}
    // преобразования
    Reserve(const string& name):name(name){}
    // деструктор
    virtual ~Reserve(){}

    virtual Reserve* operator+(const Reserve & other_reserve)const=0;

    friend ostream& operator<<(ostream& myostream,const Reserve & reserve){
        return reserve.print(myostream);
    }
    friend istream& operator>>(istream& myistream,Reserve & reserve){
        return reserve.input(myistream);
    }

};
istream& Reserve:: input(istream& myistream){
    enter_string(myistream,name,"enter name of character: ")();
    return myistream;
}

#endif