#include <iostream>
#include <stdlib.h>
#include <random>

using namespace std;


string vars[] = {"rock", "paper", "scissors", "lizard", "spock"};
int variables[] = {0, 1, 2, 3, 4};
int rules[5][2] = {{2, 3}, {0, 4}, {1, 3}, {1, 4}, {2, 0}};

string game(int computer1, int computer2){
    if (computer1 == computer2)
        return "Tie game.";
    else if((computer1 - computer2 + 5) % 5 == rules[computer1][0] || (computer1 - computer2 + 5) % 5 == rules[computer1][1])
        return "P1";
    else
        return "P2";
}

int main(){

    std::mt19937 rand;
    rand.seed(std::random_device()());
    int arrayLength = sizeof(vars) / sizeof(vars[0]);

    int computer1, computer2;
    int computer1Wins = 0;
    int computer2Wins = 0;

    //refactor this part
    while(computer1Wins < 2 && computer2Wins < 2){
        
        std::uniform_int_distribution<int> dist(0, arrayLength-1);
        computer1 = dist(rand);
        computer2 = dist(rand);

        string result = game(computer1, computer2);
        cout << result << endl;
        cout << "Player 1 chose: " << vars[computer1] << "\nPlayer 2 chose: " << vars[computer2] << endl;
        
        if(result == "P1")
            computer1Wins++;
        else if(result == "P2")
            computer2Wins++;
        
        if(computer1Wins == 2 || computer2Wins == 2){
            if(computer1Wins == 2)
                cout << "\n\nPlayer 1 wins the game!" << endl;
            else
                cout << "\n\nPlayer 2 wins the game!" << endl;
                return 0;
        }
    }
    return 0;
}
