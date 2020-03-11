#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/

typedef struct  s_art {
  char *name;
  int  price;
}				t_art;

typedef struct	s_item {
  char           *key; //here the key will be the name
  struct s_art   *value;
  struct s_item  *next;
}				t_item;

typedef struct	s_dict {
  struct s_item **items;
  int           capacity; //the capacity of the array 'items'
}				t_dict;

/*--------------------------------
  :) function you must implement
  --------------------------------*/

// DICTIONNARY

size_t hash(char *input); //return hash result

t_dict *dictInit(int capacity); //initialize the dictionnary, given as parameter the capacity of the array.
int	dictInsert(t_dict *dict, char *key, t_art *value); //add one element in the dictionnary, if FAIL return 0, otherwise 1
t_art *dictSearch(t_dict *dict, char *key); //find one element in the dictionnary, if not found, return NULL

// OTHER

int searchPrice(t_dict *dict, char *name);


/*--------------------------------
  ?? test function used in main 
  --------------------------------*/

t_art **getArts(void);


/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
