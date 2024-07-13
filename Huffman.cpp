#include "Huffman.h"
#include <queue>
#include <vector>

Huffman::Huffman() : root(nullptr) {}

Huffman::~Huffman()
{
    cleanUp(root);
}

void Huffman::buildFrequencyTable(const std::string &text)
{
    for (char ch : text)
    {
        frequencyTable[ch]++;
    }
}

void Huffman::buildHuffmanTree()
{
    auto cmp = [](Node *left, Node *right)
    { return left->freq > right->freq; };
    std::priority_queue<Node *, std::vector<Node *>, decltype(cmp)> minHeap(cmp);

    for (const auto &pair : frequencyTable)
    {
        minHeap.push(new Node(pair.first, pair.second));
    }

    while (minHeap.size() > 1)
    {
        Node *left = minHeap.top();
        minHeap.pop();
        Node *right = minHeap.top();
        minHeap.pop();

        Node *sum = new Node('\0', left->freq + right->freq);
        sum->left = left;
        sum->right = right;
        minHeap.push(sum);
    }

    root = minHeap.top();
}

void Huffman::generateCodes(Node *root, const std::string &str)
{
    if (!root)
        return;

    if (!root->left && !root->right)
    {
        huffmanCodes[root->ch] = str;
    }

    generateCodes(root->left, str + "0");
    generateCodes(root->right, str + "1");
}

std::string Huffman::encode(const std::string &text)
{
    buildFrequencyTable(text);
    buildHuffmanTree();
    generateCodes(root, "");

    std::string encodedText;
    for (char ch : text)
    {
        encodedText += huffmanCodes[ch];
    }

    return encodedText;
}

std::string Huffman::decode(const std::string &encodedText)
{
    std::string decodedText;
    Node *current = root;

    for (char bit : encodedText)
    {
        if (bit == '0')
        {
            current = current->left;
        }
        else
        {
            current = current->right;
        }

        if (!current->left && !current->right)
        {
            decodedText += current->ch;
            current = root;
        }
    }

    return decodedText;
}

void Huffman::cleanUp(Node *node)
{
    if (!node)
        return;

    cleanUp(node->left);
    cleanUp(node->right);

    delete node;
}
