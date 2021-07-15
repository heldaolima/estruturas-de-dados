#include <iostream>
#include <vector>
using namespace std;

bool pertence(vector <int> a, int tam, int ins)
{
    for (int i = 0; i < a.size(); i++){
        if (a[i] == ins) return true;
    }
    return false;
}

void mostra_v(vector <int> a)
{
    for (int i = 0; i < a.size(); i++)
    {
        printf("%d ", a[i]);
    }
}

void ler_v(vector <int> a, int n)
{
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        a.push_back(num);
    } 
}

void inserir()
{
    cout << "Forneça os dados do conjunto a ser considerado: " << endl;
    int tam;    
    
    cout << "Tamanho do conjunto: ";
    cin >> tam;
    
    vector <int> arr;
    ler_v(arr, tam);
    cout << "Seu conjunto: ";
    mostra_v(arr);

    int ins;

    cout << "Forneça o elemento a ser inserido:";
    cin >> ins;

    if (pertence(arr, tam, ins))
    {
        cout << "O número " << ins << " já está no conjunto! Encerrando a função!";
        return;
    }

    else {
        arr.push_back(ins);
        mostra_v(arr);
    }
}

void remove()
{
    cout << "Forneça os dados do conjunto a ser considerado: " << endl;
    int tam;    
    
    cout << "Tamanho do conjunto: ";
    cin >> tam;
    
    vector <int> arr;
    ler_v(arr, tam);
    cout << "Seu conjunto: ";
    mostra_v(arr);    
}


int main()
{
    int opcao;

    cout << "Escolha uma das opções: " << endl;
    cout << "[1] Insere\n[2] Remove\n[3] Pertence\n[4] União\n[6] Diferença\n[7] Encerrar\n";

    cout << "Sua opção: ";
    cin >> opcao;
    
    if (opcao == 1)
    {
        inserir();
    }

    else if (opcao == 2)
    {
        // remove
    }

    else if (opcao == 3)
    {
        // pertence
    }

    else if (opcao == 4)
    {
        // uniao
    }

    else if (opcao == 5)
    {
        // interseccao
    }

    else if (opcao == 6)
    {
        // diferenca
    }

    else if (opcao == 7 || (opcao < 1 || opcao > 2)) cout << "Programa encerrado\n";


    return 0;
}


/*simular o comportamento de um conjunto em um vetor
    inserir um elemento no conjunto
    remover
    pertence ou nao pertence
    união
    intersecção
    diferença
    */