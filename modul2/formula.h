#include <stdio.h>

int VKubus(int s);
int LKubus(int s);

int VBalok(int p, int l, int t);
int LBalok(int p, int l, int t);

float VBola(float r);
float LBola(float r);

int VKubus(int s) {
    return s * s * s;
}

int LKubus(int s) {
    return 6 * s;
}

int VBalok(int p, int l, int t) {
    return p * l * t;
}

int LBalok(int p, int l, int t) {
    return 2 * ((p * l) + (p * t) + (l * t));
}

float VBola(float r) {
    return (float) 4/3 * 22/7 * (r * r * r);
}

float LBola(float r) {
    return (float) 4 * 22/7 * (r * r);
}