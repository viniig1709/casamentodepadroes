#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define TAMANHO_MAX_TEXTO 999999 // Tamanho máximo para o vetor que armazena o texto
#define MAX_CHAR 256 // Quantidade de caracters da tabela ASCII
#define COR_BRANCO "\x1b[97m"
#define COR_VERMELHO_CLARO "\x1b[91m"
#define COR_AMARELO_CLARO "\x1b[93m"
#define COR_VERDE_AGUA_CLARO "\x1b[96m"

typedef struct ShiftAnd {
    char texto[TAMANHO_MAX_TEXTO];
    int vetorGuardaIndicesPalavrasEncontradas[TAMANHO_MAX_TEXTO];
    long int R, RLinha, sequenciaBits10MMenos1, MBinario[MAX_CHAR]; // Representa também o tamanho máximo do padrão, para long int (64 caracteres)
    int tamanhoTexto, tamanhoDoPadrao, indiceDaUltimaPalavraEncontraNoVetor;
} ShiftAnd;

void inicializa(ShiftAnd *shiftAnd, char *padrao);
void preencheM(ShiftAnd *shiftAnd, char *padrao);
void pesquisaPadraoShiftAnd(ShiftAnd *shiftAnd, char *padrao);
void listaOcorrencias(ShiftAnd *shiftAnd, char *padrao);
void leArquivoPreencheTexto(ShiftAnd *shiftAnd);
