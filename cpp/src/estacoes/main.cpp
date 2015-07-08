#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <fstream>

#include <limits> // for numeric_limits

#include <set>
#include <utility> // for pair
#include <algorithm>
#include <iterator>


typedef int vertex_t;
typedef double weight_t;

const weight_t max_weight = std::numeric_limits<double>::infinity();

struct neighbor {
    vertex_t target;
    weight_t weight;
    neighbor(vertex_t arg_target, weight_t arg_weight)
        : target(arg_target), weight(arg_weight) { }
};

typedef std::vector<std::vector<neighbor> > adjacency_list_t;


void DijkstraComputePaths(vertex_t source,const adjacency_list_t &adjacency_list,
                          std::vector<weight_t> &min_distance,
                          std::vector<vertex_t> &previous) {
    int n = adjacency_list.size();
    min_distance.clear();
    min_distance.resize(n, max_weight);
    min_distance[source] = 0;
    previous.clear();
    previous.resize(n, -1);
    std::set<std::pair<weight_t, vertex_t> > vertex_queue;
    vertex_queue.insert(std::make_pair(min_distance[source], source));

    while (!vertex_queue.empty()) {
        weight_t dist = vertex_queue.begin()->first;
        vertex_t u = vertex_queue.begin()->second;
        vertex_queue.erase(vertex_queue.begin());

        // Visit each edge exiting u
        const std::vector<neighbor> &neighbors = adjacency_list[u];
        for (std::vector<neighbor>::const_iterator neighbor_iter = neighbors.begin();
                neighbor_iter != neighbors.end();
                neighbor_iter++) {
            vertex_t v = neighbor_iter->target;
            weight_t weight = neighbor_iter->weight;
            weight_t distance_through_u = dist + weight;
            if (distance_through_u < min_distance[v]) {
                vertex_queue.erase(std::make_pair(min_distance[v], v));

                min_distance[v] = distance_through_u;
                previous[v] = u;
                vertex_queue.insert(std::make_pair(min_distance[v], v));

            }

        }
    }
}


std::list<vertex_t> DijkstraGetShortestPathTo(
    vertex_t vertex, const std::vector<vertex_t> &previous) {
    std::list<vertex_t> path;
    for ( ; vertex != -1; vertex = previous[vertex])
        path.push_front(vertex);
    return path;
}


int main() {
    // remember to insert edges both ways for an undirected graph
    adjacency_list_t adjacency_list(9400);
    std::ifstream s("metros_sp.txt");
    int i,f,p;
    if(s.is_open()) {
        while (!s.eof()) {
            s >> i;
            s >> f;
            s >> p;
            adjacency_list[i].push_back(neighbor(f, p));
        }
    }
    s.close();

    std::vector<weight_t> min_distance;
    std::vector<vertex_t> previous;
    int origem, destino;
    std::cout << "Estacao origem: ";
    std::cin >> origem;
    std::cout << "Estacao destino: ";
    std::cin >> destino;
    DijkstraComputePaths(origem/*vértice inicial*/, adjacency_list/*grafo*/, min_distance, previous);
    double tempo=min_distance[destino]/60;
    std::cout << "Tempo medio de " << origem << " para "<< destino<<" eh " << tempo <<" minutos."<< std::endl;
    std::list<vertex_t> path = DijkstraGetShortestPathTo(destino, previous);
    std::cout << "Caminho : ";
    std::copy(path.begin(), path.end(), std::ostream_iterator<vertex_t>(std::cout, " "));
    std::cout << std::endl;

    return 0;
}
