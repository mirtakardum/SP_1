#include<stdio.h>
#include<stdlib.h>

typedef struct {
	char ime[100];
	char prezime[100];
	int bodovi;
}_student;
int prebroji(FILE*);
void relativni(_student* ,int*, int);

int main() {
	int i = 0, n = 0;
	FILE* ulz = NULL;
	int* rel = NULL;
	_student* s;
	
	ulz = fopen("studenti.txt", "r");
	if (ulz == NULL) {
		printf("Greska pri otvaranju datoteke.\n");
		return -1;
	}
	n = prebroji(ulz);
	s = (_student*)malloc(sizeof(_student) * n);
	rel = (int*)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		fscanf(ulz, "%s %s %d", s[i].ime, s[i].prezime, &s[i].bodovi);
	relativni(s, rel, n);
	for (i = 0; i < n; i++)
		printf("%s %s %d %d\n", s[i].ime, s[i].prezime, s[i].bodovi, rel[i]);
	return 0;
}
int prebroji(FILE* ulz) {
	int n = 0;
	while (!feof(ulz))
		n++;
	return n;
}
void relativni(_student *s ,int* rel, int n) {
	int i = 0;
	int maks = 0;
	for (i = 0; i < n; i++) {
		if (s[i].bodovi > maks)
			maks = s[i].bodovi;
	}
	for (i = 0; i < n; i++) {
		rel[i] = s[i].bodovi / maks * 100;
	}

}