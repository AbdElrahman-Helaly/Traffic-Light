
#ifndef bit_H_
#define bit_H_
 


#define set_bit(x,y) x |= (1<<y)
#define clear_bit(x,y) (x&=~(1<<y))
#define toggle(x,y) (x^=(1<<y))
#define get(x,y) (x>>y)&1

#endif