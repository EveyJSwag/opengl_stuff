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

sound_manager::sound_manager(){}

sound_manager::create_args sound_manager::get_from_sound_registry(std::string& sound_name)
{
    return sound_registry[sound_name];
}

void sound_manager::add_to_registry(
    std::string& wav_name,
    float& volume,
    bool& loopable, 
    sound_type& type)
{
    std::string full_sound_path;
    std::stringstream full_sound_stream;
    create_args entry;
    entry.loopable = loopable;
    entry.volume = volume;
    switch (type)
    {
        case MUSIC:
            full_sound_stream << MUSIC_DIRECTORY << wav_name;
            break;
        case EFFECT:
            full_sound_stream << EFFECT_DIRECTORY << wav_name;
            break;
    }
    full_sound_path = full_sound_stream.str();
    entry.full_path = full_sound_path;
    sound_registry[wav_name] = entry;
}

const char** sound_manager::get_sound_names()
{
    std::vector<std::string> sound_names;
    for (
        std::map<std::string, create_args>::iterator registry_it = sound_registry.begin();
        registry_it != sound_registry.end();
        registry_it++)
    {
        sound_names.push_back(registry_it->first);
    }

    const char** sound_names_char = (const char**)malloc(sound_names.size() * sizeof(char*));
    int index = 0;
    for (
        std::vector<std::string>::iterator sound_string_it = sound_names.begin();
        sound_string_it != sound_names.end();
        sound_string_it++)
    {
        sound_names_char[index] = (const char*)malloc(sound_string_it->size());
        strcpy((char*)*(sound_names_char+index),  sound_string_it->c_str());
        index++;
    }

    return sound_names_char;
}

int sound_manager::get_number_of_entries()
{
    return sound_registry.size();
}

void sound_manager::play_sound(std::string& wav_name)
{
    pthread_t thread_id;
    create_args* arg = &sound_registry[wav_name];
    pthread_create(&thread_id, NULL, &play_sound_thread, arg);
    pthread_detach(thread_id);
}

void* sound_manager::play_sound_thread(void* arg_ptr)
{
    create_args* create_args_ref = (create_args*)arg_ptr;
    cpp_core_audio audio_ref = cpp_core_audio(create_args_ref->full_path, create_args_ref->volume, create_args_ref->loopable);
    audio_ref.play();
    while (audio_ref.is_playing()){}
    return (void*)0;
}
