// Faças as funcionalidades abaixo.
// Inclua as funcionalidades:
// 1 - Add aluno
// 2 - Listar alunos
// 3 - Atualizar Aluno
// 4 - Remover Aluno
// 5 - Buscar aluno por matricula
// 6 - Buscar aluno por parte do nome

// 0 - Sair

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno {
    int matricula;
    char nome[120];
    int idade;
    float renda;
};

void menu();
void limparTela();
void pedirDados(struct aluno *novoAluno);
void listarAlunos(struct aluno *alunos, int qtd_alunos);
void atualizarAluno(struct aluno *alunos, int n_aluno);
void removerAluno(struct aluno *alunos, int *qtd_alunos, int n_aluno);
void buscarMatricula(struct aluno *alunos, int qtd_alunos, int matricula);
void buscarParteNome(struct aluno *alunos, int qtd_alunos, char parte_nome[120]);


int main(){
    struct aluno *alunos;
    alunos = (struct aluno * )malloc(10 * sizeof(struct aluno));
    int qtd_alunos = 0;

    menu();
    int opcao;
    scanf("%d", &opcao);

    while(opcao != 0){
        if(opcao == 1){//adicionar aluno
            struct aluno novoAluno;
            printf("\n");
            pedirDados(&novoAluno);
            alunos[qtd_alunos] = novoAluno;
            qtd_alunos++;
        }else if(opcao ==2){//listar aluno
            limparTela();
            listarAlunos(alunos, qtd_alunos);
        }else if(opcao == 3){//atualizar aluno
            limparTela();
            listarAlunos(alunos, qtd_alunos);
            int n_aluno;
            printf("\nQual aluno deseja atualizar(número): ");
            scanf("%d", &n_aluno);
            atualizarAluno(alunos, n_aluno);
        }else if(opcao == 4){//remover aluno
            limparTela();
            listarAlunos(alunos, qtd_alunos);
            int n_aluno;
            printf("\nQual aluno deseja remover(número): ");
            scanf("%d", &n_aluno);
            removerAluno(alunos, &qtd_alunos, n_aluno);
        }else if(opcao == 5){//buscar aluno por matrícula
            limparTela();
            int matricula;
            printf("\nMatrícula do aluno: ");
            scanf("%d", &matricula);
            buscarMatricula(alunos, qtd_alunos, matricula);
        }else if(opcao == 6){//buscar aluno por nome
            limparTela();
            char parte_nome[120];
            printf("\nDigite a parte do nome do aluno que você busca: ");
            scanf("%s", parte_nome);
            buscarParteNome(alunos, qtd_alunos, parte_nome);
        }

        limparTela();
        menu();
        scanf("%d", &opcao);
    }

    free(alunos);
    return 0;
}

// funções
void limparTela(){
    printf("\n<enter> to continue...");
    getchar();
    while(getchar() != '\n');
    system("clear");
}

void menu(){
    printf("\n- - - - - - - - - - SysAlunos - - - - - - - - - -");
    printf("\n\n1-Adicionar Aluno");
    printf("\n2-Listar Alunos");
    printf("\n3-Atualizar Aluno");
    printf("\n4-Remover Aluno");
    printf("\n5-Buscar Matrícula");
    printf("\n6-Buscar Parte do Nome");
    printf("\n\n0-Sair");
    printf("\n\n>>>> ");
}

void pedirDados(struct aluno *novoAluno){
    printf("Matrícula: ");
    scanf("%d", &novoAluno->matricula);

    printf("Nome: ");
    scanf(" %120[^\n]", novoAluno->nome);

    printf("Idade: ");
    scanf("%d", &novoAluno->idade);

    printf("Renda(R$): ");
    scanf("%f", &novoAluno->renda);
}

void listarAlunos(struct aluno *alunos, int qtd_alunos){
    printf("- - - - - - - - Alunos Cadastrados - - - - - - - -\n");
    for(int i = 0; i < qtd_alunos; i++){
        printf("\n******Aluno %d******\n", i+1);
        printf("\nMatrícula: %d", alunos[i].matricula);
        printf("\nNome: %s", alunos[i].nome);
        printf("\nIdade: %d", alunos[i].idade);
        printf("\nRenda: R$%.2f", alunos[i].renda);
        printf("\n");
    }
}

void atualizarAluno(struct aluno *alunos, int n_aluno){
    printf("-------------------------------------------------\n");
    printf("\nAluno Selecionado: %d\n", n_aluno);
    printf("\nMatrícula: %d", alunos[n_aluno - 1].matricula);
    printf("\nNome: %s", alunos[n_aluno - 1].nome);
    printf("\nIdade: %d", alunos[n_aluno - 1].idade);
    printf("\nRenda: R$%.2f", alunos[n_aluno -1 ].renda);
    printf("\n");

    int opcao;
    printf("\nQual das opções abaixo deseja editar?");
    printf("\n1-Matrícula");
    printf("\n2-Nome");
    printf("\n3-Idade");
    printf("\n4-Renda");
    printf("\n\n>>>> ");
    scanf("%d", &opcao);

    if(opcao == 1){
        printf("\nNova matrícula: ");
        scanf("%d", &alunos[n_aluno - 1].matricula); 
        printf("\nMatrícula atualizada com sucesso!\n");
    }
    else if(opcao == 2){
        printf("\nNovo nome: ");
        scanf(" %120[^\n]", alunos[n_aluno - 1].nome); 
        printf("\nNome atualizado com sucesso!\n");
    }
    else if(opcao == 3){
        printf("\nNova idade: ");
        scanf("%d", &alunos[n_aluno - 1].idade); 
        printf("\nIdade atualizada com sucesso!\n");
    }
    else if(opcao == 4){
        printf("\nNova renda: ");
        scanf("%f", &alunos[n_aluno - 1].renda); 
        printf("\nRenda atualizada com sucesso!\n");
    }
}

void removerAluno(struct aluno *alunos, int *qtd_alunos, int n_aluno) {
    if (n_aluno < 1 || n_aluno > *qtd_alunos) {
        printf("\nAluno não encontrado.");
        return;
    }

    for (int i = n_aluno - 1; i < *qtd_alunos - 1; i++) {
        alunos[i] = alunos[i + 1];
    }

    (*qtd_alunos)--;

    printf("\nAluno removido com sucesso!\n");
}


void buscarMatricula(struct aluno *alunos, int qtd_alunos, int matricula){
    int alunos_encontrados = 0;
    
    printf("\n\n-------------------------------------------------\n");
    printf("\nMatrícula procurada: %d\n", matricula);
    
    for(int i = 0; i < qtd_alunos; i++){
    if (matricula == alunos[i].matricula){
        printf("\n******Aluno %d******", i+1);
        printf("\nMatrícula: %d", alunos[i].matricula);
        printf("\nNome: %s", alunos[i].nome);
        printf("\nIdade: %d", alunos[i].idade);
        printf("\nRenda: R$%.2f", alunos[i].renda); 
        printf("\n");

        alunos_encontrados++;
    }
    }

    if(alunos_encontrados == 0){
        printf("\nMatrícula '%d' não encontrada!", matricula);
    }
}

void buscarParteNome(struct aluno *alunos, int qtd_alunos, char parte_nome[120]){
    int alunos_encontrados = 0;
    
    printf("\n\n-------------------------------------------------\n");
    printf("\nParte do nome procurada: %s\n", parte_nome);
    
    for(int i = 0; i < qtd_alunos; i++){
    if (strstr(alunos[i].nome, parte_nome) != NULL){
        printf("\n******Aluno %d******", i+1);
        printf("\nMatrícula: %d", alunos[i].matricula);
        printf("\nNome: %s", alunos[i].nome);
        printf("\nIdade: %d", alunos[i].idade);
        printf("\nRenda: R$%.2f", alunos[i].renda); 
        printf("\n");

        alunos_encontrados++;
    }
    }

    if(alunos_encontrados == 0){
        printf("\nParte do nome '%s' não encontrada!", parte_nome);
    }
}