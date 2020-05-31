#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

int insertion_sort(char nome[],int size);
int selection_sort(char nome[],int size);
int bubble_sort(char nome[],int size);

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
        printf("1-Insertion_Sort\n2-Selection_Sort\n3-Bubble_Sort\n4-7 Em breve\n");
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
                default:
                        printf("Opção inválida, ou não criada\n");
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
