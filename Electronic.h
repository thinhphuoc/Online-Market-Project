#include <iostream>
using namespace std;
#include <string>
#include <fstream>
class Electronic {
public:
	bool findElectronic();
	void showElectronic();
	void editElectronic();
	void removeElectronic();
	void updateFileElectronic(int tempNo);
	Electronic() {
		electronicID = price = tax = quantity = 0;
		name = manufacturer=color = "Empty";
	}
	~Electronic() {}
private:
	int electronicID;
	string name;
	string manufacturer;
	int price;
	int tax;
	string color;
	int quantity;
};