/*
** test.c for  in /home/fortevg/rendu/infographie/gfx_tekgui
**
** Made by Forteville Gabriel
** Login   <fortevg@epitech.net>
**
** Started on  Sun Feb 28 18:55:54 2016 Forteville Gabriel
** Last update Sun Feb 28 19:36:39 2016 Forteville Gabriel
*/

#include <dlfcn.h>
#include <stdlib.h>

void		*tekfunction(const char *funcname)
{
  void		*fonction;
  void		*handle;
  char		*error;

  if ((handle = dlopen(NULL, RTLD_LAZY)) == NULL)
    return (NULL);
  dlerror();
  if ((fonction = dlsym(handle, funcname)) == NULL)
    return (NULL);
  error = dlerror();
  if (error != NULL)
    return (NULL);
  if (dlclose(handle) != 0)
    return (NULL);
  return (fonction);
}
