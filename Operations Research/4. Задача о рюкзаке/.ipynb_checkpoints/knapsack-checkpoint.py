import pandas as pd
import numpy as np

def knapsack(v, weights, W):
    n = len(weights)
    f = np.zeros((n + 1, W + 1))
    p = np.zeros((n + 1, W + 1))
    for i in range(1, n + 1):
        for w in range(1, W + 1):
            if w >= weights[i - 1]:
                f[i, w] = max([f[i - 1, w], f[i, w - weights[i - 1]] + v[i - 1]])
            else:
                f[i, w] = f[i - 1, w]
            p[i, w] = int(f[i, w] != f[i - 1, w])
            
    table_list = []
    for i in range(1, n+1):
        table_list.append(pd.Series(f[i], name=f'f_{i}'))
        table_list.append(pd.Series(p[i], name=f'p_{i}'))
    table = pd.DataFrame(table_list).T
    
    taken_list = np.zeros_like(weights)
    w = W
    i = n
    while i != 0 and w != 0:
        if p[i, w] == 1:
            taken_list[i - 1] += 1
            w -= weights[i - 1]
        else:
            i -= 1
    
    return f[n, W], table, taken_list

if __name__ == "__main__":
    w = [4, 8, 15]
    v = [3, 4, 5]
    W = 10
    result, table, taken_list = knapsack(w, v, W)
    print('Оптимальное решение задачи:', result)
    print(table)
    for i in range(len(w)):
        print(f'x_{i} = {taken_list[i]}')