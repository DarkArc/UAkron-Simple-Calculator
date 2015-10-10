#include <stdexcept>

inline Test::~Test() { }

template <typename T>
  void expect(const T& a, const T& b) {
    expect(a, b, std::string(a) + " is not equal to " + std::string(b) + "!");
  }

template <typename T>
  void expect(const T& a, const T& b, const std::string& err) {
    if (a != b) {
      throw std::logic_error(err);
    }
  }
