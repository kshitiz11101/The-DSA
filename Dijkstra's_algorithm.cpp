#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> dist(V);
        for (int i = 0; i < V; i++)
        {
            dist[i] = INT_MAX;
        }
        set<pair<int, int>> s;
        dist[S] = 0;
        s.insert(make_pair(0, S));
        while (!s.empty())
        {
            //                                       fetch top record
            auto top = *(s.begin());
            int nodeDistance = top.first;
            int topNode = top.second;
            //                                       remove top record now
            s.erase(s.begin());

            for (auto neighbour : adj[topNode])
            {
                if (nodeDistance + neighbour[topNode][0] < dist[topNode][1])
                {
                    auto record = s.find(make_pair(dist[neighbour.first], neighbour.first));
                    //          if record found,then erase it
                    if (record != s.end())
                    {
                        s.erase(record);
                    }
                    //                                       distance update
                    dist[neighbour.first] = nodeDistance + neighbour.second;
                    //                                       record push in set
                    s.insert(make_pair(dist[neighbour.first], neighbour.first));
                }
            }
        }
        return dist;
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin >> S;
        Solution obj;
        vector<int> res = obj.dijkstra(V, adj, S);
        for (int i = 0; i < V; i++)
        {
            cout << res[i] << " ";
        }
        cout << endl;
    }
    return 0;
}