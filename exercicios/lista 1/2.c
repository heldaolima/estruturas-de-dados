#include <stdio.h>

//Hélder Silva Ferreira Lima

void encontra(int coord[2], int n)
{
    int cont = 0, cont_igual = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == 1) coord[0]++;
        else if (i == 2)
        {
            coord[1]++;
            cont_igual++;
        } 
        if (i > 2)
        {  
            if (cont == 0) 
            {
                coord[0] *= -2;
                coord[1] *= -1;
                cont++;
            }
            else if (cont == 1)
            {
                coord[0] = (coord[0] * -1)+1;
                cont++;
            }
            else if (cont == 2)
            {
                cont_igual++;
                coord[0] = cont_igual;
                coord[1] = cont_igual;    
                cont = 0;
            }
        }
    }
}

int main()
{
    int n;
    printf("Insira n: ");
    scanf("%d", &n);

    if (n < 0) printf("Número inválido!\n");
    
    else 
    {
        int coord[2] = {0, 0};
        encontra(coord, n);
        printf("Coordenada: (%d, %d)\n", coord[0], coord[1]);
    }
    
    return 0;
}