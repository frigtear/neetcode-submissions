class PrefixTree {
public:
    struct Node {
        Node(char l) : letter(l) {}

        char letter;
        std::unordered_map<char, std::unique_ptr<Node>> children;
        bool isEnd = false;
    };

    PrefixTree() : root('\0') {}
    
    void insert(std::string word) {
        Node* curr = &root;

        for (char letter : word) {
            if (curr->children.contains(letter)) {
                curr = curr->children[letter].get();
            }
            else {
                curr->children[letter] = std::make_unique<Node>(letter);
                curr = curr->children[letter].get();
            }
        }

        curr->isEnd = true;
    }
    
    bool search(std::string word) {
        Node* curr = &root;

        for (char letter : word) {
            if (curr->children.contains(letter)) {
                curr = curr->children[letter].get();
            }
            else {
                return false;
            }
        }

        return curr->isEnd;
    }
    
    bool startsWith(std::string prefix) {
        Node* curr = &root;

        for (char letter : prefix) {
            if (curr->children.contains(letter)) {
                curr = curr->children[letter].get();
            }
            else {
                return false;
            }
        }

        return true;
    }

private:
    Node root;
};