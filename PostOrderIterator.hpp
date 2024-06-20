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
      if (node->getRight() != nullptr)
      {
        nodeStack.push(node->getRight());
      }
      nodeStack.push(node);
      node = node->getLeft();
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
      if (!nodeStack.empty() && nodeStack.top() == node->getRight())
      {
        node = nodeStack.top();
        nodeStack.pop();
        findNextLeaf(node->getRight());
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
    return &nodeStack.top()->getValue();
  }
};

#endif // POSTORDERITERATOR_HPP