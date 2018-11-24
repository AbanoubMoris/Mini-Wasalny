#include<string>
using namespace std;
class Edge
{
private:
	string Vertex; //city name
	double weight; //distance between 2 city
public:
	Edge(string, double);
	double GetWeight();
	string GetVertex();
};

