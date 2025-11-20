// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#include <memory>
#include <string>

#include "award.h"

int main() {
  auto teacher = std::make_unique<Teacher>("Lucy", 20, 70);
  auto student = std::make_unique<Student>("Jack", 1, 94);

  CandidateList candidates;
  candidates.AddCandidate(std::move(teacher));
  candidates.AddCandidate(std::move(student));

  ResearchAward research_check;
  ExcellentAward excellent_check;

  candidates.Check(&research_check);
  candidates.Check(&excellent_check);

  return 0;
}