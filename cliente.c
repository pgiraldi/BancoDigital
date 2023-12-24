#include "cliente.h"


/************************
* DEFINIÇÃO DAS FUNÇÕES *
************************/


void criar_cliente(cliente_t *cliente)
{
    uuid_generate(cliente->id);
    cliente->saldo = 0;
    inicializar_limites(cliente);
}

void inicializar_limites(cliente_t *cliente)
{
    cliente->limites.maximo = (limites_cliente_t) {
        .pagamento = 1000000,
        .pix = 250000,
        .saque = 50000,
        .transferencia = 500000,
    };

    cliente->limites.utilizado = (limites_cliente_t) {
        .pagamento = 0,
        .pix = 0,
        .saque = 0,
        .transferencia = 0,
    }; 
}

void saque(u_int64_t quantidade, cliente_t *cliente)
{

    int64_t novo_lim_utilizado = cliente->limites.utilizado.saque + quantidade;


    if ( novo_lim_utilizado > cliente->limites.maximo.saque ||
        cliente->saldo < (int64_t) quantidade
    )
        return;

    alterar_saldo(-quantidade, cliente);

    cliente->limites.utilizado.saque = novo_lim_utilizado;
}

void deposito(u_int64_t quantidade, cliente_t *cliente)
{
    alterar_saldo(quantidade, cliente);
}

void alterar_saldo(int64_t quantidade, cliente_t *cliente)
{
    cliente->saldo += quantidade;
}
