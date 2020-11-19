#include <stdio.h>
#include "new.h"
#include "point.h"
#include "vertex.h"
#include "object.h"

int main()
{
  Object* p1 = new(Point, 12, 13),
    * p2 = new(Point, 2, 2),
    * v1 = new(Vertex, 1, 2, 3),
    * v2 = new(Vertex, 4, 5, 6);
  Object* res_p1;
  Object* res_p2;
  Object* res_v1;
  Object* res_v2;

  printf("Testing Add and Sub functions:\n");
  res_p1 = add(p1, p2);
  printf("%s + %s = %s\n", str(p1), str(p2), str(res_p1));
  res_p2 = sub(p1, p2);
  printf("%s - %s = %s\n", str(p1), str(p2), str(res_p2));
  res_v1 = add(p1, p2);
  printf("%s + %s = %s\n", str(v1), str(v2), str(res_v1));
  res_v2 = sub(p1, p2);
  printf("%s - %s = %s\n", str(v1), str(v2), str(res_v2));

  printf("\nDeleting Objects...\n");
  delete(p1);
  delete(p2);
  delete(v1);
  delete(v2);
  delete(res_p1);
  delete(res_p2);
  delete(res_v1);
  delete(res_v2);

  return 0;
}
