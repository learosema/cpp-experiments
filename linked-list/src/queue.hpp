#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class Queue {

  public:
    Queue() {}

    ~Queue() {
      if (_val != nullptr) {
        delete _val;
        _val = nullptr;
      }
    }

    virtual Queue* getTail() {
      Queue *iter = _head;
      while (iter->_next != nullptr) {
        iter = iter->_next;
      }
      return iter;
    }

    virtual void push(T val) {
      Queue * tail = getTail();
      Queue * next = new Queue();
      tail->_next = next;
      next->_head = _head;
      next->_val = new T[1] {val};
    }

    virtual bool hasItems() {
      return (_head->_next != nullptr);
    }

    virtual T unshift() {
      Queue *first = _head->_next;
      if (!hasItems()) {
        throw new std::underflow_error("Queue is empty.");
      }
      T returnValue = first->_val[0];
      _head->_next = first->_next;
      delete first;
      return returnValue;
    }

    virtual void print() {
      for (Queue *iter = _head->_next; iter != nullptr; iter = iter->_next) {
        std::cout << iter->_val[0] << std::endl;
      }
    }

  private:
    Queue *_head = this;
    Queue *_next = nullptr;
    
    T * _val = nullptr;
};
