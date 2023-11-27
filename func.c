#include <stdio.h>
#include <stdlib.h>
#include "func.h"


void create(movie **arr, int *n)
{
	printf("Number of records: ");
	scanf("%i", n);
	
	
	if(*n<=0) return;
	
	*arr = (movie *)calloc(*n, sizeof(movie));
	
	if(!arr) return;
	
	for(int i = 0; i < *n; i++)
	{
		printf("Movie number %i:\n", i+1);
		printf("|Enter directors name: ");
		scanf("%s", (*arr)[i].name);
		printf("|Enter genre: ");
		scanf("%f", &(*arr)[i].genre);
		printf("|Enter duration: ");
		scanf("%i", &(*arr)[i].duration);
		
	};
	
}

void read(movie **arr, int *n)
{
	FILE *file = fopen("DB.txt","r");
	if(!file) return;
	
	if(fscanf(file,"%d",n)!=1)
	{
		fclose(file);
		return;
	};
	
	*arr = (movie *)calloc(*n, sizeof(movie));
		
	for(int i = 0; i < *n; i++)
	{
		if(fscanf(file, "%s %f %i", (*arr)[i].name, &(*arr)[i].genre, &(*arr)[i].duration)!=3) break;
	};
	
	fclose(file);
}

void write(movie *arr, int n)
{
	if(n<=0) return;
	FILE *file = fopen("DB.txt","w");
	if(!file)
	{
		printf("Failed");
		return;
	};
	
	fprintf(file, "%i\n" ,n);
	
	for(int i = 0; i < n; i++)
	{
		fprintf(file, "%s %f %i\n" ,arr[i].name, arr[i].genre, arr[i].duration);
	}
	fclose(file);
};
