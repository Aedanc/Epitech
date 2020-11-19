#include <stdio.h>
#include "new.h"
#include "point.h"
#include "vertex.h"

int main()
{
    Object* point = new(Point, 42, -42);
    Object* vertex = new(Vertex, 0, 1, 2);

    printf("Test str() function:\n");
    printf("Point: 42, -42\t-> %s\n", str(point));
    printf("Vertex: 0, 1, 2\t-> %s\n", str(vertex));
    printf("\nDeleting Objects...\n");
    delete(point);
    delete(vertex);
    return 0;
}
