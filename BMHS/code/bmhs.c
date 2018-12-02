#include "bmhs.h"

void pesquisaBMHS(BMHS *bmhs, char *padrao) {
    int i, j, k, d[MAX_CHAR + 1];

    bmhs->tamanhoDoPadrao = strlen(padrao);

    int m = bmhs->tamanhoDoPadrao;
    int n = bmhs->tamanhoTexto;

    bmhs->indiceDaUltimaPalavraEncontraNoVetor = 0;
    bmhs->vetorGuardaIndicesPalavrasEncontradas[0] = -1; // Flag para saber se não encontrou nenhuma ocorrência

    for(j = 0; j <= MAX_CHAR; j ++)
        d[j] = m + 1;
    for(j = 1; j <= m; j ++)
        d[(int) padrao[j-1]] = m - j + 1;
    i = m;
    while (i <= n) /*--Pesquisa--*/ {
        k = i;
        j = m;
        while (bmhs->texto[k-1] == padrao[j-1] && j > 0 ) {
            k--;
            j--;
        }
        if(j == 0) {
            bmhs->vetorGuardaIndicesPalavrasEncontradas[bmhs->indiceDaUltimaPalavraEncontraNoVetor] = k+1;
            (bmhs->indiceDaUltimaPalavraEncontraNoVetor)++;
        }
        i += d[(int) bmhs->texto[i]];
    }
}

void listaOcorrencias(BMHS *bmhs, char *padrao) {
    int i;
    system("clear");
    if(bmhs->vetorGuardaIndicesPalavrasEncontradas[0] != -1) {
        printf("Índice(es) onde o padrão " COR_AMARELO_CLARO "%s " COR_BRANCO "foi encontrado: \n\n", padrao);
        for(i = 0; i < bmhs->indiceDaUltimaPalavraEncontraNoVetor; i++)
            printf("%d ", bmhs->vetorGuardaIndicesPalavrasEncontradas[i]);
        printf("\n");
    } else
        printf(COR_BRANCO "Nenhuma ocorrência do padrão " COR_AMARELO_CLARO "%s " COR_BRANCO "foi encontrada!\n", padrao);
}

void leArquivoPreencheTexto(BMHS *bmhs) {

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
        bmhs->texto[i] = caracter;
        i++;
    }

    bmhs->texto[i] = '\0';
    bmhs->tamanhoTexto = strlen(bmhs->texto);

    system("clear");

}
