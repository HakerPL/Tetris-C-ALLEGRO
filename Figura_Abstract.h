#ifndef FIGURA_ABSTRACT_H
#define FIGURA_ABSTRACT_H

//#pragma once
#include <allegro5\allegro_primitives.h>
//#include <allegro5/allegro_image.h>
//#include <allegro5\allegro_font.h>
//#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro5.h>
#include <vector>
#include <array>
#include "zmienne.h"

class Figura_Abstract
{
	public:
		
		//RUCH KLOCKIEM
		virtual bool Move ( ALLEGRO_KEYBOARD_STATE &keyState , const std::vector< std::array<DataMap,10> > & Map ) = 0 ;
		//AUTOMATYCZNY RUCH KLOCKIEM W DOL
		virtual bool MoveDown ( const std::vector< std::array<DataMap,10> > & Map ) = 0 ;
		//RYSUJEMY KLOCEK NA MAPIE  ???????
		virtual void DrawBlock () = 0 ;
		//KOLIZJA KLOCKA
		virtual bool Colision ( const std::vector< std::array<DataMap,10> > & Map ) = 0 ;
		//RYSUJEMY NASTEPNE KLOCKI
		virtual void DrawNext () = 0 ;
		//ZWRACA KOLOR I POZYCJE BLOKOW
		virtual const std::vector< DataBlock > ReturnDataBlock () = 0 ;

		//ZMIANA POZWOLENIA NA ZMIANE POZYCJI
		virtual void Change_Position() = 0 ;

		//VIRTUALNY DESTRUKTOR
		virtual ~Figura_Abstract() {} ;

		Figura_Abstract() 
		{
			Change_Position1 = false ;
		}

	protected:

		//POZYCJA KLOCKA (LOSOWANA PRZY TWORZENIU)
		int Position ;
		//ILOSC POZYCJI
		int NumberPosition ;
		//POZYCJA KAZDEGO KLOCKA
		std::vector< DataBlock > Figura ; 

		//ZEZWOLENIE NA ZMIANE POZYCJI
		bool Change_Position1 ;

};

#endif