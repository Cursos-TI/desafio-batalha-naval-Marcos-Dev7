#include <stdio.h>

int main() {
    // Declara e inicializa o tabuleiro 10x10 com 0s (agua)
    int tabuleiro[10][10] = {0};

    // --- Dados dos navios ---
    // Navio 1 (Horizontal)
    int linha_navio1 = 2;
    int coluna_navio1 = 4;
    int tamanho_navio1 = 3;

    // Navio 2 (Vertical)
    int linha_navio2 = 4;
    int coluna_navio2 = 7;
    int tamanho_navio2 = 3;
    
    // Navio 3 (Diagonal Crescente)
    int linha_navio3 = 1;
    int coluna_navio3 = 1;
    int tamanho_navio3 = 3;
    
    // Navio 4 (Diagonal Decrescente)
    int linha_navio4 = 6;
    int coluna_navio4 = 1;
    int tamanho_navio4 = 3;

    // --- Posicionamento do Navio 1 (Horizontal) ---
    int pode_posicionar_navio1 = 1;

    // 1. Verifica se o navio ultrapassa o limite
    if (coluna_navio1 + tamanho_navio1 > 10 || linha_navio1 < 0 || linha_navio1 >= 10 || coluna_navio1 < 0) {
        pode_posicionar_navio1 = 0;
    } else {
        // 2. Verifica se ha sobreposicao
        for (int i = 0; i < tamanho_navio1; i++) {
            if (tabuleiro[linha_navio1][coluna_navio1 + i] != 0) {
                pode_posicionar_navio1 = 0;
                break;
            }
        }
    }
    
    // Se o navio puder ser posicionado, faca isso
    if (pode_posicionar_navio1) {
        for (int i = 0; i < tamanho_navio1; i++) {
            tabuleiro[linha_navio1][coluna_navio1 + i] = 3;
        }
        printf("Navio 1 (Horizontal) posicionado com sucesso.\n");
    } else {
        printf("Nao foi possivel posicionar o Navio 1.\n");
    }
    
    // --- Posicionamento do Navio 2 (Vertical) ---
    int pode_posicionar_navio2 = 1;

    // Verifica se o navio ultrapassa o limite
    if (linha_navio2 + tamanho_navio2 > 10 || linha_navio2 < 0 || linha_navio2 >= 10 || coluna_navio2 < 0 || coluna_navio2 >= 10) {
        pode_posicionar_navio2 = 0;
    } else {
        // 2. Verifica se ha sobreposicao
        for (int i = 0; i < tamanho_navio2; i++) {
            if (tabuleiro[linha_navio2 + i][coluna_navio2] != 0) {
                pode_posicionar_navio2 = 0;
                break;
            }
        }
    }
    
    // Se o navio puder ser posicionado, faca isso
    if (pode_posicionar_navio2) {
        for (int i = 0; i < tamanho_navio2; i++) {
            tabuleiro[linha_navio2 + i][coluna_navio2] = 3;
        }
        printf("Navio 2 (Vertical) posicionado com sucesso.\n");
    } else {
        printf("Nao foi possivel posicionar o Navio 2.\n");
    }
    
    // --- Posicionamento do Navio 3 (Diagonal Crescente) ---
    int pode_posicionar_navio3 = 1;
    
    // Verifica se o navio ultrapassa o limite
    if (linha_navio3 + tamanho_navio3 > 10 || coluna_navio3 + tamanho_navio3 > 10 || linha_navio3 < 0 || linha_navio3 >= 10 || coluna_navio3 < 0 || coluna_navio3 >= 10) {
        pode_posicionar_navio3 = 0;
    } else {
        // 2. Verifica se ha sobreposicao
        for (int i = 0; i < tamanho_navio3; i++) {
            if (tabuleiro[linha_navio3 + i][coluna_navio3 + i] != 0) {
                pode_posicionar_navio3 = 0;
                break;
            }
        }
    }
    
    // Se o navio puder ser posicionado, faca isso
    if (pode_posicionar_navio3) {
        for (int i = 0; i < tamanho_navio3; i++) {
            tabuleiro[linha_navio3 + i][coluna_navio3 + i] = 3;
        }
        printf("Navio 3 (Diagonal Crescente) posicionado com sucesso.\n");
    } else {
        printf("Nao foi possivel posicionar o Navio 3.\n");
    }

    // --- Posicionamento do Navio 4 (Diagonal Decrescente) ---
    int pode_posicionar_navio4 = 1;
    
    // Verifica se o navio ultrapassa o limite
    if (linha_navio4 + tamanho_navio4 > 10 || coluna_navio4 - tamanho_navio4 < -1 || linha_navio4 < 0 || linha_navio4 >= 10 || coluna_navio4 < 0 || coluna_navio4 >= 10) {
        pode_posicionar_navio4 = 0;
    } else {
        // 2. Verifica se ha sobreposicao
        for (int i = 0; i < tamanho_navio4; i++) {
            if (tabuleiro[linha_navio4 + i][coluna_navio4 - i] != 0) {
                pode_posicionar_navio4 = 0;
                break;
            }
        }
    }
    
    // Se o navio puder ser posicionado, faca isso
    if (pode_posicionar_navio4) {
        for (int i = 0; i < tamanho_navio4; i++) {
            tabuleiro[linha_navio4 + i][coluna_navio4 - i] = 3;
        }
        printf("Navio 4 (Diagonal Decrescente) posicionado com sucesso.\n");
    } else {
        printf("Nao foi possivel posicionar o Navio 4.\n");
    }

    // --- Exibir o tabuleiro final ---
    printf("\n--- Tabuleiro Completo ---\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}