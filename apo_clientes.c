#include <stdio.h>
#include <string.h>  // Para strcpy, se necessário

// Struct global "dados"gcc apo_clientes.c -o apo
struct dados {
    int codigo;
    char nome[50];
    int idade;
    char sexo;
    float salario;
};

// Variável global "cliente" do tipo struct dados (array para 5 clientes)
struct dados cliente[5];

// Função 1: Imprime todos os dados dos clientes
void imprimir(struct dados c[]) {
    int i;
    printf("\n=== DADOS DOS CLIENTES ===\n");
    for (i = 0; i < 5; i++) {
        printf("Cliente %d:\n", i+1);
        printf("Codigo: %d\n", c[i].codigo);
        printf("Nome: %s\n", c[i].nome);
        printf("Idade: %d\n", c[i].idade);
        printf("Sexo: %c\n", c[i].sexo);
        printf("Salário: R$ %.2f\n", c[i].salario);
        printf("------------------------\n");
    }
}

// Função 2: Calcula e retorna a somatória das idades
int soma_idades(struct dados c[]) {
    int i, soma = 0;
    for (i = 0; i < 5; i++) {
        soma += c[i].idade;
    }
    return soma;
}

int main() {
    int i;
    float media;

    // Entrada de dados para os 5 clientes (usando estrutura de repetição FOR)
    printf("=== CADASTRO DE 5 CLIENTES ===\n");
    for (i = 0; i < 5; i++) {
        printf("\nCliente %d:\n", i+1);
        printf("Codigo: ");
        scanf("%d", &cliente[i].codigo);
        printf("Nome: ");
        scanf(" %[^\n]", cliente[i].nome);  // Lê string com espaços
        printf("Idade: ");
        scanf("%d", &cliente[i].idade);
        printf("Sexo (M/F): ");
        scanf(" %c", &cliente[i].sexo);
        printf("Salario: ");
        scanf("%f", &cliente[i].salario);
    }

    // Chama a primeira função para imprimir
    imprimir(cliente);

    // Chama a segunda função, calcula média e imprime
    int total_idades = soma_idades(cliente);
    media = (float)total_idades / 5;
    printf("\nMedia de idade dos clientes: %.2f anos\n", media);

    return 0;
}