/*
 * kruskal.h
 *
 *  Created on: 10/06/2015
 *      Author: Wyk
 */

#ifndef KRUSKAL_H_
#define KRUSKAL_H_

#include "../base/digraph.h"
#include "../base/weightDij.h"
#include "../base/weightDijV.h"

namespace graphlib {

class Kruskal {
public:
	Kruskal();
	virtual ~Kruskal();
	std::list<Edge<WeightDij>*> execute(Graph<WeightDijV,WeightDij> someGraph);
};

} /* namespace graphlib */

#endif /* KRUSKAL_H_ */
