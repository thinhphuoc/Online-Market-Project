#include "SignUp.h"
void Sign_Up() {
	string s[6];
	int num;
	cout << "Sign-up" << endl;
	cout << "---------------------------" << endl;
	cout << ">> Fullname: ";
	getline(cin, s[0]);
	cout << ">> Username: ";
	getline(cin, s[1]);
	cout << ">> Password: ";
	getline(cin, s[2]);
	cout << ">> Age: ";
	getline(cin, s[3]);
	cout << "Choose Gender " << endl;
	cout << "1. Male    2.Female" << endl;
	cout << "Your choice: ";
	cin >> num;
	if (num == 1) s[4] = "Male";
	else s[4] = "Female";
	cin.ignore();
	cout << ">> Address: ";
	getline(cin, s[5]);
	num = 0;
	string a;
	ifstream fi;
	fi.open("D:\\Online-Market-Project\\User.txt");
	fi >> num;
	ofstream fo;
	fo.open("D:\\Online-Market-Project\\User.txt");
	if (!fi.is_open() || !fo.is_open()) {
		cout << "Can't open file User.txt" << endl;
	}
	else {
		if (num == 0) {
			fo << 1 << endl << endl;
			for (int i = 0; i < 6; i++) {
				fo << s[i] << endl;
			}
			fo << 0 << endl;
		}
		else {
			fo << num + 1;
			while (!fi.eof()) {
				getline(fi, a);
				fo << a << endl;
			}
			for (int i = 0; i < 6; i++) {
				fo << s[i] << endl;

			}
			fo << 0 << endl;
		}
		cout << endl << ">>>>>> Sign up successfully! <<<<<<" << endl;

	}
	fi.close();
	fo.close();
}