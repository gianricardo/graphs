/*
 * colouring_die.h
 *
 *  Created on: May 6, 2015
 *      Author: gian
 */

#ifndef COLOURING_DIE_H_
#define COLOURING_DIE_H_

#include "colour.h"
#include "graph.h"


namespace graphlib {


class Colouring_DIE {
public:
	Colouring_DIE();
	virtual ~Colouring_DIE();
	void execute(Graph<Colour> aGraph);
};

} /* namespace graphlib */

#endif /* COLOURING_DIE_H_ */
