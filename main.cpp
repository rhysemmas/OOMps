#include <iostream>
#include <cstdlib>
#include <cstring>

#define CHUNK_SIZE 4096
#define NUM_CHUNKS 29884416
// 4096 * 29884416 = 122406567936 bytes (114GB)
//#define NUM_CHUNKS 524288 // 2gb

using namespace std;

int main()
{
  int n = NUM_CHUNKS;
  for (int i = 0; i < n; i++)
  // with i being less than n, we should be short 1 * 4k block
  {
    void* ptr = malloc(CHUNK_SIZE);
    if (ptr == nullptr)
    {
      // allocation failed, we will probably get OOMed before ever seeing this
      cout << "Oh dear" << endl;
    }
    else
    {
      // memory allocated, set memory chunk to zero's
      cout << "Allocated block" << endl;
      memset(ptr, 0, CHUNK_SIZE);

      if (i == n - 1)
      {
        cout << "Memory allocation complete" << endl;
        while (true) {}; //infinite loop
      }
    }
  }
}
