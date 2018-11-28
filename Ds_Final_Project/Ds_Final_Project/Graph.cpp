#include "Graph.h"
#include<fstream>
#include<sstream>
Graph::Graph()
{
}
void Graph::addMap() {
	/*Note:
	you shoud put path to location you want to save files and put double back slash '\\' instead single slash '\'
	*/
	cout << "Entre Map's Name" << endl;
	getline(cin, name);
	fstream mapsNames("Mapsname.txt", ios::in | ios::out|ios::app);
	string line;
	while (mapsNames >> line)
	{
		res.insert(line);
	}
	do
	{

		if (res.find(name) != res.end())
			cout << "This name is alredy Exist." << endl;
		else {
			ofstream addName("Mapsname.txt", ios::out | ios::app);
			addName << name << endl;
			break;
		}
		cout << "Entre Map's Name" << endl;
		getline(cin, name);

	} while (true);
	mapsNames.close();
	cout << "How many Edges In the Graph :";
	cin >> NumOfCity;
	ofstream mapInfo(name + ".txt", ios::out | ios::app);
	cout << "Enter-> city1 Connected with City2 and Distance(Km) between them,: \n";
	for (int i = 0; i < NumOfCity; i++) {
		//cout << "        ";
		cout << "\nEnter Vertex Num " << i + 1 << " : ";
		cin.ignore(1000,'\n');  //to get a composite cities like ( New cairo )
		getline(cin, City1);
		cout << "connected with ->";
		getline(cin, City2);
		cout << "their weght (distance between them) is :";
		cin >> Weight;
		stringstream ss;
		ss << Weight;
		string dis = ss.str();
		string concatinate = '#' + City1 + "#" + City2 + "#" +dis;// don't forget to conver again to interger
		mapInfo << concatinate << endl;
		mp[City1].push_back(Edge(City2, Weight));
		cout << "**********************\n";
	}
	mapInfo.close();
}
void Graph::putINmap(string A, string B, int c) { 
	mp[A].push_back(Edge(B, c));
}

void Graph::outMap() { // this method is useless but leave it
	cout << "\n\n";
	for (it =mp.begin();it != mp.end(); it++) {
		cout << "Vertexes Connected to " << it->first << ":: Are -> ";
		for ( i = it->second.begin(); i != it->second.end(); i++) {
			cout << "< City : " << i->GetVertex() << "   Weight " << i->GetWeight() << " Km >";
		}
		cout << endl;
	}
}

Graph::~Graph()
{
}
