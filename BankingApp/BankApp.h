#pragma once
#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

class database
{
	int accno, ssno;
	char name[25];
	long long int phone;
	float totalbal;


public:
	void accept();
	void acceptedit();
	void display();
	char* getname();
	long long int getnumber();
	int getaccno();
	int getssno();
	void edit_rec();
	void delete_rec();
};