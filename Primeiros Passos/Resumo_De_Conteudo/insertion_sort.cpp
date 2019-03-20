#include <iostream> 
using namespace std;

int main(){
    int vec[5] = {6, 5, 12, 1, 7};
    int temp = 0;
    for(int i = 1; i < 5; i++) //FIXME não ta funcionando, tenta refazer
    {
        temp = vec[i];
        for(int j = i-1; j >= 0; j--)
        {
            if(vec[j]>temp){
                vec[j+1] = vec[j];
            }else{
                break;
            }
            vec[j+1] = temp;
        }
        
    }

    for(int i = 0; i < 5; i++)
    {
        cout << vec[i] << " ";
    }
    
    
    return 0;
}