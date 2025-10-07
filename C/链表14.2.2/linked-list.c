#include <stdio.h>
#include "node.h"
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Node *head=NULL;
	int number;
	do{
		scanf("%d", &number);
		if(number!=-1){
			//add to link-list
			Node*p = (Node*)malloc(sizeof(Node));
			p->value=number;
			p->next=NULL;
			//find the last
			Node *last = head;
			if(last){
			while(last->next){
				last=last->next;
			}
			//attch		
			last->next=p;
		}else{
			head=p;
		}
	}
	}while(number!=-1);
	
	return 0;
}
