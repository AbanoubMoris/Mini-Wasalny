#include"Shape.h"
using namespace std;
char Diamond = 4;
char Heart = 3;
char Happy = 1;
//***********************************************************************
void shape(int width, int height) {
	system("CLS");
	string Name = "Welcom in Waslny Application";
	cout << "\n\t\t\t\t  " << "Welcome" << "\n\n\t\t";
	for (int i = 0; i < width; i++)
		cout << Diamond;
	cout << endl;
	for (int i = 0; i < height; i++) {
		cout << "\t\t" << Heart;
		for (int g = 0; g < width - 2; g++)
			if (i == 5) {
				cout << "\t" << Name;
				int x = width - 2 - Name.length() - 7;
				for (int z = 0; z < x; z++) {
					cout << " ";
				}
				break;
			}
			else
				cout << " ";
		cout << Heart << endl;
	}
	cout << "\t\t";
	for (int i = 0; i < width; i++)
		cout << Diamond;
	cout << endl;
}
//******************************************************************************************************
void AppStart() {
	//cout << "\n\t\t\t\t  " << " Main Menu "<< "\n\n";
	shape(50, 10);
	cout << "\n\t\t 1 - Add Map\n\t\t 2 - Edit Map\n\t\t 3 - Display Maps\n\t\t 4 - Get Shortest Path\n\t\t 5 - Delete Map\n\t\t 6 - Change Default path\n\t\t";
	char choice;
	choice = _getch();
	if (choice == '1') {
		system("CLS");
		addGraph();
	}
	else if (choice == '2')
	{
		system("CLS");
		EditGraph();
	}
	else if (choice == '3') {
		system("CLS");
		char choose;
		do {
			displayMaps();
			cout << "\n\t\t  please write Name of the Map that you want to display\n\t\t" << endl;
			cout << "\t\t";
			string input;
			cin >> input;
			displayGraph(input);
			cout << "\n\n Do You want to display another Map (y/n)? ";
			cin >> choose;
			system("CLS");
		} while (choose == 'y');
		AppStart();
	}
	else if (choice == '4') {
		system("CLS");
		//shortestPath
	}
	else if (choice == '5') {
		system("CLS");
		deleteMap();
	}
}