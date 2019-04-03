#include <iostream>

using namespace std;

int particionar(int vec[], int seed, int end){
    int pivo = vec[seed];
    int esq = seed + 1;
    int dir = end;
    int divisor = 0;
    int aux = 0;

    while(esq < dir){
        while((vec[esq]<=pivo) && (esq <=end)){esq++;}
        while((vec[dir]>pivo) && (dir >= seed)){dir++;}
        if(esq<dir){
            aux = vec[esq];
            vec[esq] = vec[dir];
            vec[dir] = aux;    
        }
    }
    divisor = dir;
    if(vec[seed]>vec[divisor]){
        aux = vec[seed];
        vec[seed] = vec[divisor];
        vec[divisor] = aux;    
    }
    return divisor;
}

void recursiva(int vec[], int seed, int end){
    if(seed < end){
        int divisor = particionar(vec, seed, end);
        recursiva(vec, seed, divisor-1);
        recursiva(vec, divisor+1, end);
    }
    
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