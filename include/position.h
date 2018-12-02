/*
 * librairie position.h
 */

//typedef struct Coordonnees;

typedef struct coordonnees * Coor;

int get_x(Coor point){
	int x=point->x;
	return(x);
}

int get_y(Coor point){
	int y=point->y;
	return(y)
}

int get_z(Coor point){
	int z=point->z;
	return(z)
}

int get_z(Coor point){
	int z=point->z;
	return(z)
}

void new_coord(Coor point, float dt);