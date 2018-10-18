#pragma once

#include <iostream>
#include <string>
using namespace std;

class Product
{
private:
	int id;
	char* name;
	float price;
public:
	Product();
	Product(char*, float);
	Product(int, char*, float);
	~Product();
	void set_id(int);
	int get_id();
	void set_name(char*);
	char* get_name();
	void set_price(float);
	float get_price();
};