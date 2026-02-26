def input_adjacency_matrix():
    n = int(input("Введите количество вершин: "))
    matrix = []
    print("Введите матрицу смежности построчно:")
    for i in range(n):
        row = list(map(int, input().split()))
        matrix.append(row)
    return matrix


def input_incidence_matrix():
    n = int(input("Введите количество вершин: "))
    m = int(input("Введите количество ребер: "))
    matrix = []
    print("Введите матрицу инцидентности построчно:")
    for i in range(m):
        row = list(map(int, input().split()))
        matrix.append(row)
    return matrix


def input_adjacency_list():
    n = int(input("Введите количество вершин: "))
    adj_list = {}
    print("Введите список смежности:")
    for i in range(1, n + 1):
        neighbors = list(map(int, input(f"{i}: ").split()))
        adj_list[i] = neighbors
    return adj_list

# Преобразования

def adjacency_matrix_to_list(matrix):
    adj_list = {}
    n = len(matrix)
    for i in range(n):
        adj_list[i + 1] = []
        for j in range(n):
            if matrix[i][j] == 1:
                adj_list[i + 1].append(j + 1)
    return adj_list


def list_to_adjacency_matrix(adj_list):
    n = len(adj_list)
    matrix = [[0] * n for _ in range(n)]
    for i in adj_list:
        for j in adj_list[i]:
            matrix[i - 1][j - 1] = 1
    return matrix


def incidence_matrix_to_list(matrix):
    adj_list = {}
    m = len(matrix)        # ребра
    n = len(matrix[0])     # вершины

    for i in range(1, n + 1):
        adj_list[i] = []

    for edge in matrix:
        start = None
        end = None

        for j in range(n):
            if edge[j] == -1:
                start = j + 1
            elif edge[j] == 1:
                end = j + 1
            elif edge[j] == 2:
                start = end = j + 1

        if start is not None and end is not None:
            adj_list[start].append(end)

    return adj_list


def list_to_incidence_matrix(adj_list):
    edges = []

    for u in adj_list:
        for v in adj_list[u]:
            edges.append((u, v))

    n = len(adj_list)
    m = len(edges)

    matrix = [[0] * n for _ in range(m)]

    for i, (u, v) in enumerate(edges):
        if u == v:
            matrix[i][u - 1] = 2
        else:
            matrix[i][u - 1] = -1
            matrix[i][v - 1] = 1

    return matrix

# Вывод

def print_adjacency_matrix(matrix):
    print("Матрица смежности:")
    for row in matrix:
        print(*row)


def print_incidence_matrix(matrix):
    print("Матрица инцидентности:")
    for row in matrix:
        print(*row)


def print_adjacency_list(adj_list):
    print("Список смежности:")
    for key in adj_list:
        print(f"{key}: {adj_list[key]}")

# Меню

def main():
    adj_list = None

    while True:
        print("\n1 - Ввести матрицу смежности")
        print("2 - Ввести матрицу инцидентности")
        print("3 - Ввести список смежности")
        print("4 - Вывести матрицу смежности")
        print("5 - Вывести матрицу инцидентности")
        print("6 - Вывести список смежности")
        print("0 - Выход")

        choice = input("Выберите пункт меню: ")

        if choice == "1":
            matrix = input_adjacency_matrix()
            adj_list = adjacency_matrix_to_list(matrix)

        elif choice == "2":
            matrix = input_incidence_matrix()
            adj_list = incidence_matrix_to_list(matrix)

        elif choice == "3":
            adj_list = input_adjacency_list()

        elif choice == "4":
            if adj_list:
                matrix = list_to_adjacency_matrix(adj_list)
                print_adjacency_matrix(matrix)
            else:
                print("Граф не введен!")

        elif choice == "5":
            if adj_list:
                matrix = list_to_incidence_matrix(adj_list)
                print_incidence_matrix(matrix)
            else:
                print("Граф не введен!")

        elif choice == "6":
            if adj_list:
                print_adjacency_list(adj_list)
            else:
                print("Граф не введен!")

        elif choice == "0":
            break

        else:
            print("Неверный выбор!")

if __name__ == "__main__":
    main()