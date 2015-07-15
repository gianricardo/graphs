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

struct neighbor { //Estruta de vizinho utilizado na cria��o da lista de adjac�ncia
    vertex_t target;
    weight_t weight;
    neighbor(vertex_t arg_target, weight_t arg_weight)
        : target(arg_target), weight(arg_weight) { }
};

typedef std::vector<std::vector<neighbor> > adjacency_list_t; //defini��o da lista de adjac�ncia


void DijkstraComputePaths(vertex_t source,const adjacency_list_t &adjacency_list,
                          std::vector<weight_t> &min_distance,
                          std::vector<vertex_t> &previous) {
/* Implementa��o do algoritmo de Dijkstra, possui como par�metros de entrada uma matriz de adjc�ncia (grafo)
v�rtice de origem para gera��o de caminhos m�nimos, e vetores de v�rtices e de pesos nos v�rtices que s�o
utilizados no algoritmo para se obter o resultado final.*/
    int n = adjacency_list.size();
    min_distance.clear();
    min_distance.resize(n, max_weight); //Faz com que todos os valores sejam inifinito
    min_distance[source] = 0; //Torna o valor da origem ZERO
    previous.clear();
    previous.resize(n, -1);
    std::set<std::pair<weight_t, vertex_t> > vertex_queue;
    vertex_queue.insert(std::make_pair(min_distance[source], source));

    while (!vertex_queue.empty()) {
        weight_t dist = vertex_queue.begin()->first;
        vertex_t u = vertex_queue.begin()->second;
        vertex_queue.erase(vertex_queue.begin());


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
} /*Ao final do algoritmo o vetor min_distance est� preenchido com menores dist�ncias
 do v�rtice origem aos demais v�rtices do grafo. E o vetor previous com os v�rtices
que representam o caminho mais curto
*/

std::list<vertex_t> DijkstraGetShortestPathTo(
/* Fun��o utilizada para retornar uma lista de v�rtices que representam
o caminho que deve ser seguido a partir da origem declarada na fun��o citada
anteriormente at� um v�rtice de destino escolhido na chamada desta fun��o. */
    vertex_t vertex, const std::vector<vertex_t> &previous) {
    std::list<vertex_t> path;
    for ( ; vertex != -1; vertex = previous[vertex])
        path.push_front(vertex);
    return path;
}


int main() {
    // remember to insert edges both ways for an undirected graph
    adjacency_list_t adjacency_list(9400); //Declara��o do vetor que representa a matriz de adjac�ncia
//OBS: criou-se vetor com 9400 pois o programa retornava um erro devido a haver v�rtices cujo 'nome' � maior que 9000
    std::ifstream s("metros_sp.txt");
    int i,f,p;
    if(s.is_open()) {
        while (!s.eof()) {
            s >> i; //Representar� o v�rtice origem
            s >> f; //Representar� o v�rtice destino
            s >> p; //Representar� o peso da aresta
            adjacency_list[i].push_back(neighbor(f, p)); //Cria��o das arestas do grafo
        }
    }
    s.close();

    std::vector<weight_t> min_distance;
    std::vector<vertex_t> previous;

    int origem, destino;
//    std::string o_s,d_s;
    std::string continuar="sim";

    while(continuar=="sim" or continuar=="Sim") { //La�o que permite ao usu�rio realizar quantas consultas desejar
        std::cout << "Digite o codigo da estacao de origem: ";
        std::cin >> origem;
        std::cout << "Digite o codigo da estacao destino: ";
        std::cin >> destino;
        DijkstraComputePaths(origem, adjacency_list, min_distance, previous); //Chama a fun��o para executar algoritmo de Dijkstra
        double tempo=min_distance[destino]/60; //Retorna o tempo m�nimo de viagem em minutos, visto que os valores foram inseridos na unidade de segundo
        if(tempo==std::numeric_limits<double>::infinity()) {
            std::cout<<"N�o existe um caminho direto entre a estacao de origem e destino"<<std::endl<<std::endl;
            //Imprime na tela caso n�o haja caminho direto entre os v�rtices escolhidos
        } else {
            std::cout << "Tempo medio de " << origem << " para "<< destino<<" eh " << tempo <<" minutos."<< std::endl;
            std::list<vertex_t> path = DijkstraGetShortestPathTo(destino, previous);
            std::cout << "Caminho : ";
            std::copy(path.begin(), path.end(), std::ostream_iterator<vertex_t>(std::cout, " "));
            //imprime na tela o caminho a ser seguido para se chegar ao v�rtice destino no tempo m�nimo
            std::cout << std::endl<< std::endl;
        }
        std::cout << std::endl<< "Deseja fazer nova consulta? (Responda com 'Sim' ou 'Nao')";
        std::cin >> continuar;
        std::cout << std::endl;
    }



//C�DIGO ABAIXO � RASCUNHO!!!
    /*
        while(continuar=='S') {
            std::cout << "Estacao origem: ";
            std::cin >> o_s;
            std::cout << "Estacao destino: ";
            std::cin >> d_s;

            std::ifstream orig("origem.txt");
            std::ifstream nomes_o("nomes_o.txt");

            std::string nome_o,nome_d;
            if(nomes_o.is_open()) {
                while (!nomes_o.eof()) {
                    if(orig.is_open()) {
                        while (!orig.eof()) {
                            while(nome_o!=o_s) {
                                nomes_o >> nome_o;
                                orig >> origem;
                            }
                        }
                    }
                }
            }
            orig.close();
            nomes_o.close();

            std::ifstream dest("destino.txt");
            std::ifstream nomes("nomes.txt");
            if(nomes.is_open()) {
                while (!nomes.eof()) {
                    if(dest.is_open()) {
                        while (!dest.eof()) {
                            while(nome_d!=d_s) {
                                nomes >> nome_d;
                                dest >> destino;
                            }
                        }
                    }
                }
            }
            dest.close();
            nomes.close();

            DijkstraComputePaths(origem, adjacency_list, min_distance, previous);
            double tempo=min_distance[destino]/60;
            std::cout << "Tempo medio de " << origem << " para "<< destino<<" eh " << tempo <<" minutos."<< std::endl;
            std::list<vertex_t> path = DijkstraGetShortestPathTo(destino, previous);
            std::cout << "Caminho : ";
            std::copy(path.begin(), path.end(), std::ostream_iterator<vertex_t>(std::cout, " "));
            std::cout << std::endl<< std::endl;
            std::cout << "Deseja continuar? (S para Sim/N para Nao)";
            std::cin >> continuar;
            std::cout << std::endl<< std::endl;
        }*/
    std::cout<< std::endl<<"Fim da pesquisa."<<std::endl;
    return 0;
}
