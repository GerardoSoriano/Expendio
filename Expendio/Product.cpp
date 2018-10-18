#include "Product.h"

Product::Product() {
	this->id = NULL;
	this->name = "";
	this->price = NULL;
}
Product::Product(char* _name, float _price) {
	this->id = NULL;
	this->name = _name;
	this->price = _price;
}
Product::Product(int _id, char* _name, float _price) {
	this->id = _id;
	this->name = _name;
	this->price = _price;
}
Product::~Product() {
	free(this->name);
	delete this->name;
}
void Product::set_id(int _id) {
	this->id = _id;
}
int Product::get_id() {
	return this->id;
}
void Product::set_name(char* _name) {
	this->name = _name;
}
char* Product::get_name() {
	return this->name;
}
void Product::set_price(float _price){
	this->price = _price;
}
float Product::get_price(){
	return this->price;
}
