#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class Queue {
public:
    int first, rear, size;
    int *arr;
    Queue(int val) {
        arr = new int[val + 1];
        size = val + 1;
        first = 0;
        rear = 0;
    }
    void push(int val) {
        if ((rear + 1) % size != first) {
            arr[rear] = val;
            rear = (rear + 1) % size;
        } else {
            cout << "Queue overflow" << endl;
        }
    }
    int front() {
        if (first != rear) {
            return arr[first];
        }
        cout << "Queue is empty" << endl;
        return -1;
    }
    bool isEmpty() {
        return first == rear;
    }
    void pop() {
        if (first != rear) {
            first = (first + 1) % size;
        }
    }
    int Size() {
        return abs(rear - first);
    }
};

// Graph class
class Graph {
    public:
    int V;
    bool** adjMatrix;
    Node** adjList;

    void DFSUtil(int v, bool visited[]) {
        visited[v] = true;
        cout << v << " ";

        Node* temp = adjList[v];

        while (temp != NULL) {
            if (!visited[temp->data]) {
                DFSUtil(temp->data, visited);
            }
            temp = temp->next;
        }
        
    }

    Graph(int V) {
        this->V = V;
        adjList = new Node*[V];
        adjMatrix = new bool*[V];
        for (int i = 0; i < V; ++i) {
            adjList[i] = NULL;
            adjMatrix[i] = new bool[V];
            for (int j = 0; j < V; ++j) {
                adjMatrix[i][j] = false;
            }
        }
    }

    ~Graph() {
        for (int i = 0; i < V; ++i) {
            delete[] adjMatrix[i];
            Node* temp = adjList[i];
            while (temp != NULL) {
                Node* prev = temp;
                temp = temp->next;
                delete prev;
            }
        }
        delete[] adjMatrix;
        delete[] adjList;
    }

    void addEdge(int src, int dest) {
        Node* newNode = new Node(dest);  // add edge to adjacency list
        newNode->next = adjList[src];
        adjList[src] = newNode;

        adjMatrix[src][dest] = true;// add edge to adjacency matrix
    }

    void BFS(int start) {
        bool* visited = new bool[V];
        for (int i = 0; i < V; i++) {
            visited[i] = false;
        }

        Queue queue(V);

        visited[start] = true;
        queue.push(start);

        while (!queue.isEmpty()) {
            int current = queue.front();
            cout << current << " ";
            queue.pop();

            Node* temp = adjList[current];
            while (temp != NULL) {
                if (!visited[temp->data]) {
                    visited[temp->data] = true;
                    queue.push(temp->data);
                }
                temp = temp->next;
            }
        }

        delete[] visited;
    }

    void DFS(int start) {
        bool* visited = new bool[V];
        for (int i = 0; i < V; i++) {
            visited[i] = false;
        }
        DFSUtil(start, visited);

        delete[] visited;
    }
};

int main() {
    int u, v, startVertex,vertices, edges;
    
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;

    Graph g(vertices);

    cout << "Enter vertex u v in " << edges << " edges (u v format):" << endl;
    for (int i = 0; i < edges; ++i) {
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << "Enter the starting sorce vertex ";
    cin >> startVertex;

    cout << "\nBFS : ";
    g.BFS(startVertex);

    cout << "\nDFS : ";
    g.DFS(startVertex);

    return 0;
}

/*

BFS & DFS with Adjacency List:
Time Complexity: O(V+E)
Space Complexity: O(V+E)
explores each vertex once and checks all its adjacent vertices 


BFS & DSF with Adjacency Matrix:
Time Complexity:O(V^2)
Space Complexity: O(V^2)
Even though an edge may not exist between every pair of vertices, the algorithm still needs to check every entry in the adjacency matrix.

space complexity of BFS & DSF : O(V)
*/