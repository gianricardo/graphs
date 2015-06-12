/*
 * graph_io.h
 *
 *  Created on: Jun 12, 2015
 *      Author: gian
 */

#ifndef GRAPH_IO_H_
#define GRAPH_IO_H_

#include <iostream>
#include <fstream>

namespace graphlib {

#define _GRAPH_DEBUG false

template<class TGraph>
class Graph_IO {
public:
    Graph_IO(){}
    virtual ~Graph_IO(){}
    TGraph& load_from_file(std::string file) {
        TGraph aGraph;
        std::ifstream to_load(file);
        if (to_load.is_open()) {
            std::string v0, v1;
            while (true) {
                std::getline(to_load, v0, ' ');
                std::getline(to_load, v1);
                //std::cin >> v0;
                //std::cin >> v1;
                if (_GRAPH_DEBUG)
                    std::cout << "Read: " << v0 << " - " << v1 << std::endl;
                if (v0.size() > 0 && v1.size() > 0) { //read two values
                    aGraph.add_edge(v0, v1);
                } else {
                    if (!to_load.eof()) {
                        std::cout << "File bad formatted!" << std::endl;
                    }
                    break;
                }
                if (to_load.eof()) {
                    break;
                }
            }
            to_load.close();
        }
        return aGraph;
    }

    void generate_dot_file(TGraph aGraph,std::string dotfile, long upper_vertex_limit = 0) const {
        std::ofstream to_write(dotfile);
        if (to_write.is_open()) {
            long vertex_count = 0;
            to_write << "graph " << aGraph.name() << " { \n";
            for (auto position : aGraph.vertices()) {
                auto edges = position.second->list_edge_v0();
                for (auto edge : edges) {
                    to_write << "    " << edge->v0() << "--" << edge->v1() << ";\n";
                }
                vertex_count++;
                if ((upper_vertex_limit != 0) && (vertex_count >= upper_vertex_limit)) {
                    break;
                }
            }
            to_write << "}\n";
            to_write.flush();
            to_write.close();
        }
    }
};

} /* namespace graphlib */

#endif /* GRAPH_IO_H_ */
