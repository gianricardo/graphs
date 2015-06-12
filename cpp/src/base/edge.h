/*
 * edge.h
 *
 *  Created on: Apr 24, 2015
 *      Author: gian
 */

#ifndef GLIB_EDGE_
#define GLIB_EDGE_

#include <string>
#include <iostream>

namespace graphlib {

template<class Tipo_Info_Edge>
class Edge {
public:
    Edge();
    Edge(std::string v0, std::string v1) :
            _v0(v0), _v1(v1) {
    }
    Edge(std::string v0, std::string v1, Tipo_Info_Edge info) :
            _v0(v0), _v1(v1), _info(info) {
    }
    std::string v0() const;
    std::string v1() const;
    Tipo_Info_Edge info() const;
    void info(Tipo_Info_Edge i);
    void v0(std::string v0);
    void v1(std::string v1);
    virtual ~Edge();
    std::string adjcent(std::string v) {
        if (v == _v0) {
            return _v1;
        } else {
            return _v0;
        }
    }
    bool operator<(const Edge<Tipo_Info_Edge>& o_edge) {
        //std::cout << "ComparandoE";
        return _info < o_edge.info();
    }
    bool operator<(const Edge<Tipo_Info_Edge>*& o_edge) {
        //std::cout << "ComparandoE2";
        return _info < o_edge->info();
    }

private:
    std::string _v0, _v1;
    Tipo_Info_Edge _info;
};

template<class Tipo_Info_Edge>
Edge<Tipo_Info_Edge>::Edge() :
        _v0(""), _v1("") {
}

template<class Tipo_Info_Edge>
Edge<Tipo_Info_Edge>::~Edge() {
}

template<class Tipo_Info_Edge>
std::string Edge<Tipo_Info_Edge>::v0() const {
    return _v0;
}

template<class Tipo_Info_Edge>
std::string Edge<Tipo_Info_Edge>::v1() const {
    return _v1;
}

template<class Tipo_Info_Edge>
void Edge<Tipo_Info_Edge>::v0(std::string v0) {
    _v0 = v0;
}

template<class Tipo_Info_Edge>
void Edge<Tipo_Info_Edge>::v1(std::string v1) {
    _v1 = v1;
}

template<class Tipo_Info_Edge>
Tipo_Info_Edge Edge<Tipo_Info_Edge>::info() const {
    return _info;
}

template<class Tipo_Info_Edge>
void Edge<Tipo_Info_Edge>::info(Tipo_Info_Edge i) {
    _info = i;
}

} /* namespace graphlib */

#endif /* GLIB_EDGE_ */
