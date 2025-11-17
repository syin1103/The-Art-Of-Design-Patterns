// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include "scene.h"

int main() {
  GameScene scene("Beijing Scene");
  SceneManager manager;

  scene.Play();
  manager.QuickSave(scene);

  scene.set_state("Shanghai Scene");
  scene.Play();

  manager.QuickLoad(scene);
  scene.Play();

  return 0;
}