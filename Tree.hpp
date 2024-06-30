#ifndef TREE_HPP
#define TREE_HPP
#include <iostream>
#include <vector>

#include "InOrderIterator.hpp"
#include "TreeIterator.hpp"
#include "PreOrderIterator.hpp"
#include "PostOrderIterator.hpp"
#include "BFSIterator.hpp"
#include "DFSIterator.hpp"
#include <SFML/Graphics.hpp>


using namespace std;

template <typename T, int N = 2>
class Tree
{
public:
  Tree() : root(nullptr)
  {
  }

  Node<T> *get_root() const
  {
    return root;
  }

  void add_root(Node<T> *new_root)
  {
    if (this->root == nullptr)
    {
      this->root = new_root;
    }
    else
    {
      cout << "Root already exists" << endl;
    }
  }

  bool checkIfParentExists(Node<T> *node, Node<T> *parent)
  {
    if (node == parent)
    {
      return true;
    }

    for (Node<T> *child : *node->get_children())
    {
      if (checkIfParentExists(child, parent))
      {
        return true;
      }
    }

    return false;
  }

  void add_sub_node(Node<T> *parent, Node<T> *new_child)
  {
    if (root == nullptr)
    {
      cout << "Root is null" << endl;
      return;
    }

    if (parent == nullptr)
    {
      cout << "Parent is null" << endl;
      return;
    }

    if (new_child == nullptr)
    {
      cout << "Child is null" << endl;
      return;
    }

    if (!checkIfParentExists(this->root, parent))
    {
      cout << "Parent does not exist" << endl;
      return;
    }

    if (parent->get_children()->size() >= N)
    {
      cout << "Parent has max children" << endl;
      return;
    }

    parent->add_child(new_child);
  }

  // ----------------- Iterators -----------------

  TreeIterator<T, N> *begin_pre_order()
  {
    if (root == nullptr)
    {
      if (N > 2)
      {
        return new DFSIterator<T, N>(nullptr);
      }
      return new PreOrderIterator<T, N>(nullptr);
    }

    if (N > 2)
    {
      return new DFSIterator<T, N>(this);
    }
    return new PreOrderIterator<T, N>(this);
  }

  TreeIterator<T, N> *begin_in_order()
  {
    if (root == nullptr)
    {
      if (N > 2)
      {
        return new DFSIterator<T, N>(nullptr);
      }
      return new InOrderIterator<T, N>(nullptr);
    }

    if (N > 2)
    {
      return new DFSIterator<T, N>(this);
    }
    return new InOrderIterator<T, N>(this);
  }

  TreeIterator<T, N> *begin_post_order()
  {
    if (root == nullptr)
    {
      if (N > 2)
      {
        return new DFSIterator<T, N>(nullptr);
      }
      return new PostOrderIterator<T, N>(nullptr);
    }

    if (N > 2)
    {
      return new DFSIterator<T, N>(this);
    }
    return new PostOrderIterator<T, N>(this);
  }

  BFSIterator<T, N> begin_bfs_scan()
  {
    if (root == nullptr)
    {
      return BFSIterator<T, N>(nullptr);
    }

    return BFSIterator<T, N>(this);
  }

  DFSIterator<T, N> begin_dfs_scan()
  {
    if (root == nullptr)
    {
      return DFSIterator<T, N>(nullptr);
    }

    return DFSIterator<T, N>(this);
  }

  // ----------------- End Iterators -----------------

  TreeIterator<T, N> *end_pre_order()
  {
    if (N > 2)
    {
      return new DFSIterator<T, N>(nullptr);
    }
    return new PreOrderIterator<T, N>(nullptr);
  }

  TreeIterator<T, N> *end_in_order()
  {
    if (N > 2)
    {
      return new DFSIterator<T, N>(nullptr);
    }
    return new InOrderIterator<T, N>(nullptr);
  }

  TreeIterator<T, N> *end_post_order()
  {
    if (N > 2)
    {
      return new DFSIterator<T, N>(nullptr);
    }
    return new PostOrderIterator<T, N>(nullptr);
  }

  BFSIterator<T, N> end_bfs_scan()
  {
    return BFSIterator<T, N>(nullptr);
  }

  DFSIterator<T, N> end_dfs_scan()
  {
    return DFSIterator<T, N>(nullptr);
  }

  // -------------------------------------

  void draw(sf::RenderWindow &window) const
  {
    if (root != nullptr)
    {
      drawNode(window, root, window.getSize().x / 2, 50, window.getSize().x / 4);
    }
  }

  friend ostream &operator<<(ostream &os, const Tree<T, N> &tree)
  {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Tree Visualization");

    while (window.isOpen())
    {
      sf::Event event;
      while (window.pollEvent(event))
      {
        if (event.type == sf::Event::Closed)
          window.close();
      }

      window.clear();
      tree.draw(window);
      window.display();
    }

    return os;
  }

private:
  Node<T> *root;
};
#endif // TREE_HPP