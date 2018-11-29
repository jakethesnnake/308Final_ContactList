// Hard to  program  with (Bad)
int  getchar(void);

//Allows  buffer  overflow , fragile (Bad)
int  scanf(const  char *format , ...);

FILE * fp = fopen("data.txt", "r");
if (fp == NULL) { return; }
int id;
char  first [100];
char  last [100];
while(fscanf(fp , "%d %s %s", &id , first , last) !=EOF) // EOF = end of file (.hasNextLine())
{
	printf("Id: %d, Name: %s %s\n", id, first ,last);
}
fclose(fp);

fscanf();
fprintf();