#ifndef header_H_INCLUDED
#define header_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <time.h>


#define MAX_SIZE 20 // Tekstiniu duomenu didziausias uzimamas dydis
#define MAX_COUNT 100 // Irasu didziausias kiekis
#define VALIDATION_ERROR "Error: ivestas indeksas nepatenka i rezius\n"

typedef struct Software{
        char title[MAX_SIZE];
        char version[MAX_SIZE];
        int size;
        int year;
}Software;

extern int count;      // Globalus irasu kiekis




// Prototypes
void printMenu(); // Atspausdina standartini meniu
void enterData(Software *sw); // Prideda irasa i strukturu masyva ir padidina strukturos dydi
void editData(Software *sw); // Redaguoja pasirinkta irasa
void deleteData(Software *sw); // Istrina pasirinkta irasa: i istrinama iraso vieta istato sekanti irasa, sumazina kieki vienetu
void watchData(Software *sw); // Atspasudina visus (uzkrautus) irasus esancius strukturoje
void Validation(int n, Software *sw); // Ivestu duomenu validacija ir issaugojimas strukturoje
void printData(Software *sw, int i); // Atspausdina konkretu irasa i ekrana
void choose_data_menu(); // Atspausdina pasirinkimu meniu

// Filters
void filterData(Software *sw); // Irasu filtravimas
void filterTitle(Software *sw); // Filtruoja pagal ivesta pavadinima
void filterVersion(Software *sw); // Filtruoja pagal ivesta versija
void filterSize(Software *sw); // Filtruoja pagal ivestus dydzio intervalo rezius
void filterRelease(Software *sw); // Filtruoja pagal ivestus metu intervalo rezius

// Timer
void timeTracker(time_t begin);
// Prototypes

#endif // READWRITE_H_INCLUDED