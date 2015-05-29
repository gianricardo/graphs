/*
 * dijkstra.cpp
 *
 *  Created on: 26/05/2015
 *      Author: Wyk
 */

#include "dijkstra.h"
#include <vector>
#include <list>
#include <limits>

namespace graphlib {

Dijkstra::Dijkstra() {
}

Dijkstra::~Dijkstra() {
}

double Dijkstra::execute(Digraph<WeightDijV, WeightDij> someDigraph,
		std::string source, std::string end) {
	auto vertices = someDigraph.vertices();
	double inf = std::numeric_limits<double>::infinity();
	for (auto v : vertices) {
		WeightDijV wd = v.second->info();
		wd.dist_origem(inf);
		wd.visitado(false);
		v.second->info(wd);
	}
	auto v_origem = vertices[source];
	WeightDijV wd = v_origem->info();
	wd.dist_origem(0);
	v_origem->info(wd);

	std::map<std::string, Vertex<WeightDijV, WeightDij> *> set_q;
	for (auto v : vertices) {
		set_q.insert(std::make_pair(v.first, v.second));
	}

	while (!set_q.empty()) {
		auto v = set_q.begin();
		for (auto temp_v=set_q.begin();temp_v!=set_q.end(); temp_v++) {
			if (temp_v->second->info().dist_origem() < v->second->info().dist_origem()) {
				v = temp_v;
			}
		}
		std::cout<<"Apagando v "<<v->second->name()<<"\n";
		set_q.erase(v);
	}
	return 0.0;
}

} /* namespace graphlib */

/*
 Vertex<Weight> p;
 std::list<Vertex<Weight>> Q;
 std::vector<Vertex<Weight>> visitados[n];
 std::vector<Vertex<Weight>> nao_visitados[n](someDigraph.vertices_list());
 std::vector<double> dist[n](999999);
 std::vector<bool> k[n](false);
 dist[s]=0;
 while(!Q.empty()){
 for(Vertex<Weight> u : Q){
 //Q = Q - u;
 for(Vertex<Weight> v : u.list_adj_nodes()){
 if(dist[v]>dist[u] + u.arc_to(v).info()){	//peso da aresta que vai de u a v); fazer aresta ter peso agora
 dist[v]=dist[u] + u.arc_to(v).info();

 }
 }
 }
 }
 * /

 int const n = someDigraph.number_vertices();
 std::vector<double> d[n];
 for(int i=0;i<n;i++){d[i]=9999999999999;}
 std::vector<Vertex<Weight>> p[n];
 std::list<Vertex<Weight>> Q(someDigraph.vertices_list());

 while(!Q.empty()){
 for(Vertex<Weight> u : Q){ //encontrar v pertencente a Q o qual D[v] � m�nima;
 for(Vertex<Weight> v : u.list_adj_nodes()){
 Arc<Weight>	dist = u.edge_to(v);
 Q.remove(u);
 if(d[u]>dist.info().value()/ * +w(v,u) * /){
 d[u] = dist.info().value();//+w(v,u);
 p.push_back(u);
 }
 }
 }
 }
 for(int a=0;a<d.size();a++){
 std::cout<<"Vertice: "<< a << " Dist min: "<< d[a]<<std::endl;
 }
 * */
