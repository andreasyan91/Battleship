#include <string>

void battleship();

///Creates the board for preview.
char** create_sea_for_preview();

///Prints the board(sea for preview) to console.
void print(char**);

///Create playing board and assigns '0's to each point of the sea (playing
//board).
int** create_real_sea();

///Prints the playing board to console.
void print_real_sea(int**);

/// Randomly sets the direction of the ships.
///// Considering that direction doesn't make a difference for 1 sized ships,
//we set their directions to horizontal by default.
void set_direction(int**);

/// Sets up the ships.
///// Sets up the length and deafault health of each ship.
int** define_ships();

/// Randomly sets the coordintaes of the ships.
void generate_coordinates(int*);

/// Checks if the generated coordinates overlap any of the existing ships for
////horizontal ships.
bool check_set_for_horizontal(int, int, int, int**);

/// Checks if the generated coordinates overlap any of the existing ships for
////vertical ships.
bool check_set_for_vertical(int, int, int, int**);

/// Checks if the generated coordinates overlap any of the existing ships.
bool check(int*, int**);

/// Sets the vertical ship's surrounding squares to '2'.
void set_number_two_horizontal(int*, int**);

/// Sets the horizontal ship's surrounding squares to '2'.
void set_number_two_vertical(int*, int**);

/// Sets the ship's surrounding squares to '2'.
void set_number_two_around_ship(int*, int**);

/// Sets the coordinates of a horizontal ship.
void set_horizontal_ships(int*, int**);

/// Sets the coordinates of a vertical ship
void set_vertical_ships(int*, int**);

/// Sets the generated coordinates of the ship.
void write_in_real_sea(int*, int**);

/// Calls the generate_coordinates function and checks if the generated
////coordinates aren't overlapping any of the existing ships.
void set_on_board(int**, int**);

/// Verifies if entered coordinates are in the right format.
bool valid_input(std::string);

/// Receives coordinates from console and proceeds those.
void input(int&, int&);

/// Checks if the shot with the same coordinates was already made.
bool already_hit_or_miss(int, int, char**);

/// Checks if the shot hit a horizontal ship.
bool check_shot_horizontal_ship(int*, int, int, char**, int);

/// Checks if the shot hit a vertical ship.
bool check_vertical_ship(int*, int, int, char**, int);

/// Calls the sunk function, updates the health of the given ship and prints
////a message.
void update_health(int*, int, int, int**, int&);

/// Checks if the shot made by player hit any of the ships.
int check_ships(int**, int, int, char**, int&, bool&);

/// Checks if the ship is sunk.
int sunk(int**, int);

/// Player shoots at computer's ships.
void player_turn(char** sea, int** ships, int&);

/// Checks the state of the ship (hit or sunk);
int check_cpu_ships(bool&, int);

/// Cpu shoots at the player's ships.
void cpu_turn(int&);

/// Switches the shooting turn between computer and player.
void shoot(char**, int**);
void start();
