#include "sound_manager.h"
#include <sstream>
sound_manager* sound_manager::singleton = NULL;




sound_manager* sound_manager::get_instance()
{
    if (singleton)
        return singleton;
    else
        singleton = new sound_manager();

    return singleton;
}

sound_manager::sound_manager()
{

}

cpp_core_audio* sound_manager::get_from_sound_registry(std::string& sound_name)
{
    return sound_registry[sound_name];
}

void sound_manager::add_to_registry(std::string& wav_name, sound_type& type)
{
    std::string full_sound_path;
    std::stringstream full_sound_stream;
    float volume = 0.5f;
    bool can_loop = false;
    switch (type)
    {
        case MUSIC:
            can_loop = true;
            full_sound_stream << MUSIC_DIRECTORY << wav_name;
            break;
        case EFFECT:
            full_sound_stream << EFFECT_DIRECTORY << wav_name;
            break;
    }
    full_sound_path = full_sound_stream.str();

    sound_registry[wav_name] = new cpp_core_audio(full_sound_path, volume, can_loop);
}

void sound_manager::play_sound(std::string& wav_name)
{
    pthread_t thread_id;
    cpp_core_audio* arg = sound_registry[wav_name];
    pthread_create(&thread_id, NULL, &play_sound_thread, arg);
    pthread_detach(thread_id);
}

void* sound_manager::play_sound_thread(void* arg_ptr)
{
    cpp_core_audio* audio = (cpp_core_audio*)arg_ptr;
    audio->play();
    while (audio->is_playing())
    {

    }

    return (void*)0;
}
