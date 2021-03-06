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
    return cpu_;
}

void System::Update() {
    cpu_.Update();

    active_pids_ = LinuxParser::Pids();
    RemoveInactiveProcesses();
    AddNewProcesses();
    for (Process &p : processes_) {
        p.Update();
    }
    std::sort(processes_.begin(),processes_.end());
}

// TODO: Return a container composed of the system's processes
vector<Process>& System::Processes() { 
    return processes_; 
}

void System::RemoveInactiveProcesses() {
    vector<Process>::iterator it = processes_.begin();
    while (it != processes_.end()) {
        Process &p = *it;
        if (active_pids_.find(p.Pid()) != active_pids_.end()) {
            ++it;
        } else {
            it = processes_.erase(it);
        }
    }
}

void System::AddNewProcesses() {
    for (int pid : active_pids_) {
        auto it = std::find_if(processes_.begin(),processes_.end(),[&pid](const Process &p) { return p.Pid() == pid; });
        if (it == processes_.end()) {
            processes_.push_back(Process(pid));
        }
    }
}

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