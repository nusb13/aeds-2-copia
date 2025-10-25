#include "TADpacote.h"
#include <string.h> 
#include <stdio.h>


// operações de get
char *getConteudo(TADpacote *pacote){          
    return pacote->conteudo;
}

char *getDestinatario(TADpacote *pacote){        
    return pacote->destinatario;
}

int getPeso(TADpacote *pacote){              
    return pacote->peso; 
}

int getDistancia_ate_endereco(TADpacote *pacote){
    return pacote->distancia_ate_endereco;
}

int getValor_de_prioridade(TADpacote* pacote){
    return pacote->valor_de_prioridade;
}

// operações de set
void setConteudo(TADpacote *pacote, char* conteudo){
    strcpy(pacote->conteudo, conteudo);
}

void setDestinatario(TADpacote *pacote, char* destinatario){
    strcpy(pacote->destinatario, destinatario);
}

void setPeso(TADpacote *pacote, int peso){
    pacote->peso = peso;
}

void setDistancia_ate_endereco(TADpacote *pacote, int distancia_ate_endereco){
    pacote->distancia_ate_endereco = distancia_ate_endereco;
}

void setValor_de_prioridade(TADpacote* pacote, int prioridade){
    pacote->valor_de_prioridade = prioridade;
}


// imprime dados do pacote
void imprimepacote(TADpacote *pacote){
    printf("\n---------------------------\n");
    printf("Conteúdo: %s\n", getConteudo(pacote));
    printf("Destinatário: %s\n", getDestinatario(pacote));
    printf("Peso: %d\n", getPeso(pacote));
    printf("Distância até endereço: %d\n", getDistancia_ate_endereco(pacote));
    printf("\n---------------------------\n");
}


// incializa o pacote
void inicializa_pacote(TADpacote* pacote, char* conteudo, char* destinatario, int distancia_ate_endereco, int peso, int valor_de_prioridade){ 
    setConteudo(&pacote, conteudo);
    setDestinatario(&pacote, destinatario);
    setDistancia_ate_endereco(&pacote, distancia_ate_endereco);
    setPeso(&pacote, peso);
    setValor_de_prioridade(&pacote, valor_de_prioridade);
}


// // verifica se dois pacotes são iguais e retorna 1, caso sim
int pacotes_sao_iguais(TADpacote* pacote1, TADpacote* pacote2){
    if (strcmp(pacote1->conteudo, pacote2->conteudo) != 0) {
        return 0; 
    }
    if (strcmp(pacote1->destinatario, pacote2->destinatario) != 0) {
        return 0; 
    }
    if (pacote1->peso != pacote2->peso) {
        return 0;
    }
    if (pacote1->distancia_ate_endereco != pacote2->distancia_ate_endereco) {
        return 0;
    }
    if (pacote1->valor_de_prioridade != pacote2->valor_de_prioridade) {
        return 0;
    }
    // verifica campo a campo para determinar igualdade entre os pacotes, caso todos eles sejam idênticos, retorna 1
    return 1;
}
