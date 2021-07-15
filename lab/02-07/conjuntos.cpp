#include <iostream>
#include <vector>
#include <iterator>

bool pertence_bool(std::vector<int> v, int elemento)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (elemento == v[i]) return true;
    }
    return false;
}

void mostrar_conjunto(std::vector<int> c)
{
    for (int i = 0; i < c.size(); i++) std::cout << c[i] << " ";
    std::cout << std::endl;
}

void ler_conjunto(std::vector<int> &conjunto)
{
    int tam;
    std::cout << "Insira o tamanho do conjunto (até 10): ";
    std::cin >> tam;

    while (tam > 10 || tam <= 0)
    {
        std::cout << "Tamanho inválido! Insira o tamanho do conjunto (até 10): ";
        std::cin >> tam;
    }

    std::cout << "Insira os elementos do conjunto: " << std::endl;

    for (int i = 0; i < tam; i++){
        int elemento;
        std::cin >> elemento;
        while (pertence_bool(conjunto, elemento))
        {
            std::cout << "Preste atenção! O conjunto não pode ter elementos repetidos!\n";
            std::cin >> elemento;
        }
        conjunto.push_back(elemento);
    }
}

void diferenca()
{
    std::cout << "Opção DIFERENÇA\n";
    std::vector<int> cA, cB;

    std::cout << "Conjunto A\n";
    ler_conjunto(cA);
    std::cout << "Conjunto A: ";
    mostrar_conjunto(cA);

    std::cout << "Conjunto B\n";
    ler_conjunto(cB);
    std::cout << "Conjunto B: ";
    mostrar_conjunto(cB);

    std::cout << "A - B: ";
    int cont1 = 0;
    for (int i = 0; i < cA.size(); i++){
        if (!pertence_bool(cB, cA[i]))
        {
            std::cout << cA[i] << " ";
            cont1++;
        } 
    }
    if (cont1 == 0) std::cout << "Vazio!";
    std::cout << std::endl;

    std::cout << "B - A: ";
    int cont2 = 0;
    for (int i = 0; i < cB.size(); i++)
    {
        if (!(pertence_bool(cA, cB[i])))
        {
            std::cout << cB[i] << " ";
            cont2++;
        } 
    }
    if (cont2 == 0) std::cout << "Vazio!";
    std::cout << std::endl;
    
}

void interseccao()
{
    std::cout << "Opção INTERSECÇÃO\n";

    std::vector<int> cA, cB;

    std::cout << "Conjunto A\n";
    ler_conjunto(cA);
    std::cout << "Conjunto A: ";
    mostrar_conjunto(cA);

    std::cout << "Conjunto B\n";
    ler_conjunto(cB);
    std::cout << "Conjunto B: ";
    mostrar_conjunto(cB);

    std::cout << "Intersecção entre A e B: ";
    int cont = 0;

    for (int i = 0; i < cA.size(); i++)
    {
        if (pertence_bool(cB, cA[i]))
        {
            cont++;
            std::cout << cA[i] << " "; 
        }
    }

    if (cont == 0) std::cout << "Vazio";
    
    std::cout << std::endl;
}

void uniao()
{
    std::cout << "Opção UNIÃO\n";
    std::vector<int> cA, cB;

    std::cout << "Conjunto A\n";
    ler_conjunto(cA);
    std::cout << "Conjunto A: ";
    mostrar_conjunto(cA);

    std::cout << "Conjunto B\n";
    ler_conjunto(cB);
    std::cout << "Conjunto B: ";
    mostrar_conjunto(cB);

    std::cout << "União entre A e B: ";

    for (int i = 0; i < cA.size(); i++) std::cout << cA[i] << " ";
    

    for (int j = 0; j < cB.size(); j++)
    {
        if (!pertence_bool(cA, cB[j])) std::cout << cB[j] << " ";
        
    }
    std::cout << std::endl;
}

void pertence()
{
    std::cout << "Opção PERTENCE\n";
    std::vector<int> conjunto;

    ler_conjunto(conjunto);
    std::cout << "Conjunto inserido: ";
    mostrar_conjunto(conjunto);

    int p;
    std::cout << "Insira o elemento: ";
    std::cin >> p;

    std::cout << "O elemento " << p;

    if (pertence_bool(conjunto, p)) std::cout << " pertence ao conjunto.\n";
    
    else std::cout << " não pertence ao conjunto.\n";
}

void remove()
{
    std::cout << "Opção REMOVE\n";
    std::vector<int> conjunto;

    ler_conjunto(conjunto);
    std::cout << "Conjunto inserido: ";
    mostrar_conjunto(conjunto);

    int rem;
    std::cout << "Informe o elemento que será removido do conjunto: ";
    std::cin >> rem;

    if (pertence_bool(conjunto, rem))
    {
        for (int i = 0; i < conjunto.size(); i++)
        {
            if (conjunto[i] == rem)
            {
                conjunto.erase(conjunto.begin()+i);
                break;
            }
        }
        std::cout << "Novo conjunto: ";
        mostrar_conjunto(conjunto);
    }
    else if (!pertence_bool(conjunto, rem))
    {
        std::cout << "O elemento " << rem << " não se encontra no conjunto!\n";
    }
    else if (conjunto.size() == 1 && conjunto[1] == rem) {
        std::cout << "Não aceitamos elementos vazios!\n";
    }
    
}

void insere()
{
    std::cout << "Opção INSERE\n";
    std::vector<int> conjunto;

    ler_conjunto(conjunto);
    std::cout << "Conjunto inserido: ";
    mostrar_conjunto(conjunto);

    int ins;
    std::cout << "Informe o elemento que será inserido no conjunto: ";
    std::cin >> ins;
    
    if (pertence_bool(conjunto, ins)) std::cout << "O elemento "<< ins << " já se encontra no conjunto!\n";
    

    else if (conjunto.size() == 10) std::cout << "Conjunto lotado!";
    
    else
    {
        conjunto.push_back(ins);
        std::cout << "Novo conjunto: ";
        mostrar_conjunto(conjunto);
    }
}

int main()
{
    int op;
    std::cout << "[1] Insere\n[2] Remove\n[3] Pertence\n[4] União\n[5] Intersecção\n[6] Diferença\nEscolha uma das opções: ";    
    std::cin >> op;

    std::cout << std::endl;
    
    if (op == 1) insere();
    else if (op == 2) remove();
    else if (op == 3) pertence();
    else if (op == 4) uniao();
    else if (op == 5) interseccao();
    else if (op == 6) diferenca();
    else std::cout << "Valor inválido! Encerrando programa!\n";

    return 0;
}
