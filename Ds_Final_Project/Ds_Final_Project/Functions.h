#pragma once
#include<iostream>
#include<fstream>
#include"Graph.h"
#include<fstream>
#include"Shape.h"
#include<string>
#include<stdio.h>
#include<conio.h>
#include<cstring>
#include<cstringt.h>
void displayMaps();
void addGraph();
vector<string> displayGraph(string GraphName);
void deleteMap();

/*********** Abanoub ***********/
void EditGraph();
void DeleteEdge(string NodeName1,string NodeName2, vector<string> s, string fileName);
void DeleteNode(string NodeName,vector<string> , string fileName);
/*********** Abanoub ***********/
