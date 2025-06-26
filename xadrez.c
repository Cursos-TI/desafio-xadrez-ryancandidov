#include <stdio.h>

// Constantes para direções
#define CIMA "Cima\n"
#define BAIXO "Baixo\n"
#define ESQUERDA "Esquerda\n"
#define DIREITA "Direita\n"

// Protótipos das funções
void movimentoNovato();
void movimentoAventureiro();
void movimentoMestre();
void moverTorreRecursivo(int casas);
void moverRainhaRecursivo(int casas);
void moverBispoRecursivo(int casas);

int main() {
    printf("=== MATE CHESS - TODOS OS NÍVEIS INTEGRADOS ===\n\n");
    
    printf("----- NÍVEL NOVATO -----\n");
    movimentoNovato();
    
    printf("\n----- NÍVEL AVENTUREIRO -----\n");
    movimentoAventureiro();
    
    printf("\n----- NÍVEL MESTRE -----\n");
    movimentoMestre();
    
    return 0;
}

// Implementação do nível Novato
void movimentoNovato() {
    // Bispo: 5 casas na diagonal superior direita
    printf("Bispo: 5 casas diagonal superior direita\n");
    for (int i = 0; i < 5; i++) {
        printf(CIMA);
        printf(DIREITA);
    }
    
    // Torre: 5 casas para a direita
    printf("\nTorre: 5 casas para a direita\n");
    int count = 0;
    while (count < 5) {
        printf(DIREITA);
        count++;
    }
    
    // Rainha: 8 casas para a esquerda
    printf("\nRainha: 8 casas para a esquerda\n");
    count = 0;
    do {
        printf(ESQUERDA);
        count++;
    } while (count < 8);
}

// Implementação do nível Aventureiro
void movimentoAventureiro() {
    // Cavalo: movimento em L (2 baixo, 1 esquerda)
    printf("Cavalo: movimento em L (2 baixo, 1 esquerda)\n");
    
    // Primeira parte do L (2 para baixo)
    for (int i = 0; i < 2; i++) {
        printf(BAIXO);
    }
    
    // Segunda parte do L (1 para esquerda)
    int count = 0;
    while (count < 1) {
        printf(ESQUERDA);
        count++;
    }
    
    // Versão com loops aninhados para múltiplos L
    printf("\nPadrão do Cavalo com loops aninhados (3 L's):\n");
    for (int l = 0; l < 3; l++) {
        int down = 0;
        while (down < 2) {
            printf(BAIXO);
            down++;
        }
        printf(ESQUERDA);
    }
}

// Implementação do nível Mestre
void movimentoMestre() {
    // Bispo: 5 casas diagonal direita para cima com loops aninhados
    printf("Bispo: 5 casas diagonal direita para cima (loops aninhados)\n");
    for (int i = 0, j = 0; i < 5 && j < 5; i++, j++) {
        printf(CIMA);
        printf(DIREITA);
        if (i == 2) {
            printf("(continue usado aqui)\n");
            continue;
        }
        if (j == 4) {
            printf("(break usado aqui)\n");
            break;
        }
    }
    
    // Torre: 5 casas para a direita (recursivo)
    printf("\nTorre: 5 casas para a direita (função recursiva)\n");
    moverTorreRecursivo(5);
    
    // Rainha: 8 casas para a esquerda (recursivo)
    printf("\nRainha: 8 casas para a esquerda (função recursiva)\n");
    moverRainhaRecursivo(8);
    
    // Cavalo: 1 movimento em L para cima à direita (2 cima, 1 direita)
    printf("\nCavalo: 1 L para cima à direita (2 cima, 1 direita)\n");
    for (int up = 0, right = 0; up < 2 || right < 1; ) {
        if (up < 2) {
            printf(CIMA);
            up++;
            continue;
        }
        if (right < 1) {
            printf(DIREITA);
            right++;
        }
    }
    
    // Bispo: 5 casas diagonal direita para cima (recursivo)
    printf("\n\nBispo: 5 casas diagonal direita para cima (função recursiva)\n");
    moverBispoRecursivo(5);
}

// Funções recursivas para o nível Mestre
void moverTorreRecursivo(int casas) {
    if (casas <= 0) return;
    printf(DIREITA);
    moverTorreRecursivo(casas - 1);
}

void moverRainhaRecursivo(int casas) {
    if (casas <= 0) return;
    printf(ESQUERDA);
    moverRainhaRecursivo(casas - 1);
}

void moverBispoRecursivo(int casas) {
    if (casas <= 0) return;
    printf(CIMA);
    printf(DIREITA);
    moverBispoRecursivo(casas - 1);
}