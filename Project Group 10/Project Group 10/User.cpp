#include "User.h"
#include"string"
void User::SaveInforUser(string a, string b, string c, int d, string e,string n, string f, float g,int t) {
	fullname = a;
	username = b;
	password = c;
	age = d;
	gender = e;
	phoneNumbers = n;
	address = f;
	money = g;
	numDayBlock = t;

}

bool User::CheckLogin(string a, string b) {
	if (a == this->username && b == this->password && this->numDayBlock==0) return 1;
	return 0;
}

void User::Welcome() {		
	cout << "Hello: " << this->fullname << endl;
}


void User::editProfile() {
	int choice;
	string s;
loop:;
	system("cls");
	cout << "Edit Profile:" << endl;
	cout << "-------------------------" << endl;
	cout << "1. Your name: " << this->fullname << endl;
	cout << "2. Age: " << this->age << endl;
	cout << "3. Gender: " << this->gender << endl;
	cout << "4.Phone numbers: " << this->phoneNumbers << endl;
	cout << "5. Address: " << this->address << endl;
	cout << "0. Save and go back !" << endl;
	cout << "-------------------------" << endl;
	cout << "Your choice: ";
	cin >> choice;
	switch (choice)
	{
	case 1: {
		cout << "Enter new fullname: ";
		cin.ignore();
		getline(cin, this->fullname);
		goto loop;

	}
	case 2: {
		cout << "Enter age: ";
		cin >> this->age;
		goto loop;
	}
	case 3: {
		if (this->gender == "Male") {
			this->gender = "Female";
		}
		else {
			this->gender = "Male";

		}
		goto loop;

	}
	case 4: {
		cout << "Enter phone numbers: ";
		cin.ignore();
		getline(cin, this->phoneNumbers);
		goto loop;
	}
	case 5: {
		cout << "Enter address: ";
		cin.ignore();
		getline(cin, this->address);
		goto loop;

	}
	case 0: {
		cout << "Save profile successfully!" << endl;
		system("pause");
		break;
	}
	default:
		break;
	}

}





/////////////////////////////////////////////////////
//Chay cac chuc nang cua user o day !
// a la user
void Run_program_of_user(User a) {
	system("cls");
	a.Welcome();
	//...........................//
}

