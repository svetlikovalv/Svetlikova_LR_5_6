#include <ctime>
#include <map>
#include "Svetlikova_LR5_Methods.h"
#include "Svetlikova_LR5_def.h"
using namespace std;

//структура для менюшки
struct menu_item {
    string title;
    function<void()> action;
};


int main(){
    srand(time(NULL));
    map<int, menu_item > menu = {
        {1,{"",}},
        {2,{"",}},
        {3,{"",}},
        {4,{"",}},
        {5,{"",}},
        {6,{"",}},
        {7,{"",}},
        {8,{"",}},
        {9,{"",}},
        {10,{"",}},
        {11,{"",}},
        {12,{"",}},
        {13,{"",}},
        {14,{"",}},

    };
    int choice = 0;

    cout<<"Меню: "<<endl;
    for (const auto& item : menu){
        cout<<"Task "<<item.first<<". "<<item.second.title<<endl;
    }
    cout<<"0. Выход"<<endl;
    while (true){
        enter_number(cin,choice,"Введите номер пункта: ")();
        if (choice==0){
            cout<<"Вы вышли из программы"<<endl;
            break;
        }
        cout<<"==========Action=========="<<endl;
        if (menu.find(choice)!=menu.end()){
            menu[choice].action();
        }
        else{
            cout<<"Некорректный ввод. ";
        }
        cout<<endl;
    }
    return 0;
}