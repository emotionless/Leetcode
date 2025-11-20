
#define mp make_pair
#define vi vector<int>
#define xx first
#define yy second
#define all(a) a.begin(), a.end()
#define vsort(v) sort(all(v))
#define UNIQUE(a)  sort(all(a)); a.erase(unique(all(a)), a.end())
#define clr(a,k) memset(a,k,sizeof a)
#define bclr(b) memset(b,false,sizeof b)
#define fr(i, a) for(i = 0; i < a; i++)
#define frr(i,a) for(i = a - 1; i >= 0, i--)
#define LL long long
#define ll long long
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vll vector<long long>

class Solution {
public:

    vector<int>ed[6009], st[6009];
    int started[3009];

    int intersectionSizeTwo(vector< vector<int> >& intervals)
    {
        int n = intervals.size();
        int i, j, k;
        vector<int>numbers;
        for(i = 0; i < n; i++)
        {
            numbers.push_back( intervals[i][0] );
            numbers.push_back(intervals[i][1]);
        }
        UNIQUE(numbers);
        int sz = numbers.size();
        map<int, int>M;
        for(i = 0; i < sz; i++)
        {
            M[ numbers[i] ] = i+1;
        }
        for(i = 0; i < n; i++)
        {
            intervals[i][0] = M[ intervals[i][0] ];
            intervals[i][1] = M[ intervals[i][1] ];
            //cout<<intervals[i][1]<<endl;
        }
        
        for(i = 0; i < n; i++)
        {
            ed[ intervals[i][1] ].pb(i);
            st[ intervals[i][0] ].pb(i);
        }
        int cnt = 1;
        for(i = 0; i < sz; i++)
        {
            int cn = M[ numbers[i] ];
            //cout<<"now "<<cn<<" count "<<cnt<<endl;
            //cout<<"Started... \n ";
            for(j = 0; j < st[cn].size(); j++)
            {
                started[ st[cn][j] ] = cnt;
                //cout<<st[cn][j]<<" ";
            }
            //cout<<endl;
            int mn = 2;
            
            //cout<<"Ended... \n ";
            for(j = 0; j < ed[cn].size(); j++)
            {
                mn = min(mn, cnt - started[ ed[cn][j] ] );
                //cout<<ed[cn][j]<<" ";
            }
            //cout<<endl;
            if(mn == 0)
            {
                cnt++;
                mn++;
            }
            if(mn == 1)
            {
                cnt++;
                for(j = 0; j < st[cn].size(); j++)
                {
                    started[ st[cn][j] ] = cnt-1;
                }
            }
            
        }
        return cnt-1;
    }

};