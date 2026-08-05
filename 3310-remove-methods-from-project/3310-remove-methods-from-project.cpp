class Solution {
public:

    void dfs(int src  , vector<vector<int>> &adj , vector<int> &vis){
        vis[src] = 1;
        for(int next : adj[src]){
            if(!vis[next]){
                dfs(next , adj, vis);
            }
        }

    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);

        for(auto &a:  invocations){
            adj[a[0]].push_back(a[1]);
        }
        vector<int> vis(n , 0);
        dfs(k,adj,vis);

        for(auto &a: invocations){
            int u = a[0];
            int v= a[1];

            if(!vis[u] && vis[v]){
                vector<int> ans;
                for(int i =0;i<n;i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }
        vector<int> ans;

        for(int i =0;i<n;i++){
            if(!vis[i]){
                ans.push_back(i);

            }
        }
        return ans;

    }
};