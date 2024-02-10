import random

def generate_matrix(rows, cols):
    matrix = [[random.choice([True, False]) for _ in range(cols)] for _ in range(rows)]
    return matrix

def write_matrix_to_file(matrix, filename):
    with open(filename, 'w') as f:
        for row in matrix:
            f.write(' '.join(str(int(cell)) for cell in row) + '\n')

rows = 100
cols = 100

matrix = generate_matrix(rows, cols)
write_matrix_to_file(matrix, 'input.txt')
