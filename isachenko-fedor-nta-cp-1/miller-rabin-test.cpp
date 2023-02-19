//
//  miller-rabin-test.cpp
//  isachenko-fedor-nta-cp-1
//
//  Created by qqakkashi on 19.02.2023.
//

#include <iostream>
#include <math.h>

int gcd(int a,int b){
    if(b==0){
        return abs(a);
    }
    else{
        return gcd(b, a%b);
    }
}

int pow_mod(int a,int b, int m ){
    int r = 1;
    if(1 & a){
        r=b;
    }
    while (a) {
        a>>=1;
        b=(b*b)%m;
        if(a&1){
            r=(r*b)%m;
        }
    }
    return r;
}

int* miller_params(int p){
    int d = p-1;
    int s = 0;
    static int res[2];
    while (d%2==0) {
        s=s+1;
        d=d/2;
    }
    res[0]= s;
    res[1]=d;
    return res;
}

int miller(int p){
    int* params{};
    params = miller_params(p);
    
    int s = params[0];
    int d = params[1];
    
    float rounds = round(log2(p));
    
    for(int k = 0;k<=rounds;k++){
        
        int x = std::rand() % ( 1 - p) ;
        int g = gcd(x, p);
        
        if(g==1){
            
            if(pow_mod(x, d, p)==1){
                return 1;
            }
            
            else if (pow_mod(x, d, p)==-1){
                return 1;
            }
            
            else{
                for(int r = 1;r<=s-1;r++){
                    int x_r = pow_mod(x, d*(pow(2, r)), p);
                    
                    if (x_r==-1) {
                        return 1;
                    }
                    
                    else if (x_r==1){
                        return 0;
                    }
                    
                    else{
                        continue;
                    }
                }
            }
            
        }
        else{
            return 0;
        }
    }
    return 0;
}

