#include <iostream>
using namespace std;
#include <string>
#include <fstream>
class Book {
public:
	bool findBook();
	void showBook();
	void editBook();
	void removeBook();
	void updateFileBook(int tempNo);
	Book() {
		bookID = price = tax = pages = quantity = 0;
		name = author = "Empty";
	}
	~Book() {}
private:
	int bookID;
	string name;
	string author;
	int price;
	int tax;
	int pages;
	int quantity;
};