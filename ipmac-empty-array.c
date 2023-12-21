
#include <stdio.h>
#include <stdlib.h>

int countOperations(int *A, int *B, int n, int rotation) {
  int opCount =
      rotation; // Number of operations is initially the number of rotations
  int indexA = rotation;     // Starting index for A after rotation
  int indexB = 0;            // Starting index for B
  int remainingElements = n; // Remaining elements to be deleted

  while (remainingElements > 0 && indexB < n) {
    if (A[indexA] == B[indexB]) {
      // Delete the matching elements
      indexA = (indexA + 1) % n;
      indexB++;
      remainingElements--;
    } else {
      // Rotate A if no match
      indexA = (indexA + 1) % n;
      opCount++;
    }
  }

  return opCount;
}

int main() {
  int n;
  scanf("%d", &n);

  int *A = malloc(n * sizeof(int));
  int *B = malloc(n * sizeof(int));

  for (int i = 0; i < n; i++) {
    scanf("%d", &A[i]);
  }

  for (int i = 0; i < n; i++) {
    scanf("%d", &B[i]);
  }

  int minOperations = n * 2; // Max possible operations

  for (int rotation = 0; rotation < n; rotation++) {
    int operations = countOperations(A, B, n, rotation);
    if (operations < minOperations) {
      minOperations = operations;
    }
  }

  printf("%d\n", minOperations);

  free(A);
  free(B);
  return 0;
}
