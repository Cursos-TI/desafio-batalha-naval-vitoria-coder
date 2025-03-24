#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
#define tamanho_Navio 3
int main() {

//definiçao do tamanho do tabuleiro e dos navios;
    const int tamanhoTabuleiro = 10;
    const int tamanhoNavio = 3;
    
   
    char linhas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; //array pra linhas;
    int tabuleiro[10][10]; //matriz pra simular o tabuleiro;
    int i, j;

   for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            tabuleiro[i][j] = 0;
        }
   }

//vetores que representa cada posição dos navios;

int navioHorizontal[tamanho_Navio] = {3, 3, 3};
int navioVertical[tamanho_Navio] = {3, 3, 3};


//coordenadas fixas para os navios;
   int linhaH = 2, colunaH = 3;
   int linhaV = 6, colunaV = 5;


//posição do navio na horizontal;
if(colunaH + tamanhoNavio <= tamanhoTabuleiro){
    int posValido = 1;
    for(i = 0; i < tamanhoNavio; i++){
        if(tabuleiro[linhaH][colunaH + i] != 0){
            posValido = 0;
            break;
        }
    }
    if(posValido){
        for(i = 0; i < tamanhoNavio; i++){
            tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
        }
    }else{
        printf("Posicionamento do navio horizontal inválido: sobreposição..\n");
    }
}else{
    printf("Navio horizontal fora dos limites!\n");
}

//posição do navio na vertical;
if(linhaV + tamanhoNavio <= tamanhoTabuleiro){
    int posValido = 1;
    for(i = 0; i < tamanhoNavio; i++){
        if(tabuleiro[linhaV + i][colunaV] != 0){
            posValido = 0;
            break;
        }
    }

    if(posValido){
        for( i = 0; i < tamanhoNavio; i++){
            tabuleiro[linhaV + i][colunaV] = navioVertical[i];
        }
    }else{
        printf("Posicionamento do navio na vertical inválido: sobreposição..\n");
    }
}else{
        printf("Navio na vertical fora dos limetes!\n");
    }

//exibição do tabuleiro;
printf(" ");
for(j = 0; j < tamanhoTabuleiro; j++){
    printf(" %d", j);
}
printf("\n");

//imprime cada linha;
for(i = 0; i < tamanhoTabuleiro; i++){
    printf("%c ", linhas[i]);
    for(j = 0; j < tamanhoTabuleiro; j++){
        printf(" %d", tabuleiro[i][j]);
    }
    printf("\n");
}

    return 0;
}   
