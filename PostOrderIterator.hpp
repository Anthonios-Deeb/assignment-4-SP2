// anthoniosdb@gmail.com
// 3993
#ifndef POSTORDERITERATOR_HPP
#define POSTORDERITERATOR_HPP

#include "TreeIterator.hpp"

#include <stack>
using namespace std;

template <typename T, int N>
class Tree;

template <typename T>
class Node;

template <typename T, int N = 2>
class PostOrderIterator : public TreeIterator<T, N>
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
  PostOrderIterator(Tree<T, N> *tree) : nodeStack(stack<Node<T> *>())
  {
    if (tree != nullptr && tree->get_root() != nullptr)
    {
      findNextLeaf(tree->get_root());
    }
  }

  ~PostOrderIterator() override = default;

  PostOrderIterator<T, N> &operator++() override
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

  bool operator!=(const TreeIterator<T, N> &other) override
  {
    return nodeStack.size() != dynamic_cast<const PostOrderIterator<T, N> &>(other).nodeStack.size();
  }

  T *get_value() override
  {
    return nodeStack.top()->getValue();
  }
};

#endif // POSTORDERITERATOR_HPP