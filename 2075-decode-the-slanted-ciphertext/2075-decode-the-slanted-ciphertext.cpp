class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int cols = encodedText.size() / rows;
        string ans = "";
        int last = 0;
        int id = 0;
        for (int k = 0; k < cols; k++) {
            int i = 0, j = k;
            while (i < rows && j < cols) {
                int ind = i * cols + j;
                // cout << ind << endl;
                ans += encodedText[ind];
                id++;
                if (encodedText[ind] != ' ') last = id;
                i++;
                j++;
                
            }
        }
        ans.resize(last);
        return ans;
    }
};