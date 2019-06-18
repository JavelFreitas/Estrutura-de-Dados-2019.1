typedef struct no No;

typedef struct jogador Jogador;

typedef struct baralho Baralho;

// typedef struct {
//     Baralho* baralho;
//     int pontuacao;
//     int vitorias;
// } Jogador;

// typedef struct {
//     No* cartas; 
// } Baralho; 

No* criar_no(int valor);

No* inserir(No* no, int valor);

No* remover(No* no, int valor);

void zerar(No* no);

int vazio(No* no);

void imprimir_no(No* no);

No *rotacaoRR(No* no);

No *rotacaoLL(No* no);

No *rotacaoLR(No* no);

No *rotacaoRL(No* no);

int buscaMenor(No* no);

No* buscaPosicaoMenor(No *no);