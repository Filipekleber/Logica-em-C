#include <stdio.h>

int queroJogar(){

    char resposta;
    char resposta2[5]; 

    printf("Seja Bem vindo ao jogo do numero secreto\n\n");

    printf("Voce deseja jogar?");
    scanf(" %c", &resposta);
    scanf(" %s", &resposta2);

//Bloco aonde vai extrair a resposta do jogador

    if(resposta == 's' || resposta == 'S' || resposta == 'sim' || resposta == 'Sim'){
        return 1;
    }else{
        return 0;
    }
}
//------------------------------------------------------------------------------------------------------------

//Se a resposta for 'sim', daremos inicio ao jogo...
int main(){
    if(!queroJogar()){
        printf("Jogo encerrado...\n");
        return 0;
    }
    printf("Vamos comecar o jogo!!\n\n\n");

    int numeroSecreto = 30; 
    int chuteJogador;

    printf("Escolha um numero para comecar: ");
    scanf(" %d", &chuteJogador);

    int acertou = chuteJogador == numeroSecreto;

    if(acertou){

        printf("Parabens, Você acertou!");

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

return 0;


}