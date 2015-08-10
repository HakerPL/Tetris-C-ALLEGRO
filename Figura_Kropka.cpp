#include "Figura_Kropka.h"

bool Figura_Kropka::MoveDown ( const std::vector< std::array<DataMap,10> > & Map )
{
	
	//JESLI POZYCJA FIGURY + 1 JEST MNIEJSZE OD 16 (15 OSTATNI ELEMENT)
	if( (Figura[0].y + 1) < 16 )
	{
		//SPRAWDZAMY CZE POLE JEST PUSTE
		if( !Map[ (Figura[0].y + 1) ][ Figura[0].x ].Draw )
		{
			Figura[0].y++ ;
			return true ;
		}
	}
	return false ;
	//ZWRACAMY TRUE JESLI RUCH SIE UDAL A FALSE JESLI NAPOTKAL KONIEC MAPY LUB INNY KLOCEK
}

bool Figura_Kropka::Move ( ALLEGRO_KEYBOARD_STATE &keyState , const std::vector< std::array<DataMap,10> > & Map )
{
	
	if( al_key_down(&keyState , ALLEGRO_KEY_DOWN) )
	{
		//std::cout << "Figura_Kwadrat::Move" << std::endl ;
		if( Figura[0].y + 1 < 16 )
		{
			//std::cout << "Figura_Kwadrat::Move2222222222222222" << std::endl ;
			if( !Map[ Figura[0].y + 1 ][ Figura[0].x ].Draw )
			{
				Figura[0].y++ ;
				return true ;
			}
		}
	}
	else if( al_key_down(&keyState , ALLEGRO_KEY_LEFT) )
	{
		if( Figura[0].x - 1 >= 0 )
		{
			if( !Map[ Figura[0].y ][ Figura[0].x - 1 ].Draw )
			{
				Figura[0].x-- ;
				return true ;
			}
		}
	}
	else if( al_key_down(&keyState , ALLEGRO_KEY_RIGHT) )
	{
		if( Figura[0].x + 1 < 10 )
		{
			if( !Map[ Figura[0].y ][ Figura[0].x + 1 ].Draw )
			{
				Figura[0].x++ ;
				return true ;
			}
		}
	}
	//ZWRACAMY TRUE JAK RUCH SIE UDAL A FALSE JAK NAPOTKALOSMY KOLIZJE
	return false ;
}

void Figura_Kropka::DrawBlock ()
{
	if( Figura[0].y > 0 )
	{
		al_draw_filled_rectangle( (Figura[0].x * 40) + 100 , (Figura[0].y - 1) * 40 , 
					      			(Figura[0].x * 40) + 140 , Figura[0].y * 40 , Figura[0].color) ;
		al_draw_rectangle		( (Figura[0].x * 40) + 100 , (Figura[0].y - 1) * 40 , 
									(Figura[0].x * 40) + 140 , Figura[0].y * 40 , al_map_rgb( 220 , 220 , 220 ) , 2) ;
	}
}

void Figura_Kropka::DrawNext ()
{
	al_draw_filled_rectangle( 675 , 75 , 725 , 125 , Figura[0].color ) ;
	al_draw_rectangle		( 675 , 75 , 725 , 125 , al_map_rgb( 0 , 0 , 0 ) , 5) ;
}

bool Figura_Kropka::Colision ( const std::vector< std::array<DataMap,10> > & Map )
{
	if( Figura[0].y == 15 )
		return true ;

	else if( Figura[0].y + 1 < 16 )
	{
		if( Map[ Figura[0].y + 1 ][ Figura[0].x ].Draw )
			return true ;
	}
	return false ;
}

const std::vector< DataBlock > Figura_Kropka::ReturnDataBlock ()
{
	return Figura ;
}
