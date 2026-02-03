// Given a set of characters and their corresponding frequencies, write a program to construct the Huffman Tree and generate Huffman codes for each character such that the total number of bits required for encoding is minimized.
// E.g.:
// Input:
// Characters = [a, b, c, d, e, f]
// Frequencies = [5, 9, 12, 13, 16, 45]
// Output:
// Character Huffman Code
// a 1100
// b 1101
// c 100
// d 101
// e 111
// f 0
  

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Node of Huffman Tree
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

// Comparator for Min Heap
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Print Huffman Codes
void printCodes(Node* root, string code) {

    if (root == NULL)
        return;

    // If leaf node
    if (!root->left && !root->right) {
        cout << root->ch << "  " << code << endl;
        return;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {

    vector<char> chars = {'a','b','c','d','e','f'};
    vector<int> freq  = {5, 9, 12, 13, 16, 45};

    int N = chars.size();

    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    // Insert all characters
    for (int i = 0; i < N; i++) {
        minHeap.push(new Node(chars[i], freq[i]));
    }

    // Build Huffman Tree
    while (minHeap.size() > 1) {

        Node* left = minHeap.top();
        minHeap.pop();

        Node* right = minHeap.top();
        minHeap.pop();

        Node* newNode = new Node('$',
                                left->freq + right->freq);

        newNode->left = left;
        newNode->right = right;

        minHeap.push(newNode);
    }

    // Root of tree
    Node* root = minHeap.top();

    cout << "Character Huffman Code\n";

    // Print codes
    printCodes(root, "");

    return 0;
}
