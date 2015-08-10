#pragma once
#include "zmienne.h"
#include "screen_abstract.h"
//#include <allegro5\allegro_primitives.h>

class Menu_Screen :
	public Screen_Abstract
{
	public:

		//OBSLUGA MYSZKI
		void Handling_Mouse( ALLEGRO_EVENT &events ) ;
		//OBSLUGA KLAWIATURY
		void Handling_Keyboard( ALLEGRO_EVENT &events , ALLEGRO_KEYBOARD_STATE &keyState , ALLEGRO_TIMER *MoveFPS = 0 , ALLEGRO_TIMER *ChangeFPS = 0 ) ;
		//RYSOWANIE EKRANU
		void Draw_Screen( ALLEGRO_EVENT &events , ALLEGRO_TIMER *FPS , ALLEGRO_TIMER *MapFPS = 0 ) ;
		//PRZYCIEMNIANIE EKRANU PRZY PRZEJSCIU NA INNY
		void Screen_Fading()  ; 
		//ROZJASNIANIE EKRANU PRZY WCZYTANIU
		void Screen_Lighten() ;


		Menu_Screen()
		{
			//USTAWIAMY POCZATKOWE WARTOSCI
			Select_Options = 0 ;

			//MENU
			Screen_Bitmap["Menu_Background"] = load_bitmap_at_size( "Graphics\\Menu\\Menu_Background.png" , 800 , 600 )  ;
			Screen_Bitmap["Start"]			 = load_bitmap_at_size( "Graphics\\Menu\\Start.png" , 200 , 100 )    ;
			Screen_Bitmap["Start2"]			 = load_bitmap_at_size( "Graphics\\Menu\\Start2.png" , 200 , 100 )   ;
			Screen_Bitmap["Exit"]		     = load_bitmap_at_size( "Graphics\\Menu\\Exit.png" , 200 , 100 )     ;
			Screen_Bitmap["Exit2"]		     = load_bitmap_at_size( "Graphics\\Menu\\Exit2.png" , 200 , 100 )    ;

			//SPRAWDZAMY CZY BITMAPY ISTNIEJA
			if( !Screen_Bitmap["Menu_Background"] )
			{
				al_show_native_message_box( display , "ERROR BITMAP" , "ERROR" , "You don't have bitmap \"Graphics\\Menu\\Menu_Background.png\" " , NULL , ALLEGRO_MESSAGEBOX_ERROR ) ;
				exit(1) ;
			}
			else if( !Screen_Bitmap["Start"] )
			{
				al_show_native_message_box( display , "ERROR BITMAP" , "ERROR" , "You don't have bitmap \"Graphics\\Menu\\Start.png\" " , NULL , ALLEGRO_MESSAGEBOX_ERROR ) ;
				exit(1) ;
			}
			else if( !Screen_Bitmap["Start2"] )
			{
				al_show_native_message_box( display , "ERROR BITMAP" , "ERROR" , "You don't have bitmap \"Graphics\\Menu\\Start2.png\" " , NULL , ALLEGRO_MESSAGEBOX_ERROR ) ;
				exit(1) ;
			}
			else if( !Screen_Bitmap["Exit"] )
			{
				al_show_native_message_box( display , "ERROR BITMAP" , "ERROR" , "You don't have bitmap \"Graphics\\Menu\\Exit.png\" " , NULL , ALLEGRO_MESSAGEBOX_ERROR ) ;
				exit(1) ;
			}
			else if( !Screen_Bitmap["Exit2"] )
			{
				al_show_native_message_box( display , "ERROR BITMAP" , "ERROR" , "You don't have bitmap \"Graphics\\Menu\\Exit2.png\" " , NULL , ALLEGRO_MESSAGEBOX_ERROR ) ;
				exit(1) ;
			}

			//USTAWIAMY MASKE DLA PRZYCISKOW
			al_convert_mask_to_alpha( Screen_Bitmap["Start"] , al_map_rgb(255 , 255 , 255) )	;
			al_convert_mask_to_alpha( Screen_Bitmap["Start2"] , al_map_rgb(255 , 255 , 255) )	;
			al_convert_mask_to_alpha( Screen_Bitmap["Exit"] , al_map_rgb(255 , 255 , 255) )		;
			al_convert_mask_to_alpha( Screen_Bitmap["Exit2"] , al_map_rgb(255 , 255 , 255) )	;
		}

		~Menu_Screen()
		{
			al_destroy_bitmap( Screen_Bitmap["Menu_Background"] )	 ;
			al_destroy_bitmap( Screen_Bitmap["Start"] )				 ;
			al_destroy_bitmap( Screen_Bitmap["Start2"] )			 ;
			al_destroy_bitmap( Screen_Bitmap["Exit"] )				 ;
			al_destroy_bitmap( Screen_Bitmap["Exit2"] )				 ;
			//al_destroy_bitmap( Screen_Photo )						 ;
		}

	private:

		//POZYCJA NA MENU (STRZALKI / MYSZKA)
		int Select_Options ;
};
