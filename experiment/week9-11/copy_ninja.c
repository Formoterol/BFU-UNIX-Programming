#include<stdio.h>
int main() {
	const char* s = "#include<stdio.h>%cint main(){%c%cconst char *s=%c%s%c;%c%cprintf(s, 10, 10, 9, 34, s, 34, 10, 9, 10, 9, 10, 9, 34, 34, 34, 34, 10, 9, 10, 9, 10, 9, 10);%c%cFILE*fp;%c%cfp = fopen(%cvirus.txt%c,%cw+%c);%c%cfprintf(fp, s, 10, 10, 9, 34, s, 34, 10, 9, 10, 9, 10, 9, 34, 34, 34, 34, 10, 9, 10, 9, 10, 9, 10);%c%cfclose(fp);%c%creturn 0;%c}";
	printf(s, 10, 10, 9, 34, s, 34, 10, 9, 10, 9, 10, 9, 34, 34, 34, 34, 10, 9, 10, 9, 10, 9, 10);
	FILE* fp;
	fp = fopen("copy_ninja.txt", "w+");
	fprintf(fp, s, 10, 10, 9, 34, s, 34, 10, 9, 10, 9, 10, 9, 34, 34, 34, 34, 10, 9, 10, 9, 10, 9, 10);
	fclose(fp);
	return 0;
}