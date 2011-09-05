#include <stdio.h>
#include <string.h>


char *  initialize_key_vector(char key[]);
	char K[256];
int main(int argc, char * argv[])
{
	initialize_key_vector("ölkjöl");
};


char *  initialize_key_vector(char *key)
{
	char i;
	char j;
	char tmp;
	for(i= 0; i < 255; i++)
	{
		K[i] = i;
	}

	for(i= 0; i < 255; i++)
	{
		j = (j + K[i] + key[i%strlen(key)]) % 256;
		tmp = K[i];
		K[i] = K[j];
		K[j] = tmp;
	}
	return K;
};


