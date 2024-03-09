import numpy as np
import math
from sympy.solvers import solve
from sympy import Symbol

def gaussian_column(matrix, column):
    if isinstance(matrix, list):
        matrix = np.asarray(matrix)
    if isinstance(column, list):
        column = np.asarray(column)
    insertions = 0 # Число перестановок
    A = matrix.copy() # Сохраняем переданную матрицу в локальную переменную
    b = column.copy() # Сохраняем переданный столбец в локальную переменную
    for k in range(A.shape[0]):
        leading_row = k # Столбец, в котором ведущий элемент, считаем равным номеру шага
        for i in range(k, A.shape[0]): # находим максимальный по модулю элемент в столбце
            if math.fabs(A[i][k]) > math.fabs(A[leading_row][k]):
                leading_row = i # Номер столбца с ведущим элементом принимает значение того, ...
                # ...в котором находится больший элемент, чем текущий ведущий элемент
        for j in range(k, A.shape[1]): # меняем местами строку, в которой главный элемент, со строкой равной номеру шага
            A[leading_row][j], A[k][j] =  A[k][j], A[leading_row][j]
        insertions+=1 # повышаем число перестановок
        
        # Прямой ход (полностью дублирует формулу прямого хода, указанную выше)
        q = b[k] / A[k][k]
        for j in range(A.shape[0] - 1, k - 1, -1):
            c = A[k][j] / A[k][k]
            for i in range(A.shape[0] - 1, k, -1):
                    A[i][j] = A[i][j] - A[i][k]*c
                    if j == A.shape[0] - 1:
                        b[i] = b[i] - A[i][k]*q
    
    # Обратный ход (полностью дублирует формулу обратного хода, указанную выше)
    x=np.zeros(A.shape[0]) # Создаем итоговый вектор решений, заполненный нулями
    for i in range(A.shape[0]-1, -1, -1):
        summary = 0
        for j in range(i+1, A.shape[0]):
            summary += A[i][j]*x[j]
        x[i] = (b[i] - summary) / A[i][i]
        
    #Вычисление вектора невязки
    r = np.zeros(A.shape[0]) # Создаем вектор заполненный нулями
    for i in range(A.shape[0]):
        for j in range(A.shape[0]):
            r[i] += A[i][j]*x[j]; # r += Ax
        r[i] -= b[i] # r -= b
    
    # Вычисление определителя
    determinant = (-1)**insertions # Создаем переменную, в которой содержится (-1) в степени числа перестановок
    for k in range(A.shape[0]):
        determinant *= A[k][k] # Перемножаем все диагональные элементы получившейся треугольной матрицы
    
    return x.tolist(), r.tolist(), determinant;

def gaussian_row(matrix_, inhomogeneity):
    matrix = matrix_.copy() # Копируем исходную матрицу в локальную переменную
    insertions = 0 # Число перестановок
    indexes = [i for i in range (matrix.shape[0])] # Вектор индексов
    unit_matrix = np.eye(matrix.shape[0]) # Единичная матрица
    
    # Выбор главного элемента по строке
    for k in range(matrix.shape[0]):
        leading_column = k # Столбец, в котором ведущий элемент, считаем равным номеру шага
        for i in range(k, matrix.shape[0]): # находим максимальный по модулю элемент в строке
            if math.fabs(matrix[k][i]) > math.fabs(matrix[leading_column][k]): # Если нашли в строке элемент ...
                # ...больший, чем ведущий, то..
                leading_column = i # Номер столбца с ведущим элементом принимает значение того, ...
                # ...в котором находится больший элемент, чем текущий ведущий элемент
        for j in range(k, matrix.shape[1]): # меняем местами столбец, в котором главный элемент, со столбцом равном номеру шага
            matrix[j][leading_column], matrix[j][k] =  matrix[j][k], matrix[j][leading_column]
        insertions+=1 # повышаем число перестановок
        indexes[leading_column], indexes[k] = indexes[k], indexes[leading_column]
        
        # Прямой ход (полностью дублирует формулу прямого хода, указанную выше)
        q = inhomogeneity[k] / matrix[k][k] 
        for j in range(matrix.shape[0] - 1, k - 1, -1):
            c = matrix[k][j] / matrix[k][k]
            for i in range(matrix.shape[0] - 1, k, -1):
                matrix[i][j] = matrix[i][j] - matrix[i][k]*c
                if j == matrix.shape[0] - 1:
                    inhomogeneity[i] = inhomogeneity[i] - matrix[i][k]*q
                
    
    # Обратный ход (полностью дублирует формулу обратного хода, указанную выше)
    results_with_insertions = np.zeros(matrix.shape[0]) # Нулевой вектор
    for i in range(matrix.shape[0]-1, -1, -1):
        summary = 0
        for j in range(i+1, matrix.shape[0]):
            summary += matrix[i][j]*results_with_insertions[j]
        results_with_insertions[i] = (inhomogeneity[i] - summary) / matrix[i][i]
        
    
    # Перенумерация индексов в векторе решений
    results = np.zeros(matrix.shape[0]) # Создаем итоговый вектор решений, заполненный нулями
    for i in range(matrix.shape[0]):
        results[indexes[i]] = results_with_insertions[i] # Переносим значения из получившегося столбца решений ...
        # в созданный в той последовательности, в которой элементы столбца должны расоплагаться
        
    #Вычисление вектора невязки
    discrepancy_vector = np.zeros(matrix.shape[0]) # Создаем вектор заполненный нулями
    for i in range(matrix.shape[0]):
        for j in range(matrix.shape[0]):
            discrepancy_vector[i] += matrix[i][j]*results[j]; # r += Ax
        discrepancy_vector[i] -= inhomogeneity[i] # r -= b
    
    # Вычисление определителя
    determinant = (-1)**insertions # Создаем переменную, в которой содержится (-1) в степени числа перестановок
    for k in range(matrix.shape[0]):
        determinant *= matrix[k][k] # Перемножаем все диагональные элементы получившейся треугольной матрицы
        
    return results, discrepancy_vector, determinant; # Возвращаем значения решения, невязки и определителя

def reflection_method(A, b):
    E = np.eye(A.shape[0]) # Единичная матрица
    for k in range(A.shape[0] - 1): # Цикл шагов алгоритма
        s = np.zeros(A.shape[0]) # Создаем нулевой вектор s
        for i in range(k, A.shape[0]):
            s[i] = A[i][k] # Вектор s на k-ом шаге принимает значение k-ого столбца исходной матрицы системы
        e = np.array([E[i][k] for i in range(A.shape[0])]) # Вектор e равен k-ому столбцу единичной матрицы
        alpha = np.sqrt(np.dot(s,s)) # Эта и следующие 2 строки - формула (4) справа налево 
        kappa = 1 / np.sqrt(2 * np.dot(s, s - e * alpha))
        omega = (kappa * (s - alpha * e)).reshape(A.shape[0], 1)
        V = E - 2 * np.dot(omega, omega.T) # Формула (2)
        A = np.dot(V, A) # Домножаем матрицу системы на матрицу V, чтобы занулить k-ый столбец ниже главной диагонали
        b = np.dot(V, b) # Домножаем столбец неоднородности на матрицу V
        
    # Вычисление определителя
    det = 1
    for k in range(A.shape[0]):
        det *= A[k][k] # Произведение всех диагональных элементов получившейся треуголньой матрицы
    
    if len(b.shape) == 1:    # Если мы решаем систему Ax = b
        x = np.zeros(A.shape[0]) # Заводим нулевой вектор для будущего решения системы
        # Обратный ход метода Гаусса
        for i in range(A.shape[0]-1, -1, -1):
            summary = 0
            for j in range(i+1, A.shape[0]):
                summary += A[i][j]*x[j]
            x[i] = (b[i] - summary) / A[i][i]
        
        #Вычисление вектора невязки
        r = np.zeros(A.shape[0]) # Переменная для хранения значения вектора невязки
        for i in range(A.shape[0]):
            for j in range(A.shape[0]):
                r[i] += A[i][j]*x[j]; # r+=Ax
            r[i] -= b[i] #r-=b
        
        return x, r, det # Возвращаем значения решения, вектора невязки и определителя матрицы
    
    else: # Если решаем систему AX=E
        x = np.zeros((A.shape[0], A.shape[0])) # Заводим нулевую матрицу для хранения будущей обратной матрицы
        # Обратный ход метода Гаусса
        for i in range(A.shape[0]-1, -1, -1):
            summary = 0
            for j in range(i+1, A.shape[0]):
                summary += A[i][j]*x[i][j]
            for j in range(A.shape[0]):
                x[i][j] = (b[i][j] - summary) / A[i][i]
        
        return x # Возвращаем значение обратной матрицы

def rotation_method(A, b):
    E = np.eye(A.shape[0]) # Единичная матрица
    for k in range(A.shape[0] - 1): # Цикл шагов алгоритма
        T_k = np.eye(A.shape[0]) # Инициализируем матрицу T_k, на которую мы умножаем матрицу A на k-ом шаге
        for j in range(k + 1, A.shape[0]): # Цикл для подсчета n-k матриц T_kj, из произведения которых саму матрицу T_k
            cos_phi = A[k][k] / np.sqrt(A[k][k]**2 + A[j][k]**2) # Считаем косинус по формуле (4)
            sin_phi = - A[j][k] / np.sqrt(A[k][k]**2 + A[j][k]**2) # Считаем синус по формуле (4)
            T = E.copy() # Инициализируем матрицу T_kj, в k-ой и j-ой строках которой будут стоять рассчитанные синусы и косинусы...
            # ...в соответствии с формулой (2)
            
            # Расставляем на нужные позиции синус и косинус как в формуле (2)
            T[k][k] = cos_phi
            T[k][j] = -sin_phi
            T[j][k] = sin_phi
            T[j][j] = cos_phi
            
            # Домножаем матрицу T_k на T_kj слева
            T_k = np.dot(T, T_k)
        # Домножаем матрицу A и столбец на матрицу вращений T_k (последняя формула в первом этапе)
        A = np.dot(T_k, A) # A^k = T_kA^(k-1)
        b = np.dot(T_k, b) # b^k = T_kb^(k-1)
        
    # Вычисление определителя
    det = 1
    for k in range(A.shape[0]):
        det *= A[k][k] # Произведение всех диагональных элементов получившейся треуголньой матрицы
    
    if len(b.shape) == 1:    # Если мы решаем систему Ax = b
        x = np.zeros(A.shape[0]) # Заводим нулевой вектор для будущего решения системы
        # Обратный ход метода Гаусса
        for i in range(A.shape[0]-1, -1, -1):
            summary = 0
            for j in range(i+1, A.shape[0]):
                summary += A[i][j]*x[j]
            x[i] = (b[i] - summary) / A[i][i]
        
        #Вычисление вектора невязки
        r = np.zeros(A.shape[0]) # Переменная для хранения значения вектора невязки
        for i in range(A.shape[0]):
            for j in range(A.shape[0]):
                r[i] += A[i][j]*x[j]; # r+=Ax
            r[i] -= b[i] #r-=b
        
        return x, r, det # Возвращаем значения решения, вектора невязки и определителя матрицы
    
    else: # Если решаем систему AX=E
        x = np.zeros((A.shape[0], A.shape[0])) # Заводим нулевую матрицу для хранения будущей обратной матрицы
        # Обратный ход метода Гаусса
        for i in range(A.shape[0]-1, -1, -1):
            summary = 0
            for j in range(i+1, A.shape[0]):
                summary += A[i][j]*x[i][j]
            for j in range(A.shape[0]):
                x[i][j] = (b[i][j] - summary) / A[i][i]
        
        return x # Возвращаем значение обратной матрицы
    
def seidel_method(B, g, epsilon):
    x_k = np.copy(g) # Начальное приближение x_0 = g
    H, F = np.zeros((B.shape[0], B.shape[0])), np.zeros((B.shape[0], B.shape[0])) # Матрицы H и F инициализируем нулями
    x_k1 = np.zeros(x_k.shape[0]) # Столбец, отвечающий за k+1-ый шаг
    
    # Разбиение матрицы B = H + F
    for i in range(B.shape[0]):
        for j in range(B.shape[0]):
            if j < i: # Если находимся ниже главной диагонали
                H[i, j] = B[i, j] # Заполнение матрицы H значениями
            elif j >= i: # Если находимся на главной диагонали и выше
                F[i, j] = B[i, j] # Заполнение матрицы B значениями
                
    # Метод Зейделя в матричной форме
    iterations = 0 # Переменная для хранения числа итераций
    while True: # Пускаем цикл до тех пор, пока не выполнится условие остановки цикла
        iterations += 1 # Повышаем число итераций
        x_k1 = np.dot(H, x_k1) + np.dot(F, x_k) + g # Формула (3)
        if np.linalg.norm(x_k1 - x_k) <= epsilon: # Проверка условия остановки итерационного процесса
            break # Прерываем цикл
        x_k = np.copy(x_k1) # Переносим значение из (k+1)-ой итерации в k-ую
        
    return x_k1, iterations # Возвращаем значения k+1-ого шага и числа итераций

def gradient_descent(A, b, epsilon):
    x_k = np.copy(b) # Начальное приближение x_0 = g
    r_k = np.dot(A, x_k) - b # Вектор невязки
    x_k1 = np.zeros(x_k.shape[0]) # Переменная для хранения (k+1)-ой итерации
                
    # Метод градиентного спуска
    k = 0 # Переменная для хранения числа итераций
    while True:
        k += 1 # Повышаем число итераций
        x_k1 = x_k - np.dot(r_k, r_k.T) / np.dot(np.dot(A, r_k), r_k.T) * r_k # Формула (4)
        if np.linalg.norm(x_k1 - x_k) <= epsilon: # Проверка условия остановки итерационного процесса
            break # Прерываем цикл
        x_k = np.copy(x_k1) # Переносим значение из (k+1)-ой итерации в k-ую
        r_k = np.dot(A, x_k) - b # Считаем значение невязки для k-ой итерации
    x = x_k1 # Сохраняем результат для возвращения из функции
        
    return x, k # Возвращаем значение текущего приближения и числа итераций

def relaxation_method(A, b, w, epsilon):
    n = A.shape[0] # Размерность матрицы
    x_k = np.copy(b) # Вектор начального приближения x_0 = g
    x_k1 = np.copy(b) # Вектор-переменная для хранения (k+1)-ой итерации
                
    # Метод релаксации
    k = 0 # Переменная для хранения числа итераций
    while True:
        k += 1 # Повышаем число итераций
        for i in range(n):
            first_summary = 0
            second_summary = 0
            for j in range(i):
                first_summary += A[i][j] * x_k1[j] # Подсчет первой суммы в формуе (2)
            for j in range(i + 1, n):
                first_summary += A[i][j] * x_k[j] # Подсчет второй суммы в формуе (2) 
            x_k1[i] = (1-w)*x_k[i] - w / A[i][i] * (first_summary + second_summary - b[i]) # Формула (2)
        if np.linalg.norm(x_k1 - x_k) <= epsilon: # Проверка условия остановки итерационного процесса
            break
        x_k = np.copy(x_k1) # Переносим значение из (k+1)-ой итерации в k-ую
    x = x_k1 # Сохраняем результат для возвращения из функции
        
    return x, k

def danilevsky_method(A):
    n = A.shape[0]
    Phi = A.copy()
    S = np.eye(n)
    
    for k in range(n, 1, -1):
        M_inverse = np.eye(n)
        M_inverse[k-2, :] = Phi[k-1, :]
        M = np.linalg.inv(M_inverse)
        Phi = np.dot(M_inverse,np.dot(Phi,M))
        S = np.dot(S,M)
        
    x = Symbol('x')
    P_n = x**n
    for i in range(n):
        P_n -= x**(n-i-1) * Phi[0, i] 
    eigenvalues = solve(P_n, x)
    
    eigenvectors = []
    for k in range(n):
        y = [0 for _ in range(n)]
        y[n-1] = 1
        for i in range(n-2, -1, -1):
            y[i] = eigenvalues[k] ** (n-i-1)
        eigenvectors.append(np.dot(S,y))
        
    return eigenvalues, eigenvectors

def krylova_method(A):
    c = []
    n = A.shape[0]
    c.append(np.zeros(n))
    c[0][0] = 1
    
    for i in range(n):
        c.append(np.dot(A, c[i]))
    
    c_n = c[n]
    C = np.array(c[:n])
    p = list(reversed(np.linalg.solve(C.T, c_n)))
    
    x = Symbol('x')
    P_n = x**n
    for i in range(n):
        P_n -= x**(n-i-1) * p[i] 
    eigenvalues = solve(P_n, x)
    
    eigenvectors = []
    for k in range(n):
        b = [1 for _ in range(n)]
        for i in range(1, n):
            b[i] = b[i-1] * eigenvalues[k] - p[i-1]
        x = np.sum([b[i] * C[n - i - 1] for i in range(n)], axis=0)
        eigenvectors.append(x)
    
    return eigenvalues, eigenvectors

def power_method(A, epsilon):
    y = np.ones(A.shape[0])
    k = 0
    eigenvalue = 0
    while True:
        k+=1
        y = np.dot(A, y) / np.linalg.norm(np.dot(A, y), ord=math.inf)
        eigenvalue_k = np.dot(y.T, np.dot(A, y)) / np.dot(y.T, y)
        if np.absolute(eigenvalue_k - eigenvalue) < epsilon:
            break
        eigenvalue = eigenvalue_k

    eigenvector = y
    return eigenvalue.item(), eigenvector, k