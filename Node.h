#ifndef NODE_H
#define NODE_H

class Node
{
public:
    char ch;
    int freq;
    Node *left;
    Node *right;

    Node(char ch, int freq);
};

#endif // NODE_H
