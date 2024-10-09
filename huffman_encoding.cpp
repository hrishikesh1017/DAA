#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// A tree node for Huffman Tree
struct Node {
    char ch;                 // character
    int freq;                // frequency of the character
    Node *left, *right;      // left and right child nodes

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

// Comparator for priority queue (min-heap)
struct compare {
    bool operator()(Node* l, Node* r) {
        // Min-heap based on frequency
        return l->freq > r->freq;
    }
};

// Traverse the Huffman Tree and store Huffman codes in a map
void encode(Node* root, string str, unordered_map<char, string>& huffmanCode) {
    if (root == nullptr)
        return;

    // Leaf node contains a character
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

// Utility function to print the encoded string and decode it
void printEncodedString(const string& text, const unordered_map<char, string>& huffmanCode) {
    cout << "Huffman Encoded String: ";
    for (char ch : text) {
        cout << huffmanCode.at(ch);
    }
    cout << endl;
}

// Build the Huffman Tree and decode the encoded string
void buildHuffmanTree(const string& text) {
    // Calculate frequency of each character
    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    // Create a priority queue (min-heap) to store live nodes of the Huffman tree
    priority_queue<Node*, vector<Node*>, compare> pq;

    // Create a leaf node for each character and add it to the priority queue
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Iterate until the size of the queue becomes 1
    while (pq.size() != 1) {
        // Remove the two nodes with the lowest frequency
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        // Create a new internal node with the sum of the two nodes' frequencies
        Node* sum = new Node('\0', left->freq + right->freq);
        sum->left = left;
        sum->right = right;

        pq.push(sum); // Add the new node to the priority queue
    }

    // The root of the Huffman tree
    Node* root = pq.top();

    // Traverse the Huffman tree and store the Huffman codes
    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    // Print the generated Huffman codes
    cout << "Huffman Codes:\n";
    for (auto pair : huffmanCode) {
        cout << pair.first << " " << pair.second << endl;
    }

    // Print the encoded string
    printEncodedString(text, huffmanCode);
}

int main() {
    string text = "huffman encoding example";

    buildHuffmanTree(text);

    return 0;
}
