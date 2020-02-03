#include<iostream>
#include<list>
#include<iterator>

using namespace std;

// https://www.tutorialspoint.com/cplusplus-program-to-represent-graph-using-linked-list
/*
Program Name: Graph Dead End Finder
Programmer Name: Michael D. Schloss
Date: 12/4/19
Professor Name: John P. Baugh

Assumptions: Vertices must be positive integer values.
*/

// This will display the vertices which are connected
// and whether if it's a deadend, it will be labeled.
// No requirements
void display(list<int> adjacency[], int numVertices)
{
	int counter = 0;

	for (int i = 1; i <= numVertices; i++)
	{
		cout << i << " ---> ";
		list<int> ::iterator it;
		for (it = adjacency[i].begin(); it != adjacency[i].end(); ++it)
		{
				cout << *it << " ";
				counter++;
		}
		if (counter == 1)
		{
			cout << "     -Dead End";
		}
		cout << endl;
		counter = 0;
	}
}
// Connections displayed


// This will connect 2 vertices provided and create an edge.
// Requires: Inputs which follow the given prompt.
void add_edge(list<int> adjacency[], int v, int w)
{
	adjacency[v].push_back(w);
	adjacency[w].push_back(v);
}
// Edge(s) created


int main()
{
	int numVertices, numEdges, v1, v2;
	const int possibleVert = 5000; // You said (1 < n < 5 * 10^5) in the Input section


	cout << "How many locations are there: ";
	cin >> numVertices;
	list<int> adjacency[possibleVert];

	cout << "How many connections are there: ";
	cin >> numEdges;

	// The following loop simply calls the edge creater function
	for (int i = 0; i < numEdges; i++)
	{
		cout << "What is the 1st Vertex: ";
		cin >> v1;
		cout << "What is the 2nd Vertex: ";
		cin >> v2;
		add_edge(adjacency, v1, v2);
	}

	// This calls the display function
	display(adjacency, numVertices);

	cout << "Where there is only 1 number connected, there is a deadend." << endl;

	return 0;
}