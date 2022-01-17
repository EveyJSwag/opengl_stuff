#ifndef CPP_CORE_AUDIO_H
#define CPP_CORE_AUDIO_H

#include <string>
#include <vector>

class cpp_core_audio
{
public:
    cpp_core_audio(std::string& wav_file, float& a_volume, bool a_can_loop);
    double get_current_time();

    void play();
    void stop();
    void pause();
    void resume();

    void set_volume(float volume_value);
    void set_can_loop(bool can_loop_value);
    float get_volume();
    double get_play_time();
    bool is_playing();
private:
    float volume;
    bool  can_loop;
    void* objc_object;
};

#endif
