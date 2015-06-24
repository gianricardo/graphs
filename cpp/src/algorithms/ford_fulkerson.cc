/*
 * ford_fulkerson.cc
 *
 *  Created on: Jun 24, 2015
 *      Author: gian
 */

#include "ford_fulkerson.h"
#include <queue>
#include <iterator>
#include <limits>

namespace graphlib {

Ford_Fulkerson::Ford_Fulkerson() {

}

Ford_Fulkerson::~Ford_Fulkerson() {
}

bool Ford_Fulkerson::bfs(Digraph<WeightDijV, WeightDij> someGraph, std::string source, std::string end_t) //source->s  end->t
        {
    // Create a visited array and mark all vertices as not visited
    std::queue<std::string> q;
    std::map<std::string, bool> visited;

    //initializing
    auto graph_vertices = someGraph.vertices();
    for (auto position : graph_vertices) {
        visited[position.second->name()] = false;
    }
    auto v_current = graph_vertices.begin();
    for (; v_current != graph_vertices.end(); v_current = std::next(v_current)) {
        if (v_current->second->name() == source) {
            break;
        }
    }
    // Create a queue, enqueue source vertex and mark source vertex
    // as visited
    if (v_current != graph_vertices.end()) { //only traverse if there is the initial vertex in the graph
        int visit_count = 0;
        for (; visit_count < someGraph.number_vertices(); visit_count++) {
            if (!visited[v_current->second->name()]) {
                q.push(v_current->second->name());
                do {
                    std::string v2 = q.front();
                    q.pop();
                    if (!visited[v2]) {
                        visited[v2] = true;
                        if (v2 == end_t) {
                            visit_count = someGraph.number_vertices() + 1;
                            break;
                        }
                    }
                    auto edges = v_current->second->list_edges();
                    for (auto edge : edges) {
                        std::string name_node = v_current->second->name();
                        if (!visited[edge->adjcent(name_node)]) {
                            q.push(edge->adjcent(name_node));
                        }
                    }
                } while (!q.empty());
            } //end if
            v_current = std::next(v_current);
            if (v_current == graph_vertices.end()) { //reach the end of the map
                v_current = graph_vertices.begin();
            }
        } //end for
    }

    // If we reached sink in BFS starting from source, then return
    // true, else false
    return (visited[end_t]);
}

double Ford_Fulkerson::execute(Digraph<WeightDijV, WeightDij> someGraph, std::string source, std::string end_t) {
    std::string u, v;
    double inf = std::numeric_limits<double>::infinity();
    // Create a residual graph and fill the residual graph with
    // given capacities in the original graph as residual capacities
    // in residual graph
    Digraph<WeightDijV, WeightDij> *rSomeGraph = someGraph.clone();
    rSomeGraph->name("Residual Graph");
//    int rGraph[V][V]; // Residual graph where rGraph[i][j] indicates
                      // residual capacity of edge from i to j (if there
                      // is an edge. If rGraph[i][j] is 0, then there is not)
//    int parent[V];  // This array is filled by BFS and to store path
//
    double max_flow = 0;  // There is no flow initially
//
    // Augment the flow while tere is path from source to sink
    while (bfs(*rSomeGraph, source, end_t)) {
        // Find minimum residual capacity of the edhes along the
        // path filled by BFS. Or we can say find the maximum flow
        // through the path found.
        double path_flow = inf;
//        for (v = t; v != s; v = parent[v]) {
//            u = parent[v];
//            path_flow = std::min(path_flow, rGraph[u][v]);
//        }
//
//        // update residual capacities of the edges and reverse edges
//        // along the path
//        for (v = t; v != s; v = parent[v]) {
//            u = parent[v];
//            rGraph[u][v] -= path_flow;
//            rGraph[v][u] += path_flow;
//        }
//
        // Add path flow to overall flow
        max_flow += path_flow;
    }
    // Return the overall flow
    return max_flow;
}

} /* namespace graphlib */
