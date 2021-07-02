def sum_2d(matriz):
    total = 0 #O(1)
    for i in range(0, 3): 
        for j in range(0, 3):
            total += matriz[i][j] #O(1) repetido n^2 vezes, visto ser esse o tamanho de uma matriz 2d
    return total #O(1)
'''
T = O(1) + n^2*O(1) + O(1)
T = c + n^2*c
T = n^2 = O(n^2) quadratic time complexity
-----------------------
T = O(2n^2) = O(n^2)
pois T= 2N^2*c = n^2
'''

m1 = [
    [1, 2, 4],
    [4, 2, 0],
    [9, 2, 1]
]

r = sum_2d(m1)
print(r)