#ifndef TADPACOTE_H
#define TADPACOTE_H

typedef struct {
    char conteudo[100];
    char destinatario[60];
    int peso;
    int distancia_ate_endereco; 
    int valor_de_prioridade;
} TADpacote;


// operações de get
char *getConteudo(TADpacote *pacote);
char *getDestinatario(TADpacote *pacote);
int getPeso(TADpacote *pacote);
int getDistancia_ate_endereco(TADpacote *pacote);
int getValor_de_prioridade(TADpacote* pacote);


// operações de set
void setConteudo(TADpacote *pacote, char* conteudo);
void setDestinatario(TADpacote *pacote, char* destinatario);
void setPeso(TADpacote *pacote, int peso);
void setDistancia_ate_endereco(TADpacote *pacote, int distancia_ate_endereco);
void setValor_de_prioridade(TADpacote* pacote, int prioridade);


// incializa o pacote
void inicializa_pacote(TADpacote* pacote, char* conteudo, char* destinatario, int distancia_ate_endereco, int peso, int valor_de_prioridade); 


// verifica se dois pacotes são iguais e retorna 1, caso sim
int pacotes_sao_iguais(TADpacote* pacote1, TADpacote* pacote2);


// impressão do pacote
void imprimepacote(TADpacote *pacote);

#endif
