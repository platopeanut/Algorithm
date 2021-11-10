class Graph:
    def V(self) -> int:
        pass

    def E(self) -> int:
        pass

    def get_weight(self, v1: int, v2: int) -> int:
        pass

    def get_mark(self, v: int) -> bool:
        pass

    def set_mark(self, v: int, mark: bool):
        pass

    def reset_mark(self):
        pass

    def first(self, v: int) -> int:
        pass

    def next(self, v1: int, v2: int) -> int:
        pass

    def is_edge(self, v1: int, v2: int) -> bool:
        pass

    def set_edge(self, v1: int, v2: int, w: int):
        pass

    def del_edge(self, v1: int, v2: int):
        pass


class MatrixGraph(Graph):

    def __init__(self, size: int):
        self.vertex_num = size
        self.edge_num: int = 0
        self.matrix = [[0 for _ in range(size)] for _ in range(size)]
        self.mark_list = [False for _ in range(size)]

    def V(self):
        return self.vertex_num

    def E(self):
        return self.edge_num

    def get_weight(self, v1: int, v2: int):
        return self.matrix[v1][v2]

    def get_mark(self, v: int):
        return self.mark_list[v]

    def set_mark(self, v: int, mark: bool):
        self.mark_list[v] = mark

    def reset_mark(self):
        for i in range(self.vertex_num):
            self.mark_list[i] = False

    def first(self, v: int):
        for i in range(self.vertex_num):
            if self.matrix[v][i] != 0:
                return i
        return self.vertex_num

    def next(self, v1: int, v2: int):
        for i in range(v2 + 1, self.vertex_num):
            if self.matrix[v1][i] != 0:
                return i
        return self.vertex_num

    def is_edge(self, v1: int, v2: int):
        return self.matrix[v1][v2] != 0

    def set_edge(self, v1: int, v2: int, w: int):
        if w <= 0:
            raise Exception("weight must be positive")
        if self.matrix[v1][v2] == 0:
            self.edge_num += 1
        self.matrix[v1][v2] = w

    def del_edge(self, v1: int, v2: int):
        if self.is_edge(v1, v2):
            self.edge_num -= 1
        self.matrix[v1][v2] = 0


class Queue:
    def __init__(self):
        self.queue = []

    def __len__(self):
        return len(self.queue)

    def enqueue(self, obj):
        self.queue.append(obj)

    def dequeue(self):
        front = self.queue[0]
        self.queue = self.queue[1:]
        return front

    def front(self):
        return self.queue[0]

    def __getitem__(self, item):
        return self.queue[item]

    def __str__(self):
        return str(self.queue)

    def __repr__(self):
        return self.__str__()


def load_graph_from_matrix(matrix: list[list]):
    size = len(matrix[0])
    graph = MatrixGraph(size)
    for i in range(size):
        for j in range(size):
            if matrix[i][j] > 0:
                graph.set_edge(i, j, matrix[i][j])
    return graph


def DFS(graph: Graph, v: int):
    print(v + 1, end=' ')
    graph.set_mark(v, True)
    v_next = graph.first(v)
    while v_next < graph.V():
        if not graph.get_mark(v_next):
            DFS(graph, v_next)
        v_next = graph.next(v, v_next)


def DFS_stack(graph: Graph, v: int):
    stack = [v]
    tmp_stack = []
    while len(stack) > 0:
        curr = stack.pop()
        # important!!!
        if graph.get_mark(curr):
            continue
        # mark when stack pop
        graph.set_mark(curr, True)
        print(curr + 1, end=' ')
        curr_neighbor = graph.first(curr)
        while curr_neighbor < graph.V():
            # if not graph.get_mark(curr_neighbor): # could add or not
            # reverse the order
            tmp_stack.append(curr_neighbor)
            curr_neighbor = graph.next(curr, curr_neighbor)
        # reverse
        while len(tmp_stack) > 0:
            stack.append(tmp_stack.pop())


def BFS(graph: Graph, v: int):
    queue = Queue()
    queue.enqueue(v)
    while len(queue) > 0:
        curr = queue.dequeue()
        if graph.get_mark(curr):
            continue
        graph.set_mark(curr, True)
        print(curr + 1, end=' ')
        curr_neighbor = graph.first(curr)
        while curr_neighbor < graph.V():
            queue.enqueue(curr_neighbor)
            curr_neighbor = graph.next(curr, curr_neighbor)


if __name__ == '__main__':
    _matrix = [
        [0, 10, 0, 20, 0, 2],
        [10, 0, 3, 5, 0, 0],
        [0, 3, 0, 0, 15, 0],
        [20, 5, 0, 0, 11, 10],
        [0, 0, 15, 11, 0, 3],
        [2, 0, 0, 10, 3, 0]
    ]
    _graph = load_graph_from_matrix(_matrix)
    DFS(_graph, 0)
    print()
    _graph.reset_mark()
    DFS_stack(_graph, 0)
    print()
    _graph.reset_mark()
    BFS(_graph, 0)
