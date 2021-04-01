#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt user for text
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    /* Determine text reading level */

    // Average number of letters per 100 words in text
    float L = 100 * letters / (float) words;

    // average number of sentences per 100 words in text
    float S = 100 * sentences / (float) words;

    // Coleman-Liau index readability test
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = (int)round(index);

    if (grade > 16)
    {
        printf("Grade 16+\n");
    }

    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

// Count letters
int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters += 1;
        }
    }
    return letters;
}

// Count words
int count_words(string text)
{
    int words = 0;
    int n = strlen(text);

    if (n > 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (text[i] == ' ')
            {
                words += 1;
            }
        }
        words += 1;
    }
    return words;
}

// Count sentences
int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences += 1;
        }
    }
    return sentences;
}
