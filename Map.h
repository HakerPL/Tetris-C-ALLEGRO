#ifndef MAP_H
#define MAP_H

//PLIK ZE ZMIENNYMI
#include "zmienne.h"
#include "Figura_Abstract.h"
#include "Figura_Kwadrat.h"
#include "Figura_Linia_Duza.h"
#include "Figura_Kropka.h"
#include "Figura_Linia_Mala.h"
#include "Figura_Linia_Srednia.h"
#include "Figura_Zawijak_Prawy.h"
#include "Figura_Zawijak_Lewy.h"
#include "Figura_Trojkat.h"
#include "Figura_T.h"
#include "Figura_L_Normalne.h"
#include "Figura_L_Odwrocona.h"

#include <allegro5\allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5\allegro_native_dialog.h>
#include <sstream>
#include <vector>
#include <string>
#include <array>


class Map
{
	public:

		//WYPISUJE MAPE
		void Draw_Map () ;
		//KOLIZJA (DODANIE DO MAPY FIGURY)
		bool Colision() ;
		//SPRAWDZAMY CZY JEST LINIA DO SKASOWANIA
		bool Check_Line() ;
		//PRZESUWAMY LINIE W DOL
		void Down_Line() ;
		//ZWRACAMY MAPE DO OBLICZEN DLA FIGURY
		///const std::vector< std::vector< DataMap > > Send_Map() ;

		//PRZYJAZN Z KLASAMI EKRANU
		friend class Game_Screen  ;

		Map(void)
		{
			For_Line	= 100 ;
			Point		= 0   ;
			Combo		= 0   ;
			Bonus		= 10  ;
			Line_Delete = 0	  ;
			Max_Combo   = 0   ;
			LVL			= 1   ;

			DataMap aaa = { false , NULL } ;
			std::array < DataMap , 10 > bbb ;
			for( int i = 0 ; i < 10 ; i++ )
				bbb[i] = aaa ;

			//REZERWUJEMY WIELKOSC MAPY
			for( int i = 0 ; i < 16 ; i++ )
				Screen_Map.push_back(bbb) ;
			//Screen_Map.reserve(31) ;

			//USTAWIAMY WARTOSC RYSOWANIA NA FALSE
			//for( int y = 0 ; y < 2 ; y++ )
				//for( int x = 0 ; x < 1 ; x++ )
					//Screen_Map[y][x].Draw = false ;

			//LOSUJEMY FIGURY
			Random = rand() % 11 ;
			
			switch(Random)
			{
				case 0:

					Figura = new Figura_Kwadrat() ;
					break ;

				case 1:

					Figura = new Figura_Linia_Duza() ;
					break ;

				case 2:

					Figura = new Figura_Kropka() ;
					break ;

				case 3:

					Figura = new Figura_Linia_Mala() ;
					break ;

				case 4:

					Figura = new Figura_Linia_Srednia() ;
					break ;

				case 5:

					Figura = new Figura_Zawijak_Prawy() ;
					break ;

				case 6:

					Figura = new Figura_Zawijak_Lewy() ;
					break ;

				case 7:

					Figura = new Figura_Trojkat() ; 
					break ;

				case 8:

					Figura = new Figura_T() ;
					break ;

				case 9:

					Figura = new Figura_L_Normalne() ;
					break ;

				case 10:

					Figura = new Figura_L_Odwrocona() ;
					break ;
			}

			Random = rand() % 11 ;

			switch(Random)
			{
				case 0:

					Next = new Figura_Kwadrat() ;
					break ;

				case 1:

					Next = new Figura_Linia_Duza() ;
					break ;

				case 2:

					Next = new Figura_Kropka() ;
					break ;

				case 3:

					Next = new Figura_Linia_Mala() ;
					break ;

				case 4:

					Next = new Figura_Linia_Srednia() ;
					break ;

				case 5:

					Next = new Figura_Zawijak_Prawy() ;
					break ;

				case 6:

					Next = new Figura_Zawijak_Lewy() ;
					break ;

				case 7:

					Next = new Figura_Trojkat() ;
					break ;

				case 8:

					Next = new Figura_T() ;
					break ;

				case 9:

					Next = new Figura_L_Normalne() ;
					break ;

				case 10:

					Next = new Figura_L_Odwrocona() ;
					break ;
			}

		}

	private:

		//MAPA
		std::vector < std::array< DataMap , 10 > > Screen_Map ;
		
		//FIGURA KTORA RUSZAMY ORAZ NASTEPNA
		Figura_Abstract * Figura ;
		Figura_Abstract * Next ;
		//RANDOM DLA FIGUR
		int Random ;

		//DANE DO WYPISANIA NA EKRANIE
		int Point ;
		int Max_Combo ;
		//POMOCNE COMBO
		int Combo ;
		
		//ILOSC SKASOWANYCH LIN (OD TEGO ZALEZY JAK SZYBKO PORUSZA SIE GRA)
		int Line_Delete ;
		//POZIOM
		int LVL ;

		//ILOSC PUNKTOW JAKIE SIE OTRZYMUJE
		int For_Line ;
		int Bonus ;
		
		//ZMIANA INT NA STRING
		std::stringstream Draw_Int ;
};

#endif

