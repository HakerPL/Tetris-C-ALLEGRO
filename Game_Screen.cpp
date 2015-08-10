#include "Game_Screen.h"


void Game_Screen::Handling_Mouse( ALLEGRO_EVENT &events )
{
	//EVENT MYSZKI
	if(events.type == ALLEGRO_EVENT_MOUSE_AXES)
	{
		x = events.mouse.x ;
		y = events.mouse.y ;

		if( x < 800 && x > 600 && y < 400 && y > 350 )
			Mouse_Select = 1 ;
		else if( x < 800 && x > 600 && y < 450 && y > 400 )
			Mouse_Select = 2 ;
		else
			Mouse_Select = 0 ;

	}//if(events.type == ALLEGRO_EVENT_MOUSE_AXES)

	//OBSLUGA KLIKNIECIA MYSZKI
	if(events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
	{
		//POBIERAMY STAN MYSZKI
		al_get_mouse_state(&state);

		//KLIKNIECIE LEWY PRZYCISK MYSZKI
		if( state.buttons & 1 )
		{
			//START STOP GAME
			if( x < 800 && x > 600 && y < 400 && y > 350 )
				Start_Game = ( Start_Game == true ? false : true ) ;
			//WYJSCIE Z GRY
			else if( x < 800 && x > 600 && y < 450 && y > 400 )
				End_Start_Game_ = true ;
		}//if( state.buttons & 1 )
	}//if(events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
}

void Game_Screen::Handling_Keyboard( ALLEGRO_EVENT &events , ALLEGRO_KEYBOARD_STATE &keyState , ALLEGRO_TIMER *MoveFPS , ALLEGRO_TIMER *ChangeFPS )
{
	if(events.type == ALLEGRO_EVENT_TIMER)
	{
		//POZWOLENIE NA ZMIANE POZYCJI
		if( events.timer.source == ChangeFPS )
			Maps->Figura->Change_Position() ;
		//RUCH KLOCKA
		if( events.timer.source == MoveFPS )
		{
			//JESLI GRA CIAGLE TRWA
			if( Start_Game )
			{
					Maps->Figura->Move( keyState , Maps->Screen_Map ) ;
			}
		}
	}
}

void Game_Screen::Draw_Screen( ALLEGRO_EVENT &events , ALLEGRO_TIMER *FPS , ALLEGRO_TIMER *MapFPS )
{
	//OBSLUGA EVENTU CZASU
	if(events.type == ALLEGRO_EVENT_TIMER)
	{
		//ZWYKLY CZAS DO RYSOWANIA EKRANU
		if( events.timer.source == FPS )
			draw = true ;
		//CZAS UAKTUALNIENIA MAPY (RYCH / KOLIZJE ...)
		else if( events.timer.source == MapFPS )
		{
			//ROZPOCZECIE GRY 
			if( Start_Game )
			{
				//JESLI GRA CIAGLE TRWA
				if( !Game_Over )
				{
					//std::cout << " !Game_Over " << std::endl ;
					//SPRAWDZAMY KOLIZJE
					if( !Maps->Figura->MoveDown( Maps->Screen_Map ) )
					{
						if( Maps->Colision() )
						{
							//KONCZYMY GRE
							Game_Over = true ;
							//RYSUJEMY GAME OVER
							Draw_Over = true ;
							//ZMIANA CZASU MAPY NA POCZATKOWY
							Frame = SpeadMap ;
						}
						//JESLI SKASOWANE LINIE PA PODZIELNE PRZEZ 10 TO ZWIEKSZAMY SZYBKOSC
						else if( Maps->Line_Delete >= 10 )
						{
							//std::cout << "Line_Delete = " << Maps->Line_Delete << std::endl ;
							//std::cout << "Frame = " << Frame << std::endl ;
							//ZMIENIAMY LINE_DELETE NA 0 I ZWIEKSZAMY POZIOM
							Maps->LVL++ ;
							Maps->Line_Delete = 0 ;
							Frame += 0.4 ;
							al_set_timer_speed( MapFPS , 1 / Frame ) ;
						}
					}
				}//if( !Game_Over )
			}//if( Start_Game )
		}//else if( events.timer.source == MapFPS )
	}//if(events.type == ALLEGRO_EVENT_TIMER)

	if(draw)
	{
		//draw = false ;

		//TLO POD MAPA
		//al_draw_filled_rectangle( 0 , 0 , 600 , 600 , al_map_rgb( 255 , 255 , 255 ) ) ;

		Maps->Draw_Map() ;
		
		if( Start_Game )
			al_draw_bitmap( Screen_Bitmap["Pause"] , 600 , 350 , NULL ) ;
		else
		{
			//ZMIANA KOLORU (JESLI DOBRZE ROZUMIEM) [BEZ TEGO NIE DZIALA TAK JAK TRZEBA]
			al_set_blender( ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA ) ;
			//RYSUJEMY BITMAPE Z ODPOWIEDNIM KANALEM ALPHA (PRZEZROCZYSTOSC)
			al_draw_tinted_bitmap( Screen_Bitmap["Pause_Screen"] , al_map_rgba_f( 1 , 1 , 1 , 0.7 ) , 0 , 0 , 0 ) ;
			al_draw_bitmap( Screen_Bitmap["Start"] , 600 , 350 , NULL ) ;
		}

		al_draw_bitmap( Screen_Bitmap["Back"] , 600 , 400 , NULL ) ;

		//INSTRUKCJA
		al_draw_text( Font_Smal , al_map_rgb(255 , 0 , 0) , 600 , 460 , ALLEGRO_ALIGN_LEFT , "CONTROL" ) ;
		al_draw_bitmap( Screen_Bitmap["Arrow"], 600 , 500 , NULL ) ;

		if(Draw_Over)
		{
			//RYSUJEMY GAME OVER
			al_draw_bitmap( Screen_Bitmap["Game_Over"] , 0 , 100 , NULL ) ;
			al_flip_display() ;
			al_rest(3.0) ;
			//KASUJEMY GRE I WRACAMY DO MENU
			End_Start_Game_ = true ;
			Draw_Over = false ;
		}

		switch(Mouse_Select)
		{
			case 1:

				if( Start_Game )
					al_draw_bitmap( Screen_Bitmap["Pause2"] , 600 , 350 , NULL ) ;
				else
					al_draw_bitmap( Screen_Bitmap["Start2"] , 600 , 350 , NULL ) ;

				break ;

			case 2:

				al_draw_bitmap( Screen_Bitmap["Back2"] , 600 , 400 , NULL ) ;

				break ;

			default :

				break ;
		}


		//al_flip_display() ;
		//al_clear_to_color(al_map_rgb(0 , 0 , 0)) ;
	}//if(draw)
}

void Game_Screen::Screen_Lighten()
{
	//TWORZYMY BITMAPE ORAZ KOPIUJEMY OBECNY display
	Screen_Photo = al_create_bitmap( 800 , 600 ) ;
	ALLEGRO_BITMAP *Prev_Target = al_get_target_bitmap() ;

	//USTAWIAMY RYSOWANIE NA NOWEJ BITMAPIE
	al_set_target_bitmap( Screen_Photo ) ;

	Maps->Draw_Map() ;
		
	if( Start_Game )
		al_draw_bitmap( Screen_Bitmap["Pause"] , 600 , 300 , NULL ) ;
	else
	{
		//ZMIANA KOLORU (JESLI DOBRZE ROZUMIEM) [BEZ TEGO NIE DZIALA TAK JAK TRZEBA]
		al_set_blender( ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA ) ;
		//RYSUJEMY BITMAPE Z ODPOWIEDNIM KANALEM ALPHA (PRZEZROCZYSTOSC)
		al_draw_tinted_bitmap( Screen_Bitmap["Pause_Screen"] , al_map_rgba_f( 1 , 1 , 1 , 0.7 ) , 0 , 0 , 0 ) ;
		al_draw_bitmap( Screen_Bitmap["Start"] , 600 , 300 , NULL ) ;
	}

	al_draw_bitmap( Screen_Bitmap["Back"] , 600 , 360 , NULL ) ;

	//INSTRUKCJA
	al_draw_text( Font_Smal , al_map_rgb(255 , 0 , 0) , 600 , 450 , ALLEGRO_ALIGN_LEFT , "CONTROL" ) ;
	al_draw_bitmap( Screen_Bitmap["Arrow"], 600 , 500 , NULL ) ;

	//USTAWIAMY STARY display (CHODZI O RYSOWANIE JAKBY WYBOR OKNA)
	al_set_target_bitmap( Prev_Target ) ;

	//PETLA RYSUJACA OBRAZ Z CORAZ MNIEJSZA PRZEZROCZYSTOSCIA
	for( float i = 0 ; i <= 1 ; i += 0.002 )
	{
		//ZMIANA KOLORU (JESLI DOBRZE ROZUMIEM) [BEZ TEGO NIE DZIALA TAK JAK TRZEBA]
		al_set_blender( ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA ) ;

		//RYSUJEMY BITMAPE Z ODPOWIEDNIM KANALEM ALPHA (PRZEZROCZYSTOSC)
		al_draw_tinted_bitmap( Screen_Photo , al_map_rgba_f( 1 , 1 , 1 , i ) , 0 , 0 , 0 ) ;

		al_flip_display() ;
		al_clear_to_color(al_map_rgb(0 , 0 , 0)) ;
		//al_rest(5.0) ;
	}
}

void Game_Screen::Screen_Fading()
{
	//TWORZYMY BITMAPE ORAZ KOPIUJEMY OBECNY display
	Screen_Photo = al_create_bitmap( 800 , 600 ) ;
	ALLEGRO_BITMAP *Prev_Target = al_get_target_bitmap() ;

	//USTAWIAMY RYSOWANIE NA NOWEJ BITMAPIE
	al_set_target_bitmap( Screen_Photo ) ;

	Maps->Draw_Map() ;
		
	if( Start_Game )
		al_draw_bitmap( Screen_Bitmap["Pause"] , 600 , 300 , NULL ) ;
	else
	{
		//ZMIANA KOLORU (JESLI DOBRZE ROZUMIEM) [BEZ TEGO NIE DZIALA TAK JAK TRZEBA]
		al_set_blender( ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA ) ;
		//RYSUJEMY BITMAPE Z ODPOWIEDNIM KANALEM ALPHA (PRZEZROCZYSTOSC)
		al_draw_tinted_bitmap( Screen_Bitmap["Pause_Screen"] , al_map_rgba_f( 1 , 1 , 1 , 0.7 ) , 0 , 0 , 0 ) ;
		al_draw_bitmap( Screen_Bitmap["Start"] , 600 , 300 , NULL ) ;
	}

	al_draw_bitmap( Screen_Bitmap["Back"] , 600 , 360 , NULL ) ;

	//INSTRUKCJA
	al_draw_text( Font_Smal , al_map_rgb(255 , 0 , 0) , 600 , 450 , ALLEGRO_ALIGN_LEFT , "CONTROL" ) ;
	al_draw_bitmap( Screen_Bitmap["Arrow"], 600 , 500 , NULL ) ;

	//USTAWIAMY STARY display (CHODZI O RYSOWANIE JAKBY WYBOR OKNA)
	al_set_target_bitmap( Prev_Target ) ;

	//PETLA RYSUJACA OBRAZ Z CORAZ MNIEJSZA PRZEZROCZYSTOSCIA
	for( float i = 1 ; i >= 0 ; i -= 0.002 )
	{
		//ZMIANA KOLORU (JESLI DOBRZE ROZUMIEM) [BEZ TEGO NIE DZIALA TAK JAK TRZEBA]
		al_set_blender( ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA ) ;

		//RYSUJEMY BITMAPE Z ODPOWIEDNIM KANALEM ALPHA (PRZEZROCZYSTOSC)
		al_draw_tinted_bitmap( Screen_Photo , al_map_rgba_f( 1 , 1 , 1 , i ) , 0 , 0 , 0 ) ;

		al_flip_display() ;
		al_clear_to_color(al_map_rgb(0 , 0 , 0)) ;
		//al_rest(5.0) ;
	}
}
