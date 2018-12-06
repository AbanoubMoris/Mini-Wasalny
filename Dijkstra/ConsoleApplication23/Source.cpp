#include<iostream>
#include<map>
#include<unordered_map>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
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
	double min = 1000000;
	for (int z = 0; z < x.size(); z++) {
		if (x[z].visited == false && min > x[z].weight)
			min = x[z].weight;
	}
	return min;
}
vector<table> Dijkstra(map<string, vector<Edge>> mp , string source) {

	vector<table> x=MakeTable(mp);
	for (int i = 0; i < x.size(); i++) { //make source is visited
		if (x[i].city == source) {
			//x[i].visited = true;
			x[i].path = x[i].city;
			x[i].weight = 0;
		}
	}
	map<string, vector<Edge>>::iterator it = mp.begin();
	vector<Edge>::iterator E;
	//for (int i = 0; i < x.size(); i++) {
	double min = 0;
	int cnt = 0;
	int operations = 0;
	while (allVisited(x)<x.size()) {
		int  j = 0;
		for (j; j < x.size(); j++) {
			if (!x[j].visited) {
				if (x[j].weight == CurrentMinimum(x)) {
					it = mp.find(x[j].city);
					double min2 = 100000;
					for (E = it->second.begin(); E != it->second.end(); E++) {
						vector<table>::iterator TT = x.begin();
						double curwt = E->GetWeight();

						for (TT; TT != x.end(); TT++) {
							if (TT->city == E->GetVertex()) {
								//operations++;
								break;
							}
						}
						if (TT->weight > x[j].weight + curwt && !TT->visited) {
							TT->weight = curwt + x[j].weight;
							TT->path = x[j].city;


						}
						x[j].visited = true;
					}

				}

			}

		}
		//*************************
	}
	return x;
}
stack<string> GetPath(map<string, vector<Edge>> mp, string source , string dist) {
	vector<table> x = Dijkstra(mp, source);
	stack<string> s;
	string curDist = dist;
	int i = 0;
	s.push(dist);
	while (!s.empty() && s.top() != source) {
		if (x[i].city == curDist) {
			s.push(x[i].path);
			curDist = x[i].path;
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

	    stack<string> s = GetPath(mp, source, dist);
	    while (!s.empty()) {
	    	cout << s.top()<<" --> ";
	    	s.pop();
	    }

// all this comment is now on functions but leave it !

	//	vector<table> x = MakeTable(mp);
	//	for (int i = 0; i < x.size(); i++) { //make source is visited
	//		if (x[i].city == source) {
	//			//x[i].visited = true;
	//			x[i].path = x[i].city;
	//			x[i].weight = 0;
	//		}
	//	}
	//	map<string, vector<Edge>>::iterator it = mp.begin();
	//	vector<Edge>::iterator E;
	//	//for (int i = 0; i < x.size(); i++) {
	//	double min = 0;
	//	int cnt = 0;
	//
	//	int operations = 0;
	//
	//while (allVisited(x)<x.size()){
	//	int  j= 0;
	//	for (j ; j < x.size(); j++) {
	//		if (!x[j].visited) {
	//			if (x[j].weight == CurrentMinimum(x)) {
	//				it = mp.find(x[j].city);
	//				double min2 = 100000;
	//				for (E = it->second.begin(); E != it->second.end(); E++) {
	//					vector<table>::iterator TT = x.begin();
	//					double curwt=E->GetWeight();
	//
	//					for (TT; TT!=x.end(); TT++) { 
	//						if (TT->city == E->GetVertex()) {
	//							//operations++;
	//							break;
	//						}
	//					}
	//					if (TT->weight > x[j].weight + curwt && !TT->visited) {
	//						TT->weight = curwt + x[j].weight;
	//						TT->path = x[j].city;
	//
	//						
	//					}
	//					x[j].visited = true;
	//				}
	//
	//			}
	//
	//			}
	//		
	//	}
	//	//*************************
	//
	//
	//}   //    //

	cout << "\n";
	cout<<R"(
	  0
        / | \
	  |
         / \
Dijkstraaaaaaaaaaa3
		)";

	//for (int i = 0; i < x.size(); i++) {
	//	cout << x[i].city << " " << x[i].visited << " " << x[i].weight << " " << x[i].path;
	//	cout << endl;
	//}

	//cout << "\nNum of operations: " << operations << endl;
}




