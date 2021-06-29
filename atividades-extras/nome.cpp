#include <iostream>
#include <string>
using namespace std;

/*
    @author Hélder Lima
*/


bool testes(string nome)
{
    if (isspace(nome[0]) || islower(nome[0])) return false; //primero caractere espaço ou minúscula
    
    int i = 0;
    while (nome[i] != '\0')
    {
        if (isdigit(nome[i])) return false; //números no nome
        i++;
    }

    return true;
}

int main()
{
    string nome;
    bool r;
    
    cout << "Insira o seu nome: ";
    getline(cin, nome);

    r = testes(nome);

    while (!(r))
    {
        cout << "Entrada inválida! Insira o seu nome: ";
        getline(cin, nome);
        r = testes(nome);
    }

    cout << "Olá, " + nome + "!\n";

    return 0;
}