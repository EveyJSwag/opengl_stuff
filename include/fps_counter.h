#ifndef FPS_COUNTER_H
#define FPS_COUNTER_H

#include "font_renderer.h"
#include "font_info.h"

class fps_counter
{
public:
    static fps_counter* get_instance();
    void display_fps();

private:
    static fps_counter* fps_counter_instance;
    fps_counter();
    std::unique_ptr<font_renderer> fps_font;
    double current_time;
    std::stringstream fps_string_stream;
    unsigned int amount_of_frames_in_second;
    bool first_loop;

};

#endif /* FPS_COUNTER_H */