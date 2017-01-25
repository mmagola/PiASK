/*
 ============================================================================
 Name        : histogram_OMP.c
 Author      : MIS
 Version     :
 Copyright   : Your copyright notice
 Description : Hello OpenMP World in C
 ============================================================================
 */
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include "my_timers.h"
#include <math.h>
#include "FreeImage.h"

#define NBR_OF_ELEMENTS 40000

main() {


	FreeImage_Initialise(TRUE);
	FIBITMAP *bitmap = FreeImage_Load(FIF_BMP, "C:\\Studia\\IX_Semestr\\PIASK\\part_2\\project\\eclipse_Mars_worlspace\\lena.bmp", BMP_DEFAULT);
	if(bitmap){
		unsigned width = FreeImage_GetWidth(bitmap);
		unsigned height = FreeImage_GetHeight(bitmap);
		unsigned pitch = FreeImage_GetPitch(bitmap);

		printf("obrazek zaladowany \n width = %d, height = %d, pitch = %d \n", width, height,pitch );
		BYTE *ptr = FreeImage_GetBits(bitmap);
		if(ptr){
			printf("udalo sie tez GetBits\n");
		}
		FreeImage_Unload(bitmap);
	}else{
		printf("obrazek nie za³adowany\n bitmap = %d", bitmap);
	}


	long i = 0;
	float a[NBR_OF_ELEMENTS];
	omp_set_num_threads(4);
	start_time();
#pragma omp parallel for
	for (i = 0; i < NBR_OF_ELEMENTS; i++)
		a[i] = sqrt(i);

	stop_time();
	print_time("Elapsed:");
	//FreeImage_Unload(bitmap);
	FreeImage_DeInitialise();
}

