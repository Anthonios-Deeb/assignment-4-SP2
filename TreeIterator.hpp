// anthoniosdb@gmail.com
// 3993
#ifndef TREEITERATOR_HPP
#define TREEITERATOR_HPP

// this is an abstarct class that will be inherited by all the iterators
template <typename T, int N = 2>
class TreeIterator
{
public:
  virtual TreeIterator<T, N> &operator++() = 0;
  virtual ~TreeIterator() = default;
  virtual bool operator!=(const TreeIterator<T, N> &other) = 0;
  virtual T *get_value() = 0;
};

#endif // TREEITERATOR_HPP