#include <stdio.h>
#include <stdbool.h>
#include "string.h"

#define NUMBER_OF_VERTICES 7
#define NUMBER_OF_EDGES 7

struct post_station{
    int id;
    char name[15];
    int numbers_of_neighbors;
    int adjacent_stations[10];
};

struct post_station station_list[NUMBER_OF_VERTICES];

void print_stations_list(){
    for(int i = 0; i < NUMBER_OF_VERTICES; i++){
        printf("%d - %s: ", station_list[i].id, station_list[i].name);
        for(int j = 0; j < station_list[i].numbers_of_neighbors; j++){
            int n = station_list[i].adjacent_stations[j];
            printf("%s ", station_list[n].name);
            //int sn = station_list[n].id;
            //printf("%d ", station_list[n].id);
        }
        printf("\n");
    }
}

struct coachman{
    int id;
    struct post_station departure;
    struct post_station destination;
};

struct horse{
    int id;
    bool status;
};

int adjacency_matrix[NUMBER_OF_VERTICES][NUMBER_OF_VERTICES] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0}
};

void print_adjacency_matrix(){
    for(int i = 0; i < NUMBER_OF_VERTICES; i++){
        for(int j = 0; j < NUMBER_OF_VERTICES; j++){
            printf("%d ", adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

void fill_adjacency_matrix(){
    for(int i = 0; i < NUMBER_OF_VERTICES; i++){
        for(int j = 0; j < station_list[i].numbers_of_neighbors; j++){
            adjacency_matrix[station_list[i].id][station_list[i].adjacent_stations[j]] = 1;
        }
    }
}

void search(int departure, int destination){

    int visited[NUMBER_OF_VERTICES];
    for(int i = 0; i < NUMBER_OF_VERTICES; i++){
        visited[i] = 0;
    }

    void DFS(int i)
    {
        int j;
        printf("\n%d",i);
        visited[i]=1;

        for(j = 0; j < NUMBER_OF_VERTICES; j++)
            if(!visited[j] && adjacency_matrix[i][j] == 1)
                DFS(j);
    }

    DFS(1);
}



int main() {

    struct post_station Moscow; Moscow.id = 0; strcat(Moscow.name, "Moscow");
    Moscow.numbers_of_neighbors = 3;
    Moscow.adjacent_stations[0] = 1; Moscow.adjacent_stations[1] = 2;
    Moscow.adjacent_stations[2] = 5;

    struct post_station Zvenigorod; Zvenigorod.id = 1; strcat(Zvenigorod.name, "Zvenigorod");
    Zvenigorod.numbers_of_neighbors = 2;
    Zvenigorod.adjacent_stations[0] = 0;
    Zvenigorod.adjacent_stations[1] = 3;

    struct post_station Serpuhov; Serpuhov.id = 2; strcat(Serpuhov.name, "Serpuhov");
    Serpuhov.numbers_of_neighbors = 2;
    Serpuhov.adjacent_stations[0] = 0;
    Serpuhov.adjacent_stations[1] = 4;

    struct post_station Mozhaysk; Mozhaysk.id = 3; strcat(Mozhaysk.name, "Mozhaysk");
    Mozhaysk.numbers_of_neighbors = 2;
    Mozhaysk.adjacent_stations[0] = 1;
    Mozhaysk.adjacent_stations[1] = 4;

    struct post_station Vizma; Vizma.id = 4; strcat(Vizma.name, "Vizma");
    Vizma.numbers_of_neighbors = 2;
    Vizma.adjacent_stations[0] = 3;
    Vizma.adjacent_stations[1] = 2;

    struct post_station Radonezh; Radonezh.id = 5; strcat(Radonezh.name, "Radonezh");
    Radonezh.numbers_of_neighbors = 2;
    Radonezh.adjacent_stations[0] = 0;
    Radonezh.adjacent_stations[1] = 6;

    struct post_station Suzdal; Suzdal.id = 6; strcat(Suzdal.name, "Suzdal");
    Suzdal.numbers_of_neighbors = 1;
    Suzdal.adjacent_stations[0] = 5;


    station_list[0] = Moscow;
    station_list[1] = Zvenigorod;
    station_list[2] = Serpuhov;
    station_list[3] = Mozhaysk;
    station_list[4] = Vizma;
    station_list[5] = Radonezh;
    station_list[6] = Suzdal;

    print_stations_list();

    fill_adjacency_matrix();
    print_adjacency_matrix();

    search(0, 0);
    getchar();
    return 0;
}