#ifndef TADLISTADEPACOTES_h
#define TADLISTADEPACOTES_h

#include "TADpacote.h"

typedef struct celula_lista_de_pacotes{
    TADpacote pacote;
    struct celula_lista_de_pacotes* apontador_proximo;
} CELULA_lista_de_pacotes;

typedef struct {
    CELULA_lista_de_pacotes* apontador_primeiro;
    CELULA_lista_de_pacotes* apontador_ultimo;
    int tamanho;
} TADlista_de_pacotes;


// inicialização da lista 
int inicializa_lista_de_pacotes(TADlista_de_pacotes* listadepacotes);

// insere pacote no final da lista
int insere_pacote_no_final_lista(TADlista_de_pacotes* listadepacotes, TADpacote pacote);

// remove pacote do início da lista
int remove_pacote_inicio_lista(TADlista_de_pacotes* listadepacotes, TADpacote* pacote_removido);

// remove pacote do final da lista 
int remove_pacote_final_lista(TADlista_de_pacotes* listadepacotes);

// imprime lista
void imprime_lista_de_pacotes(TADlista_de_pacotes* listadepacotes);

// verifica se lista é vazia
int lista_e_vazia(TADlista_de_pacotes* listadepacotes);

// copia lista do parametro e retorna
TADlista_de_pacotes* copia_lista_pacote(TADlista_de_pacotes* listadepacotesoriginal);

// desaloca no heap todo o conteúdo de uma lista de pacotes
void libera_lista_pacotes(TADlista_de_pacotes* listadepacotes);

// retorna a soma das prioridades de todos os pacotes naquela lista
int prioridade_total_pacotes(TADlista_de_pacotes* listadepacotes);

// retorna a soma dos pesos de todos os pacotes naquela lista
int peso_total_pacotes(TADlista_de_pacotes* listadepacotes);

// encontra combinações de tamanho X
void encontrar_combinacoes(CELULA_lista_de_pacotes* no_inicio, int tamanho, TADlista_de_pacotes* combinacao_atual, TADlista_de_combinacoes* listadecombinacoes);

#endif
