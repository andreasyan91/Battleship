#include <string>
void battleship();
char** create_sea_for_preview();
void print(char**);
int** create_real_sea();
void print_real_sea(int**);
void set_direction(int**);
int** define_ships();
void generate_coordinates(int*);
bool check_for_horizontal(int, int, int, int**);
bool check_for_vertical(int, int, int, int**);
bool check(int*, int**);
void set_number_two_horizontal(int*, int**);
void set_number_two_vertical(int*, int**);
void set_number_two_around_ship(int*, int**);
void set_horizontal(int*, int**);
void set_vertical(int*, int**);    
void write_in_real_sea(int*, int**);
void set_on_board(int**, int**);
bool valid_input(std::string);
void input(int&, int&);
bool already_hit_or_miss(int, int, char**);
bool check_horizontal_ship(int*, int, int, char**, int);
bool check_vertical_ship(int*, int, int, char**, int);
void check_in(int*, int, int, int**, int&);
int check_ships(int**, int, int, char**, int&, bool&);
int sunk(int**, int);
void player_turn(char** sea, int** ships, int&);
int check_cpu_ships(std::string, bool&, int);
void cpu_turn(int&);
void shoot(char**, int**);
void start();
