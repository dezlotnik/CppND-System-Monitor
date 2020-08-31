#include <string>

#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) { 
    int s, m, h;
    std::string s_string, m_string, h_string;

    h = seconds / 3600;
    int remaining_seconds = seconds % 3600;
    m = remaining_seconds / 60;
    s = remaining_seconds % 60;

    if (s < 10) {
        s_string = "0" + std::to_string(s);
    } else {
        s_string = std::to_string(s);
    }
    if (m < 10) {
        m_string = "0" + std::to_string(m);
    } else {
        m_string = std::to_string(m);
    }
    if (h < 10) {
        h_string = "0" + std::to_string(h);
    } else {
        h_string = std::to_string(h);
    }
    
    return h_string + ":" + m_string + ":" + s_string;
}