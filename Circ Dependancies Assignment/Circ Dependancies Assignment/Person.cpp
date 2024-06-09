#include <iostream>
#include "Person.h"
using namespace std;

Person::Person()		// default constructor
{
	name = "Alex Larochette";
	pet = nullptr;

	return;
}

Person::Person(string _name, Pet *_pet) 		// custom construtor
{
	name = _name;
	
	if (_pet != nullptr)
	{
		bool isFull = true;
		for (int i = 0; i < 5; i++)
		{
			if (_pet->owners[i] == nullptr)
			{
				pet = _pet;
				pet->owners[i] = this;
				isFull = false;
				i = 10; // force leaves the loop
			}
		}

		if (isFull) // if the pet's owner list is full
		{
			pet = nullptr;
			_pet->display(true);
			cout << " has 5 owners already!" << endl;
		}
	}

	else
	{
		pet = nullptr;
	}

	return;
}

Person::~Person() 	// default destructor
{
}


void Person::display(bool displayName)
{
	if (displayName)
	{
		cout << name;
	}

	else
	{
		cout << "Person name: " << name << endl;
		cout << "Pet: ";

		if (pet != nullptr)
		{
			pet->display(true);
			cout << endl;
		}

		else
		{
			cout << "No pet!" << endl;
		}
	}

	return;
}