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
    if (numeroPecas > 50 && numeroPecas <= 80) {
        // Calcule o adicional de acordo com a quantidade de peças
        adicionalProdutividade = (numeroPecas - 50) * 0.50; // Adicional de R$ 0,50 para cada peça acima de 50
    }

    // Calcule o salário total
    float salarioTotal = salarioBase + adicionalProdutividade;

    // Exiba o salário total
    printf("O salário total é: R$ %.2f\n", salarioTotal);

    return 0;
}