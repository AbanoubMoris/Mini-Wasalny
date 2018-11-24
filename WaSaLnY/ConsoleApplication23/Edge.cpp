#include "Edge.h"
#include<string>
using namespace std;

Edge::Edge(string Vertex, double weight) {
	this->Vertex = Vertex;
	this->weight = weight;
}
string Edge::GetVertex() {
	return this->Vertex;
}
double Edge::GetWeight() {
	return this->weight;
}
