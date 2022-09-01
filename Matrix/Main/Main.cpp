#include "Matrix.h"
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define DBG_NEW new( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define newDBG_NEW

int main() {
	menu();
	_CrtDumpMemoryLeaks();
}
