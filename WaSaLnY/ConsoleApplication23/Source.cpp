#include<iostream>
#include<map>
#include<unordered_map>
#include<string>
#include<vector>
#include"Edge.h"
using namespace std;


void main() {

	unordered_map<string, vector<Edge>> mp;
	cout << "How many Edges In the Graph :";

	int  NumOfCity; 
	string City1,City2;
	double weight;

	cin >> NumOfCity;

	cout << "Enter-> city1 Connected with City2 and Distance(Km) between them,: \n";
	for (int i = 0; i < NumOfCity; i++) {
		//cout << "        ";
		cout << "\nEnter Vertex Num " << i+1<<" : ";
		cin >> City1;
		cout << "connected with ->";
		cin >> City2;
		cout << "their weght (distance between them) is :";
		cin>> weight;
		cout << "**********************";
		mp[City1].push_back(Edge(City2,weight));
	}
	//output the graph
	cout << "\n\n";
	unordered_map<string, vector<Edge>>::iterator it=mp.begin();
	for (it; it != mp.end(); it++) {
		cout <<"Vertexes Connected to "<< it->first << ":: Are -> ";
		for (vector<Edge>::iterator i = it->second.begin(); i!=it->second.end() ; i++) {
			cout <<"< City : " << i->GetVertex() << "   Weight " << i->GetWeight() <<" Km >";
		}
		cout << endl;
	}

}