/*
 * test-kruskal.cc
 *
 *  Created on: Jun 12, 2015
 *      Author: gian
 */

#include "tests.h"
#include <iostream>
#include <iomanip>
#include "../base/graph.h"
#include "../base/weightDij.h"
#include "../base/weightDijV.h"
#include "../algorithms/kruskal.h"

void test_kruskal(){
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
}

