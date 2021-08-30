#include <iostream>
#include <vector>

class Graph
{
    std::vector<std::vector<int>> graph;
    std::vector<std::vector<int>> paths;
    std::vector<bool> visited;

    void DFS(int currentNode, int destNode, std::vector<int>& currentPath)
    {
        visited[currentNode] = true;
        currentPath.push_back(currentNode);

        if (currentNode == destNode)
            paths.push_back(currentPath);
        else
        {
            for (auto node : graph[currentNode])
                if (!visited[node])
                    DFS(node, destNode, currentPath);
        }

        currentPath.pop_back();
        visited[currentNode] = false;
    }

public:

    Graph(int size)
    {
        graph.resize(size);
        visited.resize(size);
    }

    void addEdge(int from, int to)
    {
        graph[from].push_back(to);
    }

    std::vector<std::vector<int>> GetAllPossiblePaths(int source, int dest)
    {
        paths.clear();
        std::fill(visited.begin(), visited.end(), false);

        std::vector<int> temp;

        DFS(source, dest, temp);

        return paths;
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(1, 3);

    auto result = g.GetAllPossiblePaths(2, 3);

    for (auto& path : result)
    {
        for (auto node : path)
            std::cout << node << ' ';
        std::cout << std::endl;
    }
}