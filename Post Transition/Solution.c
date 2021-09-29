#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX_STRING_LENGTH 6

struct package
{
    char* id;
    int weight;
};

typedef struct package package;

struct post_office
{
    int min_weight;
    int max_weight;
    package* packages;
    int packages_count;
};

typedef struct post_office post_office;

struct town
{
    char* name;
    post_office* offices;
    int offices_count;
};

typedef struct town town;



void print_all_packages(town t) {
    printf("%s:",t.name);
    for (int i =0; i < t.offices_count; i++){
        printf("\n\t%d:",i);
        for (int j =0; j < t.offices[i].packages_count; j++){
            printf("\n\t\t%s", t.offices[i].packages[j].id);
        }
    }
    printf("\n");
}

void send_all_acceptable_packages(town* source, int source_office_index, town* target, int target_office_index) {    
    post_office source_office = source[0].offices[source_office_index];
    //post_office target_office = target[0].offices[target_office_index];
    post_office source_update;
    source_update.packages_count = 0;
    source_update.max_weight = source_office.max_weight;
    source_update.min_weight = source_office.min_weight;
    int max_weight = target[0].offices[target_office_index].max_weight;
    int min_weight = target[0].offices[target_office_index].min_weight;
    
    for (int i = 0; i < source_office.packages_count; i++){
        package pkg = source_office.packages[i];
        if (pkg.weight <= max_weight && pkg.weight >= min_weight){
            target[0].offices[target_office_index].packages_count += 1;
            target[0].offices[target_office_index].packages = realloc(target[0].offices[target_office_index].packages, sizeof(package) * target[0].offices[target_office_index].packages_count);
            target[0].offices[target_office_index].packages[target[0].offices[target_office_index].packages_count -1] = pkg;
        }
        else {
            source_update.packages_count +=1;
            if (source_update.packages_count == 1){
                source_update.packages = malloc(sizeof(package));
                source_update.packages[0] = pkg;
            }
            else{
                source_update.packages = realloc(source_update.packages, sizeof(package) * source_update.packages_count);
                source_update.packages[source_update.packages_count -1] = pkg;
            }
        }
    }
    source[0].offices[source_office_index] = source_update;
    //target[0].offices[target_office_index] = target_office;
    
}

town town_with_most_packages(town* towns, int towns_count) {
    int max = 0, id;
    for (int i = 0; i < towns_count; i++){
        int pakages_count = 0;
        for (int j = 0; j <towns[i].offices_count; j++){
            pakages_count += towns[i].offices[j].packages_count;
        }
        if (max<pakages_count){
            max = pakages_count;
            id = i;
        }
    }
    return towns[id];

}

town* find_town(town* towns, int towns_count, char* name) {
    for(int i = 0; i<towns_count; i++){
        if(strcmp(towns[i].name, name) == 0){
            return towns+i;
        }
    }
    return towns;
}

int main()
{
    int towns_count;
    scanf("%d", &towns_count);
    town* towns = malloc(sizeof(town)*towns_count);
    for (int i = 0; i < towns_count; i++) {
        towns[i].name = malloc(sizeof(char) * MAX_STRING_LENGTH);
        scanf("%s", towns[i].name);
        scanf("%d", &towns[i].offices_count);
        towns[i].offices = malloc(sizeof(post_office)*towns[i].offices_count);
        for (int j = 0; j < towns[i].offices_count; j++) {
            scanf("%d%d%d", &towns[i].offices[j].packages_count, &towns[i].offices[j].min_weight, &towns[i].offices[j].max_weight);
            towns[i].offices[j].packages = malloc(sizeof(package)*towns[i].offices[j].packages_count);
            for (int k = 0; k < towns[i].offices[j].packages_count; k++) {
                towns[i].offices[j].packages[k].id = malloc(sizeof(char) * MAX_STRING_LENGTH);
                scanf("%s", towns[i].offices[j].packages[k].id);
                scanf("%d", &towns[i].offices[j].packages[k].weight);
            }
        }
    }
    int queries;
    scanf("%d", &queries);
    char town_name[MAX_STRING_LENGTH];
    while (queries--) {
        int type;
        scanf("%d", &type);
        switch (type) {
        case 1:
            scanf("%s", town_name);
            town* t = find_town(towns, towns_count, town_name);
            print_all_packages(*t);
            break;
        case 2:
            scanf("%s", town_name);
            town* source = find_town(towns, towns_count, town_name);
            int source_index;
            scanf("%d", &source_index);
            scanf("%s", town_name);
            town* target = find_town(towns, towns_count, town_name);
            int target_index;
            scanf("%d", &target_index);
            send_all_acceptable_packages(source, source_index, target, target_index);
            break;
        case 3:
            printf("Town with the most number of packages is %s\n", town_with_most_packages(towns, towns_count).name);
            break;
        }
    }
    return 0;
}