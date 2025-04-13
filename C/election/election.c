#include <cs50.h>
#include <stdio.h>
#include <string.h>

//define max of cadidates;
#define MAX 9

//struct for the name and votes from each candidate;
typedef struct
{
    string name;
    int votes;
} candidate;

//array and counter from candidates;
candidate candidates[MAX];
int candidates_count;

//function to allocate the number of votes;
bool votes(string name)
{
    for (int i = 0; i < candidates_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

//function to print the winner;
void print_winner(void)
{
int max_votes = 0;
for (int i = 0; i < candidates_count; i++)
{
    if (candidates[i].votes > max_votes)
    {
        max_votes = candidates[i].votes;
    }
}
for (int i = 0; i < candidates_count; i++)
{
    if (candidates[i].votes == max_votes)
    {
        printf("O vencedor(a) foi: %s, com %i votos!\n", candidates[i].name, candidates[i].votes);
    }
}
}

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Put valid arguments\n");
        return 1;
    }
    //populate array of candidates;
    candidates_count = argc - 1;
    if (candidates_count > MAX)
    {
        printf("Max of candidates is 9\n");
        return 2;
    }
    for (int i = 0; i < candidates_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }
    int voters_count = get_int("Nº of voter: ");
    for (int i = 0; i < voters_count; i++)
    {
        string name = get_string("Vote: ");
        if (!votes(name))
        {
            printf("Invalid vote\n");
        }
    }
    print_winner();
}
