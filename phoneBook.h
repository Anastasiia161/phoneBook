#pragma once
#include <iostream>
using namespace std;
class Abonent {
	char* name;
	char* phone;
public:
	Abonent() {
		name = new char[0];
		phone = new char[0];
	}
	
	Abonent(const char* name, const char* phone) {
		int sz1 = strlen(name) + 1;
		int sz2 = strlen(phone) + 1;
		this->name = new char[sz1];
		this->phone = new char[sz2];
		for (int i = 0; i < sz1; i++) {
			this->name[i] = name[i];
		}
		for (int i = 0; i < sz2; i++) {
			this->phone[i] = phone[i];
		}
	}
	Abonent(const Abonent& abon) : Abonent(abon.name, abon.phone) {}
	Abonent& operator=(Abonent& abon) {
		if (this != &abon) {
			if (name)delete[]name;
			if (phone)delete[]phone;


			int sz1 = strlen(abon.name) + 1;
			int sz2 = strlen(abon.phone) + 1;
			name = new char[sz1];
			phone = new char[sz2];
			for (int i = 0; i < sz1; i++) {
				this->name[i] = abon.name[i];
			}
			for (int i = 0; i < sz2; i++) {
				this->phone[i] = abon.phone[i];
			}
		}
		return *this;
	}

	~Abonent() {
		if (name)delete[]name;
		if (phone)delete[]phone;
	}

	friend ostream& operator<<(ostream& stream, Abonent& abon); 
	friend istream& operator>>(ostream& stream, Abonent& abon);
	void show() {
		cout << name << " " << phone << endl;
	}
	bool SearchSubscriber(Abonent abon) {

		int searchFullName;
		cout << "Введите имя абонента, которого желаете найти: ";
		cin >> searchFullName;
		if (searchFullName == name) return true;
	}
};

class PhoneBook
{
	Abonent* abonents;
	int size;
public:
	PhoneBook() {}
	~PhoneBook() {
		delete[] abonents;
	}
	PhoneBook(PhoneBook& pb) {
		if (size > 0)
			delete[]abonents;
		if (pb.size > 0) {
			abonents = new Abonent[pb.size];
			for (int i; i < size; i++) {
				abonents[i] = pb.abonents[i];
			}
			size = pb.size;
		}
	}
	PhoneBook& operator=(PhoneBook& pb) {
		if (size > 0)
			delete[]abonents;
		if (pb.size > 0) {
			abonents = new Abonent[pb.size];
			for (int i; i < size; i++) {
				abonents[i] = pb.abonents[i];
			}
			size = pb.size;
		}
	}
	PhoneBook& add(Abonent abon) {
		Abonent* buff = new Abonent[size + 1];
		for (int i = 0; i < size; i++) {
			buff[i] = abonents[i];
		}
		buff[size] = abon;
		delete[]abonents;
		size++;
		abonents = buff;
		return *this;
	}
	void show() {
		for (int i = 0; i < size; i++) {
			cout << abonents[i];
		}
	}
	friend ostream& operator<<(ostream& stream, PhoneBook& pb);


	Abonent& operator[](int id) {
		
		return abonents[id];
	}
	
	void DeleteSubscriber() {

	}
	~PhoneBook() {
		cout << "Деструктор " << endl;
	}
};