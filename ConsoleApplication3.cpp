
#include <iostream>
#include "phoneBook.h"
using namespace std;



int main()
{
	Abonent abon("Ron", "89623203337");
	cout << abon << endl;
	abon.show();
	cout << abon << endl;
	
	const char* name2{ "Harry" };
	const char* phone2{ "123" };
	Abonent abon2(name2, phone2);
	
	cout << abon2 << endl;
	PhoneBook pb;
	pb.add(abon).add(abon2);
	
	cout << pb;

	
	Abonent ab3 = pb[1];
	cout << ab3;


	int val = 13;
	int& refVal = val;

}
