class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size();
        int cnt=0;
        sort(people.begin(),people.end());
        int i=0;
        int j=n-1;
        while(i<j){
            int weight = people[i]+people[j];
            if(weight<=limit){
                cnt++;
                people[i]=0;
                people[j]=0;
                i++;
                j--;
            }
            else{
                j--;
            }
        }
        for(auto it:people){
            if(it!=0 && it<=limit){
                cnt++;
            }
        }
    return cnt;
    }
};