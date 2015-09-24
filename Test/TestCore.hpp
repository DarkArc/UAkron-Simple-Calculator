#ifndef TESTCORE_HPP
#define TESTCORE_HPP

#include <string>

struct Test {
  virtual ~Test();
  virtual void complete() = 0;
};

template <typename T>
  void expect(const T&, const T&);

template <typename T>
  void expect(const T&, const T&, const std::string&);

#include "TestCore.ipp"

#endif
