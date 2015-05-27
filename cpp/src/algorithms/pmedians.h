/*
 * pmedians.h
 *
 *  Created on: 20/05/2015
 *      Author: Wyk
 */

#ifndef PMEDIANS_H_
#define PMEDIANS_H_

#include "../base/graph.h"


namespace graphlib {

class P_medians {
public:
	P_medians();
	virtual ~P_medians();
	void execute(Digraph<Weight> someDigraph, int med_number);
private:
	double transmission(std::list<Vertex<Weight>> set_S);
	double min_trans(Vertex<Weight>x, std::list<Vertex<Weight>> set_S);
};

} /*namespace graphlib /*

#endif /* PMEDIANS_H_ */
