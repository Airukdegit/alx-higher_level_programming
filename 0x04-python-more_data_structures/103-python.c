#include <Python.h>
#include <object.h>
#include <listobject.h>
#include <bytesobject.h>

void print_python_bytes(PyObject *p)
{
	long int bytes;
	int i;
	char *test_string = NULL;

	printf("[.] bytes object info\n");
	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}

	PyBytes_AsStringAndSize(p, &test_string, &bytes);

	printf("  size: %li\n", bytes);
	printf("  trying string: %s\n", test_string);
	if (bytes < 10)
		printf("  first %li bytes:", bytes + 1);
	else
		printf("  first 10 bytes:");
	for (i = 0; i <= bytes && i < 10; i++)
		printf(" %02hhx", test_string[i]);
	printf("\n");
}

void print_python_list(PyObject *p)
{
        long int size = PyList_Size(p);
        int i;
        PyListObject *list = (PyListObject *)p;
        const char *type;

        printf("[*] Python list info\n");
        printf("[*] Size of the Python List = %li\n", size);
        printf("[*] Allocated = %li\n", list->allocated);
        for (i = 0; i < size; i++)
        {
                type = (list->ob_item[i])->ob_type->tp_name;
		printf("Element %i: %s\n", i, type);
                if (!strcmp(type, "bytes"))
                        print_python_bytes(list->ob_item[i]);
        }
}

