/*
 * weight.cpp
 *
 *  Created on: 20/05/2015
 *      Author: Wyk
 */

#include "weight.h"

namespace graphlib {

Weight::Weight():_w(1) {

}

Weight::Weight(double value=1):_w(value) {

}

Weight::~Weight() {

}

double Weight::value(void)const{
	return _w;
}

void Weight::value(double value){
	_w = value;
}

}//namespace graphlib
