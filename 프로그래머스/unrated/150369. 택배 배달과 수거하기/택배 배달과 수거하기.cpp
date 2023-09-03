#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#define endl '\n'
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    int dIdx = -1, pIdx = -1;
        
    for(int i = n - 1;i >= 0;i--) {
        if(deliveries[i] != 0) {
            dIdx = i;
            break;
        }
    }
    
    for(int i = n - 1;i >= 0;i--) {
        if(pickups[i] != 0) {
            pIdx = i;
            break;
        }
    }
    
    int dCap, pCap;
    while(true) {
        if(dIdx == -1 && pIdx == -1) break;
        
        answer += 2 * max(dIdx + 1, pIdx + 1);
        
        
        dCap = cap;
        pCap = cap;
        
        if(dIdx != -1) {
            while(dIdx > -1) {
                if(deliveries[dIdx] > dCap) {
                    deliveries[dIdx] -= dCap;
                    break;
                }
                dCap -= deliveries[dIdx];
                if(dCap < 0) {
                    dCap += deliveries[dIdx];
                    break;
                }
                deliveries[dIdx] = 0;
                dIdx--;
            }
        }
        
        if(pIdx != -1) {
            while(pIdx > -1) {
                if(pickups[pIdx] > pCap) {
                    pickups[pIdx] -= pCap;
                    break;
                }
                pCap -= pickups[pIdx];
                if(pCap < 0) {
                    pCap += pickups[pIdx];
                    break;
                }
                pickups[pIdx] = 0;
                pIdx--;
            }
        }
    }
    
    return answer;
}
