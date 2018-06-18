#pragma once
#include<list>
#include<iostream>
using std::ostream;

enum spectr {WHITE, GRAY, BLACK};

template<typename T>class Graph;

template<typename T>
class GraphNode
{
	friend class Graph<T>;
	
public:
	GraphNode(T val)
		:parent(nullptr), key(val), color(WHITE), distance(0)
	{}
	~GraphNode();
	std::list<GraphNode<T>*> adjacency;
	void addToList( GraphNode<T>*);
	
private:
	GraphNode<T> *parent;
	T key;
	spectr color;
	int distance;

	T getKey() { return key; }
};

template<typename T>
GraphNode<T>::~GraphNode()
{
	adjacency.clear();
}

template<typename T>
void GraphNode<T>::addToList( GraphNode<T> *node)
{
	adjacency.push_back(node);
}


