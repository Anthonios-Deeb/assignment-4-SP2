#ifndef InORDERITERATOR_HPP
#define InORDERITERATOR_HPP

#include <stack>
using namespace std;

template <typename T,int N>
class Tree;

template <typename T>
class Node;

template <typename T,int N>
class TreeIterator;

template <typename T,int N=2>
class InOrderIterator : public TreeIterator<T,N>
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
  InOrderIterator(Tree<T,N> *tree) : nodeStack(stack<Node<T> *>())
  {
    if (tree != nullptr)
    {
      findNextLeaf(tree->get_root());
    }
  }

  T* operator*() override
  {
    return nodeStack.top()->getValue();
  }

  InOrderIterator<T,N> &operator++() override
  {
    if (!nodeStack.empty())
    {
      Node<T> *node = nodeStack.top();
      nodeStack.pop();
      findNextLeaf(node->getRight());
    }
    return *this;
  }

  bool operator!=(const TreeIterator<T,N> &other) override
  {
    return nodeStack.size() != dynamic_cast<const InOrderIterator<T,N> &>(other).nodeStack.size();
  }

  T *get_value() override
  {
    return nodeStack.top()->getValue();
  }
};
#endif // InORDERITERATOR_HPP