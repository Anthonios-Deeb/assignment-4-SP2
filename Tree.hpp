#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>
#include <vector>

#include "PreOrderIterator.hpp"
#include "InOrderIterator.hpp"
#include "PostOrderIterator.hpp"

using namespace std;
template <typename T>

class Tree
{
public:
  Tree() : root(nullptr), max_children(0) {}

  Node<T> *get_root() const
  {
    return root;
  }

  void add_root(Node<T> *root, int max_children = 2)
  {
    if (this->root != nullptr)
    {
      cout << "Root already exists in this tree" << endl;
      return;
    }

    this->root = root;
    this->max_children = max_children;
  }

  void add_sub_node(Node<T> *parent, Node<T> *new_child)
  {
    if (parent == nullptr)
    {
      cout << "Parent node does not exist" << endl;
      return;
    }

    if (new_child == nullptr)
    {
      cout << "Child node does not exist" << endl;
      return;
    }

    if (parent->get_children()->size() >= max_children)
    {
      cout << "Parent node has reached the maximum number of children" << endl;
      return;
    }

    parent->add_child(new_child);
  }

  PreOrderIterator<T> begin_pre_order()
  {
    if (max_children == 2)
    {
      return PreOrderIterator<T>(this);
    }

  }

  PreOrderIterator<T> end_pre_order()
  {
    return PreOrderIterator<T>(nullptr);
  }

  InOrderIterator<T> begin_in_order()
  {
    if (max_children == 2)
    {
      return InOrderIterator<T>(this);
    }
  }

  InOrderIterator<T> end_in_order()
  {
    return InOrderIterator<T>(nullptr);
  }

  PostOrderIterator<T> begin_post_order()
  {
    if (max_children == 2)
    {
      return PostOrderIterator<T>(this);
    }
  }

  PostOrderIterator<T> end_post_order()
  {
    return PostOrderIterator<T>(nullptr);
  }





private:
  Node<T> *root;
  size_t max_children;
};
#endif // TREE_HPP