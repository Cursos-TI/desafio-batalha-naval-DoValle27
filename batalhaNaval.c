#include <stdio.h>

#define TAMANHO 10

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO][TAMANHO]) {
    printf("Tabuleiro:\n");
    
    for (int i = 0; i < TAMANHO; i++) {
        for (int j = 0; j < TAMANHO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função para posicionar um navio horizontalmente
void posicionarNavioHorizontal(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha][coluna + i] = 3;
    }
}

// Função para posicionar um navio verticalmente
void posicionarNavioVertical(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    for (int i = 0; i < 3; i++) {
        tabuleiro[linha + i][coluna] = 3;
    }
}

// Função para sobrepor a habilidade Cone ao tabuleiro
void aplicarHabilidadeCone(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (linha + 2 < TAMANHO && coluna - 1 >= 0 && coluna + 1 < TAMANHO) {
        tabuleiro[linha][coluna] = 5;
        tabuleiro[linha + 1][coluna - 1] = 5;
        tabuleiro[linha + 1][coluna] = 5;
        tabuleiro[linha + 1][coluna + 1] = 5;
        tabuleiro[linha + 2][coluna] = 5;
    }
}

// Função para sobrepor a habilidade Cruz ao tabuleiro
void aplicarHabilidadeCruz(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (linha - 1 >= 0) tabuleiro[linha - 1][coluna] = 5;
    if (linha + 1 < TAMANHO) tabuleiro[linha + 1][coluna] = 5;
    if (coluna - 1 >= 0) tabuleiro[linha][coluna - 1] = 5;
    if (coluna + 1 < TAMANHO) tabuleiro[linha][coluna + 1] = 5;
    tabuleiro[linha][coluna] = 5;
}

// Função para sobrepor a habilidade Octaedro ao tabuleiro
void aplicarHabilidadeOctaedro(int tabuleiro[TAMANHO][TAMANHO], int linha, int coluna) {
    if (linha - 1 >= 0) tabuleiro[linha - 1][coluna] = 5;
    if (linha + 1 < TAMANHO) tabuleiro[linha + 1][coluna] = 5;
    if (coluna - 1 >= 0) tabuleiro[linha][coluna - 1] = 5;
    if (coluna + 1 < TAMANHO) tabuleiro[linha][coluna + 1] = 5;
    if (linha - 1 >= 0 && coluna - 1 >= 0) tabuleiro[linha - 1][coluna - 1] = 5;
    if (linha - 1 >= 0 && coluna + 1 < TAMANHO) tabuleiro[linha - 1][coluna + 1] = 5;
    if (linha + 1 < TAMANHO && coluna - 1 >= 0) tabuleiro[linha + 1][coluna - 1] = 5;
    if (linha + 1 < TAMANHO && coluna + 1 < TAMANHO) tabuleiro[linha + 1][coluna + 1] = 5;
    tabuleiro[linha][coluna] = 5;
}

int main() {
    int tabuleiro[TAMANHO][TAMANHO];
    
    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);
    
    // Posiciona os navios
    posicionarNavioHorizontal(tabuleiro, 2, 3);
    posicionarNavioVertical(tabuleiro, 5, 7);
    
    // Aplica habilidades
    aplicarHabilidadeCone(tabuleiro, 1, 5);
    aplicarHabilidadeCruz(tabuleiro, 4, 4);
    aplicarHabilidadeOctaedro(tabuleiro, 7, 2);
    
    // Exibe o tabuleiro
    exibirTabuleiro(tabuleiro);
    
    return 0;
}
