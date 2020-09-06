#include "processor.h"
#include "linux_parser.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() const {
    //https://stackoverflow.com/questions/23367857/accurate-calculation-of-cpu-usage-given-in-percentage-in-linux
    float delta_active = active_time_ - prev_active_time_;
    float delta_total = total_time_ - prev_total_time_;
    
    if (delta_total > 0.0) {
        return delta_active/delta_total;
    } else {
        return 0.0;
    }
}

void Processor::Update() {
    prev_active_time_ = active_time_;
    prev_total_time_ = total_time_;
    active_time_ = (float) LinuxParser::ActiveJiffies();
    total_time_ = (float) LinuxParser::Jiffies();
}