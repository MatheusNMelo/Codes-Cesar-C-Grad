#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int leitura(char nome[]);
char *insertion_sort(char list[100000]);
int main()
{
        char list[100000];
        int x,y;
        char *nomes[7];
        nomes[0]="1000.txt";
        nomes[1]="5000.txt";
        nomes[2]="10000.txt";
        nomes[3]="20000.txt";
        nomes[4]="50000.txt";
        nomes[5]="75000.txt";
        nomes[6]="100000.txt";
        printf("1-Insertion_Sort\n2-Em breve\n");
        scanf("%d",&x);
        printf("1-1k\n2-5k\n3-10k\n4-20k\n5-50k\n6-75k\n7-100k\n");
        scanf("%d",&y);
        switch (x){
                case 1:
                        *list = leitura(nomes[y-1]);
                        insertion_sort(list);
                        break;
                default:
                        printf("Opção inválida, ou não criada");
        }
        return 0;
}
int leitura(char nome[])
{
        int pos=0,list[100000],i=0,l=0;
        char c,num[5];
        FILE *arq = fopen(nome,"r");
        for (c = getc(arq); c != EOF;){
                if (c == '\t' || c == '\n'){
                        list[i] = atoi(num);
                        pos=0;
                        i++;
                        for(l = 0; l < 5; l++){
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
        return(list);
}
char *insertion_sort(char list[100000])
{
        clock_t tempo;
        tempo = clock();
        int x,i;
        int tAM=20000;
        for (int j = 2; j <= tAM; j++){
                x = list[j];
                i = j - 1;
                while (i > 0 && list[i] > x){
                       list[i + 1] = list[i];
                       i = i -1;
                }
                list[i + 1] = x;
        }
        printf("Tempo:%f",(clock() - tempo) / (double)CLOCKS_PER_SEC);
        return 0;
}