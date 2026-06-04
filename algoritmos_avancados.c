
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 🌱 Estrutura da sala
typedef struct Sala {
    char nome[50];
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;


// ✅ Função para criar sala
Sala *criarSala(const char *nome) ;{
    Sala *nova = (Sala*) malloc(sizeof(Sala));
    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}

// ✅ Função para explorar a mansão
void explorarSalas(Sala *atual) {
    char opcao;

    while (atual != NULL) {
        printf("\n📍 Você está em: %s\n", atual->nome);

        // Se for folha
        if (atual->esquerda == NULL && atual->direita == NULL) {
            printf("🔚 Você chegou ao fim deste caminho!\n");
            return;
        }

        printf("Escolha:\n");
        if (atual->esquerda != NULL)
            printf(" (e) Ir para esquerda\n");
        if (atual->direita != NULL)
            printf(" (d) Ir para direita\n");

        printf(" (s) Sair\n");
        printf("Opção: ");
        scanf(" %c", &opcao);

        if (opcao == 'e' && atual->esquerda != NULL) {
            atual = atual->esquerda;
        } else if (opcao == 'd' && atual->direita != NULL) {
            atual = atual->direita;
        } else if (opcao == 's') {
            printf("🚪 Saindo da exploração...\n");
            break;
        } else {
            printf("❌ Opção inválida!\n");
        }
    }
}

// ✅ Função main (programa principal)
int main() {

    // Criando a árvore da mansão
    Sala *hall = criarSala("Hall de Entrada");

    hall->esquerda = criarSala("Sala de Estar");
    hall->direita = criarSala("Cozinha");

    hall->esquerda->esquerda = criarSala("Biblioteca");
    hall->esquerda->direita = criarSala("Sala Secreta");

    hall->direita->esquerda = criarSala("Despensa");
    hall->direita->direita = criarSala("Jardim");

    // Iniciando exploração
    explorarSalas(hall);

    return 0;
}

    // - Finalize a exploração com uma opção de saída (s).
    // - Exiba o nome da sala a cada movimento.
    // - Use recursão ou laços para caminhar pela árvore.
    // - Nenhuma inserção dinâmica é necessária neste nível.

    // 🔍 Nível Aventureiro: Armazenamento de Pistas com Árvore de Busca
    //
    // - Crie uma struct Pista com campo texto (string).
    // - Crie uma árvore binária de busca (BST) para inserir as pistas coletadas.
    // - Ao visitar salas específicas, adicione pistas automaticamente com inserirBST().
    // - Implemente uma função para exibir as pistas em ordem alfabética (emOrdem()).
    // - Utilize alocação dinâmica e comparação de strings (strcmp) para organizar.
    // - Não precisa remover ou balancear a árvore.
    // - Use funções para modularizar: inserirPista(), listarPistas().
    // - A árvore de pistas deve ser exibida quando o jogador quiser revisar evidências.

    // 🧠 Nível Mestre: Relacionamento de Pistas com Suspeitos via Hash
    //
    // - Crie uma struct Suspeito contendo nome e lista de pistas associadas.
    // - Crie uma tabela hash (ex: array de ponteiros para listas encadeadas).
    // - A chave pode ser o nome do suspeito ou derivada das pistas.
    // - Implemente uma função inserirHash(pista, suspeito) para registrar relações.
    // - Crie uma função para mostrar todos os suspeitos e suas respectivas pistas.
    // - Adicione um contador para saber qual suspeito foi mais citado.
    // - Exiba ao final o “suspeito mais provável” baseado nas pistas coletadas.
    // - Para hashing simples, pode usar soma dos valores ASCII do nome ou primeira letra.
    // - Em caso de colisão, use lista encadeada para tratar.
    // - Modularize com funções como inicializarHash(), buscarSuspeito(), listarAssociacoes().

  
