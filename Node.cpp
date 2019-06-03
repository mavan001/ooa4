#include "Node.h"

Node::Node(string key, int x, int y) {
	_key = key;
	_posX = x;
	_posY = y;
	_edgeList = new Liste<Edge>();
}

string Node::getKey(void) {
	return _key;
}
int Node::getPositionX(void) {
	return _posX;
}

int Node::getPositionY(void) {
	return _posY;
}

Liste<Edge> Node::getEdges(void) {
	return *_edgeList;
}

void Node::setKey(string newKey) {
	_key = newKey;
}
void Node::setPositionX(int x) {
	_posX = x;
}
void Node::setPositionY(int y) {
	_posY = y;
}
void Node::setNewEdge(Edge * edge) {
	_edgeList->insertNewEntry(edge);
}

Edge::Edge(float weight, Node *startNode, Node *endNode) {
	_weight = weight;
	_startNode = startNode;
	_endNode = endNode;
}

float Edge::getWeight(void) {
	return _weight;
}

Node *Edge::getStartNode(void) {
	return _startNode;
}

Node *Edge::getEndNode(void) {
	return _endNode;
}

void Edge::setWeight(float w) {
	_weight = w;
}
void Edge::setStartNode(Node * n) {
	_startNode = n;
}
void Edge::setEndNode(Node * n) {
	_endNode = n;
}