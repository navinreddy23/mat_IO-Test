#include <stdio.h>
#include <matio.h>
#include <stdint.h>

int main(void)
{
	printf("Matio example\r\n");

	mat_t *matfp = NULL; //matfp contains pointer to MAT file or NULL on failure
	matfp = Mat_Open("input_frame.mat", MAT_ACC_RDONLY);

	if(matfp == NULL)
	{
		printf("Opening failed\r\n");
	}

	uint16_t ver = Mat_GetVersion(matfp);
	printf("Version: 0x%4X\r\n", ver);

    matvar_t *matvar; 
 
    if ( NULL == matfp ) 
	{ 
		printf("NULL PTR\r\n");
    } 

	double* data = NULL;

	matvar = Mat_VarRead(matfp, "input_frame"); 

    if ( NULL != matvar ) 
	{ 
        Mat_VarPrint(matvar,0); 
        
		size_t size = Mat_VarGetSize(matvar);
		printf("Size: %lu\r\n", size);
		printf("Mat var name: %s\r\n", matvar->name);
		printf("Datasize: %d\r\n", matvar->data_size);
		size_t* dims = matvar->dims;
		printf("Dims: %lu x %lu\r\n", dims[0], dims[1]);

		data = matvar->data;
    } 

	uint32_t row = 1, column = 1;

	uint32_t index = (row - 1) + ((column - 1) * 7034);

	printf("Value = %e\r\n", data[index]); 
 
	Mat_VarFree(matvar);
	Mat_Close(matfp);
}	
