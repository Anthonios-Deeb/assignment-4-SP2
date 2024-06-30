#include <iostream>
#include <string>
#include "Node.hpp"
#include "Tree.hpp"

using namespace std;

int main()
{
  Node<double> root_node = Node<double>(1.1);
  Tree<double> tree; // Binary tree that contains doubles.
  tree.add_root(&root_node);

  Node<double> n1 = Node<double>(1.2);
  Node<double> n2 = Node<double>(1.3);
  Node<double> n3 = Node<double>(1.4);
  Node<double> n4 = Node<double>(1.5);
  Node<double> n5 = Node<double>(1.6);

  tree.add_sub_node(&root_node, &n1);
  tree.add_sub_node(&root_node, &n2);
  tree.add_sub_node(&n1, &n3);
  tree.add_sub_node(&n1, &n4);
  tree.add_sub_node(&n2, &n5);

  // // The tree should look like:
  // /**
  //  *       root = 1.1
  //  *     /       \
  //  *    1.2      1.3
  //  *   /  \      /
  //  *  1.4  1.5  1.6
  //  */

  cout << tree; // Should print the graph using GUI.

  // cout << "Pre order:" << endl;
  // for (auto *node = tree.begin_pre_order(); (*node) != *tree.end_pre_order(); ++*node)
  // {
  //   cout << *node->get_value() << endl;
  // }

  // // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6

  // cout << "Post order:" << endl;
  // for (auto *node = tree.begin_post_order(); (*node) != *tree.end_post_order(); ++*node)
  // {
  //   cout << *node->get_value() << endl;
  // }
  // // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1

  // cout << "In order:" << endl;
  // for (auto *node = tree.begin_in_order(); (*node) != *tree.end_in_order(); ++*node)
  // {
  //   cout << *node->get_value() << endl;
  // } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3

  // cout << "BFS:" << endl;
  // for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
  // {
  //   cout << *node.get_value() << endl;
  // } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

  // cout << "DFS:" << endl;
  // for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
  // {
  //   cout << *node.get_value() << endl;
  // } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6

  // cout << tree; // Should print the graph using GUI.

  // Tree<double, 3> three_ary_tree; // 3-ary tree.
  // Node<double> root__node = Node<double>(2.1);
  // three_ary_tree.add_root(&root__node);
  
  // Node<double> n_1 = Node<double>(2.2);
  // Node<double> n_2 = Node<double>(2.3);
  // Node<double> n_3 = Node<double>(2.4);
  // Node<double> n_4 = Node<double>(2.5);
  // Node<double> n_5 = Node<double>(2.6);
  // Node<double> n_6 = Node<double>(2.7);
  // Node<double> n_7 = Node<double>(2.8);
  // Node<double> n_8 = Node<double>(2.9);
  // Node<double> n_9 = Node<double>(2.10);
  // Node<double> n_10 = Node<double>(2.11);

  // three_ary_tree.add_sub_node(&root__node, &n_1);
  // three_ary_tree.add_sub_node(&root__node, &n_2);
  // three_ary_tree.add_sub_node(&root__node, &n_3);
  // three_ary_tree.add_sub_node(&n_1, &n_4);
  // three_ary_tree.add_sub_node(&n_1, &n_5);
  // three_ary_tree.add_sub_node(&n_1, &n_6);
  // three_ary_tree.add_sub_node(&n_2, &n_7);
  // three_ary_tree.add_sub_node(&n_2, &n_8);
  // three_ary_tree.add_sub_node(&n_2, &n_9);
  // three_ary_tree.add_sub_node(&n_3, &n_10);

  // cout << "Pre order:" << endl;
  // for (auto* node = three_ary_tree.begin_pre_order(); (*node) != *three_ary_tree.end_pre_order(); ++*node)
  // {
  //   cout << *node->get_value() << endl;
  // } // prints: 2.1, 2.2, 2.4, 2.5, 2.6, 2.3, 2.7, 2.8, 2.9, 2.10

  // cout << "Post order:" << endl;
  // for (auto* node = three_ary_tree.begin_post_order(); (*node) != *three_ary_tree.end_post_order(); ++*node)
  // {
  //   cout << *node->get_value() << endl;
  // } // prints: 2.5, 2.6, 2.4, 2.7, 2.8, 2.9, 2.10, 2.3, 2.2, 2.1

  // cout << "In order:" << endl;
  // for (auto* node = three_ary_tree.begin_in_order(); (*node) != *three_ary_tree.end_in_order(); ++*node)
  // {
  //   cout << *node->get_value() << endl;
  // } // prints: 2.5, 2.4, 2.6, 2.2, 2.7, 2.1, 2.8, 2.3, 2.9, 2.10

  // cout << "BFS:" << endl;
  // for (auto node = three_ary_tree.begin_bfs_scan(); node != three_ary_tree.end_bfs_scan(); ++node)
  // {
  //   cout << *node.get_value() << endl;
  // } // prints: 2.1, 2.2, 2.3, 2.4, 2.5, 2.6, 2.7, 2.8, 2.9, 2.10

  // cout << "DFS:" << endl;
  // for (auto node = three_ary_tree.begin_dfs_scan(); node != three_ary_tree.end_dfs_scan(); ++node)
  // {
  //   cout << *node.get_value() << endl;
  // } // prints: 2.1, 2.2, 2.4, 2.5, 2.6, 2.3, 2.7, 2.8, 2.9, 2.10
  
  return 0;
}