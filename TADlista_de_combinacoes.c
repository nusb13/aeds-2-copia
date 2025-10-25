#include <math.h>
#include <stdlib.h>

#include "TADlista_de_combinacoes.h"

// inicializa a lista com as combinações
TADlista_de_combinacoes* inicializa_lista_combinacoes(int N){
    unsigned long long total_combinacoes = (1ULL << N) - 1; // calculando quantas combinações são possíveis dada uma lista de tamanho N
    TADlista_de_combinacoes* listadecombinacoes = (TADlista_de_combinacoes*) malloc(sizeof(TADlista_de_combinacoes));  // alocando dinamicamente espaço para a lista (TAD)
    if (listadecombinacoes == NULL){
        return NULL; // verifica se a alocação foi bem sucedida
    }
    listadecombinacoes->combinacao = (TADlista_de_pacotes**) malloc(total_combinacoes * sizeof(TADlista_de_pacotes*)); // por fim, aloca-se dinamicamente espaço para os 2^n -1 elementos que o total de combinações vai ocupar
    if (listadecombinacoes->combinacao == NULL){  // novamente, verifica se a alocação foi bem sucedida
        free(listadecombinacoes); // se sim, não tem necessidade da estrutura alocada anteriormente continuar no heap
        return NULL; 
    }
    // incializando de vez a lista de combinações
    listadecombinacoes->tamanho = total_combinacoes;
    listadecombinacoes->ultimo = 0; // o primeiro espaço livre para inserção é o índice 0
}

// insere uma combinação na lista
int insere_combinacao_final(TADlista_de_combinacoes* listadecombinacoes, TADlista_de_pacotes* combinacao){
    if (listadecombinacoes->ultimo == listadecombinacoes->tamanho){
        return 0; // lista está cheia
    }
    TADlista_de_pacotes* nova_combinacao = copia_lista_pacote(combinacao); // faz uma cópia para armazená-la na lista de combinações
    listadecombinacoes->combinacao[listadecombinacoes->ultimo] = nova_combinacao;
    listadecombinacoes->ultimo++;
    return 1;
}


// libera o espaço ocupado pela lista de combinações
int libera_lista_combinacoes(TADlista_de_combinacoes* listadecombinacoes){
    if (listadecombinacoes ==  NULL){
        return 0; // lista já está liberada 
    }
        for (long long int i=0; i<listadecombinacoes->ultimo; i++){ // percorre todos os elementos
            libera_lista_pacotes(listadecombinacoes->combinacao[i]); 
        }
    free(listadecombinacoes->combinacao); // libera o arranjo de ponteiros
    free(listadecombinacoes); // libera a struct lista de combinações no heap
}


// retorna a combinação com a maior prioridade, dado um peso máximo que deve ser respeitado e verificado
TADlista_de_pacotes* encontra_prioridade_combinacao(TADlista_de_combinacoes* listadecombinacoes, int peso_maximo_drone){
    int maior_prioridade = -2;
    TADlista_de_pacotes* pacotes_prioridade_maior = NULL; // declarando o ponteiro que será retornado
    for(long long int i=0; i<listadecombinacoes->ultimo; i++){
        if (prioridade_total_pacotes(listadecombinacoes->combinacao[i]) > maior_prioridade && peso_total_pacotes(listadecombinacoes->combinacao[i]) <= peso_maximo_drone){
            pacotes_prioridade_maior = listadecombinacoes->combinacao[i]; // se for a maior prioridade já vista, faz uma cópia para armazenar na lista de pacotes com maior prioridade
            maior_prioridade = prioridade_total_pacotes(listadecombinacoes->combinacao[i]);
        }
    }
    return pacotes_prioridade_maior;
}