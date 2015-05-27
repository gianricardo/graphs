/*
 * testando.cc

 *
 *  Created on: 27/05/2015
 *      Author: Wyk
 */

#include "base/digraph.h"
#include <iostream>
#include <iomanip>
#include "algorithms/dijkstra.h"
#include "base/weightDij.h"
#include "base/weightDijV.h"


int main(int argc, char **argv) {
graphlib::Digraph<graphlib::WeightDijV,graphlib::WeightDij> teste;
graphlib::WeightDij i1(false,1), i2(false,1), i3(false,1), i4(false,1), i5(false,1), i6(false,1);
teste.add_arc("1","2",i1);
teste.add_arc("1","3",i2);
teste.add_arc("1","5",i3);
teste.add_arc("2","3",i4);
teste.add_arc("3","4",i5);
teste.add_arc("5","4",i6);

graphlib::WeightDijV v1(false,1,0), v2(false,1,0), v3(false,1,0), v4(false,1,0), v5(false,1,0);
teste.info_vertex("1",v1);
teste.info_vertex("2",v2);
teste.info_vertex("3",v3);
teste.info_vertex("4",v4);
teste.info_vertex("5",v5);

graphlib::Dijkstra busca;
busca.execute(teste,"1","3");
}




