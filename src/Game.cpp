/*
    The Last: Too Fast
    ED - 2015/1
    UFSCar - São Carlos
*/
#include "Game.h"

Game::Game()
{ }
/*
	Gera as Peças do jogo atual semi-aleatoriamente
	O número de peças é dado por DIFICULDADE * 20 + 30

	A ideia é ter 55% chance da peça atual ser diferente da anterior
	(if(prob > 1):80% + else:100%*3/4)
*/
void Game::populateQueue()
{
	while (!_pieces.empty()) _pieces.pop();

	int queueSize = _difficulty * 20 + 30;

    srand (time(NULL));

    int value = rand() % Config::imagesPaths.size();
    do {
        int prob = rand() % 10;
        if (prob > 1)
        {
            value = rand() % Config::imagesPaths.size();
        }

        _pieces.push(Piece(value));
    } while (queueSize--);
}

bool Game::saveScore()
{
    throw "not implemented";
	//return _scoresManager.addScore(_difficulty, _score);
}

List<Score> Game::getScores(Config::Difficulty difficulty)
{
    throw "not implemented";
	//return _scoresManager.getScores(difficulty);
}

Piece Game::getCurrentPiece()
{
    return _pieces.getCurrent();
}

void Game::resetScore()
{
	return _score.reset("");
}

Piece Game::newGame(Config::Difficulty difficulty, std::string playerName)
{
	_difficulty = difficulty;
	_score.reset(playerName);

	populateQueue();
    _pieces.pop();
	return _pieces.getPrevious();
}

bool Game::answer(bool userAnswer)
{
	Piece current = _pieces.getCurrent();
	Piece previous = _pieces.getPrevious();
	_pieces.pop();

	if (current.isEqual(previous) && userAnswer) {
		return true;
	}
	else if (!current.isEqual(previous) && !userAnswer) {
		return true;
	}
	else {
        _score.incrementError();
        incrementTimer(); incrementTimer(); incrementTimer(); incrementTimer(); incrementTimer();

		_pieces.push(previous);
		return false;
	}
}

void Game::incrementTimer()
{
	_score.incrementTimer();
}

Score Game::getScore()
{
    return _score;
}

bool Game::finishGame()
{
	if (hasFinished())
    {
        // TODO
        // Adicionar função para manter um Score
		// saveScore();
	}

    while (!_pieces.empty()) _pieces.pop();

	return true;
}

bool Game::hasFinished()
{
	return _pieces.empty();
}
