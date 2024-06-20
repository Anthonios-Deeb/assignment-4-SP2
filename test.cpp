#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Tree.hpp"
#include "Node.hpp"

TEST_CASE("InOrder")
{
  Node<int> root_node = Node<int>(1);
  Tree<int> tree; // Binary tree that contains doubles.
  tree.add_root(&root_node);

  Node<int> n2 = Node<int>(2);
  Node<int> n3 = Node<int>(3);
  Node<int> n4 = Node<int>(4);
  Node<int> n5 = Node<int>(5);

  tree.add_sub_node(&root_node, &n2);
  tree.add_sub_node(&root_node, &n3);
  tree.add_sub_node(&n2, &n4);
  tree.add_sub_node(&n2, &n5);

  InOrderIterator<int> inOrderIterator = tree.begin_in_order();

  string expected = "4 2 5 1 3 ";
  string actual = "";
  for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
  {
    actual += to_string(*node.get_value()) + " ";
  }

  CHECK(expected == actual);
}

TEST_CASE("PreOrder")
{
  Node<int> root_node = Node<int>(1);
  Tree<int> tree; // Binary tree that contains doubles.
  tree.add_root(&root_node);

  Node<int> n2 = Node<int>(2);
  Node<int> n3 = Node<int>(3);
  Node<int> n4 = Node<int>(4);
  Node<int> n5 = Node<int>(5);

  tree.add_sub_node(&root_node, &n2);
  tree.add_sub_node(&root_node, &n3);
  tree.add_sub_node(&n2, &n4);
  tree.add_sub_node(&n2, &n5);

  PreOrderIterator<int> preOrderIterator = tree.begin_pre_order();
  string expected = "1 2 4 5 3 ";
  string actual = "";
  for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
  {
    actual += to_string(*node.get_value()) + " ";
  }

  CHECK(expected == actual);
}

TEST_CASE("PostOrder")
{
  Node<int> root_node = Node<int>(1);
  Tree<int> tree; // Binary tree that contains doubles.
  tree.add_root(&root_node);

  Node<int> n2 = Node<int>(2);
  Node<int> n3 = Node<int>(3);
  Node<int> n4 = Node<int>(4);
  Node<int> n5 = Node<int>(5);

  tree.add_sub_node(&root_node, &n2);
  tree.add_sub_node(&root_node, &n3);
  tree.add_sub_node(&n2, &n4);
  tree.add_sub_node(&n2, &n5);

  PostOrderIterator<int> postOrderIterator = tree.begin_post_order();
  string expected = "4 5 2 3 1 ";
  string actual = "";
  for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
  {
    actual += to_string(*node.get_value()) + " ";
  }

  CHECK(expected == actual);
}