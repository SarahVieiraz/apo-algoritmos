#include <stdio.h>
#include <string.h>
#include <windows.h> 

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

struct dados {
    int codigo;
    char nome[50];
    int idade;
    char sexo;
    float salario;
};

struct dados cliente[5];

void imprimir(struct dados c[]) {
    int i;
    printf("\n=== DADOS DOS CLIENTES ===\n");
    for (i = 0; i < 5; i++) {
        printf("Cliente %d:\n", i+1);
        printf("Código: %d\n", c[i].codigo);
        printf("Nome: %s\n", c[i].nome);
        printf("Idade: %d\n", c[i].idade);
        printf("Sexo: %c\n", c[i].sexo);
        printf("Salário: R$ %.2f\n", c[i].salario);
        printf("------------------------\n");
    }
}

int soma_idades(struct dados c[]) {
    int i, soma = 0;
    for (i = 0; i < 5; i++) {
        soma += c[i].idade;
    }
    return soma;
}

int main() {
    SetConsoleOutputCP(65001);
    int i;
    float media;
    char temp_nome[50];

    printf("=== CADASTRO DE 5 CLIENTES ===\n");
    for (i = 0; i < 5; i++) {
        printf("\nCliente %d:\n", i+1);
        
        printf("Código: ");
        if (scanf("%d", &cliente[i].codigo) != 1) {
            cliente[i].codigo = 0;
            limpar_buffer();
        } else {
            limpar_buffer();
        }
        
        printf("Nome: ");
        fgets(temp_nome, sizeof(temp_nome), stdin);
        temp_nome[strcspn(temp_nome, "\n")] = 0;
        strcpy(cliente[i].nome, temp_nome);
        
        printf("Idade: ");
        if (scanf("%d", &cliente[i].idade) != 1) {
            cliente[i].idade = 0;
            limpar_buffer();
        } else {
            limpar_buffer();
        }
        
        printf("Sexo (M/F): ");
        scanf(" %c", &cliente[i].sexo);
        limpar_buffer();
        
        printf("Salário: ");
        if (scanf("%f", &cliente[i].salario) != 1) {
            cliente[i].salario = 0.0;
            limpar_buffer();
        } else {
            limpar_buffer();
        }
    }

    imprimir(cliente);

    int total_idades = soma_idades(cliente);
    media = (float)total_idades / 5;
    printf("\nMédia de idade dos clientes: %.2f anos\n", media);

    system("pause");

    return 0;
}