#include "max_sub.hpp"
int left_index = 0, righ_index = 0;
int max(int a, int b) { return (a > b) ? a : b; }
int max_cross_sub(int A[MAX], int low, int mid, int high) {
  int sum = 0;
  int left_sum = INT_MIN;
  extern int left_index, righ_index;
  for (int i = mid; i >= low; i--) {
    sum += A[i];
    if (sum > left_sum) {
      left_sum = sum;
      left_index = i;
    }
  }
  int right_sum = INT_MIN;
  sum = 0;
  for (int j = mid + 1; j <= high; j++) {
    sum += A[j];
    if (sum > right_sum) {
      right_sum = sum;
      righ_index = j;
    }
  }
  return (right_sum + left_sum);
}
int find_max_sub(int A[MAX], int low, int high) {
  if (high <= low) {
    return A[low];
  }
  int mid = (low + high) / 2;
  int max_left_right =
      max(find_max_sub(A, low, mid), find_max_sub(A, mid + 1, high));
  return (max(max_cross_sub(A, low, mid, high), max_left_right));
}