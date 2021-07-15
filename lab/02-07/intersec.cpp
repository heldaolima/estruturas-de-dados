#include <iostream>

int conj_inter(int a[], int tam_a, int b[], int tam_b, int inter[])
{
    int tam_inter = 0;
    for (int i = 0; i < tam_a; i++)
    {
        for(int j = 0; j < tam_b; j++)
        {
            if (a[i] == b[j])
            {
                inter[tam_inter] = a[i];
                b[j] = -1;
                tam_inter++;
            }
        }
    }
    return tam_inter;
}

void mostrar_conjunto(int a[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

void ler_conjunto(int a[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        std::cin >> a[i];
        while (a[i] < 0)
        {
            std::cout << "Entrada inválida!" << std::endl;
            std::cin >> a[i];
        }
    }
}

void diferenca()
{
    std::cout << "Diferença de conjuntos" << std::endl;
    int tam_a, tam_b;
    
    std::cout << "Insira o tamanho do conjunto A: ";
    std::cin >> tam_a;

    int a[tam_a];

    std::cout << "Insira o conjunto A: " << std::endl;

    ler_conjunto(a, tam_a);

    std::cout << "Conjunto A: ";
    mostrar_conjunto(a, tam_a);

    std::cout << "Insira o tamanho do conjunto B: ";
    std::cin >> tam_b;

    int b[tam_b];

    ler_conjunto(b, tam_b);

    std::cout << "Conjunto B: ";
    mostrar_conjunto(b, tam_b);
    

}

void interseccao()
{
    std::cout << "Intersecção de conjuntos" << std::endl;
    
    int tam_a, tam_b;
    
    std::cout << "Insira o tamanho do conjunto A: ";
    std::cin >> tam_a;

    int a[tam_a];

    std::cout << "Insira o conjunto A: " << std::endl;

    ler_conjunto(a, tam_a);

    std::cout << "Conjunto A: ";
    mostrar_conjunto(a, tam_a);

    std::cout << "Insira o tamanho do conjunto B: ";
    std::cin >> tam_b;

    int b[tam_b];

    ler_conjunto(b, tam_b);

    std::cout << "Conjunto B: ";
    mostrar_conjunto(b, tam_b);
    
    int inter[tam_a+tam_b], resp;

    resp = conj_inter(a, tam_a, b, tam_b, inter);

    if (resp == 0) std::cout << "Não há elementos em comum entre os conjuntos" << std::endl;
    else
    {
        std::cout << "Intersecção entre A e B: ";
        mostrar_conjunto(inter, resp);
    }
}

int main()
{
    int choice;
    std::cout << "[1] Intersecção de conjuntos" << std::endl << "[2] Diferença de conjuntos" << std::endl;

    std::cout << "Escolha: ";
    std::cin >> choice;
    
    if (choice == 1) interseccao();
    // else if (choice == 2) diferenca();
    
    return 0;
}