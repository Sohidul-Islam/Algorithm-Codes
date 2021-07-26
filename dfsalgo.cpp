#include<bits/stdc++.h>
#include<vector>

using namespace std;
vector<int> adj[100];
int visited[100];
int edge_id[100];
int counter = 0;

void dfs(int s,int n)
{
    for(int i = 0 ; i<n ; i++)
    {
        edge_id[i]=visited[i]=0;
    }

    stack<int>St;

    St.push(s);
    cout<<s<<" ";
    visited[s] = 1;
    counter++;
    while(!St.empty())
    {
        int u = St.top();
        //cout<<"U: "<<u<<" ";
        St.pop();

        while(edge_id[u]<adj[u].size())
        {
            int v = adj[u][edge_id[u]];
            //cout<<"V: "<<v<<" ";
            edge_id[u]++;

            if(visited[v]==0)
            {
                visited[v] = 1;
                counter++;
                cout<<v<<" ";
                St.push(u);
                St.push(v);
                break;
            }
        }
    }
}


int main()
{
//connected
//
//    adj[6].push_back(4);
//    adj[4].push_back(6);
//    adj[4].push_back(3);
//    adj[4].push_back(5);
//    adj[5].push_back(4);
//    adj[5].push_back(2);
//    adj[5].push_back(1);
//    adj[3].push_back(4);
//    adj[3].push_back(2);
//    adj[2].push_back(3);
//    adj[2].push_back(5);
//    adj[2].push_back(1);
//    adj[1].push_back(2);
//    adj[1].push_back(5);


//unconnected
    adj[6].push_back(4);
    adj[4].push_back(6);


    adj[5].push_back(2);
    adj[5].push_back(1);

    adj[3].push_back(2);
    adj[2].push_back(3);
    adj[2].push_back(5);
    adj[2].push_back(1);
    adj[1].push_back(2);
    adj[1].push_back(5);

    cin>>m>>n
    //souce

    adj[m].push_back(n);


    dfs(5,6);
    cout<<endl;
    if(counter==6)
    {
        cout<<"Connected"<<endl;
    }
    else
    {
        cout<<"Not Connected"<<endl;
    }
}
