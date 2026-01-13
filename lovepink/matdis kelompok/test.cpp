#include <iostream>
#include <string>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;
};

Node* nodes[100];
int nodeCount = 0;

string codes[256];

// Buat node baru
Node* newNode(char ch, int freq) {
    Node* n = new Node();
    n->ch = ch;
    n->freq = freq;
    n->left = NULL;
    n->right = NULL;
    return n;
}

// Cari dua node dengan frekuensi terkecil
void findTwoSmallest(int &i1, int &i2) {
    i1 = i2 = -1;
    for (int i = 0; i < nodeCount; i++) {
        if (nodes[i] == NULL) continue;

        if (i1 == -1 || nodes[i]->freq < nodes[i1]->freq) {
            i2 = i1;
            i1 = i;
        } else if (i2 == -1 || nodes[i]->freq < nodes[i2]->freq) {
            i2 = i;
        }
    }
}

// Bangun Huffman Tree
Node* buildTree() {
    while (true) {
        int i1, i2;
        findTwoSmallest(i1, i2);

        if (i2 == -1) break;

        Node* parent = newNode('\0',
            nodes[i1]->freq + nodes[i2]->freq);
        parent->left = nodes[i1];
        parent->right = nodes[i2];

        nodes[i1] = parent;
        nodes[i2] = NULL;
    }

    for (int i = 0; i < nodeCount; i++) {
        if (nodes[i] != NULL)
            return nodes[i];
    }
    return NULL;
}

// Generate Huffman Code
void generateCode(Node* root, string code) {
    if (root == NULL) return;

    if (root->left == NULL && root->right == NULL) {
        codes[(unsigned char)root->ch] = code;
        return;
    }

    generateCode(root->left, code + "0");
    generateCode(root->right, code + "1");
}

// Decode
string decode(Node* root, string encoded) {
    string result = "";
    Node* cur = root;

    for (int i = 0; i < encoded.length(); i++) {
        if (encoded[i] == '0')
            cur = cur->left;
        else
            cur = cur->right;

        if (cur->left == NULL && cur->right == NULL) {
            result += cur->ch;
            cur = root;
        }
    }
    return result;
}

int main() {
    string text;
    cout << "Masukkan teks: ";
    getline(cin, text);

    int freq[256] = {0};

    for (int i = 0; i < text.length(); i++)
        freq[(unsigned char)text[i]]++;

    // Buat node awal
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            nodes[nodeCount++] = newNode((char)i, freq[i]);
        }
    }

    Node* root = buildTree();
    generateCode(root, "");

    cout << "\nMapping Huffman Code:\n";
    for (int i = 0; i < 256; i++) {
        if (codes[i] != "")
            cout << (char)i << " : " << codes[i] << endl;
    }

    // Encode
    string encoded = "";
    for (int i = 0; i < text.length(); i++)
        encoded += codes[(unsigned char)text[i]];

    cout << "\nHasil Encoded:\n" << encoded << endl;

    // Decode
    string decoded = decode(root, encoded);
    cout << "\nHasil Decoded:\n" << decoded << endl;

    // Rasio kompresi
    int originalBits = text.length() * 8;
    int compressedBits = encoded.length();

    cout << "\nUkuran Asli (bit): " << originalBits;
    cout << "\nUkuran Terkompresi (bit): " << compressedBits;
    cout << "\nRasio Kompresi: " << (float)compressedBits / originalBits << endl;

    return 0;
}
