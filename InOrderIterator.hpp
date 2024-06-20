#ifndef InORDERITERATOR_HPP
#define InORDERITERATOR_HPP

#include <stack>
using namespace std;

template <typename T>
class Tree;

template <typename T>
class Node;

template <typename T>
class InOrderIterator
{
private:
  stack<Node<T> *> nodeStack;

  void findNextLeaf(Node<T> *start)
  {
    Node<T> *current = start;
    while (current != nullptr)
    {
      nodeStack.push(current);
      current = current->getLeft();
    }
  }

public:
  InOrderIterator(Tree<T> *tree) : nodeStack(stack<Node<T> *>())
  {
    if (tree != nullptr)
    {
      findNextLeaf(tree->get_root());
    }
  }

  T &operator*()
  {
    return nodeStack.top()->getValue();
  }

  InOrderIterator<T> &operator++()
  {
    if (!nodeStack.empty())
    {
      Node<T> *node = nodeStack.top();
      nodeStack.pop();
      findNextLeaf(node->getRight());
    }
    return *this;
  }

  bool operator!=(const InOrderIterator<T> &other)
  {
    return nodeStack.size() != other.nodeStack.size();
  }

  T *get_value()
  {
    return nodeStack.top()->getValue();
  }
};
#endif // InORDERITERATOR_HPP