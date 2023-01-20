#include <iostream>
#include <stdlib.h>
#include <random>

using namespace std;

// Function to get the number of variables
int getVariables() {
    int n;
    cout << "Enter the number of variables: ";
    cin >> n;
    return n;
}

// Function to determine the winner
string game(int computer1, int computer2, string vars[], int rules[][2], int n) {
    if (computer1 == computer2)
        return "Tie";
    else if (vars[computer1] == vars[rules[computer2][0]] && rules[computer2][0] < n)
        return "P1";
    else if (vars[computer1] == vars[rules[computer2][1]] && rules[computer2][1] < n)
        return "P2";
    else
        return "Error";
}

int main() {
    // Get the number of variables
    int n = getVariables();

    // Create an array to store the variables
    string vars[n];
    int variables[n];
    int rules[n][2];

    // Input the variables
    for (int i = 0; i < n; i++) {
        cout << "Enter variable " << i + 1 << ": ";
        cin >> vars[i];
        variables[i] = i;
    }

    // Input the rules
    for (int i = 0; i < n; i++) {
        cout << "Enter the 2 variables that " << vars[i] << " beats separated by a space: ";
        cin >> rules[i][0] >> rules[i][1];
        // decrement by 1 to match the array index
        rules[i][0]--;
        rules[i][1]--;
    }

    // Generate random number generator
    std::mt19937 rand;
    rand.seed(std::random_device()());

    int computer1, computer2;
    int computer1Wins = 0;
    int computer2Wins = 0;

    while(computer1Wins < 2 && computer2Wins < 2){
        
        std::uniform_int_distribution<int> dist(0, n-1);
        computer1 = dist(rand);
        computer2 = dist(rand);

        string result = game(computer1, computer2, vars, rules, n);
        
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