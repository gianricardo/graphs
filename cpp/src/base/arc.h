/*
 * arc.h
 *
 *  Created on: Apr 27, 2015
 *      Author: gian
 */

#ifndef ARC_H_
#define ARC_H_

#include "edge.h"

namespace graphlib {

template<class Tipo_Info_Arc>
class Arc: public Edge<Tipo_Info_Arc> {
    typedef Edge<Tipo_Info_Arc> base;
public:
    using base::v0;
    using base::v1;
    Arc(){
    }
    Arc(std::string from,std::string to) : Edge<Tipo_Info_Arc>(from, to) {
     }
    virtual ~Arc() {
    }
    //
    std::string from() const {
        return v0();
    }
    std::string to() const {
        return v1();
    }
    void from(std::string f){
        v0(f);
    }
    void to(std::string f){
        v1(f);
    }
};

} /* namespace graphlib */

#endif /* ARC_H_ */
