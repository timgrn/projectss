
#include <iostream>
#include <vector>
#include <string>
#include "C:\Users\timur\source\repos\gorod.h"
#include "C:\Users\timur\source\repos\streets.h"
#include "C:\Users\timur\source\repos\museums.h"
#include "C:\Users\timur\source\repos\theatres.h"


using namespace std;


string gorod::data;
float gorod::time_to_spend;
int gorod::kolchelprog;
float gorod::totaltime;
int gorod::transport;
float gorod::plata_for_transport;
int gorod::kolplat_for_transport;
int gorod::food;
float gorod::price_for_food;


//проверка даты  
bool checknumdata(string a, int nach, int kon)
{
	bool check = false;


    try
    {
	    int b;
	    b = stoi(a); //преобразование string в int


        if ((b < nach) || (b > kon))
        {

            check = false;


        }

        else

        {

            for (int i = 0; i < a.length(); i++)
            {
                if ((a[i] == ',') || (a[i] == '.'))
                {

                    check = false;

                    break;
                }

                if (i == a.length() - 1)
                {
                    check = true;
                }
            }


        }

    }

    catch (std::exception& e)
    {

        check = false;

    }


    return check;
}


//проверка для целочисленных чисел
int checknumberint2(string a, int nach, int kon)
{

    int b=-1;

    bool check = false;

    while (check == false)
    {
        try
        {
            b = stoi(a); //преобразование string в int


            if ((b < nach) || (b > kon))
            {
                cout << "Введено число вне допустимого диапазона. Повторите ввод" << '\n';
                check = false;

                cin >> a;
            }

            else

            {

                for (int i = 0; i < a.length(); i++)
                {
                    if ((a[i] == ',') || (a[i] == '.'))
                    {
                        cout << "Введены некорректные данные. Повторите ввод" << '\n';
                        check = false;
                        cin >> a;
                        break;
                    }

                    if (i == a.length() - 1)
                    {
                        check = true;
                    }
                }


            }

        }

        catch (std::exception& e)
        {
            cout << "Введены некорректные данные. Повторите ввод" << '\n';
            check = false;
            cin >> a;
        }



    }


    return b;
}


//проверка для вещественных чисел
float checknumberfloat2(string a, float nach, float kon)
{

    float b=-1;

    bool check = false;

    while (check == false)
    {
        try
        {
            b = stof(a); //преобразование string в float


            if ((b < nach) || (b > kon))
            {
                cout << "Введено число вне допустимого диапазона. Повторите ввод" << '\n';
                check = false;

                cin >> a;
            }

            else

            {

                for (int i = 0; i < a.length(); i++)
                {
                    if (a[i] == ',')
                    {
                        cout << "Введены некорректные данные. Повторите ввод" << '\n';
                        check = false;
                        cin >> a;
                        break;
                    }

                    if (i == a.length() - 1)
                    {
                        check = true;
                    }
                }


            }

        }

        catch (std::exception& e)
        {
            cout << "Введены некорректные данные. Повторите ввод" << '\n';
            check = false;
            cin >> a;
        }






    }



    return b;
}






bool gorod::operator>= (gorod provvr)
{
    if (time_to_spend >= provvr.get_dublir_totaltime())
    {
        return true;
    }
    else
    {
        return false;
    }
}


bool check_data(vector <museums> museum) //проверка даты на существование
{
    if (museum[0].year != 2024)
    {
        cout << "Введён некорректный год" << '\n';
        return false;
    }

    switch (museum[0].month)
    {
    case 1:  //Январь
    case 3:  //Март
    case 5:  //Май
    case 7:  //Июль
    case 8:  //Август
    case 10: //Октябрь
    case 12: //Декабрь
        if ((museum[0].day < 1) || (museum[0].day > 31))
        {

            return false;

        }
        else { return true; }

    case 2: //Февраль
        if (museum[0].year % 4 == 0)
        {
            if ((museum[0].day < 1) || (museum[0].day > 29))
            {
                return false;

            }
            else { return true; }
        }
        else
        {
            if ((museum[0].day < 1) || (museum[0].day > 28)) { return false; }
            else { return true; }
        }

    case 4: //Апрель
    case 6: //Июнь
    case 9: //Сентябрь
    case 11: //Ноябрь
        if ((museum[0].day < 1) || (museum[0].day > 30))
        {
            return false;

        }
        else { return true; }
    default:
    {
        return false;
    }
    }
}

void vichpm(vector <streets> street, vector <museums> museum, theatres theatre) //вычисление суммы, необходимой для осуществления прогулки
{
    float sum_to_pay; //сумма, необходимая для осуществления прогулки

    sum_to_pay = (museum[0].price + theatre.price + street[0].price_for_food) * theatre.kolchelprog + street[0].kolplat_for_transport * street[0].plata_for_transport;
    cout << "_______________________________________________________" << '\n';
    cout << "Сумма, необходимая для осуществления прогулки: " << sum_to_pay << " рублей" << '\n';
    cout << "_______________________________________________________" << '\n';
}


void vichpm(vector <streets> street) //вычисление суммарного расстояния прогулки
{
    float totaldistance = 0;
    for (auto& i : street)
    {
        totaldistance = totaldistance + i.distance;
    }
    cout << "_______________________________________________________" << '\n';
    cout << "Суммарное расстояние: " << totaldistance << " км" << '\n';
    cout << "За все день на прогулку вы потратите: " << street[0].totaltime << " часов" << '\n';
    cout << "_______________________________________________________" << '\n';
}



int main()
{

    setlocale(LC_ALL, "Russian");

   

    //Запуск тестируемого кода
    


    //
    int vybor_menu = 0;

    while (vybor_menu != 3)
    {
        //главное меню
        cout << "---------------------------------" << '\n';
        cout << "Программа: 'Прогулка по городу'" << '\n';
        cout << "Для запуска программы, нажмите 1" << '\n';
        cout << "Для справки, нажмите 2" << '\n';
        cout << "Для завершения, нажмите 3" << '\n';
        cout << "---------------------------------" << '\n';


        string vybor_menu_str = "";
        cin >> vybor_menu_str;

        //проверка корректности выбора пунктов главного меню
        vybor_menu = checknumberint2(vybor_menu_str, 1, 3);



        if (vybor_menu == 1)
        {
            int nomerulits; //номер улицы для посещения
            vector <streets> street(1); //вектор улиц
            vector <museums> museum(1); //вектор музей
            gorod prvr; //объект для проверки превышения на время и демонстрации перегрузки оператора сравнения
            streets dobavvvect;

            theatres theatre; //объект театр

            string data; //дата

            float planvrpotr; //продолжительность прогулки (в часах)
            int kolchelgo;
            //(для последующего удаления всех превышающих продолжительность прогулки элементов)

            string th[3]; //варианты театров для посещения
            string mus[3]; //варианты музеев для посещения
            float price_th[3]; //цены в театр
            float price_mus[3];//цены в музей
            int check_for_transport;
            int type_eda;
            
            
            int moreinformation;
            bool check; //для проверки на повторяемость улиц
            
            string ul[8] = { "Невский проспект", "улица Рубинштейна", "Садовая улица", "улица Правды",
            "Миллионная улица", "улица зодчего Росси", "улица Чайковского", "улица Фурштатская" }; //варианты улиц для прогулки
            float distance_ul[8] = { 4.5, 0.76, 4.4, 0.6, 1, 0.22, 1.7, 1 }; //протяжённость каждой улицы (в км)
            float vremprog_ul[8] = { 0.75, 0.13, 0.73, 0.1, 0.17, 0.04, 0.28, 0.17 }; //врямя прогулки по каждой улице (в ч)

           
            int day, month, year;
            string daystr, monthstr, yearstr;

            bool checkexistdata = false;
            

            cout << "Допустимый диапазон дат от 1.1.2024 до 31.12.2024" << '\n';

            cout << "Введите дату в формате: число месяц год" << '\n';
            cin >> daystr >> monthstr >> yearstr;




            bool checkday = false;
            bool checkmonth = false;
            bool checkyear = false;

            bool checkdatamain = false;

            while (checkdatamain == false)
            {
                checkday = checknumdata(daystr, 1, 31);
                checkmonth = checknumdata(monthstr, 1, 12);
                checkyear = checknumdata(yearstr, 2024, 2024);

                if ((checkday == true) && (checkmonth == true) && (checkyear == true))
                {
                    checkdatamain = true;
                    day = stoi(daystr);
                    month = stoi(monthstr);
                    year = stoi(yearstr);
                }
                else
                {
                    cout << "Введена некорректная дата. Повторите ввод в формате: число месяц год" << '\n';
                    cin >> daystr >> monthstr >> yearstr;
                    checkday = false;
                    checkmonth = false;
                    checkyear = false;

                }



            }



            museum[0].setelemdata(day, month, year);

            while (checkexistdata == false) //проверка даты на существование
            {
                checkexistdata = check_data(museum);

                if (checkexistdata == false)
                {
                    cout << "Введена некорректная дата. Повторите ввод в формате: день месяц год" << '\n';
                    checkdatamain = false;
                    cin >> daystr >> monthstr >> yearstr;


                    while (checkdatamain == false)
                    {
                        checkday = checknumdata(daystr, 1, 31);
                        checkmonth = checknumdata(monthstr, 1, 12);
                        checkyear = checknumdata(yearstr, 2024, 2024);

                        if ((checkday == true) && (checkmonth == true) && (checkyear == true))
                        {
                            checkdatamain = true;
                            day = stoi(daystr);
                            month = stoi(monthstr);
                            year = stoi(yearstr);
                        }
                        else
                        {
                            cout << "Введена некорректная дата. Повторите ввод в формате: число месяц год" << '\n';
                            cin >> daystr >> monthstr >> yearstr;
                            checkday = false;
                            checkmonth = false;
                            checkyear = false;

                        }



                    }




                    museum[0].setelemdata(day, month, year);
                }
            }

            if (checkexistdata == true)
            {
                data = to_string(museum[0].get_day()) + '.' + to_string(museum[0].get_month()) + '.' + to_string(museum[0].get_year());
            }



            if (museum[0].get_day() % 2 == 0) //если день даты чётный, то один список театров и музеев для посещения
            {
                th[0] = "Мариинский театр"; //варианты театров для посещения
                th[1] = "Александринский театр";
                th[2] = "Большой драматический театр";
                mus[0] = "Эрмитаж"; //варианты музеев для посещения
                mus[1] = "Музей Фаберже";
                mus[2] = "Русский Этнографический музей";
                price_th[0] = 1500; //цены в театр
                price_th[1] = 1000;
                price_th[2] = 500;
                price_mus[0] = 1000;//цены в музей
                price_mus[1] = 500;
                price_mus[2] = 1500;



            }
            else //если день даты нечётный, то другой список театров и музеев для посещения
            {
                th[0] = "Малый драматический театр"; //варианты театров для посещения
                th[1] = "Эрмитажный театр";
                th[2] = "Михайловский театр";
                mus[0] = "Русский музей"; //варианты музеев для посещения
                mus[1] = "Зоологический музей";
                mus[2] = "Кунсткамера";
                price_th[0] = 1000; //цены в театр
                price_th[1] = 2000;
                price_th[2] = 500;
                price_mus[0] = 1500; //цены в музей
                price_mus[1] = 1000;
                price_mus[2] = 500;

            }

            float time_for_th = 2; //продолжительность пребывания в театре (2 часа)
            float time_for_mus = 2; //продолжительность пребывания в музее (1 час)



            //ввод количества часов, выделяемых на прогулку

            cout << "Введите сколько времени вы готовы выделить на прогулку (в часах): " << '\n';
            cout << "Допустимое время (в часах) от 0.04 до 12 " << '\n';

           
            string planvrpotrstr;
            //проверка корректности ввода
            cin >> planvrpotrstr;
            planvrpotr = checknumberfloat2(planvrpotrstr, 0.04, 12);




            //ввод количества человек, участвующих в прогулке
            string kolchelgostr;

            cout << "Сколько человек участвует в прогулке" << '\n';
            cout << "Допустимое количество человек от 1 до 5" << '\n';

            //проверка ввода количества человек
            cin >> kolchelgostr;
            kolchelgo = checknumberint2(kolchelgostr, 1, 5);

            museum[0] = museums(data, planvrpotr, kolchelgo);


            //выбор улиц для прогулки
            cout << "____________________________" << '\n';
            cout << "Самые интересные улицы для прогулки:" << '\n';
            for (int i = 0; i < 8; i++)
            {
                cout << i << "-" << ul[i] << '\n';
            }
            cout << "____________________________" << '\n';



            cout << "Введите номера улиц, которые вы хотите посетить (в порядке приоритетности)" << '\n';
            cout << "Для завершения ввода введите -1" << '\n';


            prvr = street[0];
            bool pervoevhozhd = false;
            string nomerulitsstr;

            nomerulits = -2;

            while (nomerulits != -1)
            {
                check = false; //для проверки на повторяемость улиц


                //проверка ввода данных (улиц)
                cin >> nomerulitsstr;
                nomerulits = checknumberint2(nomerulitsstr, -1, 7);



                if (pervoevhozhd == true)
                {
                    if (nomerulits != -1)
                    {
                        for (int i = 0; i < street.size(); i++)
                        {
                            if (ul[nomerulits] == street[i].get_nazv())
                            {
                                break;
                            }
                            else if (i == (street.size() - 1))
                            {
                                check = true;
                            }
                        }

                        while (check == false)
                        {
                            cout << "Вы уже выбирали " << ul[nomerulits] << '\n';
                            cout << "Выберите другую улицу или завершите ввод. Для завершения ввода нажмите -1." <<'\n';


                            cin >> nomerulitsstr;
                            nomerulits = checknumberint2(nomerulitsstr, -1, 7);

                            if (nomerulits == -1) { check = true; }
                            else
                            {
                                for (int i = 0; i < street.size(); i++)
                                {
                                    if (ul[nomerulits] == street[i].get_nazv())
                                    {
                                        break;
                                    }
                                    else if (i == (street.size() - 1))
                                    {
                                        check = true;
                                    }
                                }
                            }

                        }
                    }
                }
                if (nomerulits != -1)
                {
                    prvr = street[0]; //для обнуления переменной, в которой хранится дублирующее время обнуляется весь объект
                    prvr.set_dublir_totaltime(vremprog_ul[nomerulits]);


                    if (street[0] >= prvr)
                    {

                        if (pervoevhozhd == false)
                        {
                            street[0] = streets(ul[nomerulits], distance_ul[nomerulits], vremprog_ul[nomerulits]);
                            pervoevhozhd = true;
                        }
                        else
                        {
                            street.push_back(streets(ul[nomerulits], distance_ul[nomerulits], vremprog_ul[nomerulits]));
                        }
                    }
                    else
                    {
                        cout << "____________________________" << '\n';
                        cout << "Времени на посещение " << ul[nomerulits] << " нет" << '\n';

                    }
                }

            }

            cout << "____________________________" << '\n';
            cout << "Улицы, которые вы сможете посетить" << '\n';

            for (auto& i : street)
            {
                cout << i.get_nazv() << '\n';
            }
            cout << "____________________________" << '\n';




            //предложение посетить театр

            prvr = theatre;
            prvr.set_dublir_totaltime(time_for_th);

            if (theatre >= prvr)
            {
	            int check_for_theatre;
	            string check_for_theatre_str;
	            cout << "____________________________" << '\n';
                cout << "Хотите ли вы посетить театр?" << '\n';
                cout << "Если хотите - введите 1, если нет - введите 0" << '\n';
                cout << "____________________________" << '\n';

                //проверка ввода данных для посещения театра
                cin >> check_for_theatre_str;
                check_for_theatre = checknumberint2(check_for_theatre_str, 0, 1);


                //выбор театра для посещения


	            if (check_for_theatre == 1)
                {
	                int nomertheatre;
	                string nomertheatrestr;
	                cout << "____________________________" << '\n';
                    cout << "Выберите театр для посещения" << '\n';
                    cout << "Для этого введите число, которое соответствует выбранному вами театру" << '\n';
                    for (int i = 0; i < 3; i++)
                    {
                        cout << i << "-" << th[i] << ", стоимость билета: " << price_th[i] << " рублей" << '\n';
                    }
                    cout << "____________________________" << '\n';


                    //проверка ввода данных при выборе театра
                    cin >> nomertheatrestr;
                    nomertheatre = checknumberint2(nomertheatrestr, 0, 2);



                    theatre = theatres(th[nomertheatre], time_for_th);
                    theatre.set_price(price_th[nomertheatre]); //сохранение цены билета в театр в производном классе (перегрузка функции set_price())
                }
            }
            else
            {
                cout << "Театр не предлагается для посещения, так как у вас не хватит времени посетить его" << '\n';
            }


            //предложение посетить музей
            prvr = museum[0];
            prvr.set_dublir_totaltime(time_for_mus);

            if (museum[0] >= prvr)
            {
	            int check_for_museum;
	            string check_for_museum_str;
	            cout << "____________________________" << '\n';
                cout << "Хотите ли вы посетить музей?" << '\n';
                cout << "Если хотите - введите 1, если нет - введите 0" << '\n';
                cout << "____________________________" << '\n';

                //проверка ввода данных для посещения музея

                cin >> check_for_museum_str;
                check_for_museum = checknumberint2(check_for_museum_str, 0, 1);

                //выбор музея для посещения
                if (check_for_museum == 1)
                {
	                int nomermuseum;
	                cout << "____________________________" << '\n';
                    cout << "Выберите музей для посещения" << '\n';
                    cout << "Для этого введите число, которое соответствует выбранному вами музею" << '\n';
                    for (int i = 0; i < 3; i++)
                    {
                        cout << i << "-" << mus[i] << ", стоимость билета: " << price_mus[i] << " рублей" << '\n';
                    }
                    cout << "____________________________" << '\n';

                    //проверка ввода данных при выборе музея
                    string nomermuseumstr;
                    cin >> nomermuseumstr;
                    nomermuseum = checknumberint2(nomermuseumstr, 0, 2);

                    museum[0] = museums(mus[nomermuseum], time_for_mus);
                    museum[0].set_price(price_mus[nomermuseum]); //сохранение цены билета в музей в производном классе (перегрузка функции set_price())
                }
            }
            else
            {
                cout << "Музей не предлагается для посещения, так как у вас не хватит времени посетить его" << '\n';
            }



            //предложение воспользоваться транспортом при перемещении по городу

            cout << "____________________________" << '\n';
            cout << "Планируете ли вы использовать транспорт при передвижении по городу?" << '\n';
            cout << "Если да, введите 1. Если нет, введите 0" << '\n';
            cout << "____________________________" << '\n';

            string check_for_transport_str;

            //проверка ввода данных
            cin >> check_for_transport_str;
            check_for_transport = checknumberint2(check_for_transport_str, 0, 1);

            //выбор транспорта для перемещения
            if (check_for_transport == 1)
            {
	            int transport;
	            cout << "____________________________" << '\n';
                cout << "Каким транспортом вы хотите воспользоваться?" << '\n';
                cout << "Если такси (быстрее, но дороже) - 500 рублей на всех, введите 1" << '\n';
                cout << "Если общественный транспорт (медленнее, но дешевле) - 50 рублей за человека, введите 2" << '\n';
                cout << "____________________________" << '\n';


                //проверка ввода данных при выборе транспорта
                string transportstr;
                cin >> transportstr;
                transport = checknumberint2(transportstr, 1, 2);


                street[0].set_transport(transport);

            }



            //выбор места еды

            cout << "____________________________" << '\n';
            cout << "Где вы планируете есть?" << '\n';
            cout << "Если в ресторане (1500 руб. за человека), введите 1. Если фастфуд (500 руб. за человека), введите 2" << '\n';
            cout << "____________________________" << '\n';



            //проверка ввода данных при выборе места еды
            string type_eda_str;
            cin >> type_eda_str;
            type_eda = checknumberint2(type_eda_str, 1, 2);


            street[0].set_food(type_eda);


            //предложение узнать информацию о каждом объекте прогулки
            cout << "____________________________" << '\n';
            cout << "Хотите ли вы узнать информацию о каждом объекте?" << '\n';
            cout << "Если да, нажмите 1. Если нет, нажмите 0" << '\n';
            cout << "____________________________" << '\n';
            string moreinformationstr;



            //проверка ввода данных
            cin >> moreinformationstr;
            moreinformation = checknumberint2(moreinformationstr, 0, 1);



            if (moreinformation == 1)
            {
                if (!street[0].get_nazv().empty()) //проверка на то была ли добалена хотя бы 1 улица
                {
                    cout << "Улицы, которые вы посетите: " << '\n';
                    for (auto& i : street)
                    {
	                    i.func(); //используется виртуальная функция (перегрузка функций)
                    }
                }

                if (!theatre.get_nazv().empty())
                {
                    cout << "____________________________" << '\n';
                    cout << "Театр, который вы посетите: " << '\n';
                    theatre.func();
                }

                if (!museum[0].get_nazv().empty())
                {
                    cout << "____________________________" << '\n';
                    cout << "Музей, который вы посетите: " << '\n';
                    museum[0].func(); //используется виртуальная функция (перегрузка функций)
                }

            }
            vichpm(street, museum, theatre); //вычисление суммы к оплате за прогулку (перегрузка функции, определяющей вычисляемый показатель)
            vichpm(street); //вычисление суммарного расстояния прогулки (перегрузка функции, определяющей вычисляемый показатель)
            street.clear(); //очистка вектора (улицы)

            vybor_menu = 3;
        }
        else if (vybor_menu == 2)
        {
            cout << "__________________________________________________________________________________________________________________________________" << '\n';
            cout << "Данная программа позволяет расчитать маршрут прогулки по городу с учётом потребностей пользователя." << '\n';
            cout << "В начале программы пользователь вводит дату и количество часов, которое он готов выделить для прогулки" << '\n';
            cout << "Затем пользователь вводит количество человек, участвующих в прогулке и выбирает улицы, которые хочет посетить." << '\n';
            cout << "Далее пользователю предлагается зайти в музей и театр." << '\n';
            cout << "Затем у пользователя уточняется хочет ли он воспользоваться транспортом для перемещения по городу. Если да, то каким." << '\n';
            cout << "Далее пользователю задаётся вопрос о том, где он хочет поесть." << '\n';
            cout << "Далее пользователю предлагается узнать информацию о всех объектах маршрута." << '\n';
            cout << "В итоге пользователю выводится сумма (в рублях), которую ему следует выделить для осуществления запланированной им прогулки по городу" << '\n';
            cout << "Также пользователю выводится суммарное расстояние (в км), которое он пройдёт по маршруту и время (в часах), которое он затратит на прогулку" << '\n';
            cout << "__________________________________________________________________________________________________________________________________" << '\n';
        }

        else
        {
            break;

        }

    }
}




