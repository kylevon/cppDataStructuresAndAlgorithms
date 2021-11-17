#ifndef dQueue_H
#define dQueue_H
#include <cassert>
#include <iostream>
class QNode {
public:
  QNode *left;
  QNode *right;
  int value;
  QNode(int value) : left{nullptr}, right{nullptr}, value{value} {}
  ~QNode() = default;
};

class DQueue {
private:
  QNode *head;
  QNode *tail;

public:
  DQueue() : head{nullptr}, tail{nullptr} {}
  void pushLeft(int value);
  void pushRight(int value);
  int popLeft();
  int popRight();
  void printQueue();
  friend std::ostream &operator<<(std::ostream &out, const DQueue &dqueue);
  ~DQueue();
};
#endif
