/*
 * weightDijV.h
 *
 *  Created on: 27/05/2015
 *      Author: Wyk
 */

#include "weightDij.h"

#ifndef WEIGHTDIJV_H_
#define WEIGHTDIJV_H_

namespace graphlib {

class WeightDijV : public WeightDij{
public:
	WeightDijV(bool visitado, double peso, double dist_origem);
	WeightDijV()=default;
	virtual ~WeightDijV();
	void dist_origem(double d);
	double dist_origem();
private:
	double _dist_origem;
};

} /* namespace graphlib */

#endif /* WEIGHTDIJV_H_ */
