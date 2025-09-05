// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef SINGLETON_CREATIONAL_SIMPLE_FACTORY_SHAPE_SHAPE_H_
#define SINGLETON_CREATIONAL_SIMPLE_FACTORY_SHAPE_SHAPE_H_

#include <iostream>
#include <string>

class Shape {
 public:
  Shape(const std::string& name) : name_(name) {}
  ~Shape() {}

  virtual void Draw() = 0;
  virtual void Erase() = 0;

  std::string name() const { return name_; }

 private:
  std::string name_;
};

class Circle : public Shape {
 public:
  Circle() : Shape("Circle") { std::cout << "Create circle" << std::endl; }
  ~Circle() {}

  void Draw() override { std::cout << "Draw circle..." << std::endl; }
  void Erase() override { std::cout << "Erase circle..." << std::endl; }
};

class Square : public Shape {
 public:
  Square() : Shape("Square") { std::cout << "Create square" << std::endl; }
  ~Square() {}

  void Draw() override { std::cout << "Draw square..." << std::endl; }
  void Erase() override { std::cout << "Erase square..." << std::endl; }
};

class Triangle : public Shape {
 public:
  Triangle() : Shape("Triangle") {
    std::cout << "Create triangle" << std::endl;
  }
  ~Triangle() {}

  void Draw() override { std::cout << "Draw triangle..." << std::endl; }
  void Erase() override { std::cout << "Erase triangle..." << std::endl; }
};

#endif  // SINGLETON_CREATIONAL_SIMPLE_FACTORY_SHAPE_SHAPE_H_