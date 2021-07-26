#include<bits/stdc++.h>
#include<vector>

using namespace std;
vector<int> adj[100];
int visited[100];

void bfs(int s,int n)
{
    for(int i = 0 ; i<n ; i++)
    {
        visited[i]=0;
    }

    queue<int>Q;

    Q.push(s);

    visited[s] = 1;

    while(!Q.empty())
    {
        int u = Q.front();
        cout<<u<<" ";
        Q.pop();
        for(int i = 0; i<adj[u].size(); i++)
        {
            if(visited[adj[u][i]]==0)
            {
                int v = adj[u][i];
                visited[v] = 1;
                Q.push(v);
            }
        }
    }
}


int main()
{
    adj[6].push_back(4);
    adj[4].push_back(6);
    adj[4].push_back(3);
    adj[4].push_back(5);
    adj[5].push_back(2);
    adj[5].push_back(1);
    adj[3].push_back(4);
    adj[3].push_back(2);
    adj[2].push_back(3);
    adj[2].push_back(5);
    adj[2].push_back(1);
    adj[1].push_back(2);
    adj[1].push_back(5);



  for (int i = 0; i < 8; i++) {

        cout << "Elements at index "
             << i << ": ";

        // Displaying element at each column,
        // begin() is the starting iterator,
        // end() is the ending iterator
        for (auto it = adj[i].begin();
             it != adj[i].end(); it++) {

            // (*it) is used to get the
            // value at iterator is
            // pointing
            cout <<"Value: "<< *it << ' ';
        }
        cout << endl;
    }


    bfs(6,6);
}
