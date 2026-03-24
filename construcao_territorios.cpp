#include <stdio.h>
#include <string.h>

// 1. CRIAÇÃO DA STRUCT: Define um novo tipo de dado chamado 'Territorio'.
// Ela agrupa diferentes tipos de variáveis (char e int) que pertencem a um mesmo objeto.
struct Territorio {
    char nome[30];
    char cor[10];
    int tropas;
};

int main() {
    
    // 2. USO DA STRUCT: Criamos um "array de structs" com 5 posições.
    // Imagine como uma tabela com 5 linhas, onde cada linha tem as colunas Nome, Cor e Tropas.
    struct Territorio territorios[5];
    int i;
    
    printf("\n========================\n");
    printf("Vamos cadastrar os 5 territorios iniciais do nosso mundo.\n");
    printf("========================\n");
    
    // 3. LÓGICA DO LAÇO DE ENTRADA:
    // O 'for' percorre de 0 a 4 (5 vezes), usando o índice 'i' para acessar cada posição do array.
    for (i = 0; i < 5; i++) {
        printf("\n--- Cadastrando Territorio %d --- \n", i + 1);
        
        printf("Nome do Territorio: ");
        // Acessamos o campo da struct usando o ponto: territorios[i].nome
        fgets(territorios[i].nome, 30, stdin);
        
        printf("Cor do exercito: ");
        fgets(territorios[i].cor, 10, stdin);
        
        printf("Quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);
        
        // Limpeza de strings: Remove a quebra de linha (\n) que o fgets captura.
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0';
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0';
        
        // O getchar() limpa o "Enter" que sobra no buffer após o scanf de número,
        // evitando que o próximo fgets seja pulado.
        getchar();
    }
    
    printf("\nCadastro inicial concluido com sucesso!\n");
    printf("========================\n");
    printf(" MAPA DO MUNDO - ESTADO ATUAL\n");
    printf("========================\n");
    
    // 4. LÓGICA DO LAÇO DE SAÍDA:
    // Percorre novamente o array para ler os dados que foram salvos na memória durante o primeiro laço.
    for (i = 0; i < 5; i++) {
        printf("TERRITORIO %d:", i + 1);
        
        // Exibe os valores armazenados em cada campo da struct do índice atual [i]
        printf("\n - Nome: %s \n - Dominado por: %s \n - Tropas: %d \n\n", 
                territorios[i].nome, 
                territorios[i].cor, 
                territorios[i].tropas);
    }

    printf("\n");
    return 0;
}