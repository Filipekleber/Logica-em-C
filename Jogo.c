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
    int tentativas = 1;
    int pontos = 1000;

    while (1)
    {
        printf("Tentativas %d\n", tentativas);
        printf("Escolha um numero para comecar: ");
        scanf(" %d", &chuteJogador);

        if(chuteJogador < 0){
            printf("Por favor, chute um numero positivo\n");

            continue;
        }

        int acertou = chuteJogador == numeroSecreto;

        if(acertou){
            printf("Parabens, Você acertou!");
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
        int pontosPerdidos = (chuteJogador - numeroSecreto) / 2;
        pontos = pontos - pontosPerdidos;
}

printf("O numero de tentativas foi: %d\n", tentativas);
printf("Sua pontuação foi de: %d\n", pontos);

return 0;


}