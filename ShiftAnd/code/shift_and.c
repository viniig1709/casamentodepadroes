#include "shift_and.h"

void inicializa(ShiftAnd *shiftAnd, char *padrao) {
    int i;

    shiftAnd->tamanhoTexto = strlen(shiftAnd->texto);
    shiftAnd->tamanhoDoPadrao = strlen(padrao);

    for(i = 0; i < MAX_CHAR; i++)
        shiftAnd->MBinario[i] = 0;

    shiftAnd->R = 0;
    shiftAnd->RLinha = 0;
    shiftAnd->sequenciaBits10MMenos1 = (int) pow(2, shiftAnd->tamanhoDoPadrao-1); // Guarda um valor inteiro equivalente ao conceito de 10^m-1
    shiftAnd->indiceDaUltimaPalavraEncontraNoVetor = 0; // Índice inicial do vetor solução
    shiftAnd->vetorGuardaIndicesPalavrasEncontradas[0] = -1; // Flag para saber se não encontrou nenhuma ocorrência

    preencheM(shiftAnd, padrao);

}

void preencheM(ShiftAnd *shiftAnd, char *padrao) {
    int i;
    for(i = 0; i < shiftAnd->tamanhoDoPadrao; i++)
        shiftAnd->MBinario[(int) padrao[i]] += (int) pow(2, (shiftAnd->tamanhoDoPadrao-1)-i);
}

void pesquisaPadraoShiftAnd(ShiftAnd *shiftAnd, char *padrao) {
    int i;
    for(i = 0; i < shiftAnd->tamanhoTexto; i++) {
        shiftAnd->RLinha = ((shiftAnd->R >> 1) | shiftAnd->sequenciaBits10MMenos1) & shiftAnd->MBinario[(int) shiftAnd->texto[i]];
        shiftAnd->R = shiftAnd->RLinha;
        if(shiftAnd->RLinha % 2 != 0) {
            shiftAnd->vetorGuardaIndicesPalavrasEncontradas[shiftAnd->indiceDaUltimaPalavraEncontraNoVetor] = i-(shiftAnd->tamanhoDoPadrao-1)+1;
            (shiftAnd->indiceDaUltimaPalavraEncontraNoVetor)++;
        }
    }
}

void listaOcorrencias(ShiftAnd *shiftAnd, char *padrao) {
    int i;
    system("clear");
    if(shiftAnd->vetorGuardaIndicesPalavrasEncontradas[0] != -1) {
        printf("Índice(es) onde o padrão " COR_AMARELO_CLARO "%s " COR_BRANCO "foi encontrado: \n\n", padrao);
        for(i = 0; i < shiftAnd->indiceDaUltimaPalavraEncontraNoVetor; i++)
            printf("%d ", shiftAnd->vetorGuardaIndicesPalavrasEncontradas[i]);
        printf("\n");
    } else
        printf(COR_BRANCO "Nenhuma ocorrência do padrão " COR_AMARELO_CLARO "%s " COR_BRANCO "foi encontrada!\n", padrao);
}

void leArquivoPreencheTexto(ShiftAnd *shiftAnd) {

    FILE *arq;
    char caracter;
    char endereco[32], nomeArquivo[32];
    int i = 0;

    system("clear");
    printf("----------------------- Casamento de padrão: ------------------------\n");
    printf("\nDigite o nome do seu arquivo de texto (sem a extensão .txt): ");
    scanf("%s", nomeArquivo);
    printf("\n-------------------------------------------------------------------\n");

    strcat(nomeArquivo, ".txt");
    strcpy(endereco, "./files/");
    strcat(endereco, nomeArquivo);

    arq = fopen(endereco, "r");

    if( arq == NULL ) {
        printf("Erro na abertura do arquivo\n");
        return;
    }

    printf("\nArquivo carregado com sucesso!\nPressione enter para continuar...");
    getchar();
    getchar();

    while((caracter=fgetc(arq))!= EOF) {
        shiftAnd->texto[i] = caracter;
        i++;
    }

    shiftAnd->texto[i] = '\0'; // Fechando o texto criado

    system("clear");

}
