#include <stdio.h>

int main(){

    int tabuleiro[10][10] = {0};
    int navio1[3] = {3, 3, 3};
    int linhahorizontal = 1, colunahorizontal = 1;  //insira os valores para posicionar o navio horizontal
    int navio2[3] = {3, 3, 3};
    int linhavertical = 5, colunavertical = 7;  //insira os valores para posicionar o navio vertical

    //regras sobre posicionamento

    if (colunahorizontal >= 10 || colunavertical >= 10 || linhahorizontal >= 10 || linhavertical >= 10 ||
        colunahorizontal < 0 || colunavertical < 0 || linhahorizontal < 0 || linhavertical < 0)
        {
            printf("Entrada do Navio invalida!");
            return 0;
        }

    if (colunahorizontal + 3 > 10)
        {
            printf("Navio horizontal ultrapassa o limite!\n");
            return 0;
        }

    if (linhavertical + 3 > 10)
        {
            printf("Navio vertical ultrapassa o limite!\n");
            return 0;
        }

    //posicionando os navios no tabuleiro

        for(int i = 0; i < 3; i++)
        {
            if (tabuleiro[linhahorizontal][colunahorizontal + i] != 0)
            {
                printf("Sobreposicao dos Navios, Tente novamente!\n");
                return 0;
            }

            tabuleiro[linhahorizontal][colunahorizontal + i] = navio1[i];
        }

        for(int j = 0; j < 3; j++)
        {
            if (tabuleiro[linhavertical + j][colunavertical] != 0)
            {
                printf("Sobreposicao dos Navios, Tente novamente!\n");
                return 0;
            }

            tabuleiro[linhavertical + j][colunavertical] = navio2[j];
        }

    //mostrando o tabuleiro 

        for (int i = 0; i < 10; i++)
        { 
            for (int j = 0; j < 10; j++)
            {
                printf("%d  ", tabuleiro[i][j]);
            }
            
          printf("\n");
        }

}