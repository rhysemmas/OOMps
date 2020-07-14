#include <iostream>
#include <cstdlib>
#include <cstring>

#define CHUNK_SIZE 4096
#define NUM_CHUNKS 26214400 // 100gb
//#define NUM_CHUNKS 524288 // 2gb

// CHUNK_SIZE * NUM_CHUNKS = memory usage (bytes)
// e.g: 4096 * 29884416 = 122406567936 bytes (114GB)
// array of pointers will use NUM_CHUNKS * 8 bytes (64 bit)
// 2gb memory usage with 4k blocks = 4mb of memory usage for array of pointers

using namespace std;

int main()
{
  int n = NUM_CHUNKS;
  // allocate on the heap - very large arrays will not fit on the stack
  // the line commented out below will be ok for the 2gb example
  //void * ptr[NUM_CHUNKS];
  void **ptr = new void*[NUM_CHUNKS];

  for (int i = 0; i < n; i++)
  {
    ptr[i] = malloc(CHUNK_SIZE);
    // malloc returns a pointer to the start of a the block
    cout << "Start of block: " << ptr[i] << endl;
    if (ptr[i] == nullptr)
    {
      // allocation failed, we will probably get OOMed before ever seeing this
      cout << "Oh dear" << endl;
    }
    else
    {
      // memory allocated, set memory chunk to zeros
      cout << "Initialising allocated block" << endl;
      memset(ptr, 0, CHUNK_SIZE);

      if (i == n - 1)
      {
        cout << "Memory allocation complete" << endl;
        while (true) {}; //infinite loop
      }
    }
  }
}
