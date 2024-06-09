#include <iostream>
#include "Pet.h"
#include "Person.h"
using namespace std;

Pet::Pet()		// default constructor
{
	name = "Vivian";
	animal = "Cat";
	breed = "Siamese";

	for (int i = 0; i < 5; i++)
	{
		owners[i] = nullptr;
	}

	return;
}

// pet does not have a custom constructor for owners[] because 
// a) a person has to adopt/own a cat before the cat can call the person the owner (person's custom constructor adds to cat's owner list)
// b) having both person and pet initialize eachother creates a circular dependancy mess (and because of reason a) it makes more sense to have person initialize pet
Pet::Pet(string _name, string _animal, string _breed) 		// custom construtor
{	
	name = _name;
	animal = _animal;
	breed = _breed;

	for (int i = 0; i < 5; i++) 
	{
		owners[i] = nullptr;
	}

	return;
}

Pet::~Pet() // default destructor
{

}

void Pet::display(bool displayName)
{
	if (displayName) // outputs only the name, called from other classes
	{
		cout << name;
	}

	else
	{
		cout << "Pet name: " << name << endl;
		cout << "Animal: " << animal << endl;
		cout << "Breed: " << breed << endl;
		cout << "Owners: ";

		int counter = 0; // counter used for displaying comma
		for (int i = 0; i < 5; i++)
		{
			if (owners[i] != nullptr)
			{
				if (counter != 0) // displays a comma for every owner after the first
				{
					cout << ", ";
				}

				owners[i]->display(true); // displays the person's name
				counter++;
			}
		}

		if (counter == 0) // displays message
		{
			cout << "No Owner!";
		}

		cout << endl;
	}

	return;
}