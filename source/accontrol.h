#ifndef ACCESS_CONTROL_H
#define ACCESS_CONTROL_H
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
#include <vector>
using std::vector;
// protected members
class Base_Acc {
public:
  void pub_mem(){};

protected:
  int prot_mem; // protected member
private:
  char priv_mem;
};
// all member accessible through access specifier
struct Pub_derv : public Base_Acc {
  // making acc from this obj to public member of base cl
  int f() { return prot_mem; }
};
struct Priv_derv : private Base_Acc {
  // making acc from this obj to private member of base cl
  int f1() const { return prot_mem; }
  // ok, but have no access to base cl private mem
};
class Sneaky : public Base_Acc {
  friend void clobber(Sneaky &);   // access sneaky prot member
  friend void clobber(Base_Acc &); // can't acc prot member of base_acc
private:
  int j;
};
void clobber(Sneaky &s) { s.j = s.prot_mem = 0; }
// member on derived clas
// only have an access to data or member in derived class not to base class
void clobber(Base_Acc &b) {
  // b.prot_mem=0; not accessible
}
// virtual dctor
// allow obj in the inheritance hierarchy to be dynamically allocated
class Quote_S {
public:
  // needed as virtual if this
  // obj pointing to a derived obj is deleted
  virtual ~Quote_S() = default; // dynamic binding for dctor
};
class Derived_Quote_S : public Quote_S {
private:
  double x_point;
};
// base classes and deleted copy control in the derived
class X_Point {
public:
  X_Point(const double &_val) : x(_val){};
  X_Point(const X_Point &) = delete;

private:
  double x;
};
class Y_Point : public X_Point {
  // no ctor
private:
  double y;
};
// move operation and inheritance
class Quote_Mv {
public:
  Quote_Mv() = default;                            // memberwise default init
  Quote_Mv(const Quote_Mv &) = default;            // memberwise cp
  Quote_Mv(Quote_Mv &&) = default;                 // memberwise cp
  Quote_Mv &operator=(const Quote_Mv &) = default; // copy assign
  Quote_Mv &operator=(Quote_Mv &&) = default;      // mv assign
  virtual ~Quote_Mv() = default;

private:
  double x_mv;
  double y_mv;
};
class Derived_Quote_Mv : public Quote_Mv {
  // ok this obj has cp and move operation
  // which is explicitly init
private:
  double center;
};
// defining derived cp or mv ctor
class F_Base {
public:
  F_Base() = default;
  F_Base(const double &_c) : x_or{_c} {};
  ~F_Base() {}

private:
  double x_or;
};
class Derived_F_Base : public F_Base {
public:
  Derived_F_Base(const int &_x) : x_point(_x) {}
  // cp the base member initializers for members Derived_F_Base
  Derived_F_Base(const Derived_F_Base &f, const int &_x)
      : F_Base(f), x_point(_x) {}
  // move the base member
  Derived_F_Base(Derived_F_Base &&f, const int &_x = 0) noexcept
      : F_Base{std::move(f)}, x_point(_x) {}
  // derived class assignment operator
  Derived_F_Base &operator=(const Derived_F_Base &f) {
    F_Base::operator=(f); // assign the base part
    return *this;
  }
  // dctor for derived class
  ~Derived_F_Base() {}

private:
  int x_point;
};
// no namespace
// consider to make a new namespace
//  container and inheritance
#endif
