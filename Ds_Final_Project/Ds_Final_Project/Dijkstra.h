#pragma once
#include<string>
#include<vector>
#include<map>
#include<stack>
#include"Functions.h"
#include"Edge.h"
using namespace std;

class table {
public:
	string city;
	bool visited = false;
	double weight = 10000000;
	string path = "-1";
};
class Dijkstra{
private:
	vector<table> MakeTable(map<string, vector<Edge>> mp);
	vector<table> dijkstra(map<string, vector<Edge>> mp, string source, string distenation);
	double CurrentMinimum(vector<table> x);
	int allVisited(vector<table> t);
public:
//	map<string, vector<Edge>> mp = outMap();
	stack<string> GetPath(map<string, vector<Edge>> mp, string source, string dest, double &distance);
};
