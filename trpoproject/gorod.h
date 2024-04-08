//gorod.h
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class streets;
class museums;
class theatres;

class gorod //������� �����
{
    //�������� ������
    static string data; //����
    static float time_to_spend; //����������� ����������������� ��������
    static int kolchelprog; //���������� �������

    //�������������� ������
    static float totaltime; //��������� �����
    static int transport; //��� ����������
    static float plata_for_transport; //����� �� ��������� �� ��������
    static int kolplat_for_transport; //���������� �����, �������� �� ��������� (����� 1 ����� �� ����, ���. ��������� - ������ ������ �� ���� ���)
    static int food; //��� ���
    static float price_for_food; //��������� ��� �� ��������

    float vrodinobj; //����������� ����� ��� ������� ������
    string nazv; //�������� �������
    float dublir_totaltime; //����������� ��������� �����


public:

    gorod()
    {
        nazv = "";
    }

    virtual void func() {}; //����������� �������


    void set_dan(string dat, float time_spend, int kolchelgo)
    {
        data = dat;
        time_to_spend = time_spend;
        kolchelprog = kolchelgo;
    }
    void set_nazv(string naz)
    {
        nazv = naz;
    }
    string get_nazv()
    {
        return nazv;
    }
    string get_data()
    {
        return data;
    }


    void set_and_uvelich_totaltime(float vr)
    {
        vrodinobj = vr;
        totaltime = totaltime + vrodinobj;
    }

    float get_totaltime()
    {
        return totaltime;
    }
    void set_dublir_totaltime(float vrem)
    {
        dublir_totaltime = totaltime + vrem;

    }

    float get_dublir_totaltime()
    {
        return dublir_totaltime;
    }

    void set_transport(int transp)
    {
        transport = transp;
        if (transport == 1)
        {
            kolplat_for_transport = 1;
            plata_for_transport = 500;
            totaltime = totaltime - totaltime / 5;
        }
        else if (transport == 2)
        {
            kolplat_for_transport = kolchelprog;
            plata_for_transport = 50;
            totaltime = totaltime - totaltime / 10;
        }

    }

    void set_food(int eda)
    {
        food = eda;
        if (food == 1)
        {
            price_for_food = 1500;
        }
        else if (food == 2)
        {
            price_for_food = 500;
        }
    }


    bool operator>= (gorod provvr);



    friend void vichpm(vector <streets> street); //���������� ���������� ���������� ��������
    friend void vichpm(vector <streets> street, vector <museums> museum, theatres theatre); //���������� �����, ����������� ��� ������������� ��������

    ~gorod() {}


};