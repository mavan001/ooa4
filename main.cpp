#include <iostream>
#include "SFMLGraphVisualizer.h"
#include <fstream>
#include "Node.h"
#include <string>
#include <vector>
#include "MyException.h"
#include "tokenizer.h"


using namespace std;
string term[100];
string knotencin;
int auswahl;
string line;
string filename = "editable.txt";
bool knoten = false;
bool kanten = false;
bool repeat = true;
bool found = false;
bool similiarNode = false;
bool similiarEdge = false;


void fileEinlesen(string filename) {
	ifstream inputfile;
	inputfile.open(filename);
	if (inputfile.fail()) {
		cout << "Eingegebene Datei nicht gefunden. Es wird die Standartdatei verwendet"
			<< endl;
		filename = "editable.txt";
		inputfile.open(filename);
		filename = "editable.txt";
	}
		int count = 0;
		cout << endl;
		cout << filename << ":" << endl << endl;
		for (int i = 0; i < 100; ++i) term[i] = "";

		while (getline(inputfile, line)) {

			term[count] = line;
			cout << term[count] << endl;
			count++;

		}
		inputfile.close();
}


void knotenMethode() {
	string Node;
	cout << "Knoten: ";
	std::cin >> Node;
	bool nodeFound = false;
	for (int i = 0; i < 100; i++) {
		if (term[i] == Node) {
			cout << endl << "Knoten gefunden, wird geloescht.." << endl;
			nodeFound = true;
			ofstream buffer(filename, std::ios::trunc);
			for (int u = 0; u < i; u++) {
				buffer << term[u] << "\n";
			}
			for (int u = i + 1; u < 100; u++) {
				if (term[u] != "") { buffer << term[u] << "\n"; }
			}
			buffer.close();
		}
	}
	if (nodeFound == false) {
		cout << endl << "Knoten wird hinzugefuegt.." << endl;
		ofstream buffer(filename, std::ios::trunc);
		for (int u = 0; u < 100; u++) {
			if (term[u] != "") {
				buffer << term[u] << "\n";
				if (term[u] == "# Alle Knoten") {
					buffer << Node << "\n";
				}

			}
		}

		buffer.close();







	}



}
void gewichtAendern() {
	cout << "Geben Sie ihre Wunschkante mit neuem Gewicht ein, welches Sie veraendern wollen." << endl;

	string firstNode, secNode; 
	int Weight;
	cout << "Startknoten: ";
	std::cin >> firstNode;
	cout << "Endknoten: ";
	std::cin >> secNode;
	cout << "Neues Gewicht: ";
	std::cin >> Weight;
	string kompletteZeile = firstNode + " " + secNode;
	knoten, kanten = false;
	for (int i = 0; i < 100; i++) {
		if (term[i] == "# Alle Kanten") {
			knoten = false;
			kanten = true;
		}
		if (kanten == true && term[i] != "# Alle Kanten" && term[i] != "#ende") {
			string s = term[i];
			Tokenizer tok4(s, " ");
			string k[3];
			int t = 0;
			while (tok4.hasMoreTokens()) {

				k[t] = tok4.nextToken();
				t++;
			}
			s = k[0] + " " + k[1];
			if (kompletteZeile == s) {
				cout << endl << "Kante gefunden, Gewicht wird geaendert.." << endl;
				
					ofstream buffer(filename, std::ios::trunc);
					for (int u = 0; u < 100; u++) {
						if (term[u] != "") {	
							if (term[u] == k[0] + " " + k[1] + " " + k[2]) {
								buffer << kompletteZeile + " " + to_string(Weight) << "\n";
							}
							else {
								buffer << term[u] << "\n";
							}
						}
					}

					buffer.close();
				


			}
		}

	}
	
}

void kantenMethode() {
		
		string firstNode, secNode;
		int Weight;
		cout << "Startknoten: ";
		std::cin >> firstNode;
		cout << "Endknoten: ";
		std::cin >> secNode;
		cout << "Gewicht: ";
		bool edgeFound = false;
		std::cin >> Weight;
		string kompletteZeile = firstNode + " " + secNode + " " + to_string(Weight);

		for (int i = 0; i < 100; i++) {
			if (term[i] == kompletteZeile) {
				cout << endl << "Kante gefunden, wird geloescht.." << endl;
				edgeFound = true;
				ofstream buffer(filename, std::ios::trunc);
				for (int u = 0; u < i; u++) {
					buffer << term[u] << "\n";
				}
				for (int u = i + 1; u < 100; u++) {
					if (term[u] != "") { buffer << term[u] << "\n"; }
				}
				buffer.close();
			}
		}
		if (edgeFound == false) {
			cout << endl << "Kante wird hinzugefuegt.." << endl;
						ofstream buffer(filename, std::ios::trunc);
						for (int u = 0; u < 100; u++) {
							if (term[u] != "") {
									buffer << term[u] << "\n";
									if (term[u] == "# Alle Kanten") {
										buffer << kompletteZeile << "\n";
									}
								
							}
						}

						buffer.close();



					
				

			
		}

	

}

void allesLoeschen() {
	cout << endl << "Alle Knoten und Kanten werden bereinigt.." << endl;
	ofstream buffer(filename, std::ios::trunc);
	buffer << "# Alle Knoten" << endl << "# Alle Kanten" << endl << "#ende";

	buffer.close();
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

int main() {
	SFMLGraphVisualizer vis;
	//DiGraph graph;

	




	while (repeat == true) {
		system("CLS");
		fileEinlesen(filename);
		cout << endl << "-------------------------------------------------------" << endl << endl
			<< "Auswahlmoeglichkeiten:" << endl
			<< "[1] Knoten hinzufuegen oder entfernen" << endl //done
			<< "[2] Kante hinzufuegen oder loeschen" << endl //done
			<< "[3] Kantengewicht aendern" << endl //done
			<< "[4] Aktuellen Graphen in einer Datei speichern" << endl //Kanten checken damit keine duplikate, am besten immer neuen graph anlegen
			<< "[5] Anderen Graphen aus einer Textdatei laden" << endl
			<< "[6] Alle Knoten und Kanten loeschen" << endl //done
			<< "[7] Programm beenden" << endl //done
			<< endl << "Geben Sie eine Zahl ein: ";
		std::cin >> auswahl;

		switch (auswahl) {
		case 1:
		{cout << "Geben Sie einen Knoten ein den Sie hinzufuegen oder entfernen wollen.\n";
		
		knotenMethode();

		break; }
		case 2:
			cout << "Geben Sie eine Kante ein die Sie hinzufuegen oder entfernen wollen.\n";
			kantenMethode();
			break;
		case 3:
		{	gewichtAendern();
	
			break;
		}
		case 4:
		{
			DiGraph graph;
			for (int i = 0; i < 100; i++) {
				if (term[i] == "# Alle Knoten") {
					knoten = true;
					kanten = false;
				}
				if (term[i] == "# Alle Kanten") {
					knoten = false;
					kanten = true;
				}
				
				if (knoten == true && term[i] != "# Alle Knoten" && term[i] != "#ende") {

						graph.addNode(new Node(term[i], 0, 0));

					}
				if (kanten == true && term[i] != "# Alle Kanten" && term[i] != "#ende" && term[i] != "") {
					string s = term[i];
					Tokenizer tok(s, " ");
					string k[3];
					int i = 0;
					while (tok.hasMoreTokens()) {

						k[i] = tok.nextToken();
						i++;
					}

					try {
						graph.addEdge(k[0], k[1], atof(k[2].c_str()));
					}
					catch (MyException e) {
						cout << e.getMessage() << endl;
					}
				}
			}

				vis.dot(graph);
				break;
			}
		case 5:
		{cout << "Geben Sie den Dateinamen ein: ";
		std::cin >> filename;
		try {
			fileEinlesen(filename);
		}
		catch (MyException e) {
			cout << e.getMessage() << endl;
		}
		break; }
		case 6:
			allesLoeschen();
			break;
		case 7:
			repeat = false;

			break;
		default: repeat = true;
			}
			std::cin.get();
			std::cin.get();
		}

	
	return 0;
}