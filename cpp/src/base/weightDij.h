/*
 * weightDij.h
 *
 *  Created on: 27/05/2015
 *      Author: Wyk
 */

#ifndef WEIGHTDIJ_H_
#define WEIGHTDIJ_H_

#include "weight.h"

namespace graphlib {

class WeightDij : public Weight {
public:
	WeightDij(double peso,bool visitado=false):Weight(peso) {
	    _visitado = visitado;
	}
	WeightDij():Weight(1),_visitado(false){}
	virtual ~WeightDij();
	void visitado(bool v);
	bool visitado();
private:
	bool _visitado;
};

} /* namespace graphlib */

#endif /* WEIGHTDIJ_H_ */
