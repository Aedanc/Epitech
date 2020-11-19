#include "new.h"
#include "point.h"

int main()
{
    Object * point = new(Point);
    delete(point);

    return 0;
}
