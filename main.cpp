//WYLACZENIE KONSOLKI
#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include <allegro5/allegro5.h>
#include <allegro5/allegro_native_dialog.h>
//#include <allegro5/allegro_image.h>
//#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include "zmienne.h"
//#include "Map.h"
#include "Menu_Screen.h"
#include "Game_Screen.h"
#include <time.h>
#include <cstdlib>

//KALKULACJA FPS
INT64 CalculateFPS()
{
    static INT64 ilastTick, ilastFPS, iFPS;
    if( GetTickCount64() - ilastTick >= 1000 )
    {
        ilastFPS = iFPS;
        iFPS = 0;
        ilastTick = GetTickCount64();
    }
    iFPS++;
    return ilastFPS;
}


//WSKAZNIK NA EKRAN (KLASA ABSTRAKCYJNA)
Screen_Abstract * Screen ;

//CZCIONKA DLA NAPISOW
ALLEGRO_FONT *Font_Big  ;
ALLEGRO_FONT *Font_Smal ;

//TIMER DLA ODSWIEZANIA EKRANU
ALLEGRO_TIMER *FPS ;
//TIMER DLA RUCHU W DOL
ALLEGRO_TIMER *MapFPS ;
//TIMER DLA RUCHU NA BOKI
ALLEGRO_TIMER *MoveFPS ;
//TIMER DLA ZMIANY POZYCJI
ALLEGRO_TIMER *ChangeFPS ;

//GLOBALNA ZMIENNA OKNA
ALLEGRO_DISPLAY * display ;

int main()
{
	//LOSOWANIE LICZB
	srand ( time( NULL ) ) ;

	//INICJALIZACJA ALLEGRO
	if( !al_init() )
	{
		al_show_native_message_box(NULL , "ALLEGRO ERROR" , "ERROR" , "Allegro don't work" , NULL , ALLEGRO_MESSAGEBOX_ERROR) ;
		return -1 ;
	}

	display = al_create_display(ScreenWidth , ScreenHight) ;

	//SPRAWDZAMY CZY OKNO ISTNIEJE
	if( !display )
	{
		al_show_native_message_box(display , "DISPLAY ERROR" , "ERROR" , "Display is not create" , NULL , ALLEGRO_MESSAGEBOX_ERROR) ;
		return -1 ;
	}

	//USTAWIAMY POZYCJA OKNA 
	al_set_window_position(display , 300 , 50) ;


	//DODAJEMY MYSZKE / KLAWIATURE / FIGORY / IMAGE / OBSLUGA CZCIONEK / OBSLUGA TTF
	if( !al_install_mouse() )
	{
		al_show_native_message_box(NULL , "ALLEGRO ERROR" , "ERROR" , "Install_Mouse don't work" , NULL , ALLEGRO_MESSAGEBOX_ERROR) ;
		return -1 ;
	}

	if( !al_install_keyboard() )
	{
		al_show_native_message_box(NULL , "ALLEGRO ERROR" , "ERROR" , "Install_Keyboard don't work" , NULL , ALLEGRO_MESSAGEBOX_ERROR) ;
		return -1 ;
	}

	if( !al_init_primitives_addon() )
	{
		al_show_native_message_box(NULL , "ALLEGRO ERROR" , "ERROR" , "Init_Primitives_Addon don't work" , NULL , ALLEGRO_MESSAGEBOX_ERROR) ;
		return -1 ;
	}

	if( !al_init_image_addon() )
	{
		al_show_native_message_box(NULL , "ALLEGRO ERROR" , "ERROR" , "Init_Image_Addon don't work" , NULL , ALLEGRO_MESSAGEBOX_ERROR) ;
		return -1 ;
	}

	al_init_font_addon() ;
	
	if( !al_init_ttf_addon() )
	{
		al_show_native_message_box(NULL , "ALLEGRO ERROR" , "ERROR" , "Init_Ttf_Addon don't work" , NULL , ALLEGRO_MESSAGEBOX_ERROR) ;
		return -1 ;
	}

	//DODANIE CZCIONKI (ALLEGRO 5 NIE POZIADA WLASNEJ)
	Font_Big  = al_load_ttf_font( "Font\\orbitron-black.ttf" , 40 , NULL ) ;
	Font_Smal = al_load_ttf_font( "Font\\orbitron-black.ttf" , 20 , NULL ) ;

	//SPRAWDZAMY CZY CZCIONKI DZIALAJA
	if( !Font_Big )
	{
		al_show_native_message_box(NULL , "ALLEGRO ERROR" , "ERROR" , "Font_Big don't work (Font\\orbitron-black.ttf)" , NULL , ALLEGRO_MESSAGEBOX_ERROR) ;
		return -1 ;
	}
	if( !Font_Smal )
	{
		al_show_native_message_box(NULL , "ALLEGRO ERROR" , "ERROR" , "Font_Smal don't work (Font\\orbitron-black.ttf)" , NULL , ALLEGRO_MESSAGEBOX_ERROR) ;
		return -1 ;
	}

	//OBSLUGA KLAWIATURY
	ALLEGRO_KEYBOARD_STATE keyState ;

	//TIMER DLA ODSWIEZANIA EKRANU
	FPS = al_create_timer( 1 / FrameFPS ) ;
	//TIMER DLA RUCHU W DOL
	MapFPS = al_create_timer( 1 / Frame ) ;
	//TIMER DLA RUCHU KLOCKA
	MoveFPS = al_create_timer( 1 / MoveFRAME ) ;
	//TIMER DLA ZMIANY POZYCJI
	float ChangeFRAME = 10 ;
	ChangeFPS = al_create_timer( 1 / ChangeFRAME ) ;


	//TWORZYMY KOLEJKE EVENTU
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue() ;

	//DODAJEMY OBSLUGE EVENTOW DO KOLEJKI (KLAWIATURA / MYSZKA / ODSWIEZANIEEKRANU / ODSWIEZANIE MAPY / EKRANU)
	al_register_event_source(event_queue , al_get_keyboard_event_source() )       ;
	al_register_event_source(event_queue , al_get_mouse_event_source() )	      ;
	al_register_event_source(event_queue , al_get_timer_event_source(FPS) )	      ;
	al_register_event_source(event_queue , al_get_timer_event_source(MapFPS) )	  ;
	al_register_event_source(event_queue , al_get_timer_event_source(MoveFPS) )	  ;
	al_register_event_source(event_queue , al_get_timer_event_source(ChangeFPS) ) ;
	al_register_event_source(event_queue , al_get_display_event_source(display) ) ;
	
	bool draw2 = false ;

	//OBSLUGA POSZCZEGOLNYCH EVENTOW
	ALLEGRO_EVENT events ;

	//START CZASU
	al_start_timer(FPS)	      ; 
	al_start_timer(MapFPS)    ;
	al_start_timer(MoveFPS)   ;
	al_start_timer(ChangeFPS) ;
	

	//URUCHAMIAMY LOSOWANIE LICZB
	srand( static_cast<unsigned int>(time(NULL)) ) ;

	while(Game_)
	{
		//POBIERAMY EVENT Z KOLEJKI
		al_wait_for_event(event_queue , &events) ;

		//POBIERAMY STAN PRZYCISKU
		al_get_keyboard_state(&keyState) ;

		if(events.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			if( al_key_down(&keyState , ALLEGRO_KEY_F12) )
				draw2 = (draw2 == true ? false : true );
		}

		//EVENT OD OKNA (ZAMKNIECIE OKNA X)
		if(events.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			Game_ = false ;

		switch(STATE)
		{
			case MENU:

				//TWORZYMY OBIEKT
				if(Menu_)
				{
					Menu_  = false ;
					Screen = new Menu_Screen() ;
					//Screen->Screen_Lighten()   ;
				}

				//OBSLUGA ZDAZEN
				Screen->Handling_Keyboard( events , keyState ) ;
				Screen->Handling_Mouse( events ) ;
				Screen->Draw_Screen( events , FPS ) ;

				//KAZUJEMY OBIEKT
				if(End_Menu_)
				{
					End_Menu_ = false ;
					Menu_     = true  ;
					//Screen->Screen_Fading() ;
					delete Screen ;
				}

				break ;

			case GAME:

				if(Start_Game_)
				{
					//std::cout << "                    W Start_Game_" << std::endl ;
					Start_Game_ = false ;
					Screen   = new Game_Screen() ;
					//Screen->Screen_Lighten()   ;
					//USTAWIAMY CZAS NA POCZATKOWA WARTOSC
					al_set_timer_speed( MapFPS , 1 / Frame ) ;
				}

				Screen->Handling_Keyboard( events , keyState , MoveFPS , ChangeFPS ) ;
				Screen->Handling_Mouse( events ) ;
				Screen->Draw_Screen( events , FPS , MapFPS ) ;
				
				if(End_Start_Game_)
				{
					//std::cout << "                    W End_Start_Game_" << std::endl ;
					End_Start_Game_ = false ;
					Start_Game_ = true ;
					//Screen->Screen_Fading()   ;
					delete Screen ;
					STATE = MENU ;
				}

				break ;

		}//switch(STATE)

		if(draw)
		{
			//POBIERAMY FPS I WSTAWIAMY DO STRUMIENIA
			std::stringstream FramePerSecond ;
			FramePerSecond << CalculateFPS() ;

			draw = false ;

			if(draw2)
			{
				std::stringstream Mouse_Position ;
				//POBIERAMY X
				Mouse_Position << x ;
				//WYPISUJEMY X
				al_draw_text( Font_Smal , al_map_rgb(0 , 255 , 0) , 0 , 0 , ALLEGRO_ALIGN_LEFT , "X" ) ;
				al_draw_text( Font_Smal , al_map_rgb(0 , 255 , 0) , 20 , 0 , ALLEGRO_ALIGN_LEFT , Mouse_Position.str().c_str() ) ;
				//CZYSCIMY STRINGSTREAM
				Mouse_Position.str( std::string() ) ;
				Mouse_Position.clear() ;
				//POBIERAMY Y
				Mouse_Position << y ;
				//WYPISUJEMY X
				al_draw_text( Font_Smal , al_map_rgb(0 , 255 , 0) , 0 , 30 , ALLEGRO_ALIGN_LEFT , "Y" ) ;
				al_draw_text( Font_Smal , al_map_rgb(0 , 255 , 0) , 20 , 30 , ALLEGRO_ALIGN_LEFT , Mouse_Position.str().c_str() ) ;
				//WYPISUJEMY X
				al_draw_text( Font_Smal , al_map_rgb(0 , 255 , 0) , 100 , 0 , ALLEGRO_ALIGN_LEFT , "FPS" ) ;
				al_draw_text( Font_Smal , al_map_rgb(0 , 255 , 0) , 150 , 0 , ALLEGRO_ALIGN_LEFT , FramePerSecond.str().c_str() ) ;
			}

			//CZYSCIMY STRUMIEN
			FramePerSecond.str( std::string() ) ;
			FramePerSecond.clear() ;

			al_flip_display() ;
			al_clear_to_color(al_map_rgb(0 , 0 , 0)) ;
		}
	}//while(Game_)


	///////////////////////////////////////
	////////////CZYSCIMY PAMIEC////////////
	///////////////////////////////////////

	//CZCIONKA
	al_destroy_font( Font_Big  ) ;
	al_destroy_font( Font_Smal ) ;
	//CZAS I DISPLAY
	al_destroy_timer( FPS ) ;
	al_destroy_timer( MapFPS ) ;
	al_destroy_display( display ) ;

	return 0 ;
}
