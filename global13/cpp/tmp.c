
        pq.push(mp(S[i],-i));
    while(!pq.empty()){
        auto x = pq.top(); pq.pop();
        int pox = -x.pos;
        if(x.val == 1LL)
            break;
        if(S[pox] != x.val ){
            continue;
        }
        ++ans;
        int j = pox;
        while(j < n){
            ll tmp = S[j];
            S[j] = S[j]-1;
            S[j] = max(S[j],(long long)1);
            if(S[j] != 1LL){
                pq.push(mp(S[j],-j));
            }
            j = j + tmp;
        }
    }