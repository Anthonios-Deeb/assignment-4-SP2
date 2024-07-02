// anthoniosdb@gmail.com
// 3993
#ifndef DFSITERATOR_HPP
#define DFSITERATOR_HPP

#include <stack>
using namespace std;

template <typename T, int N>
class Tree;

template <typename T>
class Node;

template <typename T, int N>
class TreeIterator;

template <typename T, int N = 2>
class DFSIterator : public TreeIterator<T, N>
{
private:
  stack<Node<T> *> nodeStack;
  Node<T> *root;

  // Depth First Search
  void DFS()
  {
    Node<T> *current = nodeStack.top();                    // Get the top of the stack
    nodeStack.pop();                                       // Remove the top of the stack
    vector<Node<T> *> *children = current->get_children(); // Get the children of the current node
    for (int i = children->size() - 1; i >= 0; i--)        // Add all the children of the current node to the stack
    {
      if (children->at(i) != nullptr) // If the child is not empty
      {
        nodeStack.push(children->at(i)); // Add the child to the stack
      }
    }
  }

public:
  // Constructor for the DFSIterator
  DFSIterator(Tree<T, N> *tree) : nodeStack(stack<Node<T> *>())
  {
    if (tree != nullptr && tree->get_root() != nullptr)
    {
      nodeStack.push(tree->get_root());
    }
  }

  // Destructor for the DFSIterator
  ~DFSIterator() override = default;

  // Prefix increment operator
  DFSIterator<T, N> &operator++() override
  {
    if (!nodeStack.empty()) // If the stack is not empty
    {
      DFS(); // Perform the DFS
    }
    return *this;
  }

  // Inequality operator
  bool operator!=(const TreeIterator<T, N> &other) override
  {
    return nodeStack.empty() != static_cast<const DFSIterator<T, N> &>(other).nodeStack.empty();
  }

  // return the value of the current node
  T *get_value() override
  {
    return nodeStack.top()->getValue();
  }
};

#endif // DFSITERATOR_HPP