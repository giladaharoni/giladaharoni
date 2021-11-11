//318781127 Gilad Aharoni

#include <stdio.h>
#define MAX (1<<((sizeof(magnitude)*8)-1))

typedef unsigned int magnitude;

int convert_to_int(magnitude a){
    if (a > MAX)
    {
        return (int)(-1)*(a-MAX);
    } 
    else{
        return (int)a;
    }
}

magnitude convert_to_mag(int a){
    if (a>=0){
        return (magnitude) a;
    }
    else{
        return (-1)*a+MAX;
    }
}

magnitude add(magnitude a, magnitude b){
    int a_conv, b_conv;
    a_conv = convert_to_int(a);
    b_conv = convert_to_int(b);
    return convert_to_mag(a_conv+b_conv);

} // a + b

magnitude sub(magnitude a, magnitude b){
    int a_conv, b_conv;
    a_conv = convert_to_int(a);
    b_conv = convert_to_int(b);
    return convert_to_mag(a_conv-b_conv);
} // a - b

magnitude multi(magnitude a, magnitude b){
    int a_conv, b_conv;
    a_conv = convert_to_int(a);
    b_conv = convert_to_int(b);
    return convert_to_mag(a_conv * b_conv);
} // a * b

// true = 1, false = 0
int equal(magnitude a, magnitude b){
    return a==b;
} // a = b
int greater(magnitude a, magnitude b){
    int a_conv, b_conv;
    a_conv = convert_to_int(a);
    b_conv = convert_to_int(b);
    return a_conv>b_conv;
} // a > b