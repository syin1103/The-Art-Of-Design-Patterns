// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef BEHAVIORAL_COMMAND_CACULATOR_CACULATOR_H_
#define BEHAVIORAL_COMMAND_CACULATOR_CACULATOR_H_

class Caculator {
 public:
  Caculator(double curr_value = 0.0) : curr_value_(curr_value) {}
  ~Caculator() = default;

  double Add(double value) {
    curr_value_ += value;
    return curr_value_;
  }

  double Subtract(double value) {
    curr_value_ -= value;
    return curr_value_;
  }

  double value() const { return curr_value_; }
  void set_value(double value) { curr_value_ = value; }

 private:
  double curr_value_;
};

#endif  // BEHAVIORAL_COMMAND_CACULATOR_CACULATOR_H_