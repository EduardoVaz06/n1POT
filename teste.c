#include <stdio.h>
#include <stdlib.h>

int main(void)
{   
    //gerando o arquivo e escrevendo num array
    int quantidade;

    printf("Selecione a quantidade de numeros: \n");
    scanf("%d", &quantidade);
    
    FILE *arquivo;
    arquivo = fopen("arquivo.txt", "w");
    
    int i;
    int num[quantidade];
    
    srand(time(NULL));
    
    for (i = 0; i < quantidade; i++)
    {
        num[i] = (1 + rand() % 20);  
        printf("%d ", num[i]);
        fprintf(arquivo,"%d ", num[i]);
    }  
    printf("Arquivo gerado!");
    fclose(arquivo);

    // menu
    int selecao;

    printf("Escolha a opção desejada: \n");
    printf("1 - Inverter elementos\n");
    printf("2 - Ordenar Elementos\n");
    printf("3 - Encontrar maior, menor e média\n");
    printf("4 - Converter cada numero para binario\n");

    return 0;
}
