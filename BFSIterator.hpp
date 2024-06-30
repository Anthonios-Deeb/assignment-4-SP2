#ifndef BFSITERATOR_HPP
#define BFSITERATOR_HPP

#include <queue>


using namespace std;

template <typename T,int N>
class Tree;

template <typename T>
class Node;

template <typename T,int N=2>
class BFSIterator
{
private:
  queue<Node<T> *> nodeQueue;

  void BFS()
  {
    Node<T> *current = nodeQueue.front();
    nodeQueue.pop();

    for (Node<T> *child : *current->get_children())
    {
      if (child != nullptr)
      {
        nodeQueue.push(child);
      }
    }
  }

public:
  BFSIterator(Tree<T,N> *tree) : nodeQueue(queue<Node<T> *>())
  {
    if (tree != nullptr && tree->get_root() != nullptr)
    {
      nodeQueue.push(tree->get_root());
    }
  }

  T &operator*()
  {
    return nodeQueue.front()->getValue();
  }

  BFSIterator<T,N> &operator++()
  {
    if (!nodeQueue.empty())
    {
      BFS();
    }
    return *this;
  }

  virtual bool operator!=(const BFSIterator<T,N> &other)
  {
    return nodeQueue.size() != other.nodeQueue.size();
  }

  T *get_value()
  {
    return nodeQueue.front()->getValue();
  }
};

#endif // BFSITERATOR_HPP