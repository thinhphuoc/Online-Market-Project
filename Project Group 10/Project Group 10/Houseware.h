#include <iostream>
using namespace std;
#include <string>
#include <fstream>
class Houseware {
public:
	bool findHouseware();
	void showHouseware();
	void editHouseware();
	void removeHouseware();
	void updateFileHouseware(int tempNo);
	Houseware() {
		housewareID = price = tax = quantity = 0;
		name = manufacturer = color = "Empty";
	}
	~Houseware() {}
private:
	int housewareID;
	string name;
	string manufacturer;
	int price;
	int tax;
	string color;
	int quantity;
};