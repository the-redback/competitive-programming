class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int sum=dimensions[0][0]*dimensions[0][1];
        int dia=(dimensions[0][0] * dimensions[0][0]) + (dimensions[0][1] * dimensions[0][1]);

        for(int i=1; i<dimensions.size(); i++){
            int temp_dia=(dimensions[i][0] * dimensions[i][0]) + (dimensions[i][1] * dimensions[i][1]);

            if(temp_dia>dia){
                sum = dimensions[i][0]* dimensions[i][1];
                dia = temp_dia;
            } else if(temp_dia == dia){
                sum = max(sum, dimensions[i][0]* dimensions[i][1]);
            }
        }
        
        return sum;
    }
};