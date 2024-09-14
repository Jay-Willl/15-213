#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "cachelab.h"

/*
|              |                    |                       |
| tag / t bits | set index / s bits | block offset / b bits |
|              |                    |                       |


*/

void show_help();

typedef struct _cache_line
{
    int valid;              // cache line valid bit
    unsigned long long tag; // cache line tag (id)
    int age;
} cache_line;

typedef struct _cache_meta
{
    int b; // size of cache block (byte)
    int B;
    int s;
    int S;
    int E;
    int C; // size of total cache (byte)
    int L; // total number of lines
} cache_meta;

static cache_meta cache = {0, 0, 0, 0, 0, 0, 0};
static FILE *file = NULL;

cache_line *acquire_set(cache_line **cache_array, unsigned long long set)
{
    int set_index = set;

    return cache_array[set_index];
}

void update_age(cache_line *line, int inuse)
{
    if (inuse == 1)
    {
        line->age = 0;
    }
    else if (inuse == 0)
    {
        line->age += 1;
    }
    return;
}

void update_line(cache_line *line, unsigned long long tag)
{
    line->valid = 1;
    line->tag = tag;
    update_age(line, 1);
    return;
}



int LRU_simulation(cache_line *lines)
{
    int oldest_line = -1;
    int oldest_age = -1;

    for (int i = 0; i < cache.E; i++)
    {
        if (lines[i].age > oldest_age)
        {
            oldest_line = i;
            oldest_age = lines[i].age;
        }
    }

    return oldest_line;
}

void clean(cache_line **cache_array)
{
    return;
}

int main(int argc, char *argv[])
{
    /* variables used for init */
    int s = -1;
    int b = -1;
    int E = -1;
    int verbose = 0;
    char *filename = NULL;

    /* variables used for cache */
    cache_line **cache_array;

    /* variables used for memory records */
    char *delim = ", ";
    char *token_op;
    char *token_addr;
    int token_size;
    unsigned long long addr;
    unsigned long long tag;
    unsigned long long set;
    unsigned long long offset;

    /* variables used for simulation process */
    int got_hit = -1;
    int got_evicted = -1;
    int first_invalid = -1;
    int lru_invalid = -1;

    /* variables used for summary */
    int hit = 0;
    int miss = 0;
    int eviction = 0;

    if (argc == 1)
    {
        show_help();
        return 0;
    }

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-h") == 0)
        {
            show_help();
            return 0;
        }
        else if (strcmp(argv[i], "-v") == 0)
        {
            verbose = 1;
        }
        else if (strcmp(argv[i], "-s") == 0 && (i + 1) < argc)
        {
            s = atoi(argv[i + 1]);
            i += 1;
        }
        else if (strcmp(argv[i], "-E") == 0 && (i + 1) < argc)
        {
            E = atoi(argv[i + 1]);
            i += 1;
        }
        else if (strcmp(argv[i], "-b") == 0 && (i + 1) < argc)
        {
            b = atoi(argv[i + 1]);
            i += 1;
        }
        else if (strcmp(argv[i], "-t") == 0 && (i + 1) < argc)
        {
            filename = argv[i + 1];
            i += 1;
        }
        else
        {
            printf("Unknown arguments");
            return 1;
        }
    }

    if (s == -1 || b == -1 || E == -1 || filename == NULL)
    {
        printf("Invalid arguments");
        return 1;
    }
    else
    {
        cache.s = s;
        cache.S = pow(2, s);
        cache.b = b;
        cache.B = pow(2, b);
        cache.E = E;
        cache.C = cache.S * cache.E * cache.B;
        cache.L = cache.S * cache.E;
    }

    cache_array = malloc(cache.S * sizeof(cache_line *));
    if (cache_array == NULL)
    {
        printf("Malloc failed");
        return 1;
    }

    for (int i = 0; i < cache.S; i++)
    {
        cache_array[i] = malloc(cache.E * sizeof(cache_line));
        if (cache_array[i] == NULL)
        {
            printf("Malloc failed");
            return 1;
        }
    }

    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Cannot read file");
        return 1;
    }

    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file))
    {
        // continue if record don't start with ' '
        if (buffer[0] != ' ')
        {
            continue;
        }

        // parse record
        token_op = strtok(buffer, delim);
        token_addr = strtok(NULL, delim);
        token_size = atoi(strtok(NULL, delim));
        addr = strtoull(token_addr, NULL, 16);
        tag = addr >> cache.b >> cache.s;
        set = addr << (64 - cache.b - cache.s) >> (64 - cache.s);
        offset = addr << (64 - cache.b - cache.s) << cache.s >> cache.s >> (64 - cache.b - cache.s);

        printf("%s %s,%d\n", token_op, token_addr, token_size);
        printf("%llx\n", addr);
        printf("%llx\n", tag);
        printf("%llx\n", set);
        printf("%llx\n", offset);

        // ======== SIMUlATION PROCESS ========
        // acquire coresponding set
        // iterate through lines
        //      valid lines -> cmp tag
        //      invalid lines -> remember first invalid line
        //
        // check result
        //      tag matched -> hit++
        //      tag unmatched, have invalid line -> validate line, replace tag, miss++, hit++
        //      tag unmatched, no invalid line -> evict page, replace tag, miss++, evict++, hit++
        //
        // L, S:
        // M:
        // ====================================

        // refresh variables
        got_hit = -1;
        got_evicted = -1;
        first_invalid = -1;

        // simulation process
        cache_line *current_lines = acquire_set(cache_array, set);
        for (int i = 0; i < cache.E; i++)
        {
            if (current_lines[i].valid)
            {
                if (current_lines[i].tag == tag)
                {
                    got_hit = 1;
                    update_age(&current_lines[i], 1);
                } else {
                    update_age(&current_lines[i], 0);
                }
            }
            else
            {
                if (first_invalid == -1)
                {
                    first_invalid = i;
                }
            }
        }

        if (got_hit == -1)
        {
            if (first_invalid == -1)
            {
                // activate LRU process
                got_evicted = 1;
                lru_invalid = LRU_simulation(current_lines);
                update_line(&current_lines[lru_invalid], tag);
            }
            else
            {
                // just modify first invalid line
                update_line(&current_lines[first_invalid], tag);
            }
        }

        switch (*token_op)
        {
        case 'L':
        case 'S':
            if (got_hit == 1)
            {
                hit += 1;
            }
            else if (got_hit == -1 && got_evicted == 1)
            {
                miss += 1;
                eviction += 1;
            }
            else if (got_hit == -1 && got_evicted == -1)
            {
                miss += 1;
            }
            break;
        case 'M': // L followed by a S
            if (got_hit == 1)
            {
                hit += 2;
            }
            else if (got_hit == -1 && got_evicted == 1)
            {
                hit += 1;
                miss += 1;
                eviction += 1;
            }
            else if (got_hit == -1 && got_evicted == -1)
            {
                hit += 1;
                miss += 1;
            }
            break;
        }
    }

    printf("%d\n", verbose);
    printSummary(hit, miss, eviction);
    fclose(file);
    clean(cache_array);
    return 0;
}

/* auxiliary functions */
void show_help()
{
    printf("Usage: ./csim [-hv] -s <s> -E <E> -b <b> -t <tracefile>\n");
    printf("Options: \n");
    printf("  -h         Print this help message.\n");
    printf("  -v         Optional verbose flag.\n");
    printf("  -s <num>   Number of set index bits.\n");
    printf("  -E <num>   Number of lines per set.\n");
    printf("  -b <num>   Number of block offset bits.\n");
    printf("  -t <file>  Trace file.\n");
    printf("\n");
    printf("Examples: \n");
    printf("  linux>  ./csim -s 4 -E 1 -b 4 -t traces/yi.trace\n");
    printf("  linux>  ./csim -v -s 8 -E 2 -b 4 -t traces/yi.trace\n");
    return;
}
