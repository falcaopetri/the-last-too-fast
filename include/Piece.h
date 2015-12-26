/*
    The Last: Too Fast
    ED - 2015/1
    UFSCar - São Carlos
*/
#ifndef PIECE_H
#define PIECE_H

#include <string>

namespace tltf {
	/*
		Encapsula uma "Peça" do jogo,
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
			Retorna se duas Peças são iguais (mesmo ID)
		*/
		bool isEqual (const Piece& other) const;
	};
}

#endif
