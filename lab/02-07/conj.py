def unir():


def escrever_conjunto(a=[]):
    for i in a:
        print(f"{i} ", end='')
    print()


def pertence(a, ins):
    for x in a:
        if (x == a): 
            return True
    return False


def ler_conjunto (conjunto):
    tam = int(input("Insira o tamanho do conjunto: "))
    print("Insira os elementos do conjunto:")
    for i in range(0, tam):
        conjunto.append(int(input("Elemento: ")))
    

def remove():
    
    a = []
    ler_conjunto(a)
    print(a)

    escrever_conjunto(a)

    rem = int(input("Insira o elemento a ser removido: "))

    if (pertence(a, rem)):
        for i, j in enumerate(a):
            if (i == rem):
                pass
    else:
        print("O elemento fornecido não pertence ao conjunto")
        return False

def interseccao():
    print("Insira o primeiro conjunto: ")
    a = []
    ler_conjunto(a)
    
    print("Insira o segundo conjunto: ")
    b = []
    ler_conjunto(b)