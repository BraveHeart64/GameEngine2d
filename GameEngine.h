#include<allegro5/allegro.h>
#include<allegro5/allegro_image.h>
#include<allegro5/allegro_ttf.h>
#include<allegro5/allegro_font.h>
#include<allegro5/allegro_native_dialog.h>
#include<allegro5/timer.h>
#include<allegro5/allegro_audio.h>

#include<string>
#include<unordered_map>
#include<vector>
#include"Sprite.h"

#define quit 2
#define start 1
using namespace std;

// hashmap for sprite placement

class GameEngine {
    private:
        int gamestate, height, width,fps;
        bool draw;
        unordered_map<string, ALLEGRO_BITMAP> *spirtes;
        unordered_map<string, ALLEGRO_BITMAP*> tiles;
        vector<ALLEGRO_BITMAP*> tile_holder;



        /*
            store the map screen and place sprites
            Graph

        */


        ALLEGRO_DISPLAY* screen = 0;
        ALLEGRO_BITMAP* icon = 0;
        ALLEGRO_PATH* path;
        ALLEGRO_MENU* menu;
        ALLEGRO_MENU* menu_tab;

        //ALLEGRO_BITMAP* menu[4]; // builds a menu study this carfuly
        //make a name scheme for land items

        //ALLEGRO_MENU_INFO menu_info[]={};





        ALLEGRO_EVENT event;
        ALLEGRO_EVENT_QUEUE* que;
        ALLEGRO_MOUSE_EVENT* mouse;
        ALLEGRO_TIMER* clock;
        char title[50];





// the methods are null until, I figure out what I want ot do with them

    public:

        void setGameTitle(string name);
        void DrawGraphics();
        void Menu();
        void LoadBackground();
        void LoadIcon(string icon_name);
        bool GameInputs(bool val);
        void Animation();
        void GamePyhiscs();
        void LoadImages(string name,string imagetype);
        bool ObjectCollision();
        void SetUpDisplay(bool state_change);
        void SideScrollerLogic();
        void LoadSound();
        void PlaySound();
        void EngineMethod(bool run);
        void Render();

        GameEngine();
        ~GameEngine();

};
