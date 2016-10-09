#include<stdio.h>
#include<stdlib.h>
typedef struct linknode{
	char data;
	struct linknode *next;
}linkstring;
linkstring* create(){
	linkstring *head,*s,*r;
	head=(linkstring*)malloc(sizeof(linkstring));
	r=head;
	char ch;
	while((ch=getche())!='#'){
		s=(linkstring*)malloc(sizeof(linkstring));
		s->data=ch;
		r->next=s;
		r=s;
	}
	r->next=NULL;
	return head;
}
void output(linkstring *head){
	linkstring *s;
	s=head->next;
	while(s!=NULL){
		printf("%c",s->data);
		s=s->next;
	}
}
void replace(linkstring *head,char ch){
	linkstring *s,*newhead;
	newhead=(linkstring*)malloc(sizeof(linkstring));
	s=head->next;
	newhead->next=s;
	while(s!=NULL){
		if(s->data==ch){
			s->data='s';
			s=s->next;
		}
		else{
			s=s->next;
		}
	}
	 output(newhead);
}
void main(){
	linkstring *str,*head;
	printf("输入字符串，#结尾\n");
	str=create();
	head=str;
	printf("将c替换成s后:\n");
	char c='c';
	replace(head,c);
}