/*
    The Last: Too Fast
    ED - 2015/1
    UFSCar - São Carlos
*/
#ifndef GUI_H
#define GUI_H

#include <stdio.h>
#include <allegro5/allegro.h>

#include <allegro5/allegro_image.h>

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include <physfs.h>
#include <allegro5/allegro_physfs.h>

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <map>


#include "Game.h"
#include "Image.h"

using namespace tltf;
using namespace std;

const float FPS = 60*2;
const float SCALE_FACTOR = 0.5;
const int SCREEN_W = 768 * SCALE_FACTOR;
const int SCREEN_H = 1024 * SCALE_FACTOR;

enum Menu {
    HOME, DIFFICULTY, PLAYING, ABOUT, END_PLAYING
};

Menu currentMenu;
Game game;
Piece currentPiece;

std::map<std::string, Image> systemImages;

bool soundOn = true;
bool isPlayingSound = false;
bool showQuestionImage = false;
bool gameAnswer = true;
bool redraw = true;
bool doexit = false;
bool abortGameFlag = false;
int animate = 1;
int alfa = 0;

ALLEGRO_DISPLAY *display = NULL;
ALLEGRO_EVENT_QUEUE *event_queue = NULL;
ALLEGRO_TIMER *timerDrawing = NULL;
ALLEGRO_TIMER *timerPlaying = NULL;
ALLEGRO_SAMPLE *music=NULL;
ALLEGRO_SAMPLE_ID musicId;
ALLEGRO_FONT *font;
#endif
