#include "Electronic.h"

void Electronic::showElectronic() {
	cout << "ID: " << this->electronicID << endl;
	cout << "Name: " << this->name << endl;
	cout << "manufacturer: " << this->manufacturer << endl;
	cout << "Price: " << this->price << endl;
	cout << "Tax: " << this->tax << endl;
	cout << "color: " << this->color << endl;
	cout << "Quantity: " << this->quantity << endl;
}

bool Electronic::findElectronic() {
	system("cls");
	ifstream f;
	string path = "Electronic.csv";
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
		this->electronicID = stoi(tempString);

		if ((this->name = f.get()) != "\"") {
			getline(f, tempString, ',');
			this->name += tempString;
		}
		else {
			getline(f, tempString, '"');
			this->name = tempString;
			f.get();
		}
		getline(f, tempString, ',');
		this->manufacturer = tempString;
		getline(f, tempString, ',');
		this->price = stoi(tempString);
		getline(f, tempString, ',');
		this->tax = stoi(tempString);
		getline(f, tempString, ',');
		this->color = tempString;
		getline(f, tempString, '\n');
		this->quantity = stoi(tempString);
		if (this->electronicID == idFind) {
			isFind = true;
			cout << "\nElectronic is found: " << endl;
			this->showElectronic();
			break;
		}
	}

	if (isFind == false) {
		cout << "This Electronic is not exist\n";
		system("pause");
		f.close();
		return false;
	}

	f.close();
	return true;
}

void Electronic::editElectronic() {
	int oldID = 0;
	if (this->findElectronic() == true) {
		oldID = this->electronicID;
		cout << "Enter the new info of Electronic" << endl;
		cout << "Enter ID: ";
		cin >> this->electronicID;
		cout << "Enter name of Electronic: ";
		getline(cin, this->name);
		getline(cin, this->name);
		cout << "Enter manufacturer of Electronic: ";
		getline(cin, this->manufacturer);
		cout << "Enter price: ";
		cin >> this->price;
		cout << "Enter tax: ";
		cin >> this->tax;
		cout << "enter color: ";
		getline(cin, this->color);
		getline(cin, this->color);
		cout << "enter quantity: ";
		cin >> this->quantity;

		int Count = 0;
		string path = "Electronic.csv";
		string pathTemp = "temp.csv";
		fstream f, ftemp;
		Electronic temp;
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
			temp.electronicID = stoi(tempString);
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
			temp.manufacturer = tempString;
			getline(f, tempString, ',');
			temp.price = stoi(tempString);
			getline(f, tempString, ',');
			temp.tax = stoi(tempString);
			getline(f, tempString, ',');
			temp.color = tempString;
			getline(f, tempString, '\n');
			temp.quantity = stoi(tempString);
			if (oldID == temp.electronicID) {
				ftemp << Count << ',' << this->electronicID << ',' << '"' << this->name << '"' << ',' << this->manufacturer << ',' << this->price;
				ftemp << ',' << this->tax << "%," << this->color << ',' << this->quantity << '\n';
			}
			else {
				ftemp << Count << ',' << temp.electronicID << ',' << '"' << temp.name << '"' << ',' << temp.manufacturer << ',' << temp.price;
				ftemp << ',' << temp.tax << "%," << temp.color << ',' << temp.quantity << '\n';
			}
		}

		f.close();
		ftemp.close();
		remove(path.c_str());
		rename(pathTemp.c_str(), path.c_str());
	}
}

void Electronic::removeElectronic() {
	int choose;
	if (this->findElectronic()) {
		cout << "\n Do you want to remove this Electronic?     Press 1: Yes      Press 0: No     >";
		cin >> choose;
		if (choose == 1) {
			system("cls");
			string path = "Electronic.csv";
			string pathTemp = "temp.csv";
			fstream f, ftemp;
			int No, Count = 0;
			Electronic temp;
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
				temp.electronicID = stoi(tempString);
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
				temp.manufacturer = tempString;
				getline(f, tempString, ',');
				temp.price = stoi(tempString);
				getline(f, tempString, ',');
				temp.tax = stoi(tempString);
				getline(f, tempString, ',');
				temp.color = tempString;
				getline(f, tempString, '\n');
				temp.quantity = stoi(tempString);
				if (this->electronicID == temp.electronicID) {
					Count--;
					continue;
				}
				else {
					ftemp << Count << ',' << temp.electronicID << ',' << '"' << temp.name << '"' << ',' << temp.manufacturer << ',' << temp.price;
					ftemp << ',' << temp.tax << "%," << temp.color << ',' << temp.quantity << '\n';
				}
			}
			cout << "The Electronic was removed!!!" << endl;
			f.close();
			ftemp.close();
			remove(path.c_str());
			rename(pathTemp.c_str(), path.c_str());
		}
	}
}