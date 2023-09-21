#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double uniforme()
{
    double u = rand() / ((double)RAND_MAX + 1);
    // limitando entre (0,1)
    u = 1.0 - u;
    return (u);
}

int main()
{
    /*
     Na exponencial, E[X] = 1/l
     E[X] = 5
     1/l = 5
     l = 1/5
     l=0.2
    */

    double l;
    printf("Informe o tempo medio (s): ");
    scanf("%lF", &l);
    l = 1.0 / l;

    // variaveis para calculo da media final
    double soma = 0.0;
    double qtd_valores_gerados = 1000000;

    // iniciando para a geracao dos numeros pseudo-aleatorios
    int semente = time(NULL);
    //int semente =10;
    srand(semente);

    for (int i = 0; i < qtd_valores_gerados; i++)
    {
        double valor = (-1.0) / l * log(uniforme());
        //printf("%lF\n", valor);
        //getchar();
        soma += valor;
    }
    printf("media: %lF\n", (soma / qtd_valores_gerados));
    return 0;
}