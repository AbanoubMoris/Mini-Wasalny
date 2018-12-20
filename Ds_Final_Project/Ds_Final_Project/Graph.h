#pragma once
#include<iostream>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<vector>
#include"Edge.h"
using namespace std;
class Graph{

	int  NumOfEdge;
	string City1, City2;
	double Weight;
	string mapName;
	unordered_set<string> res;
	map<string, vector<Edge>>::iterator itCity;
	vector<Edge>::iterator itEdge;

public: map<string, vector<Edge>> mp;
public:
	Graph();
	void addMap();
	void putINmap(string City1, string City2, int Weight);
	map<string, vector<Edge>> GetMap();
    void outMap(map<string, vector<Edge>> &map);
	~Graph();
};
