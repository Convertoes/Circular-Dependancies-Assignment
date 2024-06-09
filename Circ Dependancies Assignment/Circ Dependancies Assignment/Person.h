#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include "Pet.h"
using namespace std;

class Person
{
	public:
		Person(); 	// default constructor
		Person(string, Pet*);		// custom constructor
		virtual ~Person(); 	// default destructor

		Pet* pet;

		void display(bool);

	protected:

	private:
		string name;

		
};

#endif // PERSON_H