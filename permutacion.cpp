#include <iostream>
#include <cstdlib>
using namespace std;

struct nodeList {
	int val;
	nodeList* next;
};
typedef struct nodeList nodo;

# define MAX 100

void appendToListL(nodo **l, int num);
void appendToListR(nodo **l, int num);
void insertInList(nodo **l, int num);
bool removeFromList(nodo **l, int num);
void printList(nodo *l);

bool existInList(nodo *l, int num);

void printDecrecientes(nodo *l);
void printCrecientes(nodo *l);
int main(int argc, char **argv){
    if(argc != 3){
        printf("Execute as ./permutacion <n> <seed> \n");
        return EXIT_FAILURE;
    }
	int n = atoi(argv[1]);
	int seed = atoi(argv[2]);
	srand(seed);

	nodo *L = NULL;
	for(int i = 0; i < n; i++) {
        int numero = 1 + (rand()%n);
        while(existInList(L, numero)) numero = 1 + (rand()%n);
        appendToListR(&L, numero);
    }
	printf("LISTA ORIGINAL L:\n");

	printList(L);

    printf("Sublistas Decrecientes\n");
    printDecrecientes(L);

    printf("Sublistas Crecientes\n");
    printCrecientes(L);
	return EXIT_SUCCESS;
}

bool existInList(nodo *l, int num){
    nodo *p = l;
    while (p != nullptr){
        if (p->val == num)
            return true;
        p = p->next;
    }
    return false;
}

void printDecrecientes(nodo *l){
    nodo *p = l;
    bool first = true;
    while(p->next != nullptr){
        if(p->val > p->next->val){
            if(first){
                printf("{%d,", p->val);
                first = false;
            }
            else printf("%d", p->val);
        }
        else if(first){
            printf("{%d}", p->val);
            first = true;
        }
        else{
            printf(",%d}", p->val);
            first = true;

        }
        p = p->next;
    } 
    if(p != nullptr && first) printf("{%d}", p->val);
    
    else if(p != nullptr) printf(",%d}", p->val);
    printf("\n");
    printf("\n");

}

void printCrecientes(nodo *l){
    nodo *p = l;
    bool first = true;
    while(p->next != nullptr){
        if(p->val < p->next->val){
            if(first){
                printf("{%d,", p->val);
                first = false;
            }
            else printf("%d", p->val);
        }
        else if(first){
            printf("{%d}", p->val);
            first = true;
        }
        else{
            printf(",%d}", p->val);
            first = true;

        }
        p = p->next;
    } 
    if(p != nullptr && first) printf("{%d}", p->val);
    
    else if(p != nullptr) printf(",%d}", p->val);
    printf("\n");
    printf("\n");
}

// aniade un nodo al inicio de la lista --> Costo Constante = O(1)
void appendToListL(nodo **l, int num){
	nodo *nuevo = new nodo;
	nuevo->val = num;
	nuevo->next = *l;
	*l = nuevo;
}

// aniade un nodo al final de la lista --> Costo lineal = O(n)
void appendToListR(nodo **l, int num){
	nodo *nuevo = new nodo;
	nuevo->val = num;
	nuevo->next = NULL;
	
	if (*l == nullptr){
		*l = nuevo;
		return;
	}
	
	nodo *p = *l;
	while(p->next != nullptr)
		p = p->next;
	p->next = nuevo;

}

// inserta el nodo en su posicion correcta (ascendente)
// Mi lista enlazada es *l y **l es la dirección de memoria de mi lista
// ASUME QUE LA LISTA ESTA ORDENADA CRECIENTEMENTE
void insertInList(nodo **l, int num){
	nodo *nuevo = new nodo;
	nuevo->val = num;
	nuevo->next = NULL;
	
	if (*l == nullptr){
		*l = nuevo;
		return;
	}
	
	nodo *p = *l;
	if(num <= p->val){
		nuevo->next = *l;
		*l = nuevo;
		return;
	}
	
	while(p->next != nullptr && p->next->val < num)
		p = p->next;
		
	if (p->next != nullptr)
		nuevo->next = p->next;
	p->next = nuevo;

}

// elimina el primer nodo de la lista con valor num que encuentra y retorna true
// (de izquierda a derecha). Si no lo encuentra retorna false


bool removeFromList(nodo **l, int num){
	if (*l == nullptr)
		return false;
	
	nodo *p = *l;
	if (p->val == num){
		*l = p->next;
		delete p;
		return true;
	}
	
	while (p->next != nullptr && p->next->val != num)
		p = p->next;
		
	if (p->next != nullptr){
		nodo *q = p->next; // q es el nodo a eliminar
		p->next = q->next;
		delete q;
		return true;
	}	
	
	return false;
}


void printList(nodo *l){
	nodo *p = l;
	//cout << "Lista :" << endl;
	while (p != nullptr){
		cout << p->val << " ";
		p = p->next;
	}
	printf("\n\n");
}