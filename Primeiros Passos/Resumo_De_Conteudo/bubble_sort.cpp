#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    vector<int> ct; // Testando o vector
    int v[5] = {11, 12, 15, 11, 0};
    int temp = 0;

    for(int i = 0; i < 5; i++)
        {
            cout << v[i] << " ";
        }
        cout << endl;
    for(int i = 5-1; i >= 0; i--)
    {
        for(int j = 0; j < i; j++){
            if(v[j]<v[j+1]){
                temp = v[j+1];
                v[j+1] = v[j];
                v[j] = temp;
                for(int i = 0; i < 5; i++)
                {
                    cout << v[i] << " ";
                }
                cout << endl;
            }
        }
    }

    cout << endl << endl;
    ct.push_back(1);
    cout << ct[0];

    return 0;
}