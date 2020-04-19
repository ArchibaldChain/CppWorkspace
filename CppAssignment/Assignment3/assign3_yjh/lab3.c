#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utf8.h"

typedef struct DataNode
{
	int start_code;
	int end_code;
	char block_name[50];
} DataNode;

DataNode *database[300];

// Search for the index of the block to which the codepoint codept belongs, and return it
int search(int codept, int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (codept < database[i]->start_code)
			continue;

		if (codept > database[i]->end_code)
			continue;

		return i;
	}

	return -1;
}

int main(int argc, char const *argv[])
{
	// Part 1
	FILE *fp;
	fp = fopen("Blocks.txt", "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Cannot open file Blocks.txt\n");
		exit(1);
	}

	int i = 0;
	while (!feof(fp) && i < 300)
	{
		database[i] = (DataNode *) malloc(sizeof(DataNode));
		char line[100];
		fgets(line, sizeof(line), fp);
		if (line[0] == '#' || line[0] == '\n')
			continue;

		char *sbegin, *send;
		size_t token;

		sbegin = line;
		token = strcspn(sbegin, "..");
		send = sbegin + token;
		*send = '\0';
		database[i]->start_code = (int)strtol(sbegin, NULL, 16);

		sbegin = send + 2;
		token = strcspn(sbegin, "; ");
		send = sbegin + token;
		*send = '\0';
		database[i]->end_code = (int)strtol(sbegin, NULL, 16);
		
		sbegin = send + 2;
		token = strcspn(sbegin, "\n");
		send = sbegin + token;
		*send = '\0';
		strcpy(database[i]->block_name, sbegin);
		
		++i;
	}
	int size = i;
	int *freq = (int *) malloc(sizeof(int));
	fclose(fp);
	//TO SHOW THAT INFORMSTION OF BLOCKS IS LOADED INTO THE ARRAY
	/*
	printf("database:\n");
	for (int k = 0; k < size; ++k)
		printf("k = %d %x---%x---%s\n", k, database[k]->start_code, 
			database[k]->end_code, database[k]->block_name);
	*/

	// Part 2
	char fline[3000];
	while (fgets(fline, sizeof(fline), stdin))
	{
    	//printf("%s", fline);
		if (strcmp(fline, "\n") == 0)
			continue;

		char *tok;
    	tok = strtok(fline, " ");
    	while (tok != NULL)
    	{
        	//printf("%s\n", tok);
        	char *str = tok;
        	unsigned char *pt;
        	pt = (unsigned char *)str;
        	int lenptr = 0;
        	int codept = 0;
        	do
        	{
            	codept = utf8_to_codepoint(pt, &lenptr);
            	if (codept == 0)
            		break;

            	int index = search(codept, size);
            	freq[index]++;
            	//printf("%d = %d %s-> %x [%d]\n", index, freq[index], pt, codept, lenptr);
            	pt += lenptr;
        	}while (codept != 0);
        	tok = strtok(NULL, " ");
    	}
	}

	// Output
	int max = 0;
	for (int k = 0; k < size; ++k)
	{
		if (freq[k] > max)
        	max = k;
	}
	printf("%s\n", database[max]->block_name);
	free(freq);
	
	return 0;
}
