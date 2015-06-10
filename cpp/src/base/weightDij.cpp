/*
 * weightDij.cpp
 *
 *  Created on: 27/05/2015
 *      Author: Wyk
 */

#include "weightDij.h"

namespace graphlib {

WeightDij::WeightDij(bool visitado, double peso) {
	_visitado = visitado;
	_peso = peso;
}

WeightDij::~WeightDij() {
}

void WeightDij::visitado(bool v){
	_visitado = v;
}

bool WeightDij::visitado(){
	return _visitado;
}

void WeightDij::peso(double p){
	_peso = p;
}

double WeightDij::peso(){
	return _peso;
}


} /* namespace graphlib */
