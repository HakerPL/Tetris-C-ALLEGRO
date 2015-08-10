#include "Menu_Screen.h"


void Menu_Screen::Handling_Keyboard( ALLEGRO_EVENT &events , ALLEGRO_KEYBOARD_STATE &keyState , ALLEGRO_TIMER *MoveFPS , ALLEGRO_TIMER *ChangeFPS )
{
	//EVENT KLAWIATURY
	if(events.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		//PORUSZANIE SIE PO MENU
		if( al_key_down(&keyState , ALLEGRO_KEY_LEFT) )
		{
			if(Select_Options <= 0)
				Select_Options = 0 ;
			else
				Select_Options-- ;
		}

		else if( al_key_down(&keyState , ALLEGRO_KEY_RIGHT) )
		{
			if(Select_Options >= 1)
				Select_Options = 1 ;
			else
				Select_Options++ ;
		}

		//WYBOR POZYCJI NA MENU
		if(al_key_down(&keyState , ALLEGRO_KEY_ENTER))
			switch(Select_Options)
			{
				case 0:

					End_Menu_ = true ;
					STATE = GAME ;
					break ;

				case 1:

					End_Menu_ = true ;
					Game_ = false ;
					break ;
			}
	}//if(events.type == ALLEGRO_EVENT_KEY_DOWN)
}

void Menu_Screen::Handling_Mouse( ALLEGRO_EVENT &events )
{
	//EVENT MYSZKI
	if(events.type == ALLEGRO_EVENT_MOUSE_AXES)
	{
		x = events.mouse.x ;
		y = events.mouse.y ;

		//START
		if( x < 350 && x > 150 && y < 500 && y > 400 )
			Select_Options   = 0 ;
		//EXIT
		else if( x < 650 && x > 450 && y < 500 && y > 400 )
			Select_Options   = 1 ;
		
	}//if(events.type == ALLEGRO_EVENT_MOUSE_AXES)

	//OBSLUGA KLIKNIECIA MYSZKI
	if(events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
	{
		//POBIERAMY STAN MYSZKI
		al_get_mouse_state(&state);

		//KLIKNIECIE LEWY PRZYCISK MYSZKI
		if( state.buttons & 1 )
		{
			//START
			if( x < 350 && x > 150 && y < 500 && y > 400 )
			{
				End_Menu_ = true ;
				STATE = GAME ;
			}

			//EXIT
			if( x < 650 && x > 450 && y < 500 && y > 400 )
			{
				End_Menu_ = true ;
				Game_ = false ;
			}
		}
	}//if(events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
}

void Menu_Screen::Draw_Screen( ALLEGRO_EVENT &events , ALLEGRO_TIMER *FPS , ALLEGRO_TIMER *MapFPS )
{
	//OBSLUGA EVENTU CZASU
	if(events.type == ALLEGRO_EVENT_TIMER)
	{
		if( events.timer.source == FPS )
			draw = true ;
	}
	//ODSWIEZAMY EKRAN
	if(draw)
	{
		//draw = false ;
		
		al_draw_bitmap( Screen_Bitmap["Menu_Background"] , 0 , 0 , NULL ) ;
		al_draw_bitmap( Screen_Bitmap["Start"] , 150 , 400 , NULL ) ;
		al_draw_bitmap( Screen_Bitmap["Exit"] , 450 , 400 , NULL ) ;


		switch(Select_Options)
		{
			case 0:

				al_draw_bitmap( Screen_Bitmap["Start2"] , 150 , 400 , NULL ) ;
				break ;

			case 1:

				al_draw_bitmap( Screen_Bitmap["Exit2"] , 450 , 400 , NULL ) ;
				break ;
		}//switch(Select_Options)

		//al_flip_display() ;
		//al_clear_to_color(al_map_rgb(0 , 0 , 0)) ;
	}
}

void Menu_Screen::Screen_Lighten()
{
	//TWORZYMY BITMAPE ORAZ KOPIUJEMY OBECNY display
	Screen_Photo = al_create_bitmap( 800 , 600 ) ;
	ALLEGRO_BITMAP *Prev_Target = al_get_target_bitmap() ;

	//USTAWIAMY RYSOWANIE NA NOWEJ BITMAPIE
	al_set_target_bitmap( Screen_Photo ) ;

	al_draw_bitmap( Screen_Bitmap["Menu_Background"] , 0 , 0 , NULL ) ;
	al_draw_bitmap( Screen_Bitmap["Start"] , ScreenWidth / 2 - 100 , 200 , NULL ) ;
	al_draw_bitmap( Screen_Bitmap["Exit"] , ScreenWidth / 2 - 100 , 500 , NULL ) ;

	//USTAWIAMY STARY display (CHODZI O RYSOWANIE JAKBY WYBOR OKNA)
	al_set_target_bitmap( Prev_Target ) ;

	//PETLA RYSUJACA OBRAZ Z CORAZ MNIEJSZA PRZEZROCZYSTOSCIA
	for( float i = 0 ; i <= 1 ; i += 0.001 )
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

void Menu_Screen::Screen_Fading()
{
	for( float i = 1 ; i >= 0 ; i -= 0.001 )
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
