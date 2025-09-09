// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef CREATIONAL_ABSTRACT_FACTORY_GAME_CONTROLLER_H_
#define CREATIONAL_ABSTRACT_FACTORY_GAME_CONTROLLER_H_

class InterfaceController {
 public:
  virtual void Render() = 0;
};

class OperationController {
 public:
  virtual void Process() = 0;
};

#endif  // CREATIONAL_ABSTRACT_FACTORY_GAME_CONTROLLER_H_