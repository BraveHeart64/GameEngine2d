#include"GameEngine.h"




GameEngine::GameEngine(){
    al_init();
    al_init_native_dialog_addon();
    al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();
    al_install_audio();
    al_install_keyboard();
    al_install_mouse();
    al_install_joystick();


    path = al_get_standard_path(ALLEGRO_RESOURCES_PATH);
    al_append_path_component(path,"images");
    al_change_directory(al_path_cstr(path,'/'));

    /*  Menu bitmaps of four screens all equal null
    menu[0] = 0;
    menu[1] = 0;
    menu[2] = 0;
    menu[3] = 0;
*/



    menu = al_create_menu();
    menu_tab = al_create_menu();

    al_append_menu_item(menu_tab,"Quit",quit,0,NULL,NULL);
    al_append_menu_item(menu,"File",0,0,NULL,menu_tab);




    this->gamestate = 0;
    this->height = 500;
    this->width = 500;
    this->fps = 60;

    clock = al_create_timer(1.0/fps);
    que = al_create_event_queue();
    al_start_timer(clock);
    screen = al_create_display(width, height);

    event.user.data1 = start;



    //al_set_new_window_position();
    al_register_event_source(que,al_get_keyboard_event_source());
    al_register_event_source(que,al_get_display_event_source(screen));
    al_register_event_source(que,al_get_timer_event_source(clock));
    al_register_event_source(que,al_get_mouse_event_source());
    al_register_event_source(que,al_get_default_menu_event_source());


}



GameEngine::~GameEngine(){

    al_destroy_event_queue(que);
    al_destroy_display(screen);
    al_destroy_timer(clock);
   //al_destroy_bitmap(landmass);
    al_destroy_bitmap(icon);

    for(auto i = tile_holder.begin(); i != tile_holder.end(); ++i){

        al_destroy_bitmap(*i);
    }

   // al_destroy_bitmap(tiles['l']);



   al_destroy_menu(menu_tab);
   al_destroy_menu(menu);


}

void GameEngine::setGameTitle(string name){
    const char * newname = name.c_str();
    al_set_window_title(screen,newname);
    draw = true;
}


void GameEngine::SetUpDisplay(bool state_change){



    switch(gamestate){
        case 0:
            // load custom menu based on Game name file method Menu to use
            // all other cases are just to load new levelts based on gamestates
        break;

        case 1:

        break;

        default:


        break;


    }


}


void GameEngine::DrawGraphics(){

}


void GameEngine::LoadSound(){


}

void GameEngine::PlaySound(){


}


void GameEngine::LoadIcon(string icon_name){

    const char* newname = icon_name.c_str();
    icon = al_load_bitmap(newname);
    al_set_display_icon(screen,icon);


}

void GameEngine::LoadImages(string name,string imagetype){
    // Load the images for the levels and gamesprites
    ALLEGRO_BITMAP* image;
    const char *nameofimage = name.c_str();
    image = al_load_bitmap(nameofimage);

    tiles[imagetype] = image;
    tile_holder.push_back(tiles[imagetype]);

}

void GameEngine::LoadBackground(){
    // paints the entire level based on game state
    if(gamestate== 0){


    }


}

void GameEngine::Animation(){


}

// fix this and unreposive events
bool GameEngine::GameInputs(bool val){
/*
    event.user.data2 = (intptr_t) screen;
    event.user.data3 = (intptr_t) menu;
    al_set_display_menu(screen,menu);
*/
    al_wait_for_event(que,&event);



    switch(event.type){

        case ALLEGRO_EVENT_TIMER:
        // add game logic here
            draw = true;
            break;


        case ALLEGRO_EVENT_KEY_DOWN:



                break;


        case ALLEGRO_EVENT_DISPLAY_CLOSE:
                val = true;
                return val;
        break;



    }



    if(event.type == ALLEGRO_EVENT_MENU_CLICK){
        if(event.user.data1 == quit){
            val = true;

        }
    }

    if(draw == true && !al_is_event_queue_empty(que))
    {
        al_clear_to_color(al_map_rgb(0,0,0));

        Render();

    }



    return false;
}

void GameEngine::GamePyhiscs(){


}


bool GameEngine::ObjectCollision(){


    return false;
}


void GameEngine::SideScrollerLogic(){



}

void GameEngine::EngineMethod(bool run){





}

void GameEngine::Render(){

    al_flip_display();


}








