// Copyright(c) 2025 syin1103.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)

#ifndef BEHAVIORAL_VISITOR_AWARD_AWARD_H_
#define BEHAVIORAL_VISITOR_AWARD_AWARD_H_

#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Teacher;
class Student;

class AwardCheck {
 public:
  virtual ~AwardCheck() {}
  virtual void Check(Teacher* teacher) = 0;
  virtual void Check(Student* student) = 0;
};

class Candidate {
 public:
  virtual ~Candidate() {}
  virtual void Check(AwardCheck* award_check) = 0;
};

class Teacher : public Candidate {
 public:
  Teacher(const std::string& name, int papers, int scores)
      : name_(name), papers_(papers), scores_(scores) {}

  void Check(AwardCheck* award_check) override { award_check->Check(this); }

  std::string name() const { return name_; }
  int papers() const { return papers_; }
  int scores() const { return scores_; }

 private:
  std::string name_;
  int papers_;
  int scores_;
};

class Student : public Candidate {
 public:
  Student(const std::string& name, int papers, int scores)
      : name_(name), papers_(papers), average_scores_(scores) {}

  void Check(AwardCheck* award_check) override { award_check->Check(this); }

  std::string name() const { return name_; }
  int papers() const { return papers_; }
  int average_scores() const { return average_scores_; }

 private:
  std::string name_;
  int papers_;
  int average_scores_;
};

class ResearchAward : public AwardCheck {
 public:
  void Check(Teacher* teacher) override {
    if (teacher->papers() >= 10) {
      std::cout << "Research Award: " << teacher->name() << std::endl;
    }
  }

  void Check(Student* student) override {
    if (student->papers() >= 2) {
      std::cout << "Research Award: " << student->name() << std::endl;
    }
  }
};

class ExcellentAward : public AwardCheck {
 public:
  void Check(Teacher* teacher) override {
    if (teacher->scores() >= 90) {
      std::cout << "Excellent Award: " << teacher->name() << std::endl;
    }
  }

  void Check(Student* student) override {
    if (student->average_scores() >= 90) {
      std::cout << "Excellent Award: " << student->name() << std::endl;
    }
  }
};

class CandidateList {
 public:
  void AddCandidate(std::unique_ptr<Candidate> candidate) {
    candidates_.emplace_back(std::move(candidate));
  }

  void Check(AwardCheck* award_check) {
    for (const auto& candidate : candidates_) {
      candidate->Check(award_check);
    }
  }

 private:
  std::vector<std::unique_ptr<Candidate>> candidates_;
};

#endif  // BEHAVIORAL_VISITOR_AWARD_AWARD_H_