#include <stdio.h>

int main() {
    float valor_original, valor_final;
    float desconto = 0.0, taxa = 0.0;
    int idade, forma_pagamento, parcelar = 0, num_parcelas = 1;

    printf("=== SISTEMA DE VENDAS E-COMMERCE ===\n");

    // Entrada de dados
    printf("Digite o valor total do pedido (R$): ");
    scanf("%f", &valor_original);

    printf("Digite a idade do cliente: ");
    scanf("%d", &idade);

    // Validações
    if (valor_original <= 0 || idade < 0) {
        printf("\nERRO: Valores inválidos.\n");
        return 0;
    }

    if (idade < 18) {
        printf("\nCOMPRA RECUSADA: Apenas maiores de 18 anos.\n");
        return 0;
    }

    valor_final = valor_original;

    // Desconto por valor da compra
    if (valor_final >= 100.0) {
        float desc = valor_final * 0.10;
        desconto += desc;
        valor_final -= desc;
    }

    // Forma de pagamento
    printf("\nFormas de Pagamento:\n");
    printf("1 - Pix\n2 - Cartao de Credito\n3 - Boleto\nEscolha: ");
    scanf("%d", &forma_pagamento);

    switch (forma_pagamento) {
        case 1: // Pix
            {
                float desc = valor_final * 0.05;
                desconto += desc;
                valor_final -= desc;
            }
            break;

        case 2: // Cartão
            printf("Deseja parcelar? (1-Sim / 0-Nao): ");
            scanf("%d", &parcelar);

            if (parcelar == 1) {
                printf("Quantidade de parcelas (Max 6): ");
                scanf("%d", &num_parcelas);

                if (num_parcelas < 1 || num_parcelas > 6) {
                    printf("Numero de parcelas invalido!\n");
                    return 0;
                }
            }
            break;

        case 3: // Boleto
            taxa = 2.50;
            valor_final += taxa;
            break;

        default:
            printf("Opcao invalida!\n");
            return 0;
    }

    // Resumo final
    printf("\n========== RESUMO DA COMPRA ==========\n");
    printf("Situacao: APROVADA\n");
    printf("Valor Original: R$ %.2f\n", valor_original);
    printf("Descontos aplicados: R$ %.2f\n", desconto);
    printf("Taxas: R$ %.2f\n", taxa);
    printf("Valor Final: R$ %.2f\n", valor_final);

    if (forma_pagamento == 2 && parcelar == 1) {
        printf("Parcelamento: %dx de R$ %.2f\n", num_parcelas, valor_final / num_parcelas);
    }

    printf("======================================\n");

    return 0;
}
