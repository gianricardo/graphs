/*
 * gnode.h
 *
 *  Created on: Apr 24, 2015
 *      Author: gian
 */

#ifndef GNODE_H_
#define GNODE_H_

#include <string>
#include <list>
#include "edge.h"

namespace graphlib {

template<class Tipo_Info_Vertex, class Tipo_Info_Edge = Tipo_Info_Vertex>
class GNode {
public:
	GNode() :
			_name("") {
	}
	GNode(std::string name) :
			_name(name) {
	}
	virtual ~GNode() {
		//erase_out_edges();
	}
	//
	Tipo_Info_Vertex info() const {
		return _info;
	}
	void info(Tipo_Info_Vertex i) {
		_info = i;
	}
	std::string name() const {
		return _name;
	}
	//
	void add_edge(Edge<Tipo_Info_Edge> *edge) {
		_edges.push_back(edge);
	}
	void remove_edge(Edge<Tipo_Info_Edge> *edge) {
		_edges.remove(edge);
	}
	//
	bool exist_edge_to(std::string v) const {
		bool exist_edge = false;
		for (auto vv : _edges) {
			if (vv->adjcent(_name) == v) {
				exist_edge = true;
				break;
			}
		}
		return exist_edge;
	}

	Edge<Tipo_Info_Edge>* edge_to(std::string v) {
		Edge<Tipo_Info_Edge>* edge_to_v = nullptr;
		for (auto vv : _edges) {
			if (vv->adjcent(_name) == v) {
				edge_to_v = vv;
				break;
			}
		}
		return edge_to_v;
	}

	const std::list<std::string> list_adj_edges() const {
		std::list<std::string> list_2_v1;
		for (auto vv : _edges) {
			list_2_v1.push_back(vv->adjcent(_name));
		}
		list_2_v1.sort();
		return list_2_v1;

	}

	int degree() const {
		return (_edges.size());
	}

	const std::list<Edge<Tipo_Info_Edge> *> list_edges() const {
		return _edges;
	}

private:
	void erase_out_edges() {
		/*
		 * Releasing the out-edges' memory.
		 * It does not need to release the in-edges' memory, because other vertices will release them as out-edges.
		 */
		for (auto edge : _edges) {
			delete edge;
		}
	}

	Tipo_Info_Vertex _info;
	std::string _name;
	std::list<Edge<Tipo_Info_Edge> *> _edges; //_edge_v0, _edge_v1;

};

} /* namespace graphlib */

#endif /* GNODE_H_ */
