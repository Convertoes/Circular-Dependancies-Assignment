// Author: Alex Larochette
// Project: Circular Dependancies Assignment
// Description: 
// Created: 
// Modified: 

// ============================= libraries ========================================================================================================

#include <iostream>
#include <windows.h>
#include "Pet.h"
#include "Person.h"
using namespace std;

// ============================= function prototypes =============================================================================================================

void setPetOwner(Pet*, Person*);
void removePetOwner(Pet*, Person*);

// ============================= function definitions =============================================================================================================

void setPetOwner(Pet* pet, Person* owner) // wrapper function that sets both pet's owners and person's pet
{
	if (pet != nullptr)
	{
		if (owner != nullptr)
		{
			if (owner->pet != nullptr and owner->pet != pet)
			{
				owner->display(true);
				cout << " already has a pet!" << endl;
			}

			else if (owner->pet == pet)
			{
				owner->display(true);
				cout << " is already the owner of ";
				pet->display(true);
				cout << endl;
			}
			
			else
			{
				bool isFull = true;
				for (int i = 0; i < 5; i++)
				{
					if (pet->owners[i] == nullptr)
					{
						pet->owners[i] = owner;
						owner->pet = pet;
						isFull = false;
						i = 10; // force leaves the loop
					}
				}

				if (isFull) // if the pet's owner list is full
				{
					pet->display(true);
					cout << " has 5 owners already!" << endl;
				}
			}
		}

		else
		{
			cout << "The owner does not exist" << endl;
		}
	}

	else
	{
		cout << "The pet does not exist" << endl;
	}
}

void removePetOwner(Pet* pet, Person* owner) // wrapper function that removes both person's pet and pet's owner
{
	if (pet != nullptr)
	{
		if (owner != nullptr)
		{
			if (owner->pet == nullptr)
			{
				owner->display(true);
				cout << " does not have a pet!" << endl;
			}

			else
			{
				for (int i = 0; i < 5; i++)
				{
					if (pet->owners[i] == owner)
					{
						pet->owners[i] = nullptr;
						owner->pet = nullptr;
						i = 10; // force leaves the loop
					}
				}
			}
		}

		else
		{
			cout << "The owner does not exist" << endl;
		}
	}

	else
	{
		cout << "The pet does not exist" << endl;
	}
	
	return;
}

// ============================= main =============================================================================================================

int main()
{
	Pet* ptrPet1 = new Pet("Sunny", "Cat", "American Ringtail"), * ptrPet2 = new Pet();
	Person* ptrPerson1 = new Person("Jessica Dao", ptrPet1), * ptrPerson2 = new Person(), * ptrPerson3 = new Person("William Griffin", nullptr);
	Person* ptrPerson4 = new Person("Jean Paul Larochette", nullptr);

	setPetOwner(ptrPet1, ptrPerson2);
	setPetOwner(ptrPet1, ptrPerson3);

	cout << endl;
	ptrPet1->display(false);
	cout << endl;
	ptrPet2->display(false);
	cout << endl;
	ptrPerson1->display(false);
	cout << endl;
	ptrPerson2->display(false);
	cout << endl;
	ptrPerson3->display(false);
	cout << endl;
	ptrPerson4->display(false);
	cout << endl;

	removePetOwner(ptrPet1, ptrPerson2);
	setPetOwner(ptrPet2, ptrPerson2);
	setPetOwner(ptrPet2, ptrPerson4);

	cout << endl;
	ptrPet1->display(false);
	cout << endl;
	ptrPet2->display(false);
	cout << endl;
	ptrPerson1->display(false);
	cout << endl;
	ptrPerson2->display(false);
	cout << endl;
	ptrPerson3->display(false);
	cout << endl;
	ptrPerson4->display(false);
	cout << endl;

	return 0;
}