/*
 * weight.h
 *
 *  Created on: 20/05/2015
 *      Author: Wyk
 */

#ifndef WEIGHT_H_
#define WEIGHT_H_

namespace graphlib {

class Weight {
public:
	Weight();
	Weight(double value);
	virtual ~Weight();
	void value(double value);
	double value(void)const;
private:
	double _w;
};

} //namespace graphlib
#endif /* WEIGHT_H_ */
