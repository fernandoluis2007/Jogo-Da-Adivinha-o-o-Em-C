#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    //cabeçalho do nosso jogo
    printf("***************************************\n");
    printf("Bem vindo ao nosso jogo de adivinhacao\n");
    printf("***************************************\n");

    int segundos = time(0);
    srand(segundos);

    int nuemroGrande = rand();

    int numeroSecreto = nuemroGrande % 100;

    int chute;
    int ganhou = 0;
    int tentativas = 0;

    double pontos = 1000;

    int acertou = 0;

    int nivel;
    printf("Qual o nivel de dificuldade?\n");
    printf("[1] Facil  [2] Medio  [3] Dificil \n\n");
    printf("Escolha: ");
    scanf("%d", &nivel); //váriavel nivel recebe o valor pelo scanf

    int numerodeTentativas;

    switch(nivel)//passo a váriavel que vamos vereficar
    { 
        case 1: //caso 1
            numerodeTentativas = 20;
            break; //para quebrar o switch, para não ocorrer erro

        case 2: //caso 2
            numerodeTentativas = 15;
            break;

        default: //como fosse um else, caso contrário
            numerodeTentativas = 5;
            break;
    }

    // printf("o numero secreto definido pela maquina e..e..e.. %d", numeroSecreto); //usando maskara para poder apresentar a variavel no texto
    //for(int i = 1; i <= NUMERO_DE_TENTATIVA; i++){

    //while(ganhou == 0) {
    for(int i = 1; i <= numerodeTentativas; i++){

        printf("Tentativa %d\n", tentativas+1);
        printf("Qual eh o seu chute: \n");

        scanf("%d", &chute);
        printf("Seu chute foi %d\n", chute);

        if(chute < 0){
            printf("O seu chute, não pode ser negativo");
            continue;
        }

        acertou = (chute == numeroSecreto);
        int maior = chute > numeroSecreto;

        if(acertou){
            //Parar o Loop!
            ganhou = 1;
        }

        else if(maior){
            printf("Seu chute eh maior, que o numero secreto!\n");
        }

        else {
            printf("Seu chute eh menor, que o numero secreto!\n");
        }

        tentativas++;

        double pontosPerdidos = abs(chute - numeroSecreto) / (double)2.0;
        pontos = pontos - pontosPerdidos;
    }

    printf("Fim de jogo!\n");

    if(acertou){
        printf("Voce ganhou!\n");
        printf("Voce acertou em %d tentativas!\n", tentativas);
        printf("Total de pontos: %.1f\n", pontos);
    }else{
        printf("Voce perdeu! Tente de novo!\n");
    }

}