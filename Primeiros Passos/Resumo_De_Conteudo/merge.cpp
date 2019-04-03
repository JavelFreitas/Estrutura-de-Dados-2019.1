#include <iostream> #FIXME a ordenação ta certa, mas por algum motivo os valores guardados foram alterados 
using namespace std;// É bom tentar reconstruir o código do 0 e comparar com esse
void mostrar(int *v, int tam)
{
    for (int i = 0; i < tam; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void mergeSort(int *v, int inicio, int meio, int fim)
{
    int tam1 = meio - inicio + 1;
    int tam2 = fim - meio;
    int i = 0;
    int j = 0;
    int k = 0;
    int A[tam1];
    int B[tam2];

    for (i = 0; i < tam1; i++) A[i] = v[i + inicio];
    for (j = 0; i < tam2; j++) B[j] = v[j + meio+1];
    i = j = 0;
    k = inicio;

    while(i<tam1 && j<tam2){
        if(A[i]<B[j]){
            v[k] = A[i++];
        }else{
            v[k] = B[j++];
        }
        k++;
    }

    while(i<tam1) v[k++] = A[i++];
    while(j<tam2) v[k++] = B[j++];

}

void merge(int *v, int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = (inicio + fim) / 2;
        merge(v, inicio, meio);
        merge(v, meio + 1, fim);
        mergeSort(v, inicio, meio, fim);
    }
}

int main()
{
    int tam = 8;
    int v[tam] = {4, 1, 7, 23, 73, 12, 76, 33};
    mostrar(v, tam);
    merge(v, 0, tam-1);
    mostrar(v, tam);
    return 0;
}