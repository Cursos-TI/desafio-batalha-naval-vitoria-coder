#include <stdio.h>
#include <stdlib.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
#define tamanho_Navio 3
#define tamanho_Tabuleiro 10
#define tamanho_Habilidade 5
int main() {

//definiçao do tamanho do tabuleiro e dos navios;
    char linhas[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'}; //array pra linhas;
    int tabuleiro[tamanho_Tabuleiro][tamanho_Tabuleiro]; //matriz pra simular o tabuleiro;
    int i, j;

//inicializa o tabuleiro com 0(água);
   for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            tabuleiro[i][j] = 0;
        }
   }

//vetores que representa cada posição dos navios;

int navioHorizontal[tamanho_Navio] = {3, 3, 3};
int navioVertical[tamanho_Navio] = {3, 3, 3};
int navioDiagonal[tamanho_Navio] = {3, 3, 3};
int navioDiagonal2[tamanho_Navio] = {3, 3, 3};


//coordenadas fixas para os navios;
   int linhaH = 2, colunaH = 3;
   int linhaV = 6, colunaV = 5;
   int linhaD = 7, colunaD = 6;
   int linhaE = 7, colunaE = 2; 



//posição do navio na horizontal;
if(colunaH + tamanho_Navio <= tamanho_Tabuleiro){
    int posValido = 1;
    for(i = 0; i < tamanho_Navio; i++){
        if(tabuleiro[linhaH][colunaH + i] != 0){
            posValido = 0;
            break;
        }
    }
    if(posValido){
        for(i = 0; i < tamanho_Navio; i++){
            tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
        }
    }else{
        printf("Posicionamento do navio horizontal inválido: sobreposição..\n");
    }
}else{
    printf("Navio horizontal fora dos limites!\n");
}

//posição do navio na vertical;
if(linhaV + tamanho_Navio <= tamanho_Tabuleiro){
    int posValido = 1;
    for(i = 0; i < tamanho_Navio; i++){
        if(tabuleiro[linhaV + i][colunaV] != 0){
            posValido = 0;
            break;
        }
    }

    if(posValido){
        for( i = 0; i < tamanho_Navio; i++){
            tabuleiro[linhaV + i][colunaV] = navioVertical[i];
        }
    }else{
        printf("Posicionamento do navio na vertical inválido: sobreposição..\n");
    }
}else{
        printf("Navio na vertical fora dos limetes!\n");
    }

//posição do návio na diagonal;
if(linhaD + tamanho_Navio <= tamanho_Tabuleiro && colunaD + tamanho_Navio <= tamanho_Tabuleiro){
    int posValido = 1;

    for(i = 0; i < tamanho_Navio; i++){
        if(tabuleiro[linhaD + i][colunaD + i] != 0){
            posValido = 0;
            break;
        }
    }
    if(posValido){
        for(i = 0; i < tamanho_Navio; i++){
            tabuleiro[linhaD + i][colunaD + i] = navioDiagonal[i];
        }
    }else{
        printf("Posicionamento do navio na diagonal inválido: sobreposição..\n");
    }
}else{
    printf("Navio na diagonal fora dos limites!\n");
}


//posição do SEGUNDO navio na diagonal;
if(linhaE + tamanho_Navio <= tamanho_Tabuleiro && colunaE + tamanho_Navio <= tamanho_Tabuleiro){
    int posValido = 1;

    for(i = 0; i < tamanho_Navio; i++){
        if(tabuleiro[linhaE + i][colunaE + i] != 0){
            posValido = 0;
            break;
        }
    }
    if(posValido){
        for( i = 0; i < tamanho_Navio; i++){
            tabuleiro[linhaE + i][colunaE + i] = navioDiagonal2[i];
        }
    }else{
        printf("Posicionamento do navio na Diagonal inválido: sobreposição..\n");
    }
}else{
    printf("Navio na diagonal fora dos limites!\n");
}

//MATRIZ DE HABILIDADE CONE(5X5);
int habilidadeCone[tamanho_Habilidade][tamanho_Habilidade];

//MATRIZ DE HABILIDADE CONE INICIALIZANDO COM 0;
for(i = 0; i < tamanho_Habilidade; i++){
    for(j = 0; j < tamanho_Habilidade; j++){
        habilidadeCone[i][j] = 0;
    }
}

habilidadeCone[0][2] = 1;
habilidadeCone[1][1] = 1;
habilidadeCone[1][2] = 1;
habilidadeCone[1][3] = 1;

for(j = 0; j < tamanho_Habilidade; j++){
    habilidadeCone[2][j];
}

//MATRIZ DA HABILIDADE CRUZ;
int habilidadeCruz[tamanho_Habilidade][tamanho_Habilidade];

for(i = 0; i < tamanho_Habilidade; i++){
    for(j = 0; j < tamanho_Habilidade; j++){
        if(i == tamanho_Habilidade / 2 || j == tamanho_Habilidade / 2){
            habilidadeCruz[i][j] = 1;
        }else{
            habilidadeCruz[i][j] = 0;
        }
    }
}

//MATRIZ DE HABILIDADE OCTAEDRO;
int habilidadeOctaedro[tamanho_Habilidade][tamanho_Habilidade];

for(i = 0; i < tamanho_Habilidade; i++){
    for(j = 0; j < tamanho_Habilidade; j++){

        if( abs(i - (tamanho_Habilidade / 2)) + abs(j - (tamanho_Habilidade / 2)) <= 2){
            habilidadeOctaedro[i][j] = 1;
        }else{
            habilidadeOctaedro [i][j] = 0;
        }
    }
}

//cada habilidade vai ter um ponto de origem no tabuleiro, onde vai ser aplicado sua área de efeito;
//integração das "habilidades" no tabuleiro;

//INTEGRAÇÃO DA HABILIDADE CONE NO TABULEIRO;
int origemConeLinha = 4, origemConeColuna = 4;
int centroHabilidade = tamanho_Habilidade / 2;

for( i = 0; i < tamanho_Habilidade; i++){
    for(j = 0; j < tamanho_Habilidade; j++){
        int posTabLinha = origemConeLinha - centroHabilidade + i;
        int posTabCol = origemConeColuna - centroHabilidade + j;
        if(posTabLinha >= 0 && posTabLinha < tamanho_Tabuleiro && posTabCol
        >= 0 && posTabCol < tamanho_Tabuleiro){
              //só ira atualizar se a posição estiver livre;
            if(habilidadeCone[i][j] == 1){
                if(tabuleiro[posTabLinha][posTabCol] ==0){
                    tabuleiro[posTabLinha][posTabCol] = 5;
                }
            }
        }
    }
}

//INTEGRAÇÃO DA HABILIDADE CRUZ NO TABULEIRO;
int origemCruzLinha = 1, origemCruzColuna = 7;

for(i = 0; i < tamanho_Habilidade; i++){
    for(j = 0; j < tamanho_Habilidade; j++){
        int posTabLinha = origemCruzLinha - centroHabilidade + i;
        int posTabCol = origemCruzColuna - centroHabilidade + j;
        if(posTabLinha >= 0 && posTabLinha < tamanho_Tabuleiro &&
        posTabCol >= 0 && posTabCol < tamanho_Tabuleiro){
            if(habilidadeCruz[i][j] == 1){
                if(tabuleiro[posTabLinha][posTabCol] == 0){
                    tabuleiro[posTabLinha][posTabCol] = 5;
                }
            }
        }
    }
}

//INTEGRAÇÃO DA HABILIDADE OCTAEDRO NO TABULEIRO;
int origemOctaedroLinha = 8, origemOctaedroColuna = 2;

for(i = 0; i < tamanho_Habilidade; i++){
    for(j = 0; j < tamanho_Habilidade; j++){
        int posTabLinha = origemOctaedroLinha - centroHabilidade + i;
        int posTabCol = origemOctaedroColuna - centroHabilidade + j;
        if(posTabLinha >= 0 && posTabLinha < tamanho_Tabuleiro && posTabCol >=
        0 && posTabCol < tamanho_Tabuleiro){
            if(habilidadeOctaedro[i][j] == 1){
                if(tabuleiro[posTabLinha][posTabCol] == 0){
                    tabuleiro[posTabLinha][posTabCol] = 5;
                }
            }
        }
    }
}

//EXIBIÇÃO FINAL DO TABULEIRO;
printf(" ");
for(j = 0; j < tamanho_Tabuleiro; j++){
    printf(" %d", j);
}
printf("\n");

//imprime cada linha;
for(i = 0; i < tamanho_Tabuleiro; i++){
    printf("%c ", linhas[i]);
    for(j = 0; j < tamanho_Tabuleiro; j++){
        printf(" %d", tabuleiro[i][j]);
    }
    printf("\n");
}

    return 0;
}   
