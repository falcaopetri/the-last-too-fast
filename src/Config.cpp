/*
    The Last: Too Fast
    ED - 2015/1
    UFSCar - S�o Carlos
*/
#include "Config.h"

const tltf::List<char*> tltf::Config::imagesPaths = {
	"images/image0.png",
	"images/image1.png",
	"images/image2.png",
	"images/image3.png"
};

const char* tltf::Config::soundPath = "sounds/sound.wav";
const char* tltf::Config::fontPath = "fonts/badabb.ttf";
const char* tltf::Config::windowTitle = "The Last: Too Fast";


std::map<std::string, char*> tltf::Config::systemImagesPaths = {
    { "background",     "images/system/background.png"},
    { "logo",           "images/system/logo.png"},
    { "icon",            "images/system/icon.png" },

    { "startNoFocus",   "images/system/startNoFocus.png" },
    { "startFocus",     "images/system/startFocus.png" },

    { "aboutNoFocus",   "images/system/aboutNoFocus.png" },
    { "aboutFocus",     "images/system/aboutFocus.png" },

    { "soundOn",        "images/system/soundOn.png" },
    { "soundOff",       "images/system/soundOff.png" },

    { "easyNoFocus",    "images/system/easyNoFocus.png" },
    { "easyFocus",      "images/system/easyFocus.png" },

    { "mediumNoFocus",  "images/system/mediumNoFocus.png" },
    { "mediumFocus",    "images/system/mediumFocus.png" },

    { "hardNoFocus",    "images/system/hardNoFocus.png" },
    { "hardFocus",      "images/system/hardFocus.png" },

    { "insaneNoFocus",  "images/system/insaneNoFocus.png" },
    { "insaneFocus",    "images/system/insaneFocus.png" },

    { "aboutInfo",      "images/system/aboutInfo.png" },
    { "gameQuestion",   "images/system/gameQuestion.png" },
    { "selectDifficulty",   "images/system/selectDifficulty.png" },
    { "noYes",          "images/system/noYes.png" },
    { "back",           "images/system/back.png" }
};
