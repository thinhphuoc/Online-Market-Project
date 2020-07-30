#include<fstream>
#include "Login.h"
#include"Admin.h"
#include"User.h"

void Login() {
	system("cls");
	int n;
	string fullname, username, password, address, gender;
	int age;
	float money;
	User* Infor_user;
	Admin* Infor_admin;
	string user, pass;
	cout << "Login" << endl;
	cout << "----------------------------" << endl;
	cout << "Enter username: ";
	getline(cin, user);
	cout << "Enter password: ";
	getline(cin, pass);
	ifstream fi;
	fi.open("D:\\Online-Market-Project\\User.txt", ios::in);
	if (!fi.is_open())
	{
		cout << "Error Open File !";
		system("pause");
		return;
	
	}
	else
	{
		string s;
		fi >> n;
		Infor_user = new User[n];
		getline(fi, s);
		getline(fi, s);
		for (int i = 0; i < n; i++)
		{
			getline(fi, fullname);
			getline(fi, username);
			getline(fi, password);
			fi >> age;
			fi.ignore();
			getline(fi, gender);
			getline(fi, address);
			fi >> money;
			getline(fi, s);
			getline(fi, s);
			Infor_user[i].SaveInforUser(fullname, username, password, age, gender, address, money);
		}
		fi.close();
	}


	int n1;
	fi.open("D:\\Online-Market-Project\\Admin.txt", ios::in);
	if (!fi.is_open())
	{
		cout << "Error Open File !";
		system("pause");
		return;

	}
	else
	{
		string s;
		fi >> n1;
		Infor_admin = new Admin[n1];
		getline(fi, s);
		getline(fi, s);
		for (int i = 0; i < n1; i++)
		{
			getline(fi, fullname);
			getline(fi, username);
			getline(fi, password);
			getline(fi, s);
			Infor_admin[i].SaveInforAdmin(fullname, username, password);
		}
		fi.close();
	}

	for (int i = 0; i < n; i++) {
		if (Infor_user[i].CheckLogin(user, pass)) {
			Run_program_of_user(Infor_user[i]);
			return;
		}


	}
	for (int i = 0; i < n1; i++) {
		if (Infor_admin[i].CheckLogin(user, pass)) {
			Run_program_of_admin(Infor_admin[i]);
			return;
		}
	}

	cout << "User or Password Incorrect!" << endl;
	system("pause");
	Login();
}