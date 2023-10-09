#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char alphabet;
  int frequency;
} SYMBOL;

struct Node {
  SYMBOL symbol;
  struct Node *left;
  struct Node *right;
};

void swap(SYMBOL *a, SYMBOL *b) {
  SYMBOL temp = *a;
  *a = *b;
  *b = temp;
}

int partition(SYMBOL *symbols, int low, int high) {
  SYMBOL pivot = symbols[high];
  int i = low - 1;
  for (int j = low; j < high; j++) {
    if (symbols[j].frequency <= pivot.frequency) {
      i++;
      swap(&symbols[i], &symbols[j]);
    }
  }
  swap(&symbols[i + 1], &symbols[high]);
  return i + 1;
}

void quicksort(SYMBOL *symbols, int low, int high) {
  if (low < high) {
    int pi = partition(symbols, low, high);
    quicksort(symbols, low, pi - 1);
    quicksort(symbols, pi + 1, high);
  }
}

struct Node *createNode(SYMBOL symbol) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->symbol = symbol;
  node->left = NULL;
  node->right = NULL;
  return node;
}

struct Node *constructHuffmanTree(SYMBOL *symbols, int size) {
  if (size == 1) {
    return createNode(symbols[0]);
  }

  quicksort(symbols, 0, size - 1);

  struct Node *left = constructHuffmanTree(symbols, size / 2);
  struct Node *right = constructHuffmanTree(symbols + size / 2, size - size / 2);

  struct Node *root = (struct Node *)malloc(sizeof(struct Node));
  root->symbol.alphabet = '$';
  root->symbol.frequency = left->symbol.frequency + right->symbol.frequency;
  root->left = left;
  root->right = right;

  return root;
}

void inOrderTraversal(struct Node *root) {
  if (root == NULL) {
    return;
  }

  inOrderTraversal(root->left);
  printf("%c ", root->symbol.alphabet);
  inOrderTraversal(root->right);
}

int main() {
  int size;
  printf("Enter the number of distinct alphabets: ");
  scanf("%d", &size);

  SYMBOL *symbols = (SYMBOL *)malloc(sizeof(SYMBOL) * size);

  printf("Enter the alphabets: ");
  for (int i = 0; i < size; i++) {
    scanf("%c", &symbols[i].alphabet);
  }

  printf("Enter its frequencies: ");
  for (int i = 0; i < size; i++) {
    scanf("%d", &symbols[i].frequency);
  }

  struct Node *root = constructHuffmanTree(symbols, size);

  printf("In-order traversal of the tree (Huffman): ");
  inOrderTraversal(root);

  return 0;
}
