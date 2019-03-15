#include <stdio.h>

int main(){
    int vec[5];
    for(int i=0 ;i<5;i++){
        printf("Digite o valor de vec\n");
        scanf("%d", &vec[i]);
    }
    for(int i=0 ;i<5;i++){
        printf("%d\n", vec[i]);
    }
    return 0;
}