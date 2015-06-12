/*
 * comparators.h
 *
 *  Created on: Jun 12, 2015
 *      Author: gian
 */

#ifndef COMPARATORS_H_
#define COMPARATORS_H_

#include "weight.h"
#include "edge.h"
#include <type_traits>

namespace graphlib {
template<class TWeight>
class CompEdge {
public:
    static bool compEdge(const Edge<TWeight>* lhs, const Edge<TWeight>* rhs) {
        if (std::is_pointer<TWeight>::value) {
            return *lhs->info() < *rhs->info();
        } else {
            return lhs->info() < rhs->info();
        }    }
    static bool compEdgeGreater(const Edge<TWeight>* lhs, const Edge<TWeight>* rhs) {
        if (std::is_pointer<TWeight>::value) {
            return *lhs->info() > *rhs->info();
        } else {
            return lhs->info() > rhs->info();
        }

    }
};
}

#endif /* COMPARATORS_H_ */
