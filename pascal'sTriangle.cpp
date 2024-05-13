//Approach 1: Using Recursions...
vector<vector<int>> generate(int numRows) {
        
        if (numRows == 0) 
        return {};

        if (numRows == 1) 
        return {{1}};
        
        vector<vector<int>> prevRows = generate(numRows - 1);
        vector<int> newRow(numRows, 1);
        
        for (int i = 1; i < numRows - 1; i++) {
            newRow[i] = prevRows.back()[i - 1] + prevRows.back()[i];
        }
        
        prevRows.push_back(newRow);
        return prevRows;   
    }

//Approach 2: Using Combitorial fromula...

//Use the binomial coefficient formula C(n, k) to calculate each element.
// C(n, k) = C(n-1, k-1) + C(n-1, k), where C(n, k) represents the binomial coefficient.
//Build the triangle row by row using the formula.

 vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; j++) {
                row[j] = result[i - 1][j - 1] + result[i - 1][j];
            }
            result.push_back(row);
        }
        return result;
    }
