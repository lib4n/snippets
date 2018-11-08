#include <iostream>

using namespace std;

namespace padding {

	#pragma pack(push,1)
	struct Person {
		char name[50];
		int  age;
		double income;
	};
	#pragma pack(pop)

	void print() {
		cout << "Size of name  : " << sizeof(Person::name) << endl;
		cout << "Size of age   : " << sizeof(Person::age) << endl;
		cout << "Size of income: " << sizeof(Person::income) << endl;
		cout << "--------------- " << endl;
		cout << "Total         : " << sizeof(Person::name) + sizeof(Person::age) + sizeof(Person::income) << endl;

		cout << "Size of struct: " << sizeof(Person) << endl;
	}

}