#include <stdio.h>

int main(void) {
    char ch[200];
    int a=0, b=0, c=0, d=0, e=0, f=0, g=0, h=0, ii=0, j=0, k=0, l=0, m=0, n=0, 
        o=0, p=0, q=0, r=0, s=0, t=0, u=0, v=0, w=0, x=0, y=0, z=0;
    char temp;

    printf("Enter a string less than 200 characters: ");
    
    while (scanf("%c", &temp) == 1 && temp != '\n') {  
        switch (temp) {
            case 'a': a++; break;
            case 'b': b++; break;
            case 'c': c++; break;
            case 'd': d++; break;
            case 'e': e++; break;
            case 'f': f++; break;
            case 'g': g++; break;
            case 'h': h++; break;
            case 'i': ii++; break;
            case 'j': j++; break;
            case 'k': k++; break;
            case 'l': l++; break;
            case 'm': m++; break;
            case 'n': n++; break;
            case 'o': o++; break;
            case 'p': p++; break;
            case 'q': q++; break;
            case 'r': r++; break;
            case 's': s++; break;
            case 't': t++; break;
            case 'u': u++; break;
            case 'v': v++; break;
            case 'w': w++; break;
            case 'x': x++; break;
            case 'y': y++; break;
            case 'z': z++; break;
            default: break;
        }
    }

    printf("Character counts:\n");
    printf("a: %d, b: %d, c: %d, d: %d, e: %d, f: %d, g: %d, h: %d, i: %d, j: %d, k: %d, l: %d, m: %d, n: %d, o: %d, p: %d, q: %d, r: %d, s: %d, t: %d, u: %d, v: %d, w: %d, x: %d, y: %d, z: %d\n",
           a, b, c, d, e, f, g, h, ii, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z);

    return 0;
}
