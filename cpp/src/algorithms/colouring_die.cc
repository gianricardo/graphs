/*
 * colouring_die.cc
 *
 *  Created on: May 6, 2015
 *      Author: gian
 */

#include "colouring_die.h"

namespace graphlib {

Colouring_DIE::Colouring_DIE() {
}

Colouring_DIE::~Colouring_DIE() {
}

void Colouring_DIE::execute(Graph<Colour> aGraph){
	/*
	 * PASSO A PASSO
	 * 1-renumerar vértices tal que xi seja o i-ésimo
	 * 2-para i=0;i=numero de vertices;i++{
	 * 	2.1-procurar vertices adjacentes a xi;
	 * 	2.2-verificar se algum dos vertices adjacentes a xi possui a cor C{
	 * 		2.2.1-se nenhum tiver a cor C, então xi recebe a cor C;
	 * 		2.2.2-caso contrario, C+1 e volta a 2.2
	 * 		}
	 */
	Colour c;
	long i=0;
	c.code(i);
	auto listav=aGraph.vertices_list();
	for(auto v : listav){
		for(auto a : v->list_adj_nodes()){
			auto va=aGraph.get_vertex(a);
			if(va->info().code()==c.code()){
				i = i+1;
				c.code(i);
			}else{
				Colour nc;
				nc.code(i);
				v->info(nc);
			}
		}
	}
}

} /* namespace graphlib */
