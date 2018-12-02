#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANHO_MAX_TEXTO 999999 // Tamanho máximo para o vetor que armazena o texto
#define MAX_CHAR 256 // Quantidade de caracters da tabela ASCII
#define COR_BRANCO "\x1b[97m"
#define COR_VERMELHO_CLARO "\x1b[91m"
#define COR_AMARELO_CLARO "\x1b[93m"
#define COR_VERDE_AGUA_CLARO "\x1b[96m"

typedef struct BMHS {
    char texto[TAMANHO_MAX_TEXTO];
    int vetorGuardaIndicesPalavrasEncontradas[TAMANHO_MAX_TEXTO];
    int tamanhoTexto, tamanhoDoPadrao, indiceDaUltimaPalavraEncontraNoVetor;
} BMHS;

void pesquisaBMHS(BMHS *bmhs, char *padrao);
void listaOcorrencias(BMHS *bmhs, char *padrao);
void leArquivoPreencheTexto(BMHS *bmhs);
