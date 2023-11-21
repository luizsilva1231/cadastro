#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_USUARIOS 1000
#define MAX_COMPRIMENTO 100

struct Usuario {
    int id;
    char nome[MAX_COMPRIMENTO];
    char email[MAX_COMPRIMENTO];
    char sexo[MAX_COMPRIMENTO];
    char endereco[MAX_COMPRIMENTO];
    double altura;
    int vacina;
};

struct Usuario usuarios[MAX_USUARIOS];
int totalUsuarios = 0;

void criarUsuario() {
    if (totalUsuarios >= MAX_USUARIOS) {
        printf("Limite máximo de usuários atingido.\n");
        return;
    }

    struct Usuario novoUsuario;
    novoUsuario.id = rand() % 1000 + 1; // Gerando um ID aleatório
    printf("ID do novo usuário: %d\n", novoUsuario.id);

    printf("Digite o nome completo: ");
    getchar();
    fgets(novoUsuario.nome, sizeof(novoUsuario.nome), stdin);
    novoUsuario.nome[strcspn(novoUsuario.nome, "\n")] = '\0'; // Removendo a quebra de linha do fgets

    printf("Digite o email: ");
    scanf("%s", novoUsuario.email);

    printf("Digite o sexo (Feminino, Masculino ou Indiferente): ");
    scanf("%s", novoUsuario.sexo);

    printf("Digite o endereço: ");
    getchar();
    fgets(novoUsuario.endereco, sizeof(novoUsuario.endereco), stdin);
    novoUsuario.endereco[strcspn(novoUsuario.endereco, "\n")] = '\0'; // Removendo a quebra de linha do fgets

    printf("Digite a altura (entre 1 e 2 metros): ");
    scanf("%lf", &novoUsuario.altura);

    printf("A pessoa já tomou vacina? (1 para sim, 0 para não): ");
    scanf("%d", &novoUsuario.vacina);

    usuarios[totalUsuarios++] = novoUsuario;
}

void editarUsuario() {
    int id;
    printf("Digite o ID do usuário a ser editado: ");
    scanf("%d", &id);

    for (int i = 0; i < totalUsuarios; ++i) {
        if (usuarios[i].id == id) {
            printf("Digite o novo nome completo: ");
            getchar();
            fgets(usuarios[i].nome, sizeof(usuarios[i].nome), stdin);
            usuarios[i].nome[strcspn(usuarios[i].nome, "\n")] = '\0';

            printf("Digite o novo email: ");
            scanf("%s", usuarios[i].email);

            printf("Digite o novo sexo (Feminino, Masculino ou Indiferente): ");
            scanf("%s", usuarios[i].sexo);

            printf("Digite o novo endereço: ");
            getchar();
            fgets(usuarios[i].endereco, sizeof(usuarios[i].endereco), stdin);
            usuarios[i].endereco[strcspn(usuarios[i].endereco, "\n")] = '\0';

            printf("Digite a nova altura (entre 1 e 2 metros): ");
            scanf("%lf", &usuarios[i].altura);

            printf("A pessoa já tomou vacina? (1 para sim, 0 para não): ");
            scanf("%d", &usuarios[i].vacina);

            printf("Usuário editado com sucesso.\n");
            return;
        }
    }

    printf("ID de usuário não encontrado.\n");
}

void excluirUsuario() {
    int id;
    printf("Digite o ID do usuário a ser excluído: ");
    scanf("%d", &id);

    for (int i = 0; i < totalUsuarios; ++i) {
        if (usuarios[i].id == id) {
            for (int j = i; j < totalUsuarios - 1; ++j) {
                usuarios[j] = usuarios[j + 1];
            }
            totalUsuarios--;
            printf("Usuário removido com sucesso.\n");
            return;
        }
    }

    printf("ID de usuário não encontrado.\n");
}

void buscarPorEmail() {
    char email[MAX_LENGTH];
    printf("Digite o email do usuário a ser buscado: ");
    scanf("%s", email);

    for (int i = 0; i < totalUsuarios; ++i) {
        if (strcmp(usuarios[i].email, email) == 0) {
            printf("Usuário encontrado:\n");
            printf("ID: %d\n", usuarios[i].id);
            printf("Nome: %s\n", usuarios[i].nome);
            printf("Email: %s\n", usuarios[i].email);
            printf("Sexo: %s\n", usuarios[i].sexo);
            printf("Endereço: %s\n", usuarios[i].endereco);
            printf("Altura: %.2lf\n", usuarios[i].altura);
            printf("Vacina: %d\n", usuarios[i].vacina);
            return;
        }
    }

    printf("Usuário não encontrado.\n");
}

void imprimirTodosUsuarios() {
    printf("Lista de Usuários:\n");
    for (int i = 0; i < totalUsuarios; ++i) {
        printf("ID: %d\n", usuarios[i].id);
        printf("Nome: %s\n", usuarios[i].nome);
        printf("Email: %s\n", usuarios[i].email);
        printf("Sexo: %s\n", usuarios[i].sexo);
        printf("Endereço: %s\n", usuarios[i].endereco);
        printf("Altura: %.2lf\n", usuarios[i].altura);
        printf("Vacina: %d\n\n", usuarios[i].vacina);
    }
}

int main() {
    srand(time(NULL));
    char opcao;

    do {
        printf("\n===== Menu =====\n");
        printf("1. Incluir usuário\n");
        printf("2. Editar usuário\n");
        printf("3. Excluir usuário\n");
        printf("4. Buscar usuário pelo email\n");
        printf("5. Imprimir todos os usuários\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf(" %c", &opcao);

        switch (opcao) {
            case '1':
                criarUsuario();
                break;
            case '2':
                editarUsuario();
                break;
            case '3':
                excluirUsuario();
                break;
            case '4':
                buscarPorEmail();
                break;
            case '5':
                imprimirTodosUsuarios();
                break;
            case '6':
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != '6');

    return 0;
}