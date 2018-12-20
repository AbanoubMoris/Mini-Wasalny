#include"Functions.h"
#include <sstream>
map<string, vector<Edge>> mp;
void Loading(string s, int delay) {
	//system("color 74");
	char a = 177;
	cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tLoading.... " + s;
	cout << "\n\n";
	cout << "\t\t\t\t\t\t";
	for (int i = 0; i <= 30; i++) {
		system("color 61");
		cout << char(219);
		Sleep(delay);
	}
	cout << endl;
	system("CLS");
}

void displayMaps() {
	Loading("Maps", 70);
	cout << "\n\t\t\t\t  " << "Welcome" << "\n\n\t\t";
	cout << "\t  Here's All map are recently Saved\n\t\t\n";
	ifstream display("Mapsname.txt", ios::in);
	string choices;
	while (getline(display, choices))
		cout << "\n\t\t ->> " << choices << endl;
	cout << endl;
}

void addGraph() {
	displayMaps();
	Graph Map;
	Map.addMap();
}

vector<string> displayGraph(string mapName, map<string, vector<Edge>> &map) {
	Loading(mapName, 70);
	Graph recall;
	recall.mp.clear();
	ifstream mapDetails(mapName + ".txt");
	string seperate;
	vector<string> mapEdges;//Put every Line before splitting in vector of strings
	mapEdges.clear();

	while (getline(mapDetails, seperate)) {
		string infoEdge[3];
		string reference = "#";
		size_t pos = 0;
		string token;
		int counter = 0;

		mapEdges.push_back(seperate); //Put every Line before splitting in vector of strings

		seperate.erase(seperate.begin()); //erase first #
		while ((pos = seperate.find(reference)) != -1) {
			token = seperate.substr(0, pos);
			infoEdge[counter] = token;
			seperate.erase(0, pos + reference.length());
			counter++;
		}
		infoEdge[counter] = seperate;
		int dis = stoi(infoEdge[2]);
		recall.putINmap(infoEdge[0], infoEdge[1], dis);
	}
	recall.outMap(map);
	return mapEdges;
}

void deleteMap() {
	displayMaps();
	string delMapName;
	unordered_set<string> delMapsNames;
	unordered_set<string>::iterator itDel;
	cout << "Entre Map's Name" << endl;
	getline(cin, delMapName);
	fstream mapsNames("Mapsname.txt", ios::in | ios::out | ios::app);
	string line;
	while (mapsNames >> line)
		delMapsNames.insert(line);
	do{
		if (delMapsNames.find(delMapName) != delMapsNames.end()) {
			delMapsNames.erase(delMapName);
			itDel = delMapsNames.begin();
			ofstream ofs;
			ofs.open("Mapsname.txt", std::ofstream::out | std::ofstream::trunc);
			ofstream append("Mapsname.txt", ios::out | ios::app);
			for (auto it = delMapsNames.begin(); it != delMapsNames.end(); it++)
				ofs << *it << endl;
			delMapName = delMapName + ".txt";
			char delFile[1024];
			strcpy_s(delFile, delMapName.c_str());
			remove(delFile);
			break;
		}
		else
			cout << "there is Map that have such Name,please check Map name and entre again" << endl;
		cout << "Entre Map Name" << endl;
		getline(cin, delMapName);
	} while (true);
	mapsNames.close();
}

void EditGraph() {
	cout << "\t\t What do you want to Edit ?\n ";
	cout << "\t\t\t 1- Add \n";
	cout << "\t\t\t 2- Update City Name \n";
	cout << "\t\t\t 3- Delete \n\n";
	int choose;
	cin >> choose;
	//choose = _getch();
	if (choose == 1) {
		system("CLS");
		cout << "\t 1- Add City\n";
		cout << "\t 2- Add edge\n";
		cin >> choose;
		if (choose == 1) {
			//add new city
			system("CLS");
			displayMaps();
			cin.ignore(1000, '\n');
			string mapName;
			cout << "Enter Name of map where you want add City: ";
			getline(cin, mapName);
			map<string, vector<Edge>> mp;
			displayGraph(mapName, mp);
			string City1;
			int connectedCityCtr;
			cout << "Enter The Name of city: ";
			getline(cin, City1);
			cout << "How Many Number of Cities Conected with " + City1 + " :";
			cin >> connectedCityCtr;
			for (int i = 0; i < connectedCityCtr; i++)
				AddCity(City1, mp, mapName);
		}
		else if (choose == 2) {
			//add edge
			displayMaps();
			cout << "\n\t\t  please write Name of the Map that you want to display\n\t\t" << endl;
			cout << "\t\t";
			string input;
			cin >> input;
			map<string, vector<Edge>> mp;
			vector<string>x = displayGraph(input, mp);
			string City1, City2;
			cout << "\tEnter City1 Name : ";
			cin.ignore(1000, '\n');
			getline(cin, City1);
			cout << "\tEnter City2 Name : ";
			getline(cin, City2);
			AddEdge(City1, City2, x, input);
		}
	}

	else if (choose == 2) {
		system("CLS");
			//update name of node
			displayMaps();
			cout << "\n\t\t  please write Name of the Map that you want to Edite it\n\t\t" << endl;
			cout << "\t\t";
			string input;
			cin >> input;
			map<string, vector<Edge>> mp;
			vector<string>x = displayGraph(input, mp);
			string NodeName;
			cout << "\tEnter Node Name : ";
			cin.ignore(1000, '\n');
			getline(cin, NodeName);
			EditNode(NodeName, x, input);
	}
	
	else if (choose == 3) {
		system("CLS");
		cout << "\t 1-> Delete Node \n";
		cout << "\t 2-> Delete Edge \n";
		cin >> choose;
		if (choose == 1) {
			//delete node
			displayMaps();
			cout << "\n\t\t  please write Name of the Map that you want to display\n\t\t" << endl;
			cout << "\t\t";
			string input;
			cin >> input;
			map<string, vector<Edge>> mp;
			vector<string>x = displayGraph(input, mp);
			string NodeName;
			cout << "\tEnter Node Name : ";
			cin.ignore(1000, '\n');
			getline(cin, NodeName);
			DeleteNode(NodeName, x, input);
		}
		else if (choose == 2) {
			//delete edge
			displayMaps();
			cout << "\n\t\t  please write Name of the Map that you want to display\n\t\t" << endl;
			cout << "\t\t";
			string input;
			cin >> input;
			map<string, vector<Edge>> mp;
			vector<string>x = displayGraph(input, mp);
			string City1, City2;
			cout << "\tEnter City1 Name : ";
			cin.ignore(1000, '\n');
			getline(cin, City1);
			cout << "\tEnter City2 Name : ";
			getline(cin, City2);
			DeleteEdge(City1, City2, x, input);
		}
	}
	system("CLS");
	cout << "\n\n\n\t\t\tAll Data Has been Edited :)";
	Sleep(2500);
	AppStart();
}
void DeleteNode(string NodeName, vector<string> s, string fileName) {
	string del = '#' + NodeName + '#';
	int i = 0;
	while (i < s.size()) {
		if (s[i].find(del) != -1) {
			s.erase(s.begin() + i);
			i = 0;
		}
		else i++;
	}
	fstream f;
	f.open(fileName + ".txt", ios::end);
	f << "Deleted";
	f.close();
	f.open(fileName + ".txt", ios::end);
	for (int i = 0; i < s.size(); i++)
		f << s[i] << endl;
	f.close();
}
void DeleteEdge(string City1, string City2, vector<string> s, string fileName) {
	string del1 = '#' + City1 + '#' + City2 + '#';
	string del2 = '#' + City2 + '#' + City1 + '#';
	int i = 0;
	while (i < s.size()) {
		if (s[i].find(del1) != -1 || s[i].find(del2) != -1) {
			s.erase(s.begin() + i);
			i = 0;
		}
		else i++;
	}
	fstream f;
	f.open(fileName + ".txt", ios::end);
	f << "Deleted";
	f.close();
	f.open(fileName + ".txt", ios::end);
	for (int i = 0; i < s.size(); i++)
		f << s[i] << endl;
	f.close();
}
void EditNode(string NodeName, vector<string>s, string fileName){
	string newname;
	cout << "Enter new name :";
	//cin.ignore(1000, '\n');
	getline(cin, newname);
	string Edit = '#' + newname + '#';
	string ToBeEdit = '#' + NodeName + '#';
	int i = 0;
	while (i < s.size()) {
		if (s[i].find(ToBeEdit) != -1) {
			s[i].replace(s[i].begin() + s[i].find(ToBeEdit), s[i].begin() + s[i].find(ToBeEdit) + ToBeEdit.size(), Edit);
			i = 0;
		}
		else i++;
	}
	fstream f;
	f.open(fileName + ".txt", ios::end);
	f << "Deleted";
	f.close();
	f.open(fileName + ".txt", ios::end);
	for (int i = 0; i < s.size(); i++) {
		f << s[i] << endl;
	}
	f.close();
}
void AddCity(string City1, map<string, vector<Edge>> mp, string fileName){
	double Weight;
	string City2;
	ofstream mapInfo(fileName + ".txt", ios::out | ios::app);
	cout << "connected with ->";
	cin >> City2;//dont accept getline
	cout << "their weight (distance between them) is :";
	cin >> Weight;
	stringstream ss;
	ss << Weight;
	string dis = ss.str();
	string concatinate = '#' + City1 + "#" + City2 + "#" + dis;
	mapInfo << concatinate << endl;
	mp[City1].push_back(Edge(City2, Weight));
	cout << "**********************\n";
}
void AddEdge(string NodeName1, string NodeName2, vector<string> x, string fileName){
	double Weight;
	ofstream mapInfo(fileName + ".txt", ios::out | ios::app);
	cout << "their weight (distance between them) is :";
	cin >> Weight;
	stringstream ss;
	ss << Weight;
	string dis = ss.str();
	string concatinate = '#' + NodeName1 + "#" + NodeName2 + "#" + dis;
	mapInfo << concatinate << endl;
	mp[NodeName1].push_back(Edge(NodeName2, Weight));
	cout << "**********************\n";
}
