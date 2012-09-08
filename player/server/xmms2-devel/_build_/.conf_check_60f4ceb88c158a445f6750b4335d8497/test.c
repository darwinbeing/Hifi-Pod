#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

	int main() {
	void *p;
	p=(void*)(semctl);
	return 0;
}
