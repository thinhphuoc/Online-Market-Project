#include "User.h"
void User::SaveInforUser(string a, string b, string c, int d, string e, string f, float g) {
	fullname = a;
	username = b;
	password = c;
	age = d;
	gender = e;
	address = f;
	money = g;
}

bool User::CheckLogin(string a, string b) {
	if (a == this->username && b == this->password) return 1;
	return 0;
}

void User::Welcome() {
	cout << "Hello: " << this->fullname << endl;
}



/////////////////////////////////////////////////////
//Chay cac chuc nang cua user o day nhe!
// a la user
void Run_program_of_user(User a) {
	system("cls");
	a.Welcome();

	//...........................//
}

