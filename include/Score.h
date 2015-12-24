/*
    The Last: Too Fast
    ED - 2015/1
    UFSCar - S�o Carlos
*/
#ifndef SCORE_H
#define SCORE_H

#include <string>

namespace tltf {
	class Score {
	private:
	    /*
            TODO
            Requisitar o Nome do Jogador para adicionar a fun��o de Score
	    */
		std::string _playerName;
		unsigned _timing;
		unsigned _errorCounter;
	public:
	    Score();
		Score(std::string playerName);
		void reset(std::string playerName);
		/*
			Incrementa o contator de erros do jogador
		*/
		void incrementError();
		/*
			Incrementa o timing em 1 segundo
		*/
		void incrementTimer();

		std::string getPlayerName();
		unsigned getTiming();
		unsigned getErrorCounter();
	};
}

#endif
