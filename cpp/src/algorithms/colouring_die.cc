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
	 * 1-renumerar vértices tal que xi seja o i-ésimo
	 * 2-para i=0;i=numero de vertices;i++{
	 * 	2.1-procurar vertices adjacentes a xi;
	 * 	2.2-verificar se algum dos vertices adjacentes a xi possui a cor C{
	 * 		2.2.1-se nenhum tiver a cor C, então xi recebe a cor C;
	 * 		2.2.2-caso contrario, C+1 e volta a 2.2
	 * 		}*
	 *
	 */
}

} /* namespace graphlib */
