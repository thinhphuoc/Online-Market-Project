#include "Admin.h"

void Admin::editItem() {
	int choose;
	cout << "Choose type Item to edit" << endl;
	cout << "Pess 1: Book          Press 2: Electronic          Press 3: Fashion          Press 4: HouseWare          Press 0: Back" << endl;
	cout << "Press>";
	cin >> choose;
	switch (choose) {
	case 1: {
		Book B;
		B.editBook();
		break;
	}
	case 2: {
		Electronic E;
		E.editElectronic();
		break;
	}
	case 3: {
		Fashion F;
		F.editFashion();
		break;
	}
	case 4: {
		Houseware H;
		H.editHouseware();
		break;
	}
	default: {
		cout << "your choice invalid!!!" << endl;
		break;
	}
	}
}

void Admin::removeItem() {
	int choose;
	Houseware H;
	Book B;
	Electronic E;
	Fashion F;
	cout << "Choose type Item to remove" << endl;
	cout << "Pess 1: Book          Press 2: Electronic          Press 3: Fashion          Press 4: HouseWare          Press 0: Back" << endl;
	cout << "Press>";
	cin >> choose;
	switch (choose) {
	case 1: {
		Book B;
		B.removeBook();
		break;
	}
	case 2: {
		Electronic E;
		E.removeElectronic();
		break;
	}
	case 3: {
		Fashion F;
		F.removeFashion();
		break;
	}
	case 4: {
		Houseware H;
		H.removeHouseware();
		break;
	}
	default: {
		cout << "your choice invalid!!!" << endl;
		break;
	}
	}
}

void Admin::add()
{
	int choose;
	cout << "Choose type Item to remove" << endl;
	cout << "Pess 1: Book          Press 2: Electronic          Press 3: Fashion          Press 4: HouseWare          Press 0: Back" << endl;
	cout << "Press>";
	cin >> choose;
	switch (choose) {
	case 1: {
		Book B;
		std::string ID, author, price, tax, pages, quantity;
		std::ofstream book(__BOOK, std::ios::app);
		book << ',' << ID  <<',' << author << ',' << price << ',' << tax << ',' << pages << ',' << quantity << '\n';
		book.close();
		break;
	}
	case 2: {
		Electronic E;
		std::string elec, name, manuf, price, tax, colors, quantity;
		std::ofstream fashion(__ELECTRONIC, std::ios::app);
		fashion << ',' << elec << ',' << name << ',' << manuf << ',' << price << ',' << tax << ',' << colors << ',' << quantity << '\n';
		break;
	}
	case 3: {
		Fashion F;
		std::string ID, name, manuf, price, tax, colors, quantity;
		std::ofstream fashion(__FASHION, std::ios::app);
		fashion << ',' << ID << ',' << name << ',' << manuf << ',' << price << ',' << tax << ',' << colors << ',' << quantity << '\n';
		break;
	}
	case 4: {
		Houseware H;
		std::string hware, name, manuf, price, tax, colors, quantity;
		std::ofstream fashion(__HOUSEWARE, std::ios::app);
		fashion << ',' << hware << ',' << name << ',' << manuf << ',' << price << ',' << tax << ',' << colors << ',' << quantity << '\n';
		break;
	}
	default: {
		cout << "your choice invalid!!!" << endl;
		break;
	}
	}
}