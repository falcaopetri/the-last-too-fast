/*
    The Last: Too Fast
    ED - 2015/1
    UFSCar - São Carlos
*/
#include "GUI.h"

/*
    Aborda a inicialização do Jogo
    Chamada para ocorra erro em algum componente ou imagem carregada por meio do Allegro
    Emite uma mensagem de acordo com o componente que falhou
*/
void abortGame (const string message)
{
    fprintf(stderr, message.c_str());
    abortGameFlag = true;
}
/*
    Desenha uma Image na tela de acordo com o identificador @name
*/
void drawImage (string name)
{
    al_draw_bitmap(systemImages[name].getBitmap(),
                           systemImages[name].getX(), systemImages[name].getY(), 0);
}
/*
    Carrega uma imagem utilizada pelo jogo, cujo path encontra-se
    em Config::imagesPaths
*/
void loadSystemImage (string name, int xPos, int yPos)
{
    if (!abortGameFlag)
    {
        systemImages[name] = Image(xPos, yPos, al_load_bitmap(Config::systemImagesPaths[name]));
        if(!systemImages[name].getBitmap())
        {
            abortGame("failed to load " + name + " image");
            return;
        }
    }
}
/*
    Carrega uma imagem utilizada nas Pelas, cujo path encontra-se
    em Config::magesPaths
*/
void loadImage (int num, int xPos, int yPos)
{
    if (!abortGameFlag)
    {
        string name = "image" + to_string(num);
        systemImages[name] = Image(xPos, yPos, al_load_bitmap(Config::imagesPaths[num]));
        if(!systemImages[name].getBitmap())
        {
            abortGame("failed to load " + name + " image");
            return;
        }
    }
}
/*
    Muda o path-working-directory para o local do executável,
    permitindo o uso de relative-paths para acessar os arquivos do jogo

    Source: https://www.allegro.cc/forums/thread/614268
*/
 void setResourceArchive() {
      // Get current working directory.
      ALLEGRO_PATH *al_path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);

      // Switch to directory in which application was run from.
      al_append_path_component(al_path, "./");
      al_change_directory(al_path_cstr(al_path, '/'));

     // Remove path from memory, as the new directory has been reached.
     al_destroy_path(al_path);

     PHYSFS_init(NULL);

     // Attempt to read contents of data.dat.
     PHYSFS_mount("data.dat", "/", 1);

     // All future loading calls will read from data.dat.
     al_set_physfs_file_interface();
 }
/*
    Inicializa o Allegro e todos os componentes utilizados
    Inicializa todas as imagens utilizadas ao longo do jogo
*/
void initAllegro ()
{
    // Init
    {
        if(!al_init())
        {
            abortGame("failed to initialize allegro!\n");
            return;
        }
    }
    // Keyboard
    {
        if(!al_install_keyboard())
        {
            abortGame("failed to initialize the keyboard!\n");
            return;
        }
    }
    // Mouse
    {
        if(!al_install_mouse())
        {
            abortGame("failed to initialize the mouse!\n");
            return;
        }
    }
    // Timers
    {
        timerDrawing = al_create_timer(1.0 / FPS);
        if(!timerDrawing)
        {
            abortGame("failed to create timerDrawing!\n");
            return;
        }
        timerPlaying = al_create_timer(1.0);
        if(!timerPlaying)
        {
            abortGame("failed to create timerPlaying!\n");
            return;
        }
    }
    // Display
    {
        display = al_create_display(SCREEN_W, SCREEN_H);
        if(!display)
        {
            abortGame("failed to create display!\n");
            return;
        }
    }

    setResourceArchive();
    // Font
    {
        al_init_font_addon();
        if(!al_init_ttf_addon())
        {
            abortGame("failed to initialize the ttf addon!\n");
            return;
        }

        font = al_load_ttf_font(Config::fontPath, 50, 0);
        if(!font)
        {
            abortGame("failed to initialize the ttf font!\n");
            return;
        }
    }
    // Audio
    {
        if(!al_install_audio())
        {
            abortGame("failed to initialize audio!\n");
            return;
        }
        if(!al_init_acodec_addon())
        {
            abortGame("failed to initialize audio codecs!\n");
            return;
        }

        if (!al_reserve_samples(1))
        {
            abortGame("failed to reserve samples!\n");
            return;
        }

        music = al_load_sample(Config::soundPath);

        if (!music)
        {
            abortGame("failed to load audio clip sample!\n" );
            return;
        }
    }
    // Image Addon
    {
        if(!al_init_image_addon())
        {
            abortGame("failed to initialize image addon!");
            return;
        }
    }
    // Background
    {
        loadSystemImage("background", 0, 0);
    }
    // Logo
    {
        loadSystemImage("logo", 0, 0);
    }
    // Icon
    {
        loadSystemImage("icon", 0, 0);
    }
    // Start Button
    {
        loadSystemImage("startNoFocus", 50, 300);
        loadSystemImage("startFocus", 45, 297);
    }
    // About Button
    {
        loadSystemImage("aboutNoFocus", 132, 380);
        loadSystemImage("aboutFocus", 127, 377);
    }
    // Sound Button
    {
        loadSystemImage("soundOn", 340, 480);
        loadSystemImage("soundOff", 340, 480);
    }
    // Easy Button
    {
        loadSystemImage("easyNoFocus", 143, 167);
        loadSystemImage("easyFocus", 138, 163);
    }
    // Medium Button
    {
        loadSystemImage("mediumNoFocus", 131, 245);
        loadSystemImage("mediumFocus", 124, 238);
    }
    // Hard Button
    {
        loadSystemImage("hardNoFocus", 132, 324);
        loadSystemImage("hardFocus", 125, 319);
    }
    // Insane Button
    {
        loadSystemImage("insaneNoFocus", 124, 406);
        loadSystemImage("insaneFocus", 117, 400);
    }
    // Images
    {
        for (size_t i = 0; i < Config::imagesPaths.size(); ++i)
        {
            loadImage(i, 65, 160);
        }
    }
    // aboutInfo
    {
        loadSystemImage("aboutInfo", 0, 0);
    }
    // gameQuestion
    {
        loadSystemImage("gameQuestion", 0, 0);
    }
    // selectDifficulty
    {
        loadSystemImage("selectDifficulty", 0, 0);
    }
    // noYes
    {
        loadSystemImage("noYes", 0, 439);
    }
    // Back
    {
        loadSystemImage("back", 5, 470);
    }
    // Event Queue
    {
        event_queue = al_create_event_queue();
        if(!event_queue)
        {
            abortGame("failed to create event_queue!\n");
            return;
        }
    }
    // Window properties
    {
        al_set_window_title(display, Config::windowTitle);
        al_set_display_icon(display, systemImages["icon"].getBitmap());
    }
    // Event registers
    {
        al_register_event_source(event_queue, al_get_display_event_source(display));
        al_register_event_source(event_queue, al_get_timer_event_source(timerDrawing));
        al_register_event_source(event_queue, al_get_timer_event_source(timerPlaying));
        al_register_event_source(event_queue, al_get_keyboard_event_source());
        al_register_event_source(event_queue, al_get_mouse_event_source());
    }
    // Display setup
    {
        al_set_target_bitmap(al_get_backbuffer(display));
        al_clear_to_color(al_map_rgb(0,0,0));
        al_flip_display();
    }
    // Start timers
    {
        al_start_timer(timerDrawing);
        al_start_timer(timerPlaying);
    }
}

void drawSoundButton ()
{
    if (soundOn)
    {
        drawImage("soundOn");
        if (!isPlayingSound)
        {
            al_play_sample(music, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, &musicId);
            isPlayingSound = true;
        }
    }
    else
    {
        drawImage("soundOff");
        if (isPlayingSound)
        {
            al_stop_sample(&musicId);
            isPlayingSound = false;
        }
    }
}
void drawMenuHome ()
{
    // Logo
    {
        drawImage("logo");
    }
    // Start Button
    {
        if(systemImages["startNoFocus"].hasFocus())   drawImage("startFocus");
        else                                        drawImage("startNoFocus");
    }
    // About Button
    {
        if(systemImages["aboutNoFocus"].hasFocus())   drawImage("aboutFocus");
        else                                        drawImage("aboutNoFocus");
    }
    // Sound
    {
        drawSoundButton();
    }
}

void drawMenuDifficulty ()
{
    // Select difficulty
    {
        drawImage("selectDifficulty");
    }
    // Easy Button
    {
        if(systemImages["easyNoFocus"].hasFocus())    drawImage("easyFocus");
        else                                        drawImage("easyNoFocus");
    }
    // Medium Button
    {
        if(systemImages["mediumNoFocus"].hasFocus())      drawImage("mediumFocus");
        else                                            drawImage("mediumNoFocus");
    }
    // Hard Button
    {
        if(systemImages["hardNoFocus"].hasFocus())    drawImage("hardFocus");
        else                                        drawImage("hardNoFocus");
    }
    // Insane Button
    {
        if(systemImages["insaneNoFocus"].hasFocus())  drawImage("insaneFocus");
        else                                        drawImage("insaneNoFocus");
    }
    // Back Button
    {
        drawImage("back");
    }
    // Sound Button
    {
        drawSoundButton();
    }
}

void drawMenuPlaying ()
{
    if (!game.hasFinished())
    {
        int time = game.getScore().getTiming();
        string name = "image" + to_string(currentPiece.getId());

        if (animate == 0)
        {
            drawImage(name);
        }
        else
        {
            alfa += 1;
            if(alfa > 10) { animate = 0; alfa=0; }

            if (animate == 1)
            {
                al_draw_tinted_bitmap(systemImages[name].getBitmap(),
                                      al_map_rgba(255 - alfa, 255 - alfa, 255 - alfa, alfa),
                                      systemImages[name].getX(), systemImages[name].getY(), 0);
            }
            else if (animate == -1)
            {
                al_draw_tinted_bitmap(systemImages[name].getBitmap(),
                                      al_map_rgba(245 + alfa, 245 + alfa, 245 + alfa, alfa),
                                      systemImages[name].getX(), systemImages[name].getY(), 0);
            }
        }

        if (time < 2 && showQuestionImage)
        {
        }
        else if (time < 3)
        {
            if (showQuestionImage) {
                game.resetScore();
                currentPiece = game.getCurrentPiece();
                animate = -1;
                showQuestionImage = false;
            }
            drawImage("gameQuestion");
            drawImage("noYes");
        }
        else
        {
            drawImage("noYes");

            string errorCounter = to_string(game.getScore().getErrorCounter());
            al_draw_text(font, al_map_rgb(255,0,0), SCREEN_W*3/18, 0,ALLEGRO_ALIGN_CENTRE, errorCounter.c_str());

            char timing[100];
            sprintf(timing, "%d:%02d", time / 60, time % 60);
            al_draw_text(font, al_map_rgb(255,255,255), SCREEN_W*52/72, 0, ALLEGRO_ALIGN_CENTRE, timing);
        }

        if (!gameAnswer)
        {
            al_draw_text(font, al_map_rgb(255,50,0), SCREEN_W*66/72, 0, ALLEGRO_ALIGN_CENTRE, "+5s");
        }
    }
    else
    {
        game.finishGame();
        currentMenu = Menu::END_PLAYING;
    }
}

void drawMenuEndPlaying ()
{
    al_draw_text(font, al_map_rgb(0,0,0), SCREEN_W/2, (SCREEN_H/2),ALLEGRO_ALIGN_CENTRE, "Total de Erros:");
    al_draw_text(font, al_map_rgb(0,0,0), SCREEN_W/2, (SCREEN_H/8),ALLEGRO_ALIGN_CENTRE, "Tempo Total:");

    string errorCounter = to_string(game.getScore().getErrorCounter());
    al_draw_text(font, al_map_rgb(255,50,0), SCREEN_W/2, (SCREEN_H*5/8),ALLEGRO_ALIGN_CENTRE, errorCounter.c_str());

    int time = game.getScore().getTiming();
    char timing[100];
    sprintf(timing, "%d:%02d", time / 60, time % 60);
    al_draw_text(font, al_map_rgb(255,50,0), SCREEN_W/2, (SCREEN_H/4),ALLEGRO_ALIGN_CENTRE, timing);

    drawImage("back");
}

void drawMenuAbout ()
{
    drawImage("aboutInfo");
    drawImage("back");
}
/*
    Desenha o Menu Atual
*/
void drawCurrentMenu ()
{
    drawImage("background");

    if      (currentMenu == Menu::HOME)         drawMenuHome();
    else if (currentMenu == Menu::DIFFICULTY)   drawMenuDifficulty();
    else if (currentMenu == Menu::PLAYING)      drawMenuPlaying();
    else if (currentMenu == Menu::END_PLAYING)  drawMenuEndPlaying();
    else if (currentMenu == Menu::ABOUT)        drawMenuAbout();

    al_flip_display();
}

void answerGame (bool answer)
{
    gameAnswer = game.answer(answer);
    currentPiece = game.getCurrentPiece();
    showQuestionImage = false;
    animate = -1;
    alfa = 0;
}
void interfaceLoop()
{
    while(!doexit)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);

        if(ev.type == ALLEGRO_EVENT_TIMER)
        {
            if (ev.timer.source == timerDrawing)
            {
                redraw = true;
            }
            else if (ev.timer.source == timerPlaying)
            {
                if (!game.hasFinished())
                    game.incrementTimer();
            }
        }
        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            break;
        }
        else if(ev.type == ALLEGRO_EVENT_MOUSE_AXES)   //check if the mouse moved
        {
            if (currentMenu == Menu::HOME)
            {
                systemImages["startNoFocus"].checkOver(ev.mouse.x, ev.mouse.y);
                systemImages["aboutNoFocus"].checkOver(ev.mouse.x, ev.mouse.y);
                systemImages["soundOn"].checkOver(ev.mouse.x, ev.mouse.y);
            }
            else if (currentMenu == Menu::DIFFICULTY)
            {
                systemImages["easyNoFocus"].checkOver(ev.mouse.x, ev.mouse.y);
                systemImages["mediumNoFocus"].checkOver(ev.mouse.x, ev.mouse.y);
                systemImages["hardNoFocus"].checkOver(ev.mouse.x, ev.mouse.y);
                systemImages["insaneNoFocus"].checkOver(ev.mouse.x, ev.mouse.y);
                systemImages["soundOn"].checkOver(ev.mouse.x, ev.mouse.y);
                systemImages["back"].checkOver(ev.mouse.x, ev.mouse.y);
            }
            else if (currentMenu == Menu::ABOUT)
            {
                systemImages["back"].checkOver(ev.mouse.x, ev.mouse.y);
            }
            else if (currentMenu == Menu::END_PLAYING)
            {
                systemImages["back"].checkOver(ev.mouse.x, ev.mouse.y);
            }
        }
        else if(ev.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
        {
            if (currentMenu == Menu::HOME)
            {
                if (systemImages["startNoFocus"].hasFocus())      currentMenu = Menu::DIFFICULTY;
                else if (systemImages["aboutNoFocus"].hasFocus()) currentMenu = Menu::ABOUT;
                else if (systemImages["soundOn"].hasFocus())      soundOn = !soundOn;
            }
            else if (currentMenu == Menu::DIFFICULTY)
            {
                gameAnswer = true;
                showQuestionImage = true;
                animate = 1;
                if (systemImages["easyNoFocus"].hasFocus())
                {
                    currentPiece = game.newGame(Config::Difficulty::FACIL, "");
                    currentMenu = Menu::PLAYING;
                }
                else if (systemImages["mediumNoFocus"].hasFocus())
                {
                    currentPiece = game.newGame(Config::Difficulty::MEDIO, "");
                    currentMenu = Menu::PLAYING;
                }
                else if (systemImages["hardNoFocus"].hasFocus())
                {
                    currentPiece = game.newGame(Config::Difficulty::DIFICIL, "");
                    currentMenu = Menu::PLAYING;
                }
                else if (systemImages["insaneNoFocus"].hasFocus())
                {
                    currentPiece = game.newGame(Config::Difficulty::INSANO, "");
                    currentMenu = Menu::PLAYING;
                }
                else if (systemImages["back"].hasFocus())
                {
                    currentMenu = Menu::HOME;
                }
                else if (systemImages["soundOn"].hasFocus())
                {
                    soundOn = !soundOn;
                }
            }
            else if (currentMenu == Menu::ABOUT)
            {
                if (systemImages["back"].hasFocus())
                {
                    currentMenu = Menu::HOME;
                }
            }
            else if (currentMenu == Menu::END_PLAYING)
            {
                if (systemImages["back"].hasFocus())
                {
                    currentMenu = Menu::DIFFICULTY;
                }
            }
        }
        else if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {
            if (currentMenu == Menu::PLAYING)
            {
                switch(ev.keyboard.keycode)
                {
                case ALLEGRO_KEY_LEFT:
                    answerGame(false);
                    break;

                case ALLEGRO_KEY_RIGHT:
                    answerGame(true);
                    break;
                }
            }
        }
        else if(ev.type == ALLEGRO_EVENT_KEY_UP)
        {
            switch(ev.keyboard.keycode)
            {
            case ALLEGRO_KEY_ESCAPE:
                if (!game.hasFinished())
                    game.finishGame();

                currentMenu = Menu::HOME;
                break;
            }
        }

        if(redraw && al_is_event_queue_empty(event_queue))
        {
            redraw = false;
            al_clear_to_color(al_map_rgb(0,0,0));
            drawCurrentMenu();
        }
    }

}
/*
    Destrói todos os componentes do Allegro
    Deve-se adicionar à esse métodos qualquer componente do Allegro
    que necessite de uma desreferenciação apropriada

    Essa função é executada ao final do jogo ou caso a inicialização
    do Allegro falhe logo no início da aplicação
*/
void shutdown()
{
    if (timerDrawing)    al_destroy_timer(timerDrawing);
    if (timerPlaying)    al_destroy_timer(timerPlaying);
    if (display)         al_destroy_display(display);
    if (event_queue)     al_destroy_event_queue(event_queue);
    if (music)           al_destroy_sample(music);

    for (auto &image: systemImages)
    {
        if (image.second.getBitmap()) al_destroy_bitmap(image.second.getBitmap());
    }
    systemImages.clear();
}
/*
    A vida de um jogo utilizando o Allegro é definida por:
    1. Inicialização dos componentes do Allegro
    2. Loop de jogo
    3. Remoção de todos os componentes criados
*/
int main(int argc, char **argv)
{
    initAllegro();
    currentMenu = Menu::HOME;
    if (!abortGameFlag)
    {
        interfaceLoop();
    }
    shutdown();

    return 0;
}
