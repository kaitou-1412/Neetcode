class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();
        if(n == 1) {
            return (triplets[0][0] == target[0]) 
            and (triplets[0][1] == target[1]) 
            and (triplets[0][2] == target[2]);
        }
        int i = 0, j = 1;
        int triplet_one_one ,triplet_two_one;
        int triplet_one_two, triplet_two_two;
        int triplet_one_three, triplet_two_three;
        int a1, a2, a3;
        while(j<n) {
            triplet_one_one = triplets[i][0], triplet_two_one = triplets[j][0];
            triplet_one_two = triplets[i][1], triplet_two_two = triplets[j][1];
            triplet_one_three = triplets[i][2], triplet_two_three = triplets[j][2];
            if(
                triplet_one_one>target[0] 
                or triplet_one_two>target[1] 
                or triplet_one_three>target[2]
            ) {
                i++;
                j++;
                continue;
            }
            a1 = max(triplet_one_one, triplet_two_one);
            a2 = max(triplet_one_two, triplet_two_two);
            a3 = max(triplet_one_three, triplet_two_three);
            if(a1<=target[0] and a2<=target[1] and a3<=target[2]) {
                triplets[j][0] = a1;
                triplets[j][1] = a2;
                triplets[j][2] = a3;
                i = j;
            }
            if((triplets[j][0] == target[0]) 
            and (triplets[j][1] == target[1]) 
            and (triplets[j][2] == target[2])) {
                return true;
            }
            j++;
        }
        return false;
    }
};