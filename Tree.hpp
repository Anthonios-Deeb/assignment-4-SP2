// anthoniosdb@gmail.com
// 3993
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
#include "HeapIterator.hpp"

#include <SFML/Graphics.hpp>
#include <cmath>

using namespace sf;
using namespace std;

template <typename T, int N = 2>
class Tree
{
public:
  Tree() : root(nullptr), numberOfNodes(0)
  {
  }

  Node<T> *get_root() const
  {
    return root;
  }

  size_t getNumberOfNodes() const
  {
    return this->numberOfNodes;
  }

  void add_root(Node<T> *new_root)
  {
    if (this->root == nullptr)
    {
      this->root = new_root;
      numberOfNodes++;
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
    numberOfNodes++;
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

  HeapIterator<T, N> begin_heap_scan()
  {
    if (N > 2)
    {
      return HeapIterator<T, N>();
    }
    return HeapIterator<T, N>(this);
  }

  HeapIterator<T, N> end_heap_scan()
  {
    return HeapIterator<T, N>();
  }

  // -------------------------------------
  int calculateTreeDepth(Node<T> *node) const
  {
    // Base case: if the node is null, return depth 0
    if (!node)
    {
      return 0;
    }

    int maxDepth = 0;
    // Recursively calculate the depth of each child node
    for (Node<T> *child : *node->get_children())
    {
      maxDepth = std::max(maxDepth, calculateTreeDepth(child));
    }

    // Return the maximum depth of the subtree plus one (for the current node)
    return maxDepth + 1;
  }

  int calculateMaxWidthAtLevel(Node<T> *node, int level) const
  {
    // Base case: if the node is null, return width 0
    if (!node)
    {
      return 0;
    }

    // If the current level is 1, this node contributes a width of 1
    if (level == 1)
    {
      return 1;
    }

    int width = 0;
    // Recursively calculate the width of each child node at the given level
    for (Node<T> *child : *node->get_children())
    {
      width += calculateMaxWidthAtLevel(child, level - 1);
    }

    // Return the total width at the given level
    return width;
  }

  float calculateSubtreeWidth(Node<T> *node, float horizontalSpacing) const
  {
    // If the node has no children, its subtree width is equal to the horizontal spacing
    if (node->get_children()->empty())
    {
      return horizontalSpacing;
    }

    float width = 0;
    // Recursively calculate the width of each child subtree
    for (Node<T> *child : *node->get_children())
    {
      width += calculateSubtreeWidth(child, horizontalSpacing);
    }
    return width;
  }

  void calculateNodePositions(Node<T> *node, float x, float y, float horizontalSpacing, float verticalSpacing, std::map<Node<T> *, sf::Vector2f> &positions) const
  {
    if (!node)
    {
      return;
    }

    // Calculate the total width of the subtree rooted at the current node
    float subtreeWidth = calculateSubtreeWidth(node, horizontalSpacing);
    float left = x - subtreeWidth / 2;
    float childX = left;

    // Store the position of the current node
    positions[node] = sf::Vector2f(x, y);

    // Recursively calculate the positions of the child nodes
    for (Node<T> *child : *node->get_children())
    {
      float childSubtreeWidth = calculateSubtreeWidth(child, horizontalSpacing);
      calculateNodePositions(child, childX + childSubtreeWidth / 2, y + verticalSpacing, horizontalSpacing, verticalSpacing, positions);
      childX += childSubtreeWidth;
    }
  }

  void drawNode(sf::RenderWindow &window, Node<T> *node, const std::map<Node<T> *, sf::Vector2f> &positions, sf::Font &font) const
  {
    if (!node)
    {
      return;
    }

    // Get the position of the current node
    sf::Vector2f pos = positions.at(node);

    // Draw the node as a circle
    sf::CircleShape shape(40);
    shape.setFillColor(sf::Color::Green);
    shape.setPosition(pos.x - shape.getRadius(), pos.y - shape.getRadius());
    window.draw(shape);

    // Draw the node's label
    sf::Text text;
    text.setFont(font);
    text.setString(node->nodeToString());
    text.setCharacterSize(20);

    // Adjust the text size to fit within the node
    while (text.getLocalBounds().width > shape.getRadius() * 2)
    {
      text.setCharacterSize(text.getCharacterSize() - 1);
    }

    text.setFillColor(sf::Color::Black);
    text.setPosition(pos.x - text.getLocalBounds().width / 2, pos.y - text.getLocalBounds().height / 2 - 10);
    window.draw(text);

    // Draw lines connecting the current node to its children
    for (Node<T> *child : *node->get_children())
    {
      sf::Vector2f childPos = positions.at(child);

      sf::Vertex line[] = {
          sf::Vertex(sf::Vector2f(pos.x, pos.y)),
          sf::Vertex(sf::Vector2f(childPos.x, childPos.y))};
      window.draw(line, 2, sf::Lines);

      // Recursively draw the child nodes
      drawNode(window, child, positions, font);
    }
  }

  void draw(sf::RenderWindow &window, sf::Font &font) const
  {
    if (root != nullptr)
    {
      std::map<Node<T> *, sf::Vector2f> positions;

      // Calculate the depth of the tree
      int treeDepth = calculateTreeDepth(root);
      int maxWidth = 0;
      // Calculate the maximum width at any level in the tree
      for (int i = 1; i <= treeDepth; ++i)
      {
        maxWidth = std::max(maxWidth, calculateMaxWidthAtLevel(root, i));
      }

      // Calculate the horizontal and vertical spacing between nodes
      float horizontalSpacing = std::max(200.0f, window.getSize().x / (float)maxWidth);
      float verticalSpacing = std::max(150.0f, window.getSize().y / (float)treeDepth);

      // Calculate the positions of all nodes
      calculateNodePositions(root, window.getSize().x / 2.0f, verticalSpacing, horizontalSpacing, verticalSpacing, positions);

      // Draw the nodes and edges
      drawNode(window, root, positions, font);
    }
  }

  friend std::ostream &operator<<(std::ostream &os, const Tree<T, N> &tree)
  {
    // Calculate the depth of the tree
    int treeDepth = tree.calculateTreeDepth(tree.root);
    int maxWidth = 0;
    // Calculate the maximum width at any level in the tree
    for (int i = 1; i <= treeDepth; ++i)
    {
      maxWidth = std::max(maxWidth, tree.calculateMaxWidthAtLevel(tree.root, i));
    }

    // Calculate the required window size dynamically
    int windowWidth = std::max(800, 200 * maxWidth);
    int windowHeight = std::max(600, 150 * treeDepth + 200);

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "SFML Tree Visualization");

    // Add zoom and scroll functionality
    sf::View view = window.getDefaultView();
    bool dragging = false;
    sf::Vector2i oldPos;

    // Load font
    sf::Font font;
    if (!font.loadFromFile("/usr/share/fonts/truetype/msttcorefonts/arial.ttf"))
    {
      std::cerr << "Error loading font from /usr/share/fonts/truetype/msttcorefonts/arial.ttf" << std::endl;
      return os;
    }

    // Attempt to set vertical sync only if supported
    try
    {
      window.setVerticalSyncEnabled(true);
    }
    catch (const std::exception &e)
    {
      std::cerr << "Vertical sync not supported: " << e.what() << std::endl;
    }

    // Main loop for the SFML window
    while (window.isOpen())
    {
      sf::Event event;
      while (window.pollEvent(event))
      {
        if (event.type == sf::Event::Closed)
          window.close();

        // Handle zoom
        if (event.type == sf::Event::MouseWheelScrolled)
        {
          if (event.mouseWheelScroll.delta > 0)
            view.zoom(0.9f);
          else
            view.zoom(1.1f);
        }

        // Handle dragging
        if (event.type == sf::Event::MouseButtonPressed)
        {
          if (event.mouseButton.button == sf::Mouse::Middle)
          {
            dragging = true;
            oldPos = sf::Mouse::getPosition(window);
          }
        }
        if (event.type == sf::Event::MouseButtonReleased)
        {
          if (event.mouseButton.button == sf::Mouse::Middle)
          {
            dragging = false;
          }
        }
        if (event.type == sf::Event::MouseMoved)
        {
          if (dragging)
          {
            sf::Vector2i newPos = sf::Mouse::getPosition(window);
            sf::Vector2f deltaPos(static_cast<float>(oldPos.x - newPos.x) * view.getSize().x / window.getSize().x,
                                  static_cast<float>(oldPos.y - newPos.y) * view.getSize().y / window.getSize().y);

            view.move(deltaPos);
            oldPos = newPos;
          }
        }
      }

      window.clear();
      window.setView(view);
      tree.draw(window, font);
      window.display();
    }

    return os;
  }

private:
  Node<T> *root;
  size_t numberOfNodes;
};
#endif // TREE_HPP