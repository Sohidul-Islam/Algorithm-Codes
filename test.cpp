#include <bits/stdc++.h>
using namespace std;

class UUGraph
{
private:
    vector<vector<int>> g;
    int Vertex = 0;
    int Edge = 0;

public:
    UUGraph(int Vertex)
    {
        this->Vertex = Vertex;
        g.resize(Vertex);
    }

    int getVertex() { return Vertex; }
    int getEdge() { return Edge; }

    void addVertex(int v)
    {
        g.resize(Vertex + v);
        this->Vertex = Vertex + v;
    }

    void addEdge(int u, int v)
    {
        g[u].push_back(v);
        Edge++;
    }

    void addEdgeLoop(int totalEdge)
    {
        int u, v;
        for (int i = 0; i < totalEdge; i++)
        {
            cin >> u >> v;
            addEdge(u, v);
        }
    }

    void addEdgeList(vector<int> vec)
    {
        for (auto it = vec.begin(); it != vec.end(); it += 2)
        {
            addEdge(*it, *(it + 1));
        }
    }

    void print()
    {
        for (int v = 0; v < Vertex; v++)
        {
            cout << v << "-> ";
            for (auto x : g[v])
                cout << x << " ";
            cout << endl;
        }
        cout << endl;
    }

    void isConnected(int s = 0)
    {
        print();

        vector<bool> visited(Vertex, false);
        stack<int> st;

        st.push(s);
        printf("DFS: ");
        while (!st.empty())
        {
            s = st.top();
            st.pop();

            if (!visited[s])
            {
                cout << s << " ";
                visited[s] = true;
            }

            for (auto it : g[s])
                if (!visited[it])
                    st.push(it);
        }
        cout << endl;

        auto it = visited.begin();
        for (it; it != visited.end(); it++)
            if (*it == 0)
                break;

        if (it == visited.end())
            cout << "This is a Connected Graph\n";
        else
            cout << "This is a Disconnected Graph\n";

        cout << endl;
    }
};

int main()
{
    // Connected Graph
    printf("Graph 1\n");
    vector<int> vec{
        0, 1,
        0, 2,
        1, 3,
        2, 4,
        3, 5,
        4, 5}; //graph

    UUGraph Graph1(6);
    Graph1.addEdgeList(vec);
    Graph1.isConnected();

    // DisConnected Graph
    printf("Graph 2\n");
    vector<int> vec2{
        0, 1,
        1, 2,
        0, 2,
        3, 4,
        3, 5,
        4, 5}; //graph

    UUGraph Graph2(6);
    Graph2.addEdgeList(vec2);
    Graph2.isConnected();
}
