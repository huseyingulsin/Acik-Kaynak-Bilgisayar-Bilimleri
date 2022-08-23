#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS_IN_SENTENCE_GENERATION 20
#define MAX_WORD_LENGTH 100
#define MAX_SENTENCE_LENGTH 1000

typedef struct WordStruct
{
    char *word;
    struct WordProbability *prob_list;
    //... Add your own fields here
    int probabilityCount; // keep prob_list array size
    int probListCapacity; // keep prob_list array capacity
} WordStruct;

typedef struct WordProbability
{
    struct WordStruct *word_struct_ptr;
    //... Add your own fields here
    int occurence; // keep occurences of words for detecting best match
} WordProbability;

/************ LINKED LIST ************/
typedef struct Node
{
    WordStruct *data;
    struct Node *next;
} Node;

typedef struct LinkList
{
    Node *first;
    Node *last;
    int size;
} LinkList;

/* function declarations to avoid warnings */
int add(LinkList *link_list, WordStruct *data);
void fill_dictionary(FILE *fp, int words_to_read, LinkList *dictionary);
int get_random_number(int max_number);
WordStruct *get_first_random_word(LinkList *dictionary);
WordStruct *get_next_random_word(WordStruct *word_struct_ptr);
int generate_sentence(LinkList *dictionary);
int add_word_to_probability_list(WordStruct *first_word,
                                 WordStruct *second_word);
void fill_dictionary(FILE *fp, int words_to_read, LinkList *dictionary);
void free_dictionary(LinkList *dictionary);

/* helper functions */
WordStruct *check_word_exist(LinkList **dictionary, char **str);
int split(const char *str, char c, char ***arr);
char **removeEmptyWords(char **arr, int *arr_size);

/**
 * Add data to new node at the end of the given link list.
 * @param link_list Link list to add data to
 * @param data pointer to dynamically allocated data
 * @return 0 on success, 1 otherwise
 */
int add(LinkList *link_list, WordStruct *data)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        return 1;
    }
    *new_node = (Node){data, NULL};

    if (link_list->first == NULL)
    {
        link_list->first = new_node;
        link_list->last = new_node;
    }
    else
    {
        link_list->last->next = new_node;
        link_list->last = new_node;
    }

    link_list->size++;
    return 0;
}
/*************************************/

/**
 * Get random number between 0 and max_number [0, max_number).
 * @param max_number
 * @return Random number
 */
int get_random_number(int max_number)
{
    /* create a random number between 0 and max_number, max number not included. */
    return rand() % max_number;
}

/**
 * Choose randomly the next word from the given dictionary, drawn   .
 * The function won't return a word that end's in full stop '.' (Nekuda).
 * @param dictionary Dictionary to choose a word from
 * @return WordStruct of the chosen word
 */
WordStruct *get_first_random_word(LinkList *dictionary)
{
    /* get a random number with random function */
    int size = get_random_number(dictionary->size);

    Node *temp = dictionary->first;

    /* go through desired word */
    int i = 0;
    for (i = 0; i < size; i++)
    {
        temp = temp->next;
    }

    // if selected wordstruct does not have enough continusly word, recall fonskiyon again.
    if (temp->data->probabilityCount < 2)
        return get_first_random_word(dictionary);
    return temp->data;
}

/**
 * Choose randomly the next word. Depend on it's occurrence frequency
 * in word_struct_ptr->WordProbability.
 * @param word_struct_ptr WordStruct to choose from
 * @return WordStruct of the chosen word
 */
WordStruct *get_next_random_word(WordStruct *word_struct_ptr)
{
    WordStruct *next_word = NULL;

    // set occurence to -1, if one of them has already equal to 0
    int occurence = -1;

    /* iterate through the word_struct_ptr's probablity list and take highest occurence word. */
    for (int i = 0; i < word_struct_ptr->probabilityCount; i++)
    {
        if (occurence < word_struct_ptr->prob_list[i].occurence)
        {
            occurence = word_struct_ptr->prob_list[i].occurence;
            next_word = word_struct_ptr->prob_list[i].word_struct_ptr;
        }
    }

    return next_word;
}

/**
 * Receive dictionary, generate and print to stdout random sentence out of it.
 * The sentence most have at least 2 words in it.
 * @param dictionary Dictionary to use
 * @return Amount of words in printed sentence
 */
int generate_sentence(LinkList *dictionary)
{
    int wordCount = 1;

    // get first word with expected random num
    WordStruct *first_word = get_first_random_word(dictionary);
    printf("%s ", first_word->word); // print first word
    while (1)
    {
        // get next word due to first word and go with it
        WordStruct *temp = get_next_random_word(first_word);

        printf("%s ", temp->word);

        wordCount++; // increment word count

        /* get last char of the word */
        if (wordCount == MAX_WORDS_IN_SENTENCE_GENERATION || temp->word[strlen(temp->word) - 1] == '.')
        {
            /* if next word ends with '.' than break. */
            break;
        }
        first_word = temp;
    }

    // bring new line after all generated sentences
    printf("\n");
    return wordCount;
}

/**
 * Gets 2 WordStructs. If second_word in first_word's prob_list,
 * update the existing probability value.
 * Otherwise, add the second word to the prob_list of the first word.
 * @param first_word
 * @param second_word
 * @return 0 if already in list, 1 otherwise.
 */
int add_word_to_probability_list(WordStruct *first_word,
                                 WordStruct *second_word)
{
    int sizeOfProb = first_word->probabilityCount;
    int i = 0;
    for (i = 0; i < sizeOfProb; i++)
    {
        char *temp = first_word->prob_list[i].word_struct_ptr->word;
        if (strcmp(temp, second_word->word) == 0) /* if already exists */
        {
            //printf("Find occurence\n");
            /* increment occurence number */
            first_word->prob_list[i].occurence++;
            return 0;
        }
    }

    /* if does not exist */
    /* increment possilbe word count */
    /* add new word to probability struct array */
    sizeOfProb++;
    first_word->probabilityCount = sizeOfProb;
    first_word->prob_list[sizeOfProb - 1].word_struct_ptr = second_word;

    return 1;
}

/**
 * Read word from the given file. Add every unique word to the dictionary.
 * Also, at every iteration, update the prob_list of the previous word with
 * the value of the current word.
 * @param fp File pointer
 * @param words_to_read Number of words to read from file.
 *                      If value is bigger than the file's word count,
 *                      or if words_to_read == -1 than read entire file.
 * @param dictionary Empty dictionary to fill
 */
void fill_dictionary(FILE *fp, int words_to_read, LinkList *dictionary)
{
    // ! Don't need to hendle this, since fp handled at main before

    // if (fp == NULL)
    // {
    //     printf("File doesn't exist");
    //     return;
    // }

    int wordCount = 0;
    // create buffer to keep sentences
    char buffer[MAX_SENTENCE_LENGTH];

    // iterate all file line by line
    while (fgets(buffer, MAX_SENTENCE_LENGTH - 1, fp))
    {
        // remove new line from sentence
        buffer[strlen(buffer) - 1] = '\0';

        /* parse this line to words */
        char **words_arr = NULL;
        int words_arr_size = split(buffer, ' ', &words_arr);
        words_arr = removeEmptyWords(words_arr, &words_arr_size);
        wordCount += words_arr_size;

        // check detected word exist in dictionary earlier
        WordStruct *prev = check_word_exist(&dictionary, &words_arr[0]);

        if (prev == NULL) /* if does not exist */
        {
            prev = malloc(sizeof(WordStruct));
            prev->word = words_arr[0];
            prev->probabilityCount = 0;
            prev->probListCapacity = 100;
            prev->prob_list = (WordProbability *)malloc(sizeof(WordStruct) * prev->probListCapacity);

            // after initialization, add this new word to dict
            add(dictionary, prev);
        }

        for (int i = 1; i < words_arr_size; i++)
        {
            WordStruct *temp = check_word_exist(&dictionary, &words_arr[i]);

            if (temp == NULL) /* if does not exist */
            {
                temp = malloc(sizeof(WordStruct));
                temp->word = words_arr[i];
                temp->probabilityCount = 0;
                temp->probListCapacity = 100;
                temp->prob_list = (WordProbability *)malloc(sizeof(WordStruct) * temp->probListCapacity);
                add(dictionary, temp);
            }

            // use this function to add this structs together.
            add_word_to_probability_list(prev, temp);

            prev = temp;
        }

        /* if number of read words equals, than break the loop, otherwise read till end of the file */
        if (words_to_read != -1 && wordCount >= words_to_read)
        {
            break;
        }
    }

    return;
}

/**
 * Free the given dictionary and all of it's content from memory.
 * @param dictionary Dictionary to free
 */
void free_dictionary(LinkList *dictionary)
{
    // free all words in dictionary
    Node *temp = dictionary->first;
    Node *next = NULL;
    int i = 0;
    while (temp != NULL)
    {
        next = temp->next;
        if (temp == NULL)
            break;
        if (temp->data == NULL)
            continue;
        if (temp->data->word == NULL)
            continue;
        if (temp->data->prob_list == NULL)
            continue;

        if (i++ == 1000)
            break;

        free(temp->data);

        temp = next;
    }
}

/* helper funtions */

/**
 * @brief check every word in dictonary that if already exist
 * 
 * @param dictionary checked dict
 * @param str checked string
 * @return int if exist, return 0, 1 otherwise.
 */
WordStruct *check_word_exist(LinkList **dictionary, char **str)
{

    // iterate over dictionary and check, word exist or not
    Node *temp = (*dictionary)->first;
    while (temp != NULL)
    {
        if (strcmp(*str, temp->data->word) == 0)
        {
            return temp->data;
        }
        temp = temp->next;
    }

    return NULL;
}

/**
 * @brief splits sentences with given delimeter and keeps it in string array
 * 
 * @param str sentence that will splited
 * @param c delimeter
 * @param arr keep words in array
 * @return int word count
 */
int split(const char *str, char c, char ***arr)
{
    // initialize values to use
    int count = 1;
    int token_len = 1;
    int i = 0;
    char *p;
    char *t;

    // iterate p pointer till end of the string or delimeter
    // and detect size
    p = (char *)str;
    while (*p != '\0')
    {
        if (*p == c)
            count++;
        p++;
    }

    *arr = (char **)malloc(sizeof(char *) * count);

    // assign again with str
    p = (char *)str;

    // process p till null terminator or delimeter
    while (*p != '\0')
    {
        if (*p == c)
        {
            (*arr)[i] = (char *)malloc(sizeof(char) * token_len);
            if ((*arr)[i] == NULL)
                exit(1);

            token_len = 0;
            i++;
        }
        p++;
        token_len++;
    }
    (*arr)[i] = (char *)malloc(sizeof(char) * token_len);

    i = 0;
    p = (char *)str;
    t = ((*arr)[i]);
    // finally, assign values to array
    while (*p != '\0')
    {
        if (*p != c && *p != '\0')
        {
            *t = *p;
            t++;
        }
        else
        {
            *t = '\0';
            i++;
            t = ((*arr)[i]);
        }
        p++;
    }

    return count;
}

/**
 * @brief Removes empty spaces from array
 * 
 * @param arr array that going to used
 * @param arr_size array size
 * @return char** return new modified array
 */
char **removeEmptyWords(char **arr, int *arr_size)
{
    // create array to fill
    char **res = malloc(sizeof(char *) * (*arr_size));
    int new_arr_size = 0;
    // iterate over the array and add words to new arr
    for (int i = 0; i < *arr_size; i++)
    {
        int str_size = strlen(arr[i]);
        if (str_size != 0 && arr[i][0] != ' ')
        {
            res[new_arr_size] = malloc(sizeof(char) * str_size);
            res[new_arr_size++] = arr[i];
        }
    }

    // change old arr size to mew
    *arr_size = new_arr_size;
    return res;
}

/**
 * @param argc
 * @param argv 1) Seed
 *             2) Number of sentences to generate
 *             3) Path to file
 *             4) Optional - Number of words to read
 */
/* int argc, char *argv[] */
int main(int argc, char *argv[])
{
    // check arguments expectations
    if (argc != 4 && argc != 5)
    {
        printf("Given arguments does not satisfies expected argument number\n");
        return EXIT_FAILURE;
    }

    // get seed value
    int seed = atoi(argv[1]);
    // get num of sentence value
    int num_of_entence = atoi(argv[2]);

    // if last arguments does not provided, than assign -1
    int number_of_words_to_read = -1;
    if (argc == 5)
        number_of_words_to_read = atoi(argv[4]);

    // create dict and allocate memory
    LinkList *dictionary = malloc(sizeof(LinkList));
    dictionary->size = 0;

    // use seed value
    srand(seed);

    // try to open file, if cant, inform user
    FILE *fp = fopen(argv[3], "r");
    if (fp == NULL)
    {
        printf("Can't open given path\n");
        return EXIT_FAILURE;
    }
    // fill dict and close the file
    fill_dictionary(fp, number_of_words_to_read, dictionary);
    fclose(fp);

    // write all generated sentences
    for (int i = 0; i < num_of_entence; i++)
    {
        printf("---------- genereted sentence %d ----------\n", i + 1);
        generate_sentence(dictionary);
    }

    // free inside of the dict
    free_dictionary(dictionary);

    return 0;
}