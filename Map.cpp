#include "Map.h"
//#include <ctime>
//#include <algorithm>
//#include <iostream>

void Map::Draw_Map () 
{
	//RYSUJEMY MAPE
	for( int y = 1 ; y < 16 ; y++ )
		for( int x = 0 ; x < 10 ; x++ )
		{
			if( Screen_Map[y][x].Draw )
			{
				al_draw_filled_rectangle( (40 * x ) + 100 , 40 * ( y - 1 ) , 
										 (40 * x ) + 140 , 40 * y , Screen_Map[y][x].color ) ;
				al_draw_rectangle		( (40 * x ) + 100 , 40 * ( y - 1 ) , 
										 (40 * x ) + 140 , 40 * y , al_map_rgb( 220 , 220 , 220 ) , 2) ;
			}
			else
			{
				al_draw_filled_rectangle( (40 * x ) + 100 , 40 * ( y - 1 ) , 
										 (40 * x ) + 140 , 40 * y , al_map_rgb( 0 , 0 , 0 ) ) ;
				al_draw_rectangle		( (40 * x ) + 100 , 40 * ( y - 1 ) , 
										 (40 * x ) + 140 , 40 * y , al_map_rgb( 220 , 220 , 220 ) , 2) ;
			}
		}

	//RYSUJEMY CO BEDZIE NASTEPNE
	Next->DrawNext() ;
	//RYSUJEMY KLOCEK NA MAPIE
	Figura->DrawBlock() ;

	//WYPISUJEMY PUNKTY I MAX_COMBO NA EKRANIE
	Draw_Int << Point ;

	al_draw_text( Font_Smal , al_map_rgb(255 , 0 , 0) , 600 , 220 , ALLEGRO_ALIGN_LEFT , "PLAYER POINTS" ) ;
	al_draw_text( Font_Smal , al_map_rgb(255 , 0 , 0) , 600 , 250 , ALLEGRO_ALIGN_LEFT , Draw_Int.str().c_str() ) ;

	//CZYSZCZENIE STRINGSTREAM
	Draw_Int.str( std::string() ) ;
	Draw_Int.clear() ;

	Draw_Int << Max_Combo ;

	al_draw_text( Font_Smal , al_map_rgb(255 , 0 , 0) , 600 , 300 , ALLEGRO_ALIGN_LEFT , "BEST COMBO" ) ;
	al_draw_text( Font_Smal , al_map_rgb(255 , 0 , 0) , 600 , 330 , ALLEGRO_ALIGN_LEFT , Draw_Int.str().c_str() ) ;

	//CZYSZCZENIE STRINGSTREAM
	Draw_Int.str( std::string() ) ;
	Draw_Int.clear() ;

	Draw_Int << LVL ;

	al_draw_text( Font_Smal , al_map_rgb(255 , 0 , 0) , 0 , 0 , ALLEGRO_ALIGN_LEFT , "POZIOM" ) ;
	al_draw_text( Font_Smal , al_map_rgb(255 , 0 , 0) , 0 , 30 , ALLEGRO_ALIGN_LEFT , Draw_Int.str().c_str() ) ;

	//CZYSZCZENIE STRINGSTREAM
	Draw_Int.str( std::string() ) ;
	Draw_Int.clear() ;
}

bool Map::Colision()
{
	//POBIERAMY DANE O FIGURZE
	std::vector< DataBlock > Coordinate = Figura->ReturnDataBlock() ;

	//SPRAWDZAMY CZY KONIEC GRY (FIGURA POZA PLANSZA LUB Y = 0)
	for( int i = 0 ; i < Coordinate.size() ; i++ )
		if( Coordinate[i].y <= 0 )
		{
			for( int i = 0 ; i < Coordinate.size() ; i++ )
			{
				if( Coordinate[i].y > 0 )
				{
					Screen_Map[ Coordinate[i].y ][ Coordinate[i].x ].Draw  = true ;
					Screen_Map[ Coordinate[i].y ][ Coordinate[i].x ].color = Coordinate[i].color ;
				}
			}
			return true ;
		}

	//PRZEPISANIE FIGURY DO MAPY
	for( int i = 0 ; i < Coordinate.size() ; i++ )
	{
		Screen_Map[ Coordinate[i].y ][ Coordinate[i].x ].Draw  = true ;
		Screen_Map[ Coordinate[i].y ][ Coordinate[i].x ].color = Coordinate[i].color ;
	}

	//ZMIENIAMY FIGURE NA NEXT I LOSUJEMY NEXT
	delete Figura ;
	Figura = Next ;

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

	//SPRAWDZAMY LINIE
	if( Check_Line() )
		Down_Line() ;

	return false ;
}

void Map::Down_Line() 
{
	//ZMIENNE DO OBLICZEN
	int Line = 0 ;
	int Lines[31] ;

	//SPRAWDZAMY LINIE
	for( int y = 15 ; y >= 0 ; y-- )
	{
		Line = 0 ;
		for( int x = 0 ; x < 10 ; x++ )
			if( Screen_Map[y][x].Draw )
				Line++ ;

		//1 COS JEST LINIA 0 PUSTA
		if( Line > 0 )
			Lines[y] = 1 ;
		else
			Lines[y] = 0 ;
	}

	//PRZELATUJEMY PO LINIACH I PRZESTAWIAMY KLOCKI W DOL
	while( true )
	{
		for( int y = 15 ; y > 0 ; y-- )
		{
			if( Lines[y] == 0 )
			{
				if( y-1 > 0 && Lines[y-1] == 1 )
				{
					for( int x = 0 ; x < 10 ; x++ )
					{
						Screen_Map[y][x] = Screen_Map[y-1][x] ;
						Screen_Map[y-1][x].Draw = false ;
					}

					Lines[y]   = 1 ;
					Lines[y-1] = 0 ;
				}
				else if( y-2 > 0 && Lines[y-2] == 1 )
				{
					for( int x = 0 ; x < 10 ; x++ )
					{
						Screen_Map[y][x] = Screen_Map[y-2][x] ;
						Screen_Map[y-2][x].Draw = false ;
					}

					Lines[y]   = 1 ;
					Lines[y-2] = 0 ;
				}
				else if( y-3 > 0 && Lines[y-3] == 1 )
				{
					for( int x = 0 ; x < 10 ; x++ )
					{
						Screen_Map[y][x] = Screen_Map[y-3][x] ;
						Screen_Map[y-3][x].Draw = false ;
					}

					Lines[y]   = 1 ;
					Lines[y-3] = 0 ;
				}
				else if( y-4 > 0 && Lines[y-4] == 1 )
				{
					for( int x = 0 ; x < 10 ; x++ )
					{
						Screen_Map[y][x] = Screen_Map[y-4][x] ;
						Screen_Map[y-4][x].Draw = false ;
					}

					Lines[y]   = 1 ;
					Lines[y-4] = 0 ;
				}
			}//if( Lines[y] == 0 )
		}//for( int y = 30 ; y > 0 ; y++ )

		for( int y = 15 ; y > 0 ; y-- )
		{
			if( y - 1 > 0 )
				if( Lines[y] >= Lines[y-1] )
					continue ;
		}

		break ;
	}//while( true )
}

bool Map::Check_Line()
{
	int Line ;

	/*//SPRAWDZAMY CZY COS JEST NA LINI 0 (KONIEC GRY)
	for( int x = 0 ; x < 10 ; x++ )
		if( Screen_Map[0][x].Draw )
		{
			return false ;
		}*/

	//SPRAWDZAMY CZY LINIA JEST PELNA
	for( int y = 1 ; y < 16 ; y++ )
	{ 
		Line = 0 ;

		for( int x = 0 ; x < 10 ; x++ )
			if( Screen_Map[y][x].Draw )
				Line++ ;
		
		if( Line == 10 )
		{
			//JESLI LINIA JEST PELTA TO DODAJEMY PUNKTY KASUJEMY LINIE I INNE OBLICZENIA
			Combo++ ;
			Point += For_Line ;
			Line_Delete++ ;

			for( int i = 0 ; i < 10 ; i++ )
				Screen_Map[y][i].Draw = false ;
		}
	}

	//ZMIENIAMY MAX COMBO NA COMBO
	if( Combo > Max_Combo )
		Max_Combo = Combo ;
	//DODAJEMY PREMIE
	if( Combo > 1 )
		Point += Combo * Bonus ;

	//ZWRACAMY TRUE JAK COS SKASOWALISMY FALSE JAK NIC NIE BYLO
	if( Combo > 0 )
	{
		Combo = 0 ;
		return true ;
	}else 
		return false ;
}
