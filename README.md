# Huffman Encoder and Decoder

This project implements a basic Huffman encoder and decoder in C++. Huffman encoding is a compression algorithm that assigns variable-length codes to characters, with shorter codes assigned to more frequent characters. This implementation includes the following files:

- `Huffman.h`
- `Huffman.cpp`
- `Node.h`
- `Node.cpp`

## Files

- `Huffman.h`: Header file for the Huffman class, which handles encoding and decoding operations.
- `Huffman.cpp`: Implementation file for the Huffman class methods.
- `Node.h`: Header file for the Node class, representing the nodes of the Huffman tree.
- `Node.cpp`: Implementation file for the Node class constructor.

## Usage

### Building the Project

To compile the project, you can use a C++ compiler such as `g++`. Open a terminal and run the following command:

```sh
g++ -o huffman Huffman.cpp Node.cpp


Encoding a string

#include <iostream>
#include "Huffman.h"

int main() {
    Huffman huffman;
    std::string text = "this is an example for huffman encoding";

    std::string encodedText = huffman.encode(text);
    std::cout << "Encoded text: " << encodedText << std::endl;

    return 0;
}

Decoding a string

#include <iostream>
#include "Huffman.h"

int main() {
    Huffman huffman;
    std::string text = "this is an example for huffman encoding";

    std::string encodedText = huffman.encode(text);
    std::cout << "Encoded text: " << encodedText << std::endl;

    std::string decodedText = huffman.decode(encodedText);
    std::cout << "Decoded text: " << decodedText << std::endl;

    return 0;
}

Cleaning Up
The Huffman class destructor will automatically clean up the Huffman tree to avoid memory leaks. If you need to manually clean up, you can call the cleanUp method, passing the root of the Huffman tree.
