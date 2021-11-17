#include "dQueueTests.h"
namespace Sequential {
void unitTests() {
  DQueue *myQueue = new DQueue{};
  for (int i = 0; i < 50; i++)
    myQueue->pushLeft(i);
  for (int i = 49; i >= 0; i--)
    assert(myQueue->popLeft() == i && "pushLeft and popLeft not working");
  for (int i = 0; i < 50; i++)
    myQueue->pushRight(i);
  for (int i = 49; i >= 0; i--) {
    assert(myQueue->popRight() == i && "pushRight and popRight not working");
  }
  for (int i = 0; i < 50; i++)
    myQueue->pushLeft(i);
  for (int i = 0; i < 50; i++) {
    assert(myQueue->popRight() == i && "pushLeft and popRight not working");
  }
  for (int i = 0; i < 50; i++)
    myQueue->pushRight(i);
  for (int i = 0; i < 50; i++) {
    assert(myQueue->popLeft() == i && "pushRight and popLeft not working");
  }
  delete myQueue;
}
} // namespace Sequential
