#ifndef POSTORDERITERATOR_HPP
#define POSTORDERITERATOR_HPP

#include <stack>
using namespace std;

template <typename T>
class Tree;

template <typename T>
class Node;

template <typename T>
class PostOrderIterator
{
private:
  stack<Node<T> *> nodeStack;

  void findNextLeaf(Node<T> *node)
  {
    while (node != nullptr)
    {
      nodeStack.push(node);
      if (node->getLeft() != nullptr)
      {
        node = node->getLeft();
      }
      else
      {
        node = node->getRight();
      }
    }
  }

public:
  PostOrderIterator(Tree<T> *tree) : nodeStack(stack<Node<T> *>())
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

  PostOrderIterator<T> &operator++()
  {
    if (!nodeStack.empty())
    {
      Node<T> *node = nodeStack.top();
      nodeStack.pop();
      if (!nodeStack.empty() && nodeStack.top()->getLeft() == node)
      {
        findNextLeaf(nodeStack.top()->getRight());
      }
    }
    return *this;
  }

  bool operator!=(const PostOrderIterator<T> &other)
  {
    return nodeStack.size() != other.nodeStack.size();
  }

  T *get_value()
  {
    return nodeStack.top()->getValue();
  }
};

#endif // POSTORDERITERATOR_HPP