#include"Functions.h"
void displayMaps() {
	cout << "\n\t\t\t\t  " << "Welcome" << "\n\n\t\t";
	cout << "\t  Here's All map are recently Saved\n\t\t" << endl;
	cout << "\n\t\t\t\t  " << "Welcome" << "\n\n\t\t";
	cout << "\t  Here's All map are recently Saved\n\t\t" << endl;
	ifstream display("Mapsname.txt", ios::in);
	string choices;
	while (getline(display, choices)) {
		cout << "\n\t\t ->> " << choices << endl;
	}
	cout << endl;
}
//****************************************************************************
void addGraph() {
	displayMaps();
	Graph Map;
	Map.addMap();
}
//*****************************************************************************************************
void displayGraph() {
	displayMaps();
	Graph recall;
	string x;
	do {
		cout << "\n\t\t  Do you Want to return to Main menue ? yes/no\n\t\t" << endl;
		cout << "\t\t ";
		cin >> x;
		if (x == "yes") {
			system("cls");
			AppStart();   // here is problem when i call not call function
		}
		else if (x == "no") {
			recall.mp.clear();
			cout << "\n\t\t  please write Name of the Map that you want to display\n\t\t" << endl;
			cout << "\t\t";
			string input;
			cin >> input;
			ifstream mapDetails(input + ".txt");
			string seperate;
			while (getline(mapDetails, seperate)) {
				string str[3];
				string reference = "#";
				size_t pos = 0;
				string token;
				int counter = 0;
				while ((pos = seperate.find(reference)) != -1) {
					token = seperate.substr(0, pos);
					str[counter] = token;
					seperate.erase(0, pos + reference.length());
					counter++;

				}
				str[counter] = seperate;
				int dis = stoi(str[2]);
				recall.putINmap(str[0], str[1], dis);
			}
			recall.outMap();
		}
		cout << "Do you want to open another File" << endl;
	} while (true);
}
//*********************************************************************************
void deleteMap() {
	displayMaps();
	string delname;
	unordered_set<string> del;
	unordered_set<string>::iterator it;
	cout << "Entre Map's Name" << endl;
	getline(cin, delname);
	fstream mapsNames("Mapsname.txt", ios::in | ios::out | ios::app);
	string line;
	while (mapsNames >> line)
	{
		del.insert(line);
	}
	do
	{

		if (del.find(delname) != del.end()) {
			del.erase(delname);
			it = del.begin();
			ofstream ofs;
			ofs.open("Mapsname.txt", std::ofstream::out | std::ofstream::trunc);
			ofstream append("Mapsname.txt", ios::out | ios::app);
			for (auto it = del.begin(); it != del.end(); it++) {
				ofs << *it << endl;
			}
			delname = delname + ".txt";
			char delfile[1024];
			strcpy_s(delfile, delname.c_str());
			remove(delfile);
			break;


		}
		else {
			cout << "there is Map that have such Name,please check Map name and entre again" << endl;
		}
		cout << "Entre Map Name" << endl;
		getline(cin, delname);

	} while (true);
	mapsNames.close();

}