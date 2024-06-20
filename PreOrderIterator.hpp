#ifndef PREORDERITERATOR_HPP
#define PREORDERITERATOR_HPP

#include <stack>
using namespace std;

template <typename T>
class Tree;

template <typename T>
class Node;

template <typename T>
class PreOrderIterator
{
private:
  stack<Node<T>*> nodeStack;

public:

  PreOrderIterator(Tree<T> *tree) : nodeStack(stack<Node<T> *>())
  {
    if (tree != nullptr)
    {
      Node<T> *root = tree->get_root();
      this->nodeStack.push(root);
    }
  }

  T &operator*()
  {
    return nodeStack.top()->getValue();
  }

  PreOrderIterator<T> &operator++()
  {
    Node<T> *node = nodeStack.top();
    nodeStack.pop();
    vector<Node<T> *>* children = node->get_children();

    for (int i = children->size() - 1; i >= 0; i--)
    {
      if (children->at(i) != nullptr)
      {
        nodeStack.push(children->at(i));
      }
    }

    return *this;
  }

  bool operator!=(const PreOrderIterator<T> &other)
  {
    return nodeStack.size() != other.nodeStack.size();
  }

  T* get_value()
  {
    return nodeStack.top()->getValue();
  }

};
#endif // PREORDERITERATOR_HPP