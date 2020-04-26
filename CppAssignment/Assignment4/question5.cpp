//
// Created by Archibald Chain on 2020/4/26.
//


#include <iostream>
#include <cstring>


#define START_CMD 0
#define STOP_CMD 1
#define RESTART_CMD 2
#define RELOAD_CMD 3
#define STATUS_CMD 4
#define EXIT_CMD 5

using namespace std;

const char *str[] = {"start", "stop", "restart", "reload", "status", "exit"};
int console();

int main(){
    return console();
}

/**
 * output the command at index i
 * @param i
 */
void command_recognized(int i){
    cout << "command <"<< str[i] << "> recognized.\n";
}

/**
 * console implement
 * @return
 */
int console(){
    cin.clear();
    string commands;
    while (printf(">") && getline(cin, commands)){
        int index = 0;
        for (int i = 0; i < 6; ++i) {
            if(strcmp(commands.c_str(), str[i]) == 0){
                index = i;
                break;
            }
            index = 6;
        }
        switch (index) {
            case START_CMD:
                command_recognized(START_CMD);
                break;
            case STOP_CMD:
                command_recognized(STOP_CMD);
                break;
            case RESTART_CMD:
                command_recognized(RESTART_CMD);
                break;
            case RELOAD_CMD:
                command_recognized(RELOAD_CMD);
                break;
            case STATUS_CMD:
                command_recognized(STATUS_CMD);
                break;
            case EXIT_CMD:
                cout << "Terminating...\n";
                return 0;
            default:
                cout << "Invalid command\n";
        }

    }
    return 1;
}


