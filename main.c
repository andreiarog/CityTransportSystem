#include <stdlib.h>
#include <stdio.h>
#define NIL -1
#define FALSE 0
#define TRUE 1
#define WHITE 5
#define GREY 10
#define BLACK 15



/*******************************************************************************
*                         GRAPH Abstract Data Type                             *
*******************************************************************************/


typedef struct {
    
	int v;
    
	int w;
} 
Edge;



typedef struct node *link;



struct node {
    
	int v;
    
	link next;};



struct graph {
    
	int V;
    
	int E;
    
	link *adj;

};



typedef struct graph *Graph;



Edge newEDGE(int v, int w) {
    
	Edge e;
    
	e.v = v;
    
	e.w = w;
    
	return e;
}



link newLINK(int v, link next) {
    
	link x = malloc(sizeof(*x));
    
	x -> v = v;
   
	x -> next = next;
    
	return x;
}



/* Initialization of the graph.
Memory allocation and NULL initialization of V vertices.
Operation complexity: O(V) */




Graph GRAPHinit(int V) {

    int v;

    Graph G = malloc(sizeof(*G));

    G -> V = V;

    G -> E = 0;

    G -> adj = malloc(V*sizeof(link));

    for (v = 0; v < V; v++) { /* Complexity O(V) */

        G->adj[v] = NULL;

    }
    return G;

}




/* Insert an edge: O(1)*/

void GRAPHinsertE(Graph G, Edge e) {

    int v = (e.v), w = (e.w);

    G -> adj[v] = newLINK(w, G -> adj[v]);

    G -> E++;
}









/*******************************************************************************
*                   DFS                                                        *
*******************************************************************************/

int sem_filhos=0;
/*int* f;*/
int* mark;
int* p;
int* tab;
int* a;
int output=0;

/*


void dfs_p (Graph G, int u) {

    
printf("%d ", u+1);

    link t=G->adj[u];

    if (t != NULL) { 
 
        dfs_p(G, t->v);

    }            
}




*/

void mesmo_pai (Graph G) {
	int i;
	int j;
	for (j=0; j<G->V; j++){
		for (i=0; i<G->V; i++){
			if (p[j]== p[i]) 
				a[p[j]]=a[p[j]]+1;
			if (a[p[j]] > 1)
				output=1;
		}
		
	}		
}

void sem_pai (Graph G) {
	int i;
	int a=0;
	for (i=0; i<G->V; i++){
		if (p[i]== -1) 
			a=a+1;
	}
	if (a>1)
		output=1;
}

void PRINT (Graph G) {
	static int j=-1;
	int i;
	for (i=0; i<G->V; i++){
		if (p[i]== j) {
			printf("%d ", i+1);
			j= i;
			PRINT (G);
		}

	}
}



/*void save (int a) {
    static int i=0;
    tab[i]= a+1;
    i=i+1;
}*/
/*void GRAPHprint(Graph J) {
    int i;
    link t;
    for (i=0; i<(J->V); i++) 
    {
        printf("%d : ", i);
        for (t = J->adj[i]; t != NULL; t = t -> next)
        	printf(" %d ", t->v); 
        printf("\n");
    }
}*/

/*void tabprint (){
	int i = 0;
	while(tab[i] != 0) {
		printf("%d ", tab[i]);
		i=i+1;

	}
	printf("\n");}*/





void dfs_visit(Graph G, int u)
{

    link t=G->adj[u];

    mark[u] = GREY ;

    
    for ( ; t != NULL ; t=t->next){

        if (mark[t->v] == GREY){   
            return;
        if (mark[t->v] == WHITE) {    
 
            dfs_visit(G, t->v);

             p[t->v]=u;

        }

        if (mark[t->v] == BLACK) {

        if (mark[p[t->v]] == BLACK){
}

            else
 
        	p[t->v]=u;

        }

    }


    mark[u] = BLACK;

}




void dfs(Graph G)
{

    int u;

    for (u = 0; u < G->V; u++) {

      	mark[u] = WHITE;

      	p[u]=-1;

    }

    for (u = 0; u < G->V; u++) {

        if (mark[u] == WHITE){

            dfs_visit(G, u);

            if (output==2){

            	return;

            }

        }

    }

}






void GRAPHorder (Graph G) {
    if (G->V > (G->E +1)) {
        output=1;
    }
    if (sem_filhos >1){
       	output=1;
    }
    sem_pai (G);
    mesmo_pai (G);
    dfs (G);
    if (output == 1) 
        printf("Insuficiente\n");
    else if (output==2) 
        printf("Incoerente\n");
    else if (output==0){
        PRINT(G);
        printf("\n");
    }
}





/*******************************************************************************
*                                Main function                                 *
*******************************************************************************/

int main() {

     /* We declare an int v to store the number of people in the network (vertices)
    and reutilize to save one vertex of the edge, int u to store the other vertex
    of the edge and an int e to the number of connections between people (edges)*/

    int v, e, u; /*v = N; e = L*/

    /* First we read from stdin the number of vertices and edges to initialize the
    graf */
    
    scanf("%d %d", &v, &e);

    Graph album = GRAPHinit(v);

    mark= malloc(v*sizeof(int));

    tab = calloc(v, v*sizeof(int));

    p = malloc(v*sizeof(int));

    a = calloc(v, v*sizeof(int));

   /* We proceed to read all the connections from the input */

    for (; e>0; e--) {

        scanf("%d %d", &u, &v);

        Edge edge = newEDGE(u-1, v-1);

        GRAPHinsertE(album, edge);}
    
/* The graph order funtion analyses the chronological order of a set of photographs*/

    GRAPHorder(album);
	    return 0;
}