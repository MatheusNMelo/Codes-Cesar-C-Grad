//-------------------------------------------------------------------------------

//-- Estrutura ELEMENTO 

//- int valor          : armazena um valor de um tipo qualquer no caso desse exemplo é do tipo (int) 
//- ELEMENTO *proximo  : é um ponteiro que aponta para uma estrutura do tipo ELEMENTO que mostra o proximo ELEMENTO da FILA;


//-- Estrutura FILA

//- ELEMENTO *primeiro : é um ponteiro que aponta para o primeiro ELEMENTO de uma FILA
//- int tamanho        : indica quantos ELEMENTOS tem na FILA


//--------------------------------------------------------------------------------

//--- FIFO : First In First Out 

//--------------------------------------------------------------------------------

//- FUNÇÕES BASICAS


//--- FILA *criarFila()      

//- Essa é a primeira função que deve ser executada ela serve para inicializar uma nova lista 
//- Ela não recebe parametros de entrada mas ela retorna um ponteiro do tipo FILA


//--- void addFim(FILA *aFila, int num)

//- Adiciona um numero do tipo (int) no fim da fila


//--- printFila(FILA *aFila)      

//- Função para visualizar todos os itens dentro de uma fila


//--- rmvPrimeiro(FILA *aFila)    

// Remove o primeiro elemento da fila


//--- excluirFila(FILA *aFila)

//- exclui todos os elementos de uma fila


//--- buscar(FILA *aFila, int num)   

//- Busca um determinado numero na fila e exclui ele


//----------------------------------------------------------------------------------


#include <stdio.h>
#include <stdlib.h>


struct ELEMENTO
{
	int valor;
	struct ELEMENTO *proximo;
};

struct FILA 
{
	struct ELEMENTO *primeiro;
	int tamanho;

};


struct FILA *criarFila()
{
	struct FILA *aFila;
	aFila = (struct FILA*)malloc(sizeof(aFila));

	aFila -> tamanho = 0;
	aFila -> primeiro = NULL;

	return aFila;
}


void addFim(struct FILA *aFila, int num)
{
	struct ELEMENTO *anterior,*novo;
	int tamanho = aFila -> tamanho;

	novo = (struct ELEMENTO*)malloc(sizeof(novo));

	if(aFila-> tamanho == 0){
		
		novo -> valor = num;
		novo -> proximo = NULL;
		aFila -> primeiro = novo;
		aFila -> tamanho = 1;

		printf("%d foi adicionado no fim da fila\n", novo -> valor);

	}

	else{
		anterior = aFila -> primeiro;
		
		for(int i = 0; i < aFila -> tamanho - 1 ; i++)
			anterior = anterior -> proximo;
	
		novo -> valor = num;
		novo -> proximo = NULL;
		
		anterior -> proximo = novo; 	
		aFila -> tamanho = tamanho + 1;
		
		printf("%d foi adicionado no fim da fila\n", novo -> valor);

	}
}


void rmvPrimeiro(struct FILA *aFila){
	struct ELEMENTO *primeiro,*proximo;

	primeiro = aFila -> primeiro;
	proximo = primeiro -> proximo;

	free(primeiro);

	aFila -> primeiro = proximo;
	aFila -> tamanho -= 1;

	printf("O primeiro da fila foi removido \n");

}


void printFila(struct FILA *aFila)
{
	struct ELEMENTO *aux;
	int tamanho = aFila -> tamanho;
	int valor;

	aux = aFila -> primeiro;
	
	printf("Print da fila: " );
	
	for(int i= 0; i < tamanho; i++){
		valor = aux -> valor;
		printf("%d ",valor);
		aux = aux -> proximo;
	}

	putchar('\n');

}


void buscar(struct FILA *aFila,int num)
{
	struct ELEMENTO *atual,*proximo,*aux;
	int rmv = 0;

	atual = aFila -> primeiro;
	proximo = atual -> proximo;

	for(int i = 0; i < aFila -> tamanho -1; i++){
		if (atual -> valor == num){
			free(atual);
			
			aFila -> primeiro = proximo;
			aFila -> tamanho -= 1;

			rmv = 1;
			break;
		}
		
		else if(proximo -> valor == num){
			aux = proximo;
			proximo = proximo -> proximo;
			
			free(aux);

			atual -> proximo = proximo;
			aFila -> tamanho -= 1;

			rmv = 1;
			break;
		}
		
		else{
			atual = proximo;
			proximo = proximo -> proximo;
		}
	}
	
	if(rmv != 0)
		printf("%d foi removido \n",num);
	else
		printf("%d não foi encontrado \n",num);	
}

void excluirFila(struct FILA *aFila)
{
	struct ELEMENTO *atual,*proximo;

	atual = aFila -> primeiro;
	proximo = atual -> proximo;

	for(int i = 0; i < aFila -> tamanho -1; i++){	
		free(atual);
		atual = proximo;
		proximo = proximo -> proximo;
	}

	free(aFila);
	
	printf("A lista foi excluida \n");

}


int main()
{
	struct FILA *f1;
	f1 = criarFila();

	addFim(f1,100);
	addFim(f1,200);
	addFim(f1,300);
	addFim(f1,400);
	addFim(f1,500);
	addFim(f1,600);

	putchar('\n');

	printFila(f1);
	rmvPrimeiro(f1);

	putchar('\n');
	
	printFila(f1);
	buscar(f1,200);

	putchar('\n');
	
	printFila(f1);
	buscar(f1,700);

	putchar('\n');
	
	excluirFila(f1);
	printFila(f1);

	return 0;
}
