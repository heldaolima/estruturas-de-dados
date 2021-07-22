#include <stdio.h>

//Hélder Silva Ferreira Lima

int main()
{
    int n; //O(1)
    printf("Insira n: "); //O(1)
    scanf("%d", &n); //O(1)

    if (n < 0) printf("Número inválido!\n");

    else 
    {
        int f1 = 0, f2 = 1, r; //O(1)
        printf("0 1 ");
        for (int i = 1; i < n; i++) //O(n)
        {
            r = f2 + f1; //O(1)
            f1 = f2; //O(1)
            f2 = r; //O(1)
            printf("%d ", r);
        }
        printf("\n");

        printf("%d\n", r); //O(1)
        
    }
    
    //A complexidade é O(n)
    
    return 0;
}