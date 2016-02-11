#include <future>
#include <iostream>

struct Foo
{
  Foo() : data(0) {}
  int sum(int i) { data += i; return data; }
  int data;
};

int main()
{
  Foo *foo = new Foo();
  auto f = std::async(&Foo::sum, foo, 42);
  foo->data = 7 + f.get();
  std::cout << foo->data << "\n";
}
