class Spreadsheet {
public:
    Spreadsheet(int rows) {
        matrix.resize(rows + 1, vector<int>(27, 0));
        // cout << "All okay" << endl;;
    }
    
    void setCell(string cell, int value) {
        int col = cell[0] - 'A';
        // cout << col << endl;
        int row = stoi(cell.substr(1));
        matrix[row][col] = value;
    }
    
    void resetCell(string cell) {
        setCell(cell, 0);
    }

    int parseAndReturn(string str) {
        if (str[0] >= 'A' && str[1] <= 'Z') {
            int col2 = str[0] - 'A';
            int row2 = stoi(str.substr(1));
            return matrix[row2][col2];
        } else {
            return stoi(str);
        }
    }
    
    int getValue(string formula) {
        formula = formula.substr(1);
        stringstream ss(formula);
        string temp;
        getline(ss, temp, '+');
        int value1 = parseAndReturn(temp);
        getline(ss, temp, '+');
        int value2 = parseAndReturn(temp);

        // cout << value1 << " " << value2 << endl;
        return value1 + value2;
    }
private:
    vector<vector<int>> matrix;
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */