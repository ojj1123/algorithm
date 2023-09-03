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
    
    int dSum = 0, pSum = 0;
    int dCap, pCap;
    while(true) {
        if(dIdx == -1 && pIdx == -1) break;
        
        answer += 2 * max(dIdx + 1, pIdx + 1);
        // cout << dIdx << ' ' << pIdx << endl;
        // cout << dIdx << ':' << deliveries[dIdx] << endl;
        // cout<<answer<<endl;
        
        
        dCap = cap;
        pCap = cap;
        // dSum = 0;
        // pSum = 0;
        
        if(dIdx != -1) {
            while(dIdx > -1) {
                // if(deliveries[dIdx] > cap) {
                //     deliveries[dIdx] -= cap;
                //     break;
                // }
                // dSum += deliveries[dIdx];
                // if(dSum > cap) {
                //     dSum -= deliveries[dIdx];
                //     break;
                // }
                // deliveries[dIdx] = 0;
                // dIdx--;
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
                // if(pickups[pIdx] > cap) {
                //     pickups[pIdx] -= cap;
                //     break;
                // }
                // pSum += pickups[pIdx];
                // if(pSum > cap) {
                //     pSum -= pickups[pIdx];
                //     break;
                // }
                // pickups[pIdx] = 0;
                // pIdx--;
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