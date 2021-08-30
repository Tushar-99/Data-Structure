#include<bits/stdc++.h>

using namespace std;

class Graph
{
public:
    unordered_map<int , list<pair<int , int>>> a_l;

    int **a_m;

    int *e_l;

    int non;

    int *visited;

    Graph(int non)
    {
        this->non = non;
        a_m = new int*[non + 1]; // here we make integer pointer type array 
        //*a_m = new int[non + 1];

        for(int i = 0 ; i <= non ; i++)
            a_m[i] = new int[non + 1];
        
        for(int i = 1 ; i <= non ; i++)
            for(int j = 1 ; j <= non ; j++)
                a_m[i][j] = 0;
    
        visited = new int[non + 1];

        for(int h = 1 ; h <= non ; h++)
            visited[h] = 0;
    }

    Graph(int v , int e)
    {
        // here edges are 8 and graph is undirected so 2 * 8
        e_l = new int[v + (2 * e) + 2] {0 , 7 , 10 , 12 , 16 , 19 , 21 , 2 , 3 , 4 , 1 , 3 , 1 , 2 , 4 , 5 , 1 , 3 , 5 , 3 , 4};
        visited = new int[v + 1];
        for(int h = 1 ; h <= non ; h++)
            visited[h] = 0;
            
        for(int i = 0 ; i <= 20 ; i++)
            cout << e_l[i] << " ";

        non = v;
    }

    void addEdge(int , int , int);
    
    void display_AM();

    void BFS_AM(int);

    void DFS_AM(int);

    void addEdge_AL(int , int , int);
    
    void display_AL();

    void BFS_AL(int , int);
    
    void DFS_AL(int);

    void addEdge_EL(int , int , int);
    
    void display_EL();

    void BFS_EL(int);
    
    void DFS_EL(int);

    bool cycle_Det_Un(int);
};

void Graph::addEdge(int from , int to , int ele)
{
    a_m[from][to] = ele;
}

void Graph::display_AM()
{
    for(int i = 1 ; i <= non ; i++)
    {
        for(int j = 1 ; j <= non ; j++)
        {
            cout << a_m[i][j] << " ";
        }
        cout << endl;
    }
}

void Graph::BFS_AM(int i)
{
    queue<int> q;
    int u;
    cout << i << " ";
    visited[i] = 1;
    q.push(i);
    
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(int v = 1 ; v <= non ; v++)
        {
            if(a_m[u][v] == 1 && visited[v] == 0)
            {
                cout << v << " ";
                visited[v] = 1;
                q.push(v);
            }
        }
    }
}

void Graph::DFS_AM(int i)
{
    if(visited[i] == 0)
    {
        cout << i << " ";
        visited[i] = 1;
        for(int j = 1 ; j <= non ; j++)
        {
            if(a_m[i][j] == 1 && visited[j] == 0)
                DFS_AM(j);
        }
    }    
}

void Graph::addEdge_AL(int from , int to ,int ele)
{
    a_l[from].push_back(make_pair(to , ele));
}

void Graph::display_AL()
{
    for(auto i : a_l)
    {   
        cout << i.first << "->" <<" ";
        for(auto j : i.second)
        {
            cout << "(" << j.first << " , " << j.second << ")" << endl;
        }
        cout << endl;
    }
}

void Graph::BFS_AL(int i , int dest)
{
    int u;
    int *dist = new int[non + 1]{0};
    int *par = new int[non + 1];
    for(int t = 0 ; t <= non ; t++)
        par[t] = -1;

    queue<int> q;
    auto f = a_l.find(i);

    if(f != a_l.end())
    {
        cout << i << " ";
        visited[i] = 1;
        q.push(i);
    }

    while(!q.empty())
    {
        u = q.front();
        q.pop();
        
        for(auto k : a_l[u])
        {
            if(visited[k.first] == 0)
            {
                visited[k.first] = 1;
                cout << k.first << " ";
                q.push(k.first);
                dist[k.first] = dist[u] + 1;
                par[k.first] = u;
            }
        }
    }

    cout << endl;
    for(int l = 1 ; l <= non ; l++)
        cout << l << " node having dist " << dist[l] << endl;

    cout << endl;
    cout << "Shortest Path is " << dist[dest] << endl;
    int temp = dest;
    while(temp != -1)
    {
        cout << temp << "<--";
        temp = par[temp];
    }
}

void Graph::DFS_AL(int i)
{
    auto p = a_l.find(i);
    cout << i << " ";
            visited[i] = 1;
            for(auto k : a_l[i])
                if(visited[k.first] == 0)
                    DFS_AL(k.first);
}

// void Graph::addEdge_EL(int val)
// {
//     for(int i = 1 ; i < 21 ; i++)
//         e_l[i] = val;
// }

void Graph::BFS_EL(int i)
{
    int u;
    queue<int> q;
    q.push(i);
    visited[i] = 1;
    cout << i << " ";
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(int k = e_l[u] ; k < e_l[u + 1] ; k++)
        {
            if(visited[e_l[k]] == 0)
            {
                cout << e_l[k] << " ";
                visited[e_l[k]] = 1;
                q.push(e_l[k]);
            }
        }
    }
}

void Graph::DFS_EL(int i)
{
    if(visited[i] == 0)
    {
       cout << i << " ";
       visited[i] = 1;
       for(int k = e_l[i] ; k < e_l[i + 1] ; k++)
           if(visited[e_l[k]] == 0)
               DFS_EL(e_l[k]);
    }
}

bool Graph::cycle_Det_Un(int )
{
    bool *vis = new bool[non + 1];
    int i = 0;
    for(int i = 0 ; i <= non ; i++)
        vis[i] = false;
     
}

int main()
{
    Graph *g = new Graph(7);
    //g->create_AM(8);
    // g->addEdge(1 , 2 , 1);
    // g->addEdge(2 , 1 , 1);
    // g->addEdge(1 , 4 , 1);
    // g->addEdge(4 , 1 , 1);
    // g->addEdge(2 , 3 , 1);
    // g->addEdge(3 , 2 , 1);
    // g->addEdge(3 , 4 , 1);
    // g->addEdge(4 , 3 , 1);
    // g->addEdge(4 , 5 , 1);
    // g->addEdge(5 , 4 , 1);
    // g->addEdge(3 , 5 , 1);
    // g->addEdge(5 , 3 , 1);
    // g->addEdge(5 , 6 , 1);
    // g->addEdge(6 , 5 , 1);
    // g->addEdge(5 , 7 , 1);
    // g->addEdge(7 , 5 , 1);
    //g->display_AM();

    // g->BFS_AM(1);
    //g->DFS_AM(1);

    //g->create_AL();
    g->addEdge_AL(1 , 2 , 1);
    g->addEdge_AL(2 , 1 , 1);
    g->addEdge_AL(1 , 4 , 1);
    g->addEdge_AL(4 , 1 , 1);
    g->addEdge_AL(2 , 3 , 1);
    g->addEdge_AL(3 , 2 , 1);
    g->addEdge_AL(3 , 4 , 1);
    g->addEdge_AL(4 , 3 , 1);
    g->addEdge_AL(4 , 5 , 1);
    g->addEdge_AL(5 , 4 , 1);
    g->addEdge_AL(3 , 5 , 1);
    g->addEdge_AL(5 , 3 , 1);
    g->addEdge_AL(5 , 6 , 1);
    g->addEdge_AL(6 , 5 , 1);
    g->addEdge_AL(5 , 7 , 1);
    g->addEdge_AL(7 , 5 , 1);

    //g->display_AL();
    cout << "\n";
    //g->BFS_AL(1 , 7);
    cout << "\n";
    g->DFS_AL(1);

    // Graph *g = new Graph(7 , 16);
    // cout << endl;
    // g->BFS_EL(5);
    // g->DFS_EL(5);

    // list<int> *arrList = new list<int>[5];

    // arrList[0].emplace_back(5);

    // Graph *g = new Graph(50);
    
    // int borad[50] = {0};
    // borad[2] = 13;
    // borad[5] = 2;
    // borad[9] = 18;
    // borad[18] = 11;
    // borad[17] = -13;
    // borad[20] = -14;
    // borad[24] = -8;
    // borad[25] = -10;
    // borad[32] = -2;
    // borad[34] = -22;

    // for(int u = 0 ; u < 36 ; u++)
    // {
    //     for(int dice = 1 ; dice <= 6 ; dice++)
    //     {
    //         int v = u + dice + borad[u + dice];
    //         g->addEdge_AL(u , v , 1);
    //     }
    // }

    // g->BFS_AL(0 , 36);
}

// Output :-

// 7-> (5 , 1)

// 6-> (5 , 1)

// 2-> (1 , 1) (3 , 1)

// 1-> (2 , 1) (4 , 1)

// 4-> (1 , 1)(3 , 1)(5 , 1)

// 3-> (2 , 1)(4 , 1)(5 , 1)

// 5-> (4 , 1)(3 , 1)(6 , 1)(7 , 1)


// 1 2 4 3 5 6 7