#include <iostream>
#include <cstring>
#include <cstdlib>
#define MAX_CHAR 256

struct SuffixTreeNode {
    SuffixTreeNode* children[MAX_CHAR];
    SuffixTreeNode* suffixLink;
    int start;
    int* end;
    int suffixIndex;
};

typedef SuffixTreeNode Node;

char text[100];
Node* root = nullptr;
Node* lastNewNode = nullptr;
Node* activeNode = nullptr;
int count = 0;

int activeEdge = -1;
int activeLength = 0;

int remainingSuffixCount = 0;
int leafEnd = -1;
int* rootEnd = nullptr;
int* splitEnd = nullptr;
int size = -1;

// Function to create a new node in the suffix tree
Node* newNode(int start, int* end) {
    count++;
    Node* node = new Node;
    for (int i = 0; i < MAX_CHAR; i++)
        node->children[i] = nullptr;

    node->suffixLink = root;
    node->start = start;
    node->end = end;
    node->suffixIndex = -1;
    return node;
}

// Function to calculate the length of an edge
int edgeLength(Node* n) {
    return *(n->end) - (n->start) + 1;
}

// Function to perform walk down in the tree
int walkDown(Node* currNode) {
    if (activeLength >= edgeLength(currNode)) {
        activeEdge = static_cast<int>(text[activeEdge + edgeLength(currNode)]) - static_cast<int>(' ');
        activeLength -= edgeLength(currNode);
        activeNode = currNode;
        return 1;
    }
    return 0;
}

// Function to extend the suffix tree
void extendSuffixTree(int pos) {
    leafEnd = pos;
    remainingSuffixCount++;
    lastNewNode = nullptr;

    while (remainingSuffixCount > 0) {

        if (activeLength == 0) {
            activeEdge = static_cast<int>(text[pos]) - static_cast<int>(' ');
        }

        if (activeNode->children[activeEdge] == nullptr) {
            activeNode->children[activeEdge] = newNode(pos, &leafEnd);

            if (lastNewNode != nullptr) {
                lastNewNode->suffixLink = activeNode;
                lastNewNode = nullptr;
            }
        }
        else {
            Node* next = activeNode->children[activeEdge];
            if (walkDown(next)) {
                continue;
            }

            if (text[next->start + activeLength] == text[pos]) {
                if (lastNewNode != nullptr && activeNode != root) {
                    lastNewNode->suffixLink = activeNode;
                    lastNewNode = nullptr;
                }

                activeLength++;
                break;
            }

            splitEnd = new int;
            *splitEnd = next->start + activeLength - 1;

            Node* split = newNode(next->start, splitEnd);
            activeNode->children[activeEdge] = split;

            split->children[static_cast<int>(text[pos]) - static_cast<int>(' ')] = newNode(pos, &leafEnd);
            next->start += activeLength;
            split->children[activeEdge] = next;

            if (lastNewNode != nullptr) {
                lastNewNode->suffixLink = split;
            }

            lastNewNode = split;
        }

        remainingSuffixCount--;
        if (activeNode == root && activeLength > 0) {
            activeLength--;
            activeEdge = static_cast<int>(text[pos - remainingSuffixCount + 1]) - static_cast<int>(' ');
        }
        else if (activeNode != root) {
            activeNode = activeNode->suffixLink;
        }
    }
}

// Function to print characters from index i to j
void print(int i, int j) {
    for (int k = i; k <= j; k++)
        std::cout << text[k];
}

// Function to set suffix index by DFS traversal
void setSuffixIndexByDFS(Node* n, int labelHeight) {
    if (n == nullptr) return;

    if (n->start != -1) {
        print(n->start, *(n->end));
    }
    int leaf = 1;
    for (int i = 0; i < MAX_CHAR; i++) {
        if (n->children[i] != nullptr) {
            if (leaf == 1 && n->start != -1)
                std::cout << " [" << n->suffixIndex << "]\n";

            leaf = 0;
            setSuffixIndexByDFS(n->children[i], labelHeight + edgeLength(n->children[i]));
        }
    }
    if (leaf == 1) {
        n->suffixIndex = size - labelHeight;
        std::cout << " [" << n->suffixIndex << "]\n";
    }
}

// Function to free memory in post-order traversal
void freeSuffixTreeByPostOrder(Node* n) {
    if (n == nullptr)
        return;
    for (int i = 0; i < MAX_CHAR; i++) {
        if (n->children[i] != nullptr) {
            freeSuffixTreeByPostOrder(n->children[i]);
        }
    }
    if (n->suffixIndex == -1)
        delete n->end;
    delete n;
}

// Function to build the suffix tree
void buildSuffixTree() {
    size = strlen(text);
    rootEnd = new int;
    *rootEnd = -1;

    root = newNode(-1, rootEnd);

    activeNode = root;
    for (int i = 0; i < size; i++)
        extendSuffixTree(i);
    int labelHeight = 0;
    setSuffixIndexByDFS(root, labelHeight);

    freeSuffixTreeByPostOrder(root);
}

// Main function
int main(int argc, char* argv[]) {
    strcpy(text, "abbc");
    buildSuffixTree();
    std::cout << "Number of nodes in suffix tree are " << count << std::endl;
    return 0;
}
