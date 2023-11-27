#include <stdio.h>
#include <stdlib.h>
#include "func.h"

int main()
{
	
	movie *arr = NULL;
	int n = 0;
	
	int stopCycle = 1;
	
	int tempKey = 0;
	
	while(stopCycle){
		int key = 0;
		
		key += tempKey;
		tempKey = 0;
		
		if (!key)
		{
			printf("Your actions?\n|1. Create a database \n|2. Print the database \n|3. Search in the database\n|0. Exit the program\n");
			scanf("%i", &key);
		}
		
		switch (key)
		{
			case 1:{
				int key2;
				
				printf("Do you want to:\n|1. Write the new one \n|2. Load an existing one from a file\n");
				scanf("%i", &key2);
				
				
				if (key2==1) {	
					create(&arr, &n);
					if(!arr) 
					{
						printf("!ERROR!\n");
						stopCycle = 0;
						break;
					}
					else
					{
						printf("found %d films\n\n", n);
					}
					write(arr,n);
					}
				else if(key2==2){
					read(&arr, &n);
					if(!arr) 
					{
						printf("ERROR\n");
						stopCycle = 0;
						break;
					}
					else
					{
						printf("Loaded %d films\n\n", n);
					}
				}
				break;
			}
			case 2:
				if(!arr) 
					{
						int key3;
						printf("Couldn't find the database. Would you like to create one?\n|1 - Yes\n|2 - No\n");
						scanf("%i", &key3);
						if(key3==1) tempKey=1;
						else stopCycle = 0;
						break;
					}
					else
					{
						for(int i = 0; i<n; i++) printf("Name: %s; Name: %0.2f; genre: %i;\n", arr[i].genre, arr[i].name, arr[i].genre);
						printf("%c",'\n');
					}
				
				break;
			case 3:
				if(!arr) 
					{
						int key3;
						printf("Couldn't find the database. Would you like to create one?\n|1 - Yes\n|2 - No\n");
						scanf("%i", &key3);
						if(key3==1) tempKey=1;
						else stopCycle = 0;
						break;
					}
					else
					{
						search(arr,n);
					}
				break;
			default:
				stopCycle = 0;
				break;
		}
	}
	if (arr) free(arr);
	return 0;
}