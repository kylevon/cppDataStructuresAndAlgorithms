#ifndef dQueue_H
#define dQueue_H
#include <cassert>
#include <iostream>

class Deque {
protected:
  class Node {
  public:
    Node *left;
    Node *right;
    int value;
    Node(int value) : left{nullptr}, right{nullptr}, value{value} {}
    ~Node() = default;
  };

private:
  Deque::Node *head;
  Deque::Node *tail;

public:
  Deque() : head{nullptr}, tail{nullptr} {}
  void pushLeft(int value);
  void pushRight(int value);
  int popLeft();
  int popRight();
  bool contains(int value);
  void printQueue();
  friend std::ostream &operator<<(std::ostream &out, const Deque &dqueue);
  ~Deque();
};
#endif
