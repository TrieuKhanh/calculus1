// author: Vo, Tong
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

float calculate_integral(const float step) {
  // define x
  vector<double> x;
  // define function y
  vector<double> y;
  // define function value calculation
  auto y_value = [](float x_value) {
    return sqrt(1 + 1 / pow(x_value, 2) + 1 / pow(x_value + 1, 2));
  };
  // init x range from 1 to 2, and calculate y immediately
  float x_up = 1;
  size_t num = static_cast<size_t>(1 / step);
  x.reserve(num + 1);
  y.reserve(num + 1);
  float result = 0;
  while (x_up <= 2) {
    //    x.push_back(x_up);
    //    y.push_back(y_value(x_up));
    result += y_value(x_up);
    x_up = +step;
  }
  cout << "x was initialzed with " << x.size() << "element" << &endl;
  // now, calculate the integral
  //  for (auto y_ : y) {
  //    result += y_;
  //  }
  result *= step;
  return result;
}

int main() {
  cout << "Start!" << endl;
  float step = 0.1f;

  cout << "result of the integral calculated with x-distance of " << step << ":"
       << calculate_integral(step) << &endl;
  return 0;
}
