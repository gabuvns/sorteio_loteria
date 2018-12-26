/*  Sorteador de números da mega-sena
*   Criado por: Gabriel Soares
*   Para a versão mais atualizada e programas como este, acesse: https://github.com/gabuvns
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void bubble_sort (int vetor[], int n) {
    int k, j, aux;

    for (k = 1; k < n; k++) {
        for (j = 0; j < n - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

//Garante que os numeros nao se repitam
int checavetor(int sorteado, int* vetor, int tamanho){
    int j;
    for(j=0; j < tamanho; j++){
        if(sorteado == vetor[j]){
            return 0;
        }
    }

   return 1;
}

void sorteio(){

    int vetor[6];
    int sorteado;
    int tamanho = 6;
    int i = 0;
    int q = 0;

    for(i=0;i<tamanho;i++){
        vetor[i] = 0;
    }

    //Setamos a seed deste modo para evitar que a seed se repita, como por exemplo quando se usa srand(time(NULL))
    struct timespec seed;																	
    clock_gettime(CLOCK_REALTIME, &seed);												
    srand(seed.tv_nsec); 


    for(i=0;i<6;i++){
        sorteado = rand() % 60 + 1;
        if(checavetor(sorteado, vetor, tamanho)){
            vetor[i] = sorteado;                

        }
        else{
            i--;
            
        }
    }
            
    bubble_sort(vetor, tamanho);
    for(q = 0;q < 6; q++){
        printf("%d). Numero Sorteado = %d\n", q+1, vetor[q]);
    }

}

int menu(){
    int qtd;

    float preco = 3.50;

    printf("Bem vindo ao sorteador de números da mega-sena!\n\nDigite o numero de jogos que deseja fazer:\n");
    
    scanf("%d", &qtd);

    while(qtd < 1){
        printf("Por favor, digite um numero maior que 0\n");
        scanf("%d", &qtd);
    }

    printf("Levando em conta o custo de R$3.50 por jogo, voce gastara: R$%.2lf\n\n", preco*qtd);
    
    return qtd;

}

int main(){
    int vezes, k;

    vezes = menu();
    
    for(k=0;k<vezes;k++){
        printf("Jogo numero (%d)\n", k+1);
        sorteio();
        printf("\n\n");
    }
    
    printf("Obrigado por sortear os numeros conosco!\nPrograma encerrado.\n");
    
    return 0;
}