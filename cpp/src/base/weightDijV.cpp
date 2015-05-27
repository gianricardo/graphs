/*
 * weightDijV.cpp
 *
 *  Created on: 27/05/2015
 *      Author: Wyk
 */

#include "weightDijV.h"

namespace graphlib {

WeightDijV::WeightDijV(bool visitado, double peso, double dist_origem):WeightDij(visitado,peso){
	_dist_origem = dist_origem;

}

WeightDijV::~WeightDijV() {
	// TODO Auto-generated destructor stub
}

void WeightDijV::dist_origem(double d){
	_dist_origem = d;
}

double WeightDijV::dist_origem(){
	return _dist_origem;
}

} /* namespace graphlib */
