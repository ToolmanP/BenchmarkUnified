#include "microbench.h"

int main() {
  uint64_t before, after;
  before = rdtsc();
  syscall(0xffff);
  after = rdtsc();
  printf("Syscall overhead: %lu cycles\n", after - before);
  return 0;
}
