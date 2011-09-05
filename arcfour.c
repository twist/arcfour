#include <stdio.h>
#include <string.h>


char *  initialize_key_vector(char key[]);
char * encrypt_message(char * message, char * K);
	unsigned char K[256];
int main(int argc, char * argv[])
{
	char * K = initialize_key_vector("asdsadasd");
	//printf("%s\n",encrypt_message(argv[2], K));
};


char *  initialize_key_vector(char *key)
{
	unsigned char i = 0;
	unsigned char j = 0;
	unsigned char tmp;
	for(i= 0; i < 255; i++)
	{
		K[i] = i;
	}
	for(i= 0; i < 255; i++)
	{
		j = (j + K[i] + key[(i % strlen(key))]) % 256;
		tmp = K[i];
		K[i] = K[j];
		K[j] = tmp;
	}
	return K;
};

char * encrypt_message(char * message, char * K)
{
	unsigned char i = 0;
	unsigned char j = 0;
	unsigned char x;
	unsigned char tmp;

	for(x = 0; x < strlen(message); x++)
	{
		i = (i+1)%256;
		j = (j+K[i])%256;
		tmp = K[i];
		K[i] = K[j];
		K[j] = tmp;
		message[x] = message[x] ^ (K[((K[i]+K[j])%256)]);
	}
	return message;

}


