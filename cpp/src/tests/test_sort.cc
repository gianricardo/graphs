/*
 * teste-sort.cc
 *
 *  Created on: Jun 12, 2015
 *      Author: gian
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include "tests.h"
#include "../base/weight.h"
#include "../base/edge.h"

void test_sort(){
        typedef graphlib::Edge<graphlib::Weight> TEdge;
        std::vector<TEdge*> list_edges;
        list_edges.push_back(new TEdge("1", "2", graphlib::Weight(2)));
        list_edges.push_back(new TEdge("1", "2", graphlib::Weight(4)));
        list_edges.push_back(new TEdge("1", "2", graphlib::Weight(1)));
        for (TEdge* unit : list_edges) {
            std::cout << unit->info().value() << " - ";
        }
        std::cout << std::endl;
        //sort ordena apenas arrays e vectors.
        std::sort(list_edges.begin(), list_edges.end(), graphlib::Edge<graphlib::Weight>::compEdgeGreater);
        std::cout << std::endl;
        for (TEdge* unit : list_edges) {
            std::cout << unit->info().value() << " - ";
        }
        std::cout << std::endl;

}

