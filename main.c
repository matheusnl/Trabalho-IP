#include "funcoes.h" // Inicializa a biblioteca funcoes.h
#define MAX 10;

// variáveis globais
aluno *alunos;
int qtde = 0;
int capacidade = MAX;

int main() {
  alunos = malloc(capacidade * sizeof(aluno)); // aloca espaço para 10 alunos
  int op;

  printf("BEM-VINDO AO SISTEMA DE GESTÃO DE ALUNOS!\n\n");
  
  // MENU
  do {
    linha();
    printf("%*sMENU%*s\n", 18, "", 18, "");
    linha();
    printf("1 - Cadastrar novo aluno\n"
      "2 - Remover aluno cadastrado\n"
      "3 - Listar alunos cadastrados\n"
      "4 - Listar alunos aprovados\n"
      "5 - Listar alunos reprovados\n"
      "0 - Sair\n");
    linha();

    printf("Digite a opção desejada: ");
    scanf("%d", &op);
    switch (op) {
      case 1: {
        // Cadastrar novo aluno
        cadastrar_aluno(alunos, &qtde, &capacidade);
      } break;
      
      case 2: {
        // Remover aluno cadastrado
        remover_aluno(alunos, &qtde, &capacidade);
      } break;

      case 3: {
        // Listar alunos cadastrados
        alunos = listar_alunos_cadastrados(alunos, &qtde, &capacidade);
      } break;

      case 4: {
        // Listar alunos aprovados
        alunos = listar_alunos_aprovados(alunos, &qtde, &capacidade);        
      } break;

      case 5: {
        // Listar alunos reprovados
        alunos = listar_alunos_reprovados(alunos, &qtde, &capacidade);        
      } break;

      case 0: {
        printf("\nEncerrando...");
        printf("\nAgradecemos por utilizar nosso sistema! (*^_^*)\n");
        printf("\nDesenvolvido por:"
          "\n• José Matheus Nogueira Luciano"
          "\n• Ravenna Jesus dos Santos"
          "\n• David Saymmon dos Santos Felipe\n");
      } break;
      
      default: {
        printf("\nEscolha uma opção válida!\n\n");
      } break;
    }
  } while (op != 0);

  free(alunos);
  
  return 0;
}