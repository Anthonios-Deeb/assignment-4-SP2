// anthoniosdb@gmail.com
// 3993
#ifndef BFSITERATOR_HPP
#define BFSITERATOR_HPP

#include <queue>

using namespace std;

template <typename T, int N>
class Tree;

template <typename T>
class Node;

template <typename T, int N = 2>
class BFSIterator
{
private:
  queue<Node<T> *> nodeQueue;

  void BFS() // Breadth First Search
  {

    Node<T> *current = nodeQueue.front(); // Get the front of the queue
    nodeQueue.pop();                      // Remove the front of the queue

    for (Node<T> *child : *current->get_children()) // Add all the children of the current node to the queue
    {
      if (child != nullptr)
      {
        nodeQueue.push(child); // Add the child to the queue
      }
    }
  }

public:
  // Constructor
  BFSIterator(Tree<T, N> *tree) : nodeQueue(queue<Node<T> *>())
  {
    if (tree != nullptr && tree->get_root() != nullptr) // If the tree is not empty and the root is not empty
    {
      nodeQueue.push(tree->get_root());
    }
  }

  // Prefix increment operator
  BFSIterator<T, N> &operator++()
  {
    if (!nodeQueue.empty())
    {
      BFS(); // Perform the BFS
    }
    return *this;
  }

  // Dereference operator
  virtual bool operator!=(const BFSIterator<T, N> &other)
  {
    return nodeQueue.size() != other.nodeQueue.size(); // Check if the size of the queue is different
  }

  // return the value of the current node
  T *get_value()
  {
    return nodeQueue.front()->getValue();
  }
};

#endif // BFSITERATOR_HPP