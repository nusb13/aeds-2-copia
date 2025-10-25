#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include "TADdrone.h"


// inicialização contendo peso máximo;
void inicializa_drone(TADdrone* drone, int peso_max){
    drone->peso_maximo = peso_max;
    inicializa_lista_de_pacotes(&(drone->lista_de_pacotes)); //chama função que vai ativar a lista de pacotes do drone
    drone->peso_carregado = 0; //nenhum pacote na lista por enquanto, logo, nenhum peso carregado
    drone->distancia_total_percorrida = 0; // drone não saiu do galpão ainda
}


// carregamento de pacote
int coleta_de_pacote_drone(TADdrone* drone, TADgalpao* galpao){
    TADpacote pacote_a_remover;
    if(primeiro_pacote_lista_galpao(galpao, &pacote_a_remover) == 0){
        return 0; // galpão está vazio, não tem o que retirar
    } // vai armazenar o primeiro pacote da lista galpão na variável temporária para verificar se o drone comporta seu peso antes de retirá-lo do galpão
    if(drone->peso_carregado + getPeso(&pacote_a_remover) > drone->peso_maximo){
        return 0; // o drone atingiu seu peso máximo e não consegue transportar o pacote
    }
    carregamento_pacote_galpao(galpao, &pacote_a_remover); // depois da verificação, retira o pacote do galpão 
    drone->peso_carregado += getPeso(&pacote_a_remover);
    insere_pacote_no_final_lista(&(drone->lista_de_pacotes), pacote_a_remover); // insere o pacote removido do galpão no drone 
    return 1; // o pacote foi inserido à lista com sucesso
}


// realiza entrega do pacote
int realiza_entrega(TADdrone* drone,TADpacote* pacote_entregue, int* posicao_atual){
    if (lista_e_vazia(&(drone->lista_de_pacotes))){
        return 0; // caso lista esteja vazia
    }
    remove_pacote_inicio_lista(&(drone->lista_de_pacotes), pacote_entregue); // devolve pacote entregue para ponteiro que vai acessar informações do pacote depois de retirá-lo da lista
    int destino = getDistancia_ate_endereco(pacote_entregue);
    drone->distancia_total_percorrida += abs(*posicao_atual - destino); // soma o módulo da diferença de distâncias 
    *posicao_atual = destino;
    if (lista_e_vazia(&(drone->lista_de_pacotes))){ // verifica se a lista de pacotes do drone está vazia
        drone->distancia_total_percorrida += *posicao_atual; // caso sim, o drone precisa voltar à base e isso adiciona novamente a distância do pacote ao trajeto total dele 
        *posicao_atual = 0; // drone está novamente na base 
    }
    drone->peso_carregado -= getPeso(pacote_entregue); // o drone libera o pacote e, consequentemente, seu peso
    return 1;
}


// imprime componentes do drone
void imprime_componentes_drone(TADdrone* drone){
    printf("\n---------------------------\n");
    printf("Peso máximo: %d\n", drone->peso_maximo);
    printf("Peso carregado: %d\n", drone->peso_carregado);
    printf("Distância total percorrida: %d\n", drone->distancia_total_percorrida);
    printf("Pacotes:\n");
    imprime_lista_de_pacotes(&(drone->lista_de_pacotes));
}
