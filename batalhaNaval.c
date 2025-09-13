#include <stdio.h>

void tabuleiro_inicial(int tabuleiro[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    
    int tabuleiro[10][10] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0,}
    };

    int navio1[3] = {3, 3, 3};
    int navio2[3] = {3, 3, 3};

    int linha_inicial_navio1 = 2;
    int linha_inicial_navio2 = 4;
    int coluna_inicial_navio1 = 4;
    int coluna_inicial_navio2 = 7;
    int tamanho_navio1 = 3;
    int tamanho_navio2 = 3;
    
    int pode_posicionar_navio1 = 1;

    // 1. Verifica se o navio ultrapassa o limite
    if (coluna_inicial_navio1 + tamanho_navio1 > 10) {
        pode_posicionar_navio1 = 0;
    } else {
        // 2. Verifica se ha sobreposicao
        for (int i = 0; i < tamanho_navio1; i++) {
            if (tabuleiro[linha_inicial_navio1][coluna_inicial_navio1 + i] != 0) {
                pode_posicionar_navio1 = 0;
                break; // Sai do loop assim que encontrar uma sobreposicao
            }
        }
    }

    // Se o navio puder ser posicionado, faca isso
    if (pode_posicionar_navio1) {
        for (int i = 0; i < tamanho_navio1; i++) {
            tabuleiro[linha_inicial_navio1][coluna_inicial_navio1 + i] = navio1[i];
        }
    } else {
        printf("Nao foi possivel posicionar o Navio 1. Verifique os limites e sobreposicao.\n");
    }

    // --- Lógica para o Navio 2 (VERTICAL) ---
    // Variável para controlar se o navio pode ser posicionado
    int pode_posicionar_navio2 = 1;

    // 1. Verifica se o navio ultrapassa o limite
    if (linha_inicial_navio2 + tamanho_navio2 > 10) {
        pode_posicionar_navio2 = 0;
    } else {
        // 2. Verifica se ha sobreposicao
        for (int i = 0; i < tamanho_navio2; i++) {
            if (tabuleiro[linha_inicial_navio2 + i][coluna_inicial_navio2] != 0) {
                pode_posicionar_navio2 = 0;
                break;
            }
        }
    }

    // Se o navio puder ser posicionado, faca isso
    if (pode_posicionar_navio2) {
        for (int i = 0; i < tamanho_navio2; i++) {
            tabuleiro[linha_inicial_navio2 + i][coluna_inicial_navio2] = navio2[i];
        }
    } else {
        printf("Nao foi possivel posicionar o Navio 2. Verifique os limites e sobreposicao.\n");
    }



    printf("Tabuleiro com os navios posicionados:\n");
    tabuleiro_inicial(tabuleiro);

    return 0;

}
