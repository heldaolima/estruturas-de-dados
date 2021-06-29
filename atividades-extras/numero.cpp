#include <iostream>
#include <string>
using namespace std;

/*
    @author Hélder Lima
*/

int ans(string num)
{
    int len = num.length();
    for (int i = 0; i <= len; i++){
        if (num[i] == ',' || num[i] == '.') return 0; //numero real
    }
    // se passou do for, então é natural ou inteiro

    if (num[0] == '-' || num[0] == '+') return 1; //inteiro
    else return 2; //natural
}

bool check(string num) //checa se a entrada é válida
{
    if (!(isdigit(num[0])))
    {
        if (num[0] != '-' && num[0] != '+') return false; //aceitar o sinal negativo, para o caso de inteiros
    }

    int i = 1; // começa do 1, pois o 0 já se resolveu no bloco anterior
    int contSimbolo = 0; 
    while (num[i] != '\0')
    {
        if (!(isdigit(num[i])))
        {
            if (num[i] != ',' && num[i] != '.') return false; //os únicos aceitos são os que demarcam um número real
            else if (num[i] == ',' || num[i] == '.')
            {
                if (i == 1) return false;
                contSimbolo++;
            } 
            if (contSimbolo > 1) return false; //mais de uma vírgula/ponto na string
        }
        i++;
    }
    return true;
}

int main()
{
    bool c;
    string num;

    cout << "Insira um número: ";
    cin >> num;
    
    c = check(num);
    
    while (!(c))
    {
        cout << "Entrada inválida! Insira um número: ";
        cin >> num;
        c = check(num);
    }
    cout << "O número " + num + " é ";

    int resp = ans(num);

    if (resp == 0) cout << "Real\n";
    else if (resp == 1) cout << "Inteiro\n";
    else cout << "Natural\n";

    return 0;
}