#ifndef TADGALPAO_H
#define TADGALPAO_H

#include "TADlista_de_pacotes.h"

typedef struct {
    TADlista_de_pacotes lista_de_pacotes_diaria;
} TADgalpao;


// inicialização do galpão
void inicializa_galpao(TADgalpao* galpao);

// recebimento de pacotes
void recebe_pacote_galpao(TADgalpao* galpao, TADpacote pacote);

// carregamento de pacotes
int carregamento_pacote_galpao(TADgalpao* galpao,TADpacote* pacote_removido);

// imprime pacotes a serem entregues no dia
void imprime_pacotes_do_dia(TADgalpao* galpao);


// verifica e retorna o primeiro pacote da lista galpão
int primeiro_pacote_lista_galpao(TADgalpao* galpao, TADpacote* primeiro_pacote);

#endif
