#include <unistd.h>
#include <cstddef>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

#include "process.h"
#include "processor.h"
#include "system.h"
#include "linux_parser.h"

using std::set;
using std::size_t;
using std::string;
using std::vector;

// TODO: Return the system's CPU
Processor& System::Cpu() {
    cpu_.Update();
    return cpu_;
}

// TODO: Return a container composed of the system's processes
vector<Process>& System::Processes() { 
    vector<int> pids = LinuxParser::Pids();
    vector<Process> processes;
    for (int pid : pids) {
        Process process(pid);
        processes.push_back(pid);
    }
    processes_ = processes;
    std::sort(processes_.begin(),processes_.end());
    std::reverse(processes_.begin(),processes_.end());

    return processes_; 
}

// void System::RemoveInactivePids(const vector<int> &pids) {
//     vector<Process>::iterator it = processes_.begin();
//     while (it != processes_.end()) {
//         Process &p = *it;
//         if (active_pid_map_[p.Pid()]) {
//             p.Update();
//             ++it;
//         } else {
//             it = processes_.erase(it);
//         }
//     }
// }

// TODO: Return the system's kernel identifier (string)
std::string System::Kernel() {
    return LinuxParser::Kernel();
}

// TODO: Return the system's memory utilization
float System::MemoryUtilization() { 
    return LinuxParser::MemoryUtilization(); 
}

// TODO: Return the operating system name
std::string System::OperatingSystem() {
    return LinuxParser::OperatingSystem(); 
}

// TODO: Return the number of processes actively running on the system
int System::RunningProcesses() {
    return LinuxParser::RunningProcesses();
}

// TODO: Return the total number of processes on the system
int System::TotalProcesses() {
    return LinuxParser::TotalProcesses();
}

// TODO: Return the number of seconds since the system started running
long int System::UpTime() { 
    return LinuxParser::UpTime();
}