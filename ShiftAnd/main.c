#include "./code/shift_and.h"
#include <time.h>
#define NORMAL 1
#define ANALISE 0

int main(int argc, char** argv) {

    ShiftAnd shiftAnd;
    char padrao[32];
    clock_t inicio, final;
    double tempoPesquisa, tempoPreProcessamento;

    leArquivoPreencheTexto(&shiftAnd);
    while(strcmp(padrao, "0") != 0) {
        system("clear");
        printf(COR_BRANCO "Digite o padrão que deseja procurar no texto" COR_VERMELHO_CLARO " (0 - Sair): " COR_BRANCO);
        scanf("%[^\n]", padrao);
        getchar();
        if(strcmp(padrao, "0") != 0) {

            inicio = clock();
            inicializa(&shiftAnd, padrao);
            final = clock() - inicio;
            tempoPreProcessamento = ((double)final) / CLOCKS_PER_SEC;

            inicio = clock();
            pesquisaPadraoShiftAnd(&shiftAnd, padrao);
            final = clock() - inicio;
            tempoPesquisa = ((double)final) / CLOCKS_PER_SEC;

            listaOcorrencias(&shiftAnd, padrao);

            if(strcmp(argv[1], "analysis")==ANALISE) {
                printf(COR_VERDE_AGUA_CLARO "\n ------- MODO ANÁLISE ------\n\n");
                printf(COR_BRANCO "Tempo para pré-processar o padrão: %lf segundo(os)\n", tempoPreProcessamento);
                printf(COR_BRANCO "Tempo para pesquisar todos os padrões: %lf segundo(os)\n", tempoPesquisa);
                printf(COR_BRANCO "Tempo total: %lf segundo(os)\n", tempoPesquisa+tempoPreProcessamento);
            }

            printf(COR_AMARELO_CLARO "\nPressione enter para pesquisar novamente..." COR_BRANCO);
            getchar();
        }
    }
    system("clear");
    printf(COR_VERDE_AGUA_CLARO "Volte sempre :)\n" COR_BRANCO);
    return 0;
}
