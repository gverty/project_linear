/**
*@file functions.c
*@brief File with realizations all functions.
*
*@author Kulish P.
*@date 13-mar-2021
*@version 1.0
*/
#include "functionsInitializations.h"
void GetData(struct basic_type* sneakers,const int N) {
    srand(time(NULL));
    char* listOfBrands[3] = { (char*)"Adidas", (char*)"Nike", (char*)"Puma"};
    char* listOfModels[2] = { (char*)"AirForce",(char*)"Superstar" };
    char* listOfYes_No[2] = { (char*)"Yes",(char*)"No" };
    for (int i = 0; i < N; i++) {
    
        /**filling basic_type*/
        strcpy(sneakers[i].brand,listOfBrands[rand() % 3]);
        strcpy(sneakers[i].model, listOfModels[rand() % 2]);
        strcpy(sneakers[i].ortopedic, listOfYes_No[rand() % 2]);
        sneakers[i].price =  rand() % (N * 10) + N;
        sneakers[i].insole.length_insole = rand() % (N * 10) + N;
        sneakers[i].insole.size_insole = rand() % (N * 10) + N;
    }
}


void ShowData(struct basic_type* sneakers, const int N) {
    printf("\t\tStudent\tBrand\tModel\t     Ortopedic\tPrice\tLength\tSize\n\n");
    for (int i = 0; i < N; i++) {
        printf("\t%s%d", "Number: ", i);
        printf("\t%s", sneakers[i].brand);
        printf("\t%s", sneakers[i].model);
        printf("\t%s", sneakers[i].ortopedic);
        printf("\t%d", sneakers[i].price);
        printf("\t%d", sneakers[i].insole.length_insole);
        printf("\t%d\n", sneakers[i].insole.size_insole);
    }
}


int save(char filename[], struct basic_type* sneakers,const int N)
{
    FILE* fp;
    if ((fp = fopen(filename, "w")) == NULL)
    {
        puts("Error occured while opening file");
        return 1;
    }

    fprintf(fp,"\t\tStudent Brand\tModel\t     Ortopedic Price\tLength\tSize\n\n");
    for (int i = 0; i < N; i++)     {
        fprintf(fp,"\t%s%d", "Number: ", i);
        fprintf(fp,"\t%s", sneakers[i].brand);
        fprintf(fp,"\t%s", sneakers[i].model);
        fprintf(fp,"\t%s", sneakers[i].ortopedic);
        fprintf(fp,"\t%d", sneakers[i].price);
        fprintf(fp,"\t%d", sneakers[i].insole.length_insole);
        fprintf(fp,"\t%d\n", sneakers[i].insole.size_insole);
    }
    fclose(fp);
    return 0;
}

//void save_binary(char filename_binary[], basic_type* sneakers,const int N)
//{
//    FILE* fp_bin;
//    if ((fp_bin = fopen(filename_binary, "wb")) == NULL)
//    {
//        puts("Error occured while opening file");
//        exit(1);  
//    }
//
//    for (int i = 0; i < N; i++) {
//        fseek(fp_bin, sizeof(basic_type) * i, SEEK_SET);
//        fwrite(sneakers + i, sizeof(basic_type), 1, fp_bin);
//    }
//    fclose(fp_bin);
//}

void save_binary(FILE* fp_bin,struct basic_type* sneakers, int i)
{
    fseek(fp_bin, sizeof(struct basic_type) * i, SEEK_SET);
    fwrite(sneakers + i,sizeof(struct basic_type),1,fp_bin);
}
void read_binary(char filename_binary[],struct basic_type* sneakers,const int N) 
{
    FILE* fp_bin;
    if ((fp_bin = fopen(filename_binary, "rb")) == NULL)
    {
        puts("Error occured while opening file");
        exit(1);
    }

    for (int i = 0; i < N; i++) {
        fseek(fp_bin, sizeof(struct basic_type) * i, SEEK_SET);
        fread(sneakers + i, sizeof(struct basic_type), 1, fp_bin); 
    }
    fclose(fp_bin);
}

/**---------------------------------------------*/


char* insert(char *main_str_ptr,char *insert_str_ptr,int insert_index){
	char *result = malloc(sizeof(char)*(strlen(main_str_ptr)+strlen(insert_str_ptr)));
	/**Copy of insert_str count of bytes from first words in resulting string*/
	memcpy(result,main_str_ptr,insert_index);
	/**Copy of first word and puts it in result string*/
	memcpy(result+insert_index,insert_str_ptr,sizeof(char)*strlen(insert_str_ptr));
	/**contactenation result string with ending of first string*/
	strcat(result,main_str_ptr+insert_index);
	return result;
}

char* reduce(char *main_str_ptr,int start_index_of_reducing,int end_index_of_reducing){
	char *result = malloc(sizeof(char)*(strlen(main_str_ptr)));
	/**Copy in resulting string all symbols without reducing*/
	memcpy(result,main_str_ptr,start_index_of_reducing);
	/**Contactenation begin string and his end after reducing*/
	strcat(result,main_str_ptr+end_index_of_reducing+1);
	return result;
}

void add_struct(struct basic_type * sneakers,const int N){
	srand(time(NULL));
    	char* listOfBrands[3] = { (char*)"Adidas", (char*)"Nike", (char*)"Puma"};
    	char* listOfModels[2] = { (char*)"AirForce",(char*)"Superstar" };
	char* listOfYes_No[2] = { (char*)"Yes",(char*)"No" };
	/**creating of an array where the struct is added*/
	struct basic_type add_mass[1];
	/**---*/
	//strcpy(sneakers[i].brand,listOfBrands[rand() % 3]);
        //strcpy(sneakers[i].model, listOfModels[rand() % 2]);
        //strcpy(sneakers[i].ortopedic, listOfYes_No[rand() % 2]);
        /**---*/
	/**appeal to elements in sturct with "->"*/
	strcpy(add_mass->brand,listOfBrands[rand()%3]);
	strcpy(add_mass->model,listOfModels[rand()%2]);
	strcpy(add_mass->ortopedic,listOfYes_No[rand()%2]);
        add_mass->price = rand()%(N*10)+N;
        add_mass->insole.length_insole = rand()%(N*10)+N;
        add_mass->insole.size_insole = rand()%(N*10)+N;
        /**copying from array add_mass to in array sneakers on fifth position */
        memmove(sneakers+N,add_mass,sizeof(struct basic_type));
}

void delete_struct(struct basic_type *sneakers,const int N,int number_Of_Struct_To_Delete){
	/**Filling the structure with spaces*/
	memset(sneakers+number_Of_Struct_To_Delete,' ',sizeof(struct basic_type));
	for(int i = number_Of_Struct_To_Delete;i<N;i++){
		memmove(sneakers+i,sneakers+i+1,sizeof(struct basic_type));
		}
}

