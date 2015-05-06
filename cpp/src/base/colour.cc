/*
 * colour.cc
 *
 *  Created on: May 6, 2015
 *      Author: gian
 */

#include "colour.h"

namespace graphlib {

Colour::Colour():_colour_code(0) {

}

Colour::Colour(long code):_colour_code(code){

}

Colour::~Colour() {
}

long Colour::code(void)const{
	return _colour_code;
}

void Colour::code(long code){
	_colour_code = code;
}

} /* namespace graphlib */
