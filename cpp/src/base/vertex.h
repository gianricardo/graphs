/*
 * vertex.h
 *
 *  Created on: Apr 27, 2015
 *      Author: gian
 */

#ifndef VERTEX_H_
#define VERTEX_H_

#include "arc.h"
#include "gnode.h"

namespace graphlib {

template<class Tipo_Info_Vertex, class Tipo_Info_Arc = Tipo_Info_Vertex>
class Vertex: public GNode<Tipo_Info_Vertex, Tipo_Info_Arc> {
public:
    Vertex() {
    }
    Vertex(std::string name) :
            GNode<Tipo_Info_Vertex, Tipo_Info_Arc>(name) {
    }
    virtual ~Vertex() {
    }
    //
    void add_from_arc(Arc<Tipo_Info_Arc> *arc) {
        GNode<Tipo_Info_Vertex, Tipo_Info_Arc>::add_edge(arc);
    }
    void add_to_arc(Arc<Tipo_Info_Arc> *arc) {
        _edges_in.push_back(arc);
    }
    void remove_from_arc(Arc<Tipo_Info_Arc> *arc) {
        GNode<Tipo_Info_Vertex, Tipo_Info_Arc>::remove_edge(arc);
    }
    void remove_to_arc(Arc<Tipo_Info_Arc> *arc) {
        _edges_in.remove(arc);
    }
    const std::list<std::string> to_vertex_list() const {
        return GNode<Tipo_Info_Vertex, Tipo_Info_Arc>::list_adj_nodes();
    }
    Arc<Tipo_Info_Arc>* arc_to(std::string v) {
        return  GNode<Tipo_Info_Vertex, Tipo_Info_Arc>::edge_to(v);
    }
    int degree_out()const {
        return GNode<Tipo_Info_Vertex, Tipo_Info_Arc>::degree();
    }

    int degree_in()const{
        return _edges_in.size();
    }

    int degree()const override {
        return (degree_out()+degree_in());
    }

    const std::list<Arc<Tipo_Info_Arc> *> out_arc_list()const{
        return GNode<Tipo_Info_Vertex, Tipo_Info_Arc>::list_edges();
    }

    const std::list<Arc<Tipo_Info_Arc> *> in_arc_list()const{
        return _edges_in;
    }
private:
    std::list<Arc<Tipo_Info_Arc> *> _edges_in;
};

} /* namespace graphlib */

#endif /* VERTEX_H_ */
