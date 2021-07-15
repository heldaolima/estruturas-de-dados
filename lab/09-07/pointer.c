#include <stdio.h>

int main(void){
	
	int b;
	
	int *c;

	b=10;
	
	c = &b;
	
	printf("\nendereço de b %d \n",c);
	
	*c= 11;
	
	printf("\nendereço de b %d \n",c);
	printf("\nendereço de b %d \n",*c);
	
	
	printf("\n %d \n",b);

}
Pedro Henrique Mesquita Isidoro17:42
sim
Roberta Lopes17:44
#include <stdio.h>

void escreveValor(int x){
	printf("\nvalor %d \n",x);
}

void escreveEndereco(int *x){
	printf("\nendereço %d \n",x);
}

void escrevePassagemValor(int x){
	x = 5;
	printf("\nvalor alterado dentro da função escrevePassagemValor %d \n",x);
}

void escrevePassagemEndereco(int *x){
	*x = 5;
	printf("\nvalor alterado dentro da função escrevePassagemEndereço %d \n",x);
}

int main(void){
	int b;
	int *c;

	b=10;

		escreveValor(b);

//		c = &b;
//		escreveEndereco(c);
//		escreveVa
//		escreveEndereco(c);
//		escreveValor(*c);
		
//		escrevePassagemValor(b);
//		escreveValor(b);
		
		escrevePassagemEndereco(&b);
		escreveValor(b);

}