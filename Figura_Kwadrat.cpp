#include "Figura_Kwadrat.h"


bool Figura_Kwadrat::MoveDown ( const std::vector< std::array<DataMap,10> > & Map )
{
	
	//JESLI POZYCJA FIGURY + 1 JEST MNIEJSZE OD 16 (15 OSTATNI ELEMENT)
	if( (Figura[2].y + 1) < 16 )
	{
		//SPRAWDZAMY CZE POLE JEST PUSTE
		if( !Map[ (Figura[2].y + 1) ][ Figura[2].x ].Draw && !Map[ (Figura[3].y + 1) ][ Figura[3].x ].Draw )
		{
			for(int i = 0 ; i < 4 ; i++)
			{
				//std::cout << "Figura[" << i << "].y = " << Figura[i].y << std::endl ;
				Figura[i].y += 1 ;
			}
			return true ;
		}
	}
	return false ;
	//ZWRACAMY TRUE JESLI RUCH SIE UDAL A FALSE JESLI NAPOTKAL KONIEC MAPY LUB INNY KLOCEK
}

bool Figura_Kwadrat::Move ( ALLEGRO_KEYBOARD_STATE &keyState , const std::vector< std::array<DataMap,10> > & Map )
{
	
	if( al_key_down(&keyState , ALLEGRO_KEY_DOWN) )
	{
		//std::cout << "Figura_Kwadrat::Move" << std::endl ;
		if( Figura[2].y + 1 < 16 )
		{
			//std::cout << "Figura_Kwadrat::Move2222222222222222" << std::endl ;
			if( !Map[ Figura[2].y + 1 ][ Figura[2].x ].Draw && !Map[ Figura[3].y + 1 ][ Figura[3].x ].Draw )
			{

				//std::cout << "Figura_Kwadrat::Move3333333333333333333333" << std::endl ;
				for(int i = 0 ; i < 4 ; i++)
				{
					Figura[i].y = Figura[i].y + 1 ;
				}
				return true ;
			}
		}
	}
	else if( al_key_down(&keyState , ALLEGRO_KEY_LEFT) )
	{
		if( Figura[2].x - 1 >= 0 )
		{
			if( !Map[ Figura[0].y ][ Figura[0].x - 1 ].Draw && !Map[ Figura[2].y ][ Figura[2].x - 1 ].Draw )
			{
				for(int i = 0 ; i < 4 ; i++)
					Figura[i].x = Figura[i].x - 1 ;
				return true ;
			}
		}
	}
	else if( al_key_down(&keyState , ALLEGRO_KEY_RIGHT) )
	{
		if( Figura[3].x + 1 < 10 )
		{
			if( !Map[ Figura[1].y ][ Figura[1].x + 1 ].Draw && !Map[ Figura[3].y ][ Figura[3].x + 1 ].Draw )
			{
				for(int i = 0 ; i < 4 ; i++)
					Figura[i].x = Figura[i].x + 1 ;
				return true ;
			}
		}
	}
	//ZWRACAMY TRUE JAK RUCH SIE UDAL A FALSE JAK NAPOTKALOSMY KOLIZJE
	return false ;
}

void Figura_Kwadrat::DrawBlock ()
{
	for(int i = 0 ; i < 4 ; i++)
	{
		if( Figura[i].y > 0 )
		{
			al_draw_filled_rectangle( (Figura[i].x * 40) + 100 , (Figura[i].y - 1) * 40 , 
					      			  (Figura[i].x * 40) + 140 , Figura[i].y * 40 , Figura[i].color) ;
			al_draw_rectangle		( (Figura[i].x * 40) + 100 , (Figura[i].y - 1) * 40 , 
									  (Figura[i].x * 40) + 140 , Figura[i].y * 40 , al_map_rgb( 220 , 220 , 220 ) , 2) ;
		}
	}
}

void Figura_Kwadrat::DrawNext ()
{
	al_draw_filled_rectangle( 650 , 50 , 700 , 100 , Figura[0].color ) ;
	al_draw_rectangle		( 650 , 50 , 700 , 100 , al_map_rgb( 0 , 0 , 0 ) , 5) ;
	
	al_draw_filled_rectangle( 700 , 50 , 750 , 100 , Figura[0].color ) ;
	al_draw_rectangle		( 700 , 50 , 750 , 100 , al_map_rgb( 0 , 0 , 0 ) , 5) ;

	al_draw_filled_rectangle( 650 , 100 , 700 , 150 , Figura[0].color ) ;
	al_draw_rectangle		( 650 , 100 , 700 , 150 , al_map_rgb( 0 , 0 , 0 ) , 5) ;

	al_draw_filled_rectangle( 700 , 100 , 750 , 150 , Figura[0].color ) ;
	al_draw_rectangle		( 700 , 100 , 750 , 150 , al_map_rgb( 0 , 0 , 0 ) , 5) ;
}

bool Figura_Kwadrat::Colision ( const std::vector< std::array<DataMap,10> > & Map )
{
	if( Figura[2].y == 15 )
		return true ;

	else if( Figura[2].y + 1 < 16 )
	{
		if( Map[ Figura[2].y + 1 ][ Figura[2].x ].Draw || Map[ Figura[3].y + 1 ][ Figura[3].x ].Draw )
			return true ;
	}
	return false ;
}

const std::vector< DataBlock > Figura_Kwadrat::ReturnDataBlock ()
{
	return Figura ;
}
