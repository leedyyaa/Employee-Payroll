#define _CRT_SECURE_NO_WARNINGS
#define SIZE 4
#include <stdio.h>
#include<math.h>
#include<string.h>

/*
Lydia Kim
CS36 Prof. Hochwald
Program 10
*/

struct Employee {
    char name[20];
    float hours, rate, fedTax, stateTax;
    float gross, fedOwed, stateOwed, net;
    float tGross, tFed, tState, tNet;

};

void calc(struct Employee s[], int n) {
  for (int i = 0; i<n; i++) {

    printf("\nPlease enter the name: ");
    gets_s(s[i].name, 20);
    printf("\nPlease enter amount of hours worked and hourly rate: ");
    scanf("%f%f", &s[i].hours, &s[i].rate);
    printf("\nPlease enter the federal and state tax: ");
    scanf("%f%f", &s[i].fedTax, &s[i].stateTax);

    s[i].gross = s[i].hours * s[i].rate;
    s[i].fedOwed = s[i].gross * s[i].fedTax / 100;
    s[i].stateOwed = s[i].gross * s[i].stateTax / 100;
    s[i].net = s[i].gross - s[i].fedOwed - s[i].stateOwed;
  
    s[i].tGross += s[i].gross;
    s[i].tFed += s[i].fedOwed;
    s[i].tState += s[i].stateOwed;
    s[i].tNet += s[i].net; 
    getchar();
  }
}

void print(struct Employee s[], int n) {
  for (int i = 0; i<n; i++) {
    printf("\nName: %s", s[i].name);
    printf("\nGross pay: $%.2f", s[i].gross);
    printf("\nFederal tax owed: $%.2f", s[i].fedOwed);
    printf("\nState tax owed: $%.2f", s[i].stateOwed);
    printf("\nNet pay: $%.2f", s[i].net);
  }
}

void printT(struct Employee s[], int n) {
  for (int i = 0; i<n; i++) {
    printf("\nTotal gross pay: $%.2f", s[i].tGross);
    printf("\nTotal federal taxes owed: $%.2f", s[i].tFed);
    printf("\nTotal state taxes owed: $%.2f", s[i].tState);
    printf("\nTotal net pay: $%.2f", s[i].tNet);
  }
}

void sort(struct Employee s[], int n) {
    int i, j;
    Employee t;

    for (i = 0; i<n-1;i++) {
        for (j=0; j<n-1; j++) {
            if (strcmp(s[j].name, s[j+1].name) > 0) {
                t=s[j];
                s[j] = s[j+1];
                s[j+1]=t;
            }
        }
    }
}

void savetest(struct Employee s[], int n){
    FILE *f;
    f = fopen("d:\\employee.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(f, "%s\n", s[i].name);
        fprintf(f, "%f %f %f %f\n", s[i].gross, s[i].fedOwed, s[i].stateOwed, s[i].net);
    }
    fclose(f);
    }

void retrievetest(struct Employee s[], int n) {
    FILE *f;
    int length;
    f = fopen("d:\\employee.txt", "r");
    for (int i = 0; i < n; i++){
        fgets(s[i].name, sizeof(s[i].name), f);
        length = strlen(s[i].name);
        s[i].name[length - 1] = '\0';
        fscanf(f, "%f %f %f %f\n", &s[i].gross, &s[i].fedOwed, &s[i].stateOwed, &s[i].net);
    }
    fclose(f);
    }

void savebin(struct Employee s[], int n) {
    FILE *f;
    f = fopen("d:\\employee.bin", "wb");
    fwrite(&s, sizeof(s[0]), n, f);
    fclose(f);
    }

void retrievebin(struct Employee s[], int n) {
    FILE *f;
    f = fopen("d:\\employee.bin", "rb");
    fread(&s, sizeof(s[0]), n, f);
    fclose(f);
}

void main() {

    Employee s[SIZE];
    calc(s, SIZE);
    sort(s, SIZE);
    print(s, SIZE);
    printT(s, SIZE);
    savetest(s, SIZE);
    retrievetest(s, SIZE);
    printf("\n\nAfter the text file is retrieved\n\n");
    print(s, SIZE);
    savebin(s, SIZE);
    retrievebin(s, SIZE);
    printf("\n\nAfter the binary file is retrieved\n\n");
    print(s, SIZE);

    //system("PAUSE");
}

/*
Terminal output 

Please enter the name: Steph Durant

Please enter amount of hours worked and hourly rate: 42.5
55.16

Please enter the federal and state tax: 19.7
6.8

Please enter the name: Kevin Curry

Please enter amount of hours worked and hourly rate: 38.75
49.77

Please enter the federal and state tax: 16.3
9.88

Please enter the name: Clay Green

Please enter amount of hours worked and hourly rate: 24.3
49.99

Please enter the federal and state tax: 16.7
6.95

Please enter the name: Draymond Thompson

Please enter amount of hours worked and hourly rate: 54.35
66.66

Please enter the federal and state tax: 20.5
8.53


Name: Steph Durant
Gross pay: $2344.30
Federal tax owed: $461.83
State tax owed: $159.41
Net pay: $1723.06

Name: Kevin Curry
Gross pay: $1928.59
Federal tax owed: $314.36
State tax owed: $190.54
Net pay: $1423.68

Name: Clay Green
Gross pay: $1214.76
Federal tax owed: $202.86
State tax owed: $84.43
Net pay: $927.47

Name: Draymond Thompson
Gross pay: $3872.95
Federal tax owed: $793.95
State tax owed: $330.36
Net pay: $2748.63

Total gross pay: $9360.59
Total federal taxes owed: $1773.01
Total state taxes owed: $764.74
Total net pay: $6822.84

After the text file is retrieved

Name: Steph Durant
Gross pay: $2344.30
Federal tax owed: $461.83
State tax owed: $159.41
Net pay: $1723.06

Name: Kevin Curry
Gross pay: $1928.59
Federal tax owed: $314.36
State tax owed: $190/54
Net pay: $1423.68

Name: Clay Green
Gross pay: $1214.76
Federal tax owed: $202.86
State tax owed: $84.43
Net pay: $927.47

Name: Draymond Thompson
Gross pay: $3872.95
Federal tax owed: $793.95
State tax owed: $330.36
Net pay: $2748.63

After the binary file is retrieved 

Name: Steph Durant
Gross pay: $2344.30
Federal tax owed: $461.83
State tax owed: $159.41
Net pay: $1723.06

Name: Kevin Curry
Gross pay: $1928.59
Federal tax owed: $314.36
State tax owed: $190/54
Net pay: $1423.68

Name: Clay Green
Gross pay: $1214.76
Federal tax owed: $202.86
State tax owed: $84.43
Net pay: $927.47

Name: Draymond Thompson
Gross pay: $3872.95
Federal tax owed: $793.95
State tax owed: $330.36
Net pay: $2748.63
*/


