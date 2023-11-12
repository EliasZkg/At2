#include <stdio.h>

// Protótipos das funções
char obterSexo();
float obterSalario();
int validaSalario(float salario);
void classificaSalario(float salario, char *classificacao);
void mostraClassificacao(float salario, char sexo);

int main() {
    int totalAbaixo = 0;
    int totalAcima = 0;

    // Loop para entrada de dados de assalariados
    while (1) {
        // Solicitação de dados do assalariado
        printf("Informe o sexo (M/F) do assalariado (ou 'S' para encerrar): ");
        char sexo = obterSexo();

        // Verifica se o usuário deseja encerrar
        if (sexo == 'S') {
            break;
        }

        // Leitura do salário
        float salario = obterSalario();

        // Validação do salário
        if (validaSalario(salario)) {
            // Classificação do salário em relação ao salário mínimo
            char classificacao[20];
            classificaSalario(salario, classificacao);

            // Exibição dos resultados
            mostraClassificacao(salario, sexo);
            printf("Classificação em relação ao salário mínimo: %s\n\n", classificacao);

            // Contagem de assalariados abaixo e acima do salário mínimo
            if (salario < 1400.00) {
                totalAbaixo++;
            } else {
                totalAcima++;
            }
        } else {
            printf("Salário inválido. Tente novamente.\n\n");
        }
    }

    // Exibição do resumo final
    printf("Resumo Final:\n");
    printf("Total de assalariados abaixo do salário mínimo: %d\n", totalAbaixo);
    printf("Total de assalariados acima do salário mínimo: %d\n", totalAcima);

    return 0;
}

// Função para obter o sexo
char obterSexo() {
    char sexo;
    scanf(" %c", &sexo); // O espaço antes do %c consome a quebra de linha pendente
    return sexo;
}

// Função para obter o salário
float obterSalario() {
    float salario;
    printf("Informe o salário do assalariado: ");
    scanf("%f", &salario);
    return salario;
}

// Função para validar o salário
int validaSalario(float salario) {
    return salario > 1.00;
}

// Função para classificar o salário em relação ao salário mínimo
void classificaSalario(float salario, char *classificacao) {
    if (salario < 1400.00) {
        sprintf(classificacao, "Abaixo do salário mínimo");
    } else if (salario == 1400.00) {
        sprintf(classificacao, "Igual ao salário mínimo");
    } else {
        sprintf(classificacao, "Acima do salário mínimo");
    }
}

// Procedimento para mostrar os resultados
void mostraClassificacao(float salario, char sexo) {
    printf("\nResultados:\n");
    printf("Salário do assalariado: R$ %.2f\n", salario);
    printf("Sexo do assalariado: %s\n", (sexo == 'M' || sexo == 'm') ? "Masculino" : "Feminino");
}