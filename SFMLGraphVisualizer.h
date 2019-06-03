#include <sstream>
#include <iostream>
#include "Node.h"
#include "DiGraph.h"
#include <fstream>

using namespace std;


class SFMLGraphVisualizer {
private:
public:

	SFMLGraphVisualizer() {
	}
	void dot(DiGraph &g) {

		cout << endl << "-------------------------------------------------------" << endl << endl
			<< "Graph.txt wird geschrieben:" << endl << endl;
		ofstream file("graph.txt", std::ios::trunc);
		string color[] = { "red", "blue", "green", "yellow" };
		Liste<Node > nodes = g.getNodes();
		cout << "digraph{" << "\n" << endl;
		file << "digraph{" << "\n" << endl;
		for (unsigned int i = 0; i < nodes.getListSize(); i++) {
			Node *node = nodes.getValueAtPos(i);
			int random_integer = rand() % 4;
			cout << "\t\"" << getString(*node) << "\"" << "    "<<"[color=" << color[random_integer] << "]" << endl;
			file << "\t\"" << getString(*node) << "\"" << "    "<< "[color=" << color[random_integer] << "]" << endl;
		}
		cout << "\n" << endl;
		file << "\n" << endl;
		for (unsigned int i = 0; i < nodes.getListSize(); i++) {
			Node *node = nodes.getValueAtPos(i);

			Liste<Edge > edges = g.getEdges(node->getKey());
			for (unsigned int j = 0; j < edges.getListSize(); j++) {
				Edge *edge = edges.getValueAtPos(j);
				cout << "\t\"" << getString(*node) << "\"" << "    -> "
					<< "\"" << getString3(*edge) << "\"" << "    " << "[label=" << getString2(*edge) << "];" << endl;
				file << "\t\"" << getString(*node) << "\"" << "    -> "
					<< "\"" << getString3(*edge) << "\"" << "    " << "[label=" << getString2(*edge) << "];" << endl;
			}
		}
		cout << "}" << endl;
		file << "}" << endl;
		file.close();
		
	}

	string getString(Node &node) {
		string key = node.getKey();

		return key;
	}
	float getString2(Edge &edge) {
		float key = edge.getWeight();

		return key;
	}
	string getString3(Edge &edge) {
		Node *node = edge.getEndNode();
		string key = getString(*node);
		return key;
	}
};