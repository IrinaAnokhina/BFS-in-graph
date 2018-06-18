#pragma once
#include<iostream>
using std::ostream;
using std::cout;
#include<iterator>
#include<queue>
#include"GraphNode.h"

template<typename T>
class Graph
{
public:
	Graph(){};

	~Graph();
	void addNode( T );
	void printGraph() const;
	void createAdj();
	void BFS();
	//print vertexes on path from source
	void printPath(T);
private:
	std::list<GraphNode<T>*>my_graph;
	GraphNode<T>* search(T);
	void PrintPath(GraphNode<T> *, GraphNode<T>* );
};

template<typename T>
Graph<T>::~Graph()
{
	if (!my_graph.empty())
	{
		auto j = my_graph.begin();
		while (j != my_graph.end())
		{
			auto temp = j;
			++j;
			delete *temp;
		}
	}
}

template<typename T>
void Graph<T>::addNode( T key)
{
	GraphNode<T> *newNode = new GraphNode<T>(key);
	my_graph.push_back(newNode);
}

template<typename T>
void Graph<T>::printGraph() const
{
	if (!(my_graph.empty()))
	{
		for (auto j : my_graph)
			cout << j->getKey() << " ";
	std::cout << std::endl;
	}
}

template<typename T>
GraphNode<T>* Graph<T>::search(T val)
{
	if (!my_graph.empty())
	{
		for (auto j : my_graph)
		{
			if (j->getKey() == val)
				return j;
		}
	}
	return nullptr;
}

template<typename T>
void Graph<T>::createAdj()
{
	T val{};
	T end{};
	char end_ch = '#';
	int end_i = -1;
	if(std::is_same<char, T>::value)
		end = end_ch;
	else
		end = end_i;
	cout << "Please, enter a -1, when finish to enter an adjacency list"
		 << " of current vertex, if your graph witn integer"
		<< " data and '#' if your graph with character-data\n";
	if (!(my_graph.empty()))
	{
		for (auto j : my_graph)
		{
			val = 0;
			cout << "Enter adjacency vertexes for vertex " << j->getKey() << ":\n";
			while (val != end)
			{
				std::cin >> val;
				GraphNode<T>* found = search(val);
				if (found != nullptr)
					j->addToList(found);
			}
		}
	}
}

template<typename T>
void Graph<T>::BFS()
{
	if (!my_graph.empty())
	{
		auto s = my_graph.begin();
		(*s)->color = GRAY;
		std::queue<GraphNode<T>*> Q;
		Q.push(*s);
		
		while (!Q.empty())
		{
			GraphNode<T> *cur = Q.front();
			Q.pop();
			for (auto j : cur->adjacency)
			{
				if (j->color == WHITE)
				{
					j->color = GRAY;
					j->distance += 1;
					j->parent = cur;
					Q.push(j);
				}
			}
			cur->color = BLACK;
			cout << cur->getKey() << " ";
		}
	}
}

template<typename T>
void Graph<T>::printPath(T key)
{
	GraphNode<T>* found = search(key);
	if (found != nullptr)
	{
		PrintPath(my_graph.front(), found);
	}
}

template<typename T>
void Graph<T>::PrintPath(GraphNode<T>* root, GraphNode<T>* node)
{
	if (node == root)
		cout << root->getKey() << " ";
	else if (node->parent == nullptr)
		cout << "There is no way\n";
	else
	{
		PrintPath(root, node->parent);
		cout << node->getKey() << " ";
	}
}