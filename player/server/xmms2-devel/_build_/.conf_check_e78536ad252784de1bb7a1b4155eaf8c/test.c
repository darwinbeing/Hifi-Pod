
#include <sys/prctl.h>
int main() {
  return prctl(PR_SET_NAME, (unsigned long) "test", 0, 0, 0);
}
