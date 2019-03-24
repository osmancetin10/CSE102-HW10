						/***************************/
						/*                         */
						/*      Osman Çetin        */
						/*       161044069         */
						/*         HW-10           */
						/*		                   */
						/***************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* this program find prime numbers between 1 and 1000000 and calculates running time*/ 
typedef struct list{/*this structer using for linked list*/
    int data;
    struct list* next;
}l1;

l1 *first=NULL;/*this is linked list's head*/
l1 *last=NULL;/*this is linked list's tail*/
l1 *temp;

int read_text(FILE* fl);
void add_list();
void find_prime();/*these five things are prototype's of functions*/
int size_text();
int prime_number(int number);


int main(){		
	find_prime(); 
}

int read_text(FILE* fl){/*this function reads text line by line and convert to integer*/
	char value[100];
	fgets(value,100,fl);
	return atoi(value);/*atoi function converts string to integer value*/
}

void find_prime(){/*this function manage all program*/
	FILE *fl,*fl2,*fl3;/*these are file pointers*/
	fl=fopen("data.txt","r");	
	fl2=fopen("output_prime_dynamic_array.txt","a");
	int i,*dynamic_array,size,control,value;
	double time_spent1,time_spent2,time_spent3,time_spent4; 
	clock_t begin1,begin2,end500k1,end750k1,end1m1,end500k2,end750k2,end1m2,end_written1,end_written2;/*these are clock calculating variables*/
	
	size=size_text();
	
	dynamic_array=(int*)malloc(size*sizeof(int));/*this is memory allocation with using malloc function*/
	
	begin1=clock();
	for(i=0;i<size;i++){/*this loop doing program with using dynamic array method*/
		dynamic_array[i]=read_text(&*fl);
		control=prime_number(dynamic_array[i]);
		if(control==1){
			printf("%d\n",dynamic_array[i]);
			fprintf(fl2,"%d\n",dynamic_array[i]);
		}
		if(i==500000) end500k1=clock();
		if(i==750000) end750k1=clock();				
	}
	
	end1m1=clock();
	
	time_spent1 = (double)(end500k1-begin1)/CLOCKS_PER_SEC;
	time_spent2 = (double)(end750k1-begin1)/CLOCKS_PER_SEC;
	time_spent3 = (double)(end1m1-begin1)/CLOCKS_PER_SEC;
	
	fprintf(fl2,"\n\nRunning time between 1 and 500.000:%lf",time_spent1);
	fprintf(fl2,"\nRunning time between 1 and 750.000:%lf",time_spent2);
	fprintf(fl2,"\nRunning time between 1 and 1.000.000:%lf",time_spent3);
	end_written1=clock();
	
	time_spent4=(double)(end_written1-begin1)/CLOCKS_PER_SEC;
	fprintf(fl2,"\nRunning time to write to the file:%lf",time_spent4);
	
	
	fclose(fl);
	fl=fopen("data.txt","r");
	fl3=fopen("output_prime_LiknedList.txt","a");
	printf("\nNow, turn of linked list prime number finding.\n");
	
	begin2=clock();
	
	for(i=0;i<size;i++){/*this loop doing program with using linked list method*/
		value=read_text(&*fl);
		add_list(value);
		control=prime_number(value);
		if(control==1){
			printf("%d\n",value);
			fprintf(fl3,"%d\n",value);
		}
		if(i==500000) end500k2=clock();
		if(i==750000) end750k2=clock();
	}
	
	end1m2=clock();
	
	time_spent1 = (double)(end500k2-begin2)/CLOCKS_PER_SEC;
	time_spent2 = (double)(end750k2-begin2)/CLOCKS_PER_SEC;
	time_spent3 = (double)(end1m2-begin2)/CLOCKS_PER_SEC;
	
	fprintf(fl3,"\n\nRunning time between 1 and 500.000:%lf",time_spent1);
	fprintf(fl3,"\nRunning time between 1 and 750.000:%lf",time_spent2);
	fprintf(fl3,"\nRunning time between 1 and 1.000.000:%lf",time_spent3);
	end_written2=clock();
	
	time_spent4=(double)(end_written2-begin2)/CLOCKS_PER_SEC;
	fprintf(fl3,"\nRunning time to write to the file:%lf",time_spent4);
	
	fclose(fl);
	fclose(fl2);
	fclose(fl3);
}

void add_list(int value){/*this function add value to linked list*/ 
	
	temp=(l1*) malloc(sizeof(l1));	
	
	temp->data=value;
	temp->next=NULL;
	
	if(first==NULL){
		first=temp;
		last=first;
	}
	
	else{
		last->next=temp;
		last=last->next;
	}
}

int size_text(){/*this calculates line count of given text*/
	FILE *fl;
	fl=fopen("data.txt","r");
	int i,size=0;
	char control,value[50];
	do{
		size++;
		control=fscanf(fl,"%s",value);
	}while(control != EOF);
	size--;
	fclose(fl);	
	
	return size;
}

int prime_number(int number){/*this finds given number's prime situation, if number is prime function returns 1, else return 0*/
	
	int i,k=0,prime=1,result;
	
	if(number==1) return 0;	
	
	else{
	
		while(k==0){
			for(i=2;i<=number/2;i++){
				result=number%i;
				if(result==0){
					return 0;
					prime=0;
					k++;
				}
			}
			k++;
		}
	}
	
	if(prime==1) return 1;
	else return 0;
}	
