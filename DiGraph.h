#ifndef DIGRAPH_H
#define DIGRAPH_H

#include <iostream>
#include "Node.h"
#include "Liste.h"

using namespace std;


class DiGraph {
private:
	Liste<Node> _nodeList;
	Node *getNodeAdress(string nodeKey);
public:
	DiGraph();
	void addNode(Node * node);
	void addEdge(string key1, string key2, float weight);
	Liste<Node> getNeighbours(string key);
	Liste<Edge> getEdges(string key);
	Liste<Node> getNodes();
};


#endif