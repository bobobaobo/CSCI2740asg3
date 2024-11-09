#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Query
{
    int l, r, i; //left endpoint, right endpoint, query index
};

int n, t, a[1000000], cq; //the numbers of elements, the array of elements, and the count of queries
Query q[100000]; //the queries
int cnt[(int)1e6 + 1]; //had to avoid "count"
int sqrtn; //square root of n
int curAnswer; //current answer

bool cmp(Query a, Query b)
{
    if(a.l / sqrtn == b.l / sqrtn)
        return a.r < b.r; //ascending r
    else
        return a.l < b.l; //ascending l and hence l/sqrtn (block index)
}

void add(int index)
{
    cnt[a[index]]++;
    if(cnt[a[index]] == 1)
        curAnswer++;
}

//remove one element from the active range
void remove(int index)
{
    cnt[a[index]]--;
    if(cnt[a[index]] == 0)
        curAnswer--;
}

int main(){
    //input all numbers
    cin >> n >> t;
    for (int i =0; i< n; i++){
        cin >> a[i];
    }
    cin >> cq;
    for (int i = 0;i< cq;i++){
        cin >> q[i].l >> q[i].r;
        q[i].l--;
        q[i].r--;
        q[i].i = i;
    }
    
    sqrtn = sqrt(n);
    sort (q, q+cq, cmp);
    int answer[cq];
    int curL = 0, curR =0;
    cnt[a[0]]++;
    curAnswer++;


    //change the current range
    for(int i = 0; i < cq; i++)
    {
        while(curL > q[i].l)
            add(--curL); //<- expand left
        while(curR < q[i].r)
            add(++curR); //expand right ->
        while(curL < q[i].l)
            remove(curL++); //-> shrink left
        while(curR > q[i].r)
            remove(curR--); //shrink right <-

        answer[q[i].i] = curAnswer;
    }
    for(int i = 0; i < cq; i++)
        cout << answer[i] << endl; //changing endl to '\n' speeds up the runtime by a lot for this problem
}

