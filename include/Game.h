/*
    The Last: Too Fast
    ED - 2015/1
    UFSCar - São Carlos
*/
#ifndef GAME_H
#define GAME_H

#include "Config.h"
#include "Piece.h"
#include "Score.h"
#include "MemoryQueue.hpp"
#include "List.hpp"

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace tltf;

namespace tltf {
	class Game {
	private:
		/*
			Dificuldade do jogo atual
		*/
		Config::Difficulty _difficulty;
		/*
			Score atual
		*/
		Score _score;
		/*
			Lista de peças geradas quando populateQueue() é invocado no início de um novo jogo
		*/
		MemoryQueue<Piece> _pieces;
		/*
			Adiciona elementos à fila, de acordo com a dificuldade definida
		*/
		void populateQueue();
		/*
			Persiste a pontuação do jogo atual (caso ela seja uma das top 5) utilizando o ScoresManager
		*/
		bool saveScore();
	public:
		Game();

		/*
            // TODO
			Retorna os Top 5 scores para uma determinada dificuldade
		*/
		List<Score> getScores(Config::Difficulty difficulty);
		Piece getCurrentPiece();

		bool hasFinished();

		void resetScore();
		/*
			Prepara o Game para um novo jogo
			Retorna a primeira peça do jogo
		*/
		Piece newGame(Config::Difficulty difficulty, std::string playerName);
		/*
			Realiza uma jogada, verificando se a resposta do usuário foi correta
			e gerenciando:
			1. A fila (avança a fila)
			2. O errorCounter do jogador atual (_score)
		*/
		bool answer(bool userAnswer);

		void incrementTimer();
		Score getScore();
		/*
			Encerra o jogo, validando se ele já tinha chegado ao final
			e adicionando a pontuação do jogador, se for o caso
		*/
		bool finishGame();
	};
}

#endif
