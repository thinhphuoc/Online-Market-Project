#include "Book.h"

void Book::showBook() {
	cout << "ID: " << this->bookID << endl;
	cout << "Name: " << this->name << endl;
	cout << "Author: " << this->author << endl;
	cout << "Price: " << this->price << endl;
	cout << "Tax: " << this->tax << endl;
	cout << "Pages: " << this->pages << endl;
	cout << "Quantity: " << this->quantity << endl;
}

bool Book::findBook() {
	system("cls");
	ifstream f;
	string path = "Book.csv";
	int idFind;
	string tempString;
	bool isFind = false;
	cout << "Enter the id: ";
	cin >> idFind;
	f.open(path, ios::in);
	if (!f) {
		cout << "can't open file!!!" << endl;
		exit(EXIT_FAILURE);
		return false;
	}
	
	getline(f, tempString, ',');
	getline(f, tempString, ',');
	getline(f, tempString, ',');
	getline(f, tempString, ',');
	getline(f, tempString, ',');
	getline(f, tempString, ',');
	getline(f, tempString, ',');
	getline(f, tempString, '\n');
	
	while (getline(f, tempString, ',')) {
		getline(f, tempString, ',');
		this->bookID = stoi(tempString);
		
		if ((this->name=f.get()) != "\"") {
			getline(f, tempString, ',');
			this->name += tempString;
		}
		else {
			getline(f, tempString, '"');
			this->name = tempString;
			f.get();
		}
		getline(f, tempString, ',');
		this->author = tempString;
		getline(f, tempString, ',');
		this->price = stoi(tempString);
		getline(f, tempString, ',');
		this->tax = stoi(tempString);
		getline(f, tempString, ',');
		this->pages = stoi(tempString);
		getline(f, tempString, '\n');
		this->quantity = stoi(tempString);
		if (this->bookID == idFind) {
			isFind = true;
			cout << "\nBook is found: " << endl;
			this->showBook();
			break;
		}
	}
	
	if (isFind == false) {
		cout << "This book is not exist\n";
		system("pause");
		f.close();
		return false;
	}
	
	f.close();
	return true;
}

void Book::editBook() {
	int oldID = 0;
	if (this->findBook() == true) {
		oldID = this->bookID;
		cout << "Enter the new info of Book" << endl;
		cout << "Enter ID: ";
		cin >> this->bookID;
		cout << "Enter name of book: ";
		getline(cin, this->name);
		getline(cin, this->name);
		cout << "Enter author of book: ";
		getline(cin, this->author);
		cout << "Enter price: ";
		cin >> this->price;
		cout << "Enter tax: ";
		cin >> this->tax;
		cout << "enter pages: ";
		cin >> this->pages;
		cout << "enter quantity: ";
		cin >> this->quantity;
		
		int Count = 0;
		string path = "Book.csv";
		string pathTemp = "temp.csv";
		fstream f, ftemp;
		Book temp;
		f.open(path, ios::in);
		ftemp.open(pathTemp, ios::out);
		string tempString;
		
		if (!f || !ftemp) {
			cout << "can't not open file for update!!!" << endl;
			exit(EXIT_FAILURE);

		}
		//read file from f write to file ftemp
		getline(f, tempString, ',');
		ftemp << "No" << ',';
		getline(f, tempString, ',');
		ftemp << tempString << ",";
		getline(f, tempString, ',');
		ftemp << tempString << ",";
		getline(f, tempString, ',');
		ftemp << tempString << ",";
		getline(f, tempString, ',');
		ftemp << tempString << ",";
		getline(f, tempString, ',');
		ftemp << tempString << ",";
		getline(f, tempString, ',');
		ftemp << tempString << ",";
		getline(f, tempString, '\n');
		ftemp << tempString << "\n";
		
		while (getline(f, tempString, ',')) {
			Count++;
			getline(f, tempString, ',');
			temp.bookID = stoi(tempString);
			if ((temp.name = f.get()) != "\"") {
				getline(f, tempString, ',');
				temp.name += tempString;
			}
			else {
				getline(f, tempString, '"');
				temp.name = tempString;
				f.get();
			}
			getline(f, tempString, ',');
			temp.author = tempString;
			getline(f, tempString, ',');
			temp.price = stoi(tempString);
			getline(f, tempString, ',');
			temp.tax = stoi(tempString);
			getline(f, tempString, ',');
			temp.pages = stoi(tempString);
			getline(f, tempString, '\n');
			temp.quantity = stoi(tempString);
			if (oldID == temp.bookID) {
				ftemp << Count << ',' << this->bookID << ',' << '"' << this->name << '"' << ',' << this->author << ',' << this->price;
				ftemp << ',' << this->tax << "%," << this->pages << ',' << this->quantity << '\n';
			}
			else {
				ftemp << Count << ',' << temp.bookID << ',' << '"' << temp.name << '"' << ',' << temp.author << ',' << temp.price;
				ftemp << ',' << temp.tax << "%," << temp.pages << ',' << temp.quantity << '\n';
			}
		}
		
		f.close();
		ftemp.close();
		remove(path.c_str());
		rename(pathTemp.c_str(), path.c_str());
	}
}

void Book::removeBook() {
	int choose;
	if (this->findBook()) {
		cout << "\n Do you want to remove this book?     Press 1: Yes      Press 0: No     >";
		cin >> choose;
		if (choose == 1) {
			system("cls");
			string path = "Book.csv";
			string pathTemp = "temp.csv";
			fstream f, ftemp;
			int No, Count=0;
			Book temp;
			string tempString;
			f.open(path, ios::in);
			ftemp.open(pathTemp, ios::out);
			if (!f || !ftemp) {
				cout << "can't not open file for remove!!!" << endl;
				exit(EXIT_FAILURE);
			}

			//read file from f write to file ftemp
			getline(f, tempString, ',');
			ftemp << "No" << ',';
			getline(f, tempString, ',');
			ftemp << tempString << ",";
			getline(f, tempString, ',');
			ftemp << tempString << ",";
			getline(f, tempString, ',');
			ftemp << tempString << ",";
			getline(f, tempString, ',');
			ftemp << tempString << ",";
			getline(f, tempString, ',');
			ftemp << tempString << ",";
			getline(f, tempString, ',');
			ftemp << tempString << ",";
			getline(f, tempString, '\n');
			ftemp << tempString << "\n";

			while (getline(f, tempString, ',')) {
				Count++;
				getline(f, tempString, ',');
				temp.bookID = stoi(tempString);
				if ((temp.name = f.get()) != "\"") {
					getline(f, tempString, ',');
					temp.name += tempString;
				}
				else {
					getline(f, tempString, '"');
					temp.name = tempString;
					f.get();
				}
				getline(f, tempString, ',');
				temp.author = tempString;
				getline(f, tempString, ',');
				temp.price = stoi(tempString);
				getline(f, tempString, ',');
				temp.tax = stoi(tempString);
				getline(f, tempString, ',');
				temp.pages = stoi(tempString);
				getline(f, tempString, '\n');
				temp.quantity = stoi(tempString);
				if (this->bookID == temp.bookID) {
					Count--;
					continue;
				}
				else {
					ftemp << Count << ',' << temp.bookID << ',' << '"' << temp.name << '"' << ',' << temp.author << ',' << temp.price;
					ftemp << ',' << temp.tax << "%," << temp.pages << ',' << temp.quantity << '\n';
				}
			}
			cout << "The book was removed!!!" << endl;
			f.close();
			ftemp.close();
			remove(path.c_str());
			rename(pathTemp.c_str(), path.c_str());
		}
	}
}