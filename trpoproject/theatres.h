//theatres.h
#include <iostream>
#include <vector>
#include <string>
using namespace std;


class gorod;
class streets;
class museums;

class theatres : public gorod //����������� �����
{

    float price;

public:
    theatres() //���������� ������������
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

    void set_price(float pr)
    {
        price = pr;
    }
    float get_price()
    {
        return price;
    }

    theatres(string nazv, float vr) //���������� ������������
    {
        set_nazv(nazv); //���������� �������� ������ � ������� ������
        set_and_uvelich_totaltime(vr); //���������� ������� ��������� ������
        //� ���������� ������ ������� � ������� ������
    }

    friend void vichpm(vector <streets> street, vector <museums> museum, theatres theatre); //���������� �����, ����������� ��� ������������� ��������

    ~theatres() {}
};