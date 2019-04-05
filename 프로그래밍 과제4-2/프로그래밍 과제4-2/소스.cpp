#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

typedef struct log {
	char IP[15];
	char time[30];
	char URL[1000];
	char sta[4];
}log;




char cal[12][10] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };

log weblog[16000];
int n = 0;
char temp[16000][1000];
void sort_ip();
void sort_t();
void switc(char *str);
int compare_ary_time(const void*p, const void *q);
int compare_ary_ip(const void*p, const void *q);


int main(void) {

	char *context = NULL;
	int x;


	errno_t err;
	FILE *fp;

	err = fopen_s(&fp, "webLog.csv", "r");
	if (err == 0)
		puts("파일오픈 성공(기다려 주세요)\n");
	else
		puts("파일 오픈 실패\n");


	fgets(temp[n], 1000, fp);

	while (fgets(temp[n++], 1000, fp) != 0) {
		strcpy_s(weblog[n - 1].IP, 1000, strtok_s(temp[n - 1], ",[", &context));
		strcpy_s(weblog[n - 1].time, 1000, strtok_s(NULL, ",[", &context));
		strcpy_s(weblog[n - 1].URL, 1000, strtok_s(NULL, ",", &context));
		strcpy_s(weblog[n - 1].sta, 1000, strtok_s(NULL, ",\n", &context));
	}



	while (1) {
		printf("\n 어떤 태그 순으로 정렬할지 선택하시오: 시간(1) ip주소(2) 종료 (0)\n");
		scanf_s("%d", &x);

		if (x == 0)
			break;
		else if (x == 2)
			sort_ip();
		else if (x == 1)
			sort_t();
	}


	return 0;


}

void sort_t() {
	printf("\n");

	qsort(weblog, n - 1, sizeof(log), compare_ary_time);

	for (int i = 0; i < n - 1; i++) {
		printf("%s\n", weblog[i].time);
		printf("    IP: %s\n", weblog[i].IP);
		printf("    URL: %s\n", weblog[i].URL);
		printf("    Status: %s\n", weblog[i].sta);
	}

}

void sort_ip() {
	printf("\n");
	qsort(weblog, n - 1, sizeof(log), compare_ary_ip);

	for (int i = 0; i < n - 1; i++) {
		printf("%s\n", weblog[i].IP);
		printf("    Time: %s\n", weblog[i].time);
		printf("    URL: %s\n", weblog[i].URL);
		printf("    Status: %s\n", weblog[i].sta);
	}

}

void switc(char *str) {

	for (int i = 0; i < 12; i++)
		if (strcmp(cal[i], str) == 0) {
			str[0] = i;
			str[1] = '\0';
		}

}

int compare_ary_time(const void*p, const void *q) {

	int result;

	char a[30], b[30];
	char *temp_a[4], *temp_b[4];
	char *context = NULL;


	strcpy_s(a, ((log*)p)->time);
	strcpy_s(b, ((log*)q)->time);



	temp_a[2] = strtok_s(a, "/", &context);
	temp_a[1] = strtok_s(NULL, "/", &context);
	temp_a[0] = strtok_s(NULL, ":", &context);
	temp_a[3] = strtok_s(NULL, " ", &context);

	temp_b[2] = strtok_s(b, "/", &context);
	temp_b[1] = strtok_s(NULL, "/", &context);
	temp_b[0] = strtok_s(NULL, ":", &context);
	temp_b[3] = strtok_s(NULL, " ", &context);


	for (int i = 0; i < 4; i++) {
		if (i == 1)
		{
			switc(temp_a[i]);
			switc(temp_b[i]);
		}
		if (strcmp(temp_a[i], temp_b[i]) != 0) {
			result = strcmp(temp_a[i], temp_b[i]);
			return result;
		}
	}

	return 0;
}


int compare_ary_ip(const void*p, const void *q) {

	int result;

	if (strcmp(((log*)p)->IP, ((log*)q)->IP) != 0)
	{
		result = strcmp(((log*)p)->IP, ((log*)q)->IP);
		return result;
	}
	else
		return compare_ary_time(p, q);
}