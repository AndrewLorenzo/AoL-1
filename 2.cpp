#include <bits/stdc++.h>
struct Hotel {
	char location[101];
	char city[101];
	long long int price;
	int room;
	int bath;
	int car;
	char type[101];
	char furnish[101];
};
void swap (struct Hotel *a, struct Hotel *b) {
	struct Hotel t = *a;
	*a = *b;
	*b = t;
}
void printH(){
	puts(" _______________________________________________________________________________________________________________________________________________________________________");
	puts("|Location\t\t\t\t            |City\t        |Price           |Rooms      |Bathroom   |Carpark    |Type                 |Furnish             |");
	puts("|___________________________________________________|___________________|________________|___________|___________|___________|_____________________|____________________|");
	}

void printB(Hotel cust){
	printf("|%-50s |%-18s |%-15lld |%-10d |%-10d |%-10d |%-20s |%-20s|\n", cust.location, cust.city, cust.price, cust.room, cust.bath, cust.car, cust.type, cust.furnish);
}

void printT(){
	puts("|___________________________________________________|___________________|________________|___________|___________|___________|_____________________|____________________|");

}
int partitioningL(struct Hotel a[], int left, int right, char type[]) {
	struct Hotel pivot = a[right];
	int i = (left-1);
	if (strcmpi(type, "asc")==0) {
		for (int j=left; j<=right-1; j++) {
			if (strcmp(a[j].location, pivot.location)<0) {
				i++;
				swap(&a[i], &a[j]);
			}
		}
		swap(&a[i+1], &a[right]);
		return (i+1);
	}
	else {
		for (int j=left; j<=right-1; j++) {
			if (strcmp(a[j].location, pivot.location)>0) {
				i++;
				swap(&a[i], &a[j]);
			}
		}
		swap(&a[i+1], &a[right]);
		return (i+1);
	}
}
int partitioningC(struct Hotel a[], int left, int right, char type[]) {
	struct Hotel pivot = a[right];
	int i = (left-1);
	if (strcmpi(type, "asc")==0) {
		for (int j=left; j<=right-1; j++) {
			if (a[j].car < pivot.car) {
				i++;
				swap(&a[i], &a[j]);
			}
		}
		swap(&a[i+1], &a[right]);
		return (i+1);
	}
	else {
		for (int j=left; j<=right-1; j++) {
		if (a[j].car > pivot.car) {
			i++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[i+1], &a[right]);
	return (i+1);
	}
}
int partitioningT(struct Hotel a[], int left, int right, char type[]) {
	struct Hotel pivot = a[right];
	int i = (left-1);
	if (strcmpi(type, "asc")==0) {
		for (int j=left; j<=right-1; j++) {
			if (strcmp(a[j].type, pivot.type)<0) {
				i++;
				swap(&a[i], &a[j]);
			}
		}
		swap(&a[i+1], &a[right]);
		return (i+1);
	}
	else {
		for (int j=left; j<=right-1; j++) {
		if (strcmp(a[j].type, pivot.type)>0) {
			i++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[i+1], &a[right]);
	return (i+1);
	}
}
int partitioningF(struct Hotel a[], int left, int right, char type[]) {
	struct Hotel pivot = a[right];
	int i = (left-1);
	if (strcmpi(type, "asc")==0) {
		for (int j=left; j<=right-1; j++) {
			if (strcmp(a[j].furnish, pivot.furnish)<0) {
				i++;
				swap(&a[i], &a[j]);
			}
		}
		swap(&a[i+1], &a[right]);
		return (i+1);
	}
	else {
		for (int j=left; j<=right-1; j++) {
		if (strcmp(a[j].furnish, pivot.furnish)>0) {
			i++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[i+1], &a[right]);
	return (i+1);
	}
}
int partitioningP(struct Hotel a[], int left, int right, char type[]) {
	struct Hotel pivot = a[right];
	int i = (left-1);
	if (strcmpi(type, "asc")==0) {
		for (int j=left; j<=right-1; j++) {
			if (a[j].price < pivot.price) {
				i++;
				swap(&a[i], &a[j]);
			}
		}
		swap(&a[i+1], &a[right]);
		return (i+1);
	}
	else {
		for (int j=left; j<=right-1; j++) {
		if (a[j].price > pivot.price) {
			i++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[i+1], &a[right]);
	return (i+1);
	}
}
int partitioningB(struct Hotel a[], int left, int right, char type[]) {
	struct Hotel pivot = a[right];
	int i = (left-1);
	if (strcmpi(type, "asc")==0) {
		for (int j=left; j<=right-1; j++) {
			if (a[j].bath < pivot.bath) {
				i++;
				swap(&a[i], &a[j]);
			}
		}
		swap(&a[i+1], &a[right]);
		return (i+1);
	}
	else {
		for (int j=left; j<=right-1; j++) {
		if (a[j].bath > pivot.bath) {
			i++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[i+1], &a[right]);
	return (i+1);
	}
}
int partitioningR(struct Hotel a[], int left, int right, char type[]) {
	struct Hotel pivot = a[right];
	int i = (left-1);
	if (strcmpi(type, "asc")==0) {
		for (int j=left; j<=right-1; j++) {
			if (a[j].room < pivot.room) {
				i++;
				swap(&a[i], &a[j]);
			}
		}
		swap(&a[i+1], &a[right]);
		return (i+1);
	}
	else {
		for (int j=left; j<=right-1; j++) {
		if (a[j].room > pivot.room) {
			i++;
			swap(&a[i], &a[j]);
		}
	}
	swap(&a[i+1], &a[right]);
	return (i+1);
	}
}
void quickSortL(struct Hotel a[], int left, int right, char type[]) {
	if (left < right) {
		int pivot = partitioningL(a, left, right, type);
		quickSortL(a, left, pivot-1, type);
		quickSortL(a, pivot+1, right, type);
	}
}
void quickSortC(struct Hotel a[], int left, int right, char type[]) {
	if (left < right) {
		int pivot = partitioningC(a, left, right, type);
		quickSortC(a, left, pivot-1, type);
		quickSortC(a, pivot+1, right, type);
	}
}
void quickSortT(struct Hotel a[], int left, int right, char type[]) {
	if (left < right) {
		int pivot = partitioningT(a, left, right, type);
		quickSortT(a, left, pivot-1, type);
		quickSortT(a, pivot+1, right, type);
	}
}
void quickSortF(struct Hotel a[], int left, int right, char type[]) {
	if (left < right) {
		int pivot = partitioningF(a, left, right, type);
		quickSortF(a, left, pivot-1, type);
		quickSortF(a, pivot+1, right, type);
	}
}
void quickSortP(struct Hotel a[], int left, int right, char type[]) {
	if (left < right) {
		int pivot = partitioningP(a, left, right, type);
		quickSortP(a, left, pivot-1, type);
		quickSortP(a, pivot+1, right, type);
	}
}
void quickSortB(struct Hotel a[], int left, int right, char type[]) {
	if (left < right) {
		int pivot = partitioningB(a, left, right, type);
		quickSortB(a, left, pivot-1, type);
		quickSortB(a, pivot+1, right, type);
	}
}
void quickSortR(struct Hotel a[], int left, int right, char type[]) {
	if (left < right) {
		int pivot = partitioningR(a, left, right, type);
		quickSortR(a, left, pivot-1, type);
		quickSortR(a, pivot+1, right, type);
	}
}
void MainMenu () {
	puts("What do you want to do?\n"
	"1. Display data\n"
	"2. Search data\n"
	"3. Sort data\n"
	"4. Export data\n"
	"5. Exit");
}
int main () {
	char temp[10000];
	FILE *p;
	p=fopen("file.csv", "r");
	fscanf(p, "%[^\n]\n",temp);
	int c=0, n;
	Hotel cust[3940];
	char col[101];
	int r, jml;
	long long int pr;
	for (int i=0; !feof(p); i++) {
		fscanf(p, "%[^,],%[^,],%lld,%d,%d,%d,%[^,],%[^\n]\n", cust[i].location, cust[i].city, &cust[i].price, &cust[i].room, &cust[i].bath, &cust[i].car, cust[i].type, cust[i].furnish);
		jml++;
	}
	fclose(p);
	do {
		MainMenu();
		printf("Your Choice: ");
		scanf("%d", &c);
		getchar();
		if (c==1) {
			printf("Total data : %d\n", jml);
			printf("Number of rows: ");
			scanf("%d", &n);
			getchar();// 
			system("cls");
			printH();
			for (int i=0; i<n; i++) {
				printB(cust[i]);
			}
			printT();
		}
		else if (c==2) {
			int isFound=0;
			printf("Choose column: ");
			scanf("%s", col);
			getchar();
			char loc[101];
			if (strcmpi(col,"Location")==0) {
				printf("What data do you want to find? ");
				scanf("%[^\n]", loc);
				getchar();
				for (int i=0; i<jml; i++) {
					if (strcmpi(loc, cust[i].location)==0) {
						isFound=1;
						break;
					}
				}
				if (isFound) {
					printH();
					for (int i=0; i<jml; i++) {
						if (strcmpi(loc, cust[i].location)==0) printB(cust[i]);
					}
					printT();
				}
				else if (!isFound) {
					puts("Data not found!");
				}
			}
			else if (strcmpi(col,"Rooms")==0) {
				printf("What data do you want to find? ");
				scanf("%d", &r);
				getchar();
				for (int i=0; i<jml; i++) {
					if (r==cust[i].room) {
						isFound=1;
						break;
					}
				}
				if (isFound) {
					puts("Data found. Detail of data: ");
					printH();
					for (int i=0; i<jml; i++) {
						if (r==cust[i].room) printB(cust[i]);
					}
					printT();
				}
				else if (!isFound) {
					puts("Data not found!");
				}
			}
			else if (strcmpi(col,"Carpark")==0) {
				printf("What data do you want to find? ");
				scanf("%d", &r);
				getchar();
				for (int i=0; i<jml; i++) {
					if (r==cust[i].car) {
						isFound=1;
						break;
					}
				}
				if (isFound) {
					puts("Data found. Detail of data: ");
					printH();
					for (int i=0; i<jml; i++) {
						if (r==cust[i].car) printB(cust[i]);
					}
					printT();
				}
				else if (!isFound) {
					puts("Data not found!");
				}
			}
			else if (strcmpi(col,"Price")==0) {
				printf("What data do you want to find? ");
				scanf("%lld", &pr);
				getchar();
				for (int i=0; i<jml; i++) {
					if (pr==cust[i].price) {
						isFound=1;
						break;
					}
				}
				if (isFound) {
					puts("Data found. Detail of data: ");
					printH();
					for (int i=0; i<jml; i++) {
						if (r==cust[i].car) printB(cust[i]);
					}
					printT();
				}
				else if (!isFound) {
					puts("Data not found!");
				}
			}
			else if (strcmpi(col, "Bathroom")==0) {
				printf("What data do you want to find? ");
				scanf("%lld", &pr);
				getchar();
				for (int i=0; i<jml; i++) {
					if (cust[i].bath==pr) {
						isFound=1;
						break;
					}
				}
				if (isFound) {
					puts("Data found. Detail of data: ");
					printH();
					for (int i=0; i<jml; i++) {
						if (cust[i].bath==pr) printB(cust[i]);
					}
					printT();
				}
				else if (!isFound) {
					puts("Data not found!");
				}
			}
			else if (strcmpi(col, "Furnish")==0) {
				printf("What data do you want to find [Partly | Fully | Unfurnished]? ");
				scanf("%[^\n]", loc);
				getchar();
				for (int i=0; i<jml; i++) {
					if (strcmpi(loc, cust[i].furnish)==0) {
						isFound=1;
						break;
					}
				}
				if (isFound) {
					puts("Data found. Detail of data: ");
					printH();
					for (int i=0; i<jml; i++) {
						if (strcmpi(loc, cust[i].furnish)==0) printB(cust[i]);
					}
					printT();
				}
				else {
					puts("Data not found!");
				}
			}
			else if (strcmpi(col, "Type")==0) {
				printf("What data do you want to find [Built-Up | Land-Area]? ");
				scanf("%[^\n]", loc);
				getchar();
				for (int i=0; i<jml; i++) {
					if (strcmpi(loc, cust[i].type)==0) {
						isFound=1;
						break;
					}
				}
				if (isFound) {
					puts("Data found. Detail of data: ");
					printH();
					for (int i=0; i<jml; i++) {
						if (strcmpi(loc, cust[i].type)==0) printB(cust[i]);
					}
					printT();
				}
				else {
					puts("Data not found!");
				}
			}
			else {
				puts("Column Not Found!!!");
			}
		}
		else if (c==3) {
			char type[100];
			printf("Choose Column: ");
			scanf("%[^\n]", col);
			getchar();
			do {
				printf("Sort ascending or descending [asc|dsc]? ");
				scanf("%[^\n]", type);
				getchar();
			}
			while (strcmpi(type,"asc")!=0 && strcmpi(type,"dsc")!=0);
			if (strcmpi(col, "Location")==0) {
				quickSortL(cust, 0, jml-1, type);
			}
			else if (strcmpi(col, "Rooms")==0) {
				quickSortR(cust, 0, jml-1, type);
			}
			else if (strcmpi(col, "Price")==0) {
				quickSortP(cust, 0, jml-1, type);
			}
			else if (strcmpi(col, "Bathroom")==0) {
				quickSortB(cust, 0, jml-1, type);
			}
			else if (strcmpi(col, "Carpark")==0) {
				quickSortC(cust, 0, jml-1, type);
			}
			else if (strcmpi(col, "Type")==0) {
				quickSortT(cust, 0, jml-1, type);
			}
			else if (strcmpi(col, "Furnish")==0) {
				quickSortF(cust, 0, jml-1, type);
			}
			else {
				puts("Column not found!!!");
			}
		}
		else if (c==4) {
			char fn[101];
			printf("File Name: ");
			scanf("%[^\n]", fn);
			getchar();
			sprintf(fn, "%s.csv", fn);
			printf("Data sucecssfully written to file %s\n", fn);
			p = fopen(fn, "w");
			for (int i=0; i<jml; i++) {
				fprintf(p, "%s,%s,%lld,%d,%d,%d,%s,%s\n", cust[i].location, cust[i].city, cust[i].price, cust[i].room, cust[i].bath, cust[i].car, cust[i].type, cust[i].furnish);
			}
		}
		else if (c!=5) {
			puts("Invalid menu!!!");
		}
	}
	while (c!=5);
	puts("Thank you!\nHave a nice day :D");
}
/*
Country-Heights-Damansara
buat input search location
*/
