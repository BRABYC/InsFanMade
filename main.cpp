#include <iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include <string>
#include <iomanip>
#include <map> 
#include <cstdlib>
#include "Item.h"
#include "Player.h"
#include "Storage.h"
#include "Game.h"
#include "Windows.h"
#include <thread>
#include <chrono>


// Vertex Shader source code
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
//Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";

using namespace std;

#ifdef _WIN32
const std::string os_name = "Windows";
#elif __APPLE__
const std::string os_name = "Mac OS";
#elif __linux__
const std::string os_name = "Linux";
#else
const std::string os_name = "Unknown";
#endif

int main()
{
	srand(time(NULL));
    HWND hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_MAXIMIZE);
	bool gameLoop;
    Player P;
    Game game(P, gameLoop);
    game.StartScreen();
    //this_thread::sleep_for(chrono::seconds(3));
	game.loadingAnimation();

    P.loadInventory();

    while (gameLoop){
		if (os_name == "Windows") system("cls");
        else system("clear"); 
        game.showUI();
        game.input();
    }

    P.saveInventory();


	return 0;
}
