#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int add(int x, int y);
int subtraction(int x, int y);
int division(int x, int y);
int multiplication(int x, int y);
void result(string n, int x, int y);

// Math
// Why do I even need this?
int MAX_SIZE = 4;
// int STRING_SIZE = 10;
char math[4][10] = {"Multiply", "Divide", "Add", "Subtract"};

// could we rewrite main?
int main(void)
{

    // Get user input
    int x = get_int("x: ");
    int y = get_int("y: ");

    // Multiply, divide, add, subtract
    string response = get_string("Multiply, Divide, Add, or Subtract?\n");

    // Case sensitive
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (islower(response[i]) && i == 0)
        {
            response[i] = toupper(response[i]);
        }
        else
        {
            if (isupper(response[i]) && i != 0)
            {
                response[i] = tolower(response[i]);
            }
        }
    }

    result(response, x, y);

    return 0;
}

// Result
void result(string n, int x, int y)
{
    // Answer
    int answer = 0;
    bool found = false;

    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (strcmp(n, math[i]) == 0)
        {
            found = true;

            if (strcmp(math[i], "Multiply") == 0)
            {
                answer = multiplication(x, y);
            }
            else if (strcmp(math[i], "Divide") == 0)
            {
                if (y == 0)
                {
                    printf("Error! Can't divide by 0\n");
                    return;
                }
                answer = division(x, y);
            }
            else if (strcmp(math[i], "Add") == 0)
            {
                answer = add(x, y);
            }
            else
            {
                answer = subtraction(x, y);
            }
        }
    }
    if (found == false)
    {
        printf("Error! Invalid operation entered.\n");
    }
    else
    {
        printf("Answer is : %i\n", answer);
    }
}

int add(int x, int y)
{
    int answer = x + y;
    return answer;
}

int subtraction(int x, int y)
{
    int answer = x - y;
    return answer;
}

int division(int x, int y)
{
    int answer = x / y;
    return answer;
}

int multiplication(int x, int y)
{
    int answer = x * y;

    return answer;
}
