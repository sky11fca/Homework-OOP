#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom comparison function for qsort
int compare(const void *a, const void *b) {
    const char *word1 = *(const char **)a;
    const char *word2 = *(const char **)b;

    int len1 = strlen(word1);
    int len2 = strlen(word2);

    // If lengths are different, sort by length in descending order
    if (len1 != len2)
        return len2 - len1;

    // If lengths are same, sort alphabetically
    return strcmp(word1, word2);
}

int main() {
    char sentence[1000];
    printf("Enter a sentence: ");
    scanf("%[^\n]", sentence);

    // Split sentence into words
    char *words[100]; // Maximum 100 words
    int wordCount = 0;
    char *token = strtok(sentence, " ");
    while (token != NULL) {
        words[wordCount++] = strdup(token);
        token = strtok(NULL, " ");
    }

    // Sort the words
    qsort(words, wordCount, sizeof(char *), compare);

    // Print the sorted words
    printf("Sorted words:\n");
    for (int i = 0; i < wordCount; ++i) {
        printf("%s\n", words[i]);
        free(words[i]); // Free memory allocated by strdup
    }

    return 0;
}