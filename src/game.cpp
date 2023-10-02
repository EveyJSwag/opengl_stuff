#include "game.h"
#include "debug_timer_singleton.h"
int game::run_game()
{
    glfwInit();

    // Define version and compatibility settings
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    // Create OpenGL window and context
    window = glfwCreateWindow(1400, 800, "Fighting-Game", NULL, NULL);
    glfwMakeContextCurrent(window);

    // Check for window creation failure
    if (!window)
    {
        // Terminate GLFW
        glfwTerminate();
        return 0;
    }

    keyboard_ref = new keyboard(window);

    glm::vec3 i_camera_pos = glm::vec3(-1.2f, -1.2f, 0.0f);

    main_camera = new camera(i_camera_pos);

    // Initialize GLEW
    glewExperimental = GL_TRUE;
    glewInit();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 150");
    ImGui::StyleColorsDark();

    vertex_coordinate3 og_coord = {0.0f, -0.1f, 0.0f};
    vertex_coordinate3 ryu_coord = {0.1f, 0.1f, 0.0f};
    vertex_coordinate3 ryu_coord2 = {0.4f, 0.1f, 0.0f};
    vertex_coordinate3 background_coord = {-0.3f, -0.4f, 0.0f};
    vertex_coordinate3 floor_coord = {0.0f, -0.1f, 0.0f};

    game_sound = sound_manager::get_instance();
    sound_manager::sound_type music_type = sound_manager::MUSIC;
    sound_manager::sound_type effect_type = sound_manager::EFFECT;
    std::string ryu_theme = "ryu_theme.wav";
    std::string cringe_song = "Cringe.wav";
    std::string fight_with_rocks_song = "FightWithRocks.wav";
    std::string tatsu = "tatsumaki.wav";
    std::string hado = "hadoken.wav";
    std::string shoryuken = "shoryuken.wav";
    std::string menu_select = "SND_SELE_2.wav";
    float music_volume = 0.2f;
    float effect_volume = 0.1f;
    bool music_loopable = true;
    bool effect_loopable = false;
    std::string punch_air = "punch_air.wav";
    game_sound->add_to_registry(ryu_theme, music_volume, music_loopable, music_type);
    game_sound->add_to_registry(cringe_song, music_volume, music_loopable, music_type);
    game_sound->add_to_registry(fight_with_rocks_song, music_volume, music_loopable, music_type);
    game_sound->add_to_registry(punch_air, effect_volume, effect_loopable, effect_type);
    game_sound->add_to_registry(tatsu, effect_volume, effect_loopable, effect_type);
    game_sound->add_to_registry(shoryuken, effect_volume, effect_loopable, effect_type);
    game_sound->add_to_registry(hado, effect_volume, effect_loopable, effect_type);
    game_sound->add_to_registry(menu_select, effect_volume, effect_loopable, effect_type);

    ryu_char = new ryu_character(
        keyboard_ref,
        "ryu",
        ryu_coord,
        "ryu_sheet.png",
        populate_sprite_info(),
        -0.008f,
        43.0f);

    std::string health_bar_sprite_sheet_name = "health_bar.png";
    vertex_coordinate3 health_bar_position_p1 = {-1.0f, 0.8f, 0.0f};
    vertex_coordinate3 health_bar_position_p2 = {0.999f, 0.8f, 0.0f};

    player1_health_bar = new health_bar(
        health_bar_sprite_sheet_name,
        health_bar_position_p1);

    player2_health_bar = new health_bar(
        health_bar_sprite_sheet_name,
        health_bar_position_p2);

    ryu_stage = new game_stage(
        "RYUS_STAGE",
        background_coord,
        floor_coord,
        "ryu_stage_alpha_2.png",
        populate_ryu_stage_info(),
        "RYU_STAGE_FLOOR",
        "RYU_STAGE_BACKGROUND");

    fps_counter_ref = fps_counter::get_instance();
    vertex_coordinate3 i_postion = {-1.0f, -0.2f, 0.0f};
    text_displayer *test_text = new text_displayer(i_postion);

    shader_creator_nt = new shader_creator(
        shader_creator::VERTEX_AND_FRAGMENT_SHADER_FILE_PATH,
        "shaders/vertex_shader_no_texture.glsl",
        "shaders/fragment_shader_no_texture.glsl");

    shader_creator_ref = new shader_creator(
        shader_creator::VERTEX_AND_FRAGMENT_SHADER_FILE_PATH,
        "shaders/vertex_shader.glsl",
        "shaders/fragment_shader.glsl");

    shader_creator_ui = new shader_creator(
        shader_creator::VERTEX_AND_FRAGMENT_SHADER_FILE_PATH,
        "shaders/UI_vertex_shader.glsl",
        "shaders/UI_fragment_shader.glsl");

    shader_creator_ref->add_uniform("MVP");

    double current_time = glfwGetTime();
    float should_walk = false;
    frame_count = 0;
    float projection_angle = 40.0f;
    float view_x_num = 0.0f;
    shader_creator_ref->use_program();
    main_camera->zoom_out(0.2f);
    std::string wav_file = "sound/music/ryu_theme.wav";
    float volume = 0.6f;
    game_sound->play_sound(fight_with_rocks_song);
    const float FPS_FACTOR = 1.0f / 60.0f;
    glfwSwapInterval(1);

    my_hurtbox = new hurtbox();
    game_loop();

    delete shader_creator_ref;
    delete shader_creator_ui;
    glfwTerminate();
    return 0;
}


void game::game_loop()
{
    const char** sound_names = game_sound->get_sound_names();
    int sound_selection_index = 0;
    int prev_sound_selection_index = sound_selection_index;
    std::string menu_string = "SND_SELE_2.wav";
    debug_timer_singleton* dts_instance = debug_timer_singleton::get_instance();
    while (!glfwWindowShouldClose(window))
    {
        std::chrono::high_resolution_clock::time_point loop_frame_start =  std::chrono::high_resolution_clock::now();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        prev_sound_selection_index = sound_selection_index;
        ImGui::ListBox(
            "SoundsToPlay", 
            &sound_selection_index, 
            sound_names, 
            game_sound->get_number_of_entries());

        if(prev_sound_selection_index != sound_selection_index)
        {
            game_sound->play_sound(menu_string);
        }
        float start_frame_time = glfwGetTime();
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

        ryu_stage->display_stage();
        ryu_char->handle_character();
        if (glfwGetKey(window, GLFW_KEY_RIGHT))
        {
            main_camera->move_camera(glm::vec3(0.05f, 0.0f, 0.0f));
            ryu_stage->move_background(0.008);
        }
        if (glfwGetKey(window, GLFW_KEY_LEFT))
        {
            main_camera->move_camera(glm::vec3(-0.05f, 0.0f, 0.0f));
            ryu_stage->move_background(-0.008);
        }
        if (glfwGetKey(window, GLFW_KEY_UP))
        {
            main_camera->move_camera(glm::vec3(0.0f, -0.05f, 0.0f));
        }
        if (glfwGetKey(window, GLFW_KEY_DOWN))
        {
            main_camera->move_camera(glm::vec3(0.0f, 0.05f, 0.0f));
        }
        if (glfwGetKey(window, GLFW_KEY_F))
        {
            ryu_char->flip();
        }
        main_camera->display();
        shader_creator_ref->set_uniform_matrix("MVP", main_camera->get_mvp());

        shader_creator_ui->use_program();

        player1_health_bar->draw();
        player2_health_bar->draw(true);

        fps_counter_ref->display_fps();

        shader_creator_nt->use_program();
        
        keyboard_ref->poll();
        shader_creator_ref->use_program();
        my_hurtbox->draw_hurtbox();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        glfwSwapBuffers(window);
        glfwPollEvents();

        frame_count++;

        lock_at_60_fps(loop_frame_start);        
    }
}

void game::lock_at_60_fps(const std::chrono::high_resolution_clock::time_point& loop_frame_start)
{
    std::chrono::high_resolution_clock::time_point loop_frame_end =  std::chrono::high_resolution_clock::now();
    long long duration_of_frame = (loop_frame_end - loop_frame_start).count();
    long long time_delta = game::FPS_DURATION_NANO_SECONDS - duration_of_frame;
    while (time_delta > 0.09){
        duration_of_frame = (std::chrono::high_resolution_clock::now() - loop_frame_start).count();
        time_delta = game::FPS_DURATION_NANO_SECONDS - duration_of_frame;
    }
}