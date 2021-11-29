#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define total 5
#define randnum(min, max) \
((rand() % (int)(((max) + 1) - (min))) + (min))
int main(){
    char categoria_geral[20] , controle_palavra[12] , controle_acerto[12] , controle_jogador;
    int escolha_menu = 0,escolha_tema = 0, i,tamanho_palavra;  
    char escolha[6];
    //-------------------------------------------BANCO DE DADO DAS PALAVRAS ---------------------------------------------------------//          
    char categoria_escola[total][12] = {"HISTORIA", "MATEMATICA" , "PORTUGUES", "FISICA" , "QUIMICA"};
    char categoria_mercado[total][12] = {"FRUTA", "DOCE", "CARNE", "BEBIDA", "CONGELADOS"};
    // -------------------------------------------------------------------------------------------------------------------------------//
    printf("---------------------------SEJA BEM VINDO AO JOGO DA FORCA------------------------\n\n");
    printf("ESCOLHA O NUMERO DAS OPCOES ABAIXO: \n\n");
    printf("--> 1 : Jogar \n\n");
    printf("--> 2 : Sobre \n\n");
    printf("--> 3 : Sair \n\n");
    printf("--> ");  
    scanf("%d",&escolha_menu);  
    system("clear");  
    escolha_tema = escolha_menu_funcao(escolha_menu,escolha_tema);
    srand(time(NULL));
    switch (escolha_tema)
    {
    case 1:
        strcpy(categoria_geral,"Escola");
        strcpy(controle_palavra,categoria_escola[randnum(1, total) % total]);
        tamanho_palavra = strlen(controle_palavra);
        printf("Palabra random %s\n",controle_palavra);
        thegame(tamanho_palavra,controle_palavra);
        break;

    case 2:
        strcpy(categoria_geral,"Mercado");
        strcpy(controle_palavra,categoria_mercado[randnum(1, total) % total]);
        tamanho_palavra = strlen(controle_palavra);
        printf("Palabra random %s\n",controle_palavra);
        break;

    default:
        break;
    }
}
int escolha_menu_funcao(int escolha_menu,int escolha_tema){
        if (escolha_menu == 1){
            srand(time(NULL));
            printf("---------------------------ESCOLHA O NUMERO DE UMA CATEGORIA------------------------ \n\n");
            printf("--> 1 : Materias da Escola \n\n");
            printf("--> 2 : Produtos do Mercado \n\n");
            printf("--> ");  
            scanf("%d", &escolha_tema);
            system("clear");  
        }
        if(escolha_menu == 2){
            system("clear"); 
            printf("|------------------------------SOBRE O PROGRAMA------------------------------------------|\n");
            printf("|                                                                                        |\n");
            printf("|                              FEITO POR:                                                |\n");
            printf("|                              Reinaldo K.n                                              |\n");
            printf("|                              Vinicus 13 ( o homem )                                    |\n");
            printf("|                                                                                        |\n");
            printf("|----------------------------------------------------------------------------------------|\n");
            return main();
        }
        if(escolha_menu == 3){
            system("clear");  
            printf("Saindo......... \n\n");
            return 0;
            
        }
        if(escolha_menu > 3 || escolha_menu < 1){
            printf(" Escolha invalida !!!! \n\n");
        }
    return escolha_tema;   
} 
void thegame(int tamanho_palavra,char controle_palavra[12]){
    printf("entao vamo jogar \n\n");
    printf("%s\n\n", controle_palavra);
    espaco_letra(tamanho_palavra);
}
void espaco_letra(int tamanho_espaco){
    int i, j;
     for(j=0; j<tamanho_espaco; j++)
    {
        printf("__");
        printf(" ");
    }
}