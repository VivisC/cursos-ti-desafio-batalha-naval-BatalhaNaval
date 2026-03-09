#include <stdio.h>

int main(){

    int tabuleiro[10][10] = {0};
    int navio1[3] = {3, 3, 3};
    int linhahorizontal = 1, colunahorizontal = 1;  //insira os valores para posicionar o navio horizontal
    int navio2[3] = {3, 3, 3};
    int linhavertical = 5, colunavertical = 6;  //insira os valores para posicionar o navio vertical
    int navio3[3][3] = {{3, 0, 0}, {0, 3, 0}, {0, 0, 3}};
    int linhad1 = 2, colunad1 = 6;  //insira os valores para posicionar o navio 3
    int navio4[3][3] = {{0, 0, 3}, {0, 3, 0}, {3, 0, 0}};
    int linhad2 = 6, colunad2 = 2;  //insira os valores para posicionar o navio 4
    int d1, d2, d3, d4;

    //regras sobre posicionamento

    if (colunahorizontal >= 10 || colunavertical >= 10 || linhahorizontal >= 10 || linhavertical >= 10 ||
        colunahorizontal < 0 || colunavertical < 0 || linhahorizontal < 0 || linhavertical < 0 ||
        colunad1 < 0 || colunad2 < 0 || linhad1 < 0 || linhad2 < 0 || colunad1 >= 10 || colunad2 >= 10 ||
        linhad1 >= 10 || linhad2 >= 10)
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
    
    if (linhad1 + 2 < 10 && colunad1 + 2 < 10)
        {
            //coloca o navio
        } else {
            printf("Navio 3 ultrapassa o limite!\n");
            return 0;
        }

    if (linhad2 + 2 < 10 && colunad2 - 2 >= 0)
        {
            //coloca o navio
        } else {
            printf("Navio 4 ultrapassa o limite!\n");
            return 0;
        }

    //posicionando os navios no tabuleiro
    //navio horizontal
        for(int i = 0; i < 3; i++)
        {
            if (tabuleiro[linhahorizontal][colunahorizontal + i] != 0)
            {
                printf("Sobreposicao dos Navios, Tente novamente!\n");
                return 0;
            }

            tabuleiro[linhahorizontal][colunahorizontal + i] = navio1[i];
        }

    //navio vertical

        for(int j = 0; j < 3; j++)
        {
            if (tabuleiro[linhavertical + j][colunavertical] != 0)
            {
                printf("Sobreposicao dos Navios, Tente novamente!\n");
                return 0;
            }

            tabuleiro[linhavertical + j][colunavertical] = navio2[j];
        }

    //navio 3 diagonal

        for (d1 = 0; d1 < 3; d1++)
        {
            for (d2 = 0; d2 < 3; d2++)
            {
                if (navio3[d1][d2] == 3)
                {
                        if (tabuleiro[linhad1 + d1][colunad1 + d2] != 0)
                    {
                        printf("Sobreposicao dos Navios, Tente novamente!\n");
                        return 0;
                    }
                    tabuleiro[linhad1 + d1][colunad1 + d2] = navio3[d2][d1];
                }
            }
        }

    //navio 4 diagonal
    
        for (d3 = 0; d3 < 3; d3++)
        {
            for (d4 = 0; d4 < 3; d4++)
            {
                if (navio4[d3][d4])
                {
                        if (tabuleiro[linhad2 + d3][colunad2 + d4] != 0)
                    {
                        printf("Sobreposicao dos Navios, Tente novamente!\n");
                        return 0;
                    }
                    tabuleiro[linhad2 + d3][colunad2 + d4] = navio4[d3][d4];
                }
            }
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