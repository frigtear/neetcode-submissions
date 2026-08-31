class Solution {

private:

    bool helper(int node, int parent, std::map<int, std::set<int>> &graph, std::set<int> &visited) {

        visited.insert(node);
        
        for (const auto &neighbor : graph[node]){

            if (neighbor == parent){
                continue;
            }

            if (visited.contains(neighbor)){
                return true;
            }

            helper(neighbor, node, graph, visited);
        }

        return false;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        std::map<int, std::set<int>> graph;

        for ( const auto &edge : edges ) {
            int u = edge[0];
            int v = edge[1];
            graph[u].insert(v);
            graph[v].insert(u);

            std::set<int> visited;

            if (helper(u, -1, graph, visited)){
                return {u, v};
            }
        }

        return {};

    }
};
