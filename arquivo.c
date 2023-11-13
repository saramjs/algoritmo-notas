#include <stdio.h>

typedef struct {
    char nome[50];
    float nota1;
    float nota2;
    float media;
} Aluno;

// aqui Calculamos a média de um aluno
float calcularMedia(Aluno *aluno) {
    return (aluno->nota1 + aluno->nota2) / 2;
}

// aqui iremos ler os dados de um aluno
void lerDadosAluno(Aluno *aluno, int indice) {
    printf("Informe o nome do aluno %d: ", indice + 1);
    scanf("%s", aluno->nome);

    printf("Informe a nota1 do aluno %d: ", indice + 1);
    scanf("%f", &aluno->nota1);

    printf("Informe a nota2 do aluno %d: ", indice + 1);
    scanf("%f", &aluno->nota2);

    // aqui calculamos a média
    aluno->media = calcularMedia(aluno);
}

// aqui é escrito os dados dos alunos no arquivo
void escreverDadosNoArquivo(Aluno alunos[], int tamanho, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    for (int i = 0; i < tamanho; i++) {
        fprintf(arquivo, "Nome: %s, Nota1: %.2f, Nota2: %.2f, Média: %.2f\n",
                alunos[i].nome, alunos[i].nota1, alunos[i].nota2, alunos[i].media);
    }

    fclose(arquivo);

    printf("Dados dos alunos foram gravados no arquivo '%s'.\n", nomeArquivo);
}

int main() {
    Aluno alunos[10];

    for (int i = 0; i < 10; i++) {
        lerDadosAluno(&alunos[i], i);
    }

    escreverDadosNoArquivo(alunos, 10, "dados_alunos_modularizado.txt");

    return 0;
}

