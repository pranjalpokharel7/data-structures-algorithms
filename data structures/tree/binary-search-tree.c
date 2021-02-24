#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *left, *right;
};
typedef struct node* nodeptr;

nodeptr create_new_node(int data){
  nodeptr new_node = (nodeptr)malloc(sizeof(struct node));
  new_node->data = data; 
  new_node->left = new_node->right = NULL;
  return new_node;
}

nodeptr insert_data(nodeptr tree, int data){
  if (tree == NULL)
    return create_new_node(data);

  if (data < tree->data)
    tree->left = insert_data(tree->left, data);
  else if (data > tree->data)
    tree->right = insert_data(tree->right, data);

  return tree;
}

nodeptr search_node(nodeptr tree, int data){
  if (tree->data == data || tree == NULL)
    return tree;
  if (data < tree->data)
    return search_node(tree->left, data);
  return search_node(tree->right, data);
}

nodeptr find_largest_node(nodeptr tree){
  if (tree == NULL || tree->right == NULL)
    return tree;
  return find_largest_node(tree->right);
}

nodeptr find_smallest_node(nodeptr tree){
  if (tree == NULL || tree->left == NULL)
    return tree;
  return find_smallest_node(tree->left);
}

nodeptr delete_node(nodeptr tree, int data){
  if (tree == NULL)
    return tree;

  if (data < tree->data)
    tree->left = delete_node(tree->left, data);
  else if (data > tree->data)
    tree->right = delete_node(tree->right, data);

  // if data == tree->data, this is the node to be deleted
  else {
    if (tree ->left == NULL){
      nodeptr temp = tree->right;
      free(tree);
      return temp;
    }
    else if (tree->right == NULL){
      nodeptr temp = tree->left; 
      free(tree);
      return temp;
    }

    if (tree->left && tree->right){
      nodeptr temp = find_largest_node(tree->left);
      tree->data = temp->data;
      delete_node(tree->left, temp->data);
    }
  }
  return tree;
}

void delete_tree(nodeptr tree){
  if (tree != NULL){
    delete_tree(tree->left);
    delete_tree(tree->right);
    free(tree);
  }
}

void pre_traversal(nodeptr tree){
  if (tree != NULL){
    printf("%d\n", tree->data);
    pre_traversal(tree->right);
    pre_traversal(tree->left);
  }
}

void post_traversal(nodeptr tree){
  if (tree != NULL){
    post_traversal(tree->left);
    post_traversal(tree->right);
    printf("%d\n", tree->data);
  }
}

void inorder_traversal(nodeptr tree){
  if (tree != NULL){
    inorder_traversal(tree->left);
    printf("%d\n", tree->data);
    inorder_traversal(tree->right);
  }
}

int main(){
  nodeptr tree, p, q;
  tree = create_new_node(5);
  insert_data(tree, 7);
  insert_data(tree, 6);
  insert_data(tree, 3);
  insert_data(tree, 8);
  inorder_traversal(tree);
  delete_node(tree, 6);
  inorder_traversal(tree);

  delete_tree(tree);
  return 0;
}
