#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define abs(x) ((x) > 0 ? (x) : -(x))
#define sgn(x) ((x) > 0 ? 1 : -1)


typedef struct
{
    int valor;
    int quantidade;
    int movimentado;
} dinheiro;

int total_caixa(dinheiro caixa[], size_t size_caixa);
void fazer_saque(dinheiro caixa[], int saque, size_t size_caixa);

int main(int argc, char *argv[])
{

    dinheiro caixa[] = {
        { .valor = 20000, .quantidade = 2 }, /* 200   reais  */
        { .valor = 10000, .quantidade = 2 }, /* 100   reais  */
        { .valor =  5000, .quantidade = 0 }, /*  50   reais  */
        { .valor =  2000, .quantidade = 0 }, /*  20   reais  */
        { .valor =  1000, .quantidade = 0 }, /*  10   reais  */
        { .valor =   500, .quantidade = 0 }, /*   5   reais  */
        { .valor =   200, .quantidade = 0 }, /*   2   reais  */
        { .valor =   100, .quantidade = 0 }, /*   1   real   */
        { .valor =    50, .quantidade = 0 }, /*  50 centavos */
        { .valor =    25, .quantidade = 0 }, /*  25 centavos */
        { .valor =    10, .quantidade = 0 }, /*  10 centavos */
        { .valor =     5, .quantidade = 0 }, /*   5 centavos */
        { .valor =     1, .quantidade = 0 }, /*   1 centavo  */

    };

    int montante;

    if (argc == 2)
    {
        montante = atoi(argv[1]) * 100;
    }
    else
    {
        // int montante = -7854793;
        montante = 7854793;
    }


    size_t size_caixa = sizeof (caixa) / sizeof (caixa[0]);

    printf("TOTAL CAIXA = %.2lf\n", total_caixa(caixa, size_caixa) / 100.0);

    fazer_saque(caixa, montante, size_caixa);

    printf("FINAL TOTAL CAIXA = %.2lf\n", total_caixa(caixa, size_caixa) / 100.0);

    exit(EXIT_SUCCESS);

}

int total_caixa(dinheiro caixa[], size_t size_caixa)
{

    int total = 0;

    for (size_t i = 0; i < size_caixa; ++i)
        total += caixa[i].quantidade * caixa[i].valor;

    return total;

}

void fazer_saque(dinheiro caixa[], int saque, size_t size_caixa)
{

    for (size_t i = 0; i < size_caixa; ++i)
    {
        printf("i = %zu | saque = %d | valor = %.2lf\n", i, saque, caixa[i].valor / 100.0);
        caixa[i].movimentado = 0;
        caixa[i].movimentado = saque / caixa[i].valor;

        if (!caixa[i].movimentado)
            continue;

        printf("movimentado = %d | quantidade = %d\n", caixa[i].movimentado, caixa[i].quantidade);

        if (!sgn(caixa[i].movimentado) && abs(caixa[i].movimentado) > caixa[i].quantidade)
        {
            printf("1. IF movimentado = %d | quantidade = %d\n", caixa[i].movimentado, caixa[i].quantidade);
            caixa[i].movimentado = -caixa[i].quantidade;
            printf("2. IF movimentado = %d | quantidade = %d\n", caixa[i].movimentado, caixa[i].quantidade);
        }

        saque -= caixa[i].valor * caixa[i].movimentado;

    }

    if (saque < 0)
    {
        printf("Operação não realizada!\n");
        return;
    }

    for (size_t i = 0; i < size_caixa; ++i)
    {
        caixa[i].quantidade += caixa[i].movimentado;
        printf("caixa[%zu]: valor = R$ %.2f, quantidade = %u, movimentado = %d, montante = %d\n",
        i, caixa[i].valor / 100.0, caixa[i].quantidade, caixa[i].movimentado, saque);
    }

}
