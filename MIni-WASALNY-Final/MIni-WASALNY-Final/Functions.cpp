#include"Functions.h"
#include <sstream>
map<string, vector<Edge>> mp;
//****************************************************** for kuriskal
map <string, string> parent;
map <string, vector<pair<string, double> > > graph;
priority_queue <pair<double, pair<string, string> > > kruskalQ;
//****************************************************************
void Loading(string s, int delay) {
	system("color 2f");
	system("color 0e");
	char a = 177, b = 219;
	cout << "\n\n\n\n\n\n\n\n\n\t\t\t\t\t\tLoading.... " + s;
	cout << "\n\n";
	cout << "\t\t\t\t\t\t";
	for (int i = 0; i <= 30; i++) {
		cout << b;
		Sleep(delay);
	}
	cout << endl;
	system("CLS");
}
//***********************************************************************************
void displayMaps() {
	Loading("Maps", 70);
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
vector<string> displayGraph(string input, map<string, vector<Edge>> &map) {
	Loading(input, 70);
	Graph recall;
	string x;
	recall.mp.clear();
	ifstream mapDetails(input + ".txt");
	string seperate;

	vector<string> L;//Put All Line before split in vector of string
	L.clear();
	while (getline(mapDetails, seperate)) {
		string str[3];
		string reference = "#";
		size_t pos = 0;
		string token;
		int counter = 0;

		L.push_back(seperate); //Put All Line before split in vector of string

		seperate.erase(seperate.begin()); //erase first #
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
	//map = mp;
	recall.outMap(map);
	return L;
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
//*********************************************************************************
void EditGraph() {
	cout << "\n\t\t\t\t  " << "Welcome" << "\n\n\t\t";
	cout << "\t\t What do you want to Edit ?\n ";
	cout << "\t\t\t 1-> Add new City \n";
	cout << "\t\t\t 2-> Update Map \n";
	cout << "\t\t\t 3-> Delete Node Or Edge \n\n";
	cout << "Enter Your choice : ";
	int choose;
	cin >> choose;
	if (choose == 1) {
		system("CLS");
		displayMaps();
		cin.ignore(1000, '\n');
		string name;
		cout << "Enter Name of map where you want add City:";
		getline(cin, name);
		map<string, vector<Edge>> mp;
		displayGraph(name, mp);
		string City1;
		int x;
		cout << "Enter The Name of city :";
		getline(cin, City1);
		cout << "How Many Number of Cities Conected with " + City1 + " :";
		cin >> x;
		for (int i = 0; i < x; i++)
		{
			AddCity(City1, mp, name);
		}
	}
	//------------------------------------------------------------------------------------------------
	else if (choose == 2) {
		//UpdateMap();
		system("CLS");
		cout << "\n\t\t\t\t  " << "Welcome" << "\n\n\t\t";
		cout << "\t 1-> Edite Name of Node \n";
		cout << "\t 2-> Add Edge in graph \n";
		cout << "Enter Your choice : ";
		cin >> choose;
		if (choose == 1) {
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
		else if (choose == 2) {
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
	//----------------------------------------------------------------------------------------------------------------
	else if (choose == 3) {
		system("CLS");
		cout << "\n\t\t\t\t  " << "Welcome" << "\n\n\t\t";
		cout << "\t 1-> Delete Node \n";
		cout << "\t 2-> Delete Edge \n";
		cout << "Enter Your choice : ";
		cin >> choose;
		if (choose == 1) {
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
	Sleep(3000);
	AppStart();
}
//***************************************************************************************
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
	for (int i = 0; i < s.size(); i++) {
		f << s[i] << endl;
	}
	f.close();
}
//**************************************************************************************
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
	for (int i = 0; i < s.size(); i++) {
		f << s[i] << endl;
	}
	f.close();
}
//*********************************************************************************
void EditNode(string NodeName, vector<string>s, string fileName)
{
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
//*************************************************************************************************************
void AddCity(string City1, map<string, vector<Edge>> mp, string fileName)
{

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
//**********************************************************************************************
void AddEdge(string NodeName1, string NodeName2, vector<string> x, string fileName)
{
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
//********************************************************************************************
void polymerization() {
	displayMaps();
	int linkedGraphs;
	bool ch_int;
	string newfile, Edge, line;
	unordered_set<string> mapNames, Edges;
	unordered_set<string>::iterator it;
	fstream mapsNames("Mapsname.txt", ios::in | ios::out | ios::app);
	while (mapsNames >> line)
		mapNames.insert(line);
	do {
		cout << "Enter Number of Graphs: ";
		cin >> linkedGraphs;
		ch_int = false;
		if (cin.fail()) {
			string choice_char;
			cin.clear();
			cin >> choice_char;
			ch_int = true;
		}
		if (linkedGraphs > mapNames.size())ch_int = true;
	} while (ch_int);
	string *file = new string[linkedGraphs];
	for (int i = 0; i < linkedGraphs; i++) {
		cout << "Enter Graph " << i + 1 << ": ";
		cin >> file[i];
	}
	cout << "Enter New Graph Name: ";
	cin >> newfile;
	do {
		bool wrongName = true, existName = false;
		if (mapNames.find(newfile) == mapNames.end()) existName = true;
		for (int i = 0; i < linkedGraphs; i++) {
			if (mapNames.find(file[i]) == mapNames.end())
				wrongName = false;
			if (file[i] == newfile)
				existName = true;
		}
		if (existName && wrongName) {
			for (int i = 0; i < linkedGraphs; i++)
				mapNames.erase(file[i]);
			it = mapNames.begin();
			ofstream ofs;
			ofs.open("Mapsname.txt", std::ofstream::out | std::ofstream::trunc);
			for (auto it = mapNames.begin(); it != mapNames.end(); it++)
				ofs << *it << endl;
			ofs << newfile << endl;
			for (int i = 0; i < linkedGraphs; i++) {
				fstream iFile(file[i] + ".txt", ios::in | ios::out | ios::app);
				while (iFile >> Edge)
					Edges.insert(Edge);
				iFile.close();
			}
			for (int i = 0; i < linkedGraphs; i++) {
				file[i] = file[i] + ".txt";
				char delfile[1024];
				strcpy_s(delfile, file[i].c_str());
				remove(delfile);
			}
			ofstream mapInfo(newfile + ".txt", ios::out | ios::app);
			for (auto it = Edges.begin(); it != Edges.end(); it++)
				mapInfo << *it << endl;
			ofs.close();
			mapInfo.close();
			break;
		}
		else
			cout << "there isn't Maps that have such Name, please check Maps' name and entre again \n\n";
		for (int i = 0; i < linkedGraphs; i++) {
			cout << "Enter Graph " << i + 1 << ": ";
			cin >> file[i];
		}
		cout << "Enter New Graph Name: ";
		cin >> newfile;
	} while (true);
	mapsNames.close();
	AppStart();
}
//**********************************************************************
void floydwarshall() {
	Loading("Maps", 70);
	char choose;
	do {
		int z;
		//cout << "Enter 1 to Direct graph Enter 2 to Undirect graph : ";
		//cin >> z;
		cout << "Enter Number of cities :";
		int num;
		cin >> num;
		//Weight 
		int ** S;
		S = new int *[num];
		for (int i = 0; i < num; i++)
			S[i] = new int[num];
		//name
		int ** D;
		D = new int *[num];
		for (int i = 0; i < num; i++)
			D[i] = new int[num];
		//********************************************************************************************
		//intial D Matrix
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num; j++)
			{
				if (i == j)
					S[i][j] = 0;
				else
					S[i][j] = j;
			}
		}
		//intial S Matrix
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num; j++)
			{
				if (i == j)
					D[i][j] = 0;
				else
					D[i][j] = 1000;
			}
		}

		int numOfEdges;
		cout << "Enter Number Of Edge : ";
		cin >> numOfEdges;
		int s, e, w;
		for (int i = 0; i < numOfEdges; i++)
		{
			cout << "Enter City1 and City2 and Weight : ";
			cin >> s >> e >> w;
			D[s - 1][e - 1] = w;
			//if (z == 2)
			//D[e-1][s-1] = w;
		}
		for (int k = 0; k < num; k++)
		{
			for (int i = 0; i < num; i++)
			{
				for (int j = 0; j < num; j++)
				{
					if (i == k || j == k || i == j)
						continue;
					else if (D[i][j] > D[i][k] + D[k][j])
					{
						D[i][j] = D[i][k] + D[k][j];
						//D[j][i] = D[i][k] + D[k][j];
						S[i][j] = S[i][k];
						//	S[j][i] =  S[k][j];
					}
					else
					{
						continue;
					}

				}
			}
		}
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num; j++)
				cout << D[i][j] << "  ";
			cout << endl;
		}
		cout << "_____________________________________" << endl;
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < num; j++)
				cout << S[i][j] << "  ";
			cout << endl;
		}
		int c, g;
		cout << "Enter Start : ";
		cin >> c;
		cout << "Enter distanation : ";
		cin >> g;
		if (c == g)
		{
			cout << "Shortest Path From " << c << " To " << g << " : " << c << "-->" << g;
			cout << "Weight : " << 0 << endl;
		}
		else {
			int start = c - 1;
			int End = g - 1;
			int shorthestWeight;
			shorthestWeight = D[start][End];
			if (shorthestWeight == 1000)
			{
				cout << "Can not Reach From " << c << " to " << g << endl;
			}
			else
			{
				queue<int> Path;
				Path.push(start);
				while (S[start][End] != End)
				{
					Path.push(S[start][End]);
					start = Path.back();

				}
				Path.push(End);

				cout << "Shortest Path From " << c << " To " << g << " : " << Path.front() + 1;
				Path.pop();
				while (!Path.empty())
				{
					cout << " --> " << Path.front() + 1;
					Path.pop();
				}
				cout << endl << "With weight : " << shorthestWeight << endl;
			}
		}
		//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
		for (int i = 0; i < num; i++)
		{
			delete[] D[i];
		}
		delete[] D;
		for (int i = 0; i < num; i++)
		{
			delete[] S[i];
		}
		delete[] S;
		cout << "\n\n Do You want to display another Map (y/n)? ";
		cin >> choose;
		system("CLS");
	} while (choose == 'y');
	AppStart();
}
//**********************************************************************************************
void Bellmanford() {
	Loading("Maps", 70);
	cout << "\n\t\t\t\t  " << "Welcome" << "\n\n\t\t";
	bool flag = false, flag2 = false, flag3 = false, flag4 = false;
	long long con = 1, max = 10000000, min = -1000000, loop = 0;
	int vertex1, vertix2, weight;
	char choose;
	multiset<pair<pair<int, int>, int>>Table; //carry two vertix and weight
	multiset<pair<pair<int, int>, int>>::iterator it;
	map<int, int>vertix_dis; //carry first vertix and weight
	map<int, int>::iterator vd;
	map<int, int>path; //carry destination
	map<int, int>::iterator ph;
	stack<int>route;
	char choose1;
	do {
		con = 1, max = 10000000, min = -1000000, loop = 0;
		cout << "Entre Vertix 1 and Vertix 2 and Weight between Them  " << endl;
		while (true) {
			flag = false, flag2 = false;
			cout << "\nCity 1 : ";
			cin >> vertex1;
			cout << "\nCity 2 : ";
			cin >> vertix2;
			cout << "\nweight :";
			cin >> weight;
			Table.insert(make_pair(make_pair(vertex1, vertix2), weight));
			cout << "\n****************************************************\n";
			cout << "Do you Want to continue, (Y/N)" << endl;
			choose = _getch();
			while (true) {
				if (choose == 'y' || choose == 'Y' || choose == 'n' || choose == 'N') {
					if (choose == 'y' || choose == 'Y') {
						flag = true;
						break;
					}
					else if (choose == 'n' || choose == 'N') {
						flag2 = true;
						break;
					}
				}
				cout << "Wrong Input" << endl;
				choose = _getch();
			}
			if (flag == true && flag2 == false)
				continue;
			else if (flag2 == true && flag == false)
				break;
		}
		for (it = Table.begin(); it != Table.end(); it++) {
			vertix_dis[it->first.first] = max;
			vertix_dis[it->first.second] = max;
			path[it->first.first] = min;
			path[it->first.second] = min;
		}
		int location, distination;
		cout << "Entre your location : ";
		cin >> location;
		cout << "Your distination : ";
		cin >> distination;
		vertix_dis[location] = 0;
		loop = vertix_dis.size();
		while ((loop - 1) > 0) {
			for (it = Table.begin(); it != Table.end(); it++) {
				if ((vertix_dis[it->first.first] + it->second) < vertix_dis[it->first.second]) {
					vertix_dis[it->first.second] = vertix_dis[it->first.first] + it->second;
					path[it->first.second] = it->first.first;
				}
			}
			loop--;
		}
		if (vertix_dis[distination] == 10000000) {
			cout << "Can't reach to this path" << endl;
			flag3 = true;
		}
		else {
			if (location == distination) {
				cout << "Shortest path from : " << location << " To " << distination << " is : " << vertix_dis[distination] << endl;
				cout << "you didn't move from your place" << endl;
				flag3 = true;
			}
			else {
				cout << "Shortest path from : " << location << " To " << distination << " is : " << vertix_dis[distination] << endl;
			}
		}
		if (!flag3) {
			long long count = path.size(), counter = 0;
			route.push(distination);
			while (path[route.top()] != location) {
				long long x = path[route.top()];
				route.push(x);
				if (counter == pow(count, (count - 1))) {
					cout << "can't reach to this path" << endl;
					flag4 = true;
					break;
				}
			}
			if (!flag4) {
				route.push(location);
				int size = route.size();
				cout << "shortest route from location to distination is : ";
				for (int i = 0; i < size; i++) {
					cout << route.top() << " ";
					route.pop();
				}
			}
			cout << endl;
		}
		cout << "\n\n Do You want to Make  another operation (y/n)? ";
		cin >> choose1;
		system("CLS");
	} while (choose == 'y');
	AppStart();
}
//*********************************************
string findParent(string city)
{
	if (parent[city] == city)
		return city;
	return parent[city] = findParent(parent[city]);
}
void join(string a, string b)
{
	a = findParent(a);
	b = findParent(b);
	if (a == b)
		return;
	parent[b] = a;
}
map <string, vector<pair<string, double> > >kruskalQs(int num_of_city)
{
	while (num_of_city--)
	{
		string a, b;
		double c;

		cout << "Insert City A, City B and the distance between them : ";
		cin >> a;
		cin >> b >> c;

		parent[a] = a;
		parent[b] = b;

		kruskalQ.push({ -1 * c,{ a, b } });
	}

	while (!kruskalQ.empty())
	{
		string cityA = kruskalQ.top().second.first;
		string cityB = kruskalQ.top().second.second;
		double dist = -1 * kruskalQ.top().first;
		kruskalQ.pop();

		if (findParent(cityA) == findParent(cityB))
			continue;

		graph[cityA].push_back({ cityB,dist });

		//graph[cityB].push_back({ cityA,dist });
		cout << cityA << ' ' << cityB << ' ' << dist << endl;

		join(cityA, cityB);
	}
	return graph;
}
void Kuriskal() {
	int NumOFCity;
	cout << "how many edges in graph :";
	cin >> NumOFCity;
	kruskalQs(NumOFCity);
}
