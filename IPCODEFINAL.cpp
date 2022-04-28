#include <iostream>
#include <string.h>
#include <fstream>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

void menu();
void admin_menu();
void add();
void list();
void list_p();
void edit();
void remove();
void remove_p();
void search();
void search_p();
void customer_menu();
void purchase();
void cart();
void thanks();
void payment();
float recipt();
void updater();
void temp_database();
void manage_records();

void login()
{
    int a = 0, i = 0;
    char uname[10], c = ' ';
    char pword[10], code[10];
    char user[10] = "a";
    char pass[10] = "a";
    do
    {
        system("cls");
        cout << "\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%";
        cout << "\n\n\t\t[$]\t\t\t<<<<<<<<<<<<<<<<<<<<<<<<<  ADMIN LOGIN FORM  >>>>>>>>>>>>>>>>>>>>>>>>>>\t\t   [$]\n\n";
        cout << "\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";

        cout << " \n\n                 >      PLEASE ENTER YOUR USERNAME -> ";
        cin >> uname;
        cout << " \n\n                 >      PLEASE ENTER THE PASSWORD -> ";
        while (i < 10)
        {
            pword[i] = getch();
            c = pword[i];
            if (c == 13)
                break;
            else
                cout << "*";
            // cout<<"*");
            i++;
        }
        pword[i] = '\0';
        i = 0;
        if (strcmp(uname, user) == 0 && strcmp(pword, pass) == 0)
        {
            cout << "\n\n\n\n\n\t\t\t\t($)       LOGIN SUCCESSFUL. INITIATING THE SYSTEM ";
            break;
        }
        else
        {
            cout << "\n\n\n\t\t\t\t=>         INVALID USERNAME OR PASSWORD !!!!\n\n\t\t\t\t\t(*)  LOGIN IS UNSUCESSFUL";
            a++;
            if (a <= 2)
            {
                cout << "\n\n\n\t\t\t\tPress any key to re enter...";
            }
            getch();
        }
    } while (a <= 2);
    if (a > 2)
    {
        cout << "\n\n\t # Sorry you have entered the wrong username and password for three times!!!\n\n\t\t\t\t\tExiting ";
        exit(0);
    }
    system("cls");
}

int order_no = 1;
string name;
string address;
long long phone;

int id;
string item_name;
float price;
int quantity;
int quantity_t;
float total_price;

int main()
{
    remove("database_temp.txt");
    temp_database();
    int i = 0;

    time_t t;
    time(&t);
    string s = ctime(&t);
    system("cls");

    cout << "\t$#########################################################################################################$\n";
    cout << "\t$                                                                                                         $\n";
    cout << "\t$                             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                           $\n";
    cout << "\t$                               WELCOME TO CUSTOMER BILLING MANAGEMENT SYSTEM                             $\n";
    cout << "\t$                             ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~                           $\n";
    cout << "\t$                                                                                                         $\n";
    cout << "\t$                                               Dhanbad                                                   $\n";
    cout << "\t$                                                INDIA                                                    $\n";
    cout << "\t$                                     PHONE NUMBER : 180044442222                                         $\n";
    cout << "\t$                                                                                                         $\n";
    cout << "\t$     Date and Time : " << s;
    cout << "\t$                                                                                                         $\n";
    cout << "\t$#########################################################################################################$\n\n\n";
    cout << " \n\t#\t Press any key to continue : ";

    getch();
    system("cls");
    menu();
}
void admin_menu()
{
    static int count = 0;
    if (count == 0)
    {
        login();
        count++;
    }

    int i = 0;
    char customername;
    char choice;
    system("cls");
    while (1)
    {
        system("cls");
        cout << "\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
        cout << "\n\t\t\t\t   #####----------------->>>>  | ADMIN MENU |  <<<<-------------------##### \n\n";
        cout << "\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
        cout << "\n\t\t <..> Select the desired option from the menu : ";
        cout << "\n";
        cout << "\n\n================================================================";
        cout << "\n\n     <> \tEnter 1 ->> Add a new Item to database";
        cout << "\n================================================================";
        cout << "\n\n     <> \tEnter 2 ->> View all the items in databse";
        cout << "\n================================================================";
        cout << "\n\n     <> \tEnter 3 ->> Delete Item from database";
        cout << "\n================================================================";
        cout << "\n\n     <> \tEnter 4 ->> Search an item in database";
        cout << "\n================================================================";
        cout << "\n\n     <> \tEnter 5 ->> Update an item";
        cout << "\n================================================================";
        cout << "\n\n     <> \tEnter 6 ->> Go back to main menu";
        cout << "\n================================================================";
        cout << "\n\n     <> \tEnter 7 ->> Exit";
        cout << "\n================================================================";
        cout << "\n \n";
        cout << "\t <.>\t Choose one of the operations => ";
        choice = getche();
        choice = toupper(choice);
        switch (choice)
        {
        case '1':
            add();
            break;
        case '2':
            list();
            break;
        case '3':
            remove();
            break;
        case '4':
            search();
            break;
        case '5':
            edit();
            break;
        case '6':
            menu();
            break;
        case '7':
            thanks();
            exit(0);
            break;
        default:
            system("cls");
            cout << "\n\n\t\t#\t Incorrect Input\n\n\t\t#\t Press any key to continue";
            getch();
        }
    }
}
void add()
{
m:
    fstream data, data1;
    int id_temp, q, n, i, valid = 1;
    char test;
    string name;
    float p;
    char item[50], names[50];
    char tmp[5] = "_";

    system("cls");
    cout << "\n\n----------------------------------------------------\n";
    cout << "|\t(^)\tPlease Enter Item Details :         |";
    cout << "\n----------------------------------------------------\n\n\n";
    cout << "\t(:) Enter the ID of product - ";
    cin >> id_temp;
    data.open("database.txt", ios::in);
    data1.open("database_temp.txt", ios::in);

    if (!data)
    {
        system("cls");
        cout << "\n\n\n\t\t$\tPlease hold on while we set up our database !!!   ";
        data.open("database.txt", ios::app | ios::out);
        data1.open("database_temp.txt", ios::app | ios::out);
        data.close();
        data1.close();
    }

    else
    {
        data >> id >> name >> price >> quantity;
        data1 >> id >> name >> price >> quantity;
        while (!data.eof())
        {
            if (id_temp == id)
            {
                valid = 0;
            }
            data >> id >> name >> price >> quantity;
            data1 >> id >> name >> price >> quantity;
        }
        data.close();
        data1.close();
    }
    if (valid == 0)
    {
        cout << "\n\nSorry !!! This Id already exists please re-enter the ID . ";
        valid = 1;
        goto m;
    }
    cout << "\n--------------------------------------------\n\n";
    cout << "\t(:) Enter the item name : ";

    getchar();
    getline(cin, item_name);
    for (int i = 0; item_name[i] != '\0'; i++)
    {
        if (item_name[i] == ' ')
        {
            item_name[i] = '_';
            break;
        }
    }

    cout << "\n--------------------------------------------\n\n";
    cout << "\t(:) Enter the price of " << item_name << " : ";
    cin >> price;
    cout << "\n--------------------------------------------\n\n";
    cout << "\t(:) Enter the quantity of " << item_name << " : ";
    cin >> quantity;
    cout << "\n--------------------------------------------\n\n";

    if (valid == 0)
    {
        goto m;
    }
    else
    {
        data.open("database.txt", ios::app | ios::out);
        data << "\t" << id_temp << "\t\t" << item_name << "\t\t\t\t\t" << price << "\t\t\t" << quantity << "\n";
        data.close();
        data1.open("database_temp.txt", ios::app | ios::out);
        data1 << "\t" << id_temp << "\t\t" << item_name << "\t\t\t\t\t" << price << "\t\t\t" << quantity << "\n";
        data1.close();
    }
    cout << "\t(+) Item Successfully Added \n\n";

    cout << "\n\t@\tPress esc key to exit or any other key to add another product:";
    test = getche();
    if (test == 27)
        admin_menu();
    else
        add();
}

void edit()
{

    fstream data, data1;
    string pkey;
    int token = 0;
    string name;
m:
    getchar();
    system("cls");
    cout << "\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    cout << "\n\t\t\t\t\t\t\tMODIFY RECORD FROM THE DATABASE\n\n";
    cout << "\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    cout << "\n\n\t(+)\t Enter the Product name :> ";
    getline(cin, pkey);
    for (int i = 0; pkey[i] != '\0'; i++)
    {
        if (pkey[i] == ' ')
        {
            pkey[i] = '_';
            break;
        }
    }
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n\t\t(+)\t File doesn't exist !!! ";
    }
    else
    {
        data1.open("temp1.txt", ios::app | ios::out);
        data >> id >> name >> price >> quantity;

        while (!data.eof())
        {
            if (pkey == name)
            {

                system("cls");
                cout << "\n\n\t\t\t---------------->\tPRODUCT FOUND\t<---------------->\n";
                cout << "\n\t\t(.)\tEnter Updated Item Details => ";
                cout << "\n\n\t\t===================================================\n\n";
                cout << "\t\t(1)\tEnter the new ID of product => ";
                cin >> id;

                cout << "\n\t\t===================================================\n\n";
                cout << "\t\t(2)\tEnter the new item name => ";

                getchar();
                getline(cin, name);

                for (int i = 0; name[i] != '\0'; i++)
                {
                    if (name[i] == ' ')
                    {
                        name[i] = '_';
                        break;
                    }
                }

                cout << "\n\t\t===================================================\n\n";
                cout << "\t\t(3)\tEnter the revised price of " << name << " => ";
                cin >> price;
                cout << "\n\t\t===================================================\n\n";
                cout << "\t\t(4)\tEnter the latest quantity of " << name << " => ";
                cin >> quantity;
                cout << "\n\t\t===================================================\n\n";
                data1 << "\t" << id << "\t\t" << name << "\t\t\t\t\t" << price << "\t\t\t" << quantity << "\n";

                token = 1;
            }

            else
            {
                data1 << "\t" << id << "\t\t" << name << "\t\t\t\t\t" << price << "\t\t\t" << quantity << "\n";
            }
            data >> id >> name >> price >> quantity;
        }

        data.close();
        data1.close();
        remove("database.txt");
        rename("temp1.txt", "database.txt");
        temp_database();
        if (token == 0)
        {
            cout << "\n\n Record not found sorry!";
            cout << "\n\nPress any key to goto previous menu -> ";
            getch();
        }
    }
}

void menu()
{
    int choice;
    while (1)
    {
        system("cls");
        cout << "\t$#########################################################################################################$\n";
        cout << "\t$                                                                                                         $\n";
        cout << "\t$\t\t------------------------------------( MENU )------------------------------------          $\n";
        cout << "\t$                                                                                                         $\n";
        cout << "\t$\t # Choose the desired option :-                                                                   $\n";
        cout << "\t$                                                                                                         $\n";
        cout << "\t$                   \t\t1. ADMINISTRATOR                                                          $\n";
        cout << "\t$                                                                                                         $\n";
        cout << "\t$                   \t\t2. CUSTOMER                                                               $\n";
        cout << "\t$                                                                                                         $\n";
        cout << "\t$                   \t\t3. EXIT                                                                   $\n";
        cout << "\t$                                                                                                         $\n";
        cout << "\t$                                                                                                         $\n";
        cout << "\t$#########################################################################################################$\n";
        cout << "\n\n\tChoice :- ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            admin_menu();
            break;
        case 2:
            customer_menu();
            break;
        case 3:
            thanks();
            exit(0);
            break;
        default:
            system("cls");
            cout << "\n\n\n\t\t\t#\t\tIncorrect Input ";
        }
    }
}

void remove()
{

    system("cls");
    fstream data, data1;
    string pkey;
    int token = 0;
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    cout << "\n\n\t\t\t\t\t REMOVE PRODUCT FROM THE DATABASE\n\n\n";
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    getchar();
    cout << "\n\n\t(.'.)\t Enter Product name -> ";
    getline(cin, pkey);
    for (int i = 0; pkey[i] != '\0'; i++)
    {
        if (pkey[i] == ' ')
        {
            pkey[i] = '_';
            break;
        }
    }
    data.open("database.txt", ios ::in);
    if (!data)
        cout << "File doesnt exist";
    else
    {
        data1.open("temp.txt", ios::app | ios::out);
        data >> id >> item_name >> price >> quantity;
        while (!data.eof())
        {
            if (pkey == item_name)
            {
                cout << "\n\n\t(.'.)\t  Product deleted succesfully ";
                cout << "\n\n\t\t\tPress any key to goto previous menu => ";
                getch();
                token = 1;
            }
            else
            {
                data1 << "\t" << id << "\t\t" << item_name << "\t\t\t\t\t" << price << "\t\t\t" << quantity << "\n";
            }
            data >> id >> item_name >> price >> quantity;
        }

        data.close();
        data1.close();
        remove("database.txt");
        rename("temp.txt", "database.txt");
        temp_database();

        if (token == 0)
        {
            cout << "\n\n\t#\tProduct not Found\n\n";
            cout << "\t*\tPlease enter the Product_name carefully -> ";
            getchar();
        }
    }
}

void list()
{

    system("cls");
    fstream data;
    data.open("database.txt", ios::in);
    cout << "\n\n-------------------------------------------------------------------------------------------------------------\n\n";
    cout << "\tID\t\tProduct_Name\t\t\t\tPrice\t\t\tQuantity";
    cout << "\n\n-------------------------------------------------------------------------------------------------------------\n\n";
    data >> id >> item_name >> price >> quantity;
    while (!data.eof())
    {
        cout << "\t" << id << "\t\t" << item_name << "\t\t\t\t\t" << price << "\t\t\t" << quantity << "\n";
        data >> id >> item_name >> price >> quantity;
    }
    data.close();
    cout << "\n\n\t(#)\tPress any key to goto previous menu => ";
    getch();
}

void search()
{
car:
    char c;
    system("cls");
    fstream data;
    string pkey;
    int token = 0;
    cout << "\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    cout << "\n\t\t\t\t\t\t\tSEARCH PRODUCT FROM THE DATABASE\n\n";
    cout << "\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    getchar();
    cout << "\n\n\t\t\t\t(?)\t Enter Product name => ";
    getline(cin, pkey);
    for (int i = 0; pkey[i] != '\0'; i++)
    {
        if (pkey[i] == ' ')
        {
            pkey[i] = '_';
            break;
        }
    }
    data.open("database.txt", ios ::in);
    if (!data)
    {
        cout << "\n\n\t(?)\t File doesn't exist";
    }
    else
    {
        data >> id >> item_name >> price >> quantity;

        while (!data.eof())
        {
            if (pkey == item_name)
            {
                cout << "\n\n\t\t\t\t(?)\t  Product found succesfully\n";
                cout << "\n\n-------------------------------------------------------------------------------------------------------------\n\n";
                cout << "\tID\t\tProduct_Name\t\t\t\tPrice\t\t\tQuantity";
                cout << "\n\n-------------------------------------------------------------------------------------------------------------\n\n";
                cout << "\t" << id << "\t\t" << item_name << "\t\t\t\t\t" << price << "\t\t\t" << quantity << "\n";
                // getchar();
                // admin_menu();
                token = 1;
            }

            data >> id >> item_name >> price >> quantity;
        }
        data.close();

        if (token == 0)
        {
            cout << "\n\n\t#\tProduct not Found\n\n";
            cout << "\t*\tDo you want to search again ? (Y/N) ";
            c = getchar();
            if (c == 'y' || c == 'Y')
            {

                goto car;
            }
        }
        else
        {
            Sleep(5000);
            cout << "\n\n\t\t(:)\tGoing back to previous menu ";
        }
    }
}

void customer_menu()
{
    int i = 0;
    char choice;
    system("cls");
    while (1)
    {
        system("cls");
        cout << "\t\t";
        for (i = 0; i < 100; i++)
            cout << "*";
        cout << "\n";
        cout << "\n\t\t\t   #####----------------->>>>  |*|  CUSTOMER MENU  |*|  <<<<-------------------##### \n\n";
        cout << "\t\t";
        for (i = 0; i < 100; i++)
            cout << "*";
        cout << "\n";
        cout << "\n\n\n\t\t <> Select the desired option from the menu : ";
        cout << "\n\n";
        cout << "\n===========================================";
        cout << " \n Enter 1 ->> ADD ITEMS TO CART ";
        cout << "\n===========================================";
        cout << " \n Enter 2 ->> PURCHASE ITEMS ";
        cout << "\n===========================================";
        cout << " \n Enter 3 ->> Exit";
        cout << "\n===========================================";
        cout << "\n \n";
        cout << "\nSELECT AN OPTION PLEASE => ";
        choice = getche();
        choice = toupper(choice);
        switch (choice)
        {
        case '1':
            cart();
            break;
        case '2':
            purchase();
            break;
        case '3':
            system("cls");
            thanks();
            exit(0);
            break;
        default:
            system("cls");
            cout << "Incorrect Input";
            cout << "\n Press any key to continue";
            getch();
        }
    }
}

void search_p()
{

    char test;
    system("cls");
    cout << "\t$%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%$\n";
    cout << "\t$                                                                                                         $\n";
    cout << "\t$                                   ----->      PRODUCT LIST      <-----                                  $\n";
    cout << "\t$                                                                                                         $\n";
    cout << "\t$%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%$\n";
    cout << "\n\n";
    fstream data, data1, data2;
    string pkey;
    int token = 0;
    cout << "\n\t ";
    int tick = 0;
    if (tick == 0)
    {
        getchar();
        tick = 1;
    }

    cout << "\n\n--------------------------------------------\n";
    cout << "\n\t Enter Product name -> ";

    getline(cin, pkey);
    for (int i = 0; pkey[i] != '\0'; i++)
    {
        if (pkey[i] == ' ')
        {
            pkey[i] = '_';
            break;
        }
    }
    cout << "\n\n--------------------------------------------\n";

    cout << "\n\t How many " << pkey << " do you want ? ";

    cin >> quantity_t;
    cout << "\n\n--------------------------------------------\n";

    data.open("database_temp.txt", ios::in);
    if (!data)
        cout << "File doesnt exist";

    else
    {
        data1.open("recipt.txt", ios::app | ios::out);
        data2.open("database_updated.txt", ios::app | ios::out);
        data >> id >> item_name >> price >> quantity;

        while (!data.eof())
        {
            if (pkey == item_name)
            {
                if (quantity_t <= quantity)
                {
                    cout << "\n\n\t Product available \n";
                    total_price = quantity_t * price;
                    data1 << "\t" << id << "\t\t" << item_name << "\t\t\t\t\t" << price << "\t\t\t" << quantity_t << "\t\t\t" << total_price << "\n";
                    data2 << "\t" << id << "\t\t" << item_name << "\t\t\t\t\t" << price << "\t\t\t" << quantity - quantity_t << "\n";
                    cout << "\n\n\t PRODUCT ADDED TO CART \n";
                    Sleep(2000);
                    token = 1;
                }
                else
                {
                    cout << "\n\n\tWe are really sorry but we don't have that much stock for " << pkey << endl;
                    goto bird;
                }
            }
            else
            {
            bird:
                data2 << "\t" << id << "\t\t" << item_name << "\t\t\t\t\t" << price << "\t\t\t" << quantity << "\n";
            }

            data >> id >> item_name >> price >> quantity;
        }
        data.close();
        data1.close();
        data2.close();

        remove("database_temp.txt");
        rename("database_updated.txt", "database_temp.txt");

        if (token == 0)
        {
            cout << "\n\n\t(#)\tProduct not in Stock\n\n\tINCONVINIENCE REGRETTED\n\n";
            cout << "\n Press esc key to exit or any other key to add another product to cart -> ";
            test = getche();
            if (test == 27)
                customer_menu();
        }
        else
        {
            cout << "\n Press esc key to exit or any other key to add another product to cart -> ";
            test = getche();
            if (test == 27)
                customer_menu();
        }
    }
}

void remove_p()
{
    int val;
    system("cls");
    cout << "Here is your cart -> ";
    list_p();
    fstream data, data1, data2;
    string pkey;
    int token = 0;
    cout << "\n\n\t Remove product from cart ";
    getchar();
    cout << "\n\n\t Product name : => ";
    getline(cin, pkey);
    for (int i = 0; pkey[i] != '\0'; i++)
    {
        if (pkey[i] == ' ')
        {
            pkey[i] = '_';
            break;
        }
    }
    cout << "\n\n\t Enter the quantity you purchased => ";
    cin >> val;
    data.open("recipt.txt", ios ::in);
    if (!data)
        cout << "File doesnt exist";
    else
    {
        data1.open("temp2.txt", ios::app | ios::out);
        data2.open("database_temp.txt", ios::app | ios::out);
        data >> id >> item_name >> price >> quantity_t >> total_price;

        while (!data.eof())
        {
            if (pkey == item_name)
            {
                cout << "\n\n\t Product removed from cart succesfully";
                cout << "\n\n\tPress any key to goto previous menu -> ";
                getch();

                token = 1;
            }
            else
            {
                data1 << "\t" << id << "\t\t" << item_name << "\t\t\t\t\t" << price << "\t\t\t" << quantity_t << "\t\t\t" << total_price << "\n";
            }
            data >> id >> item_name >> price >> quantity_t >> total_price;
        }
        data.close();
        data1.close();
        data2.close();

        remove("recipt.txt");
        rename("temp2.txt", "recipt.txt");

        if (token == 0)
        {
            cout << "\n\n\t#\tYour cart doesn't have " << pkey << "\n\n";
            cout << "\t*\tPlease enter the Product_name carefully -> ";
            getchar();
        }
    }
}

void cart()
{
    string name;

    system("cls");
    cout << "\t$%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%$\n";
    cout << "\t$                                                                                                         $\n";
    cout << "\t$                           ----->      Item Purchase Menu      <-----                                    $\n";
    cout << "\t$                                                                                                         $\n";
    cout << "\t$%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%$\n";
    cout << "\n\n";
    while (1)
    {
        search_p();
    }
}

void purchase()
{

    char choice;
    system("cls");
    cout << "\t$%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%$\n";
    cout << "\t$                                                                                                         $\n";
    cout << "\t$                           ----->      Item Purchase Menu      <-----                                    $\n";
    cout << "\t$                                                                                                         $\n";
    cout << "\t$%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%$\n";
    cout << "\n\n";

    while (1)
    {

        list_p();
        cout << "\n";
        cout << "\n\t\t <> Select the desired option from the menu : ";
        cout << "\n\n";
        cout << "\n===========================================";
        cout << " \n Enter 1 ->> REMOVE ITEMS FROM CART ";
        cout << "\n===========================================";
        cout << " \n Enter 2 ->> ADD ITEMS TO CART ";
        cout << "\n===========================================";
        cout << " \n Enter 3 ->> PROCEED TO PAYMENT ";
        cout << "\n===========================================";
        cout << " \n Enter 4 ->> CANCEL SHOPPING";
        cout << "\n===========================================";
        cout << "\n \n";
        cout << "\nSELECT AN OPTION PLEASE => ";

        choice = getche();
        choice = toupper(choice);
        switch (choice)
        {
        case '1':
            remove_p();
            break;
        case '2':
            cart();
            break;
        case '3':
            payment();
            break;
        case '4':
            system("cls");
            thanks();
            exit(0);
            break;
        default:
            system("cls");
            cout << "Incorrect Input";
            cout << "\n Press any key to continue";
            getch();
        }
    }
}

void payment()
{
    float cash;
    char test;

    while (1)
    {
    here:
        system("cls");

        float cost = recipt();

        cout << "\t\t\t\t\t\t\t\t--------------------------------------------------------";
        cout << "\n\t\t\t\t\t\t\t\t|\tTotal Price \t\t=> Rs " << cost << "\t\t       |";
        cout << "\n\t\t\t\t\t\t\t\t--------------------------------------------------------";
        cout << "\n\t\t\t\t\t\t\t\t|\tDiscount Percentage \t=> 2 %\t\t       |";
        cout << "\n\t\t\t\t\t\t\t\t--------------------------------------------------------";
        cost = float((float(98) / float(100)) * cost);
        cout << "\n\t\t\t\t\t\t\t\t|\tDiscounted Price \t=> Rs " << cost << "\t\t       |";
        cout << "\n\t\t\t\t\t\t\t\t--------------------------------------------------------";
        cout << "\n\n\t\t\t\t\t\t<.>\tPlease make the payment with cash \t=> Rs ";
        cin >> cash;
        if (cash < cost)
        {
            cout << "\n\n";
            cout << "$\tSorry Sir, but $" << cash << " is not sufficient for the payment !!!\n\n$\tYou neeed to pay more $" << cost - cash << endl;
            cout << "\n$\tPress escape to cancel the payment or any key to repay --> ";
            test = getche();
            if (test == 27)
            {
                thanks();
            }
            else
            {

                goto here;
            }
        }
        else
        {
            cout << "\n\n\t\t\t\t\t\t<.>\tMoney to return \t\t\t=> $" << cash - cost << endl;
            manage_records();
            cout << "\n\n\t\tTHANK YOU VERY MUCH FOR SHOPPING WITH US\n\n";
            cout << "\n\t\tHAVE A WONDERFULL DAY\n\n";
            remove("database.txt");
            // remove("recipt.txt");
            rename("database_temp.txt", "database.txt");
            temp_database();
            Sleep(5000);
            thanks();
        }
    }
}

float recipt()
{
    float cost = 0;
    system("cls");
    cout << "\t$%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%$\n";
    cout << "\t$                                                                                                         $\n";
    cout << "\t$                           ----->      PAYMENT GATEWAY cum RECIPT      <-----                            $\n";
    cout << "\t$                                                                                                         $\n";
    cout << "\t$%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%$\n";
    cout << "\n\n";
    fstream data;
    data.open("recipt.txt", ios::in);
    if (!data)
    {
        cout << "\n\t\t\t@\tYou haven't added products to cart yet\n\n";
        cout << "\t\t\t#\tGoing back to previous menu .\n\n\t\t\t$\tPLEASE HAVE PATIENCE";
        customer_menu();
    }
    cout << "\n";
    cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n";
    cout << "#\tID\t#\tProduct_Name\t\t#\tRate\t#\tQuantity\t#\tTotal_Price\t\t#";
    cout << "\n";
    cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    data >> id >> item_name >> price >> quantity_t >> total_price;
    while (!data.eof())
    {
        cout << "|\t" << id << "\t|\t" << item_name << "\t\t\t|\t" << price << "\t|\t" << quantity_t << "\t\t|\t\t" << total_price << "\t\t|\n";
        cout << "-------------------------------------------------------------------------------------------------------------------------\n";
        cout << "\n";

        cost += total_price;
        data >> id >> item_name >> price >> quantity_t >> total_price;
    }
    data.close();

    return cost;
}

void list_p()
{

    system("cls");
    cout << "\n\n\t\t\t\t\t\t@\tSHOPPING CART\n";

    float cost = 0;
    fstream data;
    data.open("recipt.txt", ios::in);
    if (!data)
    {
        cout << "\n\t\t\t@\tYou haven't added products to cart yet\n\n";
        cout << "\t\t\t#\tGoing back to previous menu .\n\n\t\t\t$\tPLEASE HAVE PATIENCE";
        customer_menu();
    }
    cout << "\n\n";
    cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n\n";
    cout << "#\tID\t#\tProduct_Name\t\t#\tRate\t#\tQuantity\t#\tTotal_Price\t\t#";
    cout << "\n";
    cout << "\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
    data >> id >> item_name >> price >> quantity_t >> total_price;
    while (!data.eof())
    {
        cout << "|\t" << id << "\t|\t" << item_name << "\t\t\t|\t" << price << "\t|\t" << quantity_t << "\t\t|\t\t" << total_price << "\t\t|";
        cout << "\n-------------------------------------------------------------------------------------------------------------------------\n";

        data >> id >> item_name >> price >> quantity_t >> total_price;
        cost += total_price;
    }
    data.close();
}

void temp_database()
{
    remove("database_temp.txt");
    fstream data, data1;
    data.open("database.txt", ios::in);
    if (!data)
    {
        cout << "\n\n\t\t(+)\t File doesn't exist !!! ";
    }
    else
    {
        data1.open("database_temp.txt", ios::app | ios::out);
        data >> id >> item_name >> price >> quantity;

        while (!data.eof())
        {
            data1 << "\t" << id << "\t\t" << item_name << "\t\t\t\t\t" << price << "\t\t\t" << quantity << "\n";
            data >> id >> item_name >> price >> quantity;
        }
        data.close();
        data1.close();
    }
}

void manage_records()
{
    fstream data;
    int tick = 0;

    int temp;
    char test;
    getchar();
    cout << "\n\n(!)\tPlease enter your name , Sir/Ma'am \t\t\t\t\t\t=> ";
    getline(cin, name);
    cout << "\n(!)\tMr./Ms. " << name << " Please enter your phone number for future assistance   => ";

    cin >> phone;
    getchar();
    cout << "\n(!)\tEnter your address \t\t\t\t\t\t\t\t=> ";
    getline(cin, address);
bus:
    // if (tick == 0)
    // {
    data.open("customer_record.txt", ios::in);
    // }
    // else
    // {
    //     data.open("customer_record.txt", ios::app | ios::out);
    // }

    if (!data)
    {
        system("cls");
        cout << "\n\n\n\t\t$\tPlease hold on while we set up our databsase !!!   ";
        data.open("customer_record.txt", ios::app | ios::out);
        data.close();
        tick = 1;

        goto bus;
    }

    else
    {
        data.close();
        data.open("customer_record.txt", ios::app | ios::out);

        time_t t;
        time(&t);
        string s = ctime(&t);

        data << s << "\n"
             << name << "\n"
             << phone << "\n"
             << address << "\n\n\n\n";

        data.close();
    }
}

void thanks()
{
    remove("recipt.txt");
    system("cls");
    cout << "\n\n\n\n";
    cout << "\t$%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%$\n";
    cout << "\t$                                                                                                         $\n";
    cout << "\t$       ###########     #         #          #          #         #    #        #      #   #              $\n";
    cout << "\t$            #          #         #        #   #        # #       #    #       #     #        #           $\n";
    cout << "\t$            #          #         #       #     #       #   #     #    #     #       #                    $\n";
    cout << "\t$            #          # # # # # #      # # # # #      #    #    #    #   #           #  #  #            $\n";
    cout << "\t$            #          #         #     #         #     #      #  #    #     #                 #          $\n";
    cout << "\t$            #          #         #    #           #    #       # #    #       #      #        #          $\n";
    cout << "\t$            #          #         #    #           #    #         #    #        #        #   #            $\n";
    cout << "\t$                                                                                                         $\n";
    cout << "\t$                                                                     CODED BY --->  ABHINAV PRABHAT      $\n";
    cout << "\t$                                                                                                         $\n";
    cout << "\t$%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%$\n";
    cout << "\n\n\n\n";

    exit(1);
}
