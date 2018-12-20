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
	getline(cin, mapName);
	fstream mapsNames("Mapsname.txt", ios::in | ios::out|ios::app);
	string line;
	while (mapsNames >> line)
		res.insert(line);

	do{
		if (res.find(mapName) != res.end())
			cout << "This name is alredy Exist." << endl;
		else {
			ofstream addName("Mapsname.txt", ios::out | ios::app);
			addName << mapName << endl;
			break;
		}
		cout << "Entre Map's Name" << endl;
		getline(cin, mapName);

	} while (true);
	mapsNames.close();
	cout << "How many Edges In the Graph :";
	cin >> NumOfEdge;
	ofstream mapInfo(mapName + ".txt", ios::out | ios::app);
	cout << "Enter: city1 Connected with City2 and Distance(Km) between them: \n";
	for (int i = 0; i < NumOfEdge; i++) {
		cout << "\nEnter Vertex Num " << i + 1 << " : ";
		cin.ignore(1000,'\n');  //to get a composite cities like (New cairo)
		getline(cin, City1);
		cout << "connected with ->";
		getline(cin, City2);
		cout << "Distance between them is :";
		cin >> Weight;
		stringstream ss;
		ss << Weight;
		string dis = ss.str();
		string concatenate = '#' + City1 + "#" + City2 + "#" +dis; // don't forget to conver again to interger
		mapInfo << concatenate << endl;
		mp[City1].push_back(Edge(City2, Weight));
		cout << "**********************\n";
	}
	mapInfo.close();
}

void Graph::putINmap(string City1, string City2, int Weight) { 
	mp[City1].push_back(Edge(City2, Weight));
}
map<string, vector<Edge>> Graph::GetMap() {
	return mp;
}

void  Graph::outMap(map<string, vector<Edge>> &map) { // this method is useless but leave it
	cout << "\n\n";
	for (itCity =mp.begin();itCity != mp.end(); itCity++) {
		cout << "Vertexes Connected to (" << itCity->first << "):: Are -> { \n";
		for ( itEdge = itCity->second.begin(); itEdge != itCity->second.end(); itEdge++)
			cout << "				< City : " << itEdge->GetVertex() << "   Weight " << itEdge->GetWeight() << " Km > ,\n";
		
		cout << "				}" << endl << endl;
		cout << "            _______________________________________________________\n";
	}
	map = mp;	
}

Graph::~Graph()
{
}
