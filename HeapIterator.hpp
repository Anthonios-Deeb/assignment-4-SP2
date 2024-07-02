// anthoniosdb@gmail.com
// 3993
#ifndef HEAPITERATOR_HPP
#define HEAPITERATOR_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

using namespace std;

template <typename T, int N>
class Tree;

template <typename T>
class Node;

template <typename T, int N = 2>
class HeapIterator
{
public:
    // Default constructor
    HeapIterator() : tree(nullptr), currentIndex(0), isEnd(true) {}

    // Constructor
    HeapIterator(Tree<T, N> *tree) : isEnd(false)
    {
        if (tree != nullptr && tree->get_root() != nullptr)
        {
            currentIndex = 0;              // Set the current index to 0
            this->tree = tree;             // Set the tree
            flattenTree(tree->get_root()); // Flatten the tree into a vector

            // Sort the heap
            std::sort(heap.begin(), heap.end(), [](Node<T> *lhs, Node<T> *rhs)
                      { return *lhs->getValue() < *rhs->getValue(); });
        }
    }

    // Prefix increment operator
    HeapIterator<T, N> &operator++()
    {
        if (currentIndex < heap.size())
        {
            currentIndex++;
        }
        if (currentIndex >= heap.size())
        {
            isEnd = true;
        }
        return *this;
    }

    // Dereference operator
    bool operator!=(const HeapIterator &other) const
    {
        if (isEnd && other.isEnd)
            return false;
        if (isEnd != other.isEnd)
            return true;
        return currentIndex != other.currentIndex;
    }

    // return the value of the current node
    T *get_value()
    {
        if (currentIndex >= heap.size())
        {
            return nullptr;
        }
        return heap[currentIndex]->getValue();
    }

private:
    Tree<T, N> *tree;       // The tree
    vector<Node<T> *> heap; // The heap flattened into a vector
    size_t currentIndex;    // The current index
    bool isEnd;             // Is the iterator at the end

    // Helper function to flatten the tree into a vector
    void flattenTree(Node<T> *node)
    {
        if (!node)
        {
            return;
        }

        heap.push_back(node); // Add the current node to the heap

        for (Node<T> *child : *node->get_children())
        {
            flattenTree(child); // Flatten the children of the current node
        }
    }
};

#endif // HEAPITERATOR_HPP