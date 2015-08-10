#include "Figura_Linia_Duza.h"

bool Figura_Linia_Duza::Auto_Down_0 ( const std::vector< std::array<DataMap,10> > & Map )
{
	//JESLI POZYCJA FIGURY + 1 JEST MNIEJSZE OD 16 (15 OSTATNI ELEMENT)
	if( (Figura[3].y + 1) < 16 )
	{
		//SPRAWDZAMY CZE POLE JEST PUSTE
		if( !Map[ (Figura[0].y + 1) ][ Figura[0].x ].Draw && !Map[ (Figura[1].y + 1) ][ Figura[1].x ].Draw &&
			!Map[ (Figura[2].y + 1) ][ Figura[2].x ].Draw && !Map[ (Figura[3].y + 1) ][ Figura[3].x ].Draw )
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
}

bool Figura_Linia_Duza::Auto_Down_1 ( const std::vector< std::array<DataMap,10> > & Map )
{
	//JESLI POZYCJA FIGURY + 1 JEST MNIEJSZE OD 16 (15 OSTATNI ELEMENT)
	if( (Figura[3].y + 1) < 16 )
	{
		//SPRAWDZAMY CZE POLE JEST PUSTE
		if( !Map[ (Figura[3].y + 1) ][ Figura[3].x ].Draw )
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
}

bool Figura_Linia_Duza::MoveDown ( const std::vector< std::array<DataMap,10> > & Map )
{
	//DLA KAZDEJ POZYCJI ODZIELNE OBLICZENIA
	switch(Position)
	{
		case 0:

			if( Auto_Down_0 ( Map ) ) 
				return true ;
			break ;

		case 1:

			if( Auto_Down_1 ( Map ) ) 
				return true ;
			break ;
	}
	return false ;
	//ZWRACAMY TRUE JESLI RUCH SIE UDAL A FALSE JESLI NAPOTKAL KONIEC MAPY LUB INNY KLOCEK
}

bool Figura_Linia_Duza::Change_Position ( const std::vector< std::array<DataMap,10> > & Map )
{
	//ZMIENNA DO OKRESLENIA POZYCJI
	int check_pos = Position + 1 ;

	if( check_pos >= NumberPosition )
		check_pos = 0 ;

	switch(check_pos)
	{
		case 0:

			//JESLI FIGURA MIESCI SIE NA PLANSZY
			if( Figura[3].x - 3 >= 0 )
			{
				if( !Map[ Figura[3].y ][ Figura[3].x - 1 ].Draw && !Map[ Figura[3].y ][ Figura[3].x - 2 ].Draw &&
					!Map[ Figura[3].y ][ Figura[3].x - 3 ].Draw )
				{
					Figura[2].x = Figura[3].x - 1 ;
					Figura[2].y = Figura[3].y	  ;
					Figura[1].x = Figura[3].x - 2 ;
					Figura[1].y = Figura[3].y	  ;
					Figura[0].x = Figura[3].x - 3 ;
					Figura[0].y = Figura[3].y	  ;
					Position = 0 ;
					return true ;
				}
			}
			break ;

		case 1:

			//JESLI FIGURA MIESCI SIE NA PLANSZY
			if( Figura[3].y - 3 >= 0 )
			{
				if( !Map[ (Figura[3].y - 1) ][ Figura[3].x ].Draw && !Map[ (Figura[3].y - 2) ][ Figura[3].x ].Draw &&
					!Map[ (Figura[3].y - 3) ][ Figura[3].x ].Draw )
				{
					Figura[2].y = Figura[3].y - 1 ;
					Figura[2].x = Figura[3].x	  ;
					Figura[1].y = Figura[3].y - 2 ;
					Figura[1].x = Figura[3].x	  ;
					Figura[0].y = Figura[3].y - 3 ;
					Figura[0].x = Figura[3].x	  ;
					Position = 1 ;
					return true ;
				}
			}
			//3 ELEMENTY NA PLANSZY
			else if( Figura[3].y - 2 >= 0 )
			{
				if( !Map[ (Figura[3].y - 1) ][ Figura[3].x ].Draw && !Map[ (Figura[3].y - 2) ][ Figura[3].x ].Draw )
				{
					Figura[2].y = Figura[3].y - 1 ;
					Figura[2].x = Figura[3].x	  ;
					Figura[1].y = Figura[3].y - 2 ;
					Figura[1].x = Figura[3].x	  ;
					Figura[0].y = Figura[3].y - 3 ;
					Figura[0].x = Figura[3].x	  ;
					Position = 1 ;
					return true ;
				}
			}
			//2 ELEMENTY NA PLANSZY
			else if( Figura[3].y - 1 >= 0 )
			{
				if( !Map[ (Figura[3].y - 1) ][ Figura[3].x ].Draw )
				{
					Figura[2].y = Figura[3].y - 1 ;
					Figura[2].x = Figura[3].x	  ;
					Figura[1].y = Figura[3].y - 2 ;
					Figura[1].x = Figura[3].x	  ;
					Figura[0].y = Figura[3].y - 3 ;
					Figura[0].x = Figura[3].x	  ;
					Position = 1 ;
					return true ;
				}
			}
			break ;
	}
	return false ;
}

bool Figura_Linia_Duza::Move_0 ( ALLEGRO_KEYBOARD_STATE &keyState , const std::vector< std::array<DataMap,10> > & Map ) 
{
	if( al_key_down(&keyState , ALLEGRO_KEY_DOWN) )
	{
		//std::cout << "Figura_Kwadrat::Move" << std::endl ;
		if( Figura[3].y + 1 < 16 )
		{
			//std::cout << "Figura_Kwadrat::Move2222222222222222" << std::endl ;
			if( !Map[ (Figura[0].y + 1) ][ Figura[0].x ].Draw && !Map[ (Figura[1].y + 1) ][ Figura[1].x ].Draw &&
			    !Map[ (Figura[2].y + 1) ][ Figura[2].x ].Draw && !Map[ (Figura[3].y + 1) ][ Figura[3].x ].Draw )
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
		if( Figura[0].x - 1 >= 0 )
		{
			if( !Map[ Figura[0].y ][ Figura[0].x - 1 ].Draw )
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
			if( !Map[ Figura[3].y ][ Figura[3].x + 1 ].Draw ) 
			{
				for(int i = 0 ; i < 4 ; i++)
					Figura[i].x = Figura[i].x + 1 ;
				return true ;
			}
		}
	}
	//ZMIANA POZYCJI
	else if( Change_Position1 )
	{
		if( al_key_down(&keyState , ALLEGRO_KEY_SPACE) )
		{
			if( Change_Position ( Map ) )
			{
				Change_Position1 = false ;
				return true ;
			}
		}
	}
	return false ;
}

bool Figura_Linia_Duza::Move_1 ( ALLEGRO_KEYBOARD_STATE &keyState , const std::vector< std::array<DataMap,10> > & Map ) 
{
	if( al_key_down(&keyState , ALLEGRO_KEY_DOWN) )
	{
		//std::cout << "Figura_Kwadrat::Move" << std::endl ;
		if( Figura[3].y + 1 < 16 )
		{
			//std::cout << "Figura_Kwadrat::Move2222222222222222" << std::endl ;
			if( !Map[ (Figura[3].y + 1) ][ Figura[3].x ].Draw )
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
		//SPRAWDZAMY KAZDA MOZLIWOSC (POZA PLANSZA)
		if( Figura[3].x - 1 >= 0 )
		{
			if( Figura[0].y >= 0 )
			{
				if( !Map[ Figura[0].y ][ Figura[0].x - 1 ].Draw && !Map[ Figura[1].y ][ Figura[1].x - 1].Draw &&
					!Map[ Figura[2].y ][ Figura[2].x - 1 ].Draw && !Map[ Figura[3].y ][ Figura[3].x - 1].Draw )
				{
					for(int i = 0 ; i < 4 ; i++)
						Figura[i].x = Figura[i].x - 1 ;
					return true ;
				}
			}
			else if( Figura[1].y == 0 )
			{
				if( !Map[ Figura[1].y ][ Figura[1].x - 1].Draw &&
					!Map[ Figura[2].y ][ Figura[2].x - 1 ].Draw && !Map[ Figura[3].y ][ Figura[3].x - 1].Draw )
				{
					for(int i = 0 ; i < 4 ; i++)
						Figura[i].x = Figura[i].x - 1 ;
					return true ;
				}
			}
			else if( Figura[2].y == 0 )
			{
				if( !Map[ Figura[2].y ][ Figura[2].x - 1 ].Draw && !Map[ Figura[3].y ][ Figura[3].x - 1].Draw )
				{
					for(int i = 0 ; i < 4 ; i++)
						Figura[i].x = Figura[i].x - 1 ;
					return true ;
				}
			}
		}
	}
	else if( al_key_down(&keyState , ALLEGRO_KEY_RIGHT) )
	{
		//SPRAWDZAMY KAZDA MOZLIWOSC (POZA PLANSZA)
		if( Figura[3].x + 1 < 10 )
		{
			if( Figura[0].y >= 0 )
			{
				if( !Map[ Figura[0].y ][ Figura[0].x + 1 ].Draw && !Map[ Figura[1].y ][ Figura[1].x + 1 ].Draw &&
					!Map[ Figura[2].y ][ Figura[2].x + 1 ].Draw && !Map[ Figura[3].y ][ Figura[3].x + 1 ].Draw )
				{
					for(int i = 0 ; i < 4 ; i++)
						Figura[i].x = Figura[i].x + 1 ;
					return true ;
				}
			}
			else if( Figura[1].y == 0 )
			{
				if( !Map[ Figura[1].y ][ Figura[1].x + 1 ].Draw &&
					!Map[ Figura[2].y ][ Figura[2].x + 1 ].Draw && !Map[ Figura[3].y ][ Figura[3].x + 1 ].Draw )
				{
					for(int i = 0 ; i < 4 ; i++)
						Figura[i].x = Figura[i].x + 1 ;
					return true ;
				}
			}
			else if( Figura[2].y == 0 )
			{
				if( !Map[ Figura[2].y ][ Figura[2].x + 1 ].Draw && !Map[ Figura[3].y ][ Figura[3].x + 1 ].Draw )
				{
					for(int i = 0 ; i < 4 ; i++)
						Figura[i].x = Figura[i].x + 1 ;
					return true ;
				}
			}
		}
	}
	//ZMIANA POZYCJI
	else if( Change_Position1 )
	{
		if( al_key_down(&keyState , ALLEGRO_KEY_SPACE) )
		{
			if( Change_Position ( Map ) )
			{
				Change_Position1 = false ;
				return true ;
			}
		}
	}
	return false ;
}

bool Figura_Linia_Duza::Move ( ALLEGRO_KEYBOARD_STATE &keyState , const std::vector< std::array<DataMap,10> > & Map )
{

	switch(Position)
	{
		case 0:
	
			if( Move_0 ( keyState , Map ) )
				return true ;
			break ;

		case 1:

			if( Move_1 ( keyState , Map ) )
				return true ;
			break ;
	}
	//ZWRACAMY TRUE JAK RUCH SIE UDAL A FALSE JAK NAPOTKALOSMY KOLIZJE
	return false ;
}

void Figura_Linia_Duza::DrawBlock ()
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

void Figura_Linia_Duza::DrawNext ()
{
	switch(Position)
	{

		case 0:

			al_draw_filled_rectangle( 600 , 75 , 650 , 125 , Figura[0].color ) ;
			al_draw_rectangle		( 600 , 75 , 650 , 125 , al_map_rgb( 0 , 0 , 0 ) , 5) ;
	
			al_draw_filled_rectangle( 650 , 75 , 700 , 125 , Figura[0].color ) ;
			al_draw_rectangle		( 650 , 75 , 700 , 125 , al_map_rgb( 0 , 0 , 0 ) , 5) ;

			al_draw_filled_rectangle( 700 , 75 , 750 , 125 , Figura[0].color ) ;
			al_draw_rectangle		( 700 , 75 , 750 , 125 , al_map_rgb( 0 , 0 , 0 ) , 5) ;

			al_draw_filled_rectangle( 750 , 75 , 800 , 125 , Figura[0].color ) ;
			al_draw_rectangle		( 750 , 75 , 800 , 125 , al_map_rgb( 0 , 0 , 0 ) , 5) ;
			break ;

		case 1:

			al_draw_filled_rectangle( 675 , 0 , 725 , 50 , Figura[0].color ) ;
			al_draw_rectangle		( 675 , 0 , 725 , 50 , al_map_rgb( 0 , 0 , 0 ) , 5) ;
	
			al_draw_filled_rectangle( 675 , 50 , 725 , 100 , Figura[0].color ) ;
			al_draw_rectangle		( 675 , 50 , 725 , 100 , al_map_rgb( 0 , 0 , 0 ) , 5) ;

			al_draw_filled_rectangle( 675 , 100 , 725 , 150 , Figura[0].color ) ;
			al_draw_rectangle		( 675 , 100 , 725 , 150 , al_map_rgb( 0 , 0 , 0 ) , 5) ;

			al_draw_filled_rectangle( 675 , 150 , 725 , 200 , Figura[0].color ) ;
			al_draw_rectangle		( 675 , 150 , 725 , 200 , al_map_rgb( 0 , 0 , 0 ) , 5) ;
			break ;
	}
}

bool Figura_Linia_Duza::Colision ( const std::vector< std::array<DataMap,10> > & Map )
{
	if( Figura[3].y == 15 )
		return true ;

	else if( Figura[3].y + 1 < 16 )
	{
		//SPRAWDZAMY KOLIZJE DLA KAZDEJ POZYCJI
		switch(Position)
		{
			case 0:

				if( Map[ Figura[0].y + 1 ][ Figura[0].x ].Draw || Map[ Figura[1].y + 1 ][ Figura[1].x ].Draw ||
					Map[ Figura[2].y + 1 ][ Figura[2].x ].Draw || Map[ Figura[3].y + 1 ][ Figura[3].x ].Draw )
					return true ;
				break ;

			case 1:

				if( Map[ Figura[3].y + 1 ][ Figura[3].x ].Draw )
					return true ;
				break ;
		}
	}
	return false ;
}

const std::vector< DataBlock > Figura_Linia_Duza::ReturnDataBlock ()
{
	return Figura ;
}
