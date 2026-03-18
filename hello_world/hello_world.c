#include <stdio.h>
#include <string.h>
#include <sys/cdefs.h>

typedef struct Array_t {
	int* ptr; // size 8
	int len;  // size 4
} Array;

void printArray(int* ptr, int size);
void printString(char* ptr);
void printArgs(char** ptr, int size);
void printViaStruct(Array array);

int main(int argc, char** argv) {
	char string[] = "hello world";
	int array[4] = {1,2,3,4};

	sizeof(Array);

	printArray(array, sizeof(array)/sizeof(*array));
	printf("\n\n");
	printString(string);
	printf("\n\n");
	printArgs(argv, argc);
	printf("\n\n");
	Array compact = {array, sizeof(array)/sizeof(*array)};
	printViaStruct(compact);

	//int len = strlen(string);
	//printf("strlen: %i\n", len);

	/** array access is pointer arithmetics */
	//printf("%i\n",array[1]);
	//printf("%i\n",1[array]);
	//printf("%i\n",*(array+1));

	printArray(array, sizeof(array)/sizeof(*array));
	printArray(array, sizeof(array)/sizeof(*array));
	printArray(array, sizeof(array)/sizeof(*array));
	printArray(array, sizeof(array)/sizeof(*array));
	printArray(array, sizeof(array)/sizeof(*array));
	return 0;
}

void printArray(int* ptr, int size) {
	static int test;
	for (int i = 0; i < size; i++) {
		printf("   %i\n", ptr[i]);
	}
	printf("Test is %i als integer, als float: %f\n", ++test, (float)test);
}

void printString(char* ptr) {
	for (int i = 0; ptr[i] != 0; i++) {
		printf("   %c\n", ptr[i]);
	}
}

void printArgs(char** ptr, int size) {
	for (int i = 0; i < size; i++) {
		printf("   %s\n", ptr[i]);
	}
}

void printViaStruct(Array array){
	for (int i = 0; i < array.len; i++) {
		printf("   %i\n", array.ptr[i]);
	}
}