#include<bits/stdc++.h>
using namespace std;

class Graph {

    vector<vector<int>> graph;
    vector<vector<int>> paths;
    vector<bool> v;

public:

    void DFS(int , int , vector<int>&);

    vector<vector<int>> get_all_paths(int , int , vector<vector<int>>);

    vector<vector<int>> MoneyPath(int , int , vector<vector<int>>);
};

void Graph::DFS(int poor , int rich , vector<int>& curr_Path) {

    v[poor] = true;
    curr_Path.push_back(poor);

    if (poor == rich)
        paths.push_back(curr_Path);

    else {
        for (auto node : graph[poor])
            if (!v[node])
                DFS(node , rich , curr_Path);
    }

    curr_Path.pop_back();
    v[poor] = false;
}

vector < vector<int> Graph::get_all_paths(int poor , int rich , vector<vector<int>> A) {

    paths.clear();
    vector<int> temp;
    fill(v.begin() , v.end , false);

    for (int i = 0 ; i < M ; i++) {
        for (int j = 0 ; j < 2 ; j++) {
            if (j == 0)
                graph[i][j] = A[i][j + 1];

            else
                graph[i][j] = A[i][j - 1];
        }
    }

    DFS(poor , rich , temp);
    return paths;
}

vector < vector<int> Graph::MoneyPath(int N, int M, vector<vector<int>> A) {
    // Write your code here

    // Graph g;
    vector << vector>int> res;
    int rich , poor;
    int *r_p = new int[N + 1];

    for (int i = 1 ; i < N + 1 ; i++) {
        r_p[i] = 0;
    }

    for (int i = 0; i < M; i++) {

        r_p[A[i][1]] += A[i][2];
    }

    poor = max_element(r_p + 1 , r_p + (N + 1)) - r_p;
    rich = min_element(r_p + 1 , r_p + (N + 1)) - r_p;

    res = get_all_paths(poor , rich , A);
    return res;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t_i = 0; t_i < T; t_i++)
    {
        Graph g;
        int N;
        cin >> N;
        int M;
        cin >> M;
        vector<vector<int> > A(M, vector<int>(3));
        for (int i_A = 0; i_A < M; i_A++)
        {
            for (int j_A = 0; j_A < 3; j_A++)
            {
                cin >> A[i_A][j_A];
            }
        }

        vector<vector<int>> out_;
        out_ = g.MoneyPath(N, M, A);

        for (int i = 0; i < out_.size(); i++) {

            for (int j = 0; j < out_[i].size(); ++j) {
                cout << " " << out_[i][j];
            }
        }
        cout << "\n";
    }
}