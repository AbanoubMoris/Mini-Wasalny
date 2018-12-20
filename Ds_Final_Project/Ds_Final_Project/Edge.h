#pragma once
#include<iostream>
#include<string>
using namespace std;
class Edge{
	string Vertex; //city name
	double weight; //distance between 2 city
public:
	Edge(string, double);
	double GetWeight();
	string GetVertex();
};