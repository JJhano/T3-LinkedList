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

void appendList(nodo **l, nodo *q);
void addPrevVal(nodo *l);
void insertList(nodo **l, nodo *q);
void insertListONE(nodo **l, nodo *q);

int main(int argc, char **argv){
    if(argc != 3){
        printf("Execute as ./main <n> <seed> \n");
        return EXIT_FAILURE;
    }
	int n = atoi(argv[1]);
	int seed = atoi(argv[2]);
	srand(seed);

	nodo *L = NULL;
	nodo *Q = NULL;
	// for(int i = 0; i < n; i++) appendToListR(&L, rand()%50);
	for(int i = 0; i < n; i++) appendToListR(&Q, rand()%50);
	printf("LISTA L:\n");
	// printList(L);
	// addPrevVal(L);
	printList(L);

	printf("LISTA Q:\n");

	// printList(Q);
	addPrevVal(Q);
	printList(Q);

	printf("LISTA L fusionada con Q:\n");
	// insertListONE(&L, Q);
	insertList(&L, Q);
	printList(L);
	// printf("LISTA Q sin modificaciones:\n");
	// printList(Q);
	return EXIT_SUCCESS;
}

void addPrevVal(nodo *l){
    nodo *p = l;
    while(p->next != nullptr){
        p->next->val += p->val;
        p = p->next;
    }
}

void insertList(nodo **l, nodo *q){
	nodo **p = l;
	if(q == nullptr) return;
	if(p == nullptr){
		*p = q;
		return;
	}
	nodo *r = q; //mantener apuntando a q
	while(r  != nullptr){
		nodo *nuevo = new nodo;
		nuevo->val = r->val; //para no perder la lista q
		nuevo->next = NULL;
		while(*p != nullptr && (*p)->val < r->val){
			p = &((*p)->next);
		}
		nuevo->next = *p;
		*p = nuevo;

		r = r->next;
	}

}

void insertListONE(nodo **l, nodo *q) {
    nodo **p = l;
	if(q == nullptr) return;
	if(p == nullptr){
		*p = q;
		return;
	}
    while (q != nullptr) {
        nodo *nuevo = q;
        q = q->next;
        nuevo->next = NULL;
        // Insertar el nuevo nodo en la lista l
        while (*p != nullptr && (*p)->val < nuevo->val) {
            p = &((*p)->next);
        }
        nuevo->next = *p;
        *p = nuevo;
    }
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


// Costo lineal : O(n)
int minList(nodo *l){
	if (l == nullptr){
		printf("Lista Vacía !! ");
		return -1;
	}
	int min = l->val;
	while(l!=nullptr){
		if (l->val < min)
			min = l->val;
		l = l->next;
	}
	return min;
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