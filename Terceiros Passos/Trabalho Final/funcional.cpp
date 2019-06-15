#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
    srand(time(NULL));
    int carta = ((rand() % 13) + 1);
    int i = 0;
    while( i < 10){
        carta = ((rand() % 13) + 1);
        printf("%d\n", carta);
        i++;
    }
}