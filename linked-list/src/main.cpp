#include <iostream>
#include "queue.hpp"

int main(int argc, char **argv) {
  Queue<int> a;
  a.push(10);
  a.push(20);
  a.push(30);
  a.print();


  std::cout << a.unshift() << ", ";
  std::cout << a.unshift() << ", ";
  std::cout << a.unshift() << std::endl;






  return 0;
}