#pragma once
#include<iostream>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<vector>
#include"Edge.h"
using namespace std;
class Graph
{
	int  NumOfCity;
	string City1, City2;
	double Weight;
	unordered_set<string> res;
	map<string, vector<Edge>>::iterator it;
	vector<Edge>::iterator i;
	string name;

public: map<string, vector<Edge>> mp;
public:
	Graph();
	void addMap();
	void putINmap(string A, string B, int c);
	map<string, vector<Edge>> GetMap();
	void outMap(map<string, vector<Edge>> &map);
	~Graph();
};

