#ifndef TADLISTADECOMBINACOES_h
#define TADLISTADECOMBINACOES_h

#include "TADlista_de_pacotes.h"

typedef struct {
    TADlista_de_pacotes** combinacao; //  ponteiro duplo (arranjo de ponteiros da lista encadeada)
    long long int tamanho; //  2^N - 1 (número dos subconjuntos - o conjunto vazio)
    long long int ultimo; // guarda o primeiro espaço disponível na lista após o último ocupado
} TADlista_de_combinacoes;

// inicializa a lista com as combinações
TADlista_de_combinacoes* inicializa_lista_combinacoes(int N);

// insere uma combinação na lista
int insere_combinacao_final(TADlista_de_combinacoes* listadecombinacoes, TADlista_de_pacotes* combinacao);

// libera o espaço ocupado pela lista de combinações
int libera_lista_combinacoes(TADlista_de_combinacoes* listadecombinacoes);

// retorna a combinação com a maior prioridade, dado um peso máximo que deve ser respeitado e verificado
TADlista_de_pacotes* encontra_prioridade_combinacao(TADlista_de_combinacoes* listadecombinacoes, int peso_maximo_drone);

#endif
