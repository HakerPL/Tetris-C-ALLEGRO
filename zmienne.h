#ifndef ZMIENNE_H
#define ZMIENNE_H
//#include <allegro5\allegro5.h>
#include <allegro5\allegro_font.h>
#include <string>
//#include <fstream>
//#include <time.h>

//STAN GRY
enum GAME_STATE { MENU , GAME } ;
extern GAME_STATE STATE ;

//STWORZYC MENU
extern bool Menu_ ;
//WYJSCIE Z MENU
extern bool End_Menu_ ;
//STWORZYC Game
extern bool Start_Game_ ;
//WYJSCIE Z Game
extern bool End_Start_Game_ ;

//ZMIENNA DO WLACZENIA GRY
extern bool Game_ ;

//ODSWIEZAMY EKRAN
extern bool draw ;

//WYMIARY OKNA
extern int ScreenHight ;
extern int ScreenWidth ;

//ZMIENNE DLA MYSZKI
extern float x , y ;

//POMOCNA ZMIENNA DO CZASU
extern int SpeadMap ;
//SZYBKOSC ODSWIEZANIA MAPY
extern float Frame ;
//SZYBKOSC ODSWIEZANIA EKRANU
extern float FrameFPS ;
//SZYBKOSC RUCHU KLOCKA
extern float MoveFRAME ;

//ZMIENNA EKRAN
extern ALLEGRO_DISPLAY * display ;

//CZCIONKA DLA NAPISOW
extern ALLEGRO_FONT *Font_Big  ;
extern ALLEGRO_FONT *Font_Smal ;

//STRUKTURA FIGURY
struct DataBlock
{
	//POZYCJA X / Y / KOLOR
	int x ;
	int y ;
	ALLEGRO_COLOR color ;
};

//STRUKTURA MAPY
struct DataMap
{
	bool Draw ;
	ALLEGRO_COLOR color ;
};

/////////////////////////////////////
///            FUNKCJE            ///
/////////////////////////////////////

///USTAWIANIE WIELKOSCI BITMAPY
extern ALLEGRO_BITMAP *load_bitmap_at_size(const char *filename, float w, float h) ;

#endif