/*
 * kruskal.cpp
 *
 *  Created on: 10/06/2015
 *      Author: Wyk
 */

#include "kruskal.h"
#include <algorithm>
#include "../base/comparators.h"

namespace graphlib {

Kruskal::Kruskal() {

}

Kruskal::~Kruskal() {

}

std::list<Edge<WeightDij>*> Kruskal::execute(Graph<WeightDijV, WeightDij> someGraph) {
    std::map<std::string, double> C;
    double i = 1;
    for (auto position : someGraph.vertices()) {
        C[position.second->name()] = i;
        i++;
    }

    std::vector<Edge<WeightDij>*> L;
    for (auto vert : someGraph.vertices_list()) {
        for (auto edg : vert->list_edges()) {
            L.push_back(edg);
        }
    }
    std::sort(L.begin(), L.end());
    auto it = std::unique(L.begin(), L.end());
    L.resize(std::distance(L.begin(), it));
    //DONE precisa ordenar edges em L de forma crescente por peso
    std::sort(L.begin(), L.end(), Edge<WeightDij>::compEdgeGreater);
//    for (auto edge : L) {
//        std::cout << edge->v0() << " <-> " << edge->v1() << " : " << edge->info().value() << std::endl;
//    }

    std::list<Edge<WeightDij>*> MST;
    long k = 0;
    Edge<WeightDij>* a;
    std::string v1, v2;
    while (k < (someGraph.number_vertices() - 1) && !L.empty()) {
        a = L.back();
        L.pop_back();
        v1 = a->v0();
        v2 = a->v1();
        if (C[v1] != C[v2]) {
            MST.push_back(a);
            double m1 = C[v1], m2 = C[v2];
            for (auto j : C) {
                if (j.second == m2) {
                    C[j.first] = m1;
                }
            }
            k++;
        }
//        for (auto jj : C) {
//            std::cout << jj.first << "[" << jj.second << "]";
//        }
//        std::cout << std::endl;
    }
    return MST;
}

} /* namespace graphlib */
