#include<iostream>
#include<map>
#include<unordered_map>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include <algorithm>
#include"Edge.h"
using namespace std;

struct table {
	string city;
	bool visited = false;
	double weight = 10000000;
	string path = "-1";
};

vector<table> MakeTable(map<string,vector<Edge>> mp) {
	vector<table> V;
	table t;
	map<string, vector<Edge>>::iterator it = mp.begin();
	for (it; it != mp.end(); it++) {
		t.city = it->first;
		V.push_back(t);
		vector<Edge>::iterator i = it->second.begin();
		for (i; i != it->second.end(); i++) {
			if (mp.find(i->GetVertex()) != mp.end()) continue;
			else {
				bool found = false;
				for (int j = 0; j < V.size(); j++) {
					if (V[j].city == i->GetVertex()) {
						found = true;
					}
				}
				if (!found) {
				t.city = i->GetVertex();
				V.push_back(t);

				}
				//t.visited = true;
				//.path = it->first;
			}
		}
	}
	return V;
}
int allVisited(vector<table> t) {
	double min = 1000000;
	//string MinCity;
	int cnt = 0;
	for (int i = 0; i < t.size(); i++) {
		if (t[i].visited==true) {
			cnt++;
		}
	}
	return cnt;
}
double CurrentMinimum(vector<table> x) {
	double min = 1000000000;
	for (int z = 0; z < x.size(); z++) {
		if (x[z].visited == false && min > x[z].weight)
			min = x[z].weight;
	}
	return min;
}
bool Distnation(vector<table> x , string dist ) {
	for (int i = 0; i < x.size(); i++) {
		if (x[i].visited == false && x[i].city==dist) {
			return false;
		}
	}
	return true;
}

vector<table> Dijkstra(map<string, vector<Edge>> mp , string source , string distenation) {

	vector<table> Tbl=MakeTable(mp);
	for (int i = 0; i < Tbl.size(); i++) { //make source is visited
		if (Tbl[i].city == source) {
			//x[i].visited = true;
			Tbl[i].path = Tbl[i].city;
			Tbl[i].weight = 0;
		}
	}
	map<string, vector<Edge>>::iterator it = mp.begin();
	vector<Edge>::iterator E;
	//for (int i = 0; i < x.size(); i++) {
	double min = 0;
	int loop = 0;
	while (allVisited(Tbl) < Tbl.size() /* &&  !Distnation(Tbl,distenation)*/ ) {
		int  j = 0;

		for (j; j < Tbl.size(); j++) {
			if (!Tbl[j].visited) {
				if (Tbl[j].weight == CurrentMinimum(Tbl)) {
					it = mp.find(Tbl[j].city);
					double min2 = 100000;
					if (it == mp.end()) {
					Tbl[j].visited = true;
					break;
					}
						for (E = it->second.begin(); E != it->second.end(); E++) {
							double curwt = E->GetWeight();
							vector<table>::iterator TT = Tbl.begin();

							for (TT; TT != Tbl.end(); TT++) {
								if (TT->city == E->GetVertex()) {
									//operations++;
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

stack<string> GetPath(map<string, vector<Edge>> mp, string source , string dist , double &distance) {
	vector<table> x = Dijkstra(mp, source ,dist);
	stack<string> s;
	string curDist = dist;
	int i = 0;
	s.push(dist);
	for (int i = 0l; i < x.size(); i++) {
		if (x[i].city == dist) {
		distance = x[i].weight;
		break;
		}
	}
	while (!s.empty() && s.top() != source) {
		if (x[i].city == curDist) {
			s.push(x[i].path);
			curDist = x[i].path;
		}
		if (x[i].city == dist && x[i].weight == 10000000) {
			stack<string> newstack;
			s = newstack;
			break;
		}
		i++;
		if (i == x.size())i = 0;

	}
	return s;
}


void main() {
	cout << R"(
                          	    	   /Z\
                                          /   \
                                         10    2
                                        /       \
                                       b----1----x
                                      / \       /
                                     3   4     8
                                    /     \   /
                                  a----2---c / 
)";
	/*
	/Z\
	/   \
	10    2
	/       \
	b----1----x
	/ \       /
	3   4     8
	/     \   /
	a----2---c /

test case (copy & paste)

	14
	a b 3
	a c 2
	b a 3
	b c 4
	c a 2
	c b 4
	b x 1
	x b 1
	c x 8
	x c 8
	x z 2
	z x 2
	b z 10
	z b 10
	a z
//************another test*************
	3
	v a 5
	a z 10
	x z 2
	x z

	/*******************
	

	*/
		map<string, vector<Edge>> mp;
		cout << "How many Edges In the Graph :";

		int  NumOfCity;
		string City1, City2;
		double weight;

		cin >> NumOfCity;

		cout << "Enter-> city1 Connected with City2 and Distance(Km) between them,: \n";
		for (int i = 0; i < NumOfCity; i++) {
			//cout << "        ";
		//	cout << "\nEnter Vertex Num " << i+1<<" : ";
			cin >> City1;
			//cout << "connected with ->";
			cin >> City2;
			//cout << "their weght (distance between them) is :";
			cin >> weight;
			//cout << "**********************";
			mp[City1].push_back(Edge(City2, weight));
		}
		//output the graph
		cout << "get shortest path  :";
		string source, dist;
		cin >> source >> dist;
		double distance = 0;
	    stack<string> s = GetPath(mp, source, dist,distance);
		if (!s.empty()) {
			while (!s.empty()) {
				cout << s.top() << " --> ";
				s.pop();
			}
			cout << distance << " Km";
		}
		else cout << "path can't be reached !:(\n";
}




