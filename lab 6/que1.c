#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int item_id;
  float item_profit;
  float item_weight;
  float profit_weight_ratio;
} ITEM;

void heapify(ITEM *items, int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && items[left].profit_weight_ratio > items[largest].profit_weight_ratio) {
    largest = left;
  }

  if (right < n && items[right].profit_weight_ratio > items[largest].profit_weight_ratio) {
    largest = right;
  }

  if (largest != i) {
    swap(items[i], items[largest]);
    // ITEM temp = items[i];
    // items[i] = items[largest];
    // items[largest] = temp;
    heapify(items, n, largest);
  }
}

void build_max_heap(ITEM *items, int n) {
  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(items, n, i);
  }
}

void heapsort(ITEM *items, int n) {
  build_max_heap(items, n);

  for (int i = n - 1; i >= 0; i--) {
    ITEM temp = items[0];
    items[0] = items[i];
    items[i] = temp;

    heapify(items, i, 0);
  }
}

float fractional_knapsack(ITEM *items, int n, float capacity) {
  float profit = 0.0;
  float weight = 0.0;

  for (int i = 0; i < n; i++) {
    if (weight + items[i].item_weight <= capacity) {
      profit += items[i].item_profit;
      weight += items[i].item_weight;
    } else {
      float fraction = (capacity - weight) / items[i].item_weight;
      profit += fraction * items[i].item_profit;
      weight = capacity;
      break;
    }
  }

  return profit;
}

int main() {
  int n;
  float capacity;

  printf("Enter the number of items: ");
  scanf("%d", &n);

  ITEM *items = malloc(sizeof(ITEM) * n);

  for (int i = 0; i < n; i++) {
    printf("Enter the profit and weight of item no %d: ", i + 1);
    scanf("%f %f", &items[i].item_profit, &items[i].item_weight);

    items[i].item_id = i + 1;
    items[i].profit_weight_ratio = items[i].item_profit / items[i].item_weight;
  }

  printf("Enter the capacity of knapsack: ");
  scanf("%f", &capacity);

  heapsort(items, n);

  float profit = fractional_knapsack(items, n, capacity);

  printf("\nItem No profit Weight Amount to be taken\n");
  for (int i = 0; i < n; i++) {
    printf("%d %f %f %f\n", items[i].item_id, items[i].item_profit, items[i].item_weight, items[i].item_weight);
  }

  printf("\nMaximum profit: %f\n", profit);

  free(items);

  return 0;
}

void swap(int n, int m){
    n=n+m;
    m=n-m;
    n=n-m;

}