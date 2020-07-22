#include <iostream>
using namespace std;
#include <string>
#include <fstream>
class Fashion {
public:
	bool findFashion();
	void showFashion();
	void editFashion();
	void removeFashion();
	void updateFileFashion(int tempNo);
	Fashion() {
		fashionID = price = tax = quantity = 0;
		name = manufacturer = color = "Empty";
	}
	~Fashion() {}
private:
	int fashionID;
	string name;
	string manufacturer;
	int price;
	int tax;
	string color;
	int quantity;
};