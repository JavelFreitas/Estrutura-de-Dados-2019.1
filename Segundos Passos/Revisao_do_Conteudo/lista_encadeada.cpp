#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct No
{

    string informacao;
    No *proximo;

    void setInfo(string info)
    {
        this->informacao = info;
    }
    string getInfo()
    {
        return this->informacao;
    }
};

No *inicio()     // inicia com o 'no' sendo nulo para ter um ponto de partida, caso ele não
{                // fosse seria necessário adicionar um valor ao 'no->próximo', o que sendo
    return NULL; // primeiro é difícil (A não ser que o próximo fosse nulo).
}

No *inserir(No *l, string aux) // Ao inserir um novo 'no' na lista,
{                              //
    No *no = new No;           // é criado um novo no que é definido como um 'new No'
    no->setInfo(aux);          // seu conteúdo é preenchido pela variável auxiliar
    no->proximo = l;           // e o no após ele é o que antes era o primeiro, agora segundo no
    return no;                 // o no é retornado para ser o primeiro
}

No *remover(No *no, string aux)
{
    No *pre = NULL; // salva o no anterior
    No *prox = no;  // percorre o no

    while (prox != NULL && prox->getInfo() != aux) //enquanto não chega ao final, ou não acha o que procura
    {
        pre = prox;           // atualiza o pre para o atual prox, que futuramente vai ser o anterior
        prox = prox->proximo; //atualiza o prox para o proximo da lista e vira o anterior;
    }

    if (prox == NULL) // se chegou no final da lista e não achou,
    {
        cout << "Nao achou a string '" << aux << "' no nó" << endl;
        return no; // retorna o no, sem alteração, ou seja, continua o mesmo
    }              // se chegou na linha abaixo, o buscado foi encontrado

    if (pre == NULL) // se achou o que procurava, e o valor do pre continua nulo, significa que o buscado é o primeiro
    {
        no = prox->proximo; // então, é só cortar ele da lista, fazendo com que o atual seja o próximo
    }
    else // caso não seja o primeiro, ele está no meio da lista
    {
        pre->proximo = prox->proximo; // o anterior se liga ao no que está um nó a sua frente
    }                                 // por exemplo, querendo excluir o no 2 da lista 1, 2, 3
                                      // o próximo do 1 deve ser o 3, deixando o 2 de lado,
                                      // mas não totalmente, ja que a memória utilizada pra
                                      // guardar ele ainda está sendo usada
    free(prox);                       // Libera a memória que guardava o 'no' escolhido
    return no;                        // Retorna o no, com a lista sem o ítem escolhido
}
void help()
{
    cout << "Escolha o que quer fazer: " << endl;
    cout << "help - Comandos" << endl;
    cout << "show - Mostrar Lista" << endl;
    cout << "add _info _info ... - Adicionar No" << endl;
    cout << "rem _info _info ... - Remover No" << endl;
}

void mostrar_no(No *no) // Recebe um no
{
    short int i = 0;   // define um int para informar o numero do no e seu conteúdo
    while (no != NULL) // enquanto não for o ultimo
    {
        cout << "[" << i++ << "] " << no->getInfo() << " "; // mostra a informação e onde ela está
        no = no->proximo;                                   // e itera para mostrar a informação do próximo no
    }
    cout << "[" << i << "]"
         << " _vazio_" << endl; // mostra o ultimo no definido como 'NULL' como vazio
}

bool esta_vazio(No *no)
{
    if (no == NULL)
        return 1;
    else
        return 0;
}

struct Controller
{
    No *atual = inicio(); //NOTE tenta fazer um if pra iniciar, pergunta pro enyo como que pode ser feito caso não consiga

    void shell(string comandos)
    {
        stringstream ss(comandos);
        string op = "";
        string aux = "";
        ss >> op;

        if (op == "add")
        {
            while (ss >> aux)
            {
                atual = inserir(atual, aux); // o no inserido se torna o primeiro
            }
            mostrar_no(atual);
        }
        else if (op == "show")
        {
            mostrar_no(atual); // mostra todas as informações no 'no'
        }
        else if (op == "help")
        {
            help();
        }
        else if (op == "rem")
        {
            if(esta_vazio(atual)){
                cout << "Lista vazia" << endl;
            }
            while (ss >> aux)
            {
                atual = remover(atual, aux);
            }
            mostrar_no(atual);
        }
    }
    void exec()
    {
        string comandos;
        while (true)
        {
            getline(cin, comandos);
            if (comandos == "end")
                return;
            shell(comandos);
        }
    }
};

int main()
{
    Controller c;
    c.exec();
    return 0;
}