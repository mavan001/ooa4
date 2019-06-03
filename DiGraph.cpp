#include <iostream>
#include "Liste.h"
#include "Node.h"
#include "DiGraph.h"


DiGraph::DiGraph() {
	_nodeList = Liste<Node>();
}

void DiGraph::addNode(Node *node) {
	_nodeList.insertNewEntry(node);
	
}
void DiGraph::addEdge(string key1, string key2, float weight) {
	Node *startNode = getNodeAdress(key1);
	Node *endNode = getNodeAdress(key2);
	if (startNode != endNode)
		startNode->setNewEdge(new Edge(weight, startNode, endNode));
}

Liste<Node> DiGraph::getNeighbours(string key) {
	Liste<Node> resultList;
	Liste<Edge> neighboursList;
	neighboursList = getNodeAdress(key)->getEdges();

	for (int i = 0; i < neighboursList.getListSize(); i++) {
		resultList.insertNewEntry(neighboursList.getValueAtPos(i)->getEndNode());
	}

	return resultList;
}


Liste <Edge> DiGraph::getEdges(string key) {
	for (int i = 0; i < _nodeList.getListSize(); i++) {
		if (key == _nodeList.getValueAtPos(i)->getKey()) {
			return _nodeList.getValueAtPos(i)->getEdges();
		}
	}
}

Liste <Node> DiGraph::getNodes(void) {
	return _nodeList;
}

Node* DiGraph::getNodeAdress(string key) {
	for (int i = 0; i < _nodeList.getListSize(); i++) {
		if (key == _nodeList.getValueAtPos(i)->getKey()) {
			return _nodeList.getValueAtPos(i);
		}
	}
}