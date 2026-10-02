/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {

private:

    std::unordered_map<int, Node*> nodes;


public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr){
            return nullptr;
        }
       // std::cout << node->val << std::endl;
        std::vector<Node*> toVisit;

        Node* copy = new Node(node->val);
        nodes[node->val] = copy;

        for (const auto& neighbor : node->neighbors){
            if (!nodes.contains(neighbor->val)){
                toVisit.push_back(cloneGraph(neighbor));
            }
            else{
                toVisit.push_back(nodes[neighbor->val]);
            }
        }

        copy->neighbors = toVisit;

        return copy;

    }
};
