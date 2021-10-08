// Guess the right UAT room number with a professor in it to keep your grade up

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
    // Array of UAT professors
    const int MAX_PROFESSOR = 10;
    string professor[MAX_PROFESSOR] = { "Marquit", "Clark", "Beam", "Brokaw", "Hromas",
        "Moore", "Prater", "Peters", "Vasquez", "Belanger" };

    // Array of UAT room #s
    const int MAX_ROOM = 20;
    int roomNumber[MAX_ROOM] = { 106, 107, 108, 135, 201, 202, 203, 204, 205, 206, 207,
        208, 231, 232, 234, 235, 244, 245, 252, 253 };

    // Array of letter grades
    const int MAX_GRADES = 5;
    string grade[MAX_GRADES] = { "F", "D", "C", "B", "A" };

    // Seed for random #
    srand(static_cast<unsigned int>(time(0)));

    // Used to repeat the y/n section if player inputs something that doesn't match a case
    bool repeat;
    // Used to break the loop if the player does not want to play again
    int x;
    // Used to keep track of subsequent wrong guesses
    int tries;
    int currentGrade;
    // Used for player input
    int guess;
    char playAgain;

    do
    {
        currentGrade = 2;
        tries = 0;
        x = 0;

        // Randomly shuffles the elements in the roomNumber array
        for (int i = 0; i < 20; i++)
        {
            int rnd = rand() % 20;
            int rnd2 = rand() % 20;

            while (rnd == rnd2)
            {
                rnd2 = rand() % 20;
            }
            int tmp = roomNumber[rnd2];
            roomNumber[rnd2] = roomNumber[rnd];
            roomNumber[rnd] = tmp;
        }

        chrono::duration<int, milli> timespan(2000);

        // Game begins
        cout << "Welcome to the Letter Grade Game.\n\n";

        this_thread::sleep_for(timespan);

        cout << "Guess a classroom and be in one with a professor in it to increase your grade.\n\n";

        this_thread::sleep_for(timespan);

        cout << "Once you hear the bell ring, your grade will change and the professors will move to different classrooms.\n\n";

        this_thread::sleep_for(timespan);

        cout << "Grade A wins, grade F loses. Are you ready?\n\n\n\n";

        this_thread::sleep_for(timespan);

        do
        {
            // Random professor will be in the room each right guess
            int p = rand() % 10;
            
            // Characters to keep the following if else conditions shorter
            int a = roomNumber[0];
            int b = roomNumber[1];
            int c = roomNumber[2];
            int d = roomNumber[3];
            int e = roomNumber[4];
            int f = roomNumber[5];
            int g = roomNumber[6];
            int h = roomNumber[7];
            int i = roomNumber[8];
            int j = roomNumber[9];

            chrono::duration<int, milli> timespan(100);

            printf("Rooms to pick:\n");
            this_thread::sleep_for(timespan);

            printf("106, 107, 108, 135, 201, 202, 203, 204, 205, 206, 207, 208, 231, 232, 234, 235, 244, 245, 252, & 253.\n\n");
            this_thread::sleep_for(timespan);

            cout << "Your current grade: " << grade[currentGrade] << "\n\n";
            this_thread::sleep_for(timespan);

            printf("Enter a Room Number: ");
            cin >> guess;
            cout << endl;
            ++tries;

            // Wrong guess
            if ((tries != 3) && (guess != a && guess != b && guess != c && guess != d && guess != e && guess != f && guess != g && guess != h && guess != i && guess != j))
            {
                cout << "You entered room " << guess << ", but there was no professor inside.\n\n";

                chrono::duration<int, milli> timespan(2000);
                this_thread::sleep_for(timespan);

                cout << "There is still time to keep searching.\n\n\n\n";

                this_thread::sleep_for(timespan);
            }
            // 3 wrong guesses in a row
            else if ((tries == 3) && (guess != a && guess != b && guess != c && guess != d && guess != e && guess != f && guess != g && guess != h && guess != i && guess != j))
            {
                cout << "You entered room " << guess << ", but there was no professor inside.\n\n";

                chrono::duration<int, milli> timespan(2000);
                this_thread::sleep_for(timespan);

                PlaySound(TEXT("bell.wav"), NULL, SND_FILENAME);

                cout << "Oh no, the bell rang.\n\n\n\n";

                this_thread::sleep_for(timespan);

                // Shuffles the rooms with professors in them
                for (int i = 0; i < 20; i++)
                {
                    int rnd = rand() % 20;
                    int rnd2 = rand() % 20;

                    while (rnd == rnd2)
                    {
                        rnd2 = rand() % 20;
                    }
                    int tmp = roomNumber[rnd2];
                    roomNumber[rnd2] = roomNumber[rnd];
                    roomNumber[rnd] = tmp;
                }

                tries = 0;

                currentGrade -= 1;
            }
            // Right guess
            else
            {
                cout << "You are glad you made this guess. Professor " << professor[p] << " is in this classroom.\n\n";

                chrono::duration<int, milli> timespan(2000);
                this_thread::sleep_for(timespan);

                cout << "You wait for the bell to ring...\n\n\n\n";

                this_thread::sleep_for(timespan);

                PlaySound(TEXT("bell.wav"), NULL, SND_FILENAME);

                // Shuffles the rooms with professors in them
                for (int i = 0; i < 20; i++)
                {
                    int rnd = rand() % 20;
                    int rnd2 = rand() % 20;

                    while (rnd == rnd2)
                    {
                        rnd2 = rand() % 20;
                    }
                    int tmp = roomNumber[rnd2];
                    roomNumber[rnd2] = roomNumber[rnd];
                    roomNumber[rnd] = tmp;
                }

                tries = 0;

                currentGrade += 1;
            }
            // To prevent infinitely repeating above on entering something other than a number
            if (cin.fail())
            {
                cout << "Stop trying to break my program.\n\n\n\n";
                cin.clear();
                cin.ignore(10000, '\n');

                chrono::duration<int, milli> timespan(2000);
                this_thread::sleep_for(timespan);
            }
        } while (currentGrade != 4 && currentGrade != 0);

        // Player grade hit F
        if (currentGrade == 0)
        {
            cout << "Your final grade: " << grade[0] << "\n\n";

            chrono::duration<int, milli> timespan(2000);
            this_thread::sleep_for(timespan);

            cout << "You lost.\n\n";

            this_thread::sleep_for(timespan);

            cout << "Your guessing game wasn't on point today.\n\n";

            this_thread::sleep_for(timespan);

            // Player chooses to replay or leave the game
            do
            {
                cout << "Would you like to play again? y/n: ";
                cin >> playAgain;
                cout << endl;

                switch (playAgain) {
                case 'y':
                case 'Y':
                    cout << "\n\nResetting the game...\n\n";

                    repeat = true;
                    x = 1;

                    this_thread::sleep_for(timespan);
                    break;
                case 'n':
                case 'N':
                    cout << "\n\nGoodbye! Thanks for playing.\n\n";

                    repeat = true;
                    x = 0;

                    this_thread::sleep_for(timespan);
                    break;
                default:
                    cout << "\n\nPlease respond with y/n.\n\n";
                    continue;
                }
            } while (!repeat);
        }
        // Player grade hit A
        else
        {
            cout << "Your final grade: " << grade[4] << "\n\n";

            chrono::duration<int, milli> timespan(2000);
            this_thread::sleep_for(timespan);

            cout << "You won!\n\n";

            this_thread::sleep_for(timespan);

            cout << "You might be the world champion of guessing.\n\n";

            this_thread::sleep_for(timespan);

            // Player chooses to replay or leave the game
            do
            {
                cout << "Would you like to play again? y/n: ";
                cin >> playAgain;
                cout << endl;

                switch (playAgain) {
                case 'y':
                case 'Y':
                    cout << "\n\nResetting the game...\n\n";

                    repeat = true;
                    x = 1;

                    this_thread::sleep_for(timespan);
                    break;
                case 'n':
                case 'N':
                    cout << "\n\nGoodbye! Thanks for playing.\n\n";

                    repeat = true;
                    x = 0;

                    this_thread::sleep_for(timespan);
                    break;
                default:
                    cout << "\n\nPlease respond with y/n.\n\n";
                    repeat = false;
                }
            } while (!repeat);
        }
    } while (x == 1);

    return 0;
}