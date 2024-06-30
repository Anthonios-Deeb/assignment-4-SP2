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
  Node<T> * root;
  

  void DFS()
  {
    Node<T> *current = nodeStack.top();
    nodeStack.pop();
    vector<Node<T> *> *children = current->get_children();
    for (int i = children->size() - 1; i >= 0; i--)
    {
      if (children->at(i) != nullptr)
      {
        nodeStack.push(children->at(i));
      }
    }
  }

public:
  DFSIterator(Tree<T, N> *tree) : nodeStack(stack<Node<T> *>()) 
  {
    if (tree != nullptr && tree->get_root() != nullptr)
    {
      nodeStack.push(tree->get_root());      
    }
  }

  T* operator*() override
  {
    return nodeStack.top()->getValue();
  }

  DFSIterator<T, N> &operator++() override
  {
    if (!nodeStack.empty())
    {
      DFS();
    }
    return *this;
  }

  bool operator!=(const TreeIterator<T, N> &other) override
  {
    return nodeStack.empty() != static_cast<const DFSIterator<T, N> &>(other).nodeStack.empty();
  }

  T *get_value() override
  {
    return nodeStack.top()->getValue();
  }
};

#endif // DFSITERATOR_HPP