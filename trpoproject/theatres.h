//theatres.h
#include <iostream>
#include <vector>
#include <string>
using namespace std;


class gorod;
class streets;
class museums;

class theatres : public gorod //производный класс
{

    float price;

public:
    theatres() //перегрузка конструктора
    {
        price = 0;
    }

    void func() //виртуальная функция
    {

        cout << "Название: " << get_nazv() << endl;
        cout << "Дата: " << get_data() << endl;
        cout << "Цена билета за человека: " << price << " рублей" << endl;
        cout << "____________________________" << endl;
    }

    void set_price(float pr)
    {
        price = pr;
    }
    float get_price()
    {
        return price;
    }

    theatres(string nazv, float vr) //перегрузка конструктора
    {
        set_nazv(nazv); //сохранение названия театра в базовом классе
        set_and_uvelich_totaltime(vr); //сохранение времени посещения театра
        //и увеличение общего времени в базовом классе
    }

    friend void vichpm(vector <streets> street, vector <museums> museum, theatres theatre); //вычисление суммы, необходимой для осуществления прогулки

    ~theatres() {}
};