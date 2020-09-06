#include "processor.h"
#include "linux_parser.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
    float active_jiffies = (float) LinuxParser::ActiveJiffies();
    float jiffies = (float) LinuxParser::Jiffies();
    //to do: change to utilization over a time period, rather than from boot
    return active_jiffies/jiffies;
}