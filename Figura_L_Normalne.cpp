#include "Figura_L_Normalne.h"

bool Figura_L_Normalne::Auto_Down_0 ( const std::vector< std::array<DataMap,10> > & Map )
{
	//JESLI POZYCJA FIGURY + 1 JEST MNIEJSZE OD 16 (15 OSTATNI ELEMENT)
	if( (Figura[3].y + 1) < 16 )
	{
		//SPRAWDZAMY CZE POLE JEST PUSTE
		if( !Map[ (Figura[0].y + 1) ][ Figura[0].x ].Draw &&
			!Map[ (Figura[3].y + 1) ][ Figura[3].x ].Draw )
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

bool Figura_L_Normalne::Auto_Down_1 ( const std::vector< std::array<DataMap,10> > & Map )
{
	//JESLI POZYCJA FIGURY + 1 JEST MNIEJSZE OD 16 (15 OSTATNI ELEMENT)
	if( (Figura[0].y + 1) < 16 )
	{
		//SPRAWDZAMY CZE POLE JEST PUSTE
		if( !Map[ (Figura[0].y + 1) ][ Figura[0].x ].Draw && 
			!Map[ (Figura[3].y + 1) ][ Figura[3].x ].Draw && !Map[ (Figura[2].y + 1) ][ Figura[2].x ].Draw )
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

bool Figura_L_Normalne::Auto_Down_2 ( const std::vector< std::array<DataMap,10> > & Map )
{
	//JESLI POZYCJA FIGURY + 1 JEST MNIEJSZE OD 16 (15 OSTATNI ELEMENT)
	if( (Figura[1].y + 1) < 16 )
	{
		//SPRAWDZAMY CZE POLE JEST PUSTE
		if( !Map[ (Figura[1].y + 1) ][ Figura[1].x ].Draw &&
			!Map[ (Figura[0].y + 1) ][ Figura[0].x ].Draw )
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

bool Figura_L_Normalne::Auto_Down_3 ( const std::vector< std::array<DataMap,10> > & Map )
{
	//JESLI POZYCJA FIGURY + 1 JEST MNIEJSZE OD 16 (15 OSTATNI ELEMENT)
	if( (Figura[2].y + 1) < 16 )
	{
		//SPRAWDZAMY CZE POLE JEST PUSTE
		if( !Map[ (Figura[1].y + 1) ][ Figura[1].x ].Draw && !Map[ (Figura[3].y + 1) ][ Figura[3].x ].Draw && 
			!Map[ (Figura[2].y + 1) ][ Figura[2].x ].Draw )
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

bool Figura_L_Normalne::MoveDown ( const std::vector< std::array<DataMap,10> > & Map )
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

		case 2:

			if( Auto_Down_2 ( Map ) ) 
				return true ;
			break ;

		case 3:

			if( Auto_Down_3 ( Map ) ) 
				return true ;
			break ;
	}
	return false ;
	//ZWRACAMY TRUE JESLI RUCH SIE UDAL A FALSE JESLI NAPOTKAL KONIEC MAPY LUB INNY KLOCEK
}

bool Figura_L_Normalne::Change_Position ( const std::vector< std::array<DataMap,10> > & Map )
{
	//ZMIENNA DO OKRESLENIA POZYCJI
	int check_pos = Position + 1 ;

	if( check_pos >= NumberPosition )
		check_pos = 0 ;

	switch(check_pos)
	{
		case 0:

			if( Figura[2].y - 1 >= 0 )
			{
				if( !Map[ Figura[2].y + 1 ][ Figura[2].x ].Draw && !Map[ Figura[2].y - 1 ][ Figura[2].x ].Draw &&
					!Map[ Figura[2].y - 1 ][ Figura[2].x - 1 ].Draw )
				{
					Figura[0].x = Figura[2].x - 1 ;
					Figura[0].y = Figura[2].y - 1 ;
					Figura[1].x = Figura[2].x     ;
					Figura[1].y = Figura[2].y - 1 ;
					Figura[3].x = Figura[2].x     ;
					Figura[3].y = Figura[2].y + 1 ;
					Position = 0 ;
					return true ;
				}
			}
			else
			{
				if( !Map[ Figura[2].y + 1 ][ Figura[2].x ].Draw )
				{
					Figura[0].x = Figura[2].x - 1 ;
					Figura[0].y = Figura[2].y - 1 ;
					Figura[1].x = Figura[2].x     ;
					Figura[1].y = Figura[2].y - 1 ;
					Figura[3].x = Figura[2].x     ;
					Figura[3].y = Figura[2].y + 1 ;
					Position = 0 ;
					return true ;
				}
			}
			break ;

		case 1:

			if( Figura[2].x + 1 < 10 )
			{
				if( !Map[ Figura[2].y ][ Figura[2].x + 1 ].Draw && !Map[ Figura[2].y + 1 ][ Figura[2].x - 1 ].Draw &&
					!Map[ Figura[2].y ][ Figura[2].x - 1 ].Draw )
				{
					Figura[1].x = Figura[2].x - 1 ;
					Figura[1].y = Figura[2].y     ;
					Figura[0].x = Figura[2].x - 1 ;
					Figura[0].y = Figura[2].y + 1 ;
					Figura[3].x = Figura[2].x + 1 ;
					Figura[3].y = Figura[2].y     ;
					Position = 1 ;
					return true ;
				}
			}
			break ;

		case 2:

			//JESLI FIGURA MIESCI SIE NA PLANSZY
			if( Figura[2].y - 1 >= 0 )
			{
				if( !Map[ Figura[2].y - 1 ][ Figura[2].x ].Draw && !Map[ Figura[2].y + 1 ][ Figura[2].x ].Draw &&
					!Map[ Figura[2].y + 1 ][ Figura[2].x + 1 ].Draw )
				{
					Figura[0].x = Figura[2].x + 1 ;
					Figura[0].y = Figura[2].y + 1 ;
					Figura[1].x = Figura[2].x     ;
					Figura[1].y = Figura[2].y + 1 ;
					Figura[3].x = Figura[2].x     ;
					Figura[3].y = Figura[2].y - 1 ;
					Position = 2 ;
					return true ;
				}
			}
			else
			{
				if( !Map[ Figura[2].y + 1 ][ Figura[2].x ].Draw &&
					!Map[ Figura[2].y + 1 ][ Figura[2].x + 1 ].Draw )
				{
					Figura[0].x = Figura[2].x + 1 ;
					Figura[0].y = Figura[2].y + 1 ;
					Figura[1].x = Figura[2].x     ;
					Figura[1].y = Figura[2].y + 1 ;
					Figura[3].x = Figura[2].x     ;
					Figura[3].y = Figura[2].y - 1 ;
					Position = 2 ;
					return true ;
				}
			}
			break ;

		case 3:

			//JESLI FIGURA MIESCI SIE NA PLANSZY
			if( Figura[2].y - 1 >= 0 )
			{
				if( Figura[2].x - 1 >= 0 )
				{
					if( !Map[ Figura[2].y - 1 ][ Figura[2].x + 1 ].Draw && !Map[ Figura[2].y ][ Figura[2].x + 1 ].Draw &&
						!Map[ Figura[2].y ][ Figura[2].x - 1 ].Draw )
					{
						Figura[0].x = Figura[2].x + 1 ;
						Figura[0].y = Figura[2].y - 1 ;
						Figura[1].x = Figura[2].x + 1 ;
						Figura[1].y = Figura[2].y     ;
						Figura[3].x = Figura[2].x - 1 ;
						Figura[3].y = Figura[2].y     ;
						Position = 3 ;
						return true ;
					}
				}
			}
			else
			{
				if( !Map[ Figura[2].y ][ Figura[2].x + 1 ].Draw &&
					!Map[ Figura[2].y ][ Figura[2].x - 1 ].Draw )
				{
					Figura[0].x = Figura[2].x + 1 ;
					Figura[0].y = Figura[2].y - 1 ;
					Figura[1].x = Figura[2].x + 1 ;
					Figura[1].y = Figura[2].y     ;
					Figura[3].x = Figura[2].x - 1 ;
					Figura[3].y = Figura[2].y     ;
					Position = 3 ;
					return true ;
				}
			}
			break ;

	}
	return false ;
}

bool Figura_L_Normalne::Move_0 ( ALLEGRO_KEYBOARD_STATE &keyState , const std::vector< std::array<DataMap,10> > & Map ) 
{
	if( al_key_down(&keyState , ALLEGRO_KEY_DOWN) )
	{
		//std::cout << "Figura_Kwadrat::Move" << std::endl ;
		if( Figura[3].y + 1 < 16 )
		{
			//std::cout << "Figura_Kwadrat::Move2222222222222222" << std::endl ;
			if( !Map[ (Figura[0].y + 1) ][ Figura[0].x ].Draw &&
			    !Map[ (Figura[3].y + 1) ][ Figura[3].x ].Draw )
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
			if( Figura[2].y - 1 >= 0 )
			{
				if( !Map[ Figura[0].y ][ Figura[0].x - 1 ].Draw && !Map[ Figura[3].y ][ Figura[3].x - 1 ].Draw &&
					!Map[ Figura[2].y ][ Figura[2].x - 1 ].Draw )
				{
					for(int i = 0 ; i < 4 ; i++)
						Figura[i].x = Figura[i].x - 1 ;
					return true ;
				}
			}
			else
			{
				if( !Map[ Figura[3].y ][ Figura[3].x - 1 ].Draw &&
					!Map[ Figura[2].y ][ Figura[2].x - 1 ].Draw )
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
		if( Figura[2].x + 1 < 10 )
		{
			if( Figura[2].y - 1 >= 0 )
			{
				if( !Map[ Figura[3].y ][ Figura[3].x + 1 ].Draw && !Map[ Figura[2].y ][ Figura[2].x + 1 ].Draw &&
					!Map[ Figura[1].y ][ Figura[1].x + 1 ].Draw  ) 
				{
					for(int i = 0 ; i < 4 ; i++)
						Figura[i].x = Figura[i].x + 1 ;
					return true ;
				}
			}
			else
			{
				if( !Map[ Figura[3].y ][ Figura[3].x + 1 ].Draw &&
					!Map[ Figura[2].y ][ Figura[2].x + 1 ].Draw  ) 
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

bool Figura_L_Normalne::Move_1 ( ALLEGRO_KEYBOARD_STATE &keyState , const std::vector< std::array<DataMap,10> > & Map ) 
{
	if( al_key_down(&keyState , ALLEGRO_KEY_DOWN) )
	{
		//std::cout << "Figura_Kwadrat::Move" << std::endl ;
		if( Figura[0].y + 1 < 16 )
		{
			//std::cout << "Figura_Kwadrat::Move2222222222222222" << std::endl ;
			if( !Map[ (Figura[3].y + 1) ][ Figura[3].x ].Draw && !Map[ (Figura[2].y + 1) ][ Figura[2].x ].Draw &&
				!Map[ (Figura[0].y + 1) ][ Figura[0].x ].Draw )
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
		if( Figura[1].x - 1 >= 0 )
		{
			if( !Map[ Figura[1].y ][ Figura[1].x - 1].Draw &&
				!Map[ Figura[0].y ][ Figura[0].x - 1 ].Draw )
			{
				for(int i = 0 ; i < 4 ; i++)
					Figura[i].x = Figura[i].x - 1 ;
				return true ;
			}
		}
	}
	else if( al_key_down(&keyState , ALLEGRO_KEY_RIGHT) )
	{
		//SPRAWDZAMY KAZDA MOZLIWOSC (POZA PLANSZA)
		if( Figura[3].x + 1 < 10 )
		{
			if( !Map[ Figura[0].y ][ Figura[0].x + 1 ].Draw &&
				!Map[ Figura[3].y ][ Figura[3].x + 1 ].Draw )
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

bool Figura_L_Normalne::Move_2 ( ALLEGRO_KEYBOARD_STATE &keyState , const std::vector< std::array<DataMap,10> > & Map ) 
{
	if( al_key_down(&keyState , ALLEGRO_KEY_DOWN) )
	{
		//std::cout << "Figura_Kwadrat::Move" << std::endl ;
		if( Figura[1].y + 1 < 16 )
		{
			//std::cout << "Figura_Kwadrat::Move2222222222222222" << std::endl ;
			if( !Map[ (Figura[0].y + 1) ][ Figura[0].x ].Draw && !Map[ (Figura[1].y + 1) ][ Figura[1].x ].Draw )
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
		if( Figura[1].x - 1 >= 0 )
		{
			if( Figura[3].y >= 0 )
			{
				if( !Map[ Figura[1].y ][ Figura[1].x - 1 ].Draw && !Map[ Figura[3].y ][ Figura[3].x - 1 ].Draw && 
					!Map[ Figura[2].y ][ Figura[2].x - 1 ].Draw )
				{
					for(int i = 0 ; i < 4 ; i++)
						Figura[i].x = Figura[i].x - 1 ;
					return true ;
				}
			}
			else
			{
				if( !Map[ Figura[1].y ][ Figura[1].x - 1 ].Draw && !Map[ Figura[2].y ][ Figura[2].x - 1 ].Draw )
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
		if( Figura[0].x + 1 < 10 )
		{
			if( Figura[3].y >= 0 )
			{
				if( !Map[ Figura[0].y ][ Figura[0].x + 1 ].Draw && !Map[ Figura[3].y ][ Figura[3].x + 1 ].Draw && 
					!Map[ Figura[2].y ][ Figura[2].x + 1 ].Draw ) 
				{
					for(int i = 0 ; i < 4 ; i++)
						Figura[i].x = Figura[i].x + 1 ;
					return true ;
				}
			}
			else
			{
				if( !Map[ Figura[0].y ][ Figura[0].x + 1 ].Draw && !Map[ Figura[2].y ][ Figura[2].x + 1 ].Draw ) 
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

bool Figura_L_Normalne::Move_3 ( ALLEGRO_KEYBOARD_STATE &keyState , const std::vector< std::array<DataMap,10> > & Map ) 
{
	if( al_key_down(&keyState , ALLEGRO_KEY_DOWN) )
	{
		//std::cout << "Figura_Kwadrat::Move" << std::endl ;
		if( Figura[2].y + 1 < 16 )
		{
			//std::cout << "Figura_Kwadrat::Move2222222222222222" << std::endl ;
			if( !Map[ (Figura[1].y + 1) ][ Figura[1].x ].Draw && !Map[ (Figura[3].y + 1) ][ Figura[3].x ].Draw && 
				!Map[ (Figura[2].y + 1) ][ Figura[2].x ].Draw )
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
			if( !Map[ Figura[3].y ][ Figura[3].x - 1].Draw &&
				!Map[ Figura[0].y ][ Figura[0].x - 1 ].Draw )
			{
				for(int i = 0 ; i < 4 ; i++)
					Figura[i].x = Figura[i].x - 1 ;
				return true ;
			}
		}
	}
	else if( al_key_down(&keyState , ALLEGRO_KEY_RIGHT) )
	{
		//SPRAWDZAMY KAZDA MOZLIWOSC (POZA PLANSZA)
		if( Figura[1].x + 1 < 10 )
		{
			if( !Map[ Figura[1].y ][ Figura[1].x + 1 ].Draw &&
				!Map[ Figura[0].y ][ Figura[0].x + 1 ].Draw )
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

bool Figura_L_Normalne::Move ( ALLEGRO_KEYBOARD_STATE &keyState , const std::vector< std::array<DataMap,10> > & Map )
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

		case 2:

			if( Move_2 ( keyState , Map ) )
				return true ;
			break ;

		case 3:

			if( Move_3 ( keyState , Map ) )
				return true ;
			break ;
	}
	//ZWRACAMY TRUE JAK RUCH SIE UDAL A FALSE JAK NAPOTKALOSMY KOLIZJE
	return false ;
}

void Figura_L_Normalne::DrawBlock ()
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

void Figura_L_Normalne::DrawNext ()
{
	switch(Position)
	{

		case 0:

			al_draw_filled_rectangle( 625 , 25 , 675 , 75 , Figura[0].color ) ;
			al_draw_rectangle		( 625 , 25 , 675 , 75 , al_map_rgb( 0 , 0 , 0 ) , 5) ;
	
			al_draw_filled_rectangle( 675 , 25 , 725 , 75 , Figura[0].color ) ;
			al_draw_rectangle		( 675 , 25 , 725 , 75 , al_map_rgb( 0 , 0 , 0 ) , 5) ;

			al_draw_filled_rectangle( 675 , 75 , 725 , 125 , Figura[0].color ) ;
			al_draw_rectangle		( 675 , 75 , 725 , 125 , al_map_rgb( 0 , 0 , 0 ) , 5) ;

			al_draw_filled_rectangle( 675 , 125 , 725 , 175 , Figura[0].color ) ;
			al_draw_rectangle		( 675 , 125 , 725 , 175 , al_map_rgb( 0 , 0 , 0 ) , 5) ;
			break ;

		case 1:

	
			al_draw_filled_rectangle( 625 , 75 , 675 , 125 , Figura[0].color ) ;
			al_draw_rectangle		( 625 , 75 , 675 , 125 , al_map_rgb( 0 , 0 , 0 ) , 5) ;

			al_draw_filled_rectangle( 625 , 125 , 675 , 175 , Figura[0].color ) ;
			al_draw_rectangle		( 625 , 125 , 675 , 175 , al_map_rgb( 0 , 0 , 0 ) , 5) ;

			al_draw_filled_rectangle( 675 , 75 , 725 , 125 , Figura[0].color ) ;
			al_draw_rectangle		( 675 , 75 , 725 , 125 , al_map_rgb( 0 , 0 , 0 ) , 5) ;
			
			al_draw_filled_rectangle( 725 , 75 , 775 , 125 , Figura[0].color ) ;
			al_draw_rectangle		( 725 , 75 , 775 , 125 , al_map_rgb( 0 , 0 , 0 ) , 5) ;
			break ;

		case 2:

			al_draw_filled_rectangle( 675 , 25 , 725 , 75 , Figura[0].color ) ;
			al_draw_rectangle		( 675 , 25 , 725 , 75 , al_map_rgb( 0 , 0 , 0 ) , 5) ;

			al_draw_filled_rectangle( 675 , 75 , 725 , 125 , Figura[0].color ) ;
			al_draw_rectangle		( 675 , 75 , 725 , 125 , al_map_rgb( 0 , 0 , 0 ) , 5) ;

			al_draw_filled_rectangle( 675 , 125 , 725 , 175 , Figura[0].color ) ;
			al_draw_rectangle		( 675 , 125 , 725 , 175 , al_map_rgb( 0 , 0 , 0 ) , 5) ;

			al_draw_filled_rectangle( 725 , 125 , 775 , 175 , Figura[0].color ) ;
			al_draw_rectangle		( 725 , 125 , 775 , 175 , al_map_rgb( 0 , 0 , 0 ) , 5) ;
			break ;

		case 3:

			al_draw_filled_rectangle( 625 , 75 , 675 , 125 , Figura[0].color ) ;
			al_draw_rectangle		( 625 , 75 , 675 , 125 , al_map_rgb( 0 , 0 , 0 ) , 5) ;

			al_draw_filled_rectangle( 675 , 75 , 725 , 125 , Figura[0].color ) ;
			al_draw_rectangle		( 675 , 75 , 725 , 125 , al_map_rgb( 0 , 0 , 0 ) , 5) ;
	
			al_draw_filled_rectangle( 725 , 25 , 775 , 75 , Figura[0].color ) ;
			al_draw_rectangle		( 725 , 25 , 775 , 75 , al_map_rgb( 0 , 0 , 0 ) , 5) ;

			al_draw_filled_rectangle( 725 , 75 , 775 , 125 , Figura[0].color ) ;
			al_draw_rectangle		( 725 , 75 , 775 , 125 , al_map_rgb( 0 , 0 , 0 ) , 5) ;

			break ;
	}
}

bool Figura_L_Normalne::Colision ( const std::vector< std::array<DataMap,10> > & Map )
{
	//SPRAWDZAMY KOLIZJE DLA KAZDEJ POZYCJI
	switch(Position)
	{
		case 0:

			if( Figura[3].y == 15 || Map[ Figura[0].y + 1 ][ Figura[0].x ].Draw ||
				Map[ Figura[3].y + 1 ][ Figura[3].x ].Draw )
				return true ;
			break ;

		case 1:

			if( Figura[0].y == 15 || Map[ Figura[3].y + 1 ][ Figura[3].x ].Draw || Map[ Figura[2].y + 1 ][ Figura[2].x ].Draw ||
				Map[ Figura[0].y + 1 ][ Figura[0].x ].Draw )
				return true ;
			break ;

		case 2:

			if( Figura[1].y == 15 || Map[ Figura[0].y + 1 ][ Figura[0].x ].Draw || Map[ Figura[1].y + 1 ][ Figura[1].x ].Draw )
				return true ;
			break ;

		case 3:

			if( Figura[2].y == 15 || Map[ Figura[1].y + 1 ][ Figura[1].x ].Draw || Map[ Figura[2].y + 1 ][ Figura[2].x ].Draw ||
				Map[ Figura[3].y + 1 ][ Figura[3].x ].Draw )
				return true ;
			break ;
	}
	return false ;
}

const std::vector< DataBlock > Figura_L_Normalne::ReturnDataBlock ()
{
	return Figura ;
}
