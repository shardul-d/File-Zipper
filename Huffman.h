#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <string>
#include <unordered_map>
#include "Node.h"

class Huffman
{
public:
    Huffman();
    ~Huffman();

    void buildFrequencyTable(const std::string &text);
    void buildHuffmanTree();
    void generateCodes(Node *root, const std::string &str);
    std::string encode(const std::string &text);
    std::string decode(const std::string &encodedText);
    void cleanUp(Node *node);

private:
    std::unordered_map<char, int> frequencyTable;
    std::unordered_map<char, std::string> huffmanCodes;
    Node *root;
};

#endif // HUFFMAN_H
