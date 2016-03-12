#include "ruby.h"

char* xconcat(char *s1, char *s2)
{
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    char *result = malloc(len1+len2+1);//+1 for the zero-terminator
    //in real code you would check for errors in malloc here
    memcpy(result, s1, len1);
    memcpy(result+len1, s2, len2+1);//+1 to copy the null-terminator
    return result;
}

VALUE cell_collection_native_show()
{
  char foo[] = "foo";
  char bar[] = "bar";
  char *foobar = xconcat(foo, bar);
  return rb_str_new2(foobar);
}

VALUE cell_collection_native_collection(VALUE self, VALUE count)
{
  int c = NUM2INT(count);
  char *buffer = malloc(10 * c);

  for(int i = 0; i < c; i++)
  {
    char value[6] = "foobar";
    memcpy(buffer + strlen(buffer), value, strlen(value) + 1);
  }

  return rb_str_new2(buffer);
}

void Init_cell_native()
{
  VALUE Cell = rb_define_module("Cell");
  VALUE CellCollection = rb_define_module_under(Cell, "Collection");
  VALUE CellCollectionClassMethods = rb_define_module_under(CellCollection, "ClassMethods");
  rb_define_method(CellCollection, "native_show", cell_collection_native_show, 0);
  rb_define_method(CellCollectionClassMethods, "native_collection", cell_collection_native_collection, 1);
}
