#ifndef PET_H
#define PET_H
#include <iostream>
using namespace std;

class Person; // forward declaring the class person

class Pet
{
	public:
		Pet(); 	// default constructor
		Pet(string, string, string);	// custom constructor
		virtual ~Pet(); 	// default destructor
		
		Person* owners[5];

		void display(bool);

	protected:

	private:
		string name;
		string animal;
		string breed;
	};

#endif // PET_H