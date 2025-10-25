#include <stdio.h>
#include <stdlib.h>
#include "TADdrone.h"
#include <math.h>

#define MAXTAM_CONTEUDO 70 // definindo costantes conforme solicitado pelo problema 
#define MAXTAM_DESTINATARIO 70

int main(int argc, char *argv[]){
    FILE *inputStream = NULL; // ponteiro que será usado para indicar o tipo de entrada (arquivo ou terminal)

    if (argc == 1) { // verifica se há nenhum argumento extra 
        printf("Nenhum arquivo detectado. Digite as informacoes no terminal.\n"); 
        inputStream = stdin; // se sim, define o terminal como entrada padrão
    }

    else if (argc == 2){ // nesse caso há um argumento passado
        printf("Lendo dados do arquivo: %s\n", argv[1]); 
        inputStream = fopen(argv[1], "r"); // assumindo que o que foi passado é um arquivo, define que os dados do arquivo serão os de entrada e inicia sua leitura
    
        if (inputStream == NULL) { 
            printf("Erro na leitura\n");  
            exit(1); // indica que a abertura/leitura do arquivo foi falha
        }   
    }
    else {  // mais de um argumento foi passado
        fprintf(stderr, "Uso: %s [arquivo_de_entrada]\n", argv[0]);
        exit(1); }
    
    TADgalpao galpao;
    TADdrone drone;      // declaração do TAD drone e galpão
    int peso_maximo_drone, pacotes_a_serem_entregues;

    while (fscanf(inputStream, "%d", &peso_maximo_drone) == 1){ // verirfica se itens estão sendo lidos ainda
        inicializa_drone(&drone, peso_maximo_drone); // chama função para inicializar drone com peso máximo
        inicializa_galpao(&galpao); // chama função que vai inicializar o galpão do dia

        fscanf(inputStream, "%d", &pacotes_a_serem_entregues); // quantidade de pacotes a serem entregues

        for (int i=0; i<pacotes_a_serem_entregues;i++){
            TADpacote pacote; // cria pacote temporário para guardá-lo na lista galpão
            char conteudo[MAXTAM_CONTEUDO];  char destinatario[MAXTAM_DESTINATARIO];
            int peso; int distancia_ate_endereco; int valor_de_prioridade; // cria variáveis temporárias para guardar o valor recebido por fscanf
                    
            fscanf(inputStream, "%s %s %d %d %d", conteudo, destinatario, &peso, &distancia_ate_endereco, &valor_de_prioridade); // leitura das informaçoes do pacote de indíce i

            if (peso>peso_maximo_drone){
                printf("Nao e possivel entregar esse pacote\n"); // caso o pacote seja maior que o peso máximo do drone por si próprio, ele não será adicionado ao galpão
                continue; // não será inserido um novo pacote no lugar, a lista de pacotes do galpão terá um pacote a menos do que informado anteriormente
            }


            // armazenando os valores lidos no TAD pacote por meio de suas respectivas funções
            setConteudo(&pacote, conteudo);
            setDestinatario(&pacote, destinatario);
            setDistancia_ate_endereco(&pacote, distancia_ate_endereco);
            setPeso(&pacote, peso);
            setValor_de_prioridade(&pacote, valor_de_prioridade);

            // por fim, adiciona-se o pacote à lista de pacotes do galpão por meio da função
            recebe_pacote_galpao(&galpao, pacote);
    }  // isso se repete até que todos os pacotes sejam lidos e adicionados ao galpão

    //Agora, vem a lógica que busca as combinações que possuam maior valor de prioridade atribuído que respeitem o limite de peso do drone
    //Vamos utilizar busca binaria para fazer isso
    int MAX = pow(2, calcula_quantidade_lista(&galpao)) - 1; //retorna, o numero máximo de combinações que queremos alcançar
    int NUM = 1; //Cada valor novo representa uma combinação
    while (NUM <= MAX){ //Esse while irá verificar todas as combinações necessárias

    }





    } // fecha o while fscanf == 1
    
    if (inputStream != stdin) {
        fclose(inputStream); // caso a entrada tenha sido feita por arquivo, fecha ele
    } 
    
    return 0;
}  
