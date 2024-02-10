import random


def generate_adjacency_matrix(n):
    matrix = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(i + 1, n):
            matrix[i][j] = matrix[j][i] = random.randint(0, 1)
    return matrix


def write_to_file(matrix, filename):
    with open(filename, 'w') as file:
        for row in matrix:
            file.write(' '.join(map(str, row)) + '\n')


n = 1000
adjacency_matrix = generate_adjacency_matrix(n)


write_to_file(adjacency_matrix, "input2.txt")
