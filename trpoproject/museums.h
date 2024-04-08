//museums.h
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class gorod;
class streets;
class theatres;

class museums : public gorod //производный класс
{

    float price; //цена билета в музей за человека
    int day, month, year; //день, месяц, год посещения музея (прогулки)
public:

    museums() //перегрузка конструктора
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
    void setelemdata(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }
    void set_price(float pr)
    {
        price = pr;
    }
    float get_price()
    {
        return price;
    }
    int get_day()
    {
        return day;
    }
    int get_month()
    {
        return month;
    }
    int get_year()
    {
        return year;
    }
    friend bool check_data(vector <museums> museum); //проверка даты на существование

    friend void vichpm(vector <streets> street, vector <museums> museum, theatres theatre); //вычисление суммы, необходимой для осуществления прогулки

    museums(string dat, float time_spend, int kolchelgo) //перегрузка конструктора
    {
        set_dan(dat, time_spend, kolchelgo);
    }

    museums(string nazv, float vr) //перегрузка конструктора
    {
        set_nazv(nazv); //сохранение названия музея в базовом классе
        set_and_uvelich_totaltime(vr);  //сохранение времени посещения музея 
        //и увеличение общего времени в базовом классе
    }
    ~museums() {}
};