#include "TADlista_de_pacotes.h"
#include "TADlista_de_combinacoes.h"

#include <stdio.h>
#include <stdlib.h> 


// inicialização da lista
int inicializa_lista_de_pacotes(TADlista_de_pacotes* listadepacotes){
    listadepacotes -> apontador_primeiro = (CELULA_lista_de_pacotes*)malloc(sizeof(CELULA_lista_de_pacotes)); // alocando espaço dinamicamente para a cabeça da lista pacote 
    if (listadepacotes -> apontador_primeiro == NULL){
        return 0; // teste para verificar o sucesso da alocação dinâmica 
    }
    listadepacotes->apontador_ultimo = listadepacotes->apontador_primeiro;   // como a lista ainda está sendo inicializada, o último elemento é igual ao primeiro
    listadepacotes->apontador_primeiro->apontador_proximo = NULL;     // consequentemente, o ponteiro próximo referente ao primeiro elemento estará nulo
    listadepacotes->tamanho = 0;
    return 1; // indica sucesso na operação
}


// insere no final da lista
int insere_pacote_no_final_lista(TADlista_de_pacotes* listadepacotes, TADpacote pacote){
    CELULA_lista_de_pacotes *nova_celula = (CELULA_lista_de_pacotes*)malloc(sizeof(CELULA_lista_de_pacotes)); // alocando espaço dinamicamente para nova célula
    if (nova_celula == NULL){
        return 0; // teste para verificar o sucesso da alocação dinâmica 
    }
    nova_celula->pacote = pacote;    // armazenando item pacote na nova célula
    nova_celula->apontador_proximo = NULL;    // // a nova célula inserida é a última da lista e não há elementos seguidamente
    listadepacotes->apontador_ultimo->apontador_proximo = nova_celula;     // inserindo a célula na lista 
    listadepacotes->apontador_ultimo = nova_celula;     // atualizando ponteiro do último para ser a nova célula
    listadepacotes->tamanho++;
    return 1;     // indica sucesso na operação
}


// remove elemento no início da lista
int remove_pacote_inicio_lista(TADlista_de_pacotes* listadepacotes, TADpacote* pacote_removido){
    if (lista_e_vazia(listadepacotes)){
        return 0; // teste para analisar se lista está vazia
    }
    CELULA_lista_de_pacotes* celula_a_remover = listadepacotes -> apontador_primeiro->apontador_proximo; // salvar a célula em um outro ponteiro auxiliar para poder aplicar o free() posteriormente 
    *pacote_removido = celula_a_remover->pacote; // "retornando" para o ponteiro parâmetro o pacote que foi retirado da lista
    listadepacotes->apontador_primeiro->apontador_proximo = celula_a_remover->apontador_proximo; // atualiza a lista para começar do segundo elemento
    if (celula_a_remover == listadepacotes->apontador_ultimo) {
        listadepacotes->apontador_ultimo = listadepacotes->apontador_primeiro; // caso o elemento removido ser o último  
    } 
    free(celula_a_remover); // liberando a memória alocada dinamicamente  
    listadepacotes->tamanho--;
    return 1; // operação realizada com sucesso
}


// remove pacote do final da lista 
int remove_pacote_final_lista(TADlista_de_pacotes* listadepacotes){
    if (lista_e_vazia(listadepacotes)){
        return 0; 
    }
    CELULA_lista_de_pacotes* celula_a_remover = listadepacotes->apontador_ultimo;
    if (listadepacotes->tamanho == 1){
        listadepacotes->apontador_ultimo = listadepacotes->apontador_primeiro; 
        listadepacotes->apontador_primeiro->apontador_proximo = NULL; // a lista terá apenas a célula cabeça, sem elementos após ela
    } // após essa verificação e mudança, o processo será o mesmo para ambos os casos
    else{
        CELULA_lista_de_pacotes* celula_penultima = listadepacotes->apontador_primeiro->apontador_proximo; // começa do primeiro pacote para percorrer a lista e achar o penultimo pacote
        while (celula_penultima->apontador_proximo != listadepacotes->apontador_ultimo){
            celula_penultima = celula_penultima->apontador_proximo; // caminha pela lista até atingir o pacote anterior ao último
    }
        listadepacotes->apontador_ultimo = celula_penultima;
        celula_penultima->apontador_proximo = NULL; // a penúltima célula agora será a última
    }
    free(celula_a_remover); // liberando a memória alocada para a célula removida
    listadepacotes->tamanho--;
    return 1;
}


// remove um pacote específico da lista
int remove_pacote_especifico(TADlista_de_pacotes* listadepacotes, TADpacote* pacote_a_remover){
    if (lista_e_vazia(listadepacotes)){
        return 0;
    }
    CELULA_lista_de_pacotes* no_anterior = listadepacotes->apontador_primeiro;
    CELULA_lista_de_pacotes* no_atual = no_anterior->apontador_proximo; // dois ponteiros para nao perder o laço da lista encadeada
    while (no_atual != NULL){
        if (pacotes_sao_iguais(&(no_atual->pacote), pacote_a_remover)){
            no_anterior->apontador_proximo = no_atual->apontador_proximo; // irá "pular" a célula que vamos excluir
            if (no_atual == listadepacotes->apontador_ultimo){
                    listadepacotes->apontador_ultimo = no_anterior; // caso o último pacote da lista tenha sido o removido
                }
            free(no_atual);
            listadepacotes->tamanho--; 
            return 1; // pacote removido
        }
        no_anterior = no_atual;
        no_atual = no_atual->apontador_proximo;
    }
    return 0;  //  se o loop terminar e o pacote não for encontrado
}

// imprime a lista de pacotes
void imprime_lista_de_pacotes(TADlista_de_pacotes* listadepacotes){
    if (lista_e_vazia(listadepacotes)){
        return; // teste para analisar se lista está vazia
    }
    CELULA_lista_de_pacotes* atual = listadepacotes->apontador_primeiro->apontador_proximo; // percorre os elementos da lista indo de ponteiro a ponteiro até o último
    int contador = 1;
    while(atual != NULL){
        printf("\n------PACOTE %d------\n", contador);
        printf("Conteudo: %s\n", getConteudo(&(atual->pacote)));
        printf("Destinatario: %s\n", getDestinatario(&(atual->pacote)));
        printf("Peso: %d\n", getPeso(&(atual->pacote)));
        printf("Distancia até endereço: %d\n", getDistancia_ate_endereco(&(atual->pacote)));
        printf("\n---------------------------\n");
        atual = atual->apontador_proximo;
        contador++;
    }
}


// verifica se lista é vazia
int lista_e_vazia(TADlista_de_pacotes* listadepacotes){
    if (listadepacotes->apontador_ultimo == listadepacotes->apontador_primeiro){
        return 1;
    }
    else{
        return 0;
    }
}


// copia lista do parametro e retorna
TADlista_de_pacotes* copia_lista_pacote(TADlista_de_pacotes* listadepacotesoriginal){
    TADlista_de_pacotes* listadepacotes_destino = (TADlista_de_pacotes*) malloc(sizeof(TADlista_de_pacotes));
    if (inicializa_lista_de_pacotes(listadepacotes_destino) != 1){  // verifica se a alocação foi bem sucedida
        free(listadepacotes_destino); // se sim, não tem necessidade da estrutura alocada anteriormente continuar no heap
        return NULL;
    }
    CELULA_lista_de_pacotes* no_atual = listadepacotesoriginal->apontador_primeiro->apontador_proximo; // começa do primeiro elemento da lista de origem (passando pelo próximo à célula cabeça)
    while (no_atual != NULL){
        insere_pacote_no_final_lista(listadepacotes_destino, no_atual->pacote); // usa função para ir acrescentando os pacotes da lista original na lista destino
        no_atual = no_atual->apontador_proximo; // passa pro próximo elemento
    }
    return listadepacotes_destino;
}


// desaloca no heap todo o conteúdo de uma lista de pacotes
void libera_lista_pacotes(TADlista_de_pacotes* listadepacotes){
    CELULA_lista_de_pacotes* no_anterior = listadepacotes->apontador_primeiro;
    CELULA_lista_de_pacotes* no_atual;
    while(no_anterior != NULL){
        no_atual = no_anterior->apontador_proximo;  // percorre os elementos da lista indo de ponteiro a ponteiro até o último, utiliza-se dois ponteiros para nao perder os laços formados
        free(no_anterior);
        no_anterior = no_atual;
    }
    listadepacotes->apontador_primeiro = NULL;
    listadepacotes->apontador_ultimo = NULL;
    listadepacotes->tamanho = 0; // reseta e deixa a lista pronta pra ser inicializada posteriormente
    return;
}



// retorna a soma das prioridades de todos os pacotes naquela lista
int prioridade_total_pacotes(TADlista_de_pacotes* listadepacotes){
    if (lista_e_vazia(listadepacotes)){
        return 0;
    }
    int prioridade_total = 0;;
    CELULA_lista_de_pacotes* no_pacote_atual = listadepacotes->apontador_primeiro->apontador_proximo;  // começa do primeiro elemento da lista, ou seja, o seguinte à célula cabeça ("apontador_primeiro")
    while (no_pacote_atual != NULL){
        prioridade_total += getValor_de_prioridade(&(no_pacote_atual->pacote)); // capturando o valor da prioridade de cada pacote da lista e acrescentando no contador de prioridade total
        no_pacote_atual = no_pacote_atual->apontador_proximo;
    }
    return prioridade_total;
}


// retorna a soma dos pesos de todos os pacotes naquela lista
int peso_total_pacotes(TADlista_de_pacotes* listadepacotes){
    if (lista_e_vazia(listadepacotes)){
        return 0;
    }
    int peso_total = 0;;
    CELULA_lista_de_pacotes* no_pacote_atual = listadepacotes->apontador_primeiro->apontador_proximo;  // começa do primeiro elemento da lista, ou seja, o seguinte à célula cabeça ("apontador_primeiro")
    while (no_pacote_atual != NULL){
        peso_total += getPeso(&(no_pacote_atual->pacote)); // capturando o peso de cada pacote da lista e acrescentando no contador de peso total
        no_pacote_atual = no_pacote_atual->apontador_proximo;
    }
    return peso_total;
}


// encontra todas combinações de um tamanho X e adiciona em uma lista
void encontrar_combinacoes(CELULA_lista_de_pacotes* no_inicio, int tamanho, TADlista_de_pacotes* combinacao_atual, TADlista_de_combinacoes* listadecombinacoes){    
    if (combinacao_atual->tamanho == tamanho){ // uma combinação de tamanho X foi encontrada
        insere_combinacao_final(listadecombinacoes, combinacao_atual);
        return;
    }
    while (no_inicio != NULL){ // para percorrer dos elementos da lista encadeada original
        insere_pacote_no_final_lista(combinacao_atual, no_inicio->pacote); // insere um novo elemento no subconjunto atual
        encontrar_combinacoes(no_inicio->apontador_proximo, tamanho, combinacao_atual, listadecombinacoes); // chama recursivamente a função até formar um subconjunto completo e satisfazer o primeiro if 
        remove_pacote_final_lista(combinacao_atual); // após formar um subconjunto, desacopla um pacote dele para analisar outras possibilidades (backtracking)
        no_inicio = no_inicio->apontador_proximo;
    }
}




