#include "fillit.h"

int main(int argc, char *argv[])
{
    uint16_t *map;
    t_list *tetros;
    size_t mapsize;
    int fd;
    int res;
    size_t count;

    if (argc != 2)
      return (ft_error("usage: source_file"));
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
		  return(ft_error("error"));
    count = 0;
    map = (uint16_t *)malloc(sizeof(uint16_t) * 16);
    ft_bzero(map, sizeof(uint16_t) * 16);
	  res = read_input(fd, &tetros, &count);
    if (res < 0)
      return (res);
    mapsize = checker(map, &tetros, count);
//    printf("map after checker: %llu\n", *((uint64_t *)(map)));
//    printf("%zu\n", mapsize);
    //UPDATE MAPSIZE TO MAKE MAP!!
    mapsize = solver(map, &tetros, mapsize);
/*      for (int i = 0; i < 16; i++)
    printf("|%s\n", ft_itoa_base(map[i], 2));
    printf("\n");
*/    print_solution(&tetros, mapsize);
}