#include<string>
#include<allegro5/allegro_image.h>
using namespace std;



class Sprite {

    private:
        string id_name;
        ALLEGRO_BITMAP* sprite;
        // hit dection box;
        int length_y, length_ytwo;
        int height_x, height_xtwo;
        float speed, velocity;
        double angle;


    public:
        virtual void setIdName() = 0;
        virtual string getIdName() = 0;
        virtual void setLenghtX() = 0;
        virtual int getLengthX() = 0;
        virtual void setHeightX() = 0;
        virtual int getHeightX() = 0;


};
