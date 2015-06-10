/*
 * kruskal.cpp
 *
 *  Created on: 10/06/2015
 *      Author: Wyk
 */

#include "kruskal.h"
#include <algorithm>

namespace graphlib {

Kruskal::Kruskal() {

}

Kruskal::~Kruskal() {

}

std::list<Edge<WeightDij>*> Kruskal::execute(
		Graph<WeightDijV, WeightDij> someGraph) {
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
	std::unique(L.begin(), L.end());
	//TODO precisa ordenar edges em L de forma crescente por peso

	std::list<Edge<WeightDij>*> MST;
	long k = 0;
	Edge<WeightDij>* a;
	std::string v1, v2;
	while (k < (someGraph.number_vertices() - 1) && !L.empty()) {
		a = L.front();
		L.pop_front();
		v1 = a->v0();
		v2 = a->v1();
		if (C[v1] != C[v2]) {
			MST.push_back(a);
			double m1 = C[v1], m2 = C[v2];
			for (auto j : C) {
				if (j.second == m2) {
					j.second = m1;
				}
			}
			k++;
		}
	}
	return MST;
}

void quickSort(std::vector<Edge<WeightDij>*> valor, long esquerda, long direita) {
	long i, j;
	double x, y;
	i = esquerda;
	j = direita;
	x = valor[(esquerda + direita) / 2]->info().peso();

	while (i <= j) {
		while (valor[i]->info().peso() < x && i < direita) {
			i++;
		}
		while (valor[j]->info().peso() > x && j > esquerda) {
			j--;
		}
		if (i <= j) {
			y = valor[i]->info().peso();
			valor[i]->info().peso(valor[j]->info().peso());
			valor[j]->info().peso(y);
			i++;
			j--;
		}
	}
	if (j > esquerda) {
		quickSort(valor, esquerda, j);
	}
	if (i < direita) {
		quickSort(valor, i, direita);
	}
}

} /* namespace graphlib */
