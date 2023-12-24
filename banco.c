#include "cliente.h"

/**************
* FUNÇÃO MAIN *
**************/


int main(void)
{

    cliente_t cliente;

    char id_cliente[37];

    criar_cliente(&cliente);

    uuid_unparse(cliente.id, id_cliente);

    deposito(50000, &cliente);
    saque(2000, &cliente);
    saque(44000, &cliente);

    limites_cliente_t lim_max = cliente.limites.maximo;
    limites_cliente_t lim_uti = cliente.limites.utilizado;


    printf("ID: %s\nSaldo: R$ %.2lf\n", id_cliente, cliente.saldo / 100.0);
    printf("Limite pagamento: %.2lf de R$ %.2lf\n", lim_uti.pagamento / 100.0, lim_max.pagamento / 100.0);
    printf("Limite pix: %.2lf de R$ %.2lf\n", lim_uti.pix / 100.0, lim_max.pix / 100.0);
    printf("Limite saque: %.2lf de R$ %.2lf\n", lim_uti.saque / 100.0, lim_max.saque / 100.0);
    printf("Limite transferência: %.2lf de R$ %.2lf\n", lim_uti.transferencia / 100.0, lim_max.transferencia / 100.0);

    exit(EXIT_SUCCESS);

}
