class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* cloneGraph(Node* node) {
        if (node == NULL)
            return NULL;

        // If node is already cloned
        if (mp.count(node))
            return mp[node];

        // Create clone
        Node* clone = new Node(node->val);

        // Store original -> clone mapping
        mp[node] = clone;

        // Clone all neighbors
        for (Node* neighbor : node->neighbors) {
            clone->neighbors.push_back(cloneGraph(neighbor));
        }

        return clone;
    }
};