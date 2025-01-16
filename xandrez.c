#include <stdio.h>
#include <string.h>

#define NUM_ESTADOS 8
#define CIDADES_POR_ESTADO 4
#define MAX_CIDADES (NUM_ESTADOS * CIDADES_POR_ESTADO)

// Estrutura para armazenar os dados de uma cidade
struct Cidade {
    char estado;
    char codigo[4];       // Código único da cidade (Ex: A01)
    char nome[50];        // Nome da cidade
    int populacao;        // Número de habitantes
    float area;           // Área total em km²
    float pib;            // PIB em bilhões de reais
    int pontosTuristicos; // Quantidade de pontos turísticos
};

// Função para cadastrar uma cidade
void cadastrarCidade(struct Cidade *cidade) {
    printf("\nCadastro da cidade:\n");

    // Estado (letra de A a H)
    do {
        printf("Digite a letra do estado (A-H): ");
        scanf(" %c", &cidade->estado);
        if (cidade->estado < 'A' || cidade->estado > 'H') {
            printf("Estado inválido! Digite uma letra entre A e H.\n");
        }
    } while (cidade->estado < 'A' || cidade->estado > 'H');

    // Código da cidade (A01, B02, etc.)
    int numCidade;
    do {
        printf("Digite o número da cidade (1-4): ");
        scanf("%d", &numCidade);
        if (numCidade < 1 || numCidade > 4) {
            printf("Número inválido! Digite um número entre 1 e 4.\n");
        }
    } while (numCidade < 1 || numCidade > 4);

    snprintf(cidade->codigo, sizeof(cidade->codigo), "%c%02d", cidade->estado, numCidade);

    // Nome da cidade
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", cidade->nome);

    // População
    printf("Digite a população da cidade: ");
    scanf("%d", &cidade->populacao);

    // Área
    printf("Digite a área da cidade em km²: ");
    scanf("%f", &cidade->area);

    // PIB
    printf("Digite o PIB da cidade (em bilhões R$): ");
    scanf("%f", &cidade->pib);

    // Número de pontos turísticos
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &cidade->pontosTuristicos);

    printf("\nCidade cadastrada com sucesso!\n");
}

// Função para exibir os dados de uma cidade
void exibirCidade(struct Cidade cidade) {
    printf("\n------------------------------\n");
    printf("Código da Carta: %s\n", cidade.codigo);
    printf("Nome da Cidade: %s\n", cidade.nome);
    printf("Estado: %c\n", cidade.estado);
    printf("População: %d habitantes\n", cidade.populacao);
    printf("Área: %.2f km²\n", cidade.area);
    printf("PIB: R$ %.2f bilhões\n", cidade.pib);
    printf("Pontos Turísticos: %d\n", cidade.pontosTuristicos);
    printf("------------------------------\n");
}

// Função principal
int main() {
    struct Cidade cidades[MAX_CIDADES];
    int totalCidades = 0;
    char opcao;

    do {
        printf("\n===== Menu Super Trunfo - Cidades =====\n");
        printf("1. Cadastrar nova cidade\n");
        printf("2. Exibir todas as cidades cadastradas\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &opcao);

        if (opcao == '1') {
            if (totalCidades < MAX_CIDADES) {
                cadastrarCidade(&cidades[totalCidades]);
                totalCidades++;
            } else {
                printf("Limite máximo de cidades cadastradas atingido!\n");
            }
        } else if (opcao == '2') {
            if (totalCidades == 0) {
                printf("\nNenhuma cidade cadastrada ainda!\n");
            } else {
                printf("\n=== Cartas Cadastradas ===\n");
                for (int i = 0; i < totalCidades; i++) {
                    exibirCidade(cidades[i]);
                }
            }
        } else if (opcao == '3') {
            printf("\nSaindo do programa...\n");
        } else {
            printf("Opção inválida! Tente novamente.\n");
        }

    } while (opcao != '3');

    return 0;
}
