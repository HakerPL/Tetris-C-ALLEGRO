#pragma once
#include "figura_abstract.h"
class Figura_Kropka :
	public Figura_Abstract
{
	public:

		//RUCH KLOCKIEM
		bool Move ( ALLEGRO_KEYBOARD_STATE &keyState , const std::vector< std::array<DataMap,10> > & Map ) ;
		//AUTOMATYCZNY RUCH KLOCKIEM W DOL
		bool MoveDown ( const std::vector< std::array<DataMap,10> > & Map ) ;
		//RYSUJEMY KLOCEK NA MAPIE  ???????
		void DrawBlock () ;
		//KOLIZJA KLOCKA
		bool Colision ( const std::vector< std::array<DataMap,10> > & Map ) ;
		//RYSUJEMY NASTEPNE KLOCKI
		void DrawNext () ;
		//ZWRACA KOLOR I POZYCJE BLOKOW
		const std::vector< DataBlock > ReturnDataBlock () ;

		//POZWOLENIE NA ZMIANE POZYCJI
		void Change_Position()
		{
			Change_Position1 = true ;
		}

		//POMOCNA ZMIENNA
		ALLEGRO_COLOR color1 ;

		Figura_Kropka()
		{
			int a = rand() % 5 ;
			switch(a)
			{
				case 0 :

					color1 = al_map_rgb( 24 , 230 , 38 ) ;
					break ;

				case 1:

					color1 = al_map_rgb( 24 , 52 , 230 ) ;
					break ;

				case 2:

					color1 = al_map_rgb( 255 , 255 , 255 ) ;
					break ;
					
				case 3:

					color1 = al_map_rgb( 253 , 0 , 253 ) ;
					break ;
					
				case 4:

					color1 = al_map_rgb( 253 , 25 , 0 ) ;
					break ;
			}

			DataBlock abc = { 5 , 1 , color1 } ;
			Figura.push_back( abc ) ;
		}
};

