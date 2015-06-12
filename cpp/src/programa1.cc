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
#include <algorithm>
#include "algorithms/colouring_die.h"
#include "base/colour.h"
#include "base/weight.h"
#include "base/comparators.h"
#include "base/weightDij.h"
#include "base/weightDijV.h"
#include "algorithms/kruskal.h"

using namespace std;

int main(int argc, char **argv) {
    graphlib::Graph<graphlib::WeightDijV, graphlib::WeightDij> grafolivro("G - pg. 69 - livro do boaventura");
    typedef graphlib::WeightDij W;
    grafolivro.add_edge("1","2",*(new W(4)));
    grafolivro.add_edge("1","6",*(new W(5)));
    grafolivro.add_edge("2","6",*(new W(3)));
    grafolivro.add_edge("6","7",*(new W(7)));
    grafolivro.add_edge("2","3",*(new W(7)));
    grafolivro.add_edge("3","4",*(new W(5)));
    grafolivro.add_edge("3","7",*(new W(6)));
    grafolivro.add_edge("6","9",*(new W(5)));
    grafolivro.add_edge("4","5",*(new W(3)));
    grafolivro.add_edge("7","5",*(new W(2)));
    grafolivro.add_edge("7","8",*(new W(6)));
    grafolivro.add_edge("5","8",*(new W(4)));
    grafolivro.add_edge("9","8",*(new W(8)));

    graphlib::Kruskal k;

    auto arv_min = k.execute(grafolivro);
    for (auto edge:arv_min){
        std::cout << edge->v0() << " <-> " << edge->v1() << " : " << edge->info().value() <<std::endl;
    }

    return 0;
    //testa ordenação
//    graphlib::Graph<graphlib::Colour> grafo;
//    typedef graphlib::Edge<graphlib::Weight> TEdge;
//    vector<TEdge*> list_edges;
//    list_edges.push_back(new TEdge("1", "2", graphlib::Weight(2)));
//    list_edges.push_back(new TEdge("1", "2", graphlib::Weight(4)));
//    list_edges.push_back(new TEdge("1", "2", graphlib::Weight(1)));
//    for (TEdge* unit : list_edges) {
//        cout << unit->info().value() << " - ";
//    }
//    cout << endl;
//    //sort ordena apenas arrays e vectors.
//    std::sort(list_edges.begin(), list_edges.end(), graphlib::CompEdge<graphlib::Weight>::compEdgeGreater);
//    cout << endl;
//    for (TEdge* unit : list_edges) {
//        cout << unit->info().value() << " - ";
//    }
//    cout << endl;
//    return 0;
//    grafo.add_edge("1", "2");
//    grafo.add_edge("1", "1");
//    grafo.add_edge("3", "2");
//    grafo.add_edge("2", "3");
//    grafo.erase_edge("4", "2");
//    std::cout << "Grafo\n";
//    grafo.print(std::cout);
//    auto t = grafo.depthFirst("3");
//    for (auto v : t) {
//        std::cout << std::setw(4) << v;
//    }
//    std::cout << std::endl;
//    auto tt = grafo.breadthFirst("2");
//    for (auto v : tt) {
//        std::cout << std::setw(4) << v;
//    }
//    cout << endl << endl;
//
//    graphlib::Colouring_DIE cor;
//    cor.execute(grafo);
//    auto lv = grafo.vertices_list();
//    for (auto ww : lv) {
//        graphlib::Colour k;
//        k = ww->info();
//        cout << "Nome do vertice: " << ww->name() << " Cor: " << k.code() << endl;
//    }
//
//    return 0;
}

