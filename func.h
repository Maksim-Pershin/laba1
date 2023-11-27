typedef struct movie{
	char name[40];
	float genre;
	int duration;
}movie;

void create(movie **arr, int *n);
void write(movie *arr, int n);
void read(movie **arr, int *n);

void search(movie *arr, int n);