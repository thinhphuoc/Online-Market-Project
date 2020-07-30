#pragma once
#include <iostream>
using namespace std;
class User
{
private:
	string fullname;
	string username;
	string password;
	int age;
	string gender;
	string address;
	float money;
public:
	User() {
		age = 0;
		money = 0;
	}
	bool CheckLogin(string, string);
	void SaveInforUser(string, string, string, int, string, string, float);
	void Welcome();

};


void Run_program_of_user(User a);


