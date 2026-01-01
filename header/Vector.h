#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cassert>

#define edl '\n'

template <class type>
class Vector
{
  type *arr{nullptr};
  int size{};
  int capacity{};

  void expand_capacity();

public:
  Vector(int sz = 0);
  Vector(const Vector<type> &other);
  Vector<type> &operator=(const Vector<type> &other);
  ~Vector();
  type &operator[](const int idx);
  // Return the number of items stored in the vector
  int get_size() const;
  // Return the value stored at the given index
  type get_value(int idx) const;
  // Return the value stored at the front of the vector
  type get_front() const;
  // Return the value stored at the back of the vector
  type get_back() const;
  // Check if the vector is empty or not
  bool is_empty() const;
  // Append the given value to the end of the vector
  void push_back(type val);
  // Delete the last item in the vector
  void pop_back();
  // Delete item at the given index
  type pop(int idx);
  // Remove all instances of value from the vector
  void remove(type val);
  // Set the given value at the given index
  void set_value(int idx, type val);
  // Print all the elements in the vector
  void print() const;
  // search for value and returns first index with that value, -1 if not found
  int find(type val) const;
  // Insert the given value at the given index
  void insert(int idx, type val);
  // rotate the last element to the front of the vector
  void right_rotate();
  // rotate the first element to the back of the vector
  void left_rotate();
  // rotate the last element to the front of the vector N times
  void right_rotate(int times);
  // search for value and it's index, but each time you find the value, you
  // shift it one step to the left
  int find_transposition(type val);
};
#endif