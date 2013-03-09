#include <stddef.h>
#include <stdlib.h>
typedef struct tree_node
{
	void * key;
	void *value;
	struct tree_node *left,*right,*parent;
}tree_node_t;

typedef struct tree_type{
	void *(*key_clone)(void *arg,void *key);
	void *(*value_clone)(void *arg,void *value);
	void (*value_destroy)(void *arg,void *value);
	void (*key_destroy)(void *arg,void *value);
	int (*key_cmp)(void *key1,void *key2);
	void *arg;
}tree_type_t;
typedef struct tree{
	tree_type_t * type;
	tree_node_t * root;
}tree_t;
int 
tree_init(tree_t *tree,tree_type_t * type)
{
	tree->root = NULL;
	tree->type = type;
	return 0;
}
int 
tree_insert(tree_t * tree,void *key,void *value)
{
	tree_node_t ** ppnode = &tree->root;
	tree_node_t *cut = NULL;
	while(*ppnode){
		cut = *ppnode;
		if(tree->type->key_cmp(cut->key,key) == 1){
			ppnode = &cut->left;
		}else if(tree->type->key_cmp(cut->key,key) == -1){
			ppnode = &cut->right;
		}else{
			return -1;
		}
	}
	*ppnode = malloc(sizeof(tree_node_t));
	(*ppnode)->left = NULL;
	(*ppnode)->right = NULL;
	(*ppnode)->parent = cut; 
	(*ppnode)->key = tree->type->key_clone(tree->type->arg,key);
	(*ppnode)->value = tree->type->value_clone(tree->type->arg,value);
	return 0;
}
int _tree_query_node(tree_t *tree,void *key,tree_node_t ***node){
	tree_node_t ** ppnode = &tree->root;
	tree_node_t *cut;
	while(*ppnode){
		cut = *ppnode;
		if(tree->type->key_cmp(cut->key, key)==1){
			ppnode = &cut->left;
		}else if(tree->type->key_cmp(cut->key, key)==-1){
			ppnode = &cut->right;
		}else{
			*node = ppnode;
			return 0;
		}
	}
	*node = NULL;
	return -1;
}
int tree_remove(tree_t * tree,void *key,void **value){
	tree_node_t **ppnode;
	if( _tree_query_node(tree,key,&ppnode) != 0){
		*value = NULL;
		return -1;
	}else{
		tree_node_t * delnode = *ppnode;
		*value = delnode->value;
		delnode->parent->left = delnode->right;
		tree_node_t * left = delnode->left;
		while(*ppnode){
			ppnode= & (*ppnode)->left;
		}
		*ppnode = left;
		free(delnode);
	}
	return 0;
}
int tree_query(tree_t *tree,void *key,void**value){
	tree_node_t **ppnode;
	if(_tree_query_node(tree,key,&ppnode) != 0){
		*value = NULL;
		return -1;
	}else{
		*value = tree->type->value_clone(tree->type->arg,(*ppnode)->value);
		return 0;
	}
}
