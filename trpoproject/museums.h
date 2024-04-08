//museums.h
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class gorod;
class streets;
class theatres;

class museums : public gorod //����������� �����
{

    float price; //���� ������ � ����� �� ��������
    int day, month, year; //����, �����, ��� ��������� ����� (��������)
public:

    museums() //���������� ������������
    {
        price = 0;
    }

    void func() //����������� �������
    {

        cout << "��������: " << get_nazv() << endl;
        cout << "����: " << get_data() << endl;
        cout << "���� ������ �� ��������: " << price << " ������" << endl;
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
    friend bool check_data(vector <museums> museum); //�������� ���� �� �������������

    friend void vichpm(vector <streets> street, vector <museums> museum, theatres theatre); //���������� �����, ����������� ��� ������������� ��������

    museums(string dat, float time_spend, int kolchelgo) //���������� ������������
    {
        set_dan(dat, time_spend, kolchelgo);
    }

    museums(string nazv, float vr) //���������� ������������
    {
        set_nazv(nazv); //���������� �������� ����� � ������� ������
        set_and_uvelich_totaltime(vr);  //���������� ������� ��������� ����� 
        //� ���������� ������ ������� � ������� ������
    }
    ~museums() {}
};