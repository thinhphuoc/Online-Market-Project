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
	string phoneNumbers;
	string address;
	float money;
	int numDayBlock;
public:
	User() {
		age = 0;
		money = 0;
		numDayBlock = 0;
	}
	bool CheckLogin(string, string);
	void SaveInforUser(string, string, string, int,string, string, string, float,int);
	void Welcome();
	void editProfile();

};


void Run_program_of_user(User a);


