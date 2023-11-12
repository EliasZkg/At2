#include <stdio.h>

// Protótipo da função para validar a quantidade de peças
int validaQuantidade(int quantidade);

int main() {
    // Defina o salário base
    float salarioBase = 600.00;

    // Variáveis para armazenar a quantidade de peças e o salário total de cada funcionário
    int quantidadePecas;
    float salarioTotal;

    // Loop para solicitar informações para cada funcionário
    while (1) {
        // Solicite ao usuário inserir a quantidade de peças fabricadas
        printf("Digite a quantidade de peças fabricadas por este funcionário (ou -1 para encerrar): ");
        scanf("%d", &quantidadePecas);

        // Verifique se o usuário deseja encerrar
        if (quantidadePecas == -1) {
            printf("Encerrando o programa.\n");
            break;
        }

        // Valide a quantidade de peças
        if (validaQuantidade(quantidadePecas)) {
            // Calcule o adicional de produtividade
            float adicionalProdutividade = 0.0;
            if (quantidadePecas > 50) {
                if (quantidadePecas <= 80) {
                    adicionalProdutividade = (quantidadePecas - 50) * 0.50;
                } else {
                    adicionalProdutividade = (80 - 50) * 0.50 + (quantidadePecas - 80) * 0.75;
                }
            }

            // Calcule o salário total
            salarioTotal = salarioBase + adicionalProdutividade;

            // Exiba o salário total
            printf("O salário total é: R$ %.2f\n", salarioTotal);
        } else {
            printf("A quantidade de peças inserida é inválida. Tente novamente.\n");
        }
    }

    return 0;
}

// Implementação da função para validar a quantidade de peças
int validaQuantidade(int quantidade) {
    // Validar se a quantidade é não negativa
    return quantidade >= 0;
}