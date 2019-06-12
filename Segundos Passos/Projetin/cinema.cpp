#include <iostream>
using namespace std;


class Pokemon{
    string nome;
public:
    
    virtual void dizer(string diz){cout << diz << endl;}
    
    Pokemon(string nome = ""):
    nome(nome)
    {}
};

class Fogo: public Pokemon{
public:
    virtual void dizer(string diz){cout << diz << " fogo"<< endl;}
};

class Agua: public Pokemon{
public:
    void dizer(string diz){cout << diz << " agua" << endl;}
};


int main()
{
    Pokemon poke;
    poke.dizer("Pikachu");
    Fogo o;
    return 0;
}