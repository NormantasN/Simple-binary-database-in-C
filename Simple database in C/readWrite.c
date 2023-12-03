#include "readWrite.h"

void write_data_to_bin(Software *sw){
        FILE *data;
        data = fopen("data.bin", "wb");

        if(data == NULL){
            printf("Error data file not found");
            return;
        }

        fwrite(&count, sizeof(int), 1, data);
        for(int i = 0; i < count; ++i){
            fwrite(&sw[i], sizeof(Software), 1, data);
        }

        fclose(data);
        printf("Informacija issaugota\n");
}


void load_data_from_bin(Software *sw){
        FILE *data;
        data = fopen("data.bin", "rb");
        if(data == NULL){
            printf("Error data file not found");
            return;
        }
        fread(&count, sizeof(int), 1, data);
        for(int i = 0; i < count; ++i){
            fread(&sw[i], sizeof(Software), 1, data);
        }
        fclose(data);
        printf("Informacija is databazes uzkrauta\n");
 }
