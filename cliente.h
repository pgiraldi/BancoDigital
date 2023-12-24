#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <uuid/uuid.h>


#ifndef CLIENTE_H

#define CLIENTE_H


/*********************
* DEFINIÇÃO DE TIPOS *
*********************/


typedef struct
{
    int64_t pagamento;
    int64_t pix;
    int64_t saque;
    int64_t transferencia;
} limites_cliente_t;

typedef struct
{
    limites_cliente_t maximo;
    limites_cliente_t utilizado;
} limites_t;

typedef struct
{
    uuid_t id;
    int64_t saldo;
    limites_t limites;
} cliente_t;


/*************************
* PROTÓTIPOS DAS FUNÇÕES *
*************************/


void criar_cliente(cliente_t *cliente);
void alterar_saldo(int64_t quantidade, cliente_t *cliente);
void inicializar_limites(cliente_t *cliente);
void saque(u_int64_t quantidade, cliente_t *cliente);
void deposito(u_int64_t quantidade, cliente_t *cliente);

#endif
