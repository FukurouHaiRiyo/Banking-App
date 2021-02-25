// BankingApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
#include <fstream>
#include "BankApp.h"
using namespace std;

void database::accept()
{
    cout << "\nEnter Account Name: ";
    cin >> accno;
    cin.get();
    cout << "Enter name: ";
    cin.get(name, 24);
    cin.get();
    cout << "Enter phone number: ";
    cin >> phone;
    cout << "Enter balance: ";
    cin >> totalbal;
    cout << "Enter Socia Security Number: ";
    cin >> ssno;
    cout << endl;
}

void database::acceptedit()
{
    cout << "\Enter name:";
    cin.get(name, 24);
    cin.get();
    cout << "Enter phone number: ";
    cin >> phone;
    cout << "Enter balance: ";
    cin >> totalbal;
    cout << endl;
}

void database::display()
{
    cout << "\nAccount Number: " << accno << endl;
    cout << "Name: " << name << endl;
    cout << "Phone: " << phone << endl;
    cout << "Current Balance: Lei    " << totalbal << endl;
    cout << "-------------------------------------------------\n";

}

char* database::getname()
{
    return name;
}

long long int database::getnumber()
{
    return phone;
}

int database::getaccno()
{
    return accno;
}

int database::getssno()
{
    return ssno;
}

void create_file()
{
    int n;
    database d1;

    cout << "\nEnter the number of customers:";
    cin >> n;
    ofstream file;
    file.open("record.DAT");

    for (int i = 0; i < n; ++i)
    {
        d1.accept();
        file.write((char*)&d1, sizeof(d1));
    }
    file.close();
}

void display_file()
{
    ifstream file;
    database d1;
    file.open("record.DAT");
    cout << "\nEntered details are:";

    while (file)
    {
        file.read((char*)&d1, sizeof(d1));
        if (file.eof())
            break;
        d1.display();
    }
    file.close();
}

void addnewrec()
{
    ofstream file;
    database d1;
    file.open("record.DAT", ios::app);
    cout << "\nEnter data to add a new record.";
    d1.accept();
    file.write((char*)&d1, sizeof(d1));
    file.close();
}

void searchonName()
{
    ifstream file;
    database d1;
    char name[25];
    bool flag = 0;
    cout << "\nEnter name to be searched: ";
    cin.get(name, 24);
    file.open("record.DAT", ios::in);
    while (file)
    {
        file.read((char*)&d1, sizeof(d1));
        if (file.eof() != 0)
            break;
        if (strcmp(d1.getname(), name) == 0)
        {
            cout << "\nData found";
            d1.display();
            flag = 1;
            break;
        }
    }

    file.close();

    if (flag == 0)
    {
        cout << "\Record not found";
    }
}

void searchonNumber()
{
    ifstream file;
    database d1;
    long long int phone;
    bool flag = 0;

    cout << "\nEnter number to be searched: ";
    cin >> phone;
    file.open("record.DAT", ios::in);

    while (file)
    {
        file.read((char*)&d1, sizeof(d1));

        if (file.eof() != 0)
            break;

        if (d1.getnumber() == phone)
        {
            cout << "\nData found";
            d1.display();
            flag = 1;
            break;
        }
    }

    file.close();
    if (flag == 0)
    {
        cout << "\nRecord not found";
    }
}

void SearchAccNumber()
{
    ifstream file;
    database d1;
    int accno;
    bool flag = 0;
    cout << "\nEnter account number to be searched:";
    cin >> accno;
    file.open("record.DAT", ios::in);

    while (file)
    {
        file.read((char*)&d1, sizeof(d1));
        if (file.eof() != 0)
            break;

        if (accno == d1.getaccno())
        {
            cout << "\nDataFound";
            d1.display();
            flag = 1;
            break;
        }
    }

    file.close();

    if (flag == 0)
        cout << "\nRecord not found";
}

void modifyonname()
{
    fstream file;
    database d1;
    char name[25];
    int ssno;
    bool flag = 0;

    cout << "\nEnter name to be searched:";
    cin.get(name, 24);

    file.open("record.DAT", ios::in | ios::out | ios::binary);

    while (file)
    {
        file.read((char*)&d1, sizeof(d1));

        if (file.eof() != 0)
            break;

        if (strcmp(d1.getname(), name) == 0)
        {
            cout << "\nAccount found";
            cout << "\nEnter your social security number:";
            cin >> ssno;

            if (ssno == d1.getssno())
            {
                cout << "\nEnter new details: --->>>";
                d1.acceptedit();
                file.seekp(sizeof(d1), ios::cur);
                file.write((char*)&d1, sizeof(d1));
                flag = 1;
                break;
            }
            else
                cout << "God is watching, don't cheat\n";
        }
    }

    file.close();

    if (flag == 0)
        cout << "\nRecord not found";
}

void modifyonaccno()
{
    fstream file;
    database d1;
    int accno;
    int ssno;
    bool flag = 0;
    cout << "\nEnter account number to be searched:";
    cin >> accno;
    file.open("record.DAT", ios::in | ios::out | ios::binary);

    while (file)
    {
        file.read((char*)&d1, sizeof(d1));
        if (file.eof() != 0)
            break;

        if (d1.getaccno() == accno)
        {
            cout << "\nAccount found";
            cout << "\nEnter your social security number:";
            cin >> ssno;
            if (ssno == d1.getssno())
            {
                cout << "\nEnetr new details:--->>>";
                d1.acceptedit();
                file.seekp(sizeof(d1), ios::cur);
                file.write((char*)&d1, sizeof(d1));
                flag = 1;
                break;
            }
            else
                cout << "\nDon't cheat\n";
        }
    }

    file.close();
    if (flag == 0)
        cout << "\nRecord not found";
}

int main()
{
    int ch, password, pass;
    int i = 0;
    password = 98765;

    do
    {
        cout << "\nAdmin enter your password:";
        cin >> pass;

        if (password == pass)
        {
            cout << "\n*****WELCOME ADMINISTRATOR*****\n";

            cout << "1.Create database\n";
            cout << "2.Add new record to database\n";
            cout << "3.Search Customer by name\n";
            cout << "4.Search Customer by Phone number\n";
            cout << "5.Search Customer by Accoutn name\n";
            cout << "6.Modify customer data by name\n";
            cout << "7.Modify customer data account number\n";
            cout << "8.View database";
            cout << "\n\nEneter your choice:";

            cin >> ch;

            switch (ch)
            {
            case 1:
                create_file();
                break;

            case 2:
                addnewrec();
                break;

            case 3:
                searchonName();
                break;

            case 4:
                searchonNumber();
                break;

            case 5:
                SearchAccNumber();
                break;

            case 6:
                modifyonname();
                break;

            case 7:
                modifyonaccno();
                break;

            case 8:
                display_file();
                break;
            }
        }

        else
        {
            cout << "\nYou are not the admin";
            i++;
            cout << "\n" << 5 - i << " tries left";
        }
    } while (ch > 0 && ch < 9);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
