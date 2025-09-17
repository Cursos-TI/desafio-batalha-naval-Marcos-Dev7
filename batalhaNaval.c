#include <stdio.h>
#include <stdlib.h>

int main() {
    // --- 1. Definir o tabuleiro 10x10 com navios ---
    
    // Declara e inicializa o tabuleiro 10x10 com 0s (agua)
    int tabuleiro[10][10] = {0};

    // Dados dos navios do nivel anterior
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

    // --- Logica para posicionar os navios do nivel anterior ---
    // (A logica de validacao de limites e sobreposicao e a mesma)
    
    // Posicionamento do Navio 1 (Horizontal)
    int pode_posicionar_navio1 = 1;
    if (coluna_navio1 + tamanho_navio1 > 10) pode_posicionar_navio1 = 0;
    else {
        for (int i = 0; i < tamanho_navio1; i++) {
            if (tabuleiro[linha_navio1][coluna_navio1 + i] != 0) {
                pode_posicionar_navio1 = 0;
                break;
            }
        }
    }
    if (pode_posicionar_navio1) {
        for (int i = 0; i < tamanho_navio1; i++) tabuleiro[linha_navio1][coluna_navio1 + i] = 3;
    }

    // Posicionamento do Navio 2 (Vertical)
    int pode_posicionar_navio2 = 1;
    if (linha_navio2 + tamanho_navio2 > 10) pode_posicionar_navio2 = 0;
    else {
        for (int i = 0; i < tamanho_navio2; i++) {
            if (tabuleiro[linha_navio2 + i][coluna_navio2] != 0) {
                pode_posicionar_navio2 = 0;
                break;
            }
        }
    }
    if (pode_posicionar_navio2) {
        for (int i = 0; i < tamanho_navio2; i++) tabuleiro[linha_navio2 + i][coluna_navio2] = 3;
    }
    
    // Posicionamento do Navio 3 (Diagonal Crescente)
    int pode_posicionar_navio3 = 1;
    if (linha_navio3 + tamanho_navio3 > 10 || coluna_navio3 + tamanho_navio3 > 10) pode_posicionar_navio3 = 0;
    else {
        for (int i = 0; i < tamanho_navio3; i++) {
            if (tabuleiro[linha_navio3 + i][coluna_navio3 + i] != 0) {
                pode_posicionar_navio3 = 0;
                break;
            }
        }
    }
    if (pode_posicionar_navio3) {
        for (int i = 0; i < tamanho_navio3; i++) tabuleiro[linha_navio3 + i][coluna_navio3 + i] = 3;
    }
    
    // Posicionamento do Navio 4 (Diagonal Decrescente)
    int pode_posicionar_navio4 = 1;
    if (linha_navio4 + tamanho_navio4 > 10 || coluna_navio4 - tamanho_navio4 < -1) pode_posicionar_navio4 = 0;
    else {
        for (int i = 0; i < tamanho_navio4; i++) {
            if (tabuleiro[linha_navio4 + i][coluna_navio4 - i] != 0) {
                pode_posicionar_navio4 = 0;
                break;
            }
        }
    }
    if (pode_posicionar_navio4) {
        for (int i = 0; i < tamanho_navio4; i++) tabuleiro[linha_navio4 + i][coluna_navio4 - i] = 3;
    }
    
    // --- 2. Definir e Sobrepor Habilidades ao Tabuleiro ---
    
    // --- Habilidade 1: Cone ---
    // Matriz de habilidade (5x5 para representar o cone)
    int cone[5][5] = {0};
    int centro_cone_matriz = 2; // Centro da matriz de habilidade (2,2)
    
    // Construir a forma de cone com condicionais
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // A forma de cone e' criada quando a largura (j) e' menor ou igual a i
            if (j >= centro_cone_matriz - i && j <= centro_cone_matriz + i) {
                cone[i][j] = 1;
            }
        }
    }

    // Ponto de origem do cone no tabuleiro
    int linha_origem_cone = 0;
    int coluna_origem_cone = 4;

    // Sobrepor o cone no tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // Calcula a posicao no tabuleiro a partir da matriz de habilidade
            int tab_linha = linha_origem_cone + i - centro_cone_matriz;
            int tab_coluna = coluna_origem_cone + j - centro_cone_matriz;
            
            // Verifica se a posicao esta dentro dos limites do tabuleiro (10x10)
            if (tab_linha >= 0 && tab_linha < 10 && tab_coluna >= 0 && tab_coluna < 10) {
                if (cone[i][j] == 1 && tabuleiro[tab_linha][tab_coluna] == 0) {
                    tabuleiro[tab_linha][tab_coluna] = 5; // Marca a area afetada com 5
                }
            }
        }
    }
    
    // --- Habilidade 2: Cruz ---
    // Matriz de habilidade (5x5 para representar a cruz)
    int cruz[5][5] = {0};
    int centro_cruz_matriz = 2; // Centro da matriz (2,2)
    
    // Construir a forma de cruz com condicionais
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // Condicao para formar a cruz: se a linha ou a coluna for o centro
            if (i == centro_cruz_matriz || j == centro_cruz_matriz) {
                cruz[i][j] = 1;
            }
        }
    }
    
    // Ponto de origem da cruz no tabuleiro
    int linha_origem_cruz = 6;
    int coluna_origem_cruz = 4;
    
    // Sobrepor a cruz no tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int tab_linha = linha_origem_cruz + i - centro_cruz_matriz;
            int tab_coluna = coluna_origem_cruz + j - centro_cruz_matriz;
            
            if (tab_linha >= 0 && tab_linha < 10 && tab_coluna >= 0 && tab_coluna < 10) {
                if (cruz[i][j] == 1 && tabuleiro[tab_linha][tab_coluna] == 0) {
                    tabuleiro[tab_linha][tab_coluna] = 5;
                }
            }
        }
    }
    
    // --- Habilidade 3: Octaedro (Losango) ---
    // Matriz de habilidade (5x5 para o octaedro)
    int octaedro[5][5] = {0};
    int centro_octaedro_matriz = 2; // Centro da matriz (2,2)
    
    // Construir a forma de octaedro (losango)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            // Calcula a "distancia de Manhattan" do centro da matriz
            int distancia = abs(i - centro_octaedro_matriz) + abs(j - centro_octaedro_matriz);
            // A forma de losango e' criada quando a distancia e' menor ou igual a 2 (tamanho do "raio")
            if (distancia <= 2) {
                octaedro[i][j] = 1;
            }
        }
    }
    
    // Ponto de origem do octaedro no tabuleiro
    int linha_origem_octaedro = 7;
    int coluna_origem_octaedro = 2;
    
    // Sobrepor o octaedro no tabuleiro
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int tab_linha = linha_origem_octaedro + i - centro_octaedro_matriz;
            int tab_coluna = coluna_origem_octaedro + j - centro_octaedro_matriz;
            
            if (tab_linha >= 0 && tab_linha < 10 && tab_coluna >= 0 && tab_coluna < 10) {
                if (octaedro[i][j] == 1 && tabuleiro[tab_linha][tab_coluna] == 0) {
                    tabuleiro[tab_linha][tab_coluna] = 5;
                }
            }
        }
    }

    // --- 3. Exibir o tabuleiro final ---
    printf("--- Tabuleiro Completo com Navios e Habilidades ---\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (tabuleiro[i][j] == 0) {
                printf("~ "); // Agua
            } else if (tabuleiro[i][j] == 3) {
                printf("N "); // Navio
            } else if (tabuleiro[i][j] == 5) {
                printf("X "); // Area de habilidade
            } else {
                printf("%d ", tabuleiro[i][j]); // Caso de valores inesperados
            }
        }
        printf("\n");
    }

    return 0;
}