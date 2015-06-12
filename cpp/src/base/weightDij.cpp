/*
 * weightDij.cpp
 *
 *  Created on: 27/05/2015
 *      Author: Wyk
 */

#include "weightDij.h"

namespace graphlib {

//WeightDij::WeightDij( double peso,bool visitado=false) :Weight(peso) {
//	_visitado = visitado;
//}

WeightDij::~WeightDij() {
}

void WeightDij::visitado(bool v){
	_visitado = v;
}

bool WeightDij::visitado(){
	return _visitado;
}

} /* namespace graphlib */
