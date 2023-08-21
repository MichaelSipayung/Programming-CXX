#include "dynamic.h"
#include <iostream>
#include <memory>
#include <string>

void Refactor::init_pointer() {
  const std::string auth_name = "Miller";
  // shared ptr that can point to string
  const auto p1 = std::make_shared<std::string>();
  if (p1 && p1->empty())
    *p1 = auth_name; // dereference operator to access element
  std::cout << *p1;
}

void Refactor::copy_pointer()
{
    const auto x = std::make_shared<std::string>("Miller");
    const auto& y = x;
    if (y)
        std::cout << *y;
}
