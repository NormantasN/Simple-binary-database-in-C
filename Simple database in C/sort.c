#include "sort.h"

void sortData(Software *sw) {
    int index;
	printf("Pasirinkite, pagal kuri iraso lauka noresite rikiuoti duomenis:\n");
        choose_data_menu();
	scanf("%d", &index);
        if(index > 4 || index < 1){
            printf(VALIDATION_ERROR); // Validation
        }
        switch(index){
                case 1:
                sortTitle(sw);
                case 2:
                sortVersion(sw);
                break;
                case 3:
                sortSize(sw);
                break;
                case 4:
                sortRelease(sw);
                break;
        }
        printf("** Duomenys sekmingai surikiuoti\n");
}

void sortTitle(Software *sw){
        Software temp;
        for (int i = 0; i < count - 1; ++i) {
		for (int j = i + 1; j < count; ++j) {
			int nr = strcmp(sw[i].title, sw[j].title);
			if (nr > 0) {
				temp = sw[i];
				sw[i] = sw[j];
				sw[j] = temp;
			}
		}
	}
}

void sortVersion(Software *sw){
        Software temp;
        for (int i = 0; i < count - 1; ++i) {
		for (int j = i + 1; j < count; ++j) {
			int nr = strcmp(sw[i].version, sw[j].version);
			if (nr > 0) {
				temp = sw[i];
				sw[i] = sw[j];
				sw[j] = temp;
			}
		}
	}
}

void sortSize(Software *sw){
       Software temp;
        for (int i = 0; i < count - 1; ++i) {
		for (int j = i + 1; j < count; ++j) {
			if (sw[i].size > sw[j].size) {
				temp = sw[i];
				sw[i] = sw[j];
				sw[j] = temp;
			}
		}
	} 
}

void sortRelease(Software *sw){
       Software temp;
        for (int i = 0; i < count - 1; ++i) {
		for (int j = i + 1; j < count; ++j) {
			if (sw[i].year > sw[j].year) {
				temp = sw[i];
				sw[i] = sw[j];
				sw[j] = temp;
			}
		}
	} 
}
