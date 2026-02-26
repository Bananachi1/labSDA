class Graph:
    def __init__(self):
        self.adj_list = {}

    # ---------- ВВОД ----------
    def input_adjacency_matrix(self):
        n = int(input("Количество вершин: "))
        matrix = []

        print("Введите матрицу смежности:")
        for _ in range(n):
            row = list(map(int, input().split()))
            matrix.append(row)

        self.adj_list = {i: [] for i in range(n)}

        for i in range(n):
            for j in range(n):
                if matrix[i][j] == 1:
                    self.adj_list[i].append(j)

    def input_incidence_matrix(self):
        m = int(input("Количество ребер: "))
        n = int(input("Количество вершин: "))

        matrix = []
        print("Введите матрицу инцидентности:")
        for _ in range(m):
            row = list(map(int, input().split()))
            matrix.append(row)

        self.adj_list = {i: [] for i in range(n)}

        for edge in matrix:
            vertices = [i for i in range(n) if edge[i] == 1]
            if len(vertices) == 2:
                u, v = vertices
                self.adj_list[u].append(v)
                self.adj_list[v].append(u)

    def input_adjacency_list(self):
        n = int(input("Количество вершин: "))
        self.adj_list = {}

        for i in range(n):
            neighbors = list(map(int, input(f"Соседи вершины {i}: ").split()))
            self.adj_list[i] = neighbors

    # ---------- ВЫВОД ----------
    def print_adjacency_list(self):
        print("\nСписок смежности:")
        for v in self.adj_list:
            print(v, "->", self.adj_list[v])

    def print_adjacency_matrix(self):
        n = len(self.adj_list)
        matrix = [[0] * n for _ in range(n)]

        for u in self.adj_list:
            for v in self.adj_list[u]:
                matrix[u][v] = 1

        print("\nМатрица смежности:")
        for row in matrix:
            print(*row)

    def print_incidence_matrix(self):
        edges = []
        seen = set()

        for u in self.adj_list:
            for v in self.adj_list[u]:
                if (v, u) not in seen:
                    edges.append((u, v))
                    seen.add((u, v))

        n = len(self.adj_list)
        m = len(edges)
        matrix = [[0] * n for _ in range(m)]

        for i, (u, v) in enumerate(edges):
            matrix[i][u] = 1
            matrix[i][v] = 1

        print("\nМатрица инцидентности:")
        for row in matrix:
            print(*row)


# ---------- МЕНЮ ----------
def main():
    g = Graph()

    while True:
        print("\n1 - Ввод (матрица смежности)")
        print("2 - Ввод (матрица инцидентности)")
        print("3 - Ввод (список смежности)")
        print("4 - Вывод списка смежности")
        print("5 - Вывод матрицы смежности")
        print("6 - Вывод матрицы инцидентности")
        print("0 - Выход")

        choice = input("Выбор: ")

        if choice == "1":
            g.input_adjacency_matrix()
        elif choice == "2":
            g.input_incidence_matrix()
        elif choice == "3":
            g.input_adjacency_list()
        elif choice == "4":
            g.print_adjacency_list()
        elif choice == "5":
            g.print_adjacency_matrix()
        elif choice == "6":
            g.print_incidence_matrix()
        elif choice == "0":
            break
        else:
            print("Неверный ввод!")


main()