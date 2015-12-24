/*
    The Last: Too Fast
    ED - 2015/1
    UFSCar - São Carlos
*/
#include "Score.h"

tltf::Score::Score() {
}

tltf::Score::Score(std::string playerName) {
	reset(playerName);
}

void tltf::Score::reset(std::string playerName) {
	_playerName = playerName;
	_timing = 0;
	_errorCounter = 0;
}

void tltf::Score::incrementError() {
	_errorCounter++;
}

void tltf::Score::incrementTimer() {
	_timing++;
}

std::string tltf::Score::getPlayerName() {
	return _playerName;
}

unsigned tltf::Score::getTiming() {
	return _timing;
}

unsigned tltf::Score::getErrorCounter() {
	return _errorCounter;
}
