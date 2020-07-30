#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "Book.h"
#include "Electronic.h"
#include "Fashion.h"
#include "Houseware.h"


#define __BOOK ".Book.csv"
#define __ELECTRONIC ".Electronic.csv"
#define __FASHION ".Fashion.csv"
#define __HOUSEWARE ".Houseware.csv"

class Admin
{
private:
	string name;
	string username;
	string password;
public:
	void editItem();
	void removeItem();
	void add();
	void SaveInforAdmin(string, string, string);
	bool CheckLogin(string,string);
	void Welcome();

};

void Run_program_of_admin(Admin a);
