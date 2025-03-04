#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int queroJogar(){

    char resposta;
    char resposta2[5]; 

    printf("Seja Bem vindo ao jogo do numero secreto\n\n");

    printf("Voce deseja jogar?");
    scanf(" %c", &resposta);
    scanf(" %s", &resposta2);

//Bloco aonde vai extrair a resposta do jogador

    if(resposta == 'sim' || resposta == 'Sim'){
        return 0;
    }else{
        return 1;
    }
}
//------------------------------------------------------------------------------------------------------------

//Se a resposta for 'sim', daremos inicio ao jogo...
int main(){
    if(!queroJogar()){
        printf("Jogo encerrado...\n");
        return 0;
    }
//------------------------------------------------------------------------------------------------------------
    
    int numeroSecreto = numeroSecreto % 100; 
    int chuteJogador;
    int tentativas = 1;
    double pontos = 1000;
    
    int acertou = 0;

    printf("Vamos comecar o jogo!!\n\n\n");
//----------------------------------------------------------------------------------------------------------------

    //Fução que ira perguntar ao jogador qual o nivel que ele quer jogar.
    int nivel;
    printf("Qual nivel voce vai querer jogar?");
    printf("(1) facil (2) medio (3) Dificil:    ");
    scanf("%d", &nivel);

    int numeroTentativas;

switch (nivel)
{
    case 1: numeroTentativas = 20;
    break;

    case 2: numeroTentativas = 10;
    break;

    default: numeroTentativas = 6;
    break;
}

//----------------------------------------------------------------------------------------------------------------

//Função para gerar um número aleatorio.
    int segundos = time(0);
    srand(segundos);
    int numeroGrande = rand();

  

 
    for (int i = 1; i <= numeroTentativas; i++){
        
        printf("Tentativas %d\n", tentativas);
        printf("Escolha um numero para comecar: ");
        scanf(" %d", &chuteJogador);

        if(chuteJogador < 0){
            printf("Por favor, chute um numero positivo\n");

            continue;
        }

        int acertou = chuteJogador == numeroSecreto;

        if(acertou){    
            break;
        
        }else{
            int maior = (chuteJogador > numeroSecreto);

            if(maior){
                printf("O numero secreto e menor, tente novamente!\n");
            }
            int menor = (chuteJogador < numeroSecreto);

            if(menor){
                printf("O numero e maior, tente novamente!\n");
            }
        }

        tentativas++;
        double pontosPerdidos = abs (chuteJogador - numeroSecreto) / (double)2;
        pontos = pontos - pontosPerdidos;
}

printf("Fim de jogo\n");
if (acertou){
    printf("Parabens, Você acertou!\n");
    printf("O numero de tentativas foi: %d\n", tentativas);
    printf("Sua pontuação foi de: %.1f\n", pontos);
}else{
    printf("Você perdeu, tente novamente\n");
}



return 0;


}