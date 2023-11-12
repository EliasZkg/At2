#include <stdio.h>

// Protótipos das funções
int validaQuantidade(int quantidade);
float calculaSalario(int quantidade);
void mostraFinal(int totalFuncionarios, float salarioTotalGeral);

int main() {
    // Variáveis
    int quantidadePecas;
    int totalFuncionarios = 0;
    float salarioTotalGeral = 0.0;

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
            // Calcule o salário total
            float salarioTotal = calculaSalario(quantidadePecas);

            // Adicione o salário total ao total geral
            salarioTotalGeral += salarioTotal;

            // Incrementa o número total de funcionários
            totalFuncionarios++;

            // Exibe o salário total
            printf("O salário total é: R$ %.2f\n", salarioTotal);
        } else {
            printf("A quantidade de peças inserida é inválida. Tente novamente.\n");
        }
    }

    // Exibe o resultado final
    mostraFinal(totalFuncionarios, salarioTotalGeral);

    return 0;
}

// Função para validar a quantidade de peças
int validaQuantidade(int quantidade) {
    // Validar se a quantidade é não negativa
    return quantidade >= 0;
}

// Função para calcular o salário total
float calculaSalario(int quantidade) {
    float salarioBase = 600.00;
    float adicionalProdutividade = 0.0;

    if (quantidade > 50) {
        if (quantidade <= 80) {
            adicionalProdutividade = (quantidade - 50) * 0.50;
        } else {
            adicionalProdutividade = (80 - 50) * 0.50 + (quantidade - 80) * 0.75;
        }
    }

    return salarioBase + adicionalProdutividade;
}

// Procedimento para mostrar o resultado final
void mostraFinal(int totalFuncionarios, float salarioTotalGeral) {
    printf("\nResumo Final:\n");
    printf("Número total de funcionários: %d\n", totalFuncionarios);
    printf("Salário total geral: R$ %.2f\n", salarioTotalGeral);
}