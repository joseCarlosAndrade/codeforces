#include<bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;

// 1 if a has advantage over b
int has_advantage(char a, char b) {
    if (a == b) return -1; //no advantages
    if (a == 'A') {
        if (b == 'F') return 1 ; 
        else return 0;
    }

    if (a == 'F') {
        if (b == 'G') return 1;
        else return 0;
    }

    if (a== 'G') {
        if (b == 'A') return 1;
        else return 0;
    }
    return 1;
}

//1 if f win, 0 if t win
int do_round(double vf, long int pf, char cf, double vt, long int pt, char ct) {
    // double damage;

    double fdf = pf;
    double fdt = pt ;

    // decide damage
    int adv = has_advantage(cf, ct);
    if( adv== 1) {
        fdf = (double) fdf*3/2;
        fdt = (double) fdt*3/4;
    }
    else if (adv == 0) {
        fdf = (double) fdf*3/4; 
        fdt = (double) fdt*3/2;
    }


    for (;;) {
        // fakhoury
        vt -= fdf;

        if ( vt <= 0) return 1;
        // turci
        vf -= fdt;
        if (vf <= 0) return 0;
    }
}

int main() {
    int n;
    cin >> n;


    for ( int i = 0 ; i < n; i++) {
        double vf, vt;
        long int pf;
        char cf;
        long int pt;
        char ct;
        //lendo fakhoury
        cin >> vf >> pf >> cf;
        //lendo turci
        cin >> vt >> pt >> ct;
    
        if (do_round(vf, pf, cf, vt, pt, ct)) cout<< "FAKHOURY" << endl;
        else cout << "TURCI" << endl;


    }
}