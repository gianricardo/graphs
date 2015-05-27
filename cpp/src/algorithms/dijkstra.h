/*
 * dijkstra.h
 *
 *  Created on: 26/05/2015
 *      Author: Wyk
 */

#ifndef DIJKSTRA_H_
#define DIJKSTRA_H_

#include "../base/digraph.h"
#include "../base/weightDij.h"
#include "../base/weightDijV.h"

namespace graphlib {

class Dijkstra {
public:
	Dijkstra();
	virtual ~Dijkstra();
	double execute(Digraph<WeightDijV,WeightDij> someDigraph, std::string source, std::string end);
};

} /* namespace graphlib */

#endif /* DIJKSTRA_H_ */
