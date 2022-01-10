#include <string.h>
#include <stdio.h>

int distributeCandies(int *candyType, int candyTypeSize)
{
  struct candy *root = NULL;
  int candyKey[200001], candyindex = 0;
  memset(candyKey, 0, sizeof(candyKey));
  for (int i = 0; i < candyTypeSize; i++)
  {
    if (candyKey[candyType[i] + 100000] != 1)
    {
      candyKey[candyType[i] + 100000] = 1;
      candyindex++;
    }
  }
  if (candyindex <= candyTypeSize / 2)
  {
    return candyindex;
  }
  else
  {
    return candyTypeSize / 2;
  }
}

int main()
{
  int arr[] = {1, 1, 2, 2, 3, 3};
  int ret = distributeCandies(arr, 6);
  printf("%d", ret);
  return 0;
}