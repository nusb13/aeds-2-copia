#ifndef TADDRONE_H
#define TADDRONE_H

#include "TADgalpao.h"
#include "TADlista_de_pacotes.h"

typedef struct {
    int peso_maximo;
    int peso_carregado;
    int distancia_total_percorrida;
    TADlista_de_pacotes lista_de_pacotes;
} TADdrone;


// inicialização contendo peso máximo;
void inicializa_drone(TADdrone* drone, int peso);

// carregamento de pacote
int coleta_de_pacote_drone(TADdrone* drone, TADgalpao* galpao);

// realiza entrega do pacote
int realiza_entrega(TADdrone* drone,TADpacote* pacote_entregue, int* posicao_atual);

// imprime componentes do drone
void imprime_componentes_drone(TADdrone* drone);


#endif
