#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H

#include "cpp_core_audio.h"
#include <vector>
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


    typedef struct create_args
    {
        float volume;
        bool  loopable;
        std::string full_path;

        create_args& operator= (const create_args& right)
        {
            volume = right.volume;
            loopable = right.loopable;
            full_path = right.full_path;
            return *this;
        }

        create_args (const create_args& copy)
        {
            volume = copy.volume;
            loopable = copy.loopable;
            full_path = copy.full_path;
        }

        create_args ()
        {
            volume = 0.0f;
            loopable = false;
            full_path ="";
        }
    } create_args;

    static sound_manager* get_instance();

    void add_to_registry(    
        std::string& wav_name,
        float& volume,
        bool& loopable, 
        sound_type& type);

    void play_sound(std::string& wav_name);

    create_args get_from_sound_registry(std::string& sound_name);

    const char** get_sound_names();

    int get_number_of_entries();

private:

    static void* play_sound_thread(void* arg_ptr);

    const int MAX_THREADS = 20;
    const std::string MUSIC_DIRECTORY  = "sound/music/";
    const std::string EFFECT_DIRECTORY = "sound/effects/";
    static sound_manager* singleton;
    sound_manager();

    std::map<std::string, create_args> sound_registry;
};

#endif