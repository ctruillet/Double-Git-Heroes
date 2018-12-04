/*
 * librairie position.h
 */

//typedef struct Coordonnees;

typedef struct coordonnees * Coor=NULL;

float get_x(Coor point);


float get_y(Coor point);
	

float get_z(Coor point);
	

void set_x(Coor point, float x);

void set_y(Coor point, float y);

void set_z(Coor point, float z);



void new_coord(Coor point, float dt);