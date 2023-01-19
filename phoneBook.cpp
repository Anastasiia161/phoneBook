#include "phoneBook.h"
ostream& operator<<(ostream& stream, Abonent& abon) {
	stream << abon.name << " " << abon.phone;
	return stream;

}
istream& operator>>(istream& stream, Abonent& abon) {
	char name[128];
	char phone[128];
	stream >> name;
	stream >> phone;
	Abonent abon2(name, phone);
	abon = abon2;
	return stream;
}
ostream& operator<<(ostream& stream, PhoneBook& pb) {
	for (int i = 0; i < pb.size; i++) {
		stream << pb.abonents[i] << endl;
	}
	return stream;
}