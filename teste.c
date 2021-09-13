#include <stdio.h>
#include <stdlib.h>

int main(void)
{   
    //gerando o arquivo e escrevendo num array
    int quantidade;

    printf("Serao gerados numeros aleatorios de 1 a 20 (para melhor organizacao\n\n");
    printf("Selecione a quantidade de numeros(minimo 100): \n");
    scanf("%d", &quantidade);
    
    FILE *arquivo;
    arquivo = fopen("arquivo.txt", "w");
    
    int i;
    int num[quantidade];
    int vet[quantidade];
    int vet_ord[quantidade];
    int j;
    int aux;
    
    srand(time(NULL));
    
    for (i = 0; i < quantidade; i++)
    {
        num[i] = (1 + rand() % 20);  
        printf("%d ", num[i]);
        fprintf(arquivo,"%d ", num[i]);
    }  
    printf("\nArquivo gerado!\n");
    
    fclose(arquivo);

    // menu
    int selecao;

    do
    {
    printf("Escolha a opcao desejada: \n");
    printf("1 - Inverter elementos\n");
    printf("2 - Ordenar Elementos\n");
    printf("3 - Encontrar maior, menor e media\n");
    printf("4 - Converter cada numero para binario\n");
    printf("5 - Sair\n");
    scanf("%d", &selecao);
        switch(selecao)
        {
        case 1:
        system("cls");

        arquivo = fopen("arquivoinvertido.txt", "w");
        
        for (i = 0; i < quantidade; i++)
        {
        vet[i] = num[quantidade-i-1];
        printf("%d ", vet[i]);
        fprintf(arquivo,"%d ", vet[i]);
        }
        fclose(arquivo);
        printf("\n");
        
        break;

        case 2:
        system("cls");
         for(i=quantidade-2; i>=0; i--)
        {
            for(j=0; j<=i; j++)
            {
                if(num[j] > num[j+1])
                {
                    aux = num[j];
                    num[j] = num[j+1];
                    num[j+1] = aux;
                }
            }
        }

        arquivo = fopen("arquivo_ordenado.txt", "w");
        
            for(j = 0; j < quantidade; j++)
            {
                vet_ord[i] = num[j];
                printf("%d ", vet_ord[i]);
                fprintf(arquivo,"%d ", vet_ord[i]);
            }
        
        fclose(arquivo);
        printf("\n");
        break;

        case 3:
        system("cls");
        int soma = 0;
        int media;

         for(i=quantidade-2; i>=0; i--)
        {
            for(j=0; j<=i; j++)
            {
                if(num[j] > num[j+1])
                {
                    aux = num[j];
                    num[j] = num[j+1];
                    num[j+1] = aux;
                }
            }
        }
        
        arquivo = fopen("arquivo_calculos.txt", "w");

        printf("Menor: %d\n", num[0]);
        printf("Maior: %d\n", num[quantidade-1]);

        fprintf(arquivo,"Menor: %d\n", num[0]);
        fprintf(arquivo,"Maior: %d\n", num[quantidade-1]);

                for(i = 0; i < quantidade; i++)
                {
                soma = soma + num[i];
                }
                media = (soma / (quantidade));
                printf("Media = %d\n", media);
                fprintf(arquivo, "Media = %d\n", media);

        fclose(arquivo);
        printf("\n");
        break;

        case 4:
        system("cls");
        break;

        case 5:
        system("cls");
        printf("Saindo");
        break;

        default:
        system("cls");
        printf("\nOpcao invalida\n");
        break;
        }
    } while (selecao != 5);

    return 0;
}
