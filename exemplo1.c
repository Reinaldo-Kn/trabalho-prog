#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Global Strings
char word [50];
char guessed_letters[20];
char user_guess[] = "";
char blank[1] = "-";

//Global Integers
int random_number;
int word_len;
int user_input;
int attempts = 10;

//Function Declarations
void start_game();
void get_input();
void print_blanks();
void draw_platform();
void get_word();

int main(void)
{
    //Game Loop
    while(1)
    {
        start_game();

        while(attempts > 0)
        {
            system("cls");

            //If they have guessed all the letters they win
            if(strlen(guessed_letters) == word_len - 1)
            {
                print_blanks();
                break;
            }
            //Else, decr attempts and try again
            else
            {
                printf("Attempts Remaining: %i\n", attempts);
                print_blanks();
                get_input();
            }
        }

        system("cls");

        //If they won
        if(attempts > 0)
        {
            print_blanks();
            printf("You Won! Play again?\n");
        }
        //If they lost
        else
        {
            draw_platform();
            printf("You Lost! The word was %s, Play again?\n", word);
        }

        scanf("%i", &user_input);

        switch(user_input)
        {
            case 0:
                return 0;
            default:
                continue;
        }
    }
}

void start_game()
{
    //Initializes Game
    get_word();
    word_len = strlen(word);
    memset(guessed_letters, 0, sizeof guessed_letters);
    attempts = 10;
}

void get_input()
{
    //Gets guess from user and checks
    //To see if that letter is in the word

    int i;
    int letter_hit = 0; //Used to tell if the guess letter is in the word

    printf("\nYour guess: \n");
    scanf(" %c", user_guess);

    for(i=0; i < word_len; i++)
    {
        if(user_guess[0] == word[i])
        {
            guessed_letters[i] = user_guess[0];
            letter_hit ++;
        }
    }

    if(letter_hit > 0)
    {
        return;
    }
    else
    {
        attempts --;
    }
}

void print_blanks()
{
    /////////////////////////////////////////////////
    /// Prints out a number of blanks equal to the
    /// Length of the word
    /// Then fills the blanks with the guessed letters
    /////////////////////////////////////////////////

    int i, j;

    draw_platform();
    for(i=0; i<word_len; i++)
    {
        printf("%c", guessed_letters[i]);
        printf(" ");
    }
    printf("\n");

    for(j=0; j<word_len - 1; j++)
    {
        printf("%s", blank);
        printf(" ");
    }
    printf("\n");
}

void draw_platform()
{
    /////////////////////////////////////////////////
    /// Draws a new segment onto
    /// The platform every time
    /// The user gets a wrong guess
    /////////////////////////////////////////////////

    char *platform[]={

                     "      ===\n",

                     "        |\n"
                     "        |\n"
                     "        |\n"
                     "       ===\n",

                     "   =====|\n"
                     "        |\n"
                     "        |\n"
                     "        |\n"
                     "       ===\n",

                     "  |=====|\n"
                     "        |\n"
                     "        |\n"
                     "        |\n"
                     "       ===\n",

                     "  |=====|\n"
                     "  O     |\n"
                     "        |\n"
                     "        |\n"
                     "       ===\n",

                     "  |=====|\n"
                     "  O     |\n"
                     "  |     |\n"
                     "        |\n"
                     "       ===\n",

                     "  |=====|\n"
                     "  O     |\n"
                     "  |-    |\n"
                     "        |\n"
                     "       ===\n",

                     "  |=====|\n"
                     "  O     |\n"
                     " -|-    |\n"
                     "        |\n"
                     "       ===\n",

                     "  |=====|\n"
                     "  O     |\n"
                     " -|-    |\n"
                     "  |     |\n"
                     "       ===\n",

                     "   |=====|\n"
                     "   O     |\n"
                     "  -|-    |\n"
                     "  //     |\n"
                     "       ===\n"

    };

    switch(attempts)
    {
    case 9:
        printf("\n\n%s\n", platform[0]);
        break;
    case 8:
        printf("\n\n%s\n", platform[1]);
        break;
    case 7:
        printf("\n\n%s\n", platform[2]);
        break;
    case 6:
        printf("\n\n%s\n", platform[3]);
        break;
    case 5:
        printf("\n\n%s\n", platform[4]);
        break;
    case 4:
        printf("\n\n%s\n", platform[5]);
        break;
    case 3:
        printf("\n\n%s\n", platform[6]);
        break;
    case 2:
        printf("\n\n%s\n", platform[7]);
        break;
    case 1:
        printf("\n\n%s\n", platform[8]);
        break;
    case 0:
        printf("\n\n%s\n", platform[9]);
        break;
    }
}

void get_word()
{
    /////////////////////////////////////////////////
    /// Scans a file to get the total number of lines
    /// The line total is then used as a max range
    /// For the random number
    /// The word that is on the random line is the word
    /// That will be used for the game
    /////////////////////////////////////////////////

    FILE *fp;
    int line_number = 0;
    char current_word[50];

    fp = fopen("dictionary.txt","r");

    if(fp == NULL)
    {
        perror("Error in opening file");
    }

    //While not end of file, incr line number
    while(fgets(current_word, 50, fp) != NULL)
    {
        line_number++;
    }

    random_number = rand() % line_number;

    //Start from top of file
    rewind(fp);

    //Goes to whatever line the random number equals to find the
    //Random word
    for(line_number = 0; line_number != random_number; line_number++)
    {
        fgets(current_word, 50, fp);
    }

    strcpy(word, current_word);
    fclose(fp);
}