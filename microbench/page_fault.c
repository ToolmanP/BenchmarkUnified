#include "microbench.h"

int main() {
  uint64_t before, after;
  char *page = mmap(NULL, 4096, PROT_READ | PROT_WRITE,
                        MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
  before = rdtsc();
  page[0] = 'A';  // Trigger a page fault
  after = rdtsc();
  printf("Page fault overhead from userspace: %lu cycles\n", after - before);
  return 0;
}
