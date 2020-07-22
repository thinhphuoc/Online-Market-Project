#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include "Book.h"
#include "Electronic.h"
#include "Fashion.h"
#include "Houseware.h"

class Admin
{
private:
	string name;
	string usename;
	string password;
public:
	void editItem();
	void removeItem();
};

