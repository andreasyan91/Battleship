#include "battleship.hpp"
#include <iostream>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//Possible directions of a ship.
enum Direction {horizontal, vertical};

///Details of a ship.
enum ShipDetails {length, direction, x, y, health};

///Creates the board for preview.
char** create_sea_for_preview()
{
        int size = 12;
        char** sea = new char* [size];
        for (int i = 0; i < size; ++i) {
                sea[i] = new char [size];
        }
        assert(sea != NULL);
        for(int i = 0; i < size; ++i) {
                for(int j = 0; j < size; ++j) {
                        *(*(sea+i)+j)='~';
                }
        }
        return sea;
}
///Prints the board(sea for preview) to console.
void print(char** sea)
{
        int size = 10;
        std::cout<<"  ";
        for(int i = 1; i <= size; ++i) {
                std::cout<<" "<<i;
        }
        std::cout << "\n\n";
        for (int i = 1; i <= size -1; ++i){
                std::cout << i << "  ";
                for(int j = 1; j <= size; ++j) {
                        std::cout<<*(*(sea+i)+j)<<" ";
                }
                std::cout<<"\n";
        }
        std::cout << size;
        for (int i = 1; i <= size; ++i) {
                std::cout << " " << sea[size][i];
        }
        std::cout<<std::endl<<std::endl;
}
///Create playing board and assigns '0's to each point of the sea (playing board).
int** create_real_sea()
{
        int size = 12;
        int** real_sea = new int* [size];
        for (int i = 0; i < size; ++i) {
                real_sea[i] = new int [size];
        }
        assert(real_sea != NULL);
        for(int i = 0; i< size; ++i){
                for(int j=0; j<size; ++j) {
                        *(*(real_sea+i)+j) = 0;
                }
        }
        return real_sea;
}
///Prints the playing board to console.
void print_real_sea(int** real_sea)
{
        int size = 10;
        for(int i = 1; i<= size; ++i){
                for(int j=1; j<=size; ++j) {
                        std::cout<< *(*(real_sea+i)+j)<<" ";
                }
                std::cout<<std::endl;
        }
        std::cout<<std::endl;
}
/// Randomly sets the direction of the ships.
/// Considering that direction doesn't make a difference for 1 sized ships, we
//set their directions to horizontal by default.
void set_direction(int** ships)
{
        int ships_count = 10;
        int unit_ships = 4;
        int size = ships_count-unit_ships;
        srand(time(0));
        for(int i = 0; i < size; ++i)
        {
                ships[i][direction] = rand()%2;
        }
        for(int i = size; i < ships_count; ++i) {
                ships[i][direction] = horizontal;
        }
}
/// Sets up the ships.
/// Sets up the length and deafault health of each ship.
int** define_ships()
{
        int index = 0;
        int parameters = 5;
        int ships_count = 10;
        int** ships = new int* [ships_count];
        for (int i = 0; i < ships_count; ++i) {
                ships[i] = new int [parameters];
        }
        for ( int i = 4; i > 0; --i) {
                for(int j = 1; j <= 5 - i; ++j) {
                        ships[index][length] = i;
                        ships[index][health] = i;
                        ++index;
                }
        }
        return ships;
}
/// Randomly sets the coordintaes of the ships.
void generate_coordinates(int* ships)
{
        int size = 10;
        int new_size = size - ships[length] + 1;
        int dir = ships[direction];
        int x1;
        int y1;
        if(dir == horizontal) {
                x1 = rand()%size + 1;
                y1 = rand()%new_size + 1;
        } 
        else {
                x1 = rand()%new_size + 1;
                y1 = rand()%size + 1;
        }
        ships[x] = x1;
        ships[y] = y1; 
}

/// Checks if the generated coordinates overlap any of the existing ships for
//horizontal ships.
bool check_for_horizontal(int len, int x1, int y1, int** sea)
{
        for(int i = 0; i < len; ++i) {
                if(sea[x1][y1 + i] != 0) {
                        return false;
                }
        }
}

/// Checks if the generated coordinates overlap any of the existing ships for
//vertical ships.
bool check_for_vertical(int len, int x1, int y1, int** sea)
{
        for(int i = 0; i < len; ++i) {
                if(sea[x1+i][y1] != 0) {
                        return false;
                }
        }
}

/// Checks if the generated coordinates overlap any of the existing ships.
bool check(int* ships, int** sea)
{
        int x1 = ships[x];
        int y1 = ships[y];
        int len = ships[length];
        int dir = ships[direction];
        if(dir == horizontal) {
                return check_for_horizontal(len, x1, y1, sea);
        } else {
                return  check_for_vertical(len, x1, y1, sea);
        }
        return true;
}

/// Sets the vertical ship's surrounding squares to '2'.
void set_number_two_horizontal(int* ships, int** real_sea) 
{
        int x1 = ships[x];
        int y1 = ships[y];
        int len = ships[length];
        int number = 2;
        int size = y1 + len;
        for(int i = y1 - 1; i <= size; ++i) {
                real_sea[x1 - 1][i] = number;
                real_sea[x1 + 1][i] = number;
        }
        real_sea[x1][y1-1] = number;
        real_sea[x1][size] = number;
}

/// Sets the horizontal ship's surrounding squares to '2'.
void set_number_two_vertical(int* ships, int** real_sea)
{
        int x1 = ships[x];
        int y1 = ships[y];
        int len = ships[length];
        int number = 2;
        int size = x1 + len;
        for(int i = x1 - 1; i <= size; ++i) {
                real_sea[i][y1 - 1] = number;
                real_sea[i][y1 + 1] = number;
        }
        real_sea[x1 - 1][y1] = number;
        real_sea[size][y1] = number;
}

/// Sets the ship's surrounding squares to '2'.
void set_number_two_around_ship(int* ships,int** real_sea)
{
        int dir = ships[direction];
        if(dir == horizontal) {
                set_number_two_horizontal(ships, real_sea);
        } else {
                set_number_two_vertical(ships, real_sea);
        }
}

/// Sets the coordinates of a horizontal ship.
void set_horizontal(int* ships, int** real_sea)
{
        int x1 = ships[x];
        int y1 = ships[y];
        int len = ships[length];
        for(int i = 0; i < len; ++i) {
                real_sea[x1][y1 + i] = 1;
        }
}

/// Sets the coordinates of a vertical ship.
void set_vertical(int* ships, int** real_sea)
{
        int x1 = ships[x];
        int y1 = ships[y];
        int len = ships[length];
        for(int i = 0; i < len; ++i) {
                real_sea[x1 + i][y1] = 1;
        }
}

/// Sets the generated coordinates of the ship.
void write_in_real_sea(int* ships, int** real_sea)
{
        if(ships[direction] == horizontal) {
                set_horizontal(ships, real_sea);
        } else {
                set_vertical(ships, real_sea);
        }
}

/// Calls the generate_coordinates function and checks if the generated
//coordinates aren't overlapping any of the existing ships.
void set_on_board(int** ships, int** real_sea)
{
        int row = 0;
        int ships_count = 10;
        while(ships_count != 0) {
                generate_coordinates(ships[row]);
                if(check(ships[row], real_sea)) {
                        write_in_real_sea(ships[row], real_sea);
                        set_number_two_around_ship(ships[row],real_sea);
                        ++row;
                        --ships_count;
                }
        }
}
/// Checks if the ship is sunk.
int sunk(int health, int ships_count)
{
        if(health == 0) {
                std::cout << "Ship is sunk!!!" << std::endl << std::endl;
                --ships_count;
        }
        return ships_count;
}

/// Checks if the shot hit a horizontal ship.
bool check_horizontal_ship(int* ships, int x1, int y1)
{
        int ship_x = ships[x];
        int ship_y = ships[y];
        int len = ships[length];
        for(int i = 0; i < len; ++i) {
                if((ship_x == x1) && (ship_y + i == y1)) {
                        return true;
                }
        }
        return false;  
}

/// Checks if the shot hit a vertical ship.
bool check_vertical_ship(int* ships, int x1, int y1)
{
        int ship_x = ships[x];
        int ship_y = ships[y];
        int len = ships[length];
        for(int i = 0; i < len; ++i) {
                if((ship_x + i == x1) && (ship_y == y1)) {
                        return true;
                }
        }
        return false;
}

/// Calls the sunk function, updates the health of the given ship and prints
//a message.
void check_in(int* ships, int x1, int y1, char** sea, int &ships_count)
{
        std::cout << "\nHit!!!" << std::endl << std::endl;
        --ships[health];
        sea[x1][y1] = '*';
        ships_count = sunk(ships[health], ships_count);
}
/// Checks if the shot made by player hit any of the ships.
int check_ships(int** ships, int x1, int y1, char** sea, int &ships_count, bool& hit)
{
        int count = 10;
        int dir;
        bool check;
        for(int i = 0; i< count; ++i) {
                dir = ships[i][direction];
                if(dir == horizontal) {
                        check = check_horizontal_ship(ships[i], x1, y1);      
                } else {
                        check = check_vertical_ship(ships[i], x1, y1);
                }
                if(check == true) {
                        check_in(ships[i], x1, y1, sea, ships_count);
                        hit = true;
                        break;
                }
        }
        if(check == false) {
                std::cout << "Miss!!!" << std::endl <<std::endl;
                sea[x1][y1] = '.';
        }
        return ships_count;
}
/// Verifies if entered coordinates are in the right format.
bool valid_input(std::string number)
{
        const int size = 10;
        std::string str[size] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
        for(int i = 0; i < size; ++i) {
                if(number == str[i]) {
                        return true;
                }
        }
        return false;
}
/// Receives coordinates from console and proceeds those.
void input(int &x1, int &y1) 
{
        std::string x_coordinate;
        std::string y_coordinate;
        bool is_valid = true;
        while(is_valid) {
                is_valid = false;
                std::cout << "Please enter X and Y coordinates." << std::endl << std::endl;
                std::cout << "X = ";
                getline(std::cin, x_coordinate);
                std::cout << std::endl;
                std::cout << "Y = " ;
                getline(std::cin, y_coordinate);
                if(!(valid_input(x_coordinate) && valid_input(y_coordinate))) {
                        std::cout << "please enter number in range 1 to 10." << std::endl;
                        is_valid = true;
                }
        }
        x1 = std::stoi(x_coordinate);
        y1 = std::stoi(y_coordinate);
}

/// Checks if the shot with the same coordinates was already made.
bool already_hit_or_miss(int x1, int y1, char** sea)
{
        if(sea[x1][y1] == '.') {
                std::cout << "Already miss!!!" << std::endl;
                return false;
        }
        if(sea[x1][y1] == '*') {
                std::cout << "Already hit!!!" << std::endl;
                return false;
        }
        return true;
}
/// Player shoots at computer's ships.
void player_turn(char** sea, int** ships, int& ships_count)
{
        int x1;
        int y1;
        bool hit = true;
        while(hit) {
                hit = false;
                print(sea);
                std::cout << "Your turn!" << std::endl;
                input(x1, y1);
                if(already_hit_or_miss(x1, y1, sea)) {
                        ships_count = check_ships(ships, x1, y1, sea, ships_count, hit);
                }
                if(ships_count == 0) {
                        hit = false;
                }
        }
}

/// Checks the state of the ship (hit or sunk);
int check_cpu_ships( bool& hit, int ships_count)
{
        std::string status;
        bool c = true;
        hit = true;
        while(c) {
                c = false;
                getline(std::cin,status);
                if ( status == "Hit" ) {
                        break;
                }
                if ( status == "Sunk" ) {
                        --ships_count;
                        break;
                }
                if ( status == "Miss" ) {
                        hit = false;
                        break;
                }
                std::cout << "Incorrect command. Please enter again." << std::endl;
                c = true;
                }
        return ships_count;
}

void cpu_turn(int& ships_count)
{
        int x1;
        int y1;
        bool hit = true;
        while(hit) {
                hit = false;
                std::cout << "My turn!\nPlease enter" <<std::endl;
                std::cout << "Hit -  if i hit the ship " << std::endl;
                std::cout << "Miss - if i miss" << std::endl;
                std::cout << "Sunk - if the ship is sunk" << std::endl << std::endl; 
                x1 = rand()%10 + 1;
                y1 = rand()%10 + 1;
                std::cout << "X = " << x1 << std::endl;
                std::cout << "Y = " << y1 << std::endl;
                ships_count = check_cpu_ships(hit, ships_count);
                if(ships_count == 0) {
                        hit = false; 
                }
        }
}

void shoot(char** sea, int** ships)
{
        int player_ships_count = 10;
        int cpu_ships_count = 10;
        bool continue_game = true;
        while(continue_game) {
                player_turn(sea, ships, player_ships_count);
                if(player_ships_count == 0 ) {
                        std::cout << "Congratulations!!! You Won the game!!!" << std::endl;
                        continue_game = false;
                }
                cpu_turn(cpu_ships_count);
                if(cpu_ships_count == 0 ) {
                        std::cout << "Sorry!!! You Lost the game!!!" << std::endl;
                        continue_game = false;
                }
        }
}

void battleship()
{
        char** ptr_to_sea = create_sea_for_preview();
        //  print(ptr_to_sea);
        int** ptr_to_real_sea = create_real_sea();
        int** ptr_to_ships = define_ships();
        set_direction(ptr_to_ships);
        set_on_board(ptr_to_ships, ptr_to_real_sea);
        //print_real_sea(ptr_to_real_sea);
        shoot(ptr_to_sea, ptr_to_ships);
}

void start()
{
        std::cout << "Please enter 'Start' to run the game" << std::endl;
        std::cout << "Enter 'Q' to quit the game" << std::endl;
        std::string status;
        getline(std::cin, status);
        if(status == "Start") {
                battleship();
        }
        if(status == "Q") {
                std::cout << "Bye" <<std::endl;
        } else {
                std::cout << "Incorrect command" << std::endl;
        }
}
