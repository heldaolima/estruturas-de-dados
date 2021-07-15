#include <iostream>
using std::cin;
using std::cout;

int sum_2d(int tam, int m[][tam])
{
    int total = 0;
    for (int i = 0; i < tam; i++){ )
        for (int j = 0; j < tam; j++) total += m[i][j];
    }
    return total;
}

int stupid_function(int a[])
{
    int total = 0; //O(1)
    return total; //O(1)
    /*
    T= O(1) + O(1)
    T = c1 + c2 = c3 (outra constante)
    Ergo: T = O(1)
    */
}

int soma_array(int a[])
{
    int total = 0; //O(1)
    for (int i = 0; i < 10; i++) // O(1) [whatever]
    {
        total += a[i]; //O(1) * n
    } 
    return total; //O(1)

    /*
        T = O(1) + n*O(1) + O(1)
        T = c + n*c = O(n)
            n*c é o que mais cresce
            tirando a constante, temos n
    */

}

int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int r1, r2;
    
    r1 = stupid_function(a); //O(1) 
    r2 = soma_array(a); //O(n) __usa mais tempo do que r1

    //o tamanho de uma matriz quadrada é n^2;

    int matriz1[3][3] = {{1, 4, 3},
                        {3, 1, 9},
                        {0, 5, 2}};

    int matriz2[4][4] = {
        {1, 3, 4, 1},
        {3, 1, 9, 4},
        {0, 5, 2, 6},
        {4, 5, 7, 8}
    };
    int respota = sum_2d(3, matriz1); 
    return 0;
}

/*
    linear time: O(n)
    constant time: O(1)
    quadratic time O(n^2) 
    
    T = cn^2+dn+e
        The fastest growing term?
        cn^2; sem a const: O(n2)

*/
