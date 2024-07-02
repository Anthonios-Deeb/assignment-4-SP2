// anthoniosdb@gmail.com
// 3993
#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

template <typename T>
class Node
{

public:
  Node(T value) : value(new T(value)), children(new vector<Node<T> *>())
  {
  }

  ~Node()
  {
    delete value;
  }

  // equals operator
  bool operator==(const Node<T> &other) const
  {
    return this->getValue() == other.getValue();
  }

  // not equals operator
  bool operator!=(const Node<T> &other) const
  {
    return this->getValue() != other.getValue();
  }

  T *getValue() const
  {
    return value;
  }

  vector<Node<T> *> *get_children() const
  {
    return children;
  }

  void add_child(Node<T> *child)
  {
    children->push_back(child);
  }

  Node<T> *getLeft()
  {
    if (this->children->size() > 0 && this->children->at(0) != nullptr)
    {
      return this->children->at(0);
    }
    return nullptr;
  }

  Node<T> *getRight()
  {
    if (this->children->size() > 1 && this->children->at(1) != nullptr)
    {
      return this->children->at(1);
    }
    return nullptr;
  }

  std::string nodeToString()
  {
    // Fixed method to correctly convert the value of the node to a string
    if (value == nullptr)
      return "null";
    std::ostringstream oss;
    oss << *value; // Dereference value to get the actual value instead of the pointer
    return oss.str();
  }

private:
  T *value; // the key of the node is unknown, so we use a template
  vector<Node<T> *> *children;
};

#endif // NODE_HPP