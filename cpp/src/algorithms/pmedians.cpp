 // pmedians.cpp

#include "pmedians.h"
#include <list>

namespace graphlib {

P_medians::P_medians(){

}

P_medians::~P_medians(){

}

void P_medians::execute(Digraph<Weight> someDigraph, int med_number){

/*
std::vector<Vertex<Weight>> medians_S(med_number), aux, naotestados,testados;
aux = someDigraph.vertices_list();
Vertex<Weight> add1;
for(int i=0;i<med_number;i++){
	add1 = aux.back();
	medians_S.push_back(add1);
	aux.pop_back();
}
for(auto add2 : aux){
	naotestados.push_back(add2);
}

while(!naotestados.empty()){

	int delta;
	std::vector deltas;
for(int i=0;i<naotestados.size();i++){
	std::vector new_vector(medians_S);
	new_vector[i]=naotestados[i];
	delta = transmission(medians_S)-transmission(new_vector);
	deltas.push_back(delta);
}
int delta_max=deltas[0];
for(int j=1;j<deltas.size();j++){
	if (deltas[j]>delta_max){
		delta_max = deltas[j];
	}
}
if(delta_max<=0){
	//fazer teste para colocar ver se coloca xi ou xj em testados
}

*/
}

double P_medians::transmission(std::vector<Vertex<Weight>> set_S){
	double total=0;
	for(auto x : set_S){
		total = x.info().value();//*min(x,set_S);
	}
	return total;
}

double P_medians::min_trans(Vertex<Weight>x, std::vector<Vertex<Weight>> set_S){
	return 0;
}


}//namespace graphlib
