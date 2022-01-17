#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#include "cpp_core_audio.h"
#include <map>
#include <string>
#include <pthread.h>
class sound_manager
{

public:

    typedef enum sound_type
    {
        MUSIC,
        EFFECT
    } sound_type;

    static sound_manager* get_instance();

    void add_to_registry(std::string& wav_name, sound_type& type);

    void play_sound(std::string& wav_name);

    cpp_core_audio* get_from_sound_registry(std::string& sound_name);

private:

    typedef struct instance_name_struct
    {
        void* instance;
        std::string wav_name;
    } instance_name_struct;

    static void* play_sound_thread(void* arg_ptr);

    const int MAX_THREADS = 20;
    const std::string MUSIC_DIRECTORY  = "sound/music/";
    const std::string EFFECT_DIRECTORY = "sound/effects/";
    static sound_manager* singleton;
    sound_manager();

    std::map<std::string, cpp_core_audio*> sound_registry;
    //std::map<pthread_t, cpp_core_audio> thread_registry;
};

#endif