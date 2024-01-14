%% 1. Дана матрица
matrix = [1 2 3; 4 5 6; 7 8 9];
matrix

% изменить 1го элемента матрицы на 100
matrix(1, 1) = 100;
matrix

% изменить 3ью строку матрицы на число 50
matrix(3, :) = 50;
matrix

% изменение 2го столбца матрицы на число 83
matrix(:, 2) = 33;
matrix


%% 2. Дана матрица
matrix = [5 5 5; 21 0 2; 21 0 2];
matrix

% удалить 1ую строку матрицы
matrix(1, :) = [];
matrix

% Удалить 2го столбца матрицы
matrix(:, 2) = [];
matrix


%% 3. Дана матрица
matrix = [1 1 1; 2 2 2; 3 3 3];
matrix

% Удалить две строки матрицы
matrix(2:3, :) = [];
matrix

% Удалить два последних элементов матрицы
matrix(:, 2:3) = [];
matrix


%% 4. Задать матрицу из единиц 5го порядка
matrix = eye(5);
matrix


%% Даны две матрицы. Перемножить их
matrix1 = [1 1 1; 2 2 2; 3 3 3];

matrix2 = [3 4; 3 5; 3 6];

result = matrix1 * matrix2;
result


%% 6. Дана матрица
matrix = [1 2 3; 0 2 0; 0 0 3];
matrix

% возвести матрицу в квадрат
matrix_s = matrix^2;
matrix_s

% транспонировать матрицу
matrix_T = matrix';
matrix_T


%% 7. Построить график функций
x = linspace(0, 2*pi, 100);
y = exp(-x) .* sin(10*x);

plot(x, y);

xlabel('x');
ylabel('y');


%% 8. Построить графики функций
x = linspace(0, 2*pi, 100);
y1 = sin(x);
y2 = cos(x);

plot(x, y1, x, y2);

xlabel('x');
ylabel('y');

grid on;


%% 9. Построить график функции в полярных координатах
x = 0:0.01:2*pi;
f = 8*sin(x);
z = cos(2*x);

polarplot(x, f);
hold on;
polarplot(x, z);
hold off;

grid on;
