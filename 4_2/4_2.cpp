﻿#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class address
{
private:
	string city​_name;
	string street_name;
	int house_number = -999;
	int apartment_number = -999;
public:
	address()
	{
		city​_name;
		street_name;
		house_number = -999;
		apartment_number = -999;
	}
	address(string City_name, string Street_name, int house_num_value, int flat_num_value)
	{
		this->city​_name = City_name;
		this->street_name = Street_name;
		this->house_number = house_num_value;
		this->apartment_number = flat_num_value;
	}

	string print_address()
	{

		return this->city​_name + ", " + this->street_name + ", " + to_string(this->house_number) + ", " + to_string(this->apartment_number);

	}
	string name_city()
	{
		return city​_name;
	}

};
int main()
{
	setlocale(LC_ALL, "Rus");

	int number_of_addresses = -999;

	ifstream fin;
	ofstream out;

	fin.open("in.txt");
	if (fin.is_open())
	{

		string city;
		string street;
		int house_num = -999;
		int apartment_number = -999;
		bool swapped = false;

		fin >> number_of_addresses;

		address* arr = new address[number_of_addresses];

		out.open("out.txt");
		if (out.is_open())
		{
			out << number_of_addresses << endl;
			for (int i = 0; i < number_of_addresses; i++)
			{
				fin >> city;
				fin >> street;
				fin >> house_num;
				fin >> apartment_number;
				arr[i] = address(city, street, house_num, apartment_number);
			}

			for (int i = 0; i < number_of_addresses; i++)
			{
				for (int j = 0; j < number_of_addresses - 1; j++)
				{
					if (arr[j].name_city() > arr[j + 1].name_city())
					{

						swap(arr[j], arr[j + 1]);
					}
				}
			}
			for (int i = 0; i < number_of_addresses; i++)
			{
				out << arr[i].print_address() << endl;
			}
		}
		else
		{
			cout << "Не удалось открыть файл" << endl;
			return -1;
		}
		fin.close();
		out.close();
		delete[] arr;
	}
	else
	{
		cout << "Не удалось открыть файл" << endl;
		return -1;
	}

	return 0;
}