/*
 * digraph.h
 *
 *  Created on: Apr 27, 2015
 *      Author: gian
 */

#ifndef DIGRAPH_H_
#define DIGRAPH_H_

#include "graph.h"
#include "arc.h"
#include "vertex.h"

namespace graphlib {

template<class Tipo_Info_Vertex, class Tipo_Info_Arc = Tipo_Info_Vertex>
class Digraph: public Graph<Tipo_Info_Vertex,Tipo_Info_Arc> {
public:
    Digraph(){}
    virtual ~Digraph(){}
    //TODO adicionar ARCO
    void add_arc(std::string v0, std::string v1) {
           Vertex<Tipo_Info_Vertex, Tipo_Info_Arc> *v_0;
           if (!Graph<Tipo_Info_Vertex,Tipo_Info_Arc>::exist_vertex(v0)) {
               v_0 = new Vertex<Tipo_Info_Vertex, Tipo_Info_Arc>(v0);
               Graph<Tipo_Info_Vertex,Tipo_Info_Arc>::_vertices.insert(std::make_pair(v0, v_0));
           } else {
               v_0 = Graph<Tipo_Info_Vertex,Tipo_Info_Arc>::_vertices[v0];
           }
           if (!v_0->exist_edge_to(v1)) {
               Vertex<Tipo_Info_Vertex, Tipo_Info_Arc> *v_1;
               if (!Graph<Tipo_Info_Vertex,Tipo_Info_Arc>::exist_vertex(v1)) {
                   v_1 = new Vertex<Tipo_Info_Vertex, Tipo_Info_Arc>(v1);
                   Graph<Tipo_Info_Vertex,Tipo_Info_Arc>::_vertices.insert(std::make_pair(v1, v_1));
               } else {
                   v_1 = Graph<Tipo_Info_Vertex,Tipo_Info_Arc>::_vertices[v1];
               }
               Arc<Tipo_Info_Arc> *n_arc = new Arc<Tipo_Info_Arc>(v0, v1);
               v_0->add_from_arc(n_arc);
               v_1->add_to_arc(n_arc);
               //
           }
       }
    virtual void add_edge(std::string v0, std::string v1) {
    	add_arc(v0, v1);
    }

    void erase_arc(std::string v0, std::string v1) {
        Arc<Tipo_Info_Arc> *v_0;
        if (Graph<Tipo_Info_Vertex,Tipo_Info_Arc>::exist_vertex(v0) && Graph<Tipo_Info_Vertex,Tipo_Info_Arc>::exist_vertex(v1)) {
            v_0 = Graph<Tipo_Info_Vertex,Tipo_Info_Arc>::_vertices[v0];
            if (v_0->exist_edge_to(v1)) {
                Arc<Tipo_Info_Arc> *v_1;
                v_1 = Graph<Tipo_Info_Vertex,Tipo_Info_Arc>::_vertices[v1];
                auto edge_erase = v_0->edge_to(v1);
                v_0->remove_from_arc(edge_erase);
                v_1->remove_to_arc(edge_erase);
            }
        }
    }

    virtual void erase_edge(std::string v0, std::string v1) {
    	erase_arc(v0, v1);
    }
};

} /* namespace graphlib */

#endif /* DIGRAPH_H_ */
