#include "Dijkstra.h"
//#include"Functions.h"

vector<table> Dijkstra::MakeTable(map<string, vector<Edge>> mp) {
	vector<table> tbl;
	table t;
	//mp = outMap();
	map<string, vector<Edge>>::iterator it = mp.begin();
	for (it; it != mp.end(); it++) {
		t.city = it->first;
		tbl.push_back(t);
		vector<Edge>::iterator i = it->second.begin();

		for (i; i != it->second.end(); i++) {
			if (mp.find(i->GetVertex()) != mp.end()) continue;
			else {
				bool found = false;
				for (int j = 0; j < tbl.size(); j++) {
					if (tbl[j].city == i->GetVertex()) {
						found = true;
					}
				}
				if (!found) {
					t.city = i->GetVertex();
					tbl.push_back(t);

				}
				//t.visited = true;
				//.path = it->first;
			}
		}
	}
	return tbl;
}
int Dijkstra::allVisited(vector<table> t) {
	double min = 1000000;
	//string MinCity;
	int cnt = 0;
	for (int i = 0; i < t.size(); i++) {
		if (t[i].visited == true) {
			cnt++;
		}
	}
	return cnt;
}
double Dijkstra::CurrentMinimum(vector<table> x) {
	double min = 1000000000;
	for (int z = 0; z < x.size(); z++) {
		if (x[z].visited == false && min > x[z].weight)
			min = x[z].weight;
	}
	return min;
}
vector<table> Dijkstra::dijkstra(map<string, vector<Edge>> mp, string source, string distenation) {
	//	mp = outMap();
	vector<table> Tbl = MakeTable(mp);
	for (int i = 0; i < Tbl.size(); i++) { //make source is visited
		if (Tbl[i].city == source) {
			//x[i].visited = true;
			Tbl[i].path = Tbl[i].city;
			Tbl[i].weight = 0;
			break;
		}
	}
	map<string, vector<Edge>>::iterator it = mp.begin();
	vector<Edge>::iterator E;

	int loop = 0;
	while (allVisited(Tbl) < Tbl.size() /* &&  !Distnation(Tbl,distenation)*/) {
		int  j = 0;
		for (j; j < Tbl.size(); j++) {
			if (!Tbl[j].visited) {
				if (Tbl[j].weight == CurrentMinimum(Tbl)) {
					it = mp.find(Tbl[j].city);  //make iterator points to the current minimum city
												//double min2 = 100000;
					if (it == mp.end()) {       //if not found on map key then make it visited
						Tbl[j].visited = true;
						break;
					}
					for (E = it->second.begin(); E != it->second.end(); E++) {  //E is an iterator on vector of edge
						double curwt = E->GetWeight();
						vector<table>::iterator TT = Tbl.begin();

						for (TT; TT != Tbl.end(); TT++) {    //this loop is just to make TT points to the current city
							if (TT->city == E->GetVertex()) {
								break;
							}
						}
						if (TT->weight > Tbl[j].weight + curwt && !TT->visited) {
							TT->weight = curwt + Tbl[j].weight;
							TT->path = Tbl[j].city;
						}
						Tbl[j].visited = true;
					}
				}
			}
		}
		loop++;
		if (loop == pow(Tbl.size(), 2)) break;

	}
	return Tbl;
}
stack<string> Dijkstra::GetPath(map<string, vector<Edge>> mp, string source, string dist, double &distance) {
	Loading("Path", 90);
	vector<table> Tbl = dijkstra(mp, source, dist);
	stack<string> Path;
	string curDist = dist;
	int i = 0;
	Path.push(dist);
	for (int i = 0; i < Tbl.size(); i++) {
		if (Tbl[i].city == dist) {
			distance = Tbl[i].weight;
			break;
		}
	}
	while (!Path.empty() && Path.top() != source) {
		if (Tbl[i].city == curDist) {
			Path.push(Tbl[i].path);
			curDist = Tbl[i].path;
		}
		if (Tbl[i].city == dist && Tbl[i].weight == 10000000) {  //if distnation not visited (Path can't be reached)
			stack<string> newstack;
			Path = newstack;
			break;
		}
		i++;
		if (i == Tbl.size())i = 0;

	}
	return Path;
}
