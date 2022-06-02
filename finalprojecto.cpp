#pragma warning(disable: 4996)
#define _CRT_SECURE_NO_WARNINGS 1
#define _CRTDBG_MAP_ALLOC
// C program for the above approach
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_ahoshalate     "\x1b[202m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_BRIGHTRED "\x1b[91m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
//Regular underline text
#define UBLK "\e[4;30m"
#define URED "\e[4;31m"
#define UGRN "\e[4;32m"
#define UYEL "\e[4;33m"
#define UBLU "\e[4;34m"
#define UMAG "\e[4;35m"
#define UCYN "\e[4;36m"
#define UWHT "\e[4;37m"
#include<stdio.h>
#include<windows.h>
#include <dos.h>
#include<conio.h>
#include<ctype.h>
#include<crtdbg.h>
#include<string.h>
#include <math.h>
#include <time.h>
#include<stdint.h>
#include <direct.h>
#include <process.h>
#include<stdlib.h>
#include <io.h>
int choose;
char buffer[12098] = { '\0' };
char buffer2[12098] = { '\0' };
char temp[12098] = { '\0' };
char temp2[12098] = { '\0' };
int result[2000];
int result2[100];
int tlines[12098];
int statt[12098] = { '0' };

void Title()
{
	printf(ANSI_COLOR_YELLOW"\n\n\t\t---------------------------------------------------");
	printf("\n\t\t\t\t     BUS System     ");
	printf("\n\t\t---------------------------------------------------" ANSI_COLOR_RESET);
}
void ex_it()
{
	system("cls");
	Title();
	printf("\n\n\n\n\n\t\t\tTHANK YOU FOR VISITTING  :");
	getchar();
}
void  FixCsvFile() {
	int j = 0;
	bool isStrangeChar = false;
	for (int i = 0; i < strlen(buffer); i++)
	{
		if (buffer[i] == '"' && buffer[i + 1] != ',')
			isStrangeChar = true;
		if (buffer[i] == ',' && buffer[i + 1] == ',')
		{
			temp[j] = buffer[i];
			j++;
			temp[j] = 'w';
			j++;
		}
		else if (buffer[i] == ',' && buffer[i + 1] == ' ' && isStrangeChar)
		{
			temp[j] = ';';
			j++;
			isStrangeChar = false;
		}
		else
		{
			temp[j] = buffer[i];
			j++;
		}
	}
	temp[j] = '\0';
}
int findIndexOfColumnByName(char col[], FILE* fp) {
	char buffer[11098];
	int row = 0;
	int column = 0;
	while (fgets(buffer,
		11098, fp)) {
		column = 0;
		row++;

		// To avoid printing of column
		// names in file can be changed
		// according to need
		if (row == 1) {
			// Splitting the data
			char* value = strtok(buffer, ",");

			while (value) {
				if (strcmp(value, col) == 0)
				{
					return column;
				}

				value = strtok(NULL, ",");
				column++;
			}

		}
	}
	return 0;
}
int findIndexOfColumnByNametwo(char cel[], FILE* fp2) {
	char buffer[11098];
	int row = 0;
	int column2 = 0;
	while (fgets(buffer,
		11098, fp2)) {
		column2 = 0;
		row++;

		// To avoid printing of column
		// names in file can be changed
		// according to need
		if (row == 1) {
			// Splitting the data
			char* value2 = strtok(buffer, ",");

			while (value2) {
				if (strcmp(value2, cel) == 0)
				{
					return column2;
				}

				value2 = strtok(NULL, ",");
				column2++;
			}

		}
	}
	return 0;
}
int findIndexOfColumnByNamethree(char cil[], FILE* fp3) {
	char buffer[11098];
	int row = 0;
	int column3 = 0;
	while (fgets(buffer,
		11098, fp3)) {
		column3 = 0;
		row++;

		// To avoid printing of column
		// names in file can be changed
		// according to need
		if (row == 1) {
			// Splitting the data
			char* value3 = strtok(buffer, ",");

			while (value3) {
				if (strcmp(value3, cil) == 0)
				{
					return column3;
				}

				value3 = strtok(NULL, ",");
				column3++;
			}

		}
	}
	return 0;
}
int City_List() {
	system("cls");
	FILE* file;
	file = fopen("C:\\files\\herogo.txt", "r");
	char buffer[4098];
	char** lines = NULL;
	int i = 0;

	char* buf2[12530];
	while (fgets(buffer, sizeof(buffer), file))
	{
		lines = (char**)realloc(lines, (i + 1) * sizeof(char*));
		if (lines == NULL)
		{
			// any error handling you like...
			return EXIT_FAILURE;
		}
		lines[i] = strdup(buffer);
		if (lines[i] == NULL)
		{
			// any error handling you like...
			return EXIT_FAILURE;
		}
		i++;
	}

	fclose(file);
	
	int i2 = sizeof(buf2);

	for (int i = 0; i < 12530; i++)
	{
		buf2[i] = lines[i]; // convert the lines value into buf2 (arrays)
	}

	for (int i = 0; i < sizeof(buf2) / sizeof(buf2[0]); i++)
	{
		for (int j = 1; j < sizeof(buf2) / sizeof(buf2[0]); j++)
		{
			if (i < j)
			{
				if (((strcmp(buf2[i], buf2[j])) == 0))
				{
					strcpy(buf2[j], "\0");
				}
			}
		}
	}

	char* buf3[193];
	int a = 0;
	int count = 0;
	for (int i = 0; i < sizeof(buf2) / sizeof(buf2[0]); i++)
	{
		if (strcmp(buf2[i], "") != 0)
		{
			buf3[a] = buf2[i];
			a++;
			count++;
		}

	}


	for (int i = 0; i < sizeof(buf3) / sizeof(buf3[0]); i++)
	{
		printf(ANSI_COLOR_RED"%s\n", buf3[i]);
	}
	printf("\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_CYAN"total citys = %d\n\n", count);
	free(lines);
	return EXIT_SUCCESS;
}
int StationByCity_list() {
	system("cls");
	int count3 = 0;
	FILE* fp = fopen("C:\\files\\stations3.csv", "r");
	FILE* fp2 = fopen("C:\\files\\stations3.csv", "r");
	FILE* fptr2 = fopen("C:\\files\\citystation.txt", "w");
	FILE* fptr3 = fopen("C:\\files\\citystation.txt", "r");
	char col[1000];
	char cel[1000];
	if (!fp)
		printf("Can't open file\n");

	else {

		int row = 0;
		int column = 0;
		int column2 = 0;
		char col[100] = "Stationname";
		char cel[50] = "City";
		char cel2[100];
		printf(ANSI_COLOR_BRIGHTRED"\n\nplease enter a name of city you wanna check\n" ANSI_COLOR_RESET);
		scanf_s("%s", cel2, 100);
		int numOfCol = findIndexOfColumnByName(col, fp);
		//printf("index = %d", numOfCol);
		printf("\n");
		int numofcel = findIndexOfColumnByNametwo(cel, fp2);
		//printf("index = %d", numofcel);
		printf("\n\n");

		fputs(cel2, fptr2);
		fputs("\n", fptr2);
		while (fgets(buffer,
			12098, fp)) {
			column = 0;
			column2 = 0;
			row++;

			if (row == 0)
				continue;

			//
			FixCsvFile();

			// Splitting the data
			char* value = strtok(temp, ",");

			while (value) {
				char cel3[100];
				if (column == numOfCol)//colmn which i need
				{
					strcpy(cel3, value);

				}
				if (column2 == numofcel)//colmn which i need
				{
					if (strcmp(cel2, value) == 0)//check if the city input equals to 
					{
						fputs("  --->  ", fptr2);
						fputs(cel3, fptr2);
						fputs("\n", fptr2);
						count3++;
					}
				}

				value = strtok(NULL, ",");
				column++;
				column2++;
			}
		}
		// Close the file
		fclose(fp);
		fclose(fp2);
		fclose(fptr2);
	}
	char buffer[4098];
	char** lines = NULL;
	int i = 0;

	while (fgets(buffer, sizeof(buffer), fptr3))
	{
		lines = (char**)realloc(lines, (i + 1) * sizeof(char*));
		if (lines == NULL)
		{
			// any error handling you like...
			return EXIT_FAILURE;
		}
		lines[i] = strdup(buffer);
		if (lines[i] == NULL)
		{
			// any error handling you like...
			return EXIT_FAILURE;
		}
		i++;
	}
	fclose(fptr3);
	// work with the lines
	for (int j = 0; j < i; j++)
	{
		printf(ANSI_COLOR_YELLOW"%s", lines[j]);
	}
	printf("\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_ahoshalate"number of stations=%d\n", count3);
	free(lines);
	return EXIT_SUCCESS;
}
int DistanceByCityorstation() {
	int count3 = 0;
	FILE* fp = fopen("C:\\files\\stations3.csv", "r");
	FILE* fp2 = fopen("C:\\files\\stations3.csv", "r");
	FILE* fp3 = fopen("C:\\files\\stations3.csv", "r");
	FILE* fptr2 = fopen("C:\\files\\citystation.txt", "w");
	FILE* fptr3 = fopen("C:\\files\\citystation.txt", "r");
	char col[1000];
	char cel[1000];
	char cil[1000];
	if (!fp)
		printf("Can't open file\n");

	else {

		
		int row = 0;
		int rero = -1;
		int column = 0;
		int column2 = 0;
		int column3 = 0;
		char col[250] = "Distance from departure station";
		char cel[250] = "Station number";
		char cil[250] = "City";
		char cel2[250];
		char cil2[250];
		
		printf("please enter a number of station you wanna check\n");
		scanf_s("%s", cel2, 250);
		
		int numOfCol = findIndexOfColumnByName(col, fp);
		
		int numofcel = findIndexOfColumnByNametwo(cel, fp2);
		
		int numofcil = findIndexOfColumnByNamethree(cil, fp3);
		
		fputs("\n", fptr2);
		while (fgets(buffer,
			12098, fp)) {
			column = 0;
			column2 = 0;
			column3 = 0;
			row++;

			if (row == 0)
				continue;

			FixCsvFile();

			// Splitting the data
			char* value = strtok(temp, ",");
	
			while (value) {

				char cel3[100];
				char cel4[100];
				char cel5[100];
				if (column2 == numofcel)
				{
					strcpy(cel4, value); //copy the values of all columns of the stations numbers into cel4
				}
				if (column == numOfCol && strcmp(cel2, cel4) == 0)//check if the input(cel2) equals to cel4 (the values in the column of the station number)
				{
					strcpy(cel3, value);//distance
					result[count3] = strtod(cel3, &value);//from string to int by strtod
					
				}
				if (column3 == numofcil)//no needed any more 
				{
					strcpy(cel5, value);
				}
				if (column3 == numofcil)
				{	
						if ((strcmp(cel2, cel4) == 0)) //if the input and the values of station numbers is equals they will puts the distance of stnumber
						{
							fputs(cel3, fptr2);
							fputs("\n", fptr2);
							count3++;
						}
				}


				value = strtok(NULL, ",");
				column++;
				column2++;
				column3++;
			}
			
		}
		// Close the file
		fclose(fp);
		fclose(fp2);
		fclose(fp3);
		fclose(fptr2);
	}
	char buffer[4098];
	char** lines = NULL;
	int i = 0;

	while (fgets(buffer, sizeof(buffer), fptr3))
	{
		lines = (char**)realloc(lines, (i + 1) * sizeof(char*));
		if (lines == NULL)
		{
			// any error handling you like...
			return EXIT_FAILURE;
		}
		lines[i] = strdup(buffer);
		if (lines[i] == NULL)
		{
			// any error handling you like...
			return EXIT_FAILURE;
		}
		i++;
	}
	fclose(fptr3);

	char* bof3[4000];

	free(lines);
	return result[0];
}
int distancetime()
{

	int num = DistanceByCityorstation();//the distance of first station number
	printf(ANSI_COLOR_MAGENTA"\n\nDistance from departure station=%d\n\n" ANSI_COLOR_RESET, num);
	
	int num2 = DistanceByCityorstation();//the distance of second station number
	printf(ANSI_COLOR_MAGENTA"\n\nDistance from departure station=%d\n\n" ANSI_COLOR_RESET, num2);

	if (num > num2)//check to print without (-) values , 
		return printf(ANSI_COLOR_CYAN"the distance between two locations = %d miter" ANSI_COLOR_RESET, num - num2);
	else
		return printf(ANSI_COLOR_CYAN"the distance between two locations = %d miter" ANSI_COLOR_RESET, num2 - num);
}
typedef struct btree {
	int value;
	struct btree* left;
	struct btree* right;
} Btree;
void insert(Btree** t, int* a, int index, int n)
{
	if (index < n) {
		*t = (Btree*)malloc(sizeof(**t));

		(*t)->value = a[index];
		(*t)->left = NULL;
		(*t)->right = NULL;

		insert(&(*t)->left, a, 2 * index + 1, n);
		insert(&(*t)->right, a, 2 * index + 2, n);
	}
}
void print(Btree* t, int level)
{
	if (t) {
		print(t->left, level + 1);
		printf(ANSI_COLOR_GREEN"%*s->%d\n" ANSI_COLOR_RESET, 4 * level, "", t->value);
		print(t->right, level + 1);
		
	}
}
int BusbyStation()
{
	system("cls");
	int count3 = 0;
	FILE* fp = fopen("C:\\files\\stations3.csv", "r");
	FILE* fp2 = fopen("C:\\files\\stations3.csv", "r");
	FILE* fptr2 = fopen("C:\\files\\citystation.txt", "w");
	FILE* fptr3 = fopen("C:\\files\\citystation.txt", "r");
	char col[1000];
	char cel[1000];
	if (!fp)
		printf("Can't open file\n");

	else {


		int row = 0;
		int column = 0;
		int column2 = 0;
		char col[100] = "line";
		char cel[100] = "Station number";
		char cel2[100];
		printf(ANSI_COLOR_BRIGHTRED"please enter a number of station you wanna check\n" ANSI_COLOR_RESET);
		scanf_s("%s", cel2, 100);
		int numOfCol = findIndexOfColumnByName(col, fp); //calling func to return the index of line column
		//printf("index = %d", numOfCol);
		printf("\n");
		int numofcel = findIndexOfColumnByNametwo(cel, fp2);//calling func to return the index of station number column
		//printf("index = %d", numofcel);
		printf("\n\n");

		fputs(cel2, fptr2);
		fputs("\n", fptr2);
		while (fgets(buffer,
			12098, fp)) {
			column = 0;
			column2 = 0;
			row++;

			if (row == 0)
				continue;

			FixCsvFile();

			// Splitting the data
			char* value = strtok(temp, ",");

			while (value) {
				char cel3[100];
				char cel9[100];
				if (column == numOfCol)//colmn which i need
				{
					strcpy(cel3, value);
					

				}
				if (column2 == numofcel)//colmn which i need
				{
					if (strcmp(cel2, value) == 0)
					{
						result2[count3] = strtod(cel3, &value);
						fputs("  --->  ", fptr2);
						fputs(cel3, fptr2);
						fputs("\n", fptr2);
						count3++;
					}
				}

				value = strtok(NULL, ",");
				column++;
				column2++;
			}
		}
		// Close the files
		fclose(fp);
		fclose(fp2);
		fclose(fptr2);
	}
	char buffer[4098];
	char** lines = NULL;
	int i = 0;

	while (fgets(buffer, sizeof(buffer), fptr3))
	{
		lines = (char**)realloc(lines, (i + 1) * sizeof(char*));
		if (lines == NULL)
		{
			// any error handling you like...
			return EXIT_FAILURE;
		}
		lines[i] = strdup(buffer);
		if (lines[i] == NULL)
		{
			// any error handling you like...
			return EXIT_FAILURE;
		}
		i++;
	}
	fclose(fptr3);
	

	//time to remove our duplicate values from the array 
	int min = 0;
	for (int h = 0; h < count3; h++) {
		for (int j = h + 1; j < count3; j++) {
			if (result2[h] > result2[j]) {
				min = result2[h];
				result2[h] = result2[j];
				result2[j] = min;
			}
		}
	}
	for (int e = 0; e < count3; e++) {
		for (int j = e + 1; j < count3; j++) {
			if (result2[e] == result2[j]) {
				for (int k = j; k < count3; k++) {
					result2[k] = result2[k + 1];
				}
				j--;
				count3--;
			}
		}
	}

	//calling tree func to printf with tree
	Btree* t;


	insert(&t, result2, 0, count3);//converting from array to tree 
	print(t, 0);
	


	printf(ANSI_COLOR_BLUE"\nnumber of busses=%d\n" ANSI_COLOR_RESET, count3);


	free(lines);
	return EXIT_SUCCESS;
}
int NeighborByStation()
{
	system("cls");
	int count3 = 0;
	int e = 0;
	int x = 0;
	char coco[100];
	FILE* fp = fopen("C:\\files\\stations3.csv", "r");
	FILE* fp2 = fopen("C:\\files\\stations3.csv", "r");
	FILE* fptr2 = fopen("C:\\files\\citystation.txt", "w");
	FILE* fptr3 = fopen("C:\\files\\citystation.txt", "r");
	char col[1000];
	char cel[1000];
	if (!fp)
		printf("Can't open file\n");

	else {

		

		int row = 0;
		int column = 0;
		int column2 = 0;
		int column3 = 0;
		char col[100] = "Stationarrangements";
		char cel[100] = "Station number";
		char cel2[100];
		printf("please enter a number of station you wanna check\n");
		scanf_s("%s", cel2, 100);
		strcpy(coco, cel2);
		
		int numOfCol = findIndexOfColumnByName(col, fp);
		//printf("index = %d", numOfCol);
		printf("\n");
		int numofcel = findIndexOfColumnByNametwo(cel, fp2);
		//printf("index = %d", numofcel);
		printf("\n\n");

		fputs(cel2, fptr2);
		fputs("\n", fptr2);
		while (fgets(buffer,
			12098, fp)) {
			column = 0;
			column2 = 0;
			column3 = 0;
			row++;

			if (row == 0)
				continue;

			//
			FixCsvFile();

			// Splitting the data
			char* value = strtok(temp, ",");

			while (value) {
				char cel3[100];
				char cel9[100];
				char statn[100];
				char leneine[100];

				if (column == numOfCol)//colmn which i need
				{
					strcpy(cel3, value);
					strcpy(leneine, value);
					tlines[e] = strtod(leneine, &value);//array of Stationarrangements making from string to int array values
					e++;
				}
				if (column2 == numofcel)//colmn which i need
				{
					if (strcmp(cel2, value) == 0)
					{
						result2[count3] = strtod(cel3, &value);
						fputs("  --->  ", fptr2);
						fputs(cel3, fptr2);
						fputs("\n", fptr2);
						count3++;
					}
				}
				if (column3 == numofcel)
				{
					strcpy(statn, value);
					statt[x] = strtod(statn, &value);//array of Station numbers making from string to int array values
					x++;
				}

				value = strtok(NULL, ",");
				column++;
				column2++;
				column3++;
			}
		}
		// Close the file
		fclose(fp);
		fclose(fp2);
		fclose(fptr2);
	}
	char buffer[4098];
	char** lines = NULL;
	int i = 0;

	while (fgets(buffer, sizeof(buffer), fptr3))
	{
		lines = (char**)realloc(lines, (i + 1) * sizeof(char*));
		if (lines == NULL)
		{
			// any error handling you like...
			return EXIT_FAILURE;
		}
		lines[i] = strdup(buffer);
		if (lines[i] == NULL)
		{
			// any error handling you like...
			return EXIT_FAILURE;
		}
		i++;
	}
	fclose(fptr3);
	
	


	printf("\nnumber of busses=%d\n", count3);
	
	printf("\n");
	
	



	int roro;

	char* cece = strtok(coco, "\n");

	roro = strtod(coco, &cece);

	for (int s = 0; s < x; s++)
	{
		if (statt[s] == 0)
		{
			statt[s] = roro;
		}
	}

	for (int s = 0; s < x; s++)
	{
		if (roro == statt[s])
		{
			if (tlines[s] > 1)
			{
				printf("%d-->", statt[s - 1]);
				printf("%d-->", statt[s]);
				printf("%d-->", statt[s + 1]);
				printf("||");
			}
			if (tlines[s] == 1)
			{
				printf("%d-->", statt[s]);
				printf("%d-->", statt[s + 1]);
				printf("||");
			}
		}

	}


	int dupli[50];
	int rev = 0;
	for (int s = 0; s < x; s++)
	{
		if (roro == statt[s])
		{
			if (tlines[s] > 1)
			{
				dupli[rev] = statt[s - 1];
				rev++;
				dupli[rev] = statt[s];
				rev++;
				dupli[rev] = statt[s + 1];
				rev++;
			}
			if (tlines[rev] == 1)
			{
				dupli[rev] = statt[s];
				rev++;
				dupli[rev] = statt[s + 1];
				rev++;
			}

		}

	}

	printf("\n\n\n");
	for (int q = 0; q < rev; q++)
	{
		printf("%d-->", dupli[q]);
	}
	printf("||");
	

	int maxim = 0;
	maxim = rev;
	
	for (int w = 0; w < rev; w++) {
		for (int j = w + 1; j < rev; j++) {
			if (dupli[w] == dupli[j]) {
				for (int k = j; k < rev; k++) {
					dupli[k] = dupli[k + 1];
				}
				j--;
				rev--;
			}
		}
	}
	printf("\n\n\n");

	maxim = rev;
	int neighb = 0;
	for (int w = 0; w < maxim; w++)
	{
		if (dupli[w] != 0)
		{
			printf(ANSI_COLOR_CYAN"%d-->", dupli[w]);
			neighb++;
		}
	}
	printf("||\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_RED"number of neighbors = %d" ANSI_COLOR_RESET, neighb);
	
	free(lines);
	return EXIT_SUCCESS;
}
int shortest_Distance_Between_Two_Stations() {
	system("cls");
	int count3 = 0;
	int count4 = 0;
	FILE* fp = fopen("C:\\files\\stations3.csv", "r");
	FILE* fp2 = fopen("C:\\files\\stations3.csv", "r");
	FILE* fp3 = fopen("C:\\files\\stations3.csv", "r");
	FILE* fptr2 = fopen("C:\\files\\citystation.txt", "w");
	FILE* fptr3 = fopen("C:\\files\\citystation.txt", "r");
	char col[1000];
	char cel[1000];
	char cil[1000];
	if (!fp)
		printf("Can't open file\n");

	else {


		int row = 0;
		int rero = -1;
		int column = 0;
		int column2 = 0;
		int column3 = 0;
		char col[250] = "Distance from departure station";
		char cel[250] = "Station number";
		char cil[250] = "City";
		char cel2[250];
		char cil2[250];
		char clcil[250];

		printf("please enter a number of station you wanna check\n");
		scanf_s("%s", cel2, 250);
		printf("please enter a number of second station you wanna check\n");
		scanf_s("%s", clcil, 250);

		int numOfCol = findIndexOfColumnByName(col, fp);

		int numofcel = findIndexOfColumnByNametwo(cel, fp2);

		int numofcil = findIndexOfColumnByNamethree(cil, fp3);

		fputs("\n", fptr2);
		while (fgets(buffer,
			12098, fp)) {
			column = 0;
			column2 = 0;
			column3 = 0;
			row++;

			if (row == 0)
				continue;

			FixCsvFile();

			// Splitting the data
			char* value = strtok(temp, ",");

			while (value) {

				char cel3[100];
				char cel4[100];
				char cel5[100];
				if (column2 == numofcel)
				{
					strcpy(cel4, value); //copy the values of all columns of the stations numbers into cel4
					//statt[count4] = strtod(cel4, &value);
					//count4++;
				}
				if (column == numOfCol && strcmp(cel2, cel4) == 0)//check if the input(cel2) equals to cel4 (the values in the column of the station number)
				{
					strcpy(cel3, value);//distance
					result[count3] = strtod(cel3, &value);//from string to int by strtod

				}
				if (column == numOfCol && strcmp(clcil, cel4) == 0)//check if the input(cel2) equals to cel4 (the values in the column of the station number)
				{
					strcpy(cel3, value);//distance
					statt[count4] = strtod(cel3, &value);//from string to int by strtod
					count4++;

				}
				if (column3 == numofcil)//no needed any more 
				{
					strcpy(cel5, value);

				}
				if (column3 == numofcil)
				{
					if ((strcmp(cel2, cel4) == 0)) //if the input and the values of station numbers is equals they will puts the distance of stnumber
					{
						fputs(cel3, fptr2);
						fputs("\n", fptr2);
						count3++;
					}
				}


				value = strtok(NULL, ",");
				column++;
				column2++;
				column3++;
			}

		}
		// Close the file
		fclose(fp);
		fclose(fp2);
		fclose(fp3);
		fclose(fptr2);
	}
	char buffer[4098];
	char** lines = NULL;
	int i = 0;

	while (fgets(buffer, sizeof(buffer), fptr3))
	{
		lines = (char**)realloc(lines, (i + 1) * sizeof(char*));
		if (lines == NULL)
		{
			// any error handling you like...
			return EXIT_FAILURE;
		}
		lines[i] = strdup(buffer);
		if (lines[i] == NULL)
		{
			// any error handling you like...
			return EXIT_FAILURE;
		}
		i++;
	}
	fclose(fptr3);

	char* bof3[4000];

	/*
	for (int j = 0; j < count3; j++)
	{
		printf("%d,,", result[j]);
	}
	printf("\n");
	for (int j = 0; j < count4; j++)
	{
		printf("%d,,", statt[j]);
	}
	*/
	printf("\n\n\n");

	int shortest[1000];
	int counshort = 0;


	for (int j = 0; j < count3; j++)
	{
		for (int u = 0; u < count4; u++)
		{
			if (result[j] > statt[u])
			{
				shortest[counshort] = result[j] - statt[u];
				counshort++;
			}
			else
			{
				shortest[counshort] = statt[u] - result[j];
				counshort++;
			}
		}
	}
	
	int mindis = 0;
	mindis = shortest[0];
	for (int j = 1; j < counshort; j++) {
		//Compare elements of array with mindis   
		if (shortest[j] < mindis)
			mindis = shortest[j];
	}

	printf("\n\nshortest is = %d", mindis);

	
	free(lines);
	return EXIT_SUCCESS;
}
void MainMenu()
{
	system("cls");
	Title();
	printf(ANSI_COLOR_BLUE"\n\n\n\n\n\t\t\t\t1.  Citys List\n");
	printf("\n\t\t\t\t2.  StationsLIST\n");
	printf("\n\t\t\t\t3.  Bus by Station number\n");
	printf("\n\t\t\t\t4.  distance between two locations\n");
	printf("\n\t\t\t\t5.  NeighborByStations\n");
	printf("\n\t\t\t\t6.  Shortest distance\n");
	printf("\n\t\t\t\t7.  Exit\n" ANSI_COLOR_RESET);
	printf(ANSI_COLOR_MAGENTA"\n\n\n \n\t\t\t\tChoose from 1 to 7:" ANSI_COLOR_RESET);
	scanf_s("%i", &choose);
	switch (choose)
	{
	case 1:
	{
		clock_t t;
		t = clock();
		City_List();
		t = clock() - t;
		double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
		printf("City_List() took %f seconds to execute \n", time_taken);
	}
		break;
	case 2:
	{
		clock_t t;
		t = clock();
		StationByCity_list();
		t = clock() - t;
		double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
		printf("StationByCity_list() took %f seconds to execute \n", time_taken);
		//getch();
	}
		break;
	case 3:
	{
		clock_t t;
		t = clock();
		BusbyStation();
		t = clock() - t;
		double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
		printf("BusbyStation() took %f seconds to execute \n", time_taken);
	}
		break;
	case 4:
	{
		clock_t t;
		t = clock();
		distancetime();
		t = clock() - t;
		double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
		printf("\ndistancetime() took %f seconds to execute \n", time_taken);
	}
		break;
	case 5:
	{
		clock_t t;
		t = clock();
		NeighborByStation();
		t = clock() - t;
		double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
		printf("\nNeighborByStation() took %f seconds to execute \n", time_taken);
	}
		break;
	case 6:
	{
		clock_t t;
		t = clock();
		shortest_Distance_Between_Two_Stations();
		t = clock() - t;
		double time_taken = ((double)t) / CLOCKS_PER_SEC; // in seconds
		printf("\nshortest_Distance_Between_Two_Stations() took %f seconds to execute \n", time_taken);
	}
		break;
	case 7:
		ex_it();
	default:
		printf("\t\t\tInvalid entry. please enter right option  :");
		getchar();
	}
}

int main()
{
	Title();
	MainMenu();
	for (;;) {
		if (choose == 1)
		{
			Sleep(5000);
			printf("\n\nPress enter to continue...\n");
			getch();
			MainMenu();
		}
		if (choose == 2)
		{
			Sleep(5000);
			printf("\n\nPress enter to continue...\n");
			getch();
			MainMenu();
		}
		if (choose == 3)
		{
			Sleep(5000);
			printf("\n\nPress enter to continue...\n");
			getch();
			MainMenu();
		}
		if (choose == 4)
		{
			Sleep(5000);
			printf("\n\nPress enter to continue...\n");
			getch();
			MainMenu();
		}
		if (choose == 5)
		{
			Sleep(5000);
			printf("\n\nPress enter to continue...\n");
			getch();
			MainMenu();
		}
		if (choose == 6)
		{
			Sleep(5000);
			printf("\n\nPress enter to continue...\n");
			getch();
			MainMenu();
		}
		if (choose == 7)
		{
			break;
		}
		else
		{
			Sleep(5000);
			MainMenu();
		}
	}
}
