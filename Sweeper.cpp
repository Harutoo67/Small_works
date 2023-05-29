#include <iostream>
#include <cstdlib>
#include <ctime>
// # //

// "" //

// Global Information
const int width = 8;
const int height = 8;
const int number_of_mines = width*height * 15.625 / 100; // It's a special formula
int game_map[height][width];

int main()
{
    srand( time(nullptr) );


    for(int mines_on_map = 0; mines_on_map < number_of_mines;) // Loop to distribute the mines on the map
    {
        const int hei = 0 + rand() % (height - 1); // Height random index
        const int wid = 0 + rand() % (width - 1); // Width random index

        if (game_map[hei][wid] != 9) // As the map can't have the number 9 on it, I put it as a pointer to the bomb
        {
            game_map[hei][wid] = 9; // 9 is the bomb
            mines_on_map++;
            for (int i = hei-1; i <= hei + 1; i++) // Here we add numbers next to the bombs
                for (int j = wid - 1; j <= wid + 1; j++) {

                    if (i < 0 || i > height-1 || j < 0 || j > width-1) continue; // In case "hei" and "wid" go off the map

                    if (game_map[i][j] != 9)
                        game_map[i][j]++; // And finally raise by one if everything is correct
                    else continue;
                }
        }
    }

    // Map Print
    std::cout << "\n\n\n   Minesweeper" << std::endl;
    std::cout << "------------------" << std::endl;

    for(auto & hei : game_map)
    {
        std::cout << "|";
        for (int &wid: hei)
            if (wid == 9)
                std::cout << "*" << " ";
            else
                std::cout << wid << " ";
        std::cout << "|" << std::endl;
    }
    std::cout << "------------------" << std::endl;
    return 0;
}