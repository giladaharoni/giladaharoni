
#ifndef UNTITLED2_EX2_H
#define UNTITLED2_EX2_H

typedef unsigned int magnitude;

int convert_to_int(magnitude a);
magnitude convert_to_mag(int a);

magnitude add(magnitude a, magnitude b); // a + b
magnitude sub(magnitude a, magnitude b); // a - b
magnitude multi(magnitude a, magnitude b); // a * b

// true = 1, false = 0
int equal(magnitude a, magnitude b); // a = b
int greater(magnitude a, magnitude b); // a > b


#endif //UNTITLED2_EX2_H
