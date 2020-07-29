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