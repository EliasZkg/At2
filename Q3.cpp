#include <stdio.h>

int main() {
    // Defina o salário base
    float salarioBase = 600.00;

    // Solicite ao usuário inserir o número de peças fabricadas
    int numeroPecas;
    printf("Digite o número de peças fabricadas por mês: ");
    scanf("%d", &numeroPecas);

    // Verifique o critério e calcule o adicional de produtividade
    float adicionalProdutividade = 0.0;
    if (numeroPecas > 50) {
        if (numeroPecas <= 80) {
            // Adicional de R$ 0,50 para cada peça acima de 50 até 80
            adicionalProdutividade = (numeroPecas - 50) * 0.50;
        } else {
            // Adicional de R$ 0,50 para cada peça acima de 50 até 80
            // e R$ 0,75 por peça acima das 80
            adicionalProdutividade = (80 - 50) * 0.50 + (numeroPecas - 80) * 0.75;
        }
    }

    // Calcule o salário total
    float salarioTotal = salarioBase + adicionalProdutividade;

    // Exiba o salário total
    printf("O salário total é: R$ %.2f\n", salarioTotal);

    return 0;
}