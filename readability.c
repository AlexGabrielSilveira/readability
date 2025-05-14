#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void) {
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float L = ((float) letters / words) * 100;
    float S = ((float) sentences / words) * 100;
    float coleman_index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(coleman_index);

    if(grade < 1) {
        printf("Before Grade 1...\n");
    }else if(grade >= 16) {
         printf("Grade 16+\n");
    }
    else {
        printf("Grade %d\n", grade);
    }

}

int count_letters(string text) {
    int count = 0;

    for(int i = 0, str = strlen(text); i < str; i++) {
        if(isalpha(text[i])){
            count++;
        }
    }
    return count;
}
int count_words(string text) {
    int count = 1;

    for(int i = 0; text[i] != '\0'; i++) {
        if(isspace(text[i])){
            count++;
        }
    }
    return count;
}
int count_sentences(string text) {
    int count = 0;

    for(int i = 0, str = strlen(text); i < str; i++) {

        if (strchr(".?!", text[i])) {
            count++;
        }
    }
    return count;
}



