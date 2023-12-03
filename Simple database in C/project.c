/*
            MENIU Autorius Normantas Noreika
Programinė įranga (programos pavadinimas, versijos pavadinimas, programos dydis baitais,
išleidimo metai).

1) meniu kuriamas su switch, leidziant vartotojui pasirinkt veiksma
2) Leisti pasirinkti vartotojui ka nores daryti
    a) ivesti duomenis
    b) redaguoti duomenis
    c) istrinti duomenis (viena irasa arba viska)
    d) perziureti visus duomenis
3) Duomenis issaugoti faile
4) Filtruoti duomenis
5) Rusiuoti duomenis pagal irasus

TESTAI
codeblocks versija 56 2005
discord versija 346 2015
steam versija 512 2003
powerpoint versija 4000 1987
*/



#include "header.h"
#include "readWrite.h"
#include "sort.h"


int count = 0; // Globalus irasu kiekis



int main(){  
        time_t begin = time(NULL);
        Software *sw;
        sw = (Software*) malloc(MAX_COUNT * sizeof(Software));
        if(sw == NULL){
            printf("Memory not allocated\n");
            return 0;
        }
        int index;
        printf("--------------------Sveiki atvyke i programines irangos duomenu bazes meniu-----\n");
        printf("--------------------Prasome pasirinkti norima funkcija--------------------------\n");
        while(index != 9){
            printMenu();
            scanf("%d", &index);
            assert(index < 10);
            if(index > 9 || index < 1){
                printf("Error: ivestas numeris nepatenka i rezius\n");
                return 0;
            }
            switch(index){
                case 1:
                    enterData(sw);
                    break;
                case 2:
                    load_data_from_bin(sw);
                    break;
                case 3:
                    write_data_to_bin(sw);
                    break;
                case 4:
                    editData(sw);
                    break;
                case 5:
                    deleteData(sw);
                    break;
                case 6:
                    watchData(sw);
                    break;
                case 7:
                    filterData(sw);
                    break;
                case 8:
                    sortData(sw);
                    break;
            }
        }
        free(sw);
        timeTracker(begin);
        return 0;
}

void printMenu(){
        printf("    ****************\n");
        printf("    Iveskite numeri veiksmo, kuri noresite atlikti\n");
        printf("    1. Ivesti duomenis\n");
        printf("    2. Uzkrauti duomenis is databazes\n");
        printf("    3. Issaugoti duomenis i databaze\n");
        printf("    4. Redaguoti duomenis\n");
        printf("    5. Istrinti duomenis\n");
        printf("    6. Perziureti duomenis\n");
        printf("    7. Filtruoti duomenis\n");
        printf("    8. Rikiuoti duomenis\n");
        printf("    9. Iseiti\n");
}


void enterData(Software *sw){
        printf("Prasome ivesti programines irangos duomenis atskirtus tarpais - pavadinima, versija, dydi baitais, isleidimo metus\n");
        if(count >= MAX_COUNT){      // Validation
            printf(VALIDATION_ERROR);
            return;
        }
        Validation(count, sw);
        ++count;
}





void watchData(Software *sw) {
        printf("\n");
        for(int i = 0; i < count; ++i){
            printData(sw, i);
            printf("\n");
        }
}



 void editData(Software *sw){
        int n;
        printf("Iveskite numeri iraso, kuri norite pakeisti\n");
        scanf("%d", &n);
        if(n < 0 || n >= MAX_COUNT){
            printf(VALIDATION_ERROR);
            return;
        }
        printf("Prasome ivesti programines irangos duomenis atskirtus tarpais - pavadinima, versija, dydi baitais, isleidimo metus\n");
        Validation(n, sw);
 }

 void Validation(int n, Software *sw){
        int step = 1;
        while(step){     // Validation
                scanf("%s %s %d %d", sw[n].title, sw[n].version, &(sw[n].size), &(sw[n].year));

                if(isalpha(sw[n].title[0]) == 0 || isalpha(sw[n].version[0]) == 0 || sw[n].size <= 0 || sw[n].year <= 0){
                        printf(VALIDATION_ERROR);
                }
                    else
                        step = 0;
        }
        printf("Validation done\n");
 }


void deleteData(Software *sw){
        int choice, nr;
        printf("Jei norite istrinti viska, parasykite 1, jei tik pasirinkta irasa parasykite 2\n");
        scanf("%d", &choice);

        if(choice == 1){
            remove("data.bin");
            count = 0;
        }

        else if(choice == 2){
            printf("Pasirinkite numeri iraso kuri istrinsite\n");
            scanf("%d", &nr);

            if (nr < 0 || nr > MAX_COUNT) { // Validation
                    printf(VALIDATION_ERROR);
                    return;
            }

            for (int i = nr; i < count-1; ++i) {
                sw[i] = sw[i+1];
            }
            --count;
            printf("Irasas istrintas sekmingai\n");
        }
        else{
            printf(VALIDATION_ERROR);
            return;
        }

 }

 void filterData(Software *sw){
        int index;
        printf("Pasirinkite, pagal kuri iraso lauka noresite filtruoti duomenis:\n");
        choose_data_menu();
        scanf("%d", &index);
        if(index > 4 || index < 1){
            printf(VALIDATION_ERROR); // Validation
        }
        switch(index){
                case 1:
                    filterTitle(sw);
                    assert(index == 1);
                    break;
                case 2:
                    filterVersion(sw);
                    assert(index == 2);
                    break;
                case 3:
                    filterSize(sw);
                    assert(index == 3);
                    break;
                case 4:
                    filterRelease(sw);
                    assert(index == 4);
                    break;
            }
 }

 void printData(Software *sw, int i){
                printf("    *Programines irangos numeris: %d\n", i);
                printf("    *Pavadinimas: %s\n", sw[i].title);
                printf("    *Versija: %s\n", sw[i].version);
                printf("    *Uzimamas dydis baitais: %d\n", sw[i].size);
                printf("    *Isleidimo metai: %d\n", sw[i].year);

 }

void filterTitle(Software *sw){
        char title[MAX_SIZE];
        printf("Parasykite programines irangos pavadinima, kurios duomenis norite pamatyti\n");
        scanf("%s", title);

        for(int i = 0; i < count; ++i){
            if(strcmp(title, sw[i].title) == 0){
                printData(sw, i);
            }
        }
        
 }

 void filterVersion(Software *sw){
        char version[MAX_SIZE];
        printf("Parasykite programines irangos versija, kurios duomenis norite pamatyti\n");
        scanf("%s", version);
        
        for(int i = 0; i < count; ++i){
            if(strcmp(version, sw[i].version) == 0){
                printData(sw, i);
            }
        }
        
 }

 void filterSize(Software *sw){
        int x, y;
        printf("Parasykite programines irangos dydzio intervalo rezius (2 skaicius atskirtus tarpu), \n");
        printf("kuriu duomenis norite pamatyti\n");
        scanf("%d %d", &x, &y);

        for(int i = 0; i < count; ++i){
            if(x <= sw[i].size && sw[i].size <= y){
                printData(sw, i);
            }
        }
        
 }

 void filterRelease(Software *sw){
        int x, y;
        printf("Parasykite programines irangos isleidimo metus (nuo-iki, 2 skaicius atskirtus tarpu)\n");
        scanf("%d %d", &x, &y);
        assert(x > 0 && y < 2050);
        for(int i = 0; i < count; ++i){
            if(x <= sw[i].year && sw[i].year <= y){
                printData(sw, i);
            }
        }
        
 }

 void timeTracker(time_t begin){
        FILE *timer;
        timer = fopen("time.log", "w");
        time_t end = time(NULL);
        fprintf(timer, "Programa dirbo %d sekundes\n", (end - begin));
 }

 void choose_data_menu(){
        printf("    1. Pavadinima\n");
        printf("    2. Versija\n");
        printf("    3. Uzimama dydi\n");
        printf("    4. Isleidimo metus\n");
 }
