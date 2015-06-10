/*
 * programa1.cc
 *
 *  Created on: Apr 24, 2015
 *      Author: gian
 */

#include "base/graph.h"
#include <iostream>
#include <iomanip>
#include <functional>
#include "algorithms/colouring_die.h"
#include "base/colour.h"
#include "base/weight.h"

using namespace std;

int main(int argc, char **argv) {
	graphlib::Graph<graphlib::Colour> grafo;
	typedef graphlib::Edge<graphlib::Weight> TEdge;
	list<TEdge*> list_edges;
	list_edges.push_back(new TEdge("1", "2", graphlib::Weight(2)));
	list_edges.push_back(new TEdge("1", "2", graphlib::Weight(4)));
	list_edges.push_back(new TEdge("1", "2", graphlib::Weight(1)));
	for (TEdge* unit : list_edges) {
		cout << unit->info().value() << " - ";
	}
	cout << endl;
	list_edges.sort(std::less<TEdge*>());
	for (TEdge* unit : list_edges) {
		cout << unit->info().value() << " - ";
	}
	cout << endl;
	return 0;
	grafo.add_edge("1", "2");
	grafo.add_edge("1", "1");
	grafo.add_edge("3", "2");
	grafo.add_edge("2", "3");
	grafo.erase_edge("4", "2");
	std::cout << "Grafo\n";
	grafo.print(std::cout);
	auto t = grafo.depthFirst("3");
	for (auto v : t) {
		std::cout << std::setw(4) << v;
	}
	std::cout << std::endl;
	auto tt = grafo.breadthFirst("2");
	for (auto v : tt) {
		std::cout << std::setw(4) << v;
	}
	cout << endl << endl;

	graphlib::Colouring_DIE cor;
	cor.execute(grafo);
	auto lv = grafo.vertices_list();
	for (auto ww : lv) {
		graphlib::Colour k;
		k = ww->info();
		cout << "Nome do vertice: " << ww->name() << " Cor: " << k.code()
				<< endl;
	}

	return 0;
}

