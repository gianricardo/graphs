/*
 * colour.h
 *
 *  Created on: May 6, 2015
 *      Author: gian
 */

#ifndef COLOUR_H_
#define COLOUR_H_

namespace graphlib {

class Colour {
public:
	Colour();
	Colour(long code);
	virtual ~Colour();
	void code(long code);
	long code(void)const;
private:
	long _colour_code;
};

} /* namespace graphlib */

#endif /* COLOUR_H_ */
