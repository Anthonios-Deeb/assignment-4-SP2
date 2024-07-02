// anthoniosdb@gmail.com
// 3993
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Tree.hpp"
#include "Node.hpp"
#include "Complex.hpp"

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

        for (auto *it = tree.begin_in_order(); (*it) != *tree.end_in_order(); ++*it)
        {
            actual += to_string(*it->get_value()) + " ";
        }
        CHECK(expected == actual);
    }

    SUBCASE("InOrder_Complex_Binary")
    {
        Node<Complex> root_node = Node<Complex>(Complex(10, 10));
        Tree<Complex> tree; // Binary tree that contains doubles.
        tree.add_root(&root_node);

        Node<Complex> n_1 = Node<Complex>(Complex(9, 9));
        Node<Complex> n_2 = Node<Complex>(Complex(5, 5));
        Node<Complex> n_3 = Node<Complex>(Complex(4, 4));
        Node<Complex> n_4 = Node<Complex>(Complex(6, 6));
        Node<Complex> n_5 = Node<Complex>(Complex(3, 3));
        Node<Complex> n_6 = Node<Complex>(Complex(7, 7));
        Node<Complex> n_7 = Node<Complex>(Complex(8, 8));
        Node<Complex> n_8 = Node<Complex>(Complex(2, 2));
        Node<Complex> n_9 = Node<Complex>(Complex(1, 1));
        Node<Complex> n_10 = Node<Complex>(Complex(11, 11));

        tree.add_sub_node(&root_node, &n_1);
        tree.add_sub_node(&root_node, &n_2);
        tree.add_sub_node(&n_1, &n_3);
        tree.add_sub_node(&n_1, &n_4);
        tree.add_sub_node(&n_2, &n_5);
        tree.add_sub_node(&n_3, &n_6);
        tree.add_sub_node(&n_3, &n_7);
        tree.add_sub_node(&n_4, &n_8);
        tree.add_sub_node(&n_2, &n_9);
        tree.add_sub_node(&n_4, &n_10);

        // print in order
        vector<Node<Complex> *> expected = {&n_6, &n_3, &n_7, &n_1, &n_8, &n_4, &n_10, &root_node, &n_5, &n_2, &n_9};
        vector<Complex *> actual;

        for (auto *it = tree.begin_in_order(); (*it) != *tree.end_in_order(); ++*it)
        {
            actual.push_back((*it).get_value());
        }

        for (size_t i = 0; i < expected.size(); i++)
        {
            CHECK(*(expected[i]->getValue()) == *actual[i]);
        }
    }

    SUBCASE("InOrder String Binary")
    {
        Node<string> root_node = Node<string>("5");
        Tree<string> tree; // Binary tree that contains doubles.
        tree.add_root(&root_node);

        Node<string> n2 = Node<string>("6");
        Node<string> n3 = Node<string>("8");
        Node<string> n4 = Node<string>("4");
        Node<string> n5 = Node<string>("1");
        Node<string> n6 = Node<string>("2");
        Node<string> n7 = Node<string>("7");
        Node<string> n8 = Node<string>("3");

        tree.add_sub_node(&root_node, &n2);
        tree.add_sub_node(&root_node, &n3);
        tree.add_sub_node(&n2, &n4);
        tree.add_sub_node(&n2, &n5);
        tree.add_sub_node(&n3, &n6);
        tree.add_sub_node(&n3, &n7);
        tree.add_sub_node(&n4, &n8);

        string expected = "3 4 6 1 5 2 8 7 ";
        string actual = "";

        for (auto *it = tree.begin_in_order(); (*it) != *tree.end_in_order(); ++*it)
        {
            actual += *it->get_value() + " ";
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

        for (auto *it = tree.begin_in_order(); (*it) != *tree.end_in_order(); ++*it)
        {
            actual += to_string(*it->get_value()) + " ";
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

        for (auto *it = tree.begin_in_order(); (*it) != *tree.end_in_order(); ++*it)
        {
            actual += to_string(*it->get_value()) + " ";
        }
        CHECK(expected == actual);
    }

    SUBCASE("InOrder_Complex_QuadTree")
    {
        Node<Complex> root_node = Node<Complex>(Complex(10, 10));
        Tree<Complex, 4> tree; // Quad tree that contains doubles.
        tree.add_root(&root_node);

        Node<Complex> n_1 = Node<Complex>(Complex(9, 9));
        Node<Complex> n_2 = Node<Complex>(Complex(5, 5));
        Node<Complex> n_3 = Node<Complex>(Complex(4, 4));
        Node<Complex> n_4 = Node<Complex>(Complex(6, 6));
        Node<Complex> n_5 = Node<Complex>(Complex(3, 3));
        Node<Complex> n_6 = Node<Complex>(Complex(7, 7));
        Node<Complex> n_7 = Node<Complex>(Complex(8, 8));
        Node<Complex> n_8 = Node<Complex>(Complex(2, 2));
        Node<Complex> n_9 = Node<Complex>(Complex(1, 1));
        Node<Complex> n_10 = Node<Complex>(Complex(11, 11));

        tree.add_sub_node(&root_node, &n_1);
        tree.add_sub_node(&root_node, &n_2);
        tree.add_sub_node(&root_node, &n_3);
        tree.add_sub_node(&root_node, &n_4);
        tree.add_sub_node(&n_1, &n_5);
        tree.add_sub_node(&n_1, &n_6);
        tree.add_sub_node(&n_2, &n_7);
        tree.add_sub_node(&n_2, &n_8);
        tree.add_sub_node(&n_2, &n_9);
        tree.add_sub_node(&n_4, &n_10);

        // print in order
        vector<Node<Complex> *> expected = {&root_node, &n_1, &n_5, &n_6, &n_2, &n_7, &n_8, &n_9, &n_3, &n_4, &n_10};
        vector<Complex *> actual;

        for (auto *it = tree.begin_in_order(); (*it) != *tree.end_in_order(); ++*it)
        {
            actual.push_back((*it).get_value());
        }

        for (size_t i = 0; i < expected.size(); i++)
        {
            CHECK(*(expected[i]->getValue()) == *actual[i]);
        }
    }

    SUBCASE("InOrder_NULLRoot")
    {
        Tree<int> tree; // Binary tree that contains doubles.

        string expected = "";
        string actual = "";

        for (auto *it = tree.begin_in_order(); (*it) != *tree.end_in_order(); ++*it)
        {
            actual += to_string(*it->get_value()) + " ";
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

        for (auto *it = tree.begin_pre_order(); (*it) != *tree.end_pre_order(); ++*it)
        {
            actual += to_string(*it->get_value()) + " ";
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

        for (auto *it = tree.begin_pre_order(); (*it) != *tree.end_pre_order(); ++*it)
        {
            actual += to_string(*it->get_value()) + " ";
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

        for (auto *it = tree.begin_pre_order(); (*it) != *tree.end_pre_order(); ++*it)
        {
            actual += to_string(*it->get_value()) + " ";
        }
        CHECK(expected == actual);
    }

    SUBCASE("Preorder_Complex_Binary")
    {
        Node<Complex> root_node = Node<Complex>(Complex(10, 10));
        Tree<Complex> tree; // Binary tree that contains doubles.
        tree.add_root(&root_node);

        Node<Complex> n_1 = Node<Complex>(Complex(9, 9));
        Node<Complex> n_2 = Node<Complex>(Complex(5, 5));
        Node<Complex> n_3 = Node<Complex>(Complex(4, 4));
        Node<Complex> n_4 = Node<Complex>(Complex(6, 6));
        Node<Complex> n_5 = Node<Complex>(Complex(3, 3));
        Node<Complex> n_6 = Node<Complex>(Complex(7, 7));
        Node<Complex> n_7 = Node<Complex>(Complex(8, 8));
        Node<Complex> n_8 = Node<Complex>(Complex(2, 2));
        Node<Complex> n_9 = Node<Complex>(Complex(1, 1));
        Node<Complex> n_10 = Node<Complex>(Complex(11, 11));

        tree.add_sub_node(&root_node, &n_1);
        tree.add_sub_node(&root_node, &n_2);
        tree.add_sub_node(&n_1, &n_3);
        tree.add_sub_node(&n_1, &n_4);
        tree.add_sub_node(&n_2, &n_5);
        tree.add_sub_node(&n_3, &n_6);
        tree.add_sub_node(&n_3, &n_7);
        tree.add_sub_node(&n_4, &n_8);
        tree.add_sub_node(&n_2, &n_9);
        tree.add_sub_node(&n_4, &n_10);

        // pre order
        vector<Node<Complex> *> expected = {&root_node, &n_1, &n_3, &n_6, &n_7, &n_4, &n_8, &n_10, &n_2, &n_5, &n_9};
        vector<Complex *> actual;

        for (auto *it = tree.begin_pre_order(); (*it) != *tree.end_pre_order(); ++*it)
        {
            actual.push_back((*it).get_value());
        }

        for (size_t i = 0; i < expected.size(); i++)
        {
            CHECK(*(expected[i]->getValue()) == *actual[i]);
        }
    }

    SUBCASE("PreOrder String Binary")
    {
        Node<string> root_node = Node<string>("5");
        Tree<string> tree; // Binary tree that contains doubles.
        tree.add_root(&root_node);

        Node<string> n2 = Node<string>("6");
        Node<string> n3 = Node<string>("8");
        Node<string> n4 = Node<string>("4");
        Node<string> n5 = Node<string>("1");
        Node<string> n6 = Node<string>("2");
        Node<string> n7 = Node<string>("7");
        Node<string> n8 = Node<string>("3");

        tree.add_sub_node(&root_node, &n2);
        tree.add_sub_node(&root_node, &n3);
        tree.add_sub_node(&n2, &n4);
        tree.add_sub_node(&n2, &n5);
        tree.add_sub_node(&n3, &n6);
        tree.add_sub_node(&n3, &n7);
        tree.add_sub_node(&n4, &n8);

        // pre order
        string expected = "5 6 4 3 1 8 2 7 ";
        string actual = "";

        for (auto *it = tree.begin_pre_order(); (*it) != *tree.end_pre_order(); ++*it)
        {
            actual += *it->get_value() + " ";
        }

        CHECK(expected == actual);
    }

    SUBCASE("PreOrder_NULLRoot")
    {
        Tree<int> tree; // Binary tree that contains doubles.

        string expected = "";
        string actual = "";

        for (auto *it = tree.begin_pre_order(); (*it) != *tree.end_pre_order(); ++*it)
        {
            actual += to_string(*it->get_value()) + " ";
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

        for (auto *it = tree.begin_post_order(); (*it) != *tree.end_post_order(); ++*it)
        {
            actual += to_string(*it->get_value()) + " ";
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

        for (auto *it = tree.begin_post_order(); (*it) != *tree.end_post_order(); ++*it)
        {
            actual += to_string(*it->get_value()) + " ";
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

        for (auto *it = tree.begin_post_order(); (*it) != *tree.end_post_order(); ++*it)
        {
            actual += to_string(*it->get_value()) + " ";
        }
        CHECK(expected == actual);
    }

    SUBCASE("PostOrder_NULLRoot")
    {
        Tree<int> tree; // Binary tree that contains doubles.

        string expected = "";
        string actual = "";

        for (auto *it = tree.begin_post_order(); (*it) != *tree.end_post_order(); ++*it)
        {
            actual += to_string(*it->get_value()) + " ";
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

        for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it)
        {
            actual += to_string(*it.get_value()) + " ";
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

        for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it)
        {
            actual += to_string(*it.get_value()) + " ";
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

        for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it)
        {
            actual += to_string(*it.get_value()) + " ";
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

        for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it)
        {
            actual += to_string(*it.get_value()) + " ";
        }

        CHECK(expected == actual);
    }

    SUBCASE("BFS_Complex_Binary")
    {
        Node<Complex> root_node = Node<Complex>(Complex(10, 10));
        Tree<Complex> tree; // Binary tree that contains doubles.
        tree.add_root(&root_node);

        Node<Complex> n_1 = Node<Complex>(Complex(9, 9));
        Node<Complex> n_2 = Node<Complex>(Complex(5, 5));
        Node<Complex> n_3 = Node<Complex>(Complex(4, 4));
        Node<Complex> n_4 = Node<Complex>(Complex(6, 6));
        Node<Complex> n_5 = Node<Complex>(Complex(3, 3));
        Node<Complex> n_6 = Node<Complex>(Complex(7, 7));
        Node<Complex> n_7 = Node<Complex>(Complex(8, 8));
        Node<Complex> n_8 = Node<Complex>(Complex(2, 2));
        Node<Complex> n_9 = Node<Complex>(Complex(1, 1));
        Node<Complex> n_10 = Node<Complex>(Complex(11, 11));

        tree.add_sub_node(&root_node, &n_1);
        tree.add_sub_node(&root_node, &n_2);
        tree.add_sub_node(&n_1, &n_3);
        tree.add_sub_node(&n_1, &n_4);
        tree.add_sub_node(&n_2, &n_5);
        tree.add_sub_node(&n_3, &n_6);
        tree.add_sub_node(&n_3, &n_7);
        tree.add_sub_node(&n_4, &n_8);
        tree.add_sub_node(&n_2, &n_9);
        tree.add_sub_node(&n_4, &n_10);

        // bfs
        vector<Node<Complex> *> expected = {&root_node, &n_1, &n_2, &n_3, &n_4, &n_5, &n_9, &n_6, &n_7, &n_8, &n_10};
        vector<Complex *> actual;

        for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it)
        {
            actual.push_back(it.get_value());
        }

        for (size_t i = 0; i < expected.size(); i++)
        {
            CHECK(*(expected[i]->getValue()) == *actual[i]);
        }
    }

    SUBCASE("BFS String Binary")
    {
        Node<string> root_node = Node<string>("5");
        Tree<string> tree; // Binary tree that contains doubles.
        tree.add_root(&root_node);

        Node<string> n2 = Node<string>("6");
        Node<string> n3 = Node<string>("8");
        Node<string> n4 = Node<string>("4");
        Node<string> n5 = Node<string>("1");
        Node<string> n6 = Node<string>("2");
        Node<string> n7 = Node<string>("7");
        Node<string> n8 = Node<string>("3");

        tree.add_sub_node(&root_node, &n2);
        tree.add_sub_node(&root_node, &n3);
        tree.add_sub_node(&n2, &n4);
        tree.add_sub_node(&n2, &n5);
        tree.add_sub_node(&n3, &n6);
        tree.add_sub_node(&n3, &n7);
        tree.add_sub_node(&n4, &n8);

        // bfs
        string expected = "5 6 8 4 1 2 7 3 ";
        string actual = "";

        for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it)
        {
            actual += *it.get_value() + " ";
        }

        CHECK(expected == actual);
    }

    SUBCASE("BFS_NULLRoot")
    {
        Tree<int> tree; // Binary tree that contains doubles.

        string expected = "";
        string actual = "";

        for (auto it = tree.begin_bfs_scan(); it != tree.end_bfs_scan(); ++it)
        {
            actual += to_string(*it.get_value()) + " ";
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
        for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it)
        {
            actual += to_string(*it.get_value()) + " ";
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

        for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it)
        {
            actual += to_string(*it.get_value()) + " ";
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

        for (auto it = tree.begin_dfs_scan(); it != tree.end_dfs_scan(); ++it)
        {
            actual += to_string(*it.get_value()) + " ";
        }
        CHECK(expected == actual);
    }
}

TEST_CASE("Heap")
{
    SUBCASE("int_HeapIterator")
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

        for (auto it = tree.begin_heap_scan(); it != tree.end_heap_scan(); ++it)
        {
            actual += to_string(*it.get_value()) + " ";
        }

        CHECK(expected == actual);
    }

    SUBCASE("string_HeapIterator")
    {
        Node<string> root_node = Node<string>("5");
        Tree<string> tree; // Binary tree that contains doubles.
        tree.add_root(&root_node);

        Node<string> n2 = Node<string>("6");
        Node<string> n3 = Node<string>("8");
        Node<string> n4 = Node<string>("4");
        Node<string> n5 = Node<string>("1");
        Node<string> n6 = Node<string>("2");
        Node<string> n7 = Node<string>("7");
        Node<string> n8 = Node<string>("3");

        tree.add_sub_node(&root_node, &n2);
        tree.add_sub_node(&root_node, &n3);
        tree.add_sub_node(&n2, &n4);
        tree.add_sub_node(&n2, &n5);
        tree.add_sub_node(&n3, &n6);
        tree.add_sub_node(&n3, &n7);
        tree.add_sub_node(&n4, &n8);

        string expected = "1 2 3 4 5 6 7 8 ";
        string actual = "";

        for (auto it = tree.begin_heap_scan(); it != tree.end_heap_scan(); ++it)
        {
            actual += *it.get_value() + " ";
        }

        CHECK(expected == actual);
    }

    SUBCASE("complex_HeapIterator")
    {
        Node<Complex> root_node = Node<Complex>(Complex(10, 10));
        Tree<Complex> tree; // Binary tree that contains doubles.
        tree.add_root(&root_node);

        Node<Complex> n_1 = Node<Complex>(Complex(9, 9));
        Node<Complex> n_2 = Node<Complex>(Complex(5, 5));
        Node<Complex> n_3 = Node<Complex>(Complex(4, 4));
        Node<Complex> n_4 = Node<Complex>(Complex(6, 6));
        Node<Complex> n_5 = Node<Complex>(Complex(3, 3));
        Node<Complex> n_6 = Node<Complex>(Complex(7, 7));
        Node<Complex> n_7 = Node<Complex>(Complex(8, 8));
        Node<Complex> n_8 = Node<Complex>(Complex(2, 2));
        Node<Complex> n_9 = Node<Complex>(Complex(1, 1));
        Node<Complex> n_10 = Node<Complex>(Complex(11, 11));

        tree.add_sub_node(&root_node, &n_1);
        tree.add_sub_node(&root_node, &n_2);
        tree.add_sub_node(&n_1, &n_3);
        tree.add_sub_node(&n_1, &n_4);
        tree.add_sub_node(&n_2, &n_5);
        tree.add_sub_node(&n_3, &n_6);
        tree.add_sub_node(&n_3, &n_7);
        tree.add_sub_node(&n_4, &n_8);
        tree.add_sub_node(&n_2, &n_9);
        tree.add_sub_node(&n_4, &n_10);

        vector<Node<Complex> *> expected = {&n_9, &n_8, &n_5, &n_3, &n_2, &n_4, &n_6, &n_7, &n_1, &root_node, &n_10};
        vector<Complex> actual;

        for (auto it = tree.begin_heap_scan(); it != tree.end_heap_scan(); ++it)
        {
            actual.push_back(*it.get_value());
        }

        for (size_t i = 0; i < expected.size(); i++)
        {
            CHECK(*(expected[i]->getValue()) == actual[i]);
        }
    }
}