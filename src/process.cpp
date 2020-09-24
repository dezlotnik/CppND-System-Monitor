#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>
#include <unistd.h>

#include "process.h"
#include "linux_parser.h"

using std::string;
using std::to_string;
using std::vector;

// TODO: Return this process's ID
int Process::Pid() const { return pid_; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() const {
    // https://stackoverflow.com/questions/16726779/how-do-i-get-the-total-cpu-usage-of-an-application-from-proc-pid-stat/16736599#16736599
    // float total_time = (float) LinuxParser::ActiveJiffies(Pid());
    // float seconds = UpTime();
    if (total_time_ > 0.0) {
        return active_time_ / total_time_;
    } else {
        return 0.0;
    }
}

void Process::Update() {
    active_time_ = LinuxParser::ActiveJiffies(Pid()) / sysconf(_SC_CLK_TCK);
    total_time_ = UpTime();
}

// TODO: Return the command that generated this process
string Process::Command() {
    return LinuxParser::Command(Pid());
}

// TODO: Return this process's memory utilization
string Process::Ram() { 
    return LinuxParser::Ram(Pid());
}

// TODO: Return the user (name) that generated this process
string Process::User() { 
    return LinuxParser::User(Pid());
}

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() const {
    return LinuxParser::UpTime(Pid());
}

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const { 
    // Use "<" so the output of sort in system.cpp is in decending order.
    return (CpuUtilization() > a.CpuUtilization());
}