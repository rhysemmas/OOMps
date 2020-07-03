#include <iostream>
#include <cstdlib>
#include <cstring>

// This is an example of a program which leaks memory (defined in chunk size)
// continuously until a memory allocation fails (machine is out of RAM).
// Unfortunately any modern *nix system renders this a bit useless, as memory
// overcommit will almost always be enabled, meaning `malloc` never sees a
// NULL pointer. The OOMKiller will kick in at some point and terminate the
// process, meaning we will never be able to handle a bad allocation.

#define CHUNK_SIZE 4096

using namespace std;

int main()
{
  char* cptr_mblock;
  // loop forever
  while (true)
  {
    // allocate memory
    cptr_mblock = (char*)malloc(CHUNK_SIZE);

    // test allocation
    if (cptr_mblock == nullptr)
    {
      // allocation failed
      cout << "Oh dear" << endl;
    }
    else
    {
      // memory allocated, set memory chunk to zero's
      cout << "Allocated block" << endl;
      memset(cptr_mblock, 0, CHUNK_SIZE);
    }
  }
}

// A more idiomatic C++ snippet with try/catch and using `new`.
// `new` will throw a `bad_alloc` exception when memory allocation fails

//  int* x
//  try
//  {
//    x = new int[1073741824]; // 2 * 1073741824 bytes
//  }
//  catch (std::bad_alloc& ba)
//  {
//    delete x;
//    std::cerr << "bad_alloc caught: " << ba.what() << std::endl;
//  }
