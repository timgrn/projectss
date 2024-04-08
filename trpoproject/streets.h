//streets.h
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class gorod;
class museums;
class theatres;

class streets : public gorod //производный класс
{
    float distance; //длина каждой улицы

public:


    streets()  //перегрузка конструктора
    {
        distance = 0;
    }


    void func() //виртуальная функция
    {
        cout << "____________________________" << endl;
        cout << "Название: " << get_nazv() << endl;
        cout << "Дата: " << get_data() << endl;
        cout << "Длина данной улицы: " << distance << " км" << endl;
    }


    streets(string nazv, float dist, float vr) //перегрузка конструктора
    {
        distance = dist;
        set_nazv(nazv);
        set_and_uvelich_totaltime(vr);
    }

    float get_distance()
    {
        return distance;
    }
    friend void vichpm(vector <streets> street); //вычисление суммарного расстояния прогулки
    friend void vichpm(vector <streets> street, vector <museums> museum, theatres theatre); //вычисление суммы, необходимой для осуществления прогулки

    ~streets() {}

};