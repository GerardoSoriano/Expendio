#include <iostream>
#include <locale.h>
#include "Product.h"
using namespace std;

struct Element
{
	Element *before, *after;
	Product *product;
}*index = nullptr, *aux = nullptr, *helper = nullptr;

void doAdminOption();
void doBuyOption();
void doPayOption();
void doSeeOption();

void main() {
	setlocale(LC_ALL, "");
	bool exit = false;
	do
	{
		int opt = 0;
		cout << "Bienvenido al expendio, ¿qué deseas hacer?" << endl;
		cout << "1. Administrar elementos." << endl;
		cout << "2. Comprar productos." << endl;
		cout << "3. Introducir dinero." << endl;
		cout << "4. Ver los productos adquiridos." << endl;
		cout << "5. Salir." << endl;
		cin >> opt;
		system("cls");
		try
		{
			if (cin.fail())
				throw "No has introducido un número.";
			if (opt <= 0 || opt >= 6)
				throw "Introduce una opción que se encuentre en el menú.";

			switch (opt)
			{
			case 1:
				doAdminOption();
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				cout << "Hasta luego." << endl;
				exit = true;
				system("pause");
				break;
			}
		}
		catch (const char* error)
		{
			cout << error << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("pause");
		}
		system("cls");
	} while (!exit);
}

void doAdminOption()
{
	bool exit = false;
	string _name;
	float _price;
	do
	{
		int opt = 0;
		cout << "Hola, te encuentras en el administrador de productos del expendio." << endl;
		cout << "Por favor, captura el número de la acción que deseas realizar." << endl;
		cout << "1. Agregar producto nuevo." << endl;
		cout << "2. Editar producto existente." << endl;
		cout << "3. Eliminar algún producto de la lista." << endl;
		cout << "4. Volver al menú anterior." << endl;
		cin >> opt;
		system("cls");
		try
		{
			if (cin.fail())
				throw "No has introducido un número.";
			if (opt <= 0 || opt >= 5)
				throw "Introduce una opción que se encuentre en el menú.";

			switch (opt)
			{
			case 1:
				cout << "Introduce el nombre el nuevo producto:" << endl;
				cin.ignore();
				getline(cin, _name);
				set_price:
				cout << "Introduce un precio para el producto " << _name << "." << endl;
				cin >> _price;
				try
				{
					if (cin.fail())
						throw "Por favor introduce un número.";

					if(index == nullptr)
					{
						index = aux = helper = new Element;
						index->product = new Product(0, _strdup(_name.c_str()), _price);
						index->before = index->after = nullptr;
					}
					else
					{
						aux = new Element;
						aux->product = new Product((helper->product->get_id() + 1), _strdup(_name.c_str()), _price);
						aux->before = helper;
						aux->after = nullptr;
						helper->after = aux;
						helper = aux;
					}
				}
				catch (const char* error)
				{
					cout << error << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					goto set_price;
				}
				break;
			case 2:
				if (index == nullptr)
				{
					cout << "Lo sentimos, no hay ningún producto en registrado" << endl;
					system("pause");
				}
				else
				{
					bool continue_printing = true;
					int id_to_edit = 0;
					cout << "La lista de productos es la siguiente:" << endl;
					aux = index;
					do
					{
						if (aux->after == nullptr)
							continue_printing = false;

						cout << "#" << aux->product->get_id() << "\t" << aux->product->get_name() << "\t$" << aux->product->get_price() << endl;
						aux = aux->after;
					}
					while (continue_printing);
					cout << "Introduce el ID del producto que deseas editar:" << endl;
					cin >> id_to_edit;

					if(cin.fail())
						throw "No has introducido un número.";
					if (id_to_edit <= 0 || id_to_edit > helper->product->get_id())
						throw "El id que introduciste no se encuentra en la lista.";

					system("pause");
				}
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				cout << "Hasta luego." << endl;
				exit = true;
				system("pause");
				break;
			}
		}
		catch (const char* error)
		{
			cout << error << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("pause");
		}
		system("cls");
	} while (!exit);
}
