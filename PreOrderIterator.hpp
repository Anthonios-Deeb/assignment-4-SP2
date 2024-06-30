#ifndef PREORDERITERATOR_HPP
#define PREORDERITERATOR_HPP

#include <stack>
using namespace std;

#include "TreeIterator.hpp"

template <typename T, int N>
class Tree;

template <typename T>
class Node;

template <typename T, int N = 2>

class PreOrderIterator : public TreeIterator<T, N>
{
private:
  stack<Node<T> *> nodeStack;

public:
  PreOrderIterator(Tree<T, N> *tree) : nodeStack(stack<Node<T> *>())
  {
    if (tree != nullptr && tree->get_root() != nullptr)
    {
      Node<T> *root = tree->get_root();
      this->nodeStack.push(root);
    }
  }

  T *operator*() override
  {
    if (nodeStack.empty())
    {
      return nullptr;
    }
    return nodeStack.top()->getValue();
  }

  PreOrderIterator<T, N> &operator++() override
  {
    if (!nodeStack.empty())
    {
      Node<T> *node = nodeStack.top();
      nodeStack.pop();
      vector<Node<T> *> *children = node->get_children();

      for (int i = children->size() - 1; i >= 0; i--)
      {
        if (children->at(i) != nullptr)
        {
          nodeStack.push(children->at(i));
        }
      }
    }
    return *this;
  }

  bool operator!=(const TreeIterator<T, N> &other) override
  {
    return nodeStack.size() != dynamic_cast<const PreOrderIterator<T, N> &>(other).nodeStack.size();
  }

  T *get_value() override
  {
    return nodeStack.top()->getValue();
  }
};
#endif // PREORDERITERATOR_HPP