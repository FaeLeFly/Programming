
#include <iostream>
#include <string>
using namespace std;
void pathrecur(int x, int y ,int *i);
string maze[25] = {					
    "####B######################",
    "# #       #   #      #    #",
    "# # # ###### #### ####### #",
    "# # # #       #   #       #",
    "#   # # ######### # ##### #",
    "# # # #   #       #     # #",
    "### ### ### ############# #",
    "# #   #     # #           #",
    "# # #   ####### ###########",
    "# # # #       # #         C",
    "# # ##### ### # # ####### #",
    "# # #     ### # #       # #",
    "#   ##### ### # ######### #",
    "######### ### #           #",
    "# ####### ### #############",
    "A           #   ###   #   #",
    "# ############# ### # # # #",
    "# ###       # # ### # # # #",
    "# ######### # # ### # # # F",
    "#       ### # #     # # # #",
    "# ######### # ##### # # # #",
    "# #######   #       #   # #",
    "# ####### ######### #######",
    "#         #########       #",
    "#######E############D######"
};

int main() {
    int x, y;
    int i = 0;
    cin >> x >> y;
    if ((x < 0 || x >28) || (y>28 || y < 0)) {
        cout << "Не верные координаты";
        return 0;
    }
        pathrecur(x, y, &i);
        if (i == 0) cout << "Выхода нет";
}

void pathrecur(int x, int y, int* i) {
    char wall = '#';
    char path = ' ';
    if (maze[y][x] == wall) {
        return;
    }

    if (maze[y][x] != path) {
        cout << maze[y][x];
        *i = 1;
        return;
    }

    maze[y][x] = wall;

    pathrecur(x + 1, y, i);
    pathrecur(x, y + 1, i);
    pathrecur(x - 1, y, i);
    pathrecur(x, y - 1, i);
}