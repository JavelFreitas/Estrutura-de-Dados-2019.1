#include <iostream>

using namespace std;

int particionar(){

}

void recursiva(int vec[], int seed, int end){
    int esq = seed + 1;
    int dir = end;
    int aux = 0;

    while(esq <= dir){
        if(vec[esq] > vec[dir]){
            aux = vec[esq];
            vec[esq] = vec[dir];
            vec[dir] = aux;
        }
        esq++;
        dir--;
    }
    aux = vec[seed];
    vec[seed] = vec[dir];
    vec[dir] = aux;
}

int main(){
    int n;
    cin >> n;
    int vec[n];
    for(int i = 0; i<n; i++){
        cin >> vec[i];
    }

    recursiva(vec, 1, n-1);

    for(int i = 0; i<n; i++){
        cout << vec[i] << " ";
    }
    return 0;
}