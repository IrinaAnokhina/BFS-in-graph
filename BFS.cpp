#include<iostream>
#include"Graph.h"
#include"vld.h"

int main()
{
	Graph<int> g;
	for (int i = 0; i < 8; i++)
		g.addNode(1 + i);
	
	g.printGraph();
	g.createAdj();
	g.BFS();
	cout << "Path of what vertex you want to find?\n";
	int vert;
	std::cin >> vert;
	g.printPath(vert);
}