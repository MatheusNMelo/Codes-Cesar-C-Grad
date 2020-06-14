#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

int insertion_sort(char nome[],int size);
int selection_sort(char nome[],int size);
int bubble_sort(char nome[],int size);
int merge_sort(char nome[],int size);
void mergeSort(int list[], int a, int b);
void merge(int list[], int p, int q, int r);
void pilhar(int list[], int size, int i);
void heap_sort(char nome[],int size);

int main()
{
        int x,y,size;
        char *nomes[7];
        nomes[0]="1000.txt";
        nomes[1]="5000.txt";
        nomes[2]="10000.txt";
        nomes[3]="20000.txt";
        nomes[4]="50000.txt";
        nomes[5]="75000.txt";
        nomes[6]="100000.txt";
        printf("1-Insertion_Sort\n2-Selection_Sort\n3-Bubble_Sort\n4-Heap_Sort\n5-Merge_Sort\n6- Em breve\n");
        scanf("%d",&x);
        if (x > 0 && x <= 7){
                printf("1-1k\n2-5k\n3-10k\n4-20k\n5-50k\n6-75k\n7-100k\n");
                scanf("%d",&y);
                size = atoi(nomes[y-1]);
        }
        switch (x){
                case 1:
                        insertion_sort(nomes[y-1],size);
                        break;
                case 2:
                        selection_sort(nomes[y-1],size);
                        break;
                case 3: 
                        bubble_sort(nomes[y-1],size);
                        break;
                case 4:
                        heap_sort(nomes[y-1],size);
                        break;
                case 5:
                        merge_sort(nomes[y-1],size);
                        break;
                default:
                        printf("Opcao invalida, ou nao criada\n");
        }
        return 0;
}
int insertion_sort(char nome[],int size)
{
        int pos=0,list[size],i=0,l=0;
        char c,num[6];
        FILE *arq = fopen(nome,"r");
        for (c = getc(arq); c != EOF;){
                if (c == '\t'){
                        list[i] = atoi(num);
                        pos=0;
                        i++;
                        for(l = 0; l < 6; l++){
                                num[l]='l';
                        }
                }else if(c == '\n'){
                        list[i] = atoi(num);
                        pos=0;
                        i++;
                        for(l = 0; l < 6; l++){
                                num[l]='l';
                        }
                }else{
                        num[pos] = c;
                        pos++;
                }
                c = getc(arq);
                if(c == EOF){
                        list[i] = atoi(num);
                }
        }
        fclose(arq);

        clock_t tempo;
        int a,key;
        tempo = clock();
        for (int j = 1; j<size; j++){
                key=list[j];
                a=j-1;
                while (a>0 && list[a]>key){
                        list[a+1]=list[a];
                        a--;
                }
                list[a + 1]=key;
        }
        printf("Insertion Time:%f",(clock() - tempo) / (double)CLOCKS_PER_SEC);
        return 0;
}
int selection_sort(char nome[],int size)
{
        int pos=0,list[size],i=0,l=0;
        char c,num[6];
        FILE *arq = fopen(nome,"r");
        for (c = getc(arq); c != EOF;){
                if (c == '\t'){
                        list[i] = atoi(num);
                        pos=0;
                        i++;
                        for(l = 0; l < 6; l++){
                                num[l]='l';
                        }
                }else if(c == '\n'){
                        list[i] = atoi(num);
                        pos=0;
                        i++;
                        for(l = 0; l < 6; l++){
                                num[l]='l';
                        }
                }else{
                        num[pos] = c;
                        pos++;
                }
                c = getc(arq);
                if(c == EOF){
                        list[i] = atoi(num);
                }
        }       
        fclose(arq);

        clock_t tempo;
        tempo = clock();
        int min,aux;
        for(int a=0; a<(size-1); a++){
                min = a;
                for(int b = a+1; b < size; b++)
                        if(list[b] < list[min])
                                min=b;                
                aux = list[min];
                list[min]=list[a];
                list[a]=aux; 
        }
        printf("Selection time:%f",(clock() - tempo) / (double)CLOCKS_PER_SEC);
        return 0;
}
int bubble_sort(char nome[],int size)
{
        int pos=0,list[size],i=0,l=0;
        char c,num[6];
        FILE *arq = fopen(nome,"r");
        for (c = getc(arq); c != EOF;){
                if (c == '\t'){
                        list[i] = atoi(num);
                        pos=0;
                        i++;
                        for(l = 0; l < 6; l++){
                                num[l]='l';
                        }
                }else if(c == '\n'){
                        list[i] = atoi(num);
                        pos=0;
                        i++;
                        for(l = 0; l < 6; l++){
                                num[l]='l';
                        }
                }else{
                        num[pos] = c;
                        pos++;
                }
                c = getc(arq);
                if(c == EOF){
                        list[i] = atoi(num);
                }
        }
        fclose(arq);

        clock_t tempo;
        tempo = clock();
        for (int curr = 0; curr < size - 1; curr++){
                for(int a = 0; a < (size - curr - 1); a++){
                        if (list[a] > list[a + 1]){
                                int aux = list[a];
                                list[a] = list[a + 1];
                                list[a + 1] = aux; 
                        }
                }
        }
        printf("Bubble time:%f",(clock() - tempo) / (double)CLOCKS_PER_SEC);
        return 0;
}

void pilhar(int list[], int size, int i) 
{
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < size && list[left] > list[largest])
                largest = left;
        if (right < size && list[right] > list[largest])
                largest = right;
        if (largest != i) {
                int aux = list[i];
                list[i]=list[largest];
                list[largest]=aux;
        pilhar(list, size, largest);
        }
}

void heap_sort(char nome[],int size) 
{
        int pos=0,list[size],i=0,l=0;
        char c,num[6];
        FILE *arq = fopen(nome,"r");
        for (c = getc(arq); c != EOF;){
                if (c == '\t'){
                        list[i] = atoi(num);
                        pos=0;
                        i++;
                        for(l = 0; l < 6; l++){
                                num[l]='l';
                        }
                }else if(c == '\n'){
                        list[i] = atoi(num);
                        pos=0;
                        i++;
                        for(l = 0; l < 6; l++){
                                num[l]='l';
                        }
                }else{
                        num[pos] = c;
                        pos++;
                }
                c = getc(arq);
                if(c == EOF){
                        list[i] = atoi(num);
                }
        }       
        fclose(arq);

        clock_t tempo;
        tempo = clock();
        for (int i = size / 2 - 1; i >= 0; i--)
                pilhar(list, size, i);
        for (int j = size - 1; j >= 0; j--) {
                int aux = list[0];
                list[0]=list[j];
                list[j]=aux;
                pilhar(list, j, 0);
        }
        printf("Heap time: %.4f",(clock() - tempo) / (double)CLOCKS_PER_SEC);
}
void merge(int list[], int p, int q, int r) 
{  
        int n1 = q - p + 1;
        int n2 = r - q;
        int L[n1], M[n2];
        for (int i = 0; i < n1; i++)
                L[i] = list[p + i];
        for (int j = 0; j < n2; j++)
                M[j] = list[q + 1 + j];
        int i, j, k;
        i = 0;
        j = 0;
        k = p;
        while (i < n1 && j < n2) {
                if (L[i] <= M[j]) {
                        list[k] = L[i];
                        i++;
                } else {
                        list[k] = M[j];
                        j++;
                }
                k++;
        }
        while (i < n1) {
                list[k] = L[i];
                i++;
                k++;
        }
        while (j < n2) {
                list[k] = M[j];
                j++;
                k++;
        }
}

int merge_sort(char nome[],int size) 
{       
        int pos=0,list[size],i=0,l=0;
        char c,num[6];
        FILE *arq = fopen(nome,"r");
        for (c = getc(arq); c != EOF;){
                if (c == '\t'){
                        list[i] = atoi(num);
                        pos=0;
                        i++;
                        for(l = 0; l < 6; l++){
                                num[l]='l';
                        }
                }else if(c == '\n'){
                        list[i] = atoi(num);
                        pos=0;
                        i++;
                        for(l = 0; l < 6; l++){
                                num[l]='l';
                        }
                }else{
                        num[pos] = c;
                        pos++;
                }
                c = getc(arq);
                if(c == EOF){
                        list[i] = atoi(num);
                }
        }       
        fclose(arq);
        clock_t tempo;
        tempo = clock();
        mergeSort(list,0,size-1);
        printf("Merge time: %.4f",(clock() - tempo) / (double)CLOCKS_PER_SEC);
}
void mergeSort(int list[], int a, int b)
{
        if (a < b) {
                int m = a + (b - a) / 2;
                mergeSort(list, a, m);
                mergeSort(list, m + 1, b);
                merge(list, a, m, b);
        }
}
