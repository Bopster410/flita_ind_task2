#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include "graph.h"

//#define TIME

int main(int argc, char *argv[]) {
#ifndef TIME
    if (argc != 2) {
        exit(1);
    }
    node_t *graph = graphFromFile(argv[1]);

    printGraph(graph);

    const char *dotFileName = "graph.dot";
    graphToDotDir(graph, dotFileName);

    graph = setUnvisited(graph);

    set *looped = findLoops(graph);

    puts("Elements with loops:");
    printSet(looped);

    freeSet(looped);
    freeGraph(graph);

    char *command = malloc(sizeof(char) * 64);
    sprintf(command, "dot -Tpng %s -o output.png", dotFileName);

    system(command);

    free(command);
#endif

#ifdef TIME
    FILE *timeFile = fopen("time.txt", "a");

//    for (int i = 10000; i <= 100000; i += 10000) {
        char *fileName = malloc(sizeof(char) * 64);
    printf("43: %d\n", (int)clock() * 10000);

//        sprintf(fileName, "inp/.txt", 100);
        node_t *graphaaa = graphFromFile("inp/100.txt");
//    printGraph(graphaaa);

        // Set the timer
//        clock_t time = clock();
    // time of day
    struct timeval begin, end;
    gettimeofday(&begin, 0);
//    printf("48: %f\n", (double)time(NULL));
//    printf("48: %f\n", (double)clock() / CLOCKS_PER_SEC);

//    printf("%d\n", (int)clock() * 10000);
        set *looped = findLoops(graphaaa);
//        clock_t end = clock();
//    printf("54: %f\n", (double)time(NULL));
//sleep(4);
    gettimeofday(&end, 0);
    printf("%ld\n", end.tv_usec - begin.tv_usec);

//    printf("54: %f\n", (double)clock() / CLOCKS_PER_SEC);

//    time = clock() - time;
//    printf("%f\n", ((double)(time) / CLOCKS_PER_SEC));


//    printSet(looped);
//        time_spent = ((double)(end - begin)*10000000) / CLOCKS_PER_SEC;
        fprintf(timeFile, "%d-%f\n", countConnections(graphaaa), ((double)end.tv_usec - begin.tv_usec) * 1e-6);
//    graphToDotUndir(graphaaa, "graph.dot");
//    printf("%d\n", (int)clock() * 10000);

//    system("dot -Tpng graph.dot -o output.png");

        freeGraph(graphaaa);
        freeSet(looped);
        free(fileName);
//    }
    fclose(timeFile);
#endif

    return 0;
}