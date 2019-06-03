#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "Liste.h"

using namespace std;

class Edge;
class Node {
private:
	string _key;
	int _posX, _posY;
	Liste<Edge>* _edgeList;
public:
	Node(string key, int x, int y);
	string getKey(void);
	int getPositionX(void);
	int getPositionY(void);
	Liste<Edge> getEdges(void);
	void setKey(string newKey);
	void setPositionX(int x);
	void setPositionY(int y);
	void setNewEdge(Edge * edge);
};

class Edge {
private:
	float _weight;
	Node * _startNode, *_endNode;
public:
	Edge(float weight, Node *startNode, Node *endNode);
	float getWeight(void);
	Node *getStartNode(void);
	Node *getEndNode(void);
	void setWeight(float w);
	void setStartNode(Node * n);
	void setEndNode(Node * n);
};


#endif