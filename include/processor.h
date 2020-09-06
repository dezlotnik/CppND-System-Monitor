#ifndef PROCESSOR_H
#define PROCESSOR_H

class Processor {
 public:
  float Utilization() const;  // TODO: See src/processor.cpp
  void Update();

  // TODO: Declare any necessary private members
 private:
 float active_time_ = 0.0;
 float total_time_ = 0.0;
 float prev_active_time_ = 0.0;
 float prev_total_time_ = 0.0;
};

#endif