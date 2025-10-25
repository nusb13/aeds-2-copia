#include <stdio.h>
#include <stdlib.h> 
#include "TADgalpao.h"
#include "TADlista_de_pacotes.h"


// inicialização do galpão
void inicializa_galpao(TADgalpao* galpao){
    inicializa_lista_de_pacotes(&(galpao->lista_de_pacotes_diaria)); 
}


// recebimento de pacotes
void recebe_pacote_galpao(TADgalpao* galpao, TADpacote pacote){
    insere_pacote_no_final_lista(&(galpao->lista_de_pacotes_diaria), pacote);
}


// carregamento de pacotes
int carregamento_pacote_galpao(TADgalpao* galpao,TADpacote* pacote_removido){
    if (remove_pacote_inicio_lista(&(galpao->lista_de_pacotes_diaria), pacote_removido)){
        return 1; // remoção feita com sucesso da lista
    } else {
        return 0; // houve erro na remoção 
    }
}


// imprime pacotes a serem entregues no dia
void imprime_pacotes_do_dia(TADgalpao* galpao){
    imprime_lista_de_pacotes(&(galpao->lista_de_pacotes_diaria));
}



// verifica e retorna o primeiro pacote da lista galpão
int primeiro_pacote_lista_galpao(TADgalpao* galpao, TADpacote* primeiro_pacote){
    if (lista_e_vazia(&(galpao->lista_de_pacotes_diaria))){
       return 0; // lista está vazia 
    }
    *primeiro_pacote = galpao->lista_de_pacotes_diaria.apontador_primeiro->apontador_proximo->pacote; // como a lista pacotes tem cabeça, essa atribuição coloca o pacote do apontador próximo no ponteiro que guarda o primeiro pacote do galpão
    return 1; //sucesso
}
