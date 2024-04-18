from collections import deque

def count_rotatable_gears(adj_matrix, start_gear):
    N = len(adj_matrix)
    directions = [-1] * N
    directions[start_gear] = 0
    queue = deque([start_gear])
    replaced = False

    while queue and not replaced:
        current_gear = queue.popleft()
        incident_gears = []

        for j in range(current_gear + 1, N):
            if adj_matrix[current_gear][j]:
                incident_gears.append(j)

        for gear in incident_gears:
            if directions[gear] == -1:
                directions[gear] = 1 - directions[current_gear]
                queue.append(gear)
            elif directions[gear] == directions[current_gear]:
                replaced = True
                break

    if replaced:
        return 0  # Система шестерёнок не будет вращаться
    else:
        count = directions.count(1)
        return count  # Количество вращающихся шестерёнок

# Пример использования
adjacency_matrix = [
    [0, 1, 0, 1, 1],
    [0, 0, 1, 1, 0],
    [0, 0, 0, 0, 1],
    [0, 0, 0, 0, 1],
    [0, 0, 0, 0, 0]
]
start_gear = 0

result = count_rotatable_gears(adjacency_matrix, start_gear)
print(f"Количество вращающихся шестерёнок: {result}")