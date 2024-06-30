#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Tree.hpp"
#include "Node.hpp"

TEST_CASE("AddRoot")
{
    Node<int> root_node = Node<int>(1);
    Tree<int> tree; // Binary tree that contains doubles.
    tree.add_root(&root_node);

    Node<int> root_node2 = Node<int>(2);
    tree.add_root(&root_node2);

    CHECK(tree.get_root() == &root_node);
}

TEST_CASE("InOrder")
{
    SUBCASE("InOrder_Binary")
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

        string expected = "4 2 5 1 3 ";
        string actual = "";

        for (auto *node = tree.begin_in_order(); (*node) != *tree.end_in_order(); ++*node)
        {
            actual += to_string(*node->get_value()) + " ";
        }
        CHECK(expected == actual);
    }

    SUBCASE("InOrder_Ternary")
    {
        Node<int> root_node = Node<int>(1);
        Tree<int, 3> tree; // Ternary tree that contains doubles.
        tree.add_root(&root_node);

        Node<int> n2 = Node<int>(2);
        Node<int> n3 = Node<int>(3);
        Node<int> n4 = Node<int>(4);
        Node<int> n5 = Node<int>(5);
        Node<int> n6 = Node<int>(6);
        Node<int> n7 = Node<int>(7);
        Node<int> n8 = Node<int>(8);
        Node<int> n9 = Node<int>(9);

        tree.add_sub_node(&root_node, &n2);
        tree.add_sub_node(&root_node, &n3);
        tree.add_sub_node(&root_node, &n4);
        tree.add_sub_node(&n2, &n5);
        tree.add_sub_node(&n2, &n6);
        tree.add_sub_node(&n3, &n7);
        tree.add_sub_node(&n3, &n8);
        tree.add_sub_node(&n4, &n9);

        // it uses DFS iterator
        string expected = "1 2 5 6 3 7 8 4 9 ";
        string actual = "";

        for (auto *node = tree.begin_in_order(); (*node) != *tree.end_in_order(); ++*node)
        {
            actual += to_string(*node->get_value()) + " ";
        }
        CHECK(expected == actual);
    }

    SUBCASE("InOrder_QuadTree")
    {
        Node<int> root_node = Node<int>(1);
        Tree<int, 4> tree; // Quad tree that contains doubles.
        tree.add_root(&root_node);

        Node<int> n2 = Node<int>(2);
        Node<int> n3 = Node<int>(3);
        Node<int> n4 = Node<int>(4);
        Node<int> n5 = Node<int>(5);
        Node<int> n6 = Node<int>(6);
        Node<int> n7 = Node<int>(7);
        Node<int> n8 = Node<int>(8);
        Node<int> n9 = Node<int>(9);
        Node<int> n10 = Node<int>(10);
        Node<int> n11 = Node<int>(11);
        Node<int> n12 = Node<int>(12);
        Node<int> n13 = Node<int>(13);

        tree.add_sub_node(&root_node, &n2);
        tree.add_sub_node(&root_node, &n3);
        tree.add_sub_node(&root_node, &n4);
        tree.add_sub_node(&root_node, &n5);
        tree.add_sub_node(&n2, &n6);
        tree.add_sub_node(&n2, &n7);
        tree.add_sub_node(&n2, &n8);
        tree.add_sub_node(&n2, &n9);
        tree.add_sub_node(&n3, &n10);
        tree.add_sub_node(&n4, &n11);
        tree.add_sub_node(&n3, &n12);
        tree.add_sub_node(&n5, &n13);

        // it uses DFS iterator
        string expected = "1 2 6 7 8 9 3 10 12 4 11 5 13 ";
        string actual = "";

        for (auto *node = tree.begin_in_order(); (*node) != *tree.end_in_order(); ++*node)
        {
            actual += to_string(*node->get_value()) + " ";
        }
        CHECK(expected == actual);
    }

    SUBCASE("InOrder_NULLRoot")
    {
        Tree<int> tree; // Binary tree that contains doubles.

        string expected = "";
        string actual = "";

        for (auto *node = tree.begin_in_order(); (*node) != *tree.end_in_order(); ++*node)
        {
            actual += to_string(*node->get_value()) + " ";
        }
        CHECK(expected == actual);
    }
}

TEST_CASE("PreOrder")
{
    SUBCASE("PreOrder_Binary")
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

        string expected = "1 2 4 5 3 ";
        string actual = "";

        for (auto *node = tree.begin_pre_order(); (*node) != *tree.end_pre_order(); ++*node)
        {
            actual += to_string(*node->get_value()) + " ";
        }
        CHECK(expected == actual);
    }

    SUBCASE("PreOrder_Ternary")
    {
        Node<int> root_node = Node<int>(1);
        Tree<int, 3> tree; // Ternary tree that contains doubles.
        tree.add_root(&root_node);

        Node<int> n2 = Node<int>(2);
        Node<int> n3 = Node<int>(3);
        Node<int> n4 = Node<int>(4);
        Node<int> n5 = Node<int>(5);
        Node<int> n6 = Node<int>(6);
        Node<int> n7 = Node<int>(7);
        Node<int> n8 = Node<int>(8);
        Node<int> n9 = Node<int>(9);

        tree.add_sub_node(&root_node, &n2);
        tree.add_sub_node(&root_node, &n3);
        tree.add_sub_node(&root_node, &n4);
        tree.add_sub_node(&n2, &n5);
        tree.add_sub_node(&n2, &n6);
        tree.add_sub_node(&n3, &n7);
        tree.add_sub_node(&n3, &n8);
        tree.add_sub_node(&n4, &n9);

        // it uses DFS iterator
        string expected = "1 2 5 6 3 7 8 4 9 ";
        string actual = "";

        for (auto *node = tree.begin_pre_order(); (*node) != *tree.end_pre_order(); ++*node)
        {
            actual += to_string(*node->get_value()) + " ";
        }
        CHECK(expected == actual);
    }

    SUBCASE("PreOrder_QuadTree")
    {
        Node<int> root_node = Node<int>(1);
        Tree<int, 4> tree; // Quad tree that contains doubles.
        tree.add_root(&root_node);

        Node<int> n2 = Node<int>(2);
        Node<int> n3 = Node<int>(3);
        Node<int> n4 = Node<int>(4);
        Node<int> n5 = Node<int>(5);
        Node<int> n6 = Node<int>(6);
        Node<int> n7 = Node<int>(7);
        Node<int> n8 = Node<int>(8);
        Node<int> n9 = Node<int>(9);
        Node<int> n10 = Node<int>(10);
        Node<int> n11 = Node<int>(11);
        Node<int> n12 = Node<int>(12);
        Node<int> n13 = Node<int>(13);

        tree.add_sub_node(&root_node, &n2);
        tree.add_sub_node(&root_node, &n3);
        tree.add_sub_node(&root_node, &n4);
        tree.add_sub_node(&root_node, &n5);
        tree.add_sub_node(&n2, &n6);
        tree.add_sub_node(&n2, &n7);
        tree.add_sub_node(&n2, &n8);
        tree.add_sub_node(&n2, &n9);
        tree.add_sub_node(&n3, &n10);
        tree.add_sub_node(&n4, &n11);
        tree.add_sub_node(&n3, &n12);
        tree.add_sub_node(&n5, &n13);

        // it uses DFS iterator
        string expected = "1 2 6 7 8 9 3 10 12 4 11 5 13 ";
        string actual = "";

        for (auto *node = tree.begin_pre_order(); (*node) != *tree.end_pre_order(); ++*node)
        {
            actual += to_string(*node->get_value()) + " ";
        }
        CHECK(expected == actual);
    }

    SUBCASE("PreOrder_NULLRoot")
    {
        Tree<int> tree; // Binary tree that contains doubles.

        string expected = "";
        string actual = "";

        for (auto *node = tree.begin_pre_order(); (*node) != *tree.end_pre_order(); ++*node)
        {
            actual += to_string(*node->get_value()) + " ";
        }
        CHECK(expected == actual);
    }
}

TEST_CASE("PostOrder")
{
    SUBCASE("PostOrder_Binary")
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

        string expected = "4 5 2 3 1 ";
        string actual = "";

        for (auto *node = tree.begin_post_order(); (*node) != *tree.end_post_order(); ++*node)
        {
            actual += to_string(*node->get_value()) + " ";
        }
        CHECK(expected == actual);
    }

    SUBCASE("PostOrder_Ternary")
    {
        Node<int> root_node = Node<int>(1);
        Tree<int, 3> tree; // Ternary tree that contains doubles.
        tree.add_root(&root_node);

        Node<int> n2 = Node<int>(2);
        Node<int> n3 = Node<int>(3);
        Node<int> n4 = Node<int>(4);
        Node<int> n5 = Node<int>(5);
        Node<int> n6 = Node<int>(6);
        Node<int> n7 = Node<int>(7);
        Node<int> n8 = Node<int>(8);
        Node<int> n9 = Node<int>(9);

        tree.add_sub_node(&root_node, &n2);
        tree.add_sub_node(&root_node, &n3);
        tree.add_sub_node(&root_node, &n4);
        tree.add_sub_node(&n2, &n5);
        tree.add_sub_node(&n2, &n6);
        tree.add_sub_node(&n3, &n7);
        tree.add_sub_node(&n3, &n8);
        tree.add_sub_node(&n4, &n9);

        // it uses DFS iterator
        string expected = "1 2 5 6 3 7 8 4 9 ";
        string actual = "";

        for (auto *node = tree.begin_post_order(); (*node) != *tree.end_post_order(); ++*node)
        {
            actual += to_string(*node->get_value()) + " ";
        }
        CHECK(expected == actual);
    }

    SUBCASE("PostOrder_QuadTree")
    {
        Node<int> root_node = Node<int>(1);
        Tree<int, 4> tree; // Quad tree that contains doubles.
        tree.add_root(&root_node);

        Node<int> n2 = Node<int>(2);
        Node<int> n3 = Node<int>(3);
        Node<int> n4 = Node<int>(4);
        Node<int> n5 = Node<int>(5);
        Node<int> n6 = Node<int>(6);
        Node<int> n7 = Node<int>(7);
        Node<int> n8 = Node<int>(8);
        Node<int> n9 = Node<int>(9);
        Node<int> n10 = Node<int>(10);
        Node<int> n11 = Node<int>(11);
        Node<int> n12 = Node<int>(12);
        Node<int> n13 = Node<int>(13);

        tree.add_sub_node(&root_node, &n2);
        tree.add_sub_node(&root_node, &n3);
        tree.add_sub_node(&root_node, &n4);
        tree.add_sub_node(&root_node, &n5);
        tree.add_sub_node(&n2, &n6);
        tree.add_sub_node(&n2, &n7);
        tree.add_sub_node(&n2, &n8);
        tree.add_sub_node(&n2, &n9);
        tree.add_sub_node(&n3, &n10);
        tree.add_sub_node(&n4, &n11);
        tree.add_sub_node(&n3, &n12);
        tree.add_sub_node(&n5, &n13);

        // it uses DFS iterator
        string expected = "1 2 6 7 8 9 3 10 12 4 11 5 13 ";
        string actual = "";

        for (auto *node = tree.begin_post_order(); (*node) != *tree.end_post_order(); ++*node)
        {
            actual += to_string(*node->get_value()) + " ";
        }
        CHECK(expected == actual);
    }

    SUBCASE("PostOrder_NULLRoot")
    {
        Tree<int> tree; // Binary tree that contains doubles.

        string expected = "";
        string actual = "";

        for (auto *node = tree.begin_post_order(); (*node) != *tree.end_post_order(); ++*node)
        {
            actual += to_string(*node->get_value()) + " ";
        }
        CHECK(expected == actual);
    }
}

TEST_CASE("BFS")
{
    SUBCASE("BFS_Binary")
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

        string expected = "1 2 3 4 5 ";
        string actual = "";

        for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
        {
            actual += to_string(*node.get_value()) + " ";
        }

        CHECK(expected == actual);
    }

    SUBCASE("BFS_Ternary")
    {
        Node<int> root_node = Node<int>(1);
        Tree<int, 3> tree; // Ternary tree that contains doubles.
        tree.add_root(&root_node);

        Node<int> n2 = Node<int>(2);
        Node<int> n3 = Node<int>(3);
        Node<int> n4 = Node<int>(4);
        Node<int> n5 = Node<int>(5);
        Node<int> n6 = Node<int>(6);
        Node<int> n7 = Node<int>(7);
        Node<int> n8 = Node<int>(8);
        Node<int> n9 = Node<int>(9);

        tree.add_sub_node(&root_node, &n2);
        tree.add_sub_node(&root_node, &n3);
        tree.add_sub_node(&root_node, &n4);
        tree.add_sub_node(&n2, &n5);
        tree.add_sub_node(&n2, &n6);
        tree.add_sub_node(&n3, &n7);
        tree.add_sub_node(&n3, &n8);
        tree.add_sub_node(&n4, &n9);

        // it uses BFS iterator
        string expected = "1 2 3 4 5 6 7 8 9 ";
        string actual = "";

        for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
        {
            actual += to_string(*node.get_value()) + " ";
        }
        CHECK(expected == actual);
    }

    SUBCASE("BFS_QuadTree")
    {
        Node<int> root_node = Node<int>(1);
        Tree<int, 4> tree; // Quad tree that contains doubles.
        tree.add_root(&root_node);

        Node<int> n2 = Node<int>(2);
        Node<int> n3 = Node<int>(3);
        Node<int> n4 = Node<int>(4);
        Node<int> n5 = Node<int>(5);
        Node<int> n6 = Node<int>(6);
        Node<int> n7 = Node<int>(7);
        Node<int> n8 = Node<int>(8);
        Node<int> n9 = Node<int>(9);
        Node<int> n10 = Node<int>(10);
        Node<int> n11 = Node<int>(11);
        Node<int> n12 = Node<int>(12);
        Node<int> n13 = Node<int>(13);

        tree.add_sub_node(&root_node, &n2);
        tree.add_sub_node(&root_node, &n3);
        tree.add_sub_node(&root_node, &n4);
        tree.add_sub_node(&root_node, &n5);
        tree.add_sub_node(&n2, &n6);
        tree.add_sub_node(&n2, &n7);
        tree.add_sub_node(&n2, &n8);
        tree.add_sub_node(&n2, &n9);
        tree.add_sub_node(&n3, &n10);
        tree.add_sub_node(&n4, &n11);
        tree.add_sub_node(&n3, &n12);
        tree.add_sub_node(&n5, &n13);

        // it uses BFS iterator
        string expected = "1 2 3 4 5 6 7 8 9 10 12 11 13 ";
        string actual = "";

        for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
        {
            actual += to_string(*node.get_value()) + " ";
        }

        CHECK(expected == actual);
    }

    SUBCASE("BFS_NULLRoot")
    {
        Tree<int> tree; // Binary tree that contains doubles.

        string expected = "";
        string actual = "";

        for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
        {
            actual += to_string(*node.get_value()) + " ";
        }

        CHECK(expected == actual);
    }
}

TEST_CASE("DFS")
{
    SUBCASE("DFS_Binary")
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

        string expected = "1 2 4 5 3 ";
        string actual = "";
        for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
        {
            actual += to_string(*node.get_value()) + " ";
        }

        CHECK(expected == actual);
    }

    SUBCASE("DFS_Ternary")
    {
        Node<int> root_node = Node<int>(1);
        Tree<int, 3> tree; // Ternary tree that contains doubles.
        tree.add_root(&root_node);

        Node<int> n2 = Node<int>(2);
        Node<int> n3 = Node<int>(3);
        Node<int> n4 = Node<int>(4);
        Node<int> n5 = Node<int>(5);
        Node<int> n6 = Node<int>(6);
        Node<int> n7 = Node<int>(7);
        Node<int> n8 = Node<int>(8);
        Node<int> n9 = Node<int>(9);

        tree.add_sub_node(&root_node, &n2);
        tree.add_sub_node(&root_node, &n3);
        tree.add_sub_node(&root_node, &n4);
        tree.add_sub_node(&n2, &n5);
        tree.add_sub_node(&n2, &n6);
        tree.add_sub_node(&n3, &n7);
        tree.add_sub_node(&n3, &n8);
        tree.add_sub_node(&n4, &n9);

        // it uses DFS iterator
        string expected = "1 2 5 6 3 7 8 4 9 ";
        string actual = "";

        for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
        {
            actual += to_string(*node.get_value()) + " ";
        }
        CHECK(expected == actual);
    }

    SUBCASE("DFS_QuadTree")
    {
         Node<int> root_node = Node<int>(1);
        Tree<int, 4> tree; // Quad tree that contains doubles.
        tree.add_root(&root_node);

        Node<int> n2 = Node<int>(2);
        Node<int> n3 = Node<int>(3);
        Node<int> n4 = Node<int>(4);
        Node<int> n5 = Node<int>(5);
        Node<int> n6 = Node<int>(6);
        Node<int> n7 = Node<int>(7);
        Node<int> n8 = Node<int>(8);
        Node<int> n9 = Node<int>(9);
        Node<int> n10 = Node<int>(10);
        Node<int> n11 = Node<int>(11);
        Node<int> n12 = Node<int>(12);
        Node<int> n13 = Node<int>(13);

        tree.add_sub_node(&root_node, &n2);
        tree.add_sub_node(&root_node, &n3);
        tree.add_sub_node(&root_node, &n4);
        tree.add_sub_node(&root_node, &n5);
        tree.add_sub_node(&n2, &n6);
        tree.add_sub_node(&n2, &n7);
        tree.add_sub_node(&n2, &n8);
        tree.add_sub_node(&n2, &n9);
        tree.add_sub_node(&n3, &n10);
        tree.add_sub_node(&n4, &n11);
        tree.add_sub_node(&n3, &n12);
        tree.add_sub_node(&n5, &n13);

        // it uses DFS iterator
        string expected = "1 2 6 7 8 9 3 10 12 4 11 5 13 ";
        string actual = "";

        for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
        {
            actual += to_string(*node.get_value()) + " ";
        }
        CHECK(expected == actual);
    }
}