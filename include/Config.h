/*
    The Last: Too Fast
    ED - 2015/1
    UFSCar - São Carlos
*/
#ifndef CONFIG_H
#define CONFIG_H

#include "List.hpp"

#include <string>
#include <map>

namespace tltf {
	class Config{
	public:
	     static const tltf::List<char*> imagesPaths;

		/*
            TODO
			Relative path de cada conjunto de Score
			Cada um contém os 5 maiores Scores de cada nível
        */
		//static const List<std::string> scoresPaths;

        static const char* soundPath;
        static const char* fontPath;
        static const char* windowTitle;

        static std::map<std::string, char*> systemImagesPaths;
		/*
			Enum de dificuldades
        */
		enum Difficulty {
			FACIL, MEDIO, DIFICIL, INSANO
		};

	};
}
#endif
