/*
 * weight.h
 *
 *  Created on: 20/05/2015
 *      Author: Wyk
 */

#ifndef WEIGHT_H_
#define WEIGHT_H_
#include <iostream>
namespace graphlib {

class Weight {
public:
    Weight();
    Weight(double value);
    virtual ~Weight();
    void value(double value);
    double value(void) const;
    bool operator<(const Weight& o_w) {
        return _w < o_w.value();
    }
    bool operator>(const Weight& o_w) {
//        std::cout << "111";
        return _w > o_w.value();
    }
    Weight& operator*(){
        return *this;
    }

private:
    double _w;
};

} //namespace graphlib
#endif /* WEIGHT_H_ */
