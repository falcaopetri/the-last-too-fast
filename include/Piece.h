/*
    The Last: Too Fast
    ED - 2015/1
    UFSCar - S�o Carlos
*/
#ifndef PIECE_H
#define PIECE_H

#include <string>

namespace tltf {
	/*
		Encapsula uma "Pe�a" do jogo,
		representada por um identificador inteiro
	*/
	class Piece {
	private:
		int _id;
	public:
	    Piece ();
		Piece (int id);

		int getId () const;
		/*
			Retorna se duas Pe�as s�o iguais (mesmo ID)
		*/
		bool isEqual (const Piece& other) const;
	};
}

#endif
