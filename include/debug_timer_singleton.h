#ifndef DEBUG_TIMER_SINGLETON
#define DEBUG_TIMER_SINGLETON
#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <sstream>
class debug_timer_singleton
{

public:
    static debug_timer_singleton* get_instance();
    void start_timer();
    void stop_timer(std::string event_name);
    long long get_time_difference();
    ~debug_timer_singleton();
private:
    const std::string debug_timer_file_name = "log/debug_timer_log.txt";
    std::ofstream debug_timer_file;
    static debug_timer_singleton* debug_timer_instance;
    debug_timer_singleton();
    std::chrono::steady_clock::time_point start_time;
    std::chrono::steady_clock::time_point stop_time;
    long long time_difference;
};

#endif