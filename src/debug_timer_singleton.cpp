#include "debug_timer_singleton.h"
debug_timer_singleton* debug_timer_singleton::debug_timer_instance = nullptr;

debug_timer_singleton* debug_timer_singleton::get_instance()
{
    if (debug_timer_singleton::debug_timer_instance == nullptr)
    {
        debug_timer_instance = new debug_timer_singleton();
    }
    return debug_timer_instance;
}

void debug_timer_singleton::start_timer()
{
    start_time =  std::chrono::high_resolution_clock::now();
}

void debug_timer_singleton::stop_timer(std::string event_name)
{
    stop_time = std::chrono::high_resolution_clock::now();
    time_difference = (stop_time - start_time).count();
    debug_timer_file.open(debug_timer_file_name,std::ios::app);
    debug_timer_file << event_name << ": " << time_difference << "ns" << std::endl;
    debug_timer_file.close();
}
debug_timer_singleton::debug_timer_singleton()
{
    debug_timer_file.open(debug_timer_file_name);//, std::ios::app);
    debug_timer_file.close();
}

long long debug_timer_singleton::get_time_difference()
{
    return time_difference;
}
