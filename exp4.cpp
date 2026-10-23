
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

// Compare nodes by frequency
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Print Huffman codes
void printCodes(Node* root, string code) {
    if (!root)
        return;

    // Leaf node
    if (!root->left && !root->right) {
        cout << root->ch << " : " << code << '\n';
        return;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

void huffman(char chars[], int freq[], int n) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    // Insert all characters into the min-heap
    for (int i = 0; i < n; i++)
        pq.push(new Node(chars[i], freq[i]));

    // Build the Huffman tree
    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* parent = new Node('$',
                                left->freq + right->freq);

        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    // Generate codes from the tree
    printCodes(pq.top(), "");
}

int main() {
    char chars[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    int n = sizeof(chars) / sizeof(chars[0]);

    cout << "Huffman Codes:\n";
    huffman(chars, freq, n);

    return 0;
}
