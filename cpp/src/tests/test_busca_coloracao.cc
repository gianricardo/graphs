/*
 * test_busca_coloracao.cc
 *
 *  Created on: Jun 12, 2015
 *      Author: gian
 */

#include "tests.h"
#include <iostream>
#include <iomanip>
#include "../base/graph.h"
#include "../base/colour.h"
#include "../algorithms/colouring_die.h"

void test_busca_cor(){
        graphlib::Graph<graphlib::Colour> grafo;
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
        std::cout << std::endl << std::endl;

        graphlib::Colouring_DIE cor;
        cor.execute(grafo);
        auto lv = grafo.vertices_list();
        for (auto ww : lv) {
            graphlib::Colour k;
            k = ww->info();
            std::cout << "Nome do vertice: " << ww->name() << " Cor: " << k.code() << std::endl;
        }
}

