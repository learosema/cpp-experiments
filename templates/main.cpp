#include <iostream>
#include <string>

template <typename T>
T add(T a, T b) {
  return a + b;
}

template <class T>
T sub(T a, T b) {
  return a - b;
}

template <typename T>
class Tuple {
  public:
    Tuple(T a, T b) : m_a(a), m_b(b) {}

    T getA() const { return m_a; }
    T getB() const { return m_b; }

    void print() {
      std::cout << m_a << " | " << m_b << std::endl;
    }

  private:
    T m_a;
    T m_b;
};


template <typename T = float>
struct MyContainer {
  T val;
  MyContainer() : val() {}
  MyContainer(T val) : val(val) {}
};



int main(int, char**) {
    int a = 1;
    int b = 2;
    int c = add<int>(a, b);
    double d = 1.5;
    double e = 2.5;
    double f = add<double>(d, e);
    float  g = add(1.5f, 3.5f);
    Tuple<std::string> duo("hallo", "welt");
    Tuple<int> zahlenpaar {2, 3};
    zahlenpaar.print();
    duo.print();
    std::cout << "Hello !!!! " << add<int>(a, b) << std::endl;

    MyContainer c1 {1}; // OK MyContainer<int>
    MyContainer c2; // OK MyContainer<float>
}
