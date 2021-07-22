#include <stdio.h>

//Hélder Silva Ferreira Lima

int fibo(int n) // retorna o n-ésimo número da sequência
{
    if (n <= 1) return n; // O(1) = c

    else return fibo(n-1)+ fibo(n-2); //t(n) = t(n-1) + t(n-2);

    /*
    Assim, T(n) = t(n-1) + t(n-2) + c

    n -> n-1 + n-2 ------------------- C [1]
        (n-2 + n-3) + (n-3 + n-4) ---- c + c = 2c [2]
        [(n-3 + n-4) + (n-4 + n-5)] + [(n-4 + n-5) + (n-5 + n-6)] ----> 2c + 2c = 4c = 2^2C 
              [2c]         [2c]            [2c]           [2c]   -----> 8c = 2^3C 

    O lado direito vai crescendo a 2^(n-1):
    
    T(n) = C +2C + 2^2C + 2^3C + ... 2^(n-1)C
    T(n)  = C (2 + 2^2 + 2^3 + ... + 2^(n-1))
        //o parenteses é uma progressão geométrica
    T(n) = C(2^n - 1)
    
    Desconsiderando as constantes, temos O(n^2)
        
    */ 
}

int main()
{
    int n;
    printf("Insira n: ");
    scanf("%d", &n);

    if (i < 0) printf("Número inválido!\n");

    else printf("%d\n", fibo(n));
    
   /*
    Como todas aslinhas da main são constantes, exceto a chamada da função fibo, temos que a complexidade do programa é a mesma da função: O(n^2). 
   */ 

    return 0;
}