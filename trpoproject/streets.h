//streets.h
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class gorod;
class museums;
class theatres;

class streets : public gorod //����������� �����
{
    float distance; //����� ������ �����

public:


    streets()  //���������� ������������
    {
        distance = 0;
    }


    void func() //����������� �������
    {
        cout << "____________________________" << endl;
        cout << "��������: " << get_nazv() << endl;
        cout << "����: " << get_data() << endl;
        cout << "����� ������ �����: " << distance << " ��" << endl;
    }


    streets(string nazv, float dist, float vr) //���������� ������������
    {
        distance = dist;
        set_nazv(nazv);
        set_and_uvelich_totaltime(vr);
    }

    float get_distance()
    {
        return distance;
    }
    friend void vichpm(vector <streets> street); //���������� ���������� ���������� ��������
    friend void vichpm(vector <streets> street, vector <museums> museum, theatres theatre); //���������� �����, ����������� ��� ������������� ��������

    ~streets() {}

};