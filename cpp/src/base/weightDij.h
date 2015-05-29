/*
 * weightDij.h
 *
 *  Created on: 27/05/2015
 *      Author: Wyk
 */

#ifndef WEIGHTDIJ_H_
#define WEIGHTDIJ_H_

namespace graphlib {

class WeightDij {
public:
	WeightDij(bool visitado, double peso);
	WeightDij()=default;
	virtual ~WeightDij();
	void visitado(bool v);
	bool visitado();
	void peso(double p);
	double peso();
private:
	bool _visitado;
	double _peso;
};

} /* namespace graphlib */

#endif /* WEIGHTDIJ_H_ */
