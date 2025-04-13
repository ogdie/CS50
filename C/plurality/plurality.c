#include <cs50.h>
#include <stdio.h>
#include <string.h>
#define MAX 9

typedef struct
{
    string name;
    int votes;
}candidate;

candidate candidates[MAX];
int candidate_count;

bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

void print_winner(void)
{
    int maximum_vote = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > maximum_vote)
        {
            maximum_vote = candidates[i].votes;
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == maximum_vote)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Insert cadidates!");
        return 1;
    }

    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Invalid number of candidates!");
        return 2;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        if(!vote(name))
        {
            printf("Invalid vote!");
        }
    }
    print_winner();
}
