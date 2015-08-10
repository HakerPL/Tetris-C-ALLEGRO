#pragma once
#include "figura_abstract.h"

// POZYCJA O
// 0 1     KORDY 4 5  X   1 Y

// POZYCJA 1 Y   X  
// 1		0	 5
// 2		1




class Figura_Linia_Mala :
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

		//AUTOMATYCZNY RUCH W DOL POZYCJA 0
		bool Auto_Down_0 ( const std::vector< std::array<DataMap,10> > & Map ) ;
		//DLA 1
		bool Auto_Down_1 ( const std::vector< std::array<DataMap,10> > & Map ) ;

		//RUCH KLOCKA POZYCJA 0
		bool Move_0 ( ALLEGRO_KEYBOARD_STATE &keyState , const std::vector< std::array<DataMap,10> > & Map ) ;
		//POZYCJA 1
		bool Move_1 ( ALLEGRO_KEYBOARD_STATE &keyState , const std::vector< std::array<DataMap,10> > & Map ) ;

		//SPRAWDZAMY CZY ZMIANA POZYCJI JEST MOZLIWA
		bool Change_Position ( const std::vector< std::array<DataMap,10> > & Map ) ;


		//POZWOLENIE NA ZMIANE POZYCJI
		void Change_Position()
		{
			Change_Position1 = true ;
		}

		//POMOCNA ZMIENNA
		ALLEGRO_COLOR color1 ;

		Figura_Linia_Mala()
		{
			//ILOSC POZYCJI
			NumberPosition = 2 ;

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

			//LOSUJEMY POZYCJE FIGURY
			a = rand() % NumberPosition ;
			DataBlock abc ;
			switch(a)
			{
				case 0:
					
					Position = 0 ;

					abc.color = color1 ;
					abc.x = 4 ;
					abc.y = 1 ;
					Figura.push_back( abc ) ;

					abc.x = 5 ;
					abc.y = 1 ;
					Figura.push_back( abc ) ;

					break ;

				case 1:

					Position = 1 ;

					abc.color = color1 ;
					abc.x = 5 ;
					abc.y = 0 ;
					Figura.push_back( abc ) ;

					abc.x = 5 ;
					abc.y = 1 ;
					Figura.push_back( abc ) ;

					break ;
			}
		}
};

